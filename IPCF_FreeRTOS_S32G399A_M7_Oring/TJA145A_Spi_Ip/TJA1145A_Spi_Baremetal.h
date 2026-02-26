/**
 * @file TJA1145A_Spi_Baremetal.h
 * @brief Bare-metal SPI driver for S32G3 DSPI module + TJA1145 transceiver
 * control
 * @note  S32G3 uses DSPI (De-serial SPI), NOT LPSPI!
 */

#ifndef SPI_BAREMETAL_H
#define SPI_BAREMETAL_H

/*==================================================================================================
 *                                          INCLUDES
 *==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                                     DSPI5 REGISTER MACROS
 *==================================================================================================*/

/* DSPI5 Base Address - S32G3 Reference Manual: SPI_5 = 0x402D_0000 */
#define DSPI5_BASE (0x402D0000UL)

/* DSPI Register Offsets (S32G3 RM Section 49.6) */
#define DSPI_MCR_OFFSET (0x00UL) /* Module Configuration Register */
#define DSPI_TCR_OFFSET (0x08UL) /* Transfer Count Register */
#define DSPI_CTAR0_OFFSET                                                      \
  (0x0CUL) /* Clock and Transfer Attributes Register 0 */
#define DSPI_CTAR1_OFFSET                                                      \
  (0x10UL)                        /* Clock and Transfer Attributes Register 1 */
#define DSPI_SR_OFFSET (0x2CUL)   /* Status Register */
#define DSPI_RSER_OFFSET (0x30UL) /* DMA/Interrupt Request Select and Enable   \
                                   */
#define DSPI_PUSHR_OFFSET (0x34UL) /* PUSH TX FIFO Register */
#define DSPI_POPR_OFFSET (0x38UL)  /* POP RX FIFO Register */
#define DSPI_TXFR0_OFFSET (0x3CUL) /* Transmit FIFO Register 0 */
#define DSPI_RXFR0_OFFSET (0x7CUL) /* Receive FIFO Register 0 */
#define DSPI_CTARE0_OFFSET                                                     \
  (0x11CUL) /* Clock and Transfer Attributes Extended 0 */
#define DSPI_SREX_OFFSET (0x13CUL) /* Status Register Extended */

/* MCR Field Definitions */
#define DSPI_MCR_MSTR_MASK (0x80000000UL) /* Master Mode Select (bit 31) */
#define DSPI_MCR_CONT_SCKE_MASK                                                \
  (0x40000000UL)                         /* Continuous SCK Enable (bit 30) */
#define DSPI_MCR_FRZ_MASK (0x08000000UL) /* Freeze (bit 27) */
#define DSPI_MCR_PCSIS0_MASK                                                   \
  (0x00010000UL) /* PCS0 Inactive State High (bit 16) */
#define DSPI_MCR_MDIS_MASK (0x00004000UL)    /* Module Disable (bit 14) */
#define DSPI_MCR_DIS_TXF_MASK (0x00002000UL) /* Disable TX FIFO (bit 13) */
#define DSPI_MCR_DIS_RXF_MASK (0x00001000UL) /* Disable RX FIFO (bit 12) */
#define DSPI_MCR_CLR_TXF_MASK (0x00000800UL) /* Clear TX FIFO (bit 11) */
#define DSPI_MCR_CLR_RXF_MASK (0x00000400UL) /* Clear RX FIFO (bit 10) */
#define DSPI_MCR_HALT_MASK (0x00000001UL)    /* Halt (bit 0) */

/* SR (Status Register) Field Definitions */
#define DSPI_SR_TCF_MASK (0x80000000UL)   /* Transfer Complete Flag (bit 31) */
#define DSPI_SR_TXRXS_MASK (0x40000000UL) /* TX and RX Status (bit 30) */
#define DSPI_SR_EOQF_MASK (0x10000000UL)  /* End of Queue Flag (bit 28) */
#define DSPI_SR_TFUF_MASK (0x08000000UL)  /* TX FIFO Underflow Flag (bit 27) */
#define DSPI_SR_TFFF_MASK (0x02000000UL)  /* TX FIFO Fill Flag (bit 25) */
#define DSPI_SR_RFOF_MASK (0x00080000UL)  /* RX FIFO Overflow Flag (bit 19) */
#define DSPI_SR_RFDF_MASK (0x00020000UL)  /* RX FIFO Drain Flag (bit 17) */
#define DSPI_SR_TXCTR_SHIFT (12U)
#define DSPI_SR_TXCTR_MASK (0x0000F000UL)
#define DSPI_SR_RXCTR_SHIFT (4U)
#define DSPI_SR_RXCTR_MASK (0x000000F0UL)

/* CTAR Field Definitions */
#define DSPI_CTAR_DBR_MASK (0x80000000UL) /* Double Baud Rate (bit 31) */
#define DSPI_CTAR_FMSZ_SHIFT (27U)
#define DSPI_CTAR_FMSZ_MASK (0x78000000UL)
#define DSPI_CTAR_CPOL_MASK (0x04000000UL)  /* Clock Polarity (bit 26) */
#define DSPI_CTAR_CPHA_MASK (0x02000000UL)  /* Clock Phase (bit 25) */
#define DSPI_CTAR_LSBFE_MASK (0x01000000UL) /* LSB First (bit 24) */
#define DSPI_CTAR_PCSSCK_SHIFT (22U)
#define DSPI_CTAR_PASC_SHIFT (20U)
#define DSPI_CTAR_PDT_SHIFT (18U)
#define DSPI_CTAR_PBR_SHIFT (16U)
#define DSPI_CTAR_CSSCK_SHIFT (12U)
#define DSPI_CTAR_ASC_SHIFT (8U)
#define DSPI_CTAR_DT_SHIFT (4U)
#define DSPI_CTAR_BR_SHIFT (0U)

/* PUSHR Field Definitions (Master Mode) */
#define DSPI_PUSHR_CONT_MASK (0x80000000UL) /* Continuous PCS (bit 31) */
#define DSPI_PUSHR_CTAS_SHIFT (28U)
#define DSPI_PUSHR_CTAS_MASK (0x70000000UL)
#define DSPI_PUSHR_EOQ_MASK (0x08000000UL) /* End of Queue (bit 27) */
#define DSPI_PUSHR_CTCNT_MASK                                                  \
  (0x04000000UL)                          /* Clear Transfer Counter (bit 26) */
#define DSPI_PUSHR_PE_MASK (0x02000000UL) /* Parity Enable (bit 25) */
#define DSPI_PUSHR_PP_MASK (0x01000000UL) /* Parity Polarity (bit 24) */
#define DSPI_PUSHR_PCS0_MASK (0x00010000UL)   /* PCS0 (bit 16) */
#define DSPI_PUSHR_TXDATA_MASK (0x0000FFFFUL) /* TX Data (bits 15-0) */

/* Register access macro */
#define DSPI5_REG(offset) (*((volatile uint32 *)(DSPI5_BASE + (offset))))

/*==================================================================================================
 *                                      DEBUG STRUCTURE
 *==================================================================================================*/

/**
 * @brief Runtime debug/diagnostic data for DSPI and TJA1145
 *
 * This structure is kept volatile so TRACE32 can read it at any time.
 * It captures key register snapshots and TJA1145 status for diagnostics.
 */
typedef struct {
  /* DSPI register snapshots (captured during init) */
  uint32 dspi_mcr;
  uint32 dspi_sr;
  uint32 dspi_ctar0;

  /* SPI transfer status */
  uint8 init_ok;    /* 1=DSPI init succeeded */
  uint8 error_code; /* Error code: 0=OK, 1=TX timeout, 2=RX timeout, 10=TFFF,
                       11=EOQF */

  /* TJA1145 init status */
  uint8 tja_init_step;  /* Last completed init step */
  uint8 tja_error_code; /* TJA1145 error: 0=OK, 1=NMS fail, 2=Device ID mismatch
                         */

  /* TJA1145 register snapshots (Rxx = register address) */
  uint8 tja_R7E_device_id;    /* Reg 0x7E: Device Identification */
  uint8 tja_R03_main_status;  /* Reg 0x03: Main Status (FSMS=b7, NMS=b5) */
  uint8 tja_R01_mode_ctrl;    /* Reg 0x01: Mode Control (MC=b2:0) */
  uint8 tja_R20_can_ctrl;     /* Reg 0x20: CAN Control (CMC=b1:0) */
  uint8 tja_R60_global_event; /* Reg 0x60: Global Event Status */
  uint8 tja_R61_sys_event;    /* Reg 0x61: System Event Status */
  uint8 tja_R63_trans_event;  /* Reg 0x63: Transceiver Event Status */
  uint8
      tja_R22_trans_status; /* Reg 0x22: Transceiver Status (CTS=b7, VCS=b1) */

  /* Power supply diagnostics (updated by PeriodicTest) */
  uint8 tja_pwr_fsms_count; /* Count of FSMS=1 detections (undervoltage forced
                               Sleep) */
  uint8 tja_pwr_vcs_count;  /* Count of VCS=1 detections (active VCC
                               undervoltage) */
  uint8
      tja_pwr_po_detected; /* PO bit detected (power-on event from 0x61 bit4) */
  uint8 tja_pwr_cf_detected; /* CF bit detected (CAN failure from 0x63 bit1) */
  uint8 tja_pwr_supply_status; /* 0=OK, 1=VCC_UV_NOW, 2=FORCED_SLEEP_UV,
                                  3=POWER_ON */
} Spi_Baremetal_Debug_t;

extern volatile Spi_Baremetal_Debug_t g_Spi_Baremetal_Debug;

/*==================================================================================================
 *                                      DSPI API FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Initialize DSPI5 module as Master
 * @param baudrate_div Baud rate scaler value (0-15, higher = slower)
 */
void Spi_Baremetal_Init(uint8 baudrate_div);

/**
 * @brief Transfer a single byte over DSPI5 with optional continuous CS
 * @param tx_byte  Byte to transmit
 * @param cont_cs  1=Keep CS asserted after transfer, 0=Release CS
 * @return Received byte
 */
uint8 Spi_Baremetal_TransferEx(uint8 tx_byte, uint8 cont_cs);

/*==================================================================================================
 *                                    TJA1145 REGISTER DEFINITIONS
 *==================================================================================================*/

#define TJA1145_REG_MODE_CONTROL 0x01
#define TJA1145_REG_MAIN_STATUS 0x03
#define TJA1145_REG_SYSTEM_EVENT_EN 0x04
#define TJA1145_REG_CAN_CONTROL 0x20
#define TJA1145_REG_TRANS_STATUS 0x22 /* CTS(bit7), CFS(bit0) */
#define TJA1145_REG_TRANS_EVENT_EN 0x23
#define TJA1145_REG_WAKE_PIN_STATUS 0x4B
#define TJA1145_REG_WAKE_PIN_EN 0x4C
#define TJA1145_REG_GLOBAL_EVENT_STATUS 0x60
#define TJA1145_REG_SYSTEM_EVENT_STATUS 0x61
#define TJA1145_REG_TRANSCEIVER_EVENT_STATUS 0x63
#define TJA1145_REG_WAKE_PIN_EVENT 0x64 /* W1C */
#define TJA1145_REG_DEVICE_ID 0x7E

/* Main Status register bit definitions */
#define TJA1145_MAIN_STATUS_FSMS (1U << 7) /* Forced Sleep Mode Status */
#define TJA1145_MAIN_STATUS_OTWS (1U << 6) /* Overtemperature Warning */
#define TJA1145_MAIN_STATUS_NMS                                                \
  (1U << 5) /* Normal Mode Status: 0=Normal, 1=NOT Normal */

/* Mode control values */
#define TJA1145_MODE_NORMAL 0x07
#define TJA1145_MODE_STANDBY 0x04
#define TJA1145_MODE_SLEEP 0x01

/*==================================================================================================
 *                                    TJA1145 API FUNCTIONS
 *==================================================================================================*/

uint8 Spi_Baremetal_Tja1145_ReadReg(uint8 addr);
void Spi_Baremetal_Tja1145_WriteReg(uint8 addr, uint8 data);
uint8 Spi_Baremetal_Tja1145_Init(void);
uint8 Spi_Baremetal_Tja1145_RecoverFromSleep(void);
void Spi_Baremetal_Tja1145_SetCanActive(void);
void Spi_Baremetal_Tja1145_PeriodicTest(void);

#endif /* SPI_BAREMETAL_H */
