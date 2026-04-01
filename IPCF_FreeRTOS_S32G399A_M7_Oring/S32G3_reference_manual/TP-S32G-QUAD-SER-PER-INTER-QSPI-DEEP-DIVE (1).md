## QSPI DEEP DIVE

F E B R U A R Y   2 0 2 3 VCNS Systems &amp; Applications

<!-- image -->

<!-- image -->

<!-- image -->

## Agenda

1. QSPI Overview
2. QSPI Pins Configuration
3. QSPI Clock Configuration
4. QSPI Register Configuration
5. QSPI Boot
6. Flash Tool &amp; Flash SDK
7. Flash Driver

<!-- image -->

## QSPI Overview

<!-- image -->

PUBLIC

2

## S32G QSPI OVERVIEW

<!-- image -->

## Various flash support

## Multiple protocol support

## Multiple sampling mode support

## Multiple access mode

## Multiple port support

- Flexible sequence engine to support various flash memory vendor devices
- Single, Dual, Quad, and Octal I/O data lines to transfer
- Single Data Rate(SDR) mode
- Double Data Rate(DDR) mode, further increase throughput
- Peripheral bus access(32-bit access)
- AHB master to read data through AMBA AHB(64-bit width interface)
- Support to connect two serial flash memory devices
- Support Dual-die flash

<!-- image -->

## QSPI Pins Configuration

<!-- image -->

PUBLIC

4

## QSPI PINS

## QSPI external signals

- The QSPI module supports 2 interfaces: QSPI A &amp; QSPI B
- The function of the QSPI pins can be selected in Multiplexed Signal Configuration Registers (MSCRs) and Input Multiplexed Signal Configuration Registers (IMCRs) in System Integration Unit Lite2 (SIUL2)

| Chip Select   | • Chip select is an active low signal and used to indicate that a transmit or receive is active                                                       |
|---------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| Clock         | • This signal is the serial clock output to the serial flash memory device                                                                            |
| Data          | • These signals are the data I/O lines to/from the serial flash memory device                                                                         |
| DQS           | • The source of the clock signal used for sampling incoming data can be selected in the DQS_FA/B_SEL field of the Module Configuration Register (MCR) |
| Interrupt     | • External flash memory drives it to active low value in case of an ECC error                                                                         |

| Port   | CR   | CRInstance Name   |       555 | Addr       | Function         | Description                      | Direction   |
|--------|------|-------------------|-----------|------------|------------------|----------------------------------|-------------|
| PC_14  |      |                   | 0000_0010 |            | QSPI_DATA_B_O[0] | QuadSPIBData 0                   | 0           |
| PC_14  |      | 552               | 0000_0010 | 0x4009CAE0 | QSPI_DATA_B_1[0] | QuadSPIBData 0                   | 1           |
| PC_15  |      | SIUL_CC           | 0000_0010 |            | QSPI_DATA_B_0[3] | QuadSPI B Data 3                 | 0           |
| PC_15  |      | 553               | 0000_0010 | 0x4009CAE4 | QSPI_DATA_B_1[3] | QuadSPI BData 3                  | 1           |
| PD_00  |      | SIUL_CC           | 0000_0010 |            | QSPI_CS_BO       | QuadSPI B Chip Select O          | 0           |
| PD_01  |      |                   | 0000_0010 |            | QSPI_CS_B1       | QuadSPI B Chip Select 1          | 0           |
| PD_01  |      | 559               | 0000_0010 | 0x4009CAFC | QSPI_INTB_b      | QuadSPIBInterrupt                | 1           |
| PD_02  |      | SIUL_CC           | 0000_0010 |            | QSPI_DATA_B_O[4] | QuadSPI B Data 4                 | 0           |
| PD_02  |      | 557               | 0000_0010 | 0x4009CAF4 | QSPI_DATA_B_1[4] | QuadSPIB Data4                   | 1           |
| PD_03  |      | SIUL_CC           | 0000_0010 |            | QSPI_DATA_B_O[1] | QuadSPIBData 1                   | 0           |
| PD_03  | 554  | SIUL_CC           | 0000_0010 | 0x4009CAE8 | QSPI_DATA_B_[1]  | QuadSPIBData 1                   | 1           |
| PD_04  |      |                   | 0000_0010 |            | QSPI_DQS_B_O     | Quad SPIB Data Strobe            | 0           |
| PD_04  | 558  | SIUL_CC           | 0000_0010 | 0x4009CAF8 | QSPI_DQS_B_1     | Quad SPIB Data Strobe            |             |
| PD_05  |      |                   | 0000_0010 |            | QSPI_DATA_B_O[7] | QuadSPI BData 7                  | 0           |
| PD_05  | 555  | SIUL_CC           | 0000_0010 | 0x4009CAEC | QSPI_DATA_B_1[7] | QuadSPI B Data 7                 | 1           |
| PD_06  |      |                   | 0000_0010 |            | QSPI_CK_B        | QuadSPISerial Clock Flash B+     | 0           |
| PD_07  |      |                   | 0000_0010 |            | QSPI_CK_B_b      | QuadSPI Serial Clock Flash B-    | 0           |
| PD_08  |      |                   | 0000_0010 |            | QSPI_DATA_B_O[5] | QuadSPIBData 5                   | 0           |
| PD_08  | 550  | SIUL_CC           | 0000_0010 | 0x4009CAD8 | QSPI_DATA_B_1[5] | QuadSPIBData5                    | 一           |
| PD_09  |      |                   | 0000_0010 |            | QSPI_DATA_B_O[2] | QuadSPIBData 2                   | 0           |
| PD_09  | 551  | SIUL_CC           | 0000_0010 | 0x4009CADC | QSPI_DATA_B_1[2] | QuadSPIBData 2                   | 1           |
| PD_10  |      |                   | 0000_0010 |            | QSPI_DATA_B_O[6] | QuadSPIBData 6                   | 0           |
| PD_10  | 556  | SIUL_CC           | 0000_0010 | 0x4009CAFO | QSPI_DATA_B_1[6] | QuadSPIBData6                    | 1           |
| PF_05  |      |                   | 0000_0001 |            | QSPI_DATA_A_O[0] | QuadSPIAData 0                   | 0           |
| PF_05  | 540  | SIUL_CC           | 0000_0010 | 0x4009CAB0 | QSPI_DATA_A_1[0] | QuadSPIAData 0                   |             |
| PF_06  |      |                   | 0000_0001 |            | QSPI_DATA_A_0[1] | QuadSPIAData 1                   | 0           |
| PF_06  | 541  | SIUL_CC           | 0000_0010 | 0x4009CAB4 | QSPI_DATA_A_I[1] | QuadSPIAData 1                   |             |
| PF_07  |      |                   | 0000_0001 |            | QSPI_DATA_A_0[2] | QuadSPIAData 2                   | 0           |
| PF_07  | 542  | SIUL_CC           | 0000_0010 | 0x4009CAB8 | QSPI_DATA_A_1[2] | QuadSPIAData 2                   | 1           |
| PF_08  |      |                   | 0000_0001 |            | QSPI_DATA_A_0[3] | QuadSPIAData 3                   |             |
| PF_08  | 543  | SIUL_CC           | 0000_0010 | 0x4009CABC | QSPI_DATA_A_1[3] | QuadSPIAData 3                   | 1           |
| PF_09  |      |                   | 0000_0001 |            | QSPI_DATA_A_O[4] | QuadSPIAData 4                   | 0           |
| PF_09  | 544  | SIUL_CC           | 0000_0010 | 0x4009CAC0 | QSPI_DATA_A_1[4] | QuadSPIAData 4                   | 1           |
| PF_10  |      |                   | 0000_0001 |            | QSPI_DATA_A_O[5] | QuadSPIAData 5                   | 0           |
| PF_10  | 545  | SIUL_CC           | 0000_0010 | 0x4009CAC4 | QSPI_DATA_A_I[5] | QuadSPIAData 5                   |             |
| PF_11  |      |                   | 0000_0001 |            | QSPI_DATA_A_0[6] | QuadSPIAData 6                   | 0           |
| PF_11  | 546  | SIUL_CC           | 0000_0010 | 0x4009CAC8 | QSPI_DATA_A_1[6] | QuadSPIAData6                    | 1           |
| PF_12  |      |                   | 0000_0001 |            | QSPI_DATA_A_0[7] | QuadSPIAData 7                   | 0           |
| PF_12  | 547  | SIUL_CC           | 0000_0010 | 0x4009CACC | QSPI_DATA_A_1[7] | QuadSPIAData 7                   |             |
| PF_13  |      |                   | 0000_0001 |            | QSPI_DQS_A_O     | Quad SPIAData Strobe             | 0           |
| PF_13  | 548  | SIUL_CC           | 0000_0010 | 0x4009CAD0 | QSPI_DQS_A_I     | Quad SPIAData Strobe             | 1           |
| PF_14  | 549  | SIUL_CC           | 0000_0010 | 0x4009CAD4 | QSPI_INTA_b      | Quad SPI Alnterrupt              |             |
| PG_00  |      |                   | 0000_0001 |            | QSPI_CK_A        | QuadSPI Serial Clock Flash A+    | 0           |
| PG_01  |      |                   | 0000_0001 |            | QSPI_CK_A_b      | QuadSPI Serial Clock Flash A-    | 0           |
| PG_02  |      |                   | 0000_0001 |            | QSPI_CK_2A       | QuadSPI Serial Clock 2 Flash A + | 0           |
| PG_03  |      |                   | 0000_0001 |            | QSPI_CK_2A_b     | QuadSPl Serial Clock 2 Flash A-  | 0           |
| PG_04  |      |                   | 0000_0001 |            | QSPI_CS_AO       | QuadSPI A Chip Select 0          | 0           |
| PG_05  |      |                   | 0000_0001 |            | QSPI_CS_A1       | QuadSPIA Chip Select 1           | 0           |

<!-- image -->

## QSPI Clock Configuration

<!-- image -->

PUBLIC

6

## QSPI CLOCK

<!-- image -->

| fQSPI_1X_CLK   | QSPI1Xclock frequency   |   200 | MHz   | QSPI_1X_CLK-DDR 200MHz   |
|----------------|-------------------------|-------|-------|--------------------------|
| fQSPI_1X_CLK   | QSPI1Xclock frequency   |   166 | MHz   | QSPI_1X_CLK-DDR 166MHz   |
| fQSPI1XCLK     | QSPI1Xclock frequency   |   133 | MHz   | QSPI1XCLK-DDR/ SDR133MHz |
| fQSPI_1X_CLK   | QSPI1Xclock frequency   |   104 | MHz   | QSPI_1X_CLK-SDR 104MHz   |
| fQSPI_1X_CLK   | QSPI1Xclock frequency   |   100 | MHz   | QSPI_1X_CLK-SDR 100MHz   |
| fQSPI_1X_CLK   | QSPI1Xclock frequency   |    66 | MHz   | QSPI_1X_CLK-DDR 66MHz    |

## QSPI clock path

- FXOSC → PLL → PERIPH\_DFS → PERIPH\_DFS1\_CLK → MC\_CGM\_0\_MUX\_12 → QSPI\_1/2X\_CLK
- FIRC → MC\_CGM\_0\_MUX\_12 → QSPI\_1/2X\_CLK
- FIRC→ PLL → PERIPH\_FES → PERIPH\_DFS1\_CLK → MC\_CGM\_0\_MUX\_12 → QSPI\_1/2\_CLK

The path described in the first bullet is the recommended QSPI clock path, other two are not recommended to be used by application

## QSPI clock frequency ranges

- For more information about frequency range minimum and maximums, please refer to the chapter "Clock frequency ranges" in the chip data sheet
- The valid range for PERIPH\_DFS1\_CLK is [532 … 800] MHz

<!-- image -->

## QSPI Register Configuration

<!-- image -->

PUBLIC

8

## DQS SAMPLING METHOD

## DQS Sampling method

The data strobe signal (DQS/RWDS) is used to sample the read data. DQS clock for sampling read data is selected in the field DQS\_FA/B\_SEL of MCR:

- 0x01(Dummy Pad Loopback)
- 0x11(External DQS)

## Dummy Pad Loopback

## External DQS

- The internal clock is loop-backed from the dummy internal pad to compensate data pad delays and used as the sampling strobe signal
- Pad Loopback is recommended for:
- SDR mode up to 133MHz
- DDR mode up to 66MHz
- DQS is an output from the flash memory device that indicates data is being transferred from the flash memory to the host controller
- External DQS is recommended for:
- DDR mode higher than 66MHz

<!-- image -->

<!-- image -->

## DQS DELAY CIRCUIT

## DLL and Slave Delay Chain

- The DQS delay circuit is used to delay the selected signal and generate the actual strobe signal used to sample the incoming read data from external QSPI flash
- The slave delay chain is a chain of delay blocks with taps providing access to the delayed clock signal between the block
- The Delay Locked Loop(DLL) provides the ability to select a quantized delay (in fractions of the clock period) regardless of on-chip variations such as process, voltage, and temperature (PVT)
- The DLL is disabled
- The slave delay chain is directly configured using register fields DLLCR*[SLV\_DLY\_COARSE] and DLLCR*[SLV\_FINE\_OFFSET]
- This is a static configuration (performed by application software or QSPI device driver)
- The DLL is enabled
- The slave delay chain is automatically reconfigured every time the DLL regains the lock condition
- No application SW intervention is required, once the DLL is configured initially

DLL Bypass Mode

## DLL Auto Update Mode

<!-- image -->

<!-- image -->

## LOOK UP TABLE(LUT)

<!-- image -->

- The core of the QSPI module is a programmable sequence engine that works on "instructionoperand" pairs.
- The LUT consists of several pre-programmed sequences. Each sequence is basically a sequence of instruction-operand pairs, which when executed sequentially, generate a valid serial flash memory transaction
- Up to 16 possible sequences can be programmed in the LUT
- Up to 10 instructions-operand pairs in one sequence
- At reset, the index 0 of the LUT[0..4] is programmed with a basic read sequence
- The reset command sequence in QSPI has 0x03 (basic read command) that is applicable to the flash memories

<!-- image -->

## EXAMPLE OF LUT CONFIGURATION

## FAST\_READ3B sequence

<!-- image -->

## PERIPHERAL BUS ACCESS

- The peripheral bus allows the software to write and read QSPI registers including RX and TX buffers
- Read, write and erase can be implemented over peripheral bus

Pre-program the LUT with the serial flash memory command sequences

Write the serial flash memory address to be used as provided in the Serial Flash Address Register (SFAR)

Write the sequence ID and data size details in the IP Configuration Register (IPCR)

<!-- image -->

<!-- image -->

## AHB BUS ACCESS

- AHB bus allows AHB masters to read external QSPI flash as the system memory
- External flash memory can be mapped to system memory at the address range: 0x0000\_0000 - 0x1FFF\_FFFF

<!-- image -->

<!-- image -->

<!-- image -->

## QSPI CONFIGURATION TIPS

- NXP provides a validated configuration in the datasheet, users can refer to it for supported programming settings

|                        | DDR-200MHz External DQS Edge Aligned   | DDR-133MHz External DQS Edge Aligned   | SDR-133MHz Internal pad loopback   | SDR-104MHz Intemal pad   | DDR-66MHz Internal pad loopback   |
|------------------------|----------------------------------------|----------------------------------------|------------------------------------|--------------------------|-----------------------------------|
| DQS mode               | DDR-200MHz External DQS Edge Aligned   | DDR-133MHz External DQS Edge Aligned   | SDR-133MHz Internal pad loopback   | SDR-104MHz Intemal pad   | DDR-66MHz Internal pad loopback   |
| Sampling mode          | DDR                                    | DDR                                    | SDR                                | SDR                      | DDR                               |
| DLLMode                | DLL Enable                             | DLL Enable                             | DLL Bypass                         | DLLBypass                | DLL Enable                        |
| Data Leaming           | No                                     | No                                     | No                                 | No                       | Yes                               |
| IO Voltage             | 1.8V                                   | 1.8V                                   | 1.8V                               | 3.3V                     | 1.8V/3.3V                         |
| Frequency              | 166/200 MHz                            | 100/133 MHz                            | 100/133 MHz                        | 104 MHz                  | 66MHz                             |
| FLSHCR[TDH]            | 1                                      | 1                                      | 0                                  | 0                        | 1                                 |
| FLSHCR[TCSH]           | 3                                      | 3                                      | 3                                  | 3                        | 3                                 |
| FLSHCR[TCSS]           | 3                                      | 3                                      | 3                                  | 3                        | 3                                 |
| MCR[DLPEN]             | 0                                      | 0                                      | 。                                  | 0                        | 1                                 |
| DLLCR[DLLEN]           |                                        | 1                                      | 。                                  |                          | 1                                 |
| DLLCR[FREQEN]          |                                        | 0                                      | 。                                  | 0                        | 0                                 |
| DLLCR[DLL_REFCNTR]     | 2                                      | 2                                      | NA                                 | NA                       | 2                                 |
| DLLCR[DLLRES]          | 8                                      | 8                                      | NA                                 | NA                       | 8                                 |
| DLLCR[SLV_FINE_OFFSET] | 0                                      | 0                                      |                                    |                          | 0                                 |
| DLLCR[SLV_DLY_OFFSET]  | 0                                      | 0                                      | 0                                  | 0                        | 3                                 |
| DLLCR[SLV_DLY_COARSE]  | NA                                     | NA                                     | 。                                  | 0                        |                                   |
| DLLCR[SLAVE_AUTO_UPDT] | 1                                      | 1                                      | 0                                  | 0                        | 1                                 |
| DLLCR[SLV_EN]          | 1                                      | 1                                      | 1                                  | 1                        | 1                                 |
| DLLCR[SLV_DLL_BYPASS]  | 0                                      | 0                                      | 1                                  |                          | 0                                 |
| DLLCR[SLV_UPD]         | 1                                      | 1                                      | 1                                  | 1                        | 1                                 |
| SMPR[DLLFSMPF]         | 4                                      | 4                                      |                                    | 0                        | NA                                |
| SMPR[FSDLY]            |                                        | 0                                      |                                    | 0                        | 1                                 |
| SMPR[FSPHS]            | NA                                     | NA                                     | 1                                  | 1                        | NA                                |

| Symbol      | Description                      | Min           | Typ   | Max            | Unit   |
|-------------|----------------------------------|---------------|-------|----------------|--------|
| fSCK-DQS    | SCK/DQS frequency 1.2            |               |       | 200            | MHz    |
| tCL_SCK-DQS | SCK/DQSlow time 1.2              | 2.25          |       |                | ns     |
| tCH_SCK-DQS | SCK/DQShigh time 1.2             | 2.25          |       |                | ns     |
| tOD_DATA    | Data output delay (w.r.t. SCK) 1 | 0.616         |       | 1.634          | ns     |
| tOD_CS      | CSoutputdelay (w.r.t.SCK)1.3     | 3.016-n/ fSCK |       | -2.266+ m/fScK | ns     |
| tIH_DQS     | Input hold time (w.r.t. DQS)2    | 1.684         |       |                | ns     |
| tISU_DQS    | Input setup time (w.r.t. DQS)2   | -0.466        |       |                | ns     |

<!-- image -->

<!-- image -->

## QSPI Boot

<!-- image -->

PUBLIC

1 6

## BOOTROM SUPPORTED QSPI FLASH

S32G can support boot from external QSPI flash. BootROM supported QSPI flash:

- Quad and Octal flash memories, and
- Hyper-Flash flash memories

Quad and Octal flash memories

Hyper-Flash flash memories

- Flash devices(Single, Dual, Quad, or Octal), can start in 1bit SDR mode
- The basic read command must be 0x03
- 8-bit mode for Hyper-Flash flash memories
- Should support the basic read command

| Instruction   | Pad   | Operand   | Comment                               |
|---------------|-------|-----------|---------------------------------------|
| CMD           | 0x00  | 0x03      | Read data byte command on one pad     |
| ADDR          | 0x00  | 0x18      | 24 address bits to be sent on one pad |
| READ          | 0x00  | 0x08      | Read 64 bits                          |
| JMP_ON_CS     | 0x00  | 0x0       | Jump to instruction 0 (CMD)           |

Quad and Octal flash memories basic read sequence

| Instruction   | Pad   | Operand   | Comment                |
|---------------|-------|-----------|------------------------|
| CMD_DDR       | 0x03  | 0xA0      | Read data byte command |
| ADDR_DDR      | 0x03  | 0x18      | 3 Bytes address        |
| CADDR_DDR     | 0x03  | 0x10      | 2 Bytes column address |
| DUMMY         | 0x03  | 0x0F      | 16 dummycycles         |
| READ_DDR      | 0x03  | 0x40      | Read 0x40 bytes data   |
| STOP          | 0x00  | 0x00      | Stop                   |

Hyper-flash basic read sequence

<!-- image -->

## QSPI BOOT FEATURES

## Initial Configuration

- Low frequency(G2: 40 MHz, G3: 30MHz ) in 1-bit mode for Quad and Octal flash memories. Or 8-bit mode for Hyper-Flash flash memories
- The initial configuration is used to read the reconfiguration data from the address 0x200
- If the reconfiguration data is not present, BootROM continues the booting process with the initial configuration

## Final configuration

- Prepare the clock source per required frequency in reconfiguration data
- Reconfigure the QSPI controller based on details provided in the reconfiguration data. For example, switch the external flash device from SPI mode to DDR-OPI mode

NXP provides example reconfiguration parameters with the S32 Design Studio release. NXP provides these scripts for reference only. These could be found at the below path:

- C:\NXP\S32DS.3.5\eclipse\mcu\_data\processors\S32G399A\PlatformSDK\_S32XX\_4\_0\_0\quadspi\default\_boot\_images

<!-- image -->

<!-- image -->

<!-- image -->

## QSPI BOOT TIPS

- BootROM sets a timeout of 500ms when downloading the application image. User must ensure that the maximum image size can be downloaded within this time
- For better performance, users can reconfigure QSPI flash settings by using the reconfiguration parameters, and it could be generated though the S32 Config Tool

<!-- image -->

<!-- image -->

## Flash Tool &amp; Flash SDK

<!-- image -->

PUBLIC

2 0

## S32 FLASH TOOL

- Support both GUI interface and command line interface
- Programs external flash devices such as QSPI, SD, and eMMC
- Supported communication interface: UART and CAN
- For each external flash device, there is a specific flash algorithm file
- Sends commands to the flash algorithm along with the image to be programmed to the external device
- The flash algorithm will perform the programming of the image to the external flash device

<!-- image -->

<!-- image -->

## QSPI FLASH SDK

The Flash SDK provides the capability to produce new flash algorithm files, which could then be uploaded to the target device by the S32 Flash Tool and then used to program images to the associated external flash device

- The provided flash SDK project is designed to build for ARM M7\_0 core
- The Flash SDK is provided in the form of a S32 Design Studio for S32 Platform project. The example project, as provided, will build and output a binary file like the FlashSDK.bin file, which include in the S32 Flash Tool

<!-- image -->

<!-- image -->

## Flash Driver

<!-- image -->

PUBLIC

2 3

## QSPI RTD DRIVER

<!-- image -->

- The Real Time Driver(RTD) package provides the AUTOSAR Flash Driver(FLS). The FLS driver provides services for reading, writing, and erasing flash memory
- Requirements for FLS driver are detailed in the AUTOSAR Driver Software Specification document
- The RTD package do provide example configurations that are compliant with NXP reference platforms (EVB and RDB with MX25UM51245G flash)
- The example shows how to initialize the QSPI module and the MX25UW51245G 64MB octal flash memory chip to work in DDR mode at 200 MHz

<!-- image -->

## FLS SW RESET FEATURE

BootROM can configure the external flash through QSPI reconfiguration parameters to achieve high-speed communication in OPI mode

<!-- image -->

The QSPI driver can reset the external flash memory through the software rest command of the external flash memory, and the external flash memory enters the default state, that is the SPI mode

<!-- image -->

The FLS driver can re-configure the QSPI controller and external flash in the initialization sequence, so that the external QSPI flash can enter OPI mode for higher performance

<!-- image -->

<!-- image -->

## QSPI DRIVER TIPS

- Disable speculative access to QSPI flash mapped region before configure QSPI controller

## 38.1.4QuadSPllimitations

TheimplementationofQuadSPlinthischiphasthefollowinglimitations:

- NosupportforDDRCenterAlignedReadStrobe(DCARS)flashmemory.
- ThischipdoesnotsupportWRAP*transactionsforAHBread.
- AnyspeculativeaccessoftheQuadSPlmemorymappedregion0oooooooh-2ooooooohbeforeyouconfigureQuadSPI speculativeaccessofthatregion.
- It is required that the application must rely on theFCCUfault for theECCerror handling bywriting'O'to theQuadSPI RSER[CRCBlE]andRSER[CRCAlE].IncaseswhereFCCUisnotconfigured(forexample,inthecustomerbootloader), thesefieldsmustbeenabled.
- Both AHB and IPS access are OK if the related settings are correct (like providing the SEQIDs for AHB read). There is no HW-based arbitration at the QSPI IP level between IPS and AHB, they must work in a semaphore manner at software level one by one only

## 5.8.1.3 AHBReads

- ItisnotrecommendedtoperformAHBreadsdirectlyfromtheapplication,astheymayinterferewithnormal FLSdriverfunctionality.QSPIcan onlyperformone operationatatime,soattemptingAHBreadswhile themoduleisbusymaycausethecurrentoperationtofail.ItisrecommendedtodoallreadsusingtheFLS driver'sFls\_Read()function.Thismustalsobetakenintoaccountwhiledebuggersareattachedwhichmay alsoreadfromflash
- IftheapplicationmustperformAHBreads,thesameXRDCsemaphoreusedbytheFLSdrivermustbeused toguardtheAHBreads.ThiscannotbeenforcedbyXRDC,asthesemaphoreonlycontrolswritepermissions. Sointhiscaseitis thesoftware'sresponsibilitytoensurethesemaphoreisownedbeforeAHBreads,failingto dosocouldpotentiallycauseflashoperationstofail
- Ifacoreonlyneedstoperformreadoperationsduringtheruntimestage,itcanuseAHBreadsandbenefit fromthesecurityfeaturesoftheXRDC,whichcanensurethecoreonlyhasaccesstotheallocatedmemory rangeandalsocanforbidthecore'saccesstotheQSPIregisters,thusensuringnointerferencewithothercores operations.Therequirementtousethesemaphorestillapplies

<!-- image -->

<!-- image -->

<!-- image -->