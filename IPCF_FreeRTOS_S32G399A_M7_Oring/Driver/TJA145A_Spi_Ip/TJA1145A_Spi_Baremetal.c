/**
 * @file TJA1145A_Spi_Baremetal.c
 * @brief Bare-metal SPI driver for S32G3 DSPI module + TJA1145 transceiver
 * control
 * @note  S32G3 uses DSPI (De-serial SPI), NOT LPSPI!
 *
 * Delay Strategy (v2.0 optimization):
 *   All timing delays are based on TJA1145A datasheet (Rev.2, 2020-09-23)
 *   Section 11 - Dynamic Characteristics, Table 35.
 *   DWT cycle counter is used for microsecond-precision delays.
 *   Blind NOP loops have been replaced with precise µs delays or
 *   register polling where applicable.
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
 *                                     PRIVATE FUNCTIONS
 *==================================================================================================*/

/**
 * @brief  DWT-based precise microsecond delay
 *
 * Uses ARM Cortex-M7 DWT CYCCNT for timing. Assumes DWT is already enabled
 * (done by EcuM_Diag_Init via portCONFIGURE_TIMER_FOR_RUN_TIME_STATS).
 *
 * @param  us  Number of microseconds to delay (max ~10 seconds @ 400MHz)
 */
static void Spi_Baremetal_DelayUs(uint32 us) {
  /* DWT->CYCCNT register address (ARM Cortex-M7 standard) */
  volatile uint32 *const DWT_CYCCNT = (volatile uint32 *)0xE0001004UL;

  /* CPU_FREQ / 1000000 = cycles per microsecond */
  const uint32 cycles_per_us = 400U; /* 400 MHz / 1 MHz = 400 */
  uint32 start = *DWT_CYCCNT;
  uint32 target = us * cycles_per_us;

  /* Unsigned subtraction handles 32-bit counter wrap-around */
  while ((*DWT_CYCCNT - start) < target) {
    /* busy wait */
  }
}

/**
 * @brief  Short nop delay for DSPI register stabilization
 *
 * Only used for DSPI internal register setup where a few clock cycles
 * of propagation delay is sufficient. Not for TJA1145 timing.
 *
 * @param  nops  Number of NOP iterations (1 NOP ≈ 2.5ns @ 400MHz)
 */
static void Spi_Baremetal_NopDelay(uint32 nops) {
  volatile uint32 i;
  for (i = 0; i < nops; i++) {
    __asm volatile("nop");
  }
}

/*==================================================================================================
 *                                   DSPI PUBLIC FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Initialize DSPI5 module as SPI Master
 *
 * Configuration: Master mode, 8-bit frame, CPOL=0/CPHA=1 (SPI Mode 1),
 * MSB first, PCS0 inactive high, baud rate ~1MHz.
 *
 * DSPI register stabilization only needs a few bus clock cycles, not
 * hundreds of microseconds. Using minimal NOP delays here.
 */
void Spi_Baremetal_Init(uint8 baudrate_div) {
  uint32 mcr_value;
  uint32 ctar_value;
  uint32 sr;

  /* Step 1: Disable module completely (MDIS=1, HALT=1) for clean reset */
  DSPI5_REG(DSPI_MCR_OFFSET) = DSPI_MCR_MDIS_MASK | DSPI_MCR_HALT_MASK;
  Spi_Baremetal_NopDelay(20); /* ~50ns: allow register write to propagate */

  /* Step 2: Clear ALL status flags (W1C), especially EOQF */
  DSPI5_REG(DSPI_SR_OFFSET) = 0xFFFF0000UL;
  /* No delay needed: W1C takes effect immediately */

  /* Step 3: Enable module, Master mode, keep HALT, clear FIFOs */
  mcr_value = DSPI_MCR_MSTR_MASK | DSPI_MCR_PCSIS0_MASK | DSPI_MCR_HALT_MASK |
              DSPI_MCR_CLR_TXF_MASK | DSPI_MCR_CLR_RXF_MASK;
  DSPI5_REG(DSPI_MCR_OFFSET) = mcr_value;
  Spi_Baremetal_NopDelay(20); /* ~50ns: FIFO clear propagation */

  /* Step 4: Configure CTAR0 - TJA1145 requires SPI Mode 1 (CPOL=0, CPHA=1) */
  ctar_value =
      (7UL << DSPI_CTAR_FMSZ_SHIFT) |   /* 8-bit frame (FMSZ = 7) */
      DSPI_CTAR_CPHA_MASK |             /* CPHA=1 for SPI Mode 1 */
      (0UL << DSPI_CTAR_PBR_SHIFT) |    /* Baud rate prescaler = 2 */
      (1UL << DSPI_CTAR_PCSSCK_SHIFT) | /* PCS to SCK delay prescaler */
      (1UL << DSPI_CTAR_PASC_SHIFT) |   /* After SCK delay prescaler */
      (1UL << DSPI_CTAR_PDT_SHIFT) |    /* Delay after transfer prescaler */
      (4UL << DSPI_CTAR_CSSCK_SHIFT) |  /* PCS to SCK delay scaler */
      (4UL << DSPI_CTAR_ASC_SHIFT) |    /* After SCK delay scaler */
      (4UL << DSPI_CTAR_DT_SHIFT) |     /* Delay after transfer scaler */
      ((uint32)baudrate_div << DSPI_CTAR_BR_SHIFT);
  DSPI5_REG(DSPI_CTAR0_OFFSET) = ctar_value;

  /* Step 5: Disable all DMA and interrupt requests */
  DSPI5_REG(DSPI_RSER_OFFSET) = 0x00000000UL;

  /* Step 6: Clear all status flags again before starting */
  DSPI5_REG(DSPI_SR_OFFSET) = 0xFFFF0000UL;

  /* Step 7: Release HALT to start module */
  mcr_value = DSPI_MCR_MSTR_MASK | DSPI_MCR_PCSIS0_MASK;
  DSPI5_REG(DSPI_MCR_OFFSET) = mcr_value;
  Spi_Baremetal_NopDelay(20); /* ~50ns: module start-up propagation */

  /* Step 8: Verify and capture debug info */
  sr = DSPI5_REG(DSPI_SR_OFFSET);

  if ((sr & DSPI_SR_TFFF_MASK) == 0U) {
    g_Spi_Baremetal_Debug.error_code = 10U; /* TFFF not ready */
  }
  if ((sr & DSPI_SR_EOQF_MASK) != 0U) {
    g_Spi_Baremetal_Debug.error_code = 11U; /* EOQF still set */
  }

  g_Spi_Baremetal_Debug.dspi_mcr = DSPI5_REG(DSPI_MCR_OFFSET);
  g_Spi_Baremetal_Debug.dspi_sr = sr;
  g_Spi_Baremetal_Debug.dspi_ctar0 = DSPI5_REG(DSPI_CTAR0_OFFSET);
  g_Spi_Baremetal_Debug.init_ok = 1U;
}

/**
 * @brief Transfer a single byte over DSPI5 with optional continuous CS
 *
 * PUSHR register format (Master mode):
 *   Bit 31: CONT (Continuous PCS)
 *   Bits 30-28: CTAS (CTAR Select)
 *   Bit 27: EOQ (End of Queue) - DO NOT set, stops the module!
 *   Bits 21-16: PCS select
 *   Bits 15-0: TXDATA
 *
 * @param tx_byte  Byte to transmit
 * @param cont_cs  1=Keep CS asserted, 0=Release CS after transfer
 * @return Received byte (0xFF on timeout error)
 */
uint8 Spi_Baremetal_TransferEx(uint8 tx_byte, uint8 cont_cs) {
  uint32 pushr_value;
  uint32 sr;
  uint32 timeout;
  uint32 rx_data;

  /* Clear status flags from previous transfers */
  DSPI5_REG(DSPI_SR_OFFSET) = DSPI_SR_TCF_MASK | DSPI_SR_EOQF_MASK |
                              DSPI_SR_TFFF_MASK | DSPI_SR_RFDF_MASK;

  /* Build PUSHR: PCS0 + data, optionally CONT */
  pushr_value =
      DSPI_PUSHR_PCS0_MASK | ((uint32)tx_byte & DSPI_PUSHR_TXDATA_MASK);
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
    g_Spi_Baremetal_Debug.error_code = 1U; /* TX FIFO full timeout */
    return 0xFFU;
  }

  /* Push data to start transfer */
  DSPI5_REG(DSPI_PUSHR_OFFSET) = pushr_value;
  DSPI5_REG(DSPI_SR_OFFSET) = DSPI_SR_TFFF_MASK; /* Clear TFFF */

  /* Wait for transfer complete */
  timeout = 100000U;
  do {
    sr = DSPI5_REG(DSPI_SR_OFFSET);
    timeout--;
  } while (((sr & (DSPI_SR_TCF_MASK | DSPI_SR_RFDF_MASK)) == 0U) &&
           (timeout > 0U));

  if (timeout == 0U) {
    g_Spi_Baremetal_Debug.error_code = 2U; /* Transfer timeout */
    return 0xFFU;
  }

  /* Clear TCF and RFDF flags */
  DSPI5_REG(DSPI_SR_OFFSET) = DSPI_SR_TCF_MASK | DSPI_SR_RFDF_MASK;

  /* Read received data */
  rx_data = DSPI5_REG(DSPI_POPR_OFFSET);

  return (uint8)(rx_data & 0xFFU);
}

/*==================================================================================================
 *                                  TJA1145 FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Read a TJA1145 register via SPI
 *
 * TJA1145 SPI protocol (datasheet Section 7.12):
 * - 16-bit transfer: 8-bit command + 8-bit data
 * - Command byte: [A6:A0][R/W] where R/W=1 for read
 */
uint8 Spi_Baremetal_Tja1145_ReadReg(uint8 addr) {
  uint8 read_cmd = (uint8)((addr << 1U) | 0x01U);

  /* Byte 1: address + read bit, keep CS low */
  (void)Spi_Baremetal_TransferEx(read_cmd, 1U);

  /* Byte 2: dummy TX, read response, release CS */
  return Spi_Baremetal_TransferEx(0x00U, 0U);
}

/**
 * @brief Write a TJA1145 register via SPI
 *
 * Command byte: [A6:A0][R/W] where R/W=0 for write
 */
void Spi_Baremetal_Tja1145_WriteReg(uint8 addr, uint8 data) {
  uint8 write_cmd = (uint8)((addr << 1U) | 0x00U);

  /* Byte 1: address + write bit, keep CS low */
  (void)Spi_Baremetal_TransferEx(write_cmd, 1U);

  /* Byte 2: data, release CS */
  (void)Spi_Baremetal_TransferEx(data, 0U);
}

/**
 * @brief Clear all TJA1145 event status registers and disable all wake-up
 * sources
 *
 * Per TJA1145 datasheet Section 7.6.2:
 * All event status bits must be cleared before mode transitions.
 * All wake-up sources must be disabled to prevent re-entering Sleep.
 */
static void Spi_Baremetal_Tja1145_ClearEventsAndDisableWakeup(void) {
  /* Clear all event status registers (W1C) */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_STATUS, 0xFFU);
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS, 0xFFU);
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EVENT, 0xFFU);

  /* Disable ALL wake-up sources */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANS_EVENT_EN, 0x00U);
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EN, 0x00U);
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_EN, 0x00U);
}

/**
 * @brief Initialize TJA1145 and set to Normal mode
 *
 * Timing references (TJA1145A datasheet Rev.2, Section 11, Table 35):
 *   - t_startup: max 4.7ms (power-on to INH active)
 *   - t_startup(CAN): max 220µs (CAN mode switch to Active, CTS=1)
 *   - t_WH(S): min 250ns (SCSN high pulse width in Normal/Standby)
 *   - SPI register writes take effect after CS release (next t_WH(S))
 *   - No specified minimum delay between consecutive SPI commands
 *   - NMS bit reflects mode status and can be polled immediately
 *
 * Previous version used blind delays totaling ~25ms for 5 retries.
 * This version uses:
 *   - Precise µs delays where datasheet specifies timing requirements
 *   - Register polling for NMS confirmation (instead of blind 2.5ms wait)
 *   - Minimal inter-command gaps (SPI protocol handles its own CS timing)
 *
 * @return 0 on success, 1 on failure (NMS not achieved)
 */
uint8 Spi_Baremetal_Tja1145_Init(void) {
  uint8 device_id;
  uint8 main_status;
  uint8 i;
  uint32 poll;

  g_Spi_Baremetal_Debug.tja_error_code = 0U;

  /* Step 1: Read Device ID (0x7E) to verify SPI communication */
  device_id = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_DEVICE_ID);
  g_Spi_Baremetal_Debug.tja_R7E_device_id = device_id;

  if ((device_id != 0x70U) && (device_id != 0x74U) && (device_id != 0x80U)) {
    g_Spi_Baremetal_Debug.tja_error_code = 2U;
    /* Continue anyway to try recovery */
  }

  /* Step 2: Read Main Status */
  main_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MAIN_STATUS);
  g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;

  /*
   * Step 3: Wait for VCC/VIO to stabilize after power-on.
   * Datasheet t_startup max = 4.7ms. However, by the time we reach here,
   * PMIC has been initialized and SPI communication was already verified
   * by reading Device ID. Use a conservative 2ms wait.
   */
  Spi_Baremetal_DelayUs(2000);

  /* Retry loop for mode transition (up to 5 attempts) */
  for (i = 0; i < 5; i++) {
    g_Spi_Baremetal_Debug.tja_init_step = 40U + i;

    /* Force CAN Offline (CMC=00) to stop bus-side activity */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x00U);
    /*
     * No delay needed after SPI write: the register update takes effect
     * on CS release. The next SPI transaction provides natural spacing
     * (t_WH(S) min 250ns is handled by DSPI CS timing in CTAR).
     */

    /* Disable all wake-up sources and clear events */
    Spi_Baremetal_Tja1145_ClearEventsAndDisableWakeup();

    /* Transition: -> Standby (MC=0x04) */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_MODE_CONTROL,
                                   TJA1145_MODE_STANDBY);
    /*
     * Standby mode transition: datasheet does not specify a minimum
     * waiting time. The internal state machine processes this synchronously
     * with the SPI clock. A 50µs guard is conservative.
     */
    Spi_Baremetal_DelayUs(50);

    /* Clear events again (clean slate before Normal) */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_SYSTEM_EVENT_STATUS, 0xFFU);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS, 0xFFU);
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_WAKE_PIN_EVENT, 0xFFU);

    /* Transition: -> Normal (MC=0x07) */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_MODE_CONTROL,
                                   TJA1145_MODE_NORMAL);

    /*
     * Poll NMS bit instead of blind waiting.
     * NMS=0 indicates Normal mode entered successfully.
     * The oscillator and internal logic need time to settle, so we poll
     * with a 100µs interval, up to 5ms total (well beyond typical need).
     * Previous code used a blind 2.5ms wait.
     */
    for (poll = 0; poll < 50U; poll++) {
      Spi_Baremetal_DelayUs(100);
      main_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MAIN_STATUS);
      if ((main_status & TJA1145_MAIN_STATUS_NMS) == 0U) {
        break; /* NMS=0: Normal mode confirmed */
      }
    }

    if ((main_status & TJA1145_MAIN_STATUS_NMS) == 0U) {
      g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;
      break; /* Success */
    }

    /*
     * If NMS still 1 after polling, short pause before retry to allow
     * any transient condition to settle.
     */
    Spi_Baremetal_DelayUs(200);
  }

  /* Capture final status */
  g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;
  g_Spi_Baremetal_Debug.tja_R01_mode_ctrl =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MODE_CONTROL);
  g_Spi_Baremetal_Debug.tja_R60_global_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_GLOBAL_EVENT_STATUS);
  g_Spi_Baremetal_Debug.tja_R61_sys_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_SYSTEM_EVENT_STATUS);
  g_Spi_Baremetal_Debug.tja_R63_trans_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS);

  /*
   * Enable CAN Active mode regardless of NMS result.
   * Datasheet t_startup(CAN) max = 220µs for CTS to become 1.
   * We wait 250µs to cover worst-case.
   */
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
  Spi_Baremetal_DelayUs(250);

  if ((main_status & TJA1145_MAIN_STATUS_NMS) == 0U) {
    g_Spi_Baremetal_Debug.tja_error_code = 0U;
    return 0U; /* Success */
  } else {
    g_Spi_Baremetal_Debug.tja_error_code = 1U;
    return 1U; /* Failed - NMS still set */
  }
}

/**
 * @brief Recover TJA1145 from Sleep/Standby mode back to Normal mode
 *
 * Handles FSMS=1 scenario (undervoltage forced Sleep).
 * Performs full init + re-sets CAN Active.
 *
 * @return 0 on success, non-zero on failure
 */
uint8 Spi_Baremetal_Tja1145_RecoverFromSleep(void) {
  if (Spi_Baremetal_Tja1145_Init() != 0U) {
    return 1U;
  }
  Spi_Baremetal_Tja1145_SetCanActive();
  return 0U;
}

/**
 * @brief Set TJA1145 CAN transceiver to Active mode
 *
 * MUST be called AFTER FlexCAN is initialized and TXD is recessive (HIGH).
 * Per datasheet Section 7.2.1.1: CAN transceiver activates only when
 * TXD is in recessive state.
 *
 * Datasheet t_startup(CAN) max = 220µs for CTS transition.
 * We wait 250µs before reading back status.
 */
void Spi_Baremetal_Tja1145_SetCanActive(void) {
  Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
  Spi_Baremetal_DelayUs(250); /* t_startup(CAN) max 220µs */

  g_Spi_Baremetal_Debug.tja_R22_trans_status =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANS_STATUS);
  g_Spi_Baremetal_Debug.tja_R20_can_ctrl =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_CAN_CONTROL);
}

/**
 * @brief Periodic monitoring and auto-recovery for TJA1145
 *
 * Called every ~100ms. Reads status and auto-recovers:
 * - If not in Normal mode -> full RecoverFromSleep
 * - If in Normal but CAN not Active (CTS=0) -> re-toggle CMC
 * - Tracks power supply diagnostics (FSMS, VCS, PO, CF)
 *
 * Timing note: This runs in a 10ms RTOS task context. All delays here
 * must be minimal to avoid blocking the task beyond its period.
 * Previous delays were ~1.25µs each (already small), now made precise.
 */
void Spi_Baremetal_Tja1145_PeriodicTest(void) {
  uint8 main_status;
  uint8 can_ctrl;
  uint8 trans_status;
  uint8 sys_event;
  uint8 trans_event;

  /* Read key registers */
  main_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MAIN_STATUS);
  g_Spi_Baremetal_Debug.tja_R03_main_status = main_status;

  g_Spi_Baremetal_Debug.tja_R01_mode_ctrl =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_MODE_CONTROL);

  can_ctrl = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_CAN_CONTROL);
  g_Spi_Baremetal_Debug.tja_R20_can_ctrl = can_ctrl;

  trans_status = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANS_STATUS);
  g_Spi_Baremetal_Debug.tja_R22_trans_status = trans_status;

  /* ---------- Auto-recovery ---------- */

  /* NMS=1 means NOT in Normal mode -> full recovery */
  if ((main_status & TJA1145_MAIN_STATUS_NMS) != 0U) {
    (void)Spi_Baremetal_Tja1145_RecoverFromSleep();
    return;
  }

  /* CTS=0 means CAN transceiver NOT active -> re-toggle CMC */
  if ((trans_status & 0x80U) == 0U) {
    /* Freeze FlexCAN so TXD goes recessive (HIGH) */
    FlexCAN_Ip_SetStopMode(0U);
    Spi_Baremetal_DelayUs(10); /* Allow FlexCAN to enter freeze */

    /* CMC: Offline -> Active */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x00U);
    /* No delay needed: next SPI transaction provides natural CS spacing */
    Spi_Baremetal_Tja1145_WriteReg(TJA1145_REG_CAN_CONTROL, 0x01U);
    Spi_Baremetal_DelayUs(250); /* t_startup(CAN) max 220µs */

    /* Unfreeze FlexCAN */
    FlexCAN_Ip_SetStartMode(0U);

    /* Re-read status */
    g_Spi_Baremetal_Debug.tja_R22_trans_status =
        Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANS_STATUS);
    g_Spi_Baremetal_Debug.tja_R20_can_ctrl =
        Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_CAN_CONTROL);
  }

  /* ---------- Power Supply Diagnostics ---------- */
  sys_event = Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_SYSTEM_EVENT_STATUS);
  g_Spi_Baremetal_Debug.tja_R61_sys_event = sys_event;

  trans_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_TRANSCEIVER_EVENT_STATUS);
  g_Spi_Baremetal_Debug.tja_R63_trans_event = trans_event;

  g_Spi_Baremetal_Debug.tja_R60_global_event =
      Spi_Baremetal_Tja1145_ReadReg(TJA1145_REG_GLOBAL_EVENT_STATUS);

  /* Track FSMS=1 (undervoltage forced Sleep) */
  if ((main_status & TJA1145_MAIN_STATUS_FSMS) != 0U) {
    if (g_Spi_Baremetal_Debug.tja_pwr_fsms_count < 255U) {
      g_Spi_Baremetal_Debug.tja_pwr_fsms_count++;
    }
  }

  /* Track VCS=1 (active VCC undervoltage, Reg 0x22 bit 1) */
  if ((trans_status & 0x02U) != 0U) {
    if (g_Spi_Baremetal_Debug.tja_pwr_vcs_count < 255U) {
      g_Spi_Baremetal_Debug.tja_pwr_vcs_count++;
    }
  }

  /* Track PO=1 (power-on event, Reg 0x61 bit 4) */
  if ((sys_event & 0x10U) != 0U) {
    g_Spi_Baremetal_Debug.tja_pwr_po_detected = 1U;
  }

  /* Track CF=1 (CAN failure, Reg 0x63 bit 1) */
  if ((trans_event & 0x02U) != 0U) {
    g_Spi_Baremetal_Debug.tja_pwr_cf_detected = 1U;
  }

  /* Summary status (priority: worst first) */
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
