## EB00922

## NXP Vehicle Network Processor - Feature Enhancements and Migration from S32G2 to S32G3

Rev. 2 - March, 2022

by: NXP Semiconductors

## 1 Introduction

The S32G3 is the next generation device of the NXP Vehicle Network Processor (VNP) family which brings in a number of enhancements over the S32G2 device.

This engineering bulletin is intended for customers who are looking for increased performance and memory for use cases that are not covered by the S32G2.

This document provides a comparative overview of the two devices along with guidelines to migrate from S32G2 based solution to S32G3 device.

The following table shows the abbreviations used throughout the document.

## Table 1. Acronyms and abbreviations

| Abbreviation   | Explanation                                         |
|----------------|-----------------------------------------------------|
| ADMA           | Advanced DMA                                        |
| CMU            | Clock Monitoring Unit                               |
| CRC            | Cyclic Redundancy Check                             |
| DCD            | Device Configuration Data                           |
| DID            | Domain Identifier                                   |
| DTE            | Data Transfer Engine                                |
| eDMA           | Enhanced Direct Memory Access                       |
| FIRC           | Fast Internal RC Oscillator                         |
| FRPE           | Packet Processing Engine for FlexRay                |
| GMAC           | Gigabit Ethernet Media Access Controller            |
| HIF            | Host Interface                                      |
| HSE            | Hardware Security Engine                            |
| IOMUX          | Input Output Multiplexing                           |
| IRCPxISRx      | Interrupt Router CPx Interruptx Status Register     |
| IRCPxIGRx      | Interrupt Router CPx Interruptx Generation Register |
| IVT            | Image Vector Table                                  |
| LLCE           | Low Latency Communication Engine                    |

Table continues on the next page...

Engineering Bulletin

| 1   | Introduction......................................1                                      |
|-----|------------------------------------------------------------------------------------------|
| 2   | S32G3 Enhancements over S32G2 ........................................................ 2 |
| 3   | S32G3 Hardware Design                                                                    |
|     | Considerations................................ 7                                         |
| 4   | S32G3 Software Considerations...10                                                       |
| 5   | S32G3 Tools Considerations........ 10                                                    |
| 6   | S32G2 Boards reusability for S32G3                                                       |
|     | based development.......................10                                               |
| 7   | References....................................11                                         |
| 8   | Revision history.............................11                                          |

## Contents

Table 1. Acronyms and abbreviations (continued)

| Abbreviation   | Explanation                                |
|----------------|--------------------------------------------|
| LS             | Lockstep                                   |
| MSCM           | Miscellaneous System Control Module        |
| MRC            | Memory Region Controllers                  |
| MSIs           | Message-Signaled Interrupts                |
| MU             | Messenging Unit                            |
| NC             | Not Connect                                |
| PCIe           | PCI Express                                |
| PDAC           | Peripheral Domain Access Control           |
| PFE            | Packet Forwarding Engine                   |
| PMIC           | Power Management Integrated Circuit        |
| POR            | Power-On Reset                             |
| QSPI           | Quad Serial Peripheral Interface           |
| RxLUT          | Rx Lookup Table                            |
| RxPPE          | Rx Packet Processing Engine                |
| RTD            | Real Time Drivers                          |
| SERDES         | Serializer/De-serializer                   |
| SHA            | Secure Hash Algorithm                      |
| SGMII          | Serial Gigabit Media Independent Interface |
| SRAM           | System RAM                                 |
| STM            | System Timer Module                        |
| SWD            | Serial Wire Debug                          |
| SWT            | Software Watchdog Timer                    |
| TSN            | Time Sensitive Networking                  |
| XOSC           | External Crystal Oscillator                |
| XRDC           | Extended Resource Domain Controller        |
| uSDHC          | Ultra-Secured Digital Host Controller      |

## 2 S32G3 Enhancements over S32G2

## 2.1 High level changes from S32G2 to S32G3 family

The S32G3 devices are pin-to-pin compatible with the S32G2 devices, providing over 2x performance and system RAM. The following figure shows the variants of S32G2 and S32G3 family.

S32G3 Enhancements over S32G2

The following table lists the key enhancements moving from the S32G2 to the S32G3 family. Refer to S32G3 Product Brief 3 for details.

| Feature                         | Enhancement over S32G2 family                               |
|---------------------------------|-------------------------------------------------------------|
| Applications Performance        | Up to 2.6x increase in applications performance             |
| Arm ® Cortex-A53 ® L2 Cache     | Doubled each cluster L2 cache from 512 KB to 1 MB           |
| Real-time memory                | Up to 2.5x more SRAM going from 8 MB up to 20 MB            |
| Real-time performance           | 1.33x increase with pair of Cortex-M7 lockstep cores        |
| Ethernet I/F Bandwidth          | All PFE ports support 2.5 Gbps                              |
| SerDes                          | Additional PCIe/SGMII multiplexing option                   |
| Automotive Network Acceleration | Increased performance from 4 Mbps to 5 Mbps for 16 channels |

## 2.2 S32G399A feature comparison with S32G274A

The following table lists the feature changes between the S32G274A and the S32G399A in detail. The top end variant of both families are compared. The choice of a variant would be dependent on the customer use cases. For detailed descriptions on the differences listed in the following table please refer to the respective device reference manuals 1,2 .

Table 2. Differences between S32G274A and S32G399A

| Feature               | S32G274A                                                                                                      | S32G399A                                                                                                      |
|-----------------------|---------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Compute Performance   | Compute Performance                                                                                           | Compute Performance                                                                                           |
| Arm Cortex-A53 cores  | 2 x Arm Cortex-A53 clusters 2 x Cores per cluster Operating frequency up to 1 GHz 512 KB L2 cache per cluster | 2 x Arm Cortex-A53 clusters 4 x Cores per cluster Operating frequency up to 1.3 GHz 1 MB L2 cache per cluster |
| Arm Cortex-M7 ® cores | 3 x Arm Cortex-M7 delayed lockstep clusters, 2 x Cores per cluster                                            | 4 x Arm Cortex-M7 delayed lockstep clusters 2 x Cores per cluster                                             |

Table continues on the next page...

Table 2. Differences between S32G274A and S32G399A (continued)

|                                                                     | Operating frequency up to 400 MHz                                                                                          | Operating frequency up to 400 MHz                                                                                          | Operating frequency up to 400 MHz                                                                                                                        | Operating frequency up to 400 MHz                                                                                                                        |
|---------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Real-time memory                                                    | Real-time memory                                                                                                           | Real-time memory                                                                                                           | Real-time memory                                                                                                                                         | Real-time memory                                                                                                                                         |
| SRAM                                                                | 8 MB                                                                                                                       | 8 MB                                                                                                                       | 20 MB                                                                                                                                                    | 20 MB                                                                                                                                                    |
| SRAM controllers                                                    | 2 x SRAM Controllers Each SRAM controller covers 4 MB region                                                               | 2 x SRAM Controllers Each SRAM controller covers 4 MB region                                                               | 4 x SRAM Controllers Each SRAM controller covers 5 MB region                                                                                             | 4 x SRAM Controllers Each SRAM controller covers 5 MB region                                                                                             |
| SRAM alignment with Arm Cortex-M7 cores                             | Optimum Arm Cortex-M7 cores to SRAM latency can be achieved in the following order 1 :                                     | Optimum Arm Cortex-M7 cores to SRAM latency can be achieved in the following order 1 :                                     | Optimum Arm Cortex-M7 cores to SRAM latency can be achieved in the following order 2 :                                                                   | Optimum Arm Cortex-M7 cores to SRAM latency can be achieved in the following order 2 :                                                                   |
| SRAM alignment with Arm Cortex-M7 cores                             | Arm Cortex-M7 Core                                                                                                         | SRAM address range                                                                                                         | Arm Cortex-M7 Core                                                                                                                                       | SRAM address range                                                                                                                                       |
| SRAM alignment with Arm Cortex-M7 cores                             | Arm Cortex-M7_0                                                                                                            | 0x3400_0000-0x343F _FFFF                                                                                                   | Arm Cortex-M7_0                                                                                                                                          | 0x3400_0000 - 0x344F_FFFF                                                                                                                                |
| SRAM alignment with Arm Cortex-M7 cores                             | Arm Cortex-M7_1                                                                                                            | 0x3440_0000-0x347F _FFFF                                                                                                   | Arm Cortex-M7_3                                                                                                                                          | 0x3450_0000 - 0x349F_FFFF                                                                                                                                |
| SRAM alignment with Arm Cortex-M7 cores                             | Arm Cortex-M7_2                                                                                                            | 0x3440_0000-0x347F _FFFF                                                                                                   | Arm Cortex-M7_1                                                                                                                                          | 0x34A0_0000 - 0x34EF_FFFF                                                                                                                                |
| SRAM alignment with Arm Cortex-M7 cores                             |                                                                                                                            |                                                                                                                            | Arm Cortex-M7_2                                                                                                                                          | 0x34F0_0000 - 0x353F_FFFF                                                                                                                                |
| Timers                                                              | Timers                                                                                                                     | Timers                                                                                                                     | Timers                                                                                                                                                   | Timers                                                                                                                                                   |
| SWT                                                                 | 7 instances                                                                                                                | 7 instances                                                                                                                | 12 instances                                                                                                                                             | 12 instances                                                                                                                                             |
| STM                                                                 | 8 instances                                                                                                                | 8 instances                                                                                                                | 13 instances                                                                                                                                             | 13 instances                                                                                                                                             |
| Isolation                                                           | Isolation                                                                                                                  | Isolation                                                                                                                  | Isolation                                                                                                                                                | Isolation                                                                                                                                                |
| XRDC domains                                                        | 8 domains                                                                                                                  | 8 domains                                                                                                                  | 16 domains                                                                                                                                               | 16 domains                                                                                                                                               |
| PFE MRC enhancement                                                 | XRDC_1 MRC4 supports 4 descriptors for PFE register space                                                                  | XRDC_1 MRC4 supports 4 descriptors for PFE register space                                                                  | XRDC_1 MRC4 enhanced to 8 descriptors, allowing more than 4 masters access to PFE register space                                                         | XRDC_1 MRC4 enhanced to 8 descriptors, allowing more than 4 masters access to PFE register space                                                         |
| eDMA PDAC enhancement                                               | 1 x PDAC for the full eDMA region, with no isolation between the 2 sets of channel configuration registers(0-15 and 16-31) | 1 x PDAC for the full eDMA region, with no isolation between the 2 sets of channel configuration registers(0-15 and 16-31) | 3 x PDACs to split the eDMA functionality between Arm Cortex-M7 and Arm Cortex­ A53 cores: • 1 x PDAC for eDMA control • 1 x PDAC for 0-15 eDMA channels | 3 x PDACs to split the eDMA functionality between Arm Cortex-M7 and Arm Cortex­ A53 cores: • 1 x PDAC for eDMA control • 1 x PDAC for 0-15 eDMA channels |
| DRAM address range protection by XRDC0_MRC0 from Cortex-M7 accesses | For DRAM address range protection from Cortex-M7 accesses, always program M7_DRAM_ADDRESS in XRDC                          | For DRAM address range protection from Cortex-M7 accesses, always program M7_DRAM_ADDRESS in XRDC                          | For DRAM address range protection from Cortex-M7 accesses, always program M7_DRAM_ADDRESS + 20000000h in XRDC                                            | For DRAM address range protection from Cortex-M7 accesses, always program M7_DRAM_ADDRESS + 20000000h in XRDC                                            |

Table continues on the next page...

Table 2. Differences between S32G274A and S32G399A (continued)

| XRDC error interrupt for system monitoring                                                                             | Error report of XRDC can only be accessed by the master associated with the error                                    | XRDC supports an interrupt to be routed to MSCM which can further route it to Arm Cortex-A53 GIC or Arm Cortex-M7 NVIC to make the system aware of XRDC errors   |
|------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Inter Processor Communication                                                                                          | Inter Processor Communication                                                                                        | Inter Processor Communication                                                                                                                                    |
| Core-to-core MSIs                                                                                                      | 3 x Core-to-core MSIs                                                                                                | 12 x Core-to-core MSIs                                                                                                                                           |
| Debug Interfaces                                                                                                       | Debug Interfaces                                                                                                     | Debug Interfaces                                                                                                                                                 |
| Serial Wire Debug                                                                                                      | Feature not supported                                                                                                | Feature supported for CUST_DEL and FA life cycles. This enables the developers to use the SWD based tools during the development phase                           |
| DDR                                                                                                                    | DDR                                                                                                                  | DDR                                                                                                                                                              |
| Row address bit 17 support                                                                                             | Uses both chip select to access 4GB (dual ranks) of DRAM                                                             | Uses single chip select and row address bit 17 to access 4GB (single rank) of DRAM supporting row address bit 17                                                 |
| ECC initialization                                                                                                     | DDR_GPR registers - DDR_Config_1 and DDR_Config_2 used for ECC initialization                                        | UMCTL2_MP registers - SBRSTART0,1 and SBRRANGE0,1 used for ECC initialization                                                                                    |
| Hardware Security Engine                                                                                               | Hardware Security Engine                                                                                             | Hardware Security Engine                                                                                                                                         |
| HSE access to DDR                                                                                                      | HSE's M7 core can only access 1.5 GB of DRAM                                                                         | The HSE M7 will have access to all 2 GB of DRAM                                                                                                                  |
| XRDC DID for HSE requests                                                                                              | HSE does not pass the DID of the master that requested the job. HSE has single domain ID that is not altered per job | HSE-initiated memory accesses shall be controlled using XRDC DID values based on the requesting masters MU                                                       |
| SHA-3 Hardware support                                                                                                 | Firmware support for SHA-3                                                                                           | Hardware acceleration for SHA-3                                                                                                                                  |
| Low Latency Communication Engine                                                                                       | Low Latency Communication Engine                                                                                     | Low Latency Communication Engine                                                                                                                                 |
| Performance (Max Baud Rate to transmit/ receive frames on all 16 BCAN channels, across all payload size and bus loads) | 4 Mbps per channel                                                                                                   | 5 Mbps per channel                                                                                                                                               |
| DTE code RAM capacity                                                                                                  | 8 KB                                                                                                                 | Increased to 16 KB, to handle the performance increase to 5 Mbps                                                                                                 |
| FRPE code RAM capacity                                                                                                 | 64 KB                                                                                                                | Increased to 256 KB to accomodate more customer use-cases                                                                                                        |
| RxLUT enhancements                                                                                                     | 1 x RxLUT instance, with 1K entry capability. ECC not supported                                                      | 2 x RxLUT instances, with 4K and 12K entry capability. ECC supported                                                                                             |

Table continues on the next page...

Table 2. Differences between S32G274A and S32G399A (continued)

| RxPPE code RAM capacity                        | 32 KB                                                                                                 | Increased to 96 KB to support the new RxLUT implementation                                                                                                                                                                                                                      |
|------------------------------------------------|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Access to Accelerator Peripheral Space         | No access to accelerator peripheral space from 0x44000000 to 0x46FFFFFF                               | Access to accelerator peripheral space from 0x44000000 to 0x46FFFFFF                                                                                                                                                                                                            |
| Packet Forwarding Engine                       | Packet Forwarding Engine                                                                              | Packet Forwarding Engine                                                                                                                                                                                                                                                        |
| L2/L3 Fast Path forwarding performance         | 2 Gbps for 64 bytes packet size in fast path routing                                                  | 3 Gbps for 64 bytes packet size in fast path routing                                                                                                                                                                                                                            |
| Routing Table                                  | Routing Table created in system SRAM and external DRAM                                                | Supports 1K routing table entries in PFE internal memory, in addition to system SRAM and external DRAM                                                                                                                                                                          |
| PFE HIF channel isolation                      | Does not provides HIF channel number to XRDC                                                          | Provides HIF channel number which will be mapped to a domain ID by XRDC to provide PFE HIF channels' isolation                                                                                                                                                                  |
| Error Reporting                                | Supports Watchdog timer and parity error reporting to the host via safety interrupt.                  | Additionally, supports FW failstop, multi-bit ECC, host force debug failstop and bus error reporting to the host via safety interrupt. Supports failstop mode corresponding to these errors on occurrence of which PFE completes the current AXI transfer and disable the MACs. |
| SERDES                                         | SERDES                                                                                                | SERDES                                                                                                                                                                                                                                                                          |
| PFE MAC speeds over SGMII                      | 1 x 2.5 Gbps SGMII configuration with PFE_MAC0                                                        | All PFE MACs can now be configured in 2.5 Gbps mode using mux options available on SERDES_0 and SERDES_1 3                                                                                                                                                                      |
| GENCTRL1 register to enable/disable SGMII mode | S32G_GPR_GENCTRL1.CTRL allows to enable/disable PFE MAC0 in SGMII mode                                | SRC_1_GENCTRL1.CTRL allows to enable/ disable all PFE MACs in SGMII mode                                                                                                                                                                                                        |
| Concurrent PCIE_X1 and SGMII 2.5 Gbps support  | SERDES_1 supports Ethernet SGMII 2.5 Gbps on one lane, PCIe interface cannot be accessed concurrently | Both SERDES instances support concurrent access to Ethernet SGMII 2.5 Gbps and PCIe x1(gen 1/2)                                                                                                                                                                                 |
| GMAC                                           | GMAC                                                                                                  | GMAC                                                                                                                                                                                                                                                                            |
| GMAC TSN                                       | Frame scheduling and frame preemption cannot be used at the same time.                                | Frame scheduling and frame preemption can be used at the same time.                                                                                                                                                                                                             |
| Clocking                                       | Clocking                                                                                              | Clocking                                                                                                                                                                                                                                                                        |
| GMAC Clock Tree                                | MC_CGM_0 Mux 9,10,11,15 used for GMAC related clocking                                                | MC_CGM_6 Mux 0,1,2,3 used for GMAC related clocking                                                                                                                                                                                                                             |
| BootROM                                        | BootROM                                                                                               | BootROM                                                                                                                                                                                                                                                                         |

Table continues on the next page...

Table 2. Differences between S32G274A and S32G399A (continued)

| UART Baud Rates                                           | UART baud rates supported by BootROM: • XOSC (20 MHz) - 24000 • XOSC (40 MHz) - 48000 • FIRC (48 MHz) - 48000   | UART baud rates supported by BootROM: • XOSC (20 MHz) - 57600 • XOSC (40 MHz) - 115200 • FIRC (48 MHz) - 115200                                                  |
|-----------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| IVT Life Cycle Configuration Word                         | 1-bit used for configuring each life cycle                                                                      | 4-bits used for configuring each life cycle                                                                                                                      |
| QSPI Boot Initial Phase Frequency                         | 40 MHz                                                                                                          | 30 MHz to support a wider range of flash devices                                                                                                                 |
| Self-Test, DCD, App Image identification(Primary/ Backup) | No mechanism to identify whether primary or backup image was used in current boot cycle                         | Supports a mechanism to identify if primary or backup image is used in current boot cycle by BootROM register - SRC_GPR_TOP_REG_28                               |
| QSPI POR Delay                                            | QSPIPORDelayapplied by default onlyatPOR HSE service used to control POR delay across subsequent boot cycles    | QSPI POR Delay applied by default only at POR Application core used to control the PORDelay on subsequent boot cycle using BootROM register - SRC_GPR_TOP_REG_29 |
| Reserved SRAM region for boot via uSDHC interface         | SRAM region 0x343FF000 - 0x34400000 is used for ADMA descriptors                                                | SRAM region 0x34000000 - 0x34002000 is used for ADMA descriptors                                                                                                 |
| Power Management                                          | Power Management                                                                                                | Power Management                                                                                                                                                 |
| Static Voltage Scaling                                    | 0.8 V output of VR5510 PMIC needs to be adjusted as per DIE_PROCESS[1:0] bits                                   | No action required with VR5510 + PF53 power solution                                                                                                             |
| Clock Monitoring Unit                                     | Clock Monitoring Unit                                                                                           | Clock Monitoring Unit                                                                                                                                            |
| CMU 27 and CMU 28                                         | CMU 27 and CMU 28 are accessible but all the writes would be ignored when partition 1 is not enabled.           | CMU 27 and CMU 28 are not accessible and all the writes would give bus fault when partition 1 is not enabled.                                                    |
| Interrupt Router Status and Generation Register           | Interrupt Router Status and Generation Register                                                                 | Interrupt Router Status and Generation Register                                                                                                                  |
| Register offset address                                   | MSCM register offset 0x200 and 0x204 are base offset for IRCPxISRx and IRCPxIGRx respectively.                  | MSCM register offset 0xA60 and 0xA64 are base offset for IRCPxISRx and IRCPxIGRx respectively.                                                                   |

## NOTE

For details on errata fixes in S32G3, refer the errata documents for S32G2 9  and S32G3 10 .

## 3 S32G3 Hardware Design Considerations

## 3.1 Power requirements

Worst case power consumption of S32G399A 0.8 V domain is approx. 9.5 W (Design estimate, to be confirmed on Silicon) compared to 4.5 W for S32G274A. This requires use of an additional regulator for 0.8 V supply. NXP recommends PF53 to be used for 0.8 V supply in conjuction with PMIC VR5510.

The following figure shows the power management consideration in HW design while migrating from S32G274A to S32G399A.

S32G3 Hardware Design Considerations

Figure 2. Migration from S32G274A to S32G399A to manage the power requirement

S32G3 Hardware Design Considerations

## 3.2 PINOUT change

VDD\_LV\_PLL(H15 ball on silicon package - refer S32G3\_IOMUX.xlsx) is NC on S32G3 Silicon.

This does not impact HW compatibility, for more details refer to S32G3 Hardware Design Guide 6 .

## 3.3 HW Design recommendations

S32G2 - Refer to Hardware Design Guide for S32G2 5 .

S32G3 - Refer to Hardware Design Guide for S32G3 6 .

## 4 S32G3 Software Considerations

## 4.1 Software drivers and firmware

The feature differences tabulated in S32G399A feature comparison with S32G274A will be handled by a single NXP SW release encompassing the S32G3 changes in specific firmware and drivers.

The NXP SW release would provide API compatibility between the S32G2 and the S32G3, simplifying the migration of Real Time and Linux based applications.

Refer the document 'S32G Software Offering' from My NXP &gt; Secure Files to obtain information on compatible NXP SW releases.

## NOTE

For customers planning to use NXP SW release to migrate their already existing full SW solution on S32G2 to S32G3, should refer the SW release notes and the device reference manuals 1,2 .

## 4.2 Build system

For NXP SW release the build system remains compatible across S32G2/S32G3 devices. The build system selects device specific adaption based on the device.

## NOTE

The binaries build for the S32G2 device would not be compatible with the S32G3 device.

## 5 S32G3 Tools Considerations

Single SW development tools to support both S32G2 and S32G3.

Refer the document 'S32G Software Offering' from My NXP &gt; Secure Files to obtain information on compatible NXP tool releases.

## NOTE

In the initial phase the S32G3 will be supported via patches. These patches will finally be merged with the standard tool release common to both the S32G2 and S32G3.

## 6 S32G2 Boards reusability for S32G3 based development

The power demand for the S32G3 device is higher than the S32G2. However, it is possible to reuse S32G2 based boards for S32G3 based development by replacing the silicon.

The NXP Evaluation Boards (S32G-VNP-EVB 7  and S32G-VNP-EVB3 8 ) can be referenced to understand the hardware reusability for development purposes.

Both the NXP EVB boards use a common platform board and are differentiated by the processor modules.

## Table 3. NXP EVB board variants

| Evaluation Board Variants   | Processor Module   | Platform Board   |
|-----------------------------|--------------------|------------------|
| S32G-VNP-EVB                | S32G-PROCEVB-S     | S32GRV-PLATEVB   |
| S32G-VNP-EVB-SA             | S32G-PROCEVB-SA    | S32GRV-PLATEVB   |

Table continues on the next page...

S32G3 Software Considerations

Table 3. NXP EVB board variants (continued)

| Evaluation Board Variants   | Processor Module   | Platform Board   |
|-----------------------------|--------------------|------------------|
| S32G-VNP-EVB3               | S32G-PROCEVB3-S    | S32GRV-PLATEVB   |

Th S32G-PROCEVB3-S processor module has redesigned the power solution to cater for the increased power demand for the S32G3 device. Nevertheless, the power solution on S32G-PROCEVB-S and S32G-PROCEVB-SA can support the power requirements of S32G3 device in standard lab conditions, making it also usable for S32G3 based development.

## 7 References

1. S32G2 Reference Manual
2. S32G3 Reference Manual
3. S32G3 Product Brief
4. S32G3 Data Sheet
5. S32G2 Hardware Design Guide
6. S32G3 Hardware Design Guide
7. S32G-VNP-EVB schematics
8. S32G-VNP-EVB3 schematics
9. S32G2 Errata document
10. S32G3 Errata document

## NOTE

S32G2-related documents are available on nxp.com and S32G3-related documents are available in My NXP &gt; Secure Files.

## 8 Revision history

Table 4. Revision history

|   Revision | Release date   | Changes                                                                                                                     |
|------------|----------------|-----------------------------------------------------------------------------------------------------------------------------|
|          0 | July, 2021     | Initial release                                                                                                             |
|          1 | November, 2021 | In Table 2, added the following rows for: • GENCTRL1 • SRAM alignment with Arm Cortex­ M7 cores • DDR • PFE error reporting |
|          2 | March, 2022    | In Table 2, added the following rows for: • Clock Monitoring Unit • Interrupt Router Status and Generation Register         |

Table continues on the next page...

Table 4. Revision history (continued)

| Revision   | Release date   | Changes                                        |
|------------|----------------|------------------------------------------------|
|            |                | • GMAC Updated Software drivers and firmware . |

## How To Reach Us Home Page:

nxp.com Web Support: nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions.

While NXP has implemented advanced security features, all products may be subject to unidentified vulnerabilities. Customers are responsible for the design and operation of their applications and products to reduce the effect of these vulnerabilities on customer's applications and products, and NXP accepts no liability for any vulnerability that is discovered. Customers should implement appropriate design and operating safeguards to minimize the risks associated with their applications and products.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C-5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C-Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  AMBA, Arm, Arm7, Arm7TDMI, Arm9, Arm11, Artisan, big.LITTLE, Cordio, CoreLink, CoreSight, Cortex, DesignStart, DynamIQ, Jazelle, Keil, Mali, Mbed, Mbed Enabled, NEON, POP, RealView, SecurCore, Socrates, Thumb, TrustZone, ULINK, ULINK2, ULINK-ME, ULINK-PLUS, ULINKpro, µVision, Versatile are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.

## ©  NXP B.V. 2022.

All rights reserved.

For more information, please visit: http://www.nxp.com For sales office addresses, please send an email to: salesaddresses@nxp.com

Date of release: March, 2022 Document identifier: EB00922