/**
 * @file Spi_Baremetal.c
 * @brief Bare-metal SPI driver for S32G3 DSPI module
 * @note  S32G3 uses DSPI (De-serial SPI), NOT LPSPI!
 */

/*==================================================================================================
 *                                          INCLUDES
 *==================================================================================================*/
#include "TJA1145A_Spi_Baremetal.h"
#include "FlexCAN_Ip.h" /* For FlexCAN_Ip_SetStopMode/SetStartMode */

/*==================================================================================================
 *                                     GLOBAL VARIABLES
 *==================================================================================================*/

volatile Spi_Baremetal_Debug_t g_Spi_Baremetal_Debug = {0};

/*==================================================================================================
 *                                     LOCAL MACROS
 *==================================================================================================*/

/* SIUL2_0 MSCR Register Base - Port K starts at different offset */
/* Port K MSCR: PK11=83, PK13=85, PK14=86, PK15=87 */
/* MSCR formula: SIUL2_0_BASE + 0x240 + (pin_index * 4) */
/* For PK11 (index 83): 0x4009C000 + 0x240 + (83 * 4) = 0x4009C38C */
/* For PK13 (index 85): 0x4009C000 + 0x240 + (85 * 4) = 0x4009C394 */
/* For PK14 (index 86): 0x4009C000 + 0x240 + (86 * 4) = 0x4009C398 */
/* For PK15 (index 87): 0x4009C000 + 0x240 + (87 * 4) = 0x4009C39C */

#define SIUL2_0_MSCR_BASE (SIUL2_0_BASE + 0x240UL)
#define SIUL2_1_IMCR_BASE (SIUL2_1_BASE + 0xA40UL)

#define MSCR_PK11_ADDR (SIUL2_0_MSCR_BASE + (83U * 4U)) /* SPI5_CS0 */
#define MSCR_PK13_ADDR (SIUL2_0_MSCR_BASE + (85U * 4U)) /* SPI5_SOUT (MOSI) */
#define MSCR_PK14_ADDR (SIUL2_0_MSCR_BASE + (86U * 4U)) /* SPI5_SIN (MISO) */
#define MSCR_PK15_ADDR (SIUL2_0_MSCR_BASE + (87U * 4U)) /* SPI5_SCK */

/* IMCR for SPI5_SIN input mux: IMCR index 1007 */
/* SIUL2_1_IMCR address: SIUL2_1_BASE + 0xA40 + ((imcr_index - 512) * 4) */
/* For IMCR 1007: 0x44010000 + 0xA40 + ((1007 - 512) * 4) = 0x44010000 + 0xA40 +
 * 1980 = 0x44011BDC */
#define IMCR_SPI5_SIN_ADDR (SIUL2_1_IMCR_BASE + ((1007U - 512U) * 4U))

/* MSCR Field Values */
/* For output pins (CS, MOSI, SCK):
 * - SSS (Source Signal Select) for SPI5: depends on pin
 * - SRE = 0 (Slow slew rate)
 * - OBE = 1 (Output Buffer Enable)
 * - ODE = 0 (Open Drain Disable)
 * - SMC = 0 (Safe Mode Control)
 * - IBE = 0 (Input Buffer Disable for pure output)
 */

/* For input pins (MISO):
 * - IBE = 1 (Input Buffer Enable)
 * - OBE = 0 (Output Buffer Disable)
 */

/* MSCR register bit definitions */
#define MSCR_SSS_SHIFT (0U)
#define MSCR_SMC_SHIFT (5U)
#define MSCR_IBE_SHIFT (19U)
#define MSCR_ODE_SHIFT (20U)
#define MSCR_OBE_SHIFT (21U)
#define MSCR_SRE_MASK (0x0000C000UL) /* Slew Rate bits 15:14 */

#define MSCR_OBE_MASK (1UL << MSCR_OBE_SHIFT) /* Output Buffer Enable */
#define MSCR_IBE_MASK (1UL << MSCR_IBE_SHIFT) /* Input Buffer Enable */

/*==================================================================================================
 *                                     PRIVATE FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Simple delay function
 */
void Spi_Baremetal_Delay(uint32 loops) {
  volatile uint32 i;
  for (i = 0; i < loops; i++) {
    __asm volatile("nop");
  }
}

/**
 * @brief Initialize DSPI5 pins using direct SIUL2 register access
 * NOTE: Port_Init() should have already configured these pins correctly via
 * SIUL2_1! PK11-PK15 are in SIUL2_1 (0x44010000), not SIUL2_0 (0x4009C000)!
 * Pin indices in SIUL2_1: PK11=171, PK13=173, PK14=174, PK15=175
 *
 * WARNING: M7 core cannot directly access SIUL2_1 registers (causes HardFault)!
 * Use TRACE32 to read these values instead:
 * - MSCR PK14: Data.LONG D:0x440102F8 (should have IBE=1)
 * - IMCR1007:  Data.LONG D:0x440111BC (should have route to PK14)
 */
void Spi_Baremetal_InitPins(void) {
  /* Cannot read SIUL2_1 from M7 core - causes HardFault!
   * Set marker values so user knows to use TRACE32 */
  g_Spi_Baremetal_Debug.mscr_pk11 = 0xDEAD0001UL;
  g_Spi_Baremetal_Debug.mscr_pk13 = 0xDEAD0001UL;
  g_Spi_Baremetal_Debug.mscr_pk14 = 0xDEAD0001UL;
  g_Spi_Baremetal_Debug.mscr_pk15 = 0xDEAD0001UL;
  g_Spi_Baremetal_Debug.imcr_1007 = 0xDEAD0001UL;
}

/*==================================================================================================
 *                                     PUBLIC FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Initialize DSPI5 module as SPI Master
 *
 * Configuration:
 * - Master mode
 * - 8-bit frame size
 * - CPOL=0, CPHA=0 (SPI Mode 0)
 * - MSB first
 * - PCS0 inactive high
 * - Baud rate ~1MHz (depends on protocol clock)
 */
void Spi_Baremetal_Init(uint8 baudrate_div) {
  uint32 mcr_value;
  uint32 ctar_value;
  uint32 sr;

  /* Step 1: Initialize pins first */
  g_Spi_Baremetal_Debug.init_step = 1U;
  Spi_Baremetal_InitPins();
  g_Spi_Baremetal_Debug.init_step = 2U;

  /* Step 2: Completely disable module first (MDIS=1, HALT=1)
   * This ensures a clean reset state
   */
  g_Spi_Baremetal_Debug.init_step = 3U;
  DSPI5_REG(DSPI_MCR_OFFSET) = DSPI_MCR_MDIS_MASK | DSPI_MCR_HALT_MASK;
  Spi_Baremetal_Delay(100);

  /* Step 3: Clear ALL status flags first, especially EOQF!
   * EOQF=1 causes TXRXS to auto-clear, stopping the module
   */
  g_Spi_Baremetal_Debug.init_step = 4U;
  DSPI5_REG(DSPI_SR_OFFSET) = 0xFFFF0000UL; /* Clear all W1C flags */
  Spi_Baremetal_Delay(50);

  /* Step 4: Enable module (clear MDIS), set Master mode, keep HALT, clear FIFOs
   * MCR reset value = 0x0000_4001 (MDIS=1, HALT=1)
   */
  g_Spi_Baremetal_Debug.init_step = 5U;
  mcr_value = DSPI_MCR_MSTR_MASK |    /* Master mode */
              DSPI_MCR_PCSIS0_MASK |  /* PCS0 inactive high */
              DSPI_MCR_HALT_MASK |    /* Keep halted during config */
              DSPI_MCR_CLR_TXF_MASK | /* Clear TX FIFO */
              DSPI_MCR_CLR_RXF_MASK;  /* Clear RX FIFO */
  DSPI5_REG(DSPI_MCR_OFFSET) = mcr_value;
  g_Spi_Baremetal_Debug.init_step = 6U;

  /* Wait for FIFO clear - CLR_TXF/CLR_RXF are self-clearing */
  Spi_Baremetal_Delay(100);

  /* Step 5: Configure CTAR0 (Clock and Transfer Attributes)
   * Can only be modified when HALT=1
   * TJA1145 requires SPI Mode 1: CPOL=0, CPHA=1
   */
  g_Spi_Baremetal_Debug.init_step = 7U;
  ctar_value =
      (7UL << DSPI_CTAR_FMSZ_SHIFT) |   /* 8-bit frame (FMSZ = 7) */
      DSPI_CTAR_CPHA_MASK |             /* CPHA=1 for SPI Mode 1 (TJA1145) */
      (0UL << DSPI_CTAR_PBR_SHIFT) |    /* Baud rate prescaler = 2 */
      (1UL << DSPI_CTAR_PCSSCK_SHIFT) | /* PCS to SCK delay prescaler */
      (1UL << DSPI_CTAR_PASC_SHIFT) |   /* After SCK delay prescaler */
      (1UL << DSPI_CTAR_PDT_SHIFT) |    /* Delay after transfer prescaler */
      (4UL << DSPI_CTAR_CSSCK_SHIFT) |  /* PCS to SCK delay scaler */
      (4UL << DSPI_CTAR_ASC_SHIFT) |    /* After SCK delay scaler */
      (4UL << DSPI_CTAR_DT_SHIFT) |     /* Delay after transfer scaler */
      ((uint32)baudrate_div << DSPI_CTAR_BR_SHIFT); /* Baud rate scaler */
  DSPI5_REG(DSPI_CTAR0_OFFSET) = ctar_value;
  g_Spi_Baremetal_Debug.init_step = 8U;

  /* Step 6: Disable all DMA and interrupt requests */
  DSPI5_REG(DSPI_RSER_OFFSET) = 0x00000000UL;
  g_Spi_Baremetal_Debug.init_step = 9U;

  /* Step 7: Clear all status flags again before starting */
  DSPI5_REG(DSPI_SR_OFFSET) = 0xFFFF0000UL;
  g_Spi_Baremetal_Debug.init_step = 10U;

  /* Step 8: Release HALT to start module (MSTR=1, HALT=0) */
  mcr_value = DSPI_MCR_MSTR_MASK |  /* Master mode */
              DSPI_MCR_PCSIS0_MASK; /* PCS0 inactive high */
  DSPI5_REG(DSPI_MCR_OFFSET) = mcr_value;
  g_Spi_Baremetal_Debug.init_step = 11U;

  /* Small delay to stabilize */
  Spi_Baremetal_Delay(100);

  /* Step 9: Verify module state */
  sr = DSPI5_REG(DSPI_SR_OFFSET);

  /* Check TFFF (should be 1 for empty TX FIFO) */
  if ((sr & DSPI_SR_TFFF_MASK) == 0U) {
    g_Spi_Baremetal_Debug.error_code = 10U; /* TFFF not ready */
  }
  /* Check EOQF (should be 0) */
  if ((sr & DSPI_SR_EOQF_MASK) != 0U) {
    g_Spi_Baremetal_Debug.error_code = 11U; /* EOQF still set */
  }

  /* Read back registers for debug */
  g_Spi_Baremetal_Debug.dspi_mcr = DSPI5_REG(DSPI_MCR_OFFSET);
  g_Spi_Baremetal_Debug.dspi_sr = sr;
  g_Spi_Baremetal_Debug.dspi_ctar0 = DSPI5_REG(DSPI_CTAR0_OFFSET);

  g_Spi_Baremetal_Debug.init_step = 12U;
  g_Spi_Baremetal_Debug.init_ok = 1U;
}

/**
 * @brief Transfer a single byte over DSPI5 with optional continuous CS
 *
 * The PUSHR register format (Master mode):
 * Bits 31: CONT (Continuous PCS)
 * Bits 30-28: CTAS (CTAR Select)
 * Bit 27: EOQ (End of Queue)
 * Bit 26: CTCNT (Clear Transfer Counter)
 * Bits 21-16: PCS (Peripheral Chip Select)
 * Bits 15-0: TXDATA
 *
 * @param tx_byte Byte to transmit
 * @param cont_cs 1=Keep CS asserted after transfer, 0=Release CS after transfer
 * @return Received byte
 */
uint8 Spi_Baremetal_TransferEx(uint8 tx_byte, uint8 cont_cs) {
  uint32 pushr_value;
  uint32 sr;
  uint32 timeout;
  uint32 rx_data;

  /* Save TX data for debug */
  g_Spi_Baremetal_Debug.tx_data = (uint32)tx_byte;

  /* Clear EOQF flag first - EOQF=1 causes TXRXS to auto-clear, stopping module!
   * Also clear other flags that might be set from previous transfers
   */
  DSPI5_REG(DSPI_SR_OFFSET) = DSPI_SR_TCF_MASK | DSPI_SR_EOQF_MASK |
                              DSPI_SR_TFFF_MASK | DSPI_SR_RFDF_MASK;

  /* Build PUSHR value:
   * - CONT = cont_cs (Keep or release PCS after transfer)
   * - CTAS = 0 (Use CTAR0)
   * - EOQ = 0 (DO NOT set End of Queue - this stops the module!)
   * - CTCNT = 0 (Don't clear transfer counter)
   * - PCS0 = 1 (Assert PCS0)
   * - TXDATA = tx_byte
   */
  pushr_value = DSPI_PUSHR_PCS0_MASK |                      /* Assert PCS0 */
                ((uint32)tx_byte & DSPI_PUSHR_TXDATA_MASK); /* TX data */

  /* Add CONT bit if continuous CS is requested */
  if (cont_cs != 0U) {
    pushr_value |= DSPI_PUSHR_CONT_MASK;
  }

  /* Wait for TX FIFO not full */
  timeout = 100000U;
  do {
    sr = DSPI5_REG(DSPI_SR_OFFSET);
    timeout--;
  } while (((sr & DSPI_SR_TFFF_MASK) == 0U) && (timeout > 0U));

  if (timeout == 0U) {
    g_Spi_Baremetal_Debug.transfer_ok = 0U;
    g_Spi_Baremetal_Debug.error_code = 1U; /* TX FIFO full timeout */
    g_Spi_Baremetal_Debug.dspi_sr =
        sr; /* Capture SR at timeout for debugging */
    return 0xFFU;
  }

  /* Write to PUSHR to start transfer */
  DSPI5_REG(DSPI_PUSHR_OFFSET) = pushr_value;

  /* Clear TFFF flag by writing 1 */
  DSPI5_REG(DSPI_SR_OFFSET) = DSPI_SR_TFFF_MASK;

  /* Wait for transfer complete or RX FIFO not empty */
  timeout = 100000U;
  do {
    sr = DSPI5_REG(DSPI_SR_OFFSET);
    timeout--;
  } while (((sr & (DSPI_SR_TCF_MASK | DSPI_SR_RFDF_MASK)) == 0U) &&
           (timeout > 0U));

  if (timeout == 0U) {
    g_Spi_Baremetal_Debug.transfer_ok = 0U;
    g_Spi_Baremetal_Debug.error_code = 2U; /* Transfer timeout */
    return 0xFFU;
  }

  /* Clear TCF and RFDF flags */
  DSPI5_REG(DSPI_SR_OFFSET) = DSPI_SR_TCF_MASK | DSPI_SR_RFDF_MASK;

  /* Read received data from POPR */
  rx_data = DSPI5_REG(DSPI_POPR_OFFSET);
  g_Spi_Baremetal_Debug.rx_data = rx_data;
  g_Spi_Baremetal_Debug.transfer_ok = 1U;
  g_Spi_Baremetal_Debug.dspi_sr = sr;

  return (uint8)(rx_data & 0xFFU);
}

/**
 * @brief Transfer a single byte over DSPI5 (legacy function, releases CS)
 * @param tx_byte Byte to transmit
 * @return Received byte
 */
uint8 Spi_Baremetal_Transfer(uint8 tx_byte) {
  return Spi_Baremetal_TransferEx(tx_byte, 0U);
}

/**
 * @brief Transfer multiple bytes over DSPI5
 */
void Spi_Baremetal_TransferBuffer(const uint8 *tx_buf, uint8 *rx_buf,
                                  uint32 len) {
  uint32 i;
  uint8 rx;

  if ((tx_buf == NULL_PTR) || (rx_buf == NULL_PTR) || (len == 0U)) {
    return;
  }

  for (i = 0U; i < len; i++) {
    rx = Spi_Baremetal_Transfer(tx_buf[i]);
    rx_buf[i] = rx;
  }
}

/*==================================================================================================
 *                                  TJA1145 FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Read a register from TJA1145
 *
 * TJA1145 SPI protocol (per datasheet Section 7.12):
 * - 16-bit transfer (8-bit command + 8-bit data)
 * - Command byte format: [A6][A5][A4][A3][A2][A1][A0][R/W]
 *   - Bits 7:1 = 7-bit register address
 *   - Bit 0 (LSB) = R/W bit: 1=Read, 0=Write
 * - Data byte: returned on second byte (SDO)
 */
uint8 Spi_Baremetal_Tja1145_ReadReg(uint8 addr) {
  uint8 rx1, rx2;
  uint8 read_cmd;

  /* Read command: address in bits 7:1, bit 0 (LSB) = 1 for read */
  read_cmd = (uint8)((addr << 1U) | 0x01U);

  /* Transfer address byte with CONT=1 (keep CS low) */
  rx1 = Spi_Baremetal_TransferEx(read_cmd, 1U);
  (void)rx1;

  /* Transfer dummy byte with CONT=0 (release CS after this byte) */
  rx2 = Spi_Baremetal_TransferEx(0x00U, 0U);

  return rx2;
}

/**
 * @brief Write a register to TJA1145
 *
 * TJA1145 SPI protocol (per datasheet Section 7.12):
 * - 16-bit transfer (8-bit command + 8-bit data)
 * - Command byte format: [A6][A5][A4][A3][A2][A1][A0][R/W]
 *   - Bits 7:1 = 7-bit register address
 *   - Bit 0 (LSB) = R/W bit: 1=Read, 0=Write
 */
void Spi_Baremetal_Tja1145_WriteReg(uint8 addr, uint8 data) {
  uint8 rx1, rx2;
  uint8 write_cmd;

  /* Write command: address in bits 7:1, bit 0 (LSB) = 0 for write */
  write_cmd = (uint8)((addr << 1U) | 0x00U);

  /* Transfer address byte with CONT=1 (keep CS low) */
  rx1 = Spi_Baremetal_TransferEx(write_cmd, 1U);
  (void)rx1;

  /* Transfer data byte with CONT=0 (release CS after this byte) */
  rx2 = Spi_Baremetal_TransferEx(data, 0U);
  (void)rx2;
}

/**
 * @brief Clear all TJA1145 event status registers and disable all wake-up
 * sources
 *
 * Per TJA1145 datasheet Section 7.6.2 (Sleep mode protection):
 * All event status bits must be cleared before Mode transitions.
 *
 * Per Section 7.1.1.3:
 * When undervoltage forces Sleep mode, CWE/WPFE/WPRE are auto-enabled.
 * We must disable them to prevent re-entering Sleep.
 */
static void Spi_Baremetal_Tja1145_ClearEventsAndDisableWakeup(void) {
  /* Step 1: Clear all event status registers (write 1 to clear = W1C) */
  /* System event status (0x61): clear PO, OTW, SPIF */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_STATUS, 0xFFU);

  /* Transceiver event status (0x63): clear PNFDE, CBS, CF, CW */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS, 0xFFU);

  /* WAKE pin event status (0x64): clear WPR, WPF */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EVENT, 0xFFU);

  /* Step 2: Disable ALL wake-up sources to prevent re-entering Sleep */
  /* Disable CAN wake-up (CWE=0), CAN failure detect (CFE=0),
   * CAN bus silence (CBSE=0) in transceiver event enable (0x23) */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANS_EVENT_EN, 0x00U);

  /* Disable WAKE pin wake-up (WPRE=0, WPFE=0) in WAKE pin enable (0x4C) */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EN, 0x00U);

  /* Disable SPI failure and overtemp warning in system event enable (0x04) */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_EN, 0x00U);
}

/**
 * @brief Initialize TJA1145 and set to Normal mode
 *
 * Full initialization sequence per TJA1145 datasheet:
 * 1. Read Device ID to verify SPI communication
 * 2. Read Main Status to check FSMS (forced Sleep)
 * 3. Clear all event status registers (required before mode transition)
 * 4. Disable all wake-up sources (prevent re-entering Sleep)
 * 5. Set Normal mode (MC=111)
 * 6. Set CAN Active mode (CMC=01)
 * 7. Verify and read diagnostics
 *
 * @return 0 on success, error code on failure
 */
/**
 * @brief Initialize TJA1145 and set to Normal mode
 *
 * Full initialization sequence to ensure NMS=1:
 * 1. Read Device ID
 * 2. Force CAN Offline (CMC=00)
 * 3. Disable all wake-up sources
 * 4. Clear all event status registers
 * 5. Transition: Sleep/Unknown -> Standby
 * 6. Clear events again
 * 7. Transition: Standby -> Normal
 * 8. Verify NMS=1
 * 9. Set CAN Active (CMC=01)
 *
 * @return 0 on success, error code on failure
 */
uint8 Spi_Baremetal_Tja1145_Init(void) {
  uint8 device_id;
  uint8 main_status;
  uint8 i;

  g_Spi_Baremetal_Debug.tja_init_step = 1U;
  g_Spi_Baremetal_Debug.tja_error_code = 0U;

  /* Step 1: Read Device ID (0x7E) to verify SPI communication */
  device_id = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_DEVICE_ID);
  g_Spi_Baremetal_Debug.tja_R7E_device_id = device_id;
  g_Spi_Baremetal_Debug.tja_init_step = 2U;

  if ((device_id != 0x70U) && (device_id != 0x74U) && (device_id != 0x80U)) {
    g_Spi_Baremetal_Debug.tja_error_code = 2U;
    /* Continue anyway to try recovery */
  }

  /* Step 2: Read Main Status */
  main_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MAIN_STATUS);
  g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;
  g_Spi_Baremetal_Debug.tja_init_step = 3U;

  /* Step 3: Wait for VCC/VIO to stabilize after power-on (~10ms) */
  Spi_Baremetal_Delay(800000);

  /* RETRY LOOP for Mode Transition */
  for (i = 0; i < 5; i++) {
    g_Spi_Baremetal_Debug.tja_init_step = 40U + i;

    /* Step 3: Force CAN Offline (CMC=00) to clear any invalid Active state */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x00U);
    Spi_Baremetal_Delay(50000);

    /* Step 4: Disable ALL wake-up sources FIRST */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANS_EVENT_EN, 0x00U);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EN, 0x00U);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_EN, 0x00U);

    /* Step 5: Clear all event status registers */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_STATUS, 0xFFU);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS, 0xFFU);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EVENT, 0xFFU);

    Spi_Baremetal_Delay(200000);

    /* Step 6: Go to Standby (Required transition) */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_MODE_CONTROL,
                                   TJA1145_MODE_STANDBY);
    Spi_Baremetal_Delay(400000);

    /* Step 7: Clear events again (Clean slate) */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_STATUS, 0xFFU);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS, 0xFFU);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EVENT, 0xFFU);
    Spi_Baremetal_Delay(200000);

    /* Step 8: Go to Normal */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_MODE_CONTROL,
                                   TJA1145_MODE_NORMAL);
    /* Wait significant time for Oscillator to start and NMS to set */
    Spi_Baremetal_Delay(1000000);

    /* Step 9: Verify NMS (per datasheet: NMS=0 = Normal mode confirmed) */
    main_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MAIN_STATUS);
    if ((main_status & TJA1145_MAIN_STATUS_NMS) == 0U) {
      /* Success! NMS=0 = Normal mode confirmed per datasheet */
      g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;
      break;
    }
  }

  /* Final Status Update */
  g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;
  g_Spi_Baremetal_Debug.tja_R01_mode_ctrl =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MODE_CONTROL);

  /* Read Diagnostics */
  g_Spi_Baremetal_Debug.tja_R60_global_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_GLOBAL_EVENT_STATUS);
  g_Spi_Baremetal_Debug.tja_R61_sys_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_SYSTEM_EVENT_STATUS);
  g_Spi_Baremetal_Debug.tja_R63_trans_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS);

  if ((main_status & TJA1145_MAIN_STATUS_NMS) == 0U) {
    /* Step 10: Enable CAN Active Mode - NMS=0 = Normal mode confirmed */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
    Spi_Baremetal_Delay(20000);

    g_Spi_Baremetal_Debug.tja_init_step = 9U;
    g_Spi_Baremetal_Debug.tja_error_code = 0U;
    return 0U; /* Success - NMS=0 = Normal mode confirmed */
  } else {
    /* Failed to enter Normal Mode (NMS still 1 = not yet in Normal) */
    /* Force CAN Active (CMC=01) ANYWAY to restore partial functionality
     * (TX-only) */
    /* This ensures we at least see TXD activity on bus, even if RXD is dead */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
    Spi_Baremetal_Delay(20000);

    g_Spi_Baremetal_Debug.tja_error_code = 1U;
    return 1U; /* Failed - NMS still 1 (not yet in Normal) */
  }
}

/**
 * @brief Recover TJA1145 from Sleep/Standby mode back to Normal mode
 *
 * Handles the FSMS=1 scenario (undervoltage forced Sleep).
 * Recovery sequence:
 * 1. Full Init (NMS=1, CMC=0)
 * 2. Set CAN Active mode (CMC=01)
 *
 * @return 0 on success, non-zero on failure
 */
uint8 Spi_Baremetal_Tja1145_RecoverFromSleep(void) {
  /* Step 1: Perform full initialization sequence to get NMS=1 */
  if (Spi_Baremetal_Tja1145_Init() != 0U) {
    /* Init failed (NMS still 0) */
    return 1U;
  }

  /* Step 2: Init succeeded (NMS=1). Now set CAN Active.
   * We assume FlexCAN is already running when Recovery is called.
   */
  Spi_Baremetal_Tja1145_SetCanActive();

  return 0U;
}

/**
 * @brief Set TJA1145 CAN transceiver to Active mode
 *
 * MUST be called AFTER FlexCAN is initialized and TXD pin is properly
 * configured. If called before, TXD may be LOW causing Listen-only mode.
 *
 * Per datasheet Section 7.2.1.1:
 * "The active mode transmitter and receiver are activated once the CAN
 *  oscillator is stable and pin TXD is in the recessive state (HIGH)."
 */
void Spi_Baremetal_Tja1145_SetCanActive(void) {
  uint8 trans_status;

  /* Set CAN Active mode (CMC=01, no wake-up) */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
  Spi_Baremetal_Delay(1000);

  /* Read back and verify CTS bit */
  trans_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANS_STATUS);
  g_Spi_Baremetal_Debug.tja_R22_trans_status = trans_status;
  g_Spi_Baremetal_Debug.tja_R20_can_ctrl =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_CAN_CONTROL);
}

/**
 * @brief Periodic monitoring and auto-recovery for TJA1145
 *
 * Reads TJA1145 status registers and automatically attempts recovery:
 * 1. If not in Normal mode -> full RecoverFromSleep
 * 2. If in Normal mode but CAN not Active (CTS=0) -> re-set CMC
 *
 * Per datasheet Section 7.2.1.1: If TXD is LOW when CMC is set to Active,
 * the transceiver stays in Listen-only mode. Re-toggling CMC fixes this.
 */
void Spi_Baremetal_Tja1145_PeriodicTest(void) {
  uint8 main_status;
  uint8 can_ctrl;
  uint8 trans_status;

  /* Read Main Status - check NMS (Normal Mode Status, bit 5) */
  main_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MAIN_STATUS);
  g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;

  /* Read Mode Control */
  g_Spi_Baremetal_Debug.tja_R01_mode_ctrl =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MODE_CONTROL);

  /* Read CAN Control */
  can_ctrl = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_CAN_CONTROL);
  g_Spi_Baremetal_Debug.tja_R20_can_ctrl = can_ctrl;

  /* Read Transceiver Status (0x22) - CTS bit 7 = CAN Active status */
  trans_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANS_STATUS);
  g_Spi_Baremetal_Debug.tja_R22_trans_status = trans_status;

  /* Auto-recovery: NMS=1 means NOT yet in Normal mode (per datasheet:
   * NMS=0 = entered Normal, NMS=1 = not yet in Normal) */
  if ((main_status & TJA1145_MAIN_STATUS_NMS) != 0U) {
    (void)Spi_Baremetal_Tja1145_RecoverFromSleep();
    return;
  }

  /* CAN Active check: if CTS=0, CAN transceiver is NOT truly Active */
  if ((trans_status & 0x80U) == 0U) {
    /* Step 1: Freeze FlexCAN to stop TX -> TXD goes recessive (HIGH) */
    FlexCAN_Ip_SetStopMode(0U);
    Spi_Baremetal_Delay(500);

    /* Step 2: Set CAN Offline first */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x00U);
    Spi_Baremetal_Delay(500);

    /* Step 3: Re-enable CAN Active (CMC=01, no wake-up) - TXD is now HIGH */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
    Spi_Baremetal_Delay(1000);

    /* Step 4: Unfreeze FlexCAN to resume TX */
    FlexCAN_Ip_SetStartMode(0U);

    /* Re-read status to verify */
    g_Spi_Baremetal_Debug.tja_R22_trans_status =
        Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANS_STATUS);
    g_Spi_Baremetal_Debug.tja_R20_can_ctrl =
        Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_CAN_CONTROL);
  }

  /* ========================================================================
   * Power Supply Diagnostic Analysis
   * Analyze FSMS, VCS, PO, CF bits to diagnose undervoltage conditions.
   * Per TJA1145A datasheet:
   *   FSMS=1 (Reg 0x03 b7): Undervoltage forced Sleep
   *   VCS=1  (Reg 0x22 b1): VCC currently below Vuvd(VCC) 4.5-4.75V
   *   PO=1   (Reg 0x61 b4): Power-on event (battery was reconnected)
   *   CF=1   (Reg 0x63 b1): CAN failure (can be from VCC undervoltage)
   * ======================================================================== */
  {
    uint8 sys_event;
    uint8 trans_event;

    /* Read event registers for power diagnostics */
    sys_event = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_SYSTEM_EVENT_STATUS);
    g_Spi_Baremetal_Debug.tja_R61_sys_event = sys_event;

    trans_event =
        Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS);
    g_Spi_Baremetal_Debug.tja_R63_trans_event = trans_event;

    g_Spi_Baremetal_Debug.tja_R60_global_event =
        Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_GLOBAL_EVENT_STATUS);

    /* Track FSMS=1 (undervoltage forced Sleep) count */
    if ((main_status & TJA1145_MAIN_STATUS_FSMS) != 0U) {
      if (g_Spi_Baremetal_Debug.tja_pwr_fsms_count < 255U) {
        g_Spi_Baremetal_Debug.tja_pwr_fsms_count++;
      }
    }

    /* Track VCS=1 (active VCC undervoltage) count */
    if ((trans_status & 0x02U) != 0U) { /* VCS = bit 1 of Reg 0x22 */
      if (g_Spi_Baremetal_Debug.tja_pwr_vcs_count < 255U) {
        g_Spi_Baremetal_Debug.tja_pwr_vcs_count++;
      }
    }

    /* Track PO=1 (power-on event, bit 4 of Reg 0x61) */
    if ((sys_event & 0x10U) != 0U) {
      g_Spi_Baremetal_Debug.tja_pwr_po_detected = 1U;
    }

    /* Track CF=1 (CAN failure, bit 1 of Reg 0x63) */
    if ((trans_event & 0x02U) != 0U) {
      g_Spi_Baremetal_Debug.tja_pwr_cf_detected = 1U;
    }

    /* Set summary status (priority order: worst first) */
    if ((trans_status & 0x02U) != 0U) {
      g_Spi_Baremetal_Debug.tja_pwr_supply_status = 1U; /* VCC_UV_NOW */
    } else if ((main_status & TJA1145_MAIN_STATUS_FSMS) != 0U) {
      g_Spi_Baremetal_Debug.tja_pwr_supply_status = 2U; /* FORCED_SLEEP_UV */
    } else if ((sys_event & 0x10U) != 0U) {
      g_Spi_Baremetal_Debug.tja_pwr_supply_status = 3U; /* POWER_ON */
    } else {
      g_Spi_Baremetal_Debug.tja_pwr_supply_status = 0U; /* OK */
    }
  }
}
