## S32G3

Rev. 4 - 29 September 2025

## S32G3 Data Sheet

- This document provides electrical specifications for S32G3.
- For functional characteristics and the programming model, see S32G3 Reference Manual.

Product data sheet

<!-- image -->

## 1 Introduction

## 1.1 Overview

S32G3 is a family of high-performance vehicle network processors that combine controller area network (CAN), local interconnect network (LIN), and FlexRay networking with high data rate Ethernet networking. It also combines a functional safe-core infrastructure with MPU cores and includes high-level security features. The S32G3 chips are pin-for-pin compatible with S32G2 chips, providing over 2x performance and over 2x system RAM.

Table 1. S32G3 family key enhancements

| Feature                      | Enhancements                                                                                 |
|------------------------------|----------------------------------------------------------------------------------------------|
| Compute performance          | Up to 2.6 x increase in applications performance (doubling Cortex-A53 cores@ 1.4x frequency) |
| Real-time memory             | Increase SRAM from 6 MB / 8 MB to 15 MB / 20 MB                                              |
| Real-time performance        | Additional pair of Cortex-M7 lockstep cores                                                  |
| Ethernet interface bandwidth | Increased speed from 1 Gbps to 2.5 Gbps on two SGMII interfaces                              |
| Ethernet packet routing      | Performance target increase from 2 Gbps@64B to 3 Gbps@64B                                    |

Figure 1. S32G2 to S32G3 evolution

<!-- image -->

S32G3 family includes the following variants:

- S32G399A
- S32G398A
- S32G379A
- S32G378A

This document primarily represents the features offered by the superset S32G399A. To compare the features of the S32G3 family variants, see Feature comparison.

## 1.2 Applications

Combining ASIL D safety, hardware security, high-performance real-time and application processing and network acceleration, this chip targets applications that includes:

- Service-oriented gateways and domain controllers
- Safety processor for ADAS and autonomous driving

S32G3 Data Sheet

- High-performance central compute nodes
- FOTA masters controlling secure software image downloads and their distribution to the ECUs in the network
- Security services and key management
- Smart antennas

## 2 Block diagram

The following is the block diagram for S32G399A, the superset chip in the S32G3 family.

Figure 2. Block diagram

<!-- image -->

## 3 Feature comparison

This table compares the features of the chips in the S32G3 family.

Table 2. S32G3 feature list and supported functionality

| Feature                 | S32G399A                                            | S32G398A                                            | S32G379A                                            | S32G378A                                            |
|-------------------------|-----------------------------------------------------|-----------------------------------------------------|-----------------------------------------------------|-----------------------------------------------------|
| Compute and bus modules | Compute and bus modules                             | Compute and bus modules                             | Compute and bus modules                             | Compute and bus modules                             |
| Applications CPUs       | 4 x Cortex-A53 LS (8 x Cortex-A53)                  | 4 x Cortex-A53 LS (8 x Cortex-A53)                  | 2 x Cortex-A53 LS (4 x Cortex-A53) [1]              | 2 x Cortex-A53 LS (4 x Cortex-A53) [1]              |
| Real-time CPUs          | 4 x Cortex-M7 LS                                    | 3 x Cortex-M7 LS [2]                                | 4 x Cortex-M7 LS                                    | 3 x Cortex-M7 LS [2]                                |
| Cortex-A53              | Cortex-A53                                          | Cortex-A53                                          | Cortex-A53                                          | Cortex-A53                                          |
| L1 cache                | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core |

Table continues on the next page...

S32G3 Data Sheet

Table 2. S32G3 feature list and supported functionality...continued

| Feature                      | S32G399A                                                                                 | S32G398A                                                                                 | S32G379A                                                                                 | S32G378A                                                                                 |
|------------------------------|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------|
| L2 cache                     | 1 MB per cluster                                                                         | 1 MB per cluster                                                                         | 1 MB per cluster                                                                         | 1 MB per cluster                                                                         |
| Cache coherency interconnect | Supported                                                                                | Supported                                                                                | Supported                                                                                | Supported                                                                                |
| Interrupt controller         | GIC-500                                                                                  | GIC-500                                                                                  | GIC-500                                                                                  | GIC-500                                                                                  |
| Maximum frequency            | Up to 1.4 GHz                                                                            | Up to 1.4 GHz                                                                            | Up to 1.4 GHz                                                                            | Up to 1.4 GHz                                                                            |
| Functional safety            | Configurable ASIL D lockstep clusters and two ASIL B independent clusters                | Configurable ASIL D lockstep clusters and two ASIL B independent clusters                | Configurable ASIL D lockstep clusters and two ASIL B independent clusters                | Configurable ASIL D lockstep clusters and two ASIL B independent clusters                |
| Cortex-M7                    | Cortex-M7                                                                                | Cortex-M7                                                                                | Cortex-M7                                                                                | Cortex-M7                                                                                |
| L1 cache                     | 32 KB I-cache and 32 KB D-cache per Cortex-M7                                            | 32 KB I-cache and 32 KB D-cache per Cortex-M7                                            | 32 KB I-cache and 32 KB D-cache per Cortex-M7                                            | 32 KB I-cache and 32 KB D-cache per Cortex-M7                                            |
| Cache coherency interconnect | Not supported                                                                            | Not supported                                                                            | Not supported                                                                            | Not supported                                                                            |
| Interrupt controller         | 4 x NVIC                                                                                 | 4 x NVIC                                                                                 | 4 x NVIC                                                                                 | 4 x NVIC                                                                                 |
| Maximum frequency            | 400 MHz                                                                                  | 400 MHz                                                                                  | 400 MHz                                                                                  | 400 MHz                                                                                  |
| Functional safety            | Dual-core lockstep                                                                       | Dual-core lockstep                                                                       | Dual-core lockstep                                                                       | Dual-core lockstep                                                                       |
| DTCM                         | 64 KB per Cortex-M7                                                                      | 64 KB per Cortex-M7                                                                      | 64 KB per Cortex-M7                                                                      | 64 KB per Cortex-M7                                                                      |
| System modules               | System modules                                                                           | System modules                                                                           | System modules                                                                           | System modules                                                                           |
| DMA                          | 2x safe eDMA (supporting lockstep) with 32 channels per eDMA                             | 2x safe eDMA (supporting lockstep) with 32 channels per eDMA                             | 2x safe eDMA (supporting lockstep) with 32 channels per eDMA                             | 2x safe eDMA (supporting lockstep) with 32 channels per eDMA                             |
| DMAMUX                       | 128 inputs per DMA                                                                       | 128 inputs per DMA                                                                       | 128 inputs per DMA                                                                       | 128 inputs per DMA                                                                       |
| Debug: Run control           | Arm CoreSight JTAG (IEEE 1149.1)                                                         | Arm CoreSight JTAG (IEEE 1149.1)                                                         | Arm CoreSight JTAG (IEEE 1149.1)                                                         | Arm CoreSight JTAG (IEEE 1149.1)                                                         |
| Debug: Trace                 | 4-lane Aurora                                                                            | 4-lane Aurora                                                                            | 4-lane Aurora                                                                            | 4-lane Aurora                                                                            |
| SWT instances                | 12                                                                                       | 12                                                                                       | 12                                                                                       | 12                                                                                       |
| STM instances                | 13                                                                                       | 13                                                                                       | 13                                                                                       | 13                                                                                       |
| Memory modules               | Memory modules                                                                           | Memory modules                                                                           | Memory modules                                                                           | Memory modules                                                                           |
| Internal RAM                 | 20 MB                                                                                    | 15 MB [3]                                                                                | 20 MB                                                                                    | 15 MB [3]                                                                                |
| RAM ports                    | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes |
| DRAM                         | DDR3L and LPDDR4 - up to 4 GB                                                            | DDR3L and LPDDR4 - up to 4 GB                                                            | DDR3L and LPDDR4 - up to 4 GB                                                            | DDR3L and LPDDR4 - up to 4 GB                                                            |
| DRAM PHY                     | x32                                                                                      | x32                                                                                      | x32                                                                                      | x32                                                                                      |
| QuadSPI instances            | 1                                                                                        | 1                                                                                        | 1                                                                                        | 1                                                                                        |
| uSDHC instances              | 1                                                                                        | 1                                                                                        | 1                                                                                        | 1                                                                                        |
| Fuses                        | 8 KB bank                                                                                | 8 KB bank                                                                                | 8 KB bank                                                                                | 8 KB bank                                                                                |
| Standby SRAM with ECC        | 32 KB                                                                                    | 32 KB                                                                                    | 32 KB                                                                                    | 32 KB                                                                                    |
| Security modules             | Security modules                                                                         | Security modules                                                                         | Security modules                                                                         | Security modules                                                                         |

Table continues on the next page...

S32G3 Data Sheet

Table 2. S32G3 feature list and supported functionality...continued

| Feature                               | S32G399A                                                     | S32G398A                                                     | S32G379A                                                     | S32G378A                                                     |
|---------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|
| Security subsystem                    | HSE_H                                                        | HSE_H                                                        | HSE_H                                                        | HSE_H                                                        |
| Resource isolation                    | XRDC supporting 16 domains                                   | XRDC supporting 16 domains                                   | XRDC supporting 16 domains                                   | XRDC supporting 16 domains                                   |
| Arm TrustZone                         | Supported                                                    | Supported                                                    | Supported                                                    | Supported                                                    |
| Life cycle                            | Supported                                                    | Supported                                                    | Supported                                                    | Supported                                                    |
| Secure debug                          | Supported                                                    | Supported                                                    | Supported                                                    | Supported                                                    |
| Communication interface modules       | Communication interface modules                              | Communication interface modules                              | Communication interface modules                              | Communication interface modules                              |
| Communication acceleration            | LLCE                                                         | LLCE                                                         | LLCE                                                         | LLCE                                                         |
| CAN with flexible data rate           | 16 in LLCE and 4 outside LLCE                                | 16 in LLCE and 4 outside LLCE                                | 16 in LLCE and 4 outside LLCE                                | 16 in LLCE and 4 outside LLCE                                |
| FlexRay 2.1 (dual- channel) instances | 1 in LLCE and 1 outside LLCE                                 | 1 in LLCE and 1 outside LLCE                                 | 1 in LLCE and 1 outside LLCE                                 | 1 in LLCE and 1 outside LLCE                                 |
| LINFlexD instances                    | 4 in LLCE and 3 outside LLCE                                 | 4 in LLCE and 3 outside LLCE                                 | 4 in LLCE and 3 outside LLCE                                 | 4 in LLCE and 3 outside LLCE                                 |
| Ethernet acceleration                 | PFE                                                          | PFE                                                          | PFE                                                          | PFE                                                          |
| Ethernet MAC                          | 3 in PFE and 1 outside PFE                                   | 3 in PFE and 1 outside PFE                                   | 3 in PFE and 1 outside PFE                                   | 3 in PFE and 1 outside PFE                                   |
| Ethernet interface                    | MII, RMII, RGMII, SGMII                                      | MII, RMII, RGMII, SGMII                                      | MII, RMII, RGMII, SGMII                                      | MII, RMII, RGMII, SGMII                                      |
| PCIe controller                       | 2x Gen3 controllers (X1, X2 modes)                           | 2x Gen3 controllers (X1, X2 modes)                           | 2x Gen3 controllers (X1, X2 modes)                           | 2x Gen3 controllers (X1, X2 modes)                           |
| SerDes subsystem                      | Four lanes (configurable PCIe and SGMII)                     | Four lanes (configurable PCIe and SGMII)                     | Four lanes (configurable PCIe and SGMII)                     | Four lanes (configurable PCIe and SGMII)                     |
| USBOTG instances                      | 1, supporting USB 2.0 and a ULPI interface                   | 1, supporting USB 2.0 and a ULPI interface                   | 1, supporting USB 2.0 and a ULPI interface                   | 1, supporting USB 2.0 and a ULPI interface                   |
| I 2 C instances                       | 4 + 1 for power management integrated circuits (PMIC)        | 4 + 1 for power management integrated circuits (PMIC)        | 4 + 1 for power management integrated circuits (PMIC)        | 4 + 1 for power management integrated circuits (PMIC)        |
| SPI instances                         | 4 (in LLCE, can be enabled with firmware) and 6 outside LLCE | 4 (in LLCE, can be enabled with firmware) and 6 outside LLCE | 4 (in LLCE, can be enabled with firmware) and 6 outside LLCE | 4 (in LLCE, can be enabled with firmware) and 6 outside LLCE |
| CRC instances                         | 1                                                            | 1                                                            | 1                                                            | 1                                                            |
| Generic modules                       | Generic modules                                              | Generic modules                                              | Generic modules                                              | Generic modules                                              |
| PIT instances                         | 2                                                            | 2                                                            | 2                                                            | 2                                                            |
| SAR_ADC instances                     | 12-bit 2 x 6 channels                                        | 12-bit 2 x 6 channels                                        | 12-bit 2 x 6 channels                                        | 12-bit 2 x 6 channels                                        |
| FTM instances                         | 2 x 6 channels                                               | 2 x 6 channels                                               | 2 x 6 channels                                               | 2 x 6 channels                                               |
| CTU instances                         | 1                                                            | 1                                                            | 1                                                            | 1                                                            |
| SEMA42 instances                      | 1                                                            | 1                                                            | 1                                                            | 1                                                            |
| Clocking, power, and reset modules    | Clocking, power, and reset modules                           | Clocking, power, and reset modules                           | Clocking, power, and reset modules                           | Clocking, power, and reset modules                           |
| FIRC frequency                        | 48 MHz                                                       | 48 MHz                                                       | 48 MHz                                                       | 48 MHz                                                       |
| SIRC frequency                        | 32 KHz                                                       | 32 KHz                                                       | 32 KHz                                                       | 32 KHz                                                       |
| FXOSC frequency                       | 20-40 MHz                                                    | 20-40 MHz                                                    | 20-40 MHz                                                    | 20-40 MHz                                                    |
| PLLDIG instances                      | 5                                                            | 5                                                            | 5                                                            | 5                                                            |

Table continues on the next page...

S32G3 Data Sheet

## Table 2. S32G3 feature list and supported functionality...continued

| Feature                               | S32G399A                                                     | S32G398A                                                     | S32G379A                                                     | S32G378A                                                     |
|---------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|
| Low-power mode                        | Supported                                                    | Supported                                                    | Supported                                                    | Supported                                                    |
| RTC                                   | 1 with API function                                          | 1 with API function                                          | 1 with API function                                          | 1 with API function                                          |
| Wake-up                               | 24 wake-up sources                                           | 24 wake-up sources                                           | 24 wake-up sources                                           | 24 wake-up sources                                           |
| Miscellaneous                         | Miscellaneous                                                | Miscellaneous                                                | Miscellaneous                                                | Miscellaneous                                                |
| Package specifications and dimensions | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm |

- [1] Cortex-A53\_2 and Cortex-A53\_3 have been defeatured in cluster 0 and cluster 1.
- [3] SRAM (12, 13, 14, 15) i.e., the highest address range (0x34F0\_0000-0x353F\_FFFF) associated to Cortex-M7\_2 have been defeatured. See the System RAM Controller chapter of the S32G3 Reference Manual for details on internal RAM support across the family.
- [2] Cortex-M7\_2 has been defeatured. See the System RAM Controller chapter of the S32G3 Reference Manual for details.

## 4 Ordering information

<!-- image -->

- Product brand and status 1-3

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

UC

<!-- image -->

## 1st, 2nd, 3rd Characters

Product brand and status

P32 = Prototype chip

S32 = Qualified chip

- 4 th  Character

Product line

G = Gateway

5 th  Character

Family

- 3 = S32G3 family

6 th  Character

MPU performance identifier

9

- 8× Cortex-A53 core

7

- 4× Cortex-A53 core

- 7 th  Character

MCU performance identifier and system RAM size

8

= 3× Cortex-M7 core and 15 MB SRAM

9

= 4× Cortex-M7 core and 20 MB SRAM

8 th  Character

Product type

A

= MCU + MPU

- 4 Product line
- 5 Family
- 6 MPU performance identifier
- 7 MCU performance identifier and system RAM size
- 8 Product type
- 9 Chip configuration
- 10 Arm core speeds
- 11-12 Fab and mask revision
- 13 Temperature (T ) range A
- 14-15 Package code
- 16 Shipping method

Figure 3. Ordering information

|                      | S32G399A   | S32G398A   | S32G379A   | S32G378A   |
|----------------------|------------|------------|------------|------------|
| Arm Cortex-M7 cores  | 4          | 3          | 4          | 3          |
| Arm Cortex-A53 cores | 8          | 8          | 4          | 4          |
| System RAM size      | 20 MB      | 15 MB      | 20 MB      | 15 MB      |

## 9th Character

Chip configuration

A = Standard chip

S

= Premium security chip

- 10 th  Character

Arm core speeds

A = 400 MHz (Cortex-M7 core), 1000 MHz (Cortex-A53 core)

B

= 400 MHz (Cortex-M7 core), 1100 MHz (Cortex-A53 core)

C

= 400 MHz (Cortex-M7 core), 1300 MHz (Cortex-A53 core)

D

= 400 MHz (Cortex-M7 core), 1400 MHz (Cortex-A53 core)

- 11 th  and 12 th  Characters

Fab and mask revision

K

= TSMC fab

- x = Mask revision (0 = first mask revision)

## 13 th  Character

Temperature (T ) range A

C = -40 °C to 85 °C

V

= -40 °C to 105 °C

- 14 th  and 15 th  Characters

Package code

UC = 525 FC-PBGA, 19×19 mm, 0.8 mm pitch

16 th  Character

Shipping method

T

R

= Tray

= Reel

S32G3 Data Sheet

## 5 Electrostatic Discharge (ESD) Characteristics

The following table gives the ESD ratings and test conditions for the device.

Table 3. Electrostatic Discharge (ESD) Characteristics

| Symbol   | Description                              | Min   | Typ   |   Max | Unit   | Condition   | Spec Number   |
|----------|------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| -        | ESD Human Body Model (HBM) [1][2][3]     | -     | -     |  2000 | V      | All pins    | -             |
| -        | ESD Charged Device Model (CDM) [1][2][4] | -     | -     |   250 | V      | All pins    | -             |

## 6 Absolute Maximum Ratings

This table defines the absolute maximum ratings for the device in terms of reliability characteristics. Absolute maximum rating specifications are stress ratings only, and functional operation is not guaranteed under these conditions. Functional operating conditions are given in the Operating Conditions section of this document.

Note: All specifications associated with VIN are measured at the SoC pin.

Table 4. Absolute Maximum Ratings

| Symbol           | Description                                 |   Min | Typ   |   Max | Unit   | Condition   | Spec Number   |
|------------------|---------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| VDD              | Core voltage Supply [1][2]                  |  -0.3 | -     |  0.96 | V      | -           | -             |
| VSS              | Ground Supply [1]                           |  -0.3 | -     |  0.3  | V      | -           | -             |
| VDD_STBY         | Standby domain supply voltage [1][2]        |  -0.3 | -     |  0.96 | V      | -           | -             |
| VDD_LV_PLL_AUR   | Aurora PLL digital voltage supply [1][2]    |  -0.3 | -     |  0.96 | V      | -           | -             |
| VDD_LV_PLL_ DDR0 | DDR0 PLL digital voltage supply [1][2]      |  -0.3 | -     |  0.96 | V      | -           | -             |
| VDD_VP_PCIEn     | PCIE0/1 core voltage supply (n=0, 1) [1][2] |  -0.3 | -     |  0.96 | V      | -           | -             |
| VDD_FIRC         | FIRC high voltage supply [1][3]             |  -0.3 | -     |  2.16 | V      | -           | -             |
| VDD_EFUSE        | EFUSE high voltage supply [1][3]            |  -0.3 | -     |  2.16 | V      | -           | -             |
| VDD_IO_x         | GPIO 3.3V supply [1] [4]                    |  -0.3 | -     |  4    | V      | -           | -             |

Table continues on the next page...

S32G3 Data Sheet

Table 4. Absolute Maximum Ratings...continued

| Symbol           | Description                                |   Min | Typ   |   Max | Unit   | Condition               | Spec Number   |
|------------------|--------------------------------------------|-------|-------|-------|--------|-------------------------|---------------|
| VDD_IO_A         | GPIO A 3.3V supply [1][4]                  |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_IO_B         | GPIO B 3.3V supply [1][4]                  |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_IO_GMAC0     | GMAC0 I/O voltage supply [1][4]            |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_IO_GMAC1     | GMAC1 I/O voltage supply [1][4]            |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_IO_QSPI      | QSPI A I/O voltage supply [1][3]           |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_IO_SDHC      | uSDHC / QSPI B I/O voltage supply [1][4]   |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_IO_CLKOUT    | CLKOUT 1.8V I/O supply [1][3]              |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_IO_AUR       | Aurora 1.8V I/O supply [1][3]              |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_IO_DDR0      | DDR0 I/O voltage supply [1]                |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_IO_USB       | USB I/O voltage supply [1][4]              |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_IO_STBY      | Standby domain I/O voltage supply [1][4]   |  -0.3 | -     |  4    | V      | -                       | -             |
| VDD_VREF         | Supply detector high voltage supply [1][3] |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_ADC          | ADC voltage supply [1][3]                  |  -0.3 | -     |  2.16 | V      | Reference to VSS_ ADC   | -             |
| VSS_ADC          | ADC ground supply [1]                      |  -0.3 | -     |  0.3  | V      | Reference to VSS        | -             |
| VDD_HV_PLL       | PLL high voltage supply [1][3]             |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_HV_PLL_ AUR  | Aurora PLL high voltage supply [1][3]      |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_HV_PLL_ DDR0 | DDR PLL voltage supply [1][3]              |  -0.3 | -     |  2.16 | V      | -                       | -             |
| VDD_DDR0         | DDR0 high voltage supply [1][3]            |  -0.3 | -     |  2.16 | V      | DDR PHY PLL             | -             |
| VDD_FXOSC        | FXOSC high voltage supply [1][3]           |  -0.3 | -     |  2.16 | V      | Reference to VSS_ FXOSC | -             |

Table continues on the next page...

## Table 4. Absolute Maximum Ratings...continued

| Symbol       | Description                                               | Min           | Typ   | Max             | Unit   | Condition               | Spec Number   |
|--------------|-----------------------------------------------------------|---------------|-------|-----------------|--------|-------------------------|---------------|
| VSS_FXOSC    | FXOSC ground supply [1]                                   | -0.3          | -     | 0.3             | V      | Reference to VSS        | -             |
| VEXTAL       | FXOSC EXTAL input voltage range [1][3][5]                 | -0.3          | -     | 2.16            | V      | -                       | -             |
| VXTAL        | FXOSC XTAL input voltage range [1][3][5]                  | -0.3          | -     | 2.16            | V      | -                       | -             |
| VDD_IO_PCIEn | PCIE0/1 high voltage supply (n=0, 1) [1][3]               | -0.3          | -     | 2.16            | V      | -                       | -             |
| VDD_TMU      | Thermal Monitoring Unit (TMU) high voltage supply [1][3]  | -0.3          | -     | 2.16            | V      | -                       | -             |
| VREFH_ADC    | ADC reference high voltage [1][3]                         | -0.3          | -     | 2.16            | V      | Reference to VREFL_ ADC | -             |
| VREFL_ADC    | ADC reference low voltage [1]                             | -0.3          | -     | 0.3             | V      | Reference to VSS        | -             |
| VAD_INPUT    | ADC input voltage range [1][6][7]                         | VSS_AD C -0.6 | -     | VDD_AD C +0.5   | V      | -                       | -             |
| VIN          | GPIO input voltage range [1][8][9][10]                    | VSS - 0.3     | -     | VDD_IO_ * + 0.3 | V      | -                       | -             |
| IINJ_D       | Maximum DC current injection digital I/O pin [1][11]      | -3            | -     | 3               | mA     | -                       | -             |
| IINJ_A       | Maximum DC current injection analog input pin [1][7] [12] | -1            | -     | 1               | mA     | -                       | -             |
| IINJ_LVDS    | Max LVDS RX or TX pin injection current [1][13]           | 0             | -     | 100             | uA     | -                       | -             |
| IMAXSEG      | Maximum RMS current per GPIO supply domain (VDD_IO_*) [1] | -             | -     | 140             | mA     | -                       | -             |
| TSTG         | Storage temperature range [1]                             | -55           | -     | 150             | C      | -                       | -             |
| TSDR         | Maximum solder temperature [1][14]                        | -             | -     | 260             | C      | Pb free                 | -             |
| MSL          | Moisture Sensitivity Level [1][15]                        | -             | -     | 3               | -      | -                       | -             |

Table continues on the next page...

## Table 4. Absolute Maximum Ratings...continued

| Symbol      | Description                         |   Min | Typ   |   Max | Unit   | Condition                                                                            | Spec Number   |
|-------------|-------------------------------------|-------|-------|-------|--------|--------------------------------------------------------------------------------------|---------------|
| V_OS_US_10  | Voltage at 10 %of tSIGNAL [16]      |  -0.4 | -     |  3.7  | V      | 3.3V, See "SoC-pin overshoot/undershoot voltage for each GPIO pad type" figure below | -             |
| V_OS_US_7p5 | Voltage at 7.50 %of tSIGNAL [16]    |  -0.5 | -     |  3.8  | V      | 3.3V, See "SoC-pin overshoot/undershoot voltage for each GPIO pad type" figure below | -             |
| V_OS_US_2p5 | Voltage at 2.50 %of tSIGNAL [16]    |  -0.6 | -     |  3.9  | V      | 3.3V, See "SoC-pin overshoot/undershoot voltage for each GPIO pad type" figure below | -             |
| V_OS_US_1p6 | Voltage at 1.60 %of tSIGNAL [1][16] |  -0.7 | -     |  4    | V      | 3.3V, See "SoC-pin overshoot/undershoot voltage for each GPIO pad type" figure below | -             |
| V_OS_US_10  | Voltage at 10 %of tSIGNAL [17]      |  -0.7 | -     |  2.31 | V      | 1.8V, See "SoC-pin overshoot/undershoot voltage for each GPIO pad type" figure below | -             |

- [1] Absolute maximum ratings are stress ratings only, and functional operation beyond the operating condition maxima is not guaranteed. Stress beyond the listed maxima may affect device reliability or cause permanent damage to the device. See the operating conditions table for functional specifications.

[3] Allowed 1.92V - 2.16V for 60 seconds cumulative over lifetime with no operating restrictions, 2.6 hours cumulative over lifetime with device in reset, at maximum Tj = 125 °C

[2] Allowed 0.88V - 0.96V for 60 seconds cumulative over lifetime with no operating restrictions, 2.0 hours cumulative over lifetime with device in reset, at maximum Tj = 125 °C

[4] Allowed 3.52V - 4.0V for 60 seconds cumulative over lifetime with no operating restrictions, 2.6 hours cumulative over lifetime with device in reset, at maximum Tj = 125 °C

- [6] The maximum input voltage on an I/O pin tracks with the associated I/O supply maximum. For the injection current condition on a pin, the voltage equals the supply plus the voltage drop across the internal ESD diode from I/O pin to supply.
- [5] VEXTAL/ VXTAL (min) is for powered condition. VEXTAL/VXTAL (min) can be lower in unpowered condition.
- [7] Allowed for a cumulative duration of 50 hours operation over the lifetime of the device at maximum Tj, with VDD\_ADC &lt;= 1.92V, VSS\_ADC = 0V. Allowed for unlimited duration if the device is unpowered.
- [9] Absolute minimum DC VIN level for a powered device is -0.3V. For unpowered devices, the allowed VIN min level is -0.9V. Unpowered devices must simultaneously follow IINJ\_D unpowered current injection constraints.
- [8] Absolute maximum DC VIN levels for a powered device are 3.82V and 2.22V, for 3.3V and 1.8V domains, respectively. For powered devices when VIN ≥ VDD\_IO*, VIN must simultaneously follow the constraint that VIN-VDD\_IO* ≤ 0.3V for the DC case. For unpowered devices, the allowed VIN max level is +0.9V. Unpowered devices must simultaneously follow IINJ\_D unpowered current injection constraints.
- [10] DC case limit. Overshoot/Undershoot beyond this range is allowed, but only for the limited durations as constrained by temporal percentages of tSIGNAL.
- [12] Non-disturb of ADC channels during current injection cannot be guaranteed. The degradation in channel performance cannot be specified due to the dynamic operation of the ADC input mux and potential for varying charge distribution. For the max +/-1mA DC injection quoted here, VAD\_INPUT would be +0.5/-0.6V relative to VREFH\_ADC/VREFL\_ADC at max Tj. ADC Output of the channel into which injection occurs will saturate depending on the direction of injection and for the channels not subject to current injection Offset error would be -12 LSB to 6 LSB and TUE would be -12 LSB to 8 LSB.
- [11] IINJ\_D specifications are per pin for an unpowered condition of the associated supply. The maximum simultaneous injection per supply is 30mA.
- [13] Applies exclusively to ZipWire and does not apply to Aurora. Allowed for a cumulative of 14 hours over the life of the part. The voltage on the RX or TX pin must not exceed 2.16 V at any time during the power-cycling or normal operation.
- [15] Moisture sensitivity per JEDEC test method A112.
- [14] Solder profile per IPC/JEDEC J-STD-020D.
- [16] For AC Signals in a 3.3V supply domain, if VDD\_IO ≤ 3.3V, max VIN overshoot is limited to VDD\_IO+20%. If VDD\_IO &gt; 3.3V, then max VIN overshoot is limited to 4V.
- [17] For AC Signals in a 1.8V supply domain, max VIN overshoot is limited to VDD\_IO+20% for 10% of tSIGNAL.

S32G3 Data Sheet

S32G3 Data Sheet

Figure 4. Soc-pin overshoot/undershoot voltage for each GPIO pad type

<!-- image -->

## 7 Operating conditions

## 7.1 Operating Conditions

The following table describes the functional operating conditions for the device, and for which all specifications in this datasheet are valid, except where explicitly noted. Device behavior is not guaranteed for operation outside of the conditions in this table.

Note: ΔVDD* specifications are applicable to the supplies mentioned in the condition column when the device is not in standby mode. VDD\_IO\_B, VDD\_IO\_QSPI and VDD\_DDR0 may stay powered in standby mode as applicable to the group.

Note: All specifications associated with VIN are measured at the SoC pin.

Table 5. Operating Conditions

| Symbol      | Description                                | Min   | Typ   |   Max | Unit   | Condition   | Spec Number   |
|-------------|--------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| fSYS_A53    | Cortex-A53 core operating frequency [1][2] | -     | -     |  1400 | MHz    | -           | -             |
| fSYS_CM7    | Cortex-M7 core operating frequency [1][2]  | -     | -     |   400 | MHz    | -           | -             |
| fSYS_PFE_PE | PFE PE operating frequency [1][2]          | -     | -     |   600 | MHz    | -           | -             |
| Tj          | Junction Temperature Range [1][3][4]       | -40   | -     |   125 | C      | -           | -             |
| Ta          | Ambient Temperature Range [1][4]           | -40   | -     |   105 | C      | -           | -             |

Table continues on the next page...

Table 5. Operating Conditions...continued

| Symbol           | Description                              | Min   |   Typ | Max   | Unit   | Condition                  | Spec Number   |
|------------------|------------------------------------------|-------|-------|-------|--------|----------------------------|---------------|
| VDD              | Core voltage Supply [1]                  | 0.75  |   0.8 | 0.87  | V      | -                          | -             |
| VSS              | Ground Supply [1]                        | -     |   0   | -     | V      | -                          | -             |
| VDD_STBY         | Standby domain supply voltage [1][5]     | 0.75  |   0.8 | 0.87  | V      | -                          | -             |
| VDD_LV_PLL_AUR   | Aurora PLL digital voltage supply [1]    | 0.75  |   0.8 | 0.87  | V      | -                          | -             |
| VDD_LV_PLL_ DDR0 | DDR0 PLL digital voltage supply [1]      | 0.75  |   0.8 | 0.87  | V      | -                          | -             |
| VDD_VP_PCIE0     | PCIE0/1 core voltage supply [1][6]       | 0.75  |   0.8 | 0.87  | V      | -                          | -             |
| VDD_IO_A         | GPIO A 3.3V supply [1]                   | 3.08  |   3.3 | 3.52  | V      | -                          | -             |
| VDD_IO_B         | GPIO B 3.3V supply [1][7]                | 3.08  |   3.3 | 3.52  | V      | -                          | -             |
| VDD_IO_GMAC0     | GMAC0 I/O voltage supply [1]             | 1.68  |   1.8 | 1.92  | V      | 1.8V                       | -             |
| VDD_IO_GMAC0     | GMAC0 I/O voltage supply [1]             | 3.08  |   3.3 | 3.52  | V      | 3.3V                       | -             |
| VDD_IO_GMAC1     | GMAC1 I/O voltage supply [1]             | 1.68  |   1.8 | 1.92  | V      | 1.8V                       | -             |
| VDD_IO_GMAC1     | GMAC1 I/O voltage supply [1]             | 3.08  |   3.3 | 3.52  | V      | 3.3V                       | -             |
| VDD_IO_QSPI      | QuadSPI A I/O voltage supply [1][8]      | 1.68  |   1.8 | 1.92  | V      | 1.8V                       | -             |
| VDD_IO_SDHC      | uSDHC / QSPI B I/O voltage supply [1]    | 1.68  |   1.8 | 1.92  | V      | 1.8V                       | -             |
| VDD_IO_SDHC      | uSDHC I/O voltage supply [1]             | 3.08  |   3.3 | 3.52  | V      | 3.3V                       | -             |
| VDD_IO_CLKOUT    | CLKOUT 1.8V I/O supply [1]               | 1.68  |   1.8 | 1.92  | V      | -                          | -             |
| VDD_IO_AUR       | Aurora 1.8V I/O supply [1]               | 1.68  |   1.8 | 1.92  | V      | Aurora LVDS Tx + ref clock | -             |
| VDD_IO_STBY      | Standby domain I/O voltage supply [1][7] | 3.08  |   3.3 | 3.52  | V      | -                          | -             |
| VDD_IO_USB       | USB I/O voltage supply [1]               | 1.68  |   1.8 | 1.92  | V      | 1.8V                       | -             |

Table continues on the next page...

Table 5. Operating Conditions...continued

| Symbol            | Description                                           |    Min | Typ   |   Max | Unit   | Condition   | Spec Number   |
|-------------------|-------------------------------------------------------|--------|-------|-------|--------|-------------|---------------|
| VDD_IO_USB        | USB I/O voltage supply [1]                            |  3.08  | 3.3   |  3.52 | V      | 3.3V        | -             |
| VDD_IO_DDR0       | DDR3L I/O voltage supply [1]                          |  1.283 | 1.35  |  1.45 | V      | -           | -             |
| VDD_IO_DDR0       | LPDDR4 I/O voltage supply [1]                         |  1.06  | 1.1   |  1.17 | V      | -           | -             |
| δVDD_IO_DDR0      | DDR3L I/O supply ripple voltage [1]                   | -5     | -     |  5    | %      | -           | -             |
| δVDD_IO_DDR0      | LPDDR4 I/O supply ripple voltage [1]                  | -2.5   | -     |  2.5  | %      | -           | -             |
| VDD_DDR0          | DDR0 high voltage supply [1]                          |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_FIRC          | FIRC high voltage supply [1]                          |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_VREF          | PMC high voltage supply [1]                           |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_EFUSE         | EFUSE high voltage supply [1][9][10][11]              |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_ADC           | ADC high voltage supply [1]                           |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_HV_PLL        | PLL high voltage supply [1]                           |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_HV_PLL_ AUR   | Aurora PLL high voltage supply [1]                    |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_HV_PLL_ DDR0  | DDR PLL voltage supply [1]                            |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| ðVDD_HV_PLL_ DDR0 | DDR PLL supply ripple voltage [1]                     | -2.5   | -     |  2.5  | %      | -           | -             |
| VDD_FXOSC         | FXOSC high voltage supply [1]                         |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_IO_PCIEn      | PCIE0/1 high voltage supply [1][6]                    |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VDD_TMU           | Thermal Monitoring Unit (TMU) high voltage supply [1] |  1.68  | 1.8   |  1.92 | V      | -           | -             |
| VREFH_ADCn        | ADC reference high voltage (n=0, 1) [1]               |  1.68  | 1.8   |  1.92 | V      | -           | -             |

Table continues on the next page...

Table 5. Operating Conditions...continued

| Symbol            | Description                                                               | Min       | Typ   | Max             | Unit   | Condition                                                                                                                                                            | Spec Number   |
|-------------------|---------------------------------------------------------------------------|-----------|-------|-----------------|--------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|
| VIN_33            | 3.3V GPIO input voltage range [1][12] [13][14]                            | VSS - 0.3 | -     | VDD_IO_ * + 0.3 | V      | -                                                                                                                                                                    | -             |
| VIN_18            | 1.8V GPIO input voltage range [1][12] [13][14]                            | VSS - 0.3 | -     | VDD_IO_ * + 0.3 | V      | -                                                                                                                                                                    | -             |
| ΔVDD              | 0.8V supply voltage differential [1][15]                                  | -25       | -     | 25              | mV     | Applies to all 0.8V supplies on the device.                                                                                                                          | -             |
| ΔVDD_HV_18_IO     | 1.8V I/O supply voltage differential group [1][15][16][17]                | -25       | -     | 25              | mV     | Applies to VDD_IO_ QSPI, VDD_IO_SDHC, VDD_IO_GMAC0, VDD_IO_GMAC1, VDD_IO_USB                                                                                         | -             |
| ΔVDD_HV_18_ ANA   | 1.8V analog supply voltage differential group [1][9][10][11][15] [17][18] | -25       | -     | 25              | mV     | Applies to VDD_IO_CLKOUT, VDD_IO_AUR, VDD_ TMU, VREFH_ADC*, VDD_ADC, VDD_HV_ PLL*, VDD_VREF, VDD_FXOSC, VDD_ FIRC, VDD_EFUSE, VDD_DDR0, VDD_ IO_PCIE0, VDD_IO_ PCIE1 | -             |
| ΔVDD_HV_33_IO     | 3.3V I/O supply voltage differential group [1][15][17][19]                | -25       | -     | 25              | mV     | VDD_IO_A, VDD_IO_B                                                                                                                                                   | -             |
| ΔVSS_HV_18        | 1.8V supply ground voltage differential [1] [15]                          | -25       | -     | 25              | mV     | Applies to VSS, VREFL_ADCn, VSS_ ADC, VSS_FXOSC                                                                                                                      | -             |
| VRAMP_LV          | LV supply voltage ramp-up rate [1][20]                                    | 0.001     | -     | 24              | V / ms | Applies to 0.8V supplies                                                                                                                                             | -             |
| VRAMP_HV          | HV supply voltage ramp-up rate [1]                                        | 0.001     | -     | 24              | V / ms | Applies to 1.8V supplies and DDR I/O supplies.                                                                                                                       | -             |
| VRAMP_HV_33_IO    | 3.3V I/O supply voltage ramp-up rate [1]                                  | 0.001     | -     | 50              | V / ms | Applies to 3.3V I/O supplies.                                                                                                                                        | -             |
| TDISCHARGE_ STDBY | Supply discharge time during Standby mode entry [1]                       | 100       | -     | -               | us     | Applies to all switchable supplies during Standby mode entry                                                                                                         | -             |

Table continues on the next page...

Table 5. Operating Conditions...continued

| Symbol    | Description                                    | Min             | Typ   | Max             | Unit   | Condition   | Spec Number   |
|-----------|------------------------------------------------|-----------------|-------|-----------------|--------|-------------|---------------|
| VAD_INPUT | ADC input voltage range [1][21]                | VSS_AD C - 0.35 | -     | VDD_AD C + 0.25 | V      | -           | -             |
| IINJ_D    | GPIO Input DC Injection Current [1] [22]       | -3              | -     | 3               | mA     | Unpowered   | -             |
| IINJ_D    | GPIO Input DC Injection Current [1] [23]       | 0               | -     | 5               | uA     | Powered     | -             |
| IINJ_A    | SAR ADC Input DC Injection Current [1] [24]    | -20             | -     | 20              | uA     | -           | -             |
| IMAXSEG   | Maximum RMS current per GPIO supply domain [1] | -               | -     | 120             | mA     | -           | -             |

- [3] Lifetime operation at Tj max not guaranteed. Standard automotive temperature profile assumed for performance and reliability guarantees.
- [2] The stated maximum operating frequency must be observed when using the PLL with frequency modulation enabled. Center-spread modulation is supported in cases where the nominal operating frequency plus half the modulation depth is less than the stated maximum frequency.

[4] The junction temperature (Tj) range specification cannot be violated. The ambient temperature shown in the table, is a rough indicative value, for a typical system. Customers must ensure there is an appropriate thermal solution in their system to keep Tj within the spec range

- [6] Both PCIe supplies must ramp for the SerDes PHY to safely power up into its reset state. Until both supplies are ramped, the SerDes PHY will be in an undefined state.

[5] The operating voltage range applies when the device is not in standby mode.

- [7] A minimum of 2.91V is supported on this supply when the device is in low-power standby mode if it is kept powered during this mode.
- [9] The VDD\_EFUSE supply must be maintained within specification during fuse programming. Failure to do this may result in improper functionality of the device after fuse programming.
- [8] The device supports QSPI interface to 3.3V memories on the QSPI B bank, which is multiplexed with uSDHC functions on the VDD\_IO\_SDHC supply. QSPI A signals on VDD\_IO\_QSPI are limited to 1.8V.
- [10] VDD\_EFUSE must be grounded when not actively programming the fuses. This supply is not required to be powered for fuse reads. See device hardware design guidelines document for more details.
- [12] For AC signals, allowed max VIN ≤ VDD\_IO* for lifetime operation. If AC overshoot beyond VDD\_IO* occurs, then refer to the Abs Max duration constraints as a function of the amount of overshoot. For DC signals ≥ VDD\_IO, VIN-VDD\_IO* ≤ 0.3V is allowed for lifetime operation.
- [11] Refer to the Power Sequencing section for the relationship of VDD\_EFUSE powering up/down relative to the core, high-voltage, and I/O supplies.
- [13] The min DC VIN level for a powered device is -0.3V. If AC undershoot below -0.3V occurs, then refer to the Abs Max duration constraints as a function of the amount of undershoot.
- [15] The "voltage differential" refers to the difference between the lowest and highest voltages across all supplies within the supply group as defined under Condition column.
- [14] DC case limit. Overshoot/Undershoot beyond this range is allowed, but only for the limited durations as constrained by temporal percentages of tSIGNAL.
- [16] Applies to multi-voltage supplies when operating in 1.8V range.
- [18] VREFH\_ADCn allows a differential voltage of +/-100mV.
- [17] Applies only during power up while POR\_B is asserted.
- [19] Applies to multi-voltage supplies when operating in 3.3V range
- [21] The maximum input voltage on an I/O pin tracks with the associated I/O supply maximum. For the injection current condition on a pin, the voltage equals the supply plus the voltage drop across the internal ESD diode from I/O pin to supply.
- [20] On slow ramps, the RESET\_B pin may be observed to be asserted multiple times during the supply ramping. In order to prevent these pulses from being propagated into the system, it is recommended that the PMIC drives RESET\_B low during supply ramp or whenever POR\_B is asserted.
- [22] IINJ\_D specifications are per pin for an unpowered condition of the associated supply. The maximum simultaneous injection per supply is 30mA.
- [24] The SAR ADC electrical specifications are not guaranteed during any period when the operating injection current limit is violated. These specifications are at maximum Tj and VREFH\_ADC=1.8V; the injected current will reduce with reduced Tj.
- [23] You must ensure that neither IINJ nor VIN specs are violated. Negligible DC injection currents are expected to flow during normal powered operation.

The device hardware design guidelines document summarizes mandatory board design rules in table 'Decaps and Ferrite Bead requirement' and section 'PDN (Power Delivery Network) Guidelines".

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

<!-- image -->

## 7.2 Clock frequency ranges

The following table gives the frequency range minimum and maximums to use when programming the clock dividers on the device.

Table 6. Clock frequency ranges

| Symbol               | Description                           | Min   | Typ   |   Max | Unit   | Condition           | Spec Number   |
|----------------------|---------------------------------------|-------|-------|-------|--------|---------------------|---------------|
| fA53_CORE_DIV2_ CLK  | Cortex-A53 core div2 clock frequency  | 24    | -     |   700 | MHz    | A53_CORE_DIV2_CLK   | -             |
| fA53_CORE_ DIV10_CLK | Cortex-A53 core div10 clock frequency | 4.8   | -     |   140 | MHz    | A53_CORE_DIV10_ CLK | -             |
| fLBIST_CLK           | LBIST[7:0] clock frequency            | -     | -     |    50 | MHz    | LBIST_CLK[7:0]      | -             |

Table continues on the next page...

Table 6. Clock frequency ranges...continued

| Symbol           | Description                          | Min   | Typ   |   Max | Unit   | Condition      | Spec Number   |
|------------------|--------------------------------------|-------|-------|-------|--------|----------------|---------------|
| fXBAR_CLK        | XBAR clock frequency                 | 24    | -     | 400   | MHz    | XBAR_CLK       | -             |
| fXBAR_2X_CLK     | XBAR 2X clock frequency              | 48    | -     | 800   | MHz    | XBAR_2X_CLK    | -             |
| fXBAR_DIV2_CLK   | XBAR div2 clock frequency            | 12    | -     | 200   | MHz    | XBAR_DIV2_CLK  | -             |
| fXBAR_DIV3_CLK   | XBAR div3 clock frequency            | 8     | -     | 133   | MHz    | XBAR_DIV3_CLK  | -             |
| fXBAR_DIV4_CLK   | XBAR div4 clock frequency            | 6     | -     | 100   | MHz    | XBAR_DIV4_CLK  | -             |
| fXBAR_DIV6_CLK   | XBAR div6 clock frequency            | 4     | -     |  66.7 | MHz    | XBAR_DIV6_CLK  | -             |
| fDAPB_CLK        | Debug clock frequency                | -     | -     | 133   | MHz    | fDAPB_CLK      | -             |
| fFRAY_CHI        | FlexRay CHI clock frequency          | -     | -     | 133   | MHz    | -              | -             |
| fSERDES_REF_ CLK | SERDES reference clock frequency     | 100   | -     | 125   | MHz    | SERDES_REF_CLK | -             |
| fPER_CLK         | Peripheral clock frequency           | -     | -     |  80   | MHz    | PER_CLK        | -             |
| fFTM_0_REF_CLK   | FlexTimer 0 external clock frequency | -     | -     |  20   | MHz    | FTM_0_REF_CLK  | -             |
| fFTM_1_REF_CLK   | FlexTimer 1 external clock frequency | -     | -     |  20   | MHz    | FTM_1_REF_CLK  | -             |
| fFLEXRAY_PE_ CLK | FlexRay PE clock frequency           | -     | -     |  40   | MHz    | FLEXRAY_PE_CLK | -             |
| fCAN_PE_CLK      | CAN PE clock frequency               | 40    | -     |  80   | MHz    | CAN_PE_CLK     | -             |
| fLIN_BAUD_CLK    | LIN baud clock frequency             | -     | -     | 133   | MHz    | LIN_BAUD_CLK   | -             |
| fLINFLEXD_CLK    | LIN clock frequency                  | -     | -     |  66.7 | MHz    | LINFLEXD_CLK   | -             |
| fGMAC_TS_CLK     | GMAC timestamp cl ock frequency      | 5     | -     | 200   | MHz    | GMAC_TS_CLK    | -             |
| fGMAC_0_TX_CLK   | GMAC_0 transmit clock frequency      | 2.5   | -     | 125   | MHz    | GMAC_0_TX_CLK  | -             |
| fGMAC_0_RX_CLK   | GMAC_0 receive clock frequency       | 2.5   | -     | 125   | MHz    | GMAC_0_RX_CLK  | -             |

Table continues on the next page...

Table 6. Clock frequency ranges...continued

| Symbol              | Description                         | Min   | Typ   |   Max | Unit   | Condition                      | Spec Number   |
|---------------------|-------------------------------------|-------|-------|-------|--------|--------------------------------|---------------|
| fGMAC_0_REF_ CLK    | GMAC_0 reference clock frequency    | -     | -     |  50   | MHz    | GMAC_0_REF_CLK                 | -             |
| fPFE_MAC_0_TX_ CLK  | PFE MAC_0 transmit clock frequency  | 2.5   | -     | 312.5 | MHz    | PFE_MAC_0_TX_CLK               | -             |
| fPFE_MAC_0_RX_ CLK  | PFE MAC_0 receive clock frequency   | 2.5   | -     | 312.5 | MHz    | PFE_MAC_0_RX_CLK               | -             |
| fPFE_MAC_0_ REF_CLK | PFE MAC_0 reference clock frequency | -     | -     |  50   | MHz    | PFE_MAC_0_REF_ CLK             | -             |
| fPFE_MAC_1_TX_ CLK  | PFE MAC_1 transmit clock frequency  | 2.5   | -     | 312.5 | MHz    | PFE_MAC_1_TX_CLK               | -             |
| fPFE_MAC_1_RX_ CLK  | PFE MAC_1 receive clock frequency   | 2.5   | -     | 312.5 | MHz    | PFE_MAC_1_RX_CLK               | -             |
| fPFE_MAC_1_ REF_CLK | PFE MAC_1 reference clock frequency | -     | -     |  50   | MHz    | PFE_MAC_1_REF_ CLK             | -             |
| fPFE_MAC_2_TX_ CLK  | PFE MAC_2 transmit cloc k frequency | 2.5   | -     | 312.5 | MHz    | PFE_MAC_2_TX_CLK               | -             |
| fPFE_MAC_2_RX_ CLK  | PFE MAC_2 receive clock frequency   | 2.5   | -     | 312.5 | MHz    | PFE_MAC_2_RX_CLK               | -             |
| fPFE_MAC_2_ REF_CLK | PFE MAC_2 reference clock frequency | -     | -     |  50   | MHz    | PFE_MAC_2_REF_ CLK             | -             |
| fSPI_CLK            | SPI clock frequency                 | 10    | -     | 100   | MHz    | SPI_CLK                        | -             |
| fQSPI_2X_CLK        | QSPI 2X clock frequency             | -     | -     | 400   | MHz    | QSPI_2X_CLK - DDR 200MHz       | -             |
| fQSPI_2X_CLK        | QSPI 2X clock frequency             | -     | -     | 333   | MHz    | QSPI_2X_CLK - DDR 166MHz       | -             |
| fQSPI_2X_CLK        | QSPI 2X clock frequency             | -     | -     | 266   | MHz    | QSPI_2X_CLK - DDR / SDR 133MHz | -             |
| fQSPI_2X_CLK        | QSPI 2X clock frequency             | -     | -     | 208   | MHz    | QSPI_2X_CLK - SDR 104MHz       | -             |
| fQSPI_2X_CLK        | QSPI 2X clock frequency             | -     | -     | 200   | MHz    | QSPI_2X_CLK - SDR 100MHz       | -             |
| fQSPI_2X_CLK        | QSPI 2X clock frequency             | -     | -     | 133   | MHz    | QSPI_2X_CLK - DDR 66MHz        | -             |

Table continues on the next page...

Table 6. Clock frequency ranges...continued

| Symbol       | Description                | Min   | Typ   |   Max | Unit   | Condition                      | Spec Number   |
|--------------|----------------------------|-------|-------|-------|--------|--------------------------------|---------------|
| fQSPI_1X_CLK | QSPI 1X clock frequency    | -     | -     |   200 | MHz    | QSPI_1X_CLK - DDR 200MHz       | -             |
| fQSPI_1X_CLK | QSPI 1X clock frequency    | -     | -     |   166 | MHz    | QSPI_1X_CLK - DDR 166MHz       | -             |
| fQSPI_1X_CLK | QSPI 1X clock frequency    | -     | -     |   133 | MHz    | QSPI_1X_CLK - DDR / SDR 133MHz | -             |
| fQSPI_1X_CLK | QSPI 1X clock frequency    | -     | -     |   104 | MHz    | QSPI_1X_CLK - SDR 104MHz       | -             |
| fQSPI_1X_CLK | QSPI 1X clock frequency    | -     | -     |   100 | MHz    | QSPI_1X_CLK - SDR 100MHz       | -             |
| fQSPI_1X_CLK | QSPI 1X clock frequency    | -     | -     |    66 | MHz    | QSPI_1X_CLK - DDR 66MHz        | -             |
| fSDHC_CLK    | uSDHC clock frequency      | -     | -     |   200 | MHz    | SDHC_CLK - DDR HS400           | -             |
| fSDHC_CLK    | uSDHC clock frequency      | 133   | -     |   200 | MHz    | SDHC_CLK - DDR HS400           | -             |
| fSDHC_CLK    | uSDHC clock frequency      | -     | -     |   200 | MHz    | SDHC_CLK - SDR HS200           | -             |
| fSDHC_CLK    | uSDHC clock frequency      | -     | -     |   100 | MHz    | SDHC_CLK - SDR 100MHz          | -             |
| fSDHC_CLK    | uSDHC clock frequency      | -     | -     |    50 | MHz    | SDHC_CLK - DDR / SDR 52MHz     | -             |
| fPFE_PE_CLK  | PFE PE clock frequency     | -     | -     |   600 | MHz    | PFE_PE_CLK                     | -             |
| fPFE_SYS_CLK | PFE system clock frequency | -     | -     |   300 | MHz    | PFE_SYS_CLK                    | -             |

## 8 Thermal Characteristics

Thermal characteristics are targets based on simulation from preliminary die and package definitions. The specified characteristics are subject to change per final device design and characterization. Junction temperature is a function of die size, on-chip power dissipation, package thermal resistance, mounting site (board) temperature, ambient temperature, air flow, power dissipation of other components on the board, and board thermal resistance.

Table 7. Thermal Resistance

| Board type [1]   | Symbol   | Description                                |   Value | Unit   |
|------------------|----------|--------------------------------------------|---------|--------|
| JESD51-9, 2s2p   | R θJA    | Junction to ambient Thermal Resistance     |    15.6 | °C/W   |
| JESD51-9, 2s2p   | Ψ JT     | Junction to Lid Top Thermal Resistance [2] |     0.3 | °C/W   |

Table continues on the next page...

Table 7. Thermal Resistance...continued

| Board type [1]   | Symbol   | Description                             |   Value | Unit   |
|------------------|----------|-----------------------------------------|---------|--------|
| NA               | R θJC    | Junction to Case Thermal Resistance [3] |     0.4 | °C/W   |

## 9 DC electricals

## 9.1 Total power specifications for 0.8V and 1.8V Analog Domains

The following table contains the individual max and thermal 0.8V power figures for each device in the S32G3 family as well as a 1.8V analog total which applies to all devices. For I/O power specifications please see dedicated I/O table.

Table 8. Total power specifications for 0.8V and 1.8V Analog Domains

| Symbol   | Description                                          | Min   | Typ   |   Max | Unit   | Condition                                                                                                                       | Spec Number   |
|----------|------------------------------------------------------|-------|-------|-------|--------|---------------------------------------------------------------------------------------------------------------------------------|---------------|
| -        | 0.8V Supply Rail Power: S32G399A Max Usecase [1]     | -     | -     |  8.62 | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G399A Max Usecase [1]     | -     | -     |  8.77 | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G399A Thermal Usecase [2] | -     | -     |  8.41 | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G399A Thermal Usecase [1] | -     | -     |  8.56 | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_                                            | -             |

Table continues on the next page...

<!-- image -->

Table 8. Total power specifications for 0.8V and 1.8V Analog Domains...continued

| Symbol   | Description                                              | Min   | Typ   | Max   | Unit   | Condition                                                                                                                       | Spec Number   |
|----------|----------------------------------------------------------|-------|-------|-------|--------|---------------------------------------------------------------------------------------------------------------------------------|---------------|
|          |                                                          |       |       |       |        | PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR                                                                                      |               |
| -        | 0.8V Supply Rail Power: S32G398A Max Usecase [1][3]      | -     | -     | 8.56  | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G398A Max Usecase [1][3]      | -     | -     | 8.71  | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G398A Thermal Usecase [2] [3] | -     | -     | 8.35  | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G398A Thermal Usecase [2] [3] | -     | -     | 8.5   | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G379A Max Usecase [1][3]      | -     | -     | 8.28  | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |

Table continues on the next page...

Table 8. Total power specifications for 0.8V and 1.8V Analog Domains...continued

| Symbol   | Description                                              | Min   | Typ   |   Max | Unit   | Condition                                                                                                                       | Spec Number   |
|----------|----------------------------------------------------------|-------|-------|-------|--------|---------------------------------------------------------------------------------------------------------------------------------|---------------|
| -        | 0.8V Supply Rail Power: S32G379A Max Usecase [1][3]      | -     | -     |  8.43 | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G379A Thermal Usecase [2] [3] | -     | -     |  8.08 | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G379A Thermal Usecase [2] [3] | -     | -     |  8.23 | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G378A Max Usecase [1][3]      | -     | -     |  8.22 | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G378A Max Usecase [1][3]      | -     | -     |  8.37 | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR | -             |
| -        | 0.8V Supply Rail Power: S32G378A Thermal Usecase [2] [3] | -     | -     |  8.02 | W      | fSYS_A53=1311 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_                           | -             |

Table continues on the next page...

Table 8. Total power specifications for 0.8V and 1.8V Analog Domains...continued

| Symbol   | Description                                              | Min   | Typ   | Max   | Unit   | Condition                                                                                                                                                          | Spec Number   |
|----------|----------------------------------------------------------|-------|-------|-------|--------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|
|          |                                                          |       |       |       |        | PLL_DDR0, VDD_LV_ PLL_AUR                                                                                                                                          |               |
| -        | 0.8V Supply Rail Power: S32G378A Thermal Usecase [2] [3] | -     | -     | 8.17  | W      | fSYS_A53=1400 MHz, Tj=125C, All 0.8v supplies at 0.8V, Sum of VDD, VDD_STBY, VDD_VP_ PCIE0/1, VDD_LV_ PLL_DDR0, VDD_LV_ PLL_AUR                                    | -             |
| -        | 1.8V Analog Supply Rail power: All devices [4]           | -     | -     | 0.135 | W      | Tj=125C, All 1.8V supplies at 1.8V, Sum of VDD_FXOSC, VDD_HV_PLL_AUR, VDD_HV_PLL_DDR0, VDD_ADC, VREFH_ ADC0/1, VDD_FIRC, VDD_VREF, VDD_HV_ PLL, VDD_TMU, VDD_ DDR0 | -             |

## 9.2 Static power specifications for I/O Domains

The following table contains the static power consumption for each I/O power domain. This data does not include the usage dependent dynamic current of GPIO-pins. To estimate the dynamic GPIO current for a specific use-case, an IO calculator tool is available. For IO calculator, contact your NXP sales representative. The " Device Power and Operating Current Specifications"  table contains pre-calculated total I/O power (static + dynamic) for common usecases.

Table 9. Static power specifications for I/O Domains

| Symbol        | Description                      | Min   | Typ   |   Max | Unit   | Condition          | Spec Number   |
|---------------|----------------------------------|-------|-------|-------|--------|--------------------|---------------|
| SPVDD_IO_A    | 3.3V Static Power on VDD_IO_A    | -     | -     |   2.6 | mW     | VDD_IO_A = 3.3V    | -             |
| SPVDD_IO_B    | 3.3V Static Power on VDD_IO_B    | -     | -     |   2.2 | mW     | VDD_IO_B = 3.3V    | -             |
| SPVDD_IO_STBY | 3.3V Static Power on VDD_IO_STBY | -     | -     |   3.1 | mW     | VDD_IO_STBY = 3.3V | -             |
| SPVDD_IO_SDHC | 3.3V Static Power on VDD_IO_SDHC | -     | -     | 159   | mW     | VDD_IO_SDHC = 3.3V | -             |

Table continues on the next page...

S32G3 Data Sheet

Table 9. Static power specifications for I/O Domains...continued

| Symbol           | Description                              | Min   | Typ   |   Max | Unit   | Condition            | Spec Number   |
|------------------|------------------------------------------|-------|-------|-------|--------|----------------------|---------------|
| SPVDD_IO_SDHC    | 1.8V Static Power on VDD_IO_SDHC         | -     | -     |  12.1 | mW     | VDD_IO_SDHC = 1.8V   | -             |
| SPVDD_IO_ GMAC0  | 3.3V Static Power on VDD_IO_GMAC0        | -     | -     | 150.5 | mW     | VDD_IO_GMAC0 = 3.3V  | -             |
| SPVDD_IO_ GMAC0  | 1.8V Static Power on VDD_IO_GMAC0        | -     | -     |  11.4 | mW     | VDD_IO_GMAC0 = 1.8V  | -             |
| SPVDD_IO_ GMAC1  | 3.3V Static Power on VDD_IO_GMAC1        | -     | -     | 151.5 | mW     | VDD_IO_GMAC1 = 3.3V  | -             |
| SPVDD_IO_ GMAC1  | 1.8V Static Power on VDD_IO_GMAC1        | -     | -     |  11.5 | mW     | VDD_IO_GMAC1 = 1.8V  | -             |
| SPVDD_IO_USB     | 3.3V Static Power on VDD_IO_USB          | -     | -     | 152.6 | mW     | VDD_IO_USB = 3.3V    | -             |
| SPVDD_IO_USB     | 1.8V Static Power on VDD_IO_USB          | -     | -     |  11.4 | mW     | VDD_IO_USB = 1.8V    | -             |
| SPVDD_IO_QSPI    | 1.8V Static Power on VDD_IO_QSPI         | -     | -     |   0.5 | mW     | VDD_IO_QSPI = 1.8V   | -             |
| SPVDD_IO_ CLKOUT | 1.8V Static Power on VDD_IO_CLKOUT       | -     | -     |   0.7 | mW     | VDD_IO_CLKOUT = 1.8V | -             |
| SPVDD_IO_PCIE0   | 1.8V Static Power on VDD_IO_PCIE0        | -     | -     |   2.8 | mW     | VDD_IO_PCIE0 = 1.8V  | -             |
| SPVDD_IO_PCIE1   | 1.8V Static Power on VDD_IO_PCIE1        | -     | -     |   2.8 | mW     | VDD_IO_PCIE1 = 1.8V  | -             |
| SPVDD_IO_AUR     | 1.8V Static Power on VDD_IO_AUR          | -     | -     |   0.8 | mW     | VDD_IO_AUR = 1.8V    | -             |
| SPVDD_IO_DDR     | 1.1V Static Power on VDD_IO_DDR - LPDDR4 | -     | -     |   2.4 | mW     | VDD_IO_DDR = 1.1V    | -             |
| SPVDD_IO_DDR     | 1.35V Static Power on VDD_IO_DDR - DDR3L | -     | -     |   2.8 | mW     | VDD_IO_DDR = 1.35V   | -             |

## 9.3 Device Power and Operating Current Specifications

The device power consumption, operating current, and applicable conditions are given in the following table.

Note: All measurements are at Tj=125C, unless otherwise specified.

Table 10. Device Power and Operating Current Specifications

| Symbol           | Description                                                 | Min   | Typ   | Max   | Unit   | Condition                                                                 | Spec Number   |
|------------------|-------------------------------------------------------------|-------|-------|-------|--------|---------------------------------------------------------------------------|---------------|
| PVDD_STBY        | Standby mode core supply power                              | -     | 58    | -     | uW     | Ta = 25C, VDD_ STBY = 0.8V, typical silicon, all pull up/down disabled    | -             |
| PVDD_IO_STBY     | Standby mode I/O supply power [1]                           | -     | 110   | -     | uW     | Ta = 25C, VDD_IO_ STBY = 3.0V, typical silicon, all pull up/down disabled | -             |
| IDD_FXOSC        | VDD_FXOSC operating current                                 | -     | 0.6   | -     | mA     | 1.8V, 40MHz                                                               | -             |
| IDD_HV_PLL_AUR   | VDD_HV_PLL_AUR operating current                            | -     | 4.3   | -     | mA     | 1.8V, fPLL_VCO = 5GHz                                                     | -             |
| IDD_HV_PLL_ DDR0 | VDD_HV_PLL_DDR 0 operating current (DDR reference PLL only) | -     | 2     | -     | mA     | fPLL_DDR_PHI0 = 800MHz, fDDR_PLL = 1600MHz, 1.8V                          | -             |
| IDD_ADC          | VDD_ADC operating current                                   | -     | 1.8   | -     | mA     | 1.8V, 2 ADCs@ 1Msps                                                       | -             |
| IDD_ADC          | VDD_ADC operating current                                   | -     | 200   | -     | uA     | 1.8V, Disabled (per ADC)                                                  | -             |
| IVREFH_ADC       | VREFH_ADC operating current                                 | -     | 210   | -     | uA     | VREFH_ADC = 1.8V                                                          | -             |
| IDD_FIRC         | VDD_FIRC operating current                                  | -     | 0.6   | -     | mA     | FIRC trimmed frequency (48MHz typical)                                    | -             |
| IDD_VREF         | VDD_VREF operating current                                  | -     | 0.7   | -     | mA     | 1.8V                                                                      | -             |
| IDD_HV_PLL       | VDD_HV_PLL operating current                                | -     | 8.9   | -     | mA     | 1.8V, fPLL_VCO = 2GHz, Core / Peripheral/Acclerator PLLs                  | -             |
| IDD_EFUSE_PGM    | VDD_EFUSE programming current                               | -     | -     | 140   | mA     | VDD_EFUSE=1.8V, VDD=0.8V                                                  | -             |
| IDD_TMU          | VDD_TMU operating current                                   | -     | 4.6   | -     | mA     | 1.8V, central unit and remote sensors operating                           | -             |
| IDD_DDR0         | VDD_DDR0 operating current                                  | -     | 5.0   | -     | mA     | 1.8V, fPLL_DDR_PHI0 = 800MHz, fDDR_PLL = 1600MHz                          | -             |
| PVDD_IO_PCIEn    | VDD_IO_PCIE0 operating power [2]                            | -     | -     | 76    | mW     | All circuits enabled, VDD_IO_PCIEn=1.8V,                                  | -             |

Table continues on the next page...

Table 10. Device Power and Operating Current Specifications...continued

| Symbol            | Description                               | Min   | Typ   | Max   | Unit   | Condition                                                                                                                               | Spec Number   |
|-------------------|-------------------------------------------|-------|-------|-------|--------|-----------------------------------------------------------------------------------------------------------------------------------------|---------------|
|                   |                                           |       |       |       |        | Gen3 8Gbps, 2 lanes. Per IP instance                                                                                                    |               |
| PVDD_IO_PCIEn     | VDD_IO_PCIE0 operating power              | -     | -     | 72    | mW     | All circuits enabled, VDD_IO_PCIEn=1.8V, Gen2.1 5Gbps, 2 lanes. Per IP instance                                                         | -             |
| PVDD_IO_PCIEn     | VDD_IO_PCIE0 operating power              | -     | -     | 68    | mW     | All circuits enabled, VDD_IO_PCIEn=1.8V, Gen1.1 2.5Gbps, 2 lanes. Per IP instance                                                       | -             |
| PVDD_IO_PCIEn     | VDD_IO_PCIE0 operating power              | -     | -     | 1.5   | mW     | Powered down state, VDD_IO_PCIEn=1.8V, Per IP instance                                                                                  | -             |
| PVDD_IO_DDR       | VDD_IO_DDR 100% write operating power     | -     | -     | 625   | mW     | LPDDR4, VDD_IO_ DDR = 1.1V, 3200 MT/s, 100% write, 1/2 data lines switching, 60 Ohm transmit termination driving a 60 Ohm load          | -             |
| PVDD_IO_DDR_ IDLE | VDD_IO_DDR idle power                     | -     | 55    | -     | mW     | LPDDR4, VDD_IO_ DDR = 1.1V, Tj = 25C                                                                                                    | -             |
| PVDD_IO_DDR_ RET  | VDD_IO_DDR data retention power           | -     | 0.02  | -     | mW     | LPDDR4, VDD_IO_ DDR = 1.1V, Standby mode and DRAM in self-refresh, Tj=25C.                                                              | -             |
| PVDD_IO_DDR_ RET  | VDD_IO_DDR data retention power           | -     | 0.030 | -     | mW     | DDR3L, VDD_IO_DDR = 1.35V, Standby mode and DRAM in self-refresh, Tj=25C.                                                               | -             |
| PVDD_IO_DDR       | VDD_IO_DDR 100% write operating power     | -     | -     | 598   | mW     | DDR3L, VDD_IO_DDR = 1.35V, 1600 MT/s, 100% Write operation, 1/2 data lines switching, 60 Ohm transmit termination driving a 60 ohm load | -             |
| PVDD_IO_DDR_ IDLE | VDD_IO_DDR idle power                     | -     | 57    | -     | mW     | DDR3L, VDD_IO_DDR = 1.35V, Tj=25C                                                                                                       | -             |
| PVDD_IO_QSPI      | QSPI A I/O voltage supply operating power | -     | 58    | -     | mW     | 1.8V, 200MHz - clocks 100% activity rate, 50% data rate, 1/2 data switching per cycle,                                                  | -             |

Table continues on the next page...

Table 10. Device Power and Operating Current Specifications...continued

| Symbol           | Description                            | Min   | Typ   | Max   | Unit   | Condition                                                                                                                                                                        | Spec Number   |
|------------------|----------------------------------------|-------|-------|-------|--------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|
|                  |                                        |       |       |       |        | does not include power for other I/O ins on the VDD_IO_QSPI supply. 15.5pF.                                                                                                      |               |
| PVDD_IO_SDHC     | VDD_IO_SDHC operating power            | -     | 128   | -     | mW     | 1.8V, HS400, SD_CLK 100%, SD_D(8) 50%, 1/2 data switching per cycle, does not include power for other I/O pins on the VDD_IO_SDHC supply, 15.5pF                                 | -             |
| PVDD_IO_GMACn    | VDD_IO_GMACn operating power           | -     | 81    | -     | mW     | 1.8V, RGMII 125MHz, 100% clock rate, 50% data rate, 1/2 data switching per cycle, per IP instance, does not include power for other I/O pins on the VDD_IO_GMACn supply. 15.5pF  | -             |
| PVDD_IO_GMACn    | VDD_IO_GMACn operating power           | -     | 292   | -     | mW     | 3.3V, RGMII 125MHz, 100% clock rate, 50% data rate, 1/2 data switching per cycle, per IP instance, does not include power for other I/O pins on the VDD_IO_GMACn supply, 15.5pF. | -             |
| PVDD_IO_USB_ TYP | USB I/O voltage supply operating power | -     | 59    | -     | mW     | 1.8V, modem - 8 outputs @60MHz, 50% data rate, 1/2 data switching per cycle, does not include power for other I/O pins on the VDD_IO_USB supply. 15.5pF.                         | -             |
| PVDD_IO_USB_ TYP | USB I/O voltage supply operating power | -     | 174   | -     | mW     | 3.3V, modem - 8 outputs @60MHz, 50% data rate, 1/2 data switching per cycle, does not include power for the other I/O pins on the VDD_IO_USB supply. 15.5pF                      | -             |

Table continues on the next page...

Table 10. Device Power and Operating Current Specifications...continued

| Symbol      | Description                               | Min   |   Typ | Max   | Unit   | Condition                                                               | Spec Number   |
|-------------|-------------------------------------------|-------|-------|-------|--------|-------------------------------------------------------------------------|---------------|
| PVDD_IO_AUR | Aurora I/O voltage supply operating power | -     |   164 | -     | mW     | 1.8V, 5Gbps on 4 lanes, 50% Activity Rate, 1/2 data switching per cycle | -             |

## 10 Power sequencing

## 10.1 Power-up

The following sequence has been validated by NXP and is to be followed when powering up the device. Each supply within a step must be within its specified operating voltage range before the next step in the sequence is started,  except as noted below.

1. Set POR\_B input to low value.
2. Ramp up VDD\_IO\_STBY supply.

VDD\_IO\_B can optionally be included with VDD\_IO\_STBY in the first step.

3. Ramp up all GPIO supplies powered to 3.3V.
4. Ramp up all 1.8V supplies including GPIO supplies powered to 1.8V

Step 5 and 6 can start before step 4 starts or before it reaches its DC tolerance but still after step 3 has reached its DC tolerance. Step 5 must still reach DC tolerance before Step 6 starts to ramp.

5. Ramp up VDD\_IO\_DDR supply
6. Ramp up all 0.8V supplies
7. Set POR\_B and PMIC\_VDD\_OK inputs to high value once all supplies have reached their specified levels.

Note: For step 4, it is acceptable for the 1.8V supplies to not yet be within their specified range at the time of asserting the PMIC\_VDD\_OK input when exiting Standby mode if it is ensured that they are within their specified range no later than 140 us after the PMIC\_VDD\_OK input assertion. VDD\_IO\_QSPI (a 1.8V GPIO supply) has the additional option to ramp with step 3 instead of step 4.

Figure 7. 1.8V supply timing with respect to PMIC\_VDD\_OK during Standby Mode Exit

<!-- image -->

Note: While powering up the device, the VDD\_EFUSE supply pin must be kept powered down. While the device is already powered up, the VDD\_EFUSE supply pin can be powered up/down independent of the other supplies on the device. The VDD\_EFUSE supply pin must be powered down prior to Standby mode entry or, at the latest, powered down together with the other 1.8V supplies during Standby mode entry.

The power-up sequence on Standby exit is the same except that only the switchable supplies that were powered down during Standby mode are ramped up again, and the POR\_B input is kept high throughout the sequence.

S32G3 Data Sheet

## 10.2 Power-down

When powering down the SoC, it is recommended to use the reverse order from the power-up sequence. If this cannot be achieved, ensure that all supplies are below the Vpwrdwn level before powering up again.

Table 11. Power-down

| Symbol   | Description                                       | Min   | Typ   |   Max | Unit   | Condition   | Spec Number   |
|----------|---------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| Vpwrdwn  | Maximum voltage on a supply pin in powerdown mode | -     | -     |   100 | mV     | -           | -             |

## 11 Electromagnetic compatibility (EMC)

EMC measurements to IC-level IEC standards are available from NXP Semiconductor on request.

## 12 GPIO Pads

## Table 12. GPIO Pads

| Symbol    | Description                                     | Min             | Typ   | Max             | Unit   | Condition       | Spec Number   |
|-----------|-------------------------------------------------|-----------------|-------|-----------------|--------|-----------------|---------------|
| VIH       | Input high level DC voltage threshold           | 0.7 * VDD_IO_ * | -     | -               | V      | 1.8V / 3.3V     | -             |
| VIL       | Input low level DC voltage threshold            | -               | -     | 0.3 * VDD_IO_ * | V      | 1.8V / 3.3V     | -             |
| VOL       | GPIO output low voltage [1]                     | -               | -     | 20% * VDD_IO_ * | V      | -               | -             |
| VOH       | GPIO output high voltage [1]                    | 80% * VDD_IO_ * | -     | -               | V      | -               | -             |
| VHYS_33   | 3.3V GPIO input hysteresis voltage              | 100             | -     | -               | mV     | Always enabled. | -             |
| ILKG_18   | 1.8V GPIO pad input leakage current             | -17             | -     | 17              | uA     | 1.8V, Tj = 125C | -             |
| ILKG_33   | 3.3V GPI / GPIO pad input leakage current       | -30             | -     | 30              | uA     | 3.3V, Tj = 125C | -             |
| ILKG_3318 | 1.8V/3.3V GPIO pad input leakage current (3.3V) | -50             | -     | 50              | uA     | 3.3V, Tj = 125C | -             |
| ILKG_3318 | 1.8V/3.3V GPIO pad input leakage current (1.8V) | -17             | -     | 17              | uA     | 1.8V, Tj = 125C | -             |

Table continues on the next page...

S32G3 Data Sheet

Table 12. GPIO Pads...continued

| Symbol       | Description                                  | Min   | Typ   | Max   | Unit   | Condition                                             | Spec Number   |
|--------------|----------------------------------------------|-------|-------|-------|--------|-------------------------------------------------------|---------------|
| CIN_18       | Input capacitance (1.8V GPIO)                | -     | 6     | 8     | pF     | -                                                     | -             |
| CIN_33       | Input capacitance (3.3V GPI / GPIO)          | -     | 7     | 11    | pF     | -                                                     | -             |
| CIN_3318     | Input capacitance (1.8V/3.3V GPIO)           | -     | 7     | 11    | pF     | -                                                     | -             |
| ISLEW        | Input signal slew rate [2]                   | 1     | -     | 4     | V/ns   | -                                                     | -             |
| ITR_TF       | Input signal rise/fall time [2][3]           | 0.5   | -     | 2     | ns     | -                                                     | -             |
| TPW_MIN      | Input minimum pulse width                    | 2     | -     | -     | ns     | -                                                     | -             |
| FMAX_IN_18   | 1.8V GPIO maximum input frequency [4]        | -     | -     | 50    | MHz    | CMOS Receiver                                         | -             |
| FMAX_IN_18   | 1.8V GPIO maximum input frequency [4]        | -     | -     | 208   | MHz    | VREF Receiver                                         | -             |
| FMAX_IN_3318 | 1.8V/3.3V GPIO maximum input frequency [4]   | -     | -     | 208   | MHz    | 1.8V                                                  | -             |
| FMAX_IN_3318 | 1.8V/3.3V GPIO maximum input frequency [4]   | -     | -     | 166.7 | MHz    | 3.3V                                                  | -             |
| FMAX_IN_33   | 3.3V GPIO maximum input frequency [4]        | -     | -     | 50    | MHz    | -                                                     | -             |
| IPU_18       | 1.8V GPIO pull up/ down resistance           | 9     | 18    | 23    | kΩ     | pull up @0.3 * VDD_ HV_IO, pull down@ 0.7 * VDD_HV_IO | -             |
| IPU_33       | 3.3V GPIO pull up/ down resistance           | 9     | 18    | 23    | kΩ     | pull up @0.3 * VDD_ HV_IO, pull down@ 0.7 * VDD_HV_IO | -             |
| IPU_3318     | 1.8V/3.3V GPIO pull up/down resistance       | 9     | 18    | 23    | kΩ     | pull up @0.3 * VDD_ HV_IO, pull down@ 0.7 * VDD_HV_IO | -             |
| RDSON_18     | 1.8V GPIO output impedance (NMOS & PMOS) [5] | 27.0  | 36.3  | 48.0  | Ω      | SRE[2:0] = xxx, 50% * VDD_IO_*                        | -             |
| RDSON_3318   | 1.8V/3.3V GPIO output impedance              | 18.0  | 30.0  | 43.0  | Ω      | SRE[2:0] = 000, 50% * VDD_IO_*                        | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol     | Description                                               | Min   | Typ   | Max   | Unit   | Condition                      | Spec Number   |
|------------|-----------------------------------------------------------|-------|-------|-------|--------|--------------------------------|---------------|
|            | (NMOS & PMOS) at 1.8V [5]                                 |       |       |       |        |                                |               |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 1.8V [5] | 19.0  | 30.0  | 44.0  | Ω      | SRE[2:0] = 100, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 1.8V [5] | 21.0  | 33.0  | 49.0  | Ω      | SRE[2:0] = 101, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 1.8V [5] | 23.0  | 37.5  | 58.0  | Ω      | SRE[2:0] = 110, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 1.8V [5] | 24.0  | 37.5  | 57.0  | Ω      | SRE[2:0] = 111, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 3.3V [5] | 18.0  | 30.0  | 43.0  | Ω      | SRE[2:0] = 000, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 3.3V [5] | 19.0  | 30.0  | 44.0  | Ω      | SRE[2:0] = 100, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 3.3V [5] | 21.0  | 33.4  | 50.0  | Ω      | SRE[2:0] = 101, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 3.3V [5] | 23.0  | 39.5  | 61.0  | Ω      | SRE[2:0] = 110, 50% * VDD_IO_* | -             |
| RDSON_3318 | 1.8V/3.3V GPIO output impedance (NMOS & PMOS) at 3.3V [5] | 26.0  | 39.5  | 61.0  | Ω      | SRE[2:0] = 111, 50% * VDD_IO_* | -             |
| RDSON_33   | 3.3V GPIO output impedance (NMOS & PMOS) [5]              | 16.5  | 26.5  | 42.0  | Ω      | SRE[2:0] = 100, 50% * VDD_IO_* | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol   | Description                                    |   Min | Typ   |   Max | Unit   | Condition                      | Spec Number   |
|----------|------------------------------------------------|-------|-------|-------|--------|--------------------------------|---------------|
| RDSON_33 | 3.3V GPIO output impedance (NMOS & PMOS) [5]   |  19.2 | 30.5  |  49.5 | Ω      | SRE[2:0] = 101, 50% * VDD_IO_* | -             |
| RDSON_33 | 3.3V GPIO output impedance (NMOS & PMOS) [5]   |  24.5 | 38.0  |  61.5 | Ω      | SRE[2:0] = 110, 50% * VDD_IO_* | -             |
| RDSON_33 | 3.3V GPIO output impedance (NMOS & PMOS) [5]   |  32   | 48.0  |  75.5 | Ω      | SRE[2:0] = 111, 50% * VDD_IO_* | -             |
| IOH_18   | 1.8V GPIO output high current [5]              | -15   | -     |  -6   | mA     | SRE[2:0] = xxx, 80% * VDD_IO_* | -             |
| IOL_18   | 1.8V GPIO output low current [5]               |   6   | -     |  15   | mA     | SRE[2:0] = xxx, 20% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 1.8V [5] | -22   | -     |  -8   | mA     | SRE[2:0] = 000, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 1.8V [5] | -21   | -     |  -8   | mA     | SRE[2:0] = 100, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 1.8V [5] | -19   | -     |  -6   | mA     | SRE[2:0] = 101, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 1.8V [5] | -17   | -     |  -6   | mA     | SRE[2:0] = 110, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 1.8V [5] | -17   | -     |  -6   | mA     | SRE[2:0] = 111, 80% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 1.8V [5]  |   8   | -     |  22   | mA     | SRE[2:0] = 000, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 1.8V [5]  |   8   | -     |  21   | mA     | SRE[2:0] = 100, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 1.8V [5]  |   6   | -     |  20   | mA     | SRE[2:0] = 101, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 1.8V [5]  |   6   | -     |  18   | mA     | SRE[2:0] = 110, 20% * VDD_IO_* | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol   | Description                                    |   Min | Typ   |   Max | Unit   | Condition                      | Spec Number   |
|----------|------------------------------------------------|-------|-------|-------|--------|--------------------------------|---------------|
| IOL_3318 | 1.8V/3.3V GPIO output low current at 1.8V [5]  |   6   | -     |  17   | mA     | SRE[2:0] = 111, 20% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 3.3V [5] | -40   | -     | -14   | mA     | SRE[2:0] = 000, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 3.3V [5] | -40   | -     | -14   | mA     | SRE[2:0] = 100, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 3.3V [5] | -35   | -     | -10   | mA     | SRE[2:0] = 101, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 3.3V [5] | -32   | -     | -10   | mA     | SRE[2:0] = 110, 80% * VDD_IO_* | -             |
| IOH_3318 | 1.8V/3.3V GPIO output high current at 3.3V [5] | -32   | -     | -10   | mA     | SRE[2:0] = 111, 80% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 3.3V [5]  |  15   | -     |  40   | mA     | SRE[2:0] = 000, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 3.3V [5]  |  15   | -     |  40   | mA     | SRE[2:0] = 100, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 3.3V [5]  |  13   | -     |  36   | mA     | SRE[2:0] = 101, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 3.3V [5]  |  12   | -     |  33   | mA     | SRE[2:0] = 110, 20% * VDD_IO_* | -             |
| IOL_3318 | 1.8V/3.3V GPIO output low current at 3.3V [5]  |  11   | -     |  32   | mA     | SRE[2:0] = 111, 20% * VDD_IO_* | -             |
| IOH_33   | 3.3V GPIO output high current [5]              | -40.1 | -     | -14   | mA     | SRE[2:0] = 100, 80% * VDD_IO_* | -             |
| IOH_33   | 3.3V GPIO output high current [5]              | -36.2 | -     | -12.1 | mA     | SRE[2:0] = 101, 80% * VDD_IO_* | -             |
| IOH_33   | 3.3V GPIO output high current [5]              | -32   | -     | -10.3 | mA     | SRE[2:0] = 110, 80% * VDD_IO_* | -             |
| IOH_33   | 3.3V GPIO output high current [5]              | -29   | -     |  -9   | mA     | SRE[2:0] = 111, 80% * VDD_IO_* | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol   | Description                                | Min   | Typ   |   Max | Unit   | Condition                                                                                     | Spec Number   |
|----------|--------------------------------------------|-------|-------|-------|--------|-----------------------------------------------------------------------------------------------|---------------|
| IOL_33   | 3.3V GPIO output low current [5]           | 14.6  | -     |  39.4 | mA     | SRE[2:0] = 000, 20% * VDD_IO_*                                                                | -             |
| IOL_33   | 3.3V GPIO output low current [5]           | 14.6  | -     |  39.4 | mA     | SRE[2:0] = 100, 20% * VDD_IO_*                                                                | -             |
| IOL_33   | 3.3V GPIO output low current [5]           | 13.0  | -     |  35.5 | mA     | SRE[2:0] = 101, 20% * VDD_IO_*                                                                | -             |
| IOL_33   | 3.3V GPIO output low current [5]           | 11.2  | -     |  32   | mA     | SRE[2:0] = 110, 20% * VDD_IO_*                                                                | -             |
| IOL_33   | 3.3V GPIO output low current [5]           | 10.0  | -     |  29   | mA     | SRE[2:0] = 111, 20% * VDD_IO_*                                                                | -             |
| FMAX_18  | 1.8V GPIO maximum output frequency [5][6]  | -     | -     | 208   | MHz    | SRE[2:0] = 000                                                                                | -             |
| FMAX_18  | 1.8V GPIO maximum output frequency [5][6]  | -     | -     | 150   | MHz    | SRE[2:0] = 100                                                                                | -             |
| FMAX_18  | 1.8V GPIO maximum output frequency [5] [6] | -     | -     | 133   | MHz    | SRE[2:0] = 101                                                                                | -             |
| FMAX_18  | 1.8V GPIO maximum output frequency [5][6]  | -     | -     | 100   | MHz    | SRE[2:0] = 110                                                                                | -             |
| FMAX_18  | 1.8V GPIO maximum output frequency [5] [6] | -     | -     |  50   | MHz    | SRE[2:0] = 111                                                                                | -             |
| FMAX_33  | 3.3V GPIO maximum output frequency [5][6]  | -     | -     |  50   | MHz    | SRE[2:0] = 100                                                                                | -             |
| FMAX_33  | 3.3V GPIO maximum output frequency [5][6]  | -     | -     |  50   | MHz    | SRE[2:0] = 101, reduced slew relative to the SRE[2:0] = 100 setting for the same output load. | -             |
| FMAX_33  | 3.3V GPIO maximum output frequency [5][6]  | -     | -     |  50   | MHz    | SRE[2:0] = 110                                                                                | -             |
| FMAX_33  | 3.3V GPIO maximum output frequency [5][6]  | -     | -     |   1   | MHz    | SRE[2:0] = 111                                                                                | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol     | Description                                       | Min   | Typ   |    Max | Unit   | Condition            | Spec Number   |
|------------|---------------------------------------------------|-------|-------|--------|--------|----------------------|---------------|
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 208    | MHz    | SRE[2:0] = 000, 1.8V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 166.7  | MHz    | SRE[2:0] = 100, 1.8V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 150    | MHz    | SRE[2:0] = 101, 1.8V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 133.3  | MHz    | SRE[2:0] = 110, 1.8V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 100    | MHz    | SRE[2:0] = 111, 1.8V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 166.7  | MHz    | SRE[2:0] = 000, 3.3V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 150    | MHz    | SRE[2:0] = 100, 3.3V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 133.3  | MHz    | SRE[2:0] = 101, 3.3V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     | 100    | MHz    | SRE[2:0] = 110, 3.3V | -             |
| FMAX_3318  | 1.8V/3.3V GPIO maximum output frequency [5][6]    | -     | -     |  83.3  | MHz    | SRE[2:0] = 111, 3.3V | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 1.8V [5][6] [7] | 1.0   | -     |   5.5  | V/ns   | SRE[2:0] = 000       | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 1.8V [5][6] [7] | 1.0   | -     |   5.75 | V/ns   | SRE[2:0] = 100       | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 1.8V [5][6] [7] | 0.75  | -     |   4.75 | V/ns   | SRE[2:0] = 101       | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 1.8V [5][6] [7] | 0.5   | -     |   4.5  | V/ns   | SRE[2:0] = 110       | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol     | Description                                       | Min   | Typ   | Max   | Unit   | Condition                                                  | Spec Number   |
|------------|---------------------------------------------------|-------|-------|-------|--------|------------------------------------------------------------|---------------|
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 1.8V [5][6] [7] | 0.5   | -     | 4.0   | V/ns   | SRE[2:0] = 111                                             | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 3.3V [5][6] [7] | 2.0   | -     | 10.5  | V/ns   | SRE[2:0] = 000                                             | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 3.3V [5][6] [7] | 2.0   | -     | 9.25  | V/ns   | SRE[2:0] = 100                                             | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 3.3V [5][6] [7] | 1.5   | -     | 9.5   | V/ns   | SRE[2:0] = 101                                             | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 3.3V [5][6] [7] | 0.75  | -     | 7.5   | V/ns   | SRE[2:0] = 110                                             | -             |
| TR_TF_3318 | 1.8V/3.3V GPIO rise/ fall time at 3.3V [5][6] [7] | 0.75  | -     | 7.25  | V/ns   | SRE[2:0] = 111                                             | -             |
| TR_TF_18   | 1.8V GPIO rise/fall time [5][6][7]                | 0.75  | -     | 3.75  | V/ns   | SRE[2:0] = 000                                             | -             |
| TR_TF_18   | 1.8V GPIO rise/fall time [5][6][7]                | 0.75  | -     | 3.75  | V/ns   | SRE[2:0] = 100                                             | -             |
| TR_TF_18   | 1.8V GPIO rise/fall time [5][6][7]                | 0.75  | -     | 3.25  | V/ns   | SRE[2:0] = 101                                             | -             |
| TR_TF_18   | 1.8V GPIO rise/fall time [5][6][7]                | 0.75  | -     | 3.25  | V/ns   | SRE[2:0] = 110                                             | -             |
| TR_TF_18   | 1.8V GPIO rise/fall time [5][6][7]                | 0.25  | -     | 3.25  | V/ns   | SRE[2:0] = 111                                             | -             |
| TR_TF_33   | 3.3V GPIO rise/fall time [5][6][7]                | 1.90  | -     | 9.0   | V/ns   | SRE[2:0] = 100                                             | -             |
| TR_TF_33   | 3.3V GPIO rise/fall time [5][6][7]                | 1.00  | -     | 8.50  | V/ns   | SRE[2:0] = 101                                             | -             |
| TR_TF_33   | 3.3V GPIO rise/fall time [5][6][7]                | 0.50  | -     | 7.30  | V/ns   | SRE[2:0] = 110                                             | -             |
| TR_TF_33   | 3.3V GPIO rise/fall time [5][6][7]                | 0.40  | -     | 6.0   | V/ns   | SRE[2:0] = 111                                             | -             |
| VISE_33    | 3.3V GPIO pad indeterminate state end threshold   | -     | 2.35  | -     | V      | See 1.8V and 3.3V GPIO pad detailed behavior diagram below | -             |

Table continues on the next page...

Table 12. GPIO Pads...continued

| Symbol    | Description                                          | Min   |   Typ | Max   | Unit   | Condition                                                  | Spec Number   |
|-----------|------------------------------------------------------|-------|-------|-------|--------|------------------------------------------------------------|---------------|
| VISE_3318 | 1.8V/3.3V GPIO pad indeterminate state end threshold | -     |  1.53 | -     | V      | See 1.8V/3.3V GPIO pad detailed behavior diagram below     | -             |
| VISE_18   | 1.8V GPIO pad indeterminate state end threshold      | -     |  0.6  | -     | V      | See 1.8V and 3.3V GPIO pad detailed behavior diagram below | -             |

- [1] For current at this voltage see IOL/IOH specs respectively.
- [3] The ISLEW has precedence over ITR\_TF if the ITR\_TF violates the implied range for a given ISLEW.
- [2] Fastest slew rate and lowest rise/fall time constraint required to meet high-speed interface timing such as QSPI, RGMII, and uSDHC. Slower input transitions can be used for input signals with slow switching rates (&lt;40 MHz).
- [4] Input slew rate and rise/fall time limits must be adhered to in conjunction with the max input frequency limits given for proper operation.
- [6] I/O timing specifications are valid for the un-terminated 50ohm transmission line reference load given in the figure below. A lumped 8pF load is assumed at the end of a 5 inch microstrip trace on standard FR4 with approximately 3.3pF/inch. For signals with frequency greater than 63MHz, a maximum 2 inch PCB trace is assumed. For best signal integrity, the series resistance in the transmission line should be matched closely to the selected RDSON of the I/O pad output.
- [5] GPIO output transition time information can be obtained from the device IBIS model. IBIS models are recommended for system level simulations, as discrete values for I/O transition times are not representative of the I/O pad behavior when connected to an actual transmission line load.
- [7] Rise/fall time specifications are derived from simulation model for the defined operating points (between 20% and 80% of VDD\_HV\_IO level). Actual application rise/fall time should be extracted from IBIS model simulations with the microcontroller models and application PCB. Actual application rise fall times extracted from simulation must meet the TR\_TF specification.

Note: In the Standby mode exit case, the rising edge of the PMIC\_VDD\_OK pin determines when the pads enter their 'POR value' state instead of the POR\_B pin.

<!-- image -->

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

The high-impedance state level is shown based on the external pull-up being on the corresponding pad supply.

## 13 Aurora specifications

## 13.1 Aurora Pads

## Table 13. Aurora Pads

| Symbol     | Description                                                        |   Min | Typ   |   Max | Unit   | Condition                                                                        | Spec Number   |
|------------|--------------------------------------------------------------------|-------|-------|-------|--------|----------------------------------------------------------------------------------|---------------|
| fAURORA    | Data Rate                                                          |  0.05 | -     |     5 | Gbps   | 100Ω external termination ( Not on board but inside receiver after AC coupling ) | -             |
| IDD_HV_AUR | Transmitter HV supply current consumption (No pre-emphasis)        | 18    | 22    |    31 | mA     | max fAURORA per active transmit lane                                             | -             |
| IDD_HV_AUR | Transmitter HV supply current consumption (pre- emphasis enabled , | 25    | 30    |    40 | mA     | max fAURORA per active transmit lane                                             | -             |

Table continues on the next page...

Table 13. Aurora Pads...continued

| Symbol                  | Description                                                                                    | Min   | Typ   | Max   | Unit       | Condition                                                                                 | Spec Number   |
|-------------------------|------------------------------------------------------------------------------------------------|-------|-------|-------|------------|-------------------------------------------------------------------------------------------|---------------|
|                         | pre- emphasis gain=11)                                                                         |       |       |       |            |                                                                                           |               |
| VOD_AURORA_ AC          | Transmitter Differential output voltage (end termination) [1][2][3]                            | 400   | 600   | 900   | mV         | max fAURORA, 100Ω termination, 100Ω differential transmission line delay, matched network | -             |
| VOD_AURORA_ DC          | DC range for the VOD (Transmitter Differen tial Output Voltage)                                | 800   | -     | -     | mV         | ipp_obe=1 DC condition                                                                    | -             |
| VOD_AURORA_ AC_PRE_EMPH | Transmitter Differential output voltage (end termination, preemph=11) [2][3][4]                | 600   | 900   | 1200  | mV         | max fAURORA, 100Ω termination, 100Ω differential transmission line delay, matched network | -             |
| VCM_AURORA              | Transmitter Common mode voltage                                                                | 0.775 | -     | 1.025 | V          | -                                                                                         | -             |
| VCM_LVDS_RX             | Receiver input signal common mode range                                                        | 0.6   | -     | 1.0   | V          | -                                                                                         | -             |
| VDIFF_LVDS_RX           | Receiver input differential signal                                                             | 400   | -     | -     | mV         | -                                                                                         | -             |
| CLOAD_AURORA            | Maximum transmission line load ( Lumped Load at any point on Tline )                           | -     | -     | 0.1   | pF         | -                                                                                         | -             |
| RTERM_AURORA            | Internal termination resistance                                                                | 80    | 100   | 130   | Ohm        | enabled                                                                                   | -             |
| VSLEW_AURORA            | Differential output slew rate                                                                  | -     | 30    | 50    | ps / 200mV | max fAURORA                                                                               | -             |
| TSTARTUP_ AURORA        | Transmitter startup time (assertion of ipp_obe to common mode settling of differential output) | -     | -     | 500   | ns         | -                                                                                         | -             |
| TEYE_AURORA             | Valid data region ( Including PLL Jitter for Aurora ) [5]                                      | 0.55  | -     | -     | UI         | max fAURORA                                                                               | -             |

Table continues on the next page...

Table 13. Aurora Pads...continued

| Symbol     | Description                                 | Min             | Typ   | Max             | Unit   | Condition                        | Spec Number   |
|------------|---------------------------------------------|-----------------|-------|-----------------|--------|----------------------------------|---------------|
| VOH_AURORA | Transmitter output high indicator [6]       | VDD_IO/ 2 + 0.2 | -     | -               | V      | 100Ω termination at receiver end | -             |
| VOL_AURORA | Transmitter output low indicator [6]        | -               | -     | VDD_IO/ 2 - 0.2 | V      | 100Ω termination at receiver end | -             |
| PAD_P_BIAS | Pad_p voltage output level when Tx disabled | -               | -     | 0.6             | V      | Ipp_obe_lv=0 Ipp_ term_en_lv=0   | -             |
| PAD_N_BIAS | Pad_n voltage output level when Tx disabled | 1.1             | -     | -               | V      | Ipp_obe_lv=0 Ipp_ term_en_lv=0   | -             |

- [1] Differential output is with pre-emphasis disabled, and a 10mA output stage current.
- [3] When  operating at max speed, there will be losses and differential output will be smaller as against DC condition. Aurora Interface Min differential swing is 400mV which is always guaranteed but the max limit is dependent on board design/losses. For boards with negligible losses , if differential output (P-N) goes higher than 800mV (Aurora max differential input spec) , user must use 'dual termination' scheme as highlighted in the Source Termination Circuit Figure to get the differential swing back within Range. The termination in the source side can be enabled through software in the transmitter pad design. Direct end termination without AC coupling is not allowed.
- [2] Termination scheme as shown in the End Termination Circuit Figure.  Direct end termination without AC coupling is not allowed.
- [4] Differential output is with pre-emphasis enabled, and a ~15mA avg output stage current
- [6] VDD\_IO maps to corresponding supply name on the device.
- [5] UI @ 5Gbps equals 200ps. The valid eye is expected to be &gt; 110ps in width. ISI jitter spec is 20-30ps for the LVDS transmitter across PVT in a delay matched differential transmission line impedance of 100Ω.

Termination scheme as shown in 'End Termination Circuit' applies to debug tool hardware and is not recommended to be placed on the PC.

Source termination Circuit - Transmitter side 100 ohm termination is present inside the Tx pad and should not be placed on the PCB.

Direct 100 ohm board termination not allowed between AUR\_TXn\_N and AUR\_TXn\_N (n=0,1,2,3). Source termination is only allowed through the internal termination inside LVDS Tx pad.

Figure 12. Source Termination Circuit

<!-- image -->

<!-- image -->

## 13.2 Aurora Port Timing

The following table gives the Aurora Port interface timing specifications for the device.

Figure 11. End Termination Circuit

S32G3 Data Sheet

Table 14. Aurora Port Timing

| Symbol   | Description                        | Min   | Typ   | Max    | Unit   | Condition                      | Spec Number   |
|----------|------------------------------------|-------|-------|--------|--------|--------------------------------|---------------|
| BER      | Bit Error Rate                     | -     | -     | 10e-12 | -      | -                              | -             |
| JD       | Transmit line deterministic jitter | -     | -     | 0.17   | OUI    | data rate <=3.0 Gbps           | -             |
| JD       | Transmit line deterministic jitter | -     | -     | 0.25   | OUI    | 3.0Gbps < data rate <= 5.0Gbps | -             |
| JT       | Transmit line total jitter         | -     | -     | 0.35   | OUI    | data rate <= 3.0 Gbps          | 2             |
| JT       | Transmit line total jitter         | -     | -     | 0.45   | OUI    | 3.0Gbps < data rate <= 5.0Gbps | 2             |
| SO       | Differential output skew           | -     | -     | 20     | ps     | -                              | 3             |
| SMO      | Lane to lane output skew           | -     | -     | 1000   | ps     | -                              | 4             |
| OUI      | Aurora lane unit interval [1][2]   | -     | 500   | -      | ps     | 2.0 Gbps                       | 5             |
| OUI      | Aurora lane unit interval [1][2]   | -     | 400   | -      | ps     | 2.5 Gbps                       | 5             |
| OUI      | Aurora lane unit interval [1][2]   | -     | 333   | -      | ps     | 3.0 Gbps                       | 5             |
| OUI      | Aurora lane unit interval [1][2]   | -     | 294   | -      | ps     | 3.4 Gbps                       | 5             |
| OUI      | Aurora lane unit interval [1][2]   | -     | 250   | -      | ps     | 4.0 Gbps                       | 5             |
| OUI      | Aurora lane unit interval [1][2]   | -     | 200   | -      | ps     | 5.0 Gbps                       | 5             |

S32G3 Data Sheet

<!-- image -->

## 13.3 Aurora PLL

The following table gives the operating frequencies and characteristics of the Aurora PLL. The operating frequencies correspond to the supported Aurora data trace lane speed. The Aurora PLL works from an external 100MHz input reference clock, and achieves a maximum output frequency of 5GHz.

Table 15. Aurora PLL

| Symbol         | Description                                          | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------------|------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| fPLL_CLKIN     | Aurora PLL Input Reference Clock Frequency [1][2][3] | -     | 100   | -     | MHz    | -           | -             |
| fPLL_CLKIN_PFD | Aurora PLL Phase Detector Clock Frequency [4]        | -     | 100   | -     | MHz    | -           | -             |
| ΔfPLL_CLKIN    | Aurora PLL Input Reference Clock Duty Cycle [1]      | 40    | -     | 60    | %      | -           | -             |

Table continues on the next page...

Table 15. Aurora PLL...continued

| Symbol       | Description                                   | Min   | Typ   |   Max | Unit   | Condition                                                         | Spec Number   |
|--------------|-----------------------------------------------|-------|-------|-------|--------|-------------------------------------------------------------------|---------------|
| JRCDC        | Reference clock period jitter                 | -     | -     |     5 | ps     | RMS, 0.5MHz - 20MHz                                               | -             |
| fPLL_VCO     | Aurora PLL VCO Frequency Range                | 3000  | -     |  5000 | MHz    | -                                                                 | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range [5] | -     | -     |  5000 | MHz    | 5.0Gbps Aurora lane data rate, VCO frequency divided by 1         | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range [5] | -     | -     |  4000 | MHz    | 4.0Gbps Aurora lane data rate, VCO frequency divided by 1         | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range [5] | -     | -     |  3400 | MHz    | 3.4Gbps Aurora lane data rate, VCO frequency divided by 1         | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range [5] | -     | -     |  3000 | MHz    | 3.0Gbps Aurora lane data rate, VCO frequency divided by 1         | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range [5] | -     | -     |  2500 | MHz    | 2.5Gbps Aurora lane data rate, VCO frequency divided by 2.        | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range [5] | -     | -     |  2000 | MHz    | 2.0Gbps Aurora lane data rate, VCO frequency divided by 2.        | -             |
| fPLL_CLKOUT0 | Aurora PLL Output Clock 0 Frequency Range     | -     | -     |   500 | MHz    | No tool connected - trace logic clock with FXOSC reference clock. | -             |
| tLOCK        | Aurora PLL Lock Time                          | -     | -     |   150 | us     | -                                                                 | -             |
| PER_jitter   | Aurora PLL Period Jitter                      | -21   | -     |    21 | ps     | fPLL_CLKIN = 100MHz, VCO = 5GHz, fPLL_CLKOUT = 5GHz, 6-sigma      | -             |
| LT_jitter    | Aurora PLL Long Term Jitter                   | -120  | -     |   120 | ps     | Saturated, 6-sigma                                                | -             |

S32G3 Data Sheet

## 14 Power Management Controller (PMC)

## 14.1 PMC Bandgap

## Table 16. PMC Bandgap

| Symbol     | Description                                                         |   Min |   Typ |   Max | Unit   | Condition                           | Spec Number   |
|------------|---------------------------------------------------------------------|-------|-------|-------|--------|-------------------------------------|---------------|
| VBG_SCALED | Scaled version of bandgap reference voltage measured by SAR ADC [1] | 1.127 |  1.15 | 1.173 | V      | Both bandgap and buffer are trimmed | -             |

## 15 Reset

## 15.1 Reset Duration

The durations specified "Reset Duration" table and the corresponding figures refer to standard reset sequences. A reset sequence is no longer standard when it is interrupted by another power-on or destructive reset event, in which case the reset sequence restarts from the beginning of the reset sequence corresponding to that event, and the total duration is the time already spent in reset plus the duration of the new sequence.

The diagrams in this section are not to scale.

Table 17. Reset Duration

| Symbol   | Description                         | Min   | Typ   |   Max | Unit   | Condition                                        | Spec Number   |
|----------|-------------------------------------|-------|-------|-------|--------|--------------------------------------------------|---------------|
| TFR      | Functional Reset Sequence Duration  | -     | -     |   545 | us     | FIRC_CLK, trimmed                                | -             |
| TDR      | Destructive Reset Sequence Duration | -     | -     |  1370 | us     | FIRC_CLK, trimmed during destructive reset phase | -             |
| POR      | Power On Reset Sequence Duration    | -     | -     |  1500 | us     | FIRC_CLK, trimmed during destructive reset phase | -             |

<!-- image -->

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

<!-- image -->

S32G3 Data Sheet

Figure 22. Reset\_b pad detailed behavior during power down

<!-- image -->

## 15.2 Reset and Standby related pad electrical characteristics

The following table gives the characteristics of the POR\_B, RESET\_B, PMIC\_STBY\_MODE\_B, and PMIC\_VDD\_OK pads. Values not explicitly listed in this table can be found in the 'GPIO Pads' section.

Table 18. Reset and Standby related pad electrical characteristics

| Symbol        | Description                                   | Min    | Typ   | Max   | Unit   | Condition                                       | Spec Number   |
|---------------|-----------------------------------------------|--------|-------|-------|--------|-------------------------------------------------|---------------|
| ISLEW_POR_B   | POR_B slew rate                               | 30e-06 | -     | 4     | V/ns   | -                                               | -             |
| ISLEW_RESET_B | RESET_B slew rate [1]                         | 30e-06 | -     | 4     | V/ns   | Noise on RESET_B <100mV peak-peak.              | -             |
| VISE_RESET_B  | RESET_B pad indeterminate state end threshold | -      | 2.35  | -     | V      | See RESET_B pad detailed behavior diagram below | -             |
| VRSE_RESET_B  | RESET_B pad ramp- up state end threshold      | -      | 460   | -     | mV     | See RESET_B pad detailed behavior diagram below | -             |
| WF_RESET_B    | RESET_B input filtered pulse                  | -      | -     | 17    | ns     | -                                               | -             |

Table continues on the next page...

Table 18. Reset and Standby related pad electrical characteristics...continued

| Symbol           | Description                      |   Min | Typ   | Max   | Unit   | Condition                 | Spec Number   |
|------------------|----------------------------------|-------|-------|-------|--------|---------------------------|---------------|
| WNF_RESET_B      | RESET_B input not filtered pulse |   400 | -     | -     | ns     | -                         | -             |
| MLP_POR_B        | POR_B minimum low pulse          |     5 | -     | -     | µs     | -                         | -             |
| MLP_PMIC_VDD_ OK | PMIC_VDD_OK minimum low pulse    |    36 | -     | -     | us     | during Standby mode entry | -             |
| MHP_PMIC_VDD_ OK | PMIC_VDD_OK minimum high pulse   |    36 | -     | -     | µs     | during Standby mode exit  | -             |

<!-- image -->

The RESET\_B pad behavior described in the diagram and the related VRSE\_RESET\_B parameter spec also apply to the case of core VDD droop after power-up.

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

During SoC power-up, the PMIC asserts the POR\_B input before the SoC supplies are turned on and kept asserted until all SoC supplies have reached their operational levels (i.e., all the corresponding voltage monitors in the PMIC have been satisfied) and any required PMIC BIST has completed. See the 'Power Sequencing' section for details.

The PMIC asserts the POR\_B input whenever one of its voltage detectors detects an SoC supply's voltage is outside its operational range (i.e., a corresponding PMIC LVD or HVD event occurs).

## 15.3 PMIC Standby Mode Entry / Exit Protocol

The PMIC\_STBY\_MODE\_B output is:

1. asserted by the SoC when the power domains that are not needed during Standby mode are to be turned off
2. deasserted by the SoC when the power domains that are not needed during Standby mode are to be turned on The PMIC\_VDD\_OK input is:
1. deasserted by the PMIC when the power domains that are not needed during Standby mode have been turned off
2. asserted by the PMIC when the power domains that are not needed during Standby mode have been turned on and have reached their operational levels (e.g., all the corresponding voltage monitors in the PMIC have been satisfied) and any required PMIC BIST has completed. See the 'Power Sequencing' section for any exceptions.

This implies that the PMIC\_VDD\_OK input is asserted and deasserted together with the POR\_B input during non-Standby modes. Deasserting PMIC\_VDD\_OK during non-Standby modes while not also asserting POR\_B  will cause the SoC to start a power-on reset sequence.

S32G3 Data Sheet

<!-- image -->

<!-- image -->

Figure 26. Standby Mode Aborted by SoC POR Event Prior to PMIC\_VDD\_OK Deassertion

<!-- image -->

S32G3 Data Sheet

<!-- image -->

## 16 Peripheral specifications

## 16.1 Analog Modules

## 16.1.1 SAR ADC

ADC performance specifications are only guaranteed when the injection current limits in the operating conditions table of this electrical specification are met.

Although functionally supported on devices with 2 ADCs, ADC performance specifications are not guaranteed for shared channels between the 2 ADCs if the input channel is sampled or converted simultaneously by both ADCs. For best performance in this case, the external capacitance at the input pin and reference pin should be maximized.

## Table 19. SAR ADC

| Symbol    | Description                              | Min      | Typ   | Max      | Unit   | Condition                                 | Spec Number   |
|-----------|------------------------------------------|----------|-------|----------|--------|-------------------------------------------|---------------|
| VAD_INPUT | ADC Input Voltage [1]                    | VSS_AD C | -     | VDD_AD C | V      | on or off channels                        | -             |
| fAD_CK    | ADC Clock Frequency                      | 20       | -     | 80       | MHz    | -                                         | -             |
| tSAMPLE   | ADC Input Sampling Time [2]              | 275      | -     | -        | ns     | -                                         | -             |
| tCONV     | ADC Total Conversion Time [3]            | 1        | -     | -        | us     | -                                         | -             |
| tRECOVERY | ADC Initialization Time from power- down | -        | -     | 1        | us     | -                                         | -             |
| CAD_INPUT | ADC Input Capacitance                    | -        | -     | 7        | pF     | ADC component plus pad capacitance (~2pF) | -             |
| RAD_INPUT | ADC Input Series Resistance              | -        | -     | 1.25     | kΩ     | -                                         | -             |
| OFS       | ADC Offset Error [4]                     | -6       | -     | 6        | LSB    | after calibration                         | -             |

Table continues on the next page...

Table 19. SAR ADC...continued

| Symbol   | Description                              | Min   | Typ   | Max   | Unit   | Condition                                                         | Spec Number   |
|----------|------------------------------------------|-------|-------|-------|--------|-------------------------------------------------------------------|---------------|
| GNE      | ADC Gain Error (full scale) [4]          | -6    | -     | 6     | LSB    | after calibration                                                 | -             |
| DNL      | ADC Differential Non-linearity [4][5][6] | -1    | -     | 2     | LSB    | after calibration                                                 | -             |
| INL      | ADC Integral Non- linearity [4][5]       | -3    | -     | 3     | LSB    | after calibration                                                 | -             |
| TUE      | ADC Total Unadjusted Error [4] [5]       | -8    | -     | 8     | LSB    | after calibration                                                 | -             |
| SNR      | Signal-to-Noise Ratio [4]                | -     | 65    | -     | dBFS   | input signal frequency <= 50KHz                                   | -             |
| THD      | Total Harmonic Distortion [4]            | -     | 72    | -     | dBFS   | Input signal frequency <= 50KHz.                                  | -             |
| IAD_LKG  | ADC Input Leakage Current [7]            | -1    | -     | 1     | uA     | TJ = 125C, Dedicated input channel, channel selection switch open | -             |
| IAD_LKG  | ADC Input Leakage Current [7]            | -2    | -     | 2     | uA     | TJ = 125C, Shared channel, channel selection switch open          | -             |
| CP1      | ADC input pin capacitance 1              | -     | -     | 4     | pF     | -                                                                 | -             |
| CP2      | ADC input pin capacitance 2              | -     | -     | 0.5   | pF     | -                                                                 | -             |
| CS       | ADC input sampling capacitance           | -     | -     | 4     | pF     | -                                                                 | -             |
| RSW1     | Internal resistance of analog source     | -     | -     | 600   | ohm    | -                                                                 | -             |
| RAD      | Internal resistance of analog source     | -     | -     | 150   | ohm    | -                                                                 | -             |

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

<!-- image -->

## 16.1.2 Temperature Monitoring Unit (TMU)

The table below gives the specification for the Temperature Monitoring Unit (TMU). Specifications apply to all remote temperature sensors connected to the TMU on the device.

## Table 20. Temperature Monitoring Unit (TMU)

| Symbol   | Description                      |   Min | Typ   |   Max | Unit   | Condition             | Spec Number   |
|----------|----------------------------------|-------|-------|-------|--------|-----------------------|---------------|
| TRANGE   | Temperature monitoring range [1] |   -45 | -     |   130 | C      | -                     | -             |
| TERR     | Temperature sensor error         |    -8 | -     |     8 | C      | TRANGE = -40C to 84C  | -             |
| TERR     | Temperature sensor error         |    -5 | -     |     5 | C      | TRANGE = 85C to 110C  | -             |
| TERR     | Temperature sensor error         |    -3 | -     |     3 | C      | TRANGE = 111C to 125C | -             |

## 16.1.3 Glitch Filter

## Table 21. Glitch Filter

| Symbol   | Description                                           | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| TFILT    | Glitch filter max filtered pulse width [1][2][3][4]   | -     | -     | 17    | ns     | -           | -             |
| TUNFILT  | Glitch filter min unfiltered pulse width [1][3][4][5] | 400   | -     | -     | ns     | -           | -             |

## 16.1.4 IRQ

The following table gives the input specifications for the external interrupt pins.

tCYC refers to FIRC\_CLK.

## Table 22. IRQ

| Symbol   | Description          |   Min | Typ   | Max   | Unit   | Condition   |   Spec Number |
|----------|----------------------|-------|-------|-------|--------|-------------|---------------|
| tIPWL    | IRQ pulse width low  |     4 | -     | -     | tCYC   | MAXCNT = 3  |             1 |
| tIPWH    | IRQ pulse width high |     4 | -     | -     | tCYC   | MAXCNT = 3  |             2 |

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

## 16.2 Clock and PLL Interfaces

## 16.2.1 DFS

The following table specifies the output frequency ranges and characteristics of the Digital Frequency Synthesizer (DFS).

## Table 23. DFS

| Symbol         | Description                             |   Min | Typ   |   Max | Unit   | Condition                      | Spec Number   |
|----------------|-----------------------------------------|-------|-------|-------|--------|--------------------------------|---------------|
| fDFS_CORE_CLK1 | Core DFS Output Clock 1 Frequency       |    40 | -     |   800 | MHz    | CORE_DFS1                      | -             |
| fDFS_PER_CLK1  | Peripheral DFS Output Clock 1 Frequency |   532 | -     |   800 | MHz    | PERIPH_DFS1                    | -             |
| fDFS_PER_CLK2  | Peripheral DFS Output Clock 2 Frequency |    40 | -     |   628 | MHz    | PERIPH_DFS2                    | -             |
| fDFS_PER_CLK3  | Peripheral DFS Output Clock 3 Frequency |   416 | -     |   800 | MHz    | PERIPH_DFS3                    | -             |
| fDFS_CLKIN     | DFS Input Clock Frequency               |  1300 | -     |  2622 | MHz    | -                              | -             |
| PER_jitter     | DFS Period Jitter [1] [2]               |   -30 | -     |    30 | ps     | Even MFN                       | -             |
| PER_jitter     | DFS Period Jitter [1] [2]               |   -45 | -     |    45 | ps     | fDFS_CLKIN = 2000 MHz, Odd MFN | -             |
| PER_Jitter     | DFS Period Jitter [1] [2]               |   -30 | -     |    30 | ps     | fDFS_CLKIN = 2622 MHz, Odd MFN | -             |
| PER_jitter     | DFS Period Jitter [1] [2]               |   -60 | -     |    60 | ps     | fDFS_CLKIN = 1300 MHz, Odd MFN | -             |

Peripheral DFS output clock min jitter=Min(PER\_jitter(PLL))*(sqrt(N))+Min(PER\_jitter(DFS)). Peripheral DFS output clock max jitter=Max(PER\_jitter(PLL))*(sqrt(N)) +Max(PER\_jitter(DFS)). Where N is the DFS division factor. All jitter numbers are in ps.

## 16.2.2 FIRC

## Table 24. FIRC

| Symbol   | Description                  | Min   | Typ   | Max   | Unit   | Condition                        | Spec Number   |
|----------|------------------------------|-------|-------|-------|--------|----------------------------------|---------------|
| fFIRC    | FIRC Target Frequency        | -     | 48    | -     | MHz    | -                                | -             |
| ðfVAR    | FIRC Frequency Variation [1] | -5    | -     | 5     | %      | Trimmed                          | -             |
| TSTART   | Startup Time                 | -     | 10    | 20    | us     | After valid supply level reached | -             |

## 16.2.3 SIRC

## Table 25. SIRC

| Symbol   | Description                   | Min   | Typ   | Max   | Unit   | Condition                                                                | Spec Number   |
|----------|-------------------------------|-------|-------|-------|--------|--------------------------------------------------------------------------|---------------|
| fSIRC    | SIRC Target Frequency Trimmed | -     | 32    | -     | KHz    | Trimmed                                                                  | -             |
| PTA      | SIRC Trimming Resolution [1]  | -1    | -     | 1     | %      | Trimmed 32KHz, 25C, 0.8V Core                                            | -             |
| ðfVAR    | SIRC Frequency Variation [2]  | -5    | -     | 5     | %      | Frequency variation across voltage and temperature range after trimming. | -             |
| TSTART   | SIRC Startup Time             | -     | -     | 50    | us     | -                                                                        | -             |

## 16.2.4 FXOSC

## Table 26. FXOSC

| Symbol    | Description                  | Min          | Typ   | Max        | Unit   | Condition                                                                | Spec Number   |
|-----------|------------------------------|--------------|-------|------------|--------|--------------------------------------------------------------------------|---------------|
| fXTAL     | Input Frequency Range [1][2] | 20           | -     | 40         | MHz    | Crystal mode                                                             | -             |
| TCST      | Crystal Startup Time         | -            | -     | 2          | ms     | Crystal mode - time to stable duty cycle when EOCV is set to 1 ms period | -             |
| fBYP_SE   | FXOSC Bypass Frequency [3]   | -            | 40    | -          | MHz    | Single-ended bypass mode                                                 | -             |
| VIH_EXTAL | EXTAL Input High Level [4]   | VCM_SE + 0.3 | -     | VDD_FX OSC | V      | Single-ended bypass mode                                                 | -             |

Table continues on the next page...

S32G3 Data Sheet

Table 26. FXOSC...continued

| Symbol            | Description                                  | Min   | Typ            | Max          | Unit   | Condition                                              | Spec Number   |
|-------------------|----------------------------------------------|-------|----------------|--------------|--------|--------------------------------------------------------|---------------|
| VIL_EXTAL         | EXTAL Input Low Level [4]                    | 0     | -              | VCM_SE - 0.3 | V      | Single-ended bypass mode                               | -             |
| ΔfXTAL_CLK        | Input Clock Duty Cycle                       | 47.5  | -              | 52.5         | %      | Bypass mode                                            | -             |
| CLOAD             | XTAL/EXTAL pin load capacitance [5]          | -     | 8              | -            | pF     | Crystal mode                                           | -             |
| CS_XTAL           | XTAL/EXTAL pin on-chip stray capacitance [5] | -     | -              | 3            | pF     | -                                                      | -             |
| VCM_SE            | Common Mode Voltage for Single ended Bypass  | -     | VDD_FX OSC / 2 | -            | mV     | -                                                      | -             |
| Leakage_injection | EXTAL injection current                      | -50   | -              | 100          | nA     | Mean current flowing into EXTAL in crystal mode        | -             |
| Leakage_extal     | External Leakage on EXTAL Pin                | -20   | -              | 20           | nA     | Bypass mode, 0.5V                                      | -             |
| EXTAL_AMP         | EXTAL_amplitude (p k-pk)                     | 300   | -              | 900          | mV     | Crystal mode                                           | -             |
| LT_Jitter         | Long term jitter                             | -120  | -              | 120          | ps     | gm_sel=1111 with 40MHz crystal (NX5032GA and NX3225GA) | -             |

In crystal mode NX5032GA crystal at 20 MHz has a load cap of 8 pF and configure gm\_sel[3:0]=4'b0100 and NX3225GA crystal has a load cap of 8 pF and configure gm\_sel[3:0]=4'b100.

In crystal mode NX5032GA crystal at 24 MHz has a load cap of 8 pF and configure gm\_sel[3:0]=4'b0101 and NX3225GA has a load cap of 8 pF and configure gm\_sel[3:0]=4'b0110.

In crystal mode NX5032GA and NX3225GA crystal at 40 MHz (ALC enable) has a load cap of 8 pF and configure gm\_sel[3:0]=4'b1111.

In ALC disable mode the minimum crystal drive level should be greater than 500uW.

Duty cycle of the FXOSC clock when output on either the single-ended or LVDS CLKOUT pins is given in the I/O pad specifications.

See Hardware design guide for the recommended circuit for each mode.

RGMII specifications require clock source to have tolerance of +/- 50ppm. When using this mode, the crystal selected for system clock (FXOSC) should adhere to this specification.

S32G3 Data Sheet

## 16.2.5 PLL

The following table gives the operating frequencies and characteristics of the PLL, and applies to all instances on the device. Actual operating frequencies for the device are constrained to the values given below.

PLL refers to the Core, Peripheral, Accelerator, and DDR reference PLLs on the device.

Spread spectrum clock modulation is only available on the Core, Accelerator and DDR reference PLLs.

Table 27. PLL

| Symbol          | Description                                | Min   | Typ   |   Max | Unit   | Condition                                         | Spec Number   |
|-----------------|--------------------------------------------|-------|-------|-------|--------|---------------------------------------------------|---------------|
| fPLL_CLKIN      | PLL Input Clock Frequency [1]              | 20    | -     |   100 | MHz    | Before PLL input divider.                         | -             |
| fPLL_CLKIN_PFD  | PLL Phase Detector Clock Frequency [2]     | 20    | -     |    40 | MHz    | After PLL input divider.                          | -             |
| fPLL_CORE_VCO   | Core PLL VCO Frequency Range [3] [4][5][6] | 1300  | -     |  2800 | MHz    | without center-spread SSCG enabled                | -             |
| fPLL_CORE_PHI0  | Core PLL PHI0 Frequency [5]                | -     | -     |  1400 | MHz    | CORE_PLL_PHI0, without center-spread SSCG enabled | -             |
| fPLL_PER_VCO    | Peripheral PLL VCO Frequency Range         | 1300  | -     |  2000 | MHz    | -                                                 | -             |
| fPLL_PER_PHI0   | Peripheral PLL PHI0 Frequency              | 100   | -     |   125 | MHz    | PERIPH_PLL_PHI0                                   | -             |
| fPLL_PER_PHI1   | Peripheral PLL PHI1 Frequency              | -     | -     |    80 | MHz    | PERIPH_PLL_PHI1                                   | -             |
| fPLL_PER_PHI2   | Peripheral PLL PHI2 Frequency              | 40    | -     |    80 | MHz    | PERIPH_PLL_PHI2                                   | -             |
| fPLL_PER_PHI3   | Peripheral PLL PHI3 Frequency              | -     | -     |   133 | MHz    | PERIPH_PLL_PHI3                                   | -             |
| fPLL_PER_PHI4   | Peripheral PLL PHI4 Frequency              | -     | -     |   200 | MHz    | PERIPH_PLL_PHI4                                   | -             |
| fPLL_PER_PHI5   | Peripheral PLL PHI5 Frequency              | -     | -     |   125 | MHz    | PERIPH_PLL_PHI5                                   | -             |
| fPLL_PER_PHI7   | Peripheral PLL PHI7 Frequency              | -     | -     |   100 | MHz    | PERIPH_PLL_PHI7                                   | -             |
| fPLL_ACCEL_VCO  | Accelerator PLL VCO Frequency Range [5][6] | 1300  | -     |  2400 | MHz    | without center-spread SSCG enabled                | -             |
| fPLL_ACCEL_PHI1 | Accelerator PLL PHI1 Frequency [5]         | -     | -     |   600 | MHz    | ACCEL_PHI1, without center-spread SSCG enabled    | -             |

Table continues on the next page...

S32G3 Data Sheet

## Table 27. PLL...continued

| Symbol        | Description                                    | Min   | Typ   |    Max | Unit   | Condition                                                            | Spec Number   |
|---------------|------------------------------------------------|-------|-------|--------|--------|----------------------------------------------------------------------|---------------|
| fPLL_DDR_VCO  | DDR PLL VCO Frequency Range [5] [6][7]         | 1300  | -     | 1600   | MHz    | without center-spread SSCG enabled                                   | -             |
| fPLL_DDR_PHI0 | DDR PLL PHI0 Frequency [5][8]                  | 800   | -     |  800   | MHz    | DDR_CLK (3200 MT/s), without center- spread SSCG enabled             | -             |
| fPLL_DDR_PHI0 | DDR PLL PHI0 Frequency [8]                     | 758   | -     |  758   | MHz    | DDR_CLK (3032 MT/s)                                                  | -             |
| fPLL_DDR_PHI0 | DDR PLL PHI0 Frequency [8]                     | 666.5 | -     |  666.5 | MHz    | DDR_CLK (2666 MT/s)                                                  | -             |
| fPLL_DDR_PHI0 | DDR PLL PHI0 Frequency [8]                     | 533.3 | -     |  533.3 | MHz    | DDR_CLK (2133 MT/s)                                                  | -             |
| fPLL_DDR_PHI0 | DDR PLL PHI0 Frequency [8]                     | 466.6 | -     |  466.6 | MHz    | DDR_CLK (1866 MT/s)                                                  | -             |
| fPLL_DDR_PHI0 | DDR PLL PHI0 Frequency [8]                     | 400   | -     |  400   | MHz    | DDR_CLK (1600 MT/s)                                                  | -             |
| tLOCK         | PLL Lock Time                                  | -     | -     |  100   | us     | -                                                                    | -             |
| PER_jitter    | PLL Period Jitter [9] [10][11][12]             | -23   | -     |   23   | ps     | fPLL_CLKIN = 40MHz, fVCO = 2GHz, 6- sigma, SSCG & Frac mode disabled | -             |
| LT_jitter     | PLL Long Term Jitter [11][12][13]              | -120  | -     |  120   | ps     | Saturated, 6-sigma                                                   | -             |
| fPLL_MOD      | Spread Spectrum Clock Modulation Frequency [7] | 30    | -     |   64   | KHz    | -                                                                    | -             |

- [1] This refers to spec number 1 which is shown in the figure in Aurora port specifications
- [3] Duty cycle of the PLL clock when output on an external pin is given in the I/O pad specifications.
- [2] This specification is PLL input reference clock frequency after pre-divider.
- [4] The frequencies are the nominal frequencies (i.e., what the PLL's VCO is configured to).
- [6] Same min frequency value applies for center-spread SSCG enabled as provided for center-spread SSCG disabled.
- [5] The max frequency in case of center-spread SSCG enabled for a modulation depth can be calculated as: Max frequency(with center-spread SSCG disabled) - (Modulation Depth(in %)/(2*100))* Max frequency (with center-spread SSCG disabled). For details, see section 'Frequency modulation programming' in reference manual.
- [7] DDR PLL allows center-spread SSCG at fPLL\_MOD 32KHz @2% MD (modulation depth) and fPLL\_MOD 64KHz @ 1% MD
- [9] Jitter is dependent on the period of the PLL output clock, and the division ratio of the clock at the destination module.
- [8] The DDR PHY internally multiplies the PLL\_DDR\_PHI0 by factor of two.
- [10] For chip clocks that are further divided down from the PLL output clock, the jitter is multiplied by a factor of SQRT(N), where N is the ratio of the PLL output clock and destination clock periods.
- [12] Jitter is dependent on supply noise. Specified jitter values are valid for the FXOSC reference clock input only - not valid for FIRC reference clock input.
- [11] Jitter value does not apply when a PLL clock is output on an external pin. In this case, the rise and fall time variations in the I/O pad are orders of magnitude more than the PLL and SoC mux jitter contributions.

[13] This specification is valid when all clock sources are stable.

Note: fPLL\_DDR\_PHI0 frequencies and data rate mentioned in this table are for LPDDR4. DDR3L frequencies and data rates are half of the LPDDR4.

S32G3 Data Sheet

## 16.3 Communication modules

## 16.3.1 SPI

SRE[2:0]=101 is the required drive setting to meet the timing.

Table 28. SPI

| Symbol   | Description                  | Min                            | Typ   | Max   | Unit   | Condition                            |   Spec Number |
|----------|------------------------------|--------------------------------|-------|-------|--------|--------------------------------------|---------------|
| tSCK     | SPI cycle time [1][2]        | 40                             | -     | 10000 | ns     | Master, MTFE=0                       |             1 |
| tSCK     | SPI cycle time [2]           | 25                             | -     | 10000 | ns     | Master, MTFE=1                       |             1 |
| tSCK     | SPI cycle time [2][3]        | 16.67                          | -     | 10000 | ns     | Slave Receive Mode                   |             1 |
| tSCK     | SPI cycle time [2]           | 40                             | -     | 10000 | ns     | Slave Transmit Mode                  |             1 |
| tCSC     | PCS to SCK delay [4]         | 20                             | -     | 10000 | ns     | -                                    |             2 |
| tASC     | After SCK delay [5]          | 20                             | -     | 10000 | ns     | -                                    |             3 |
| tSDC     | SCK duty cycle               | 40                             | -     | 60    | %      | -                                    |             4 |
| tA       | Slave access time            | -                              | -     | 40    | ns     | SS active to SOUT valid              |             5 |
| tDIS     | Slave SOUT disable time      | -                              | -     | 15    | ns     | SS inactive to SOUT hi-z or invalid  |             6 |
| tPCSC    | PCSx to PCSS time            | 13                             | -     | -     | ns     | -                                    |             7 |
| tPASC    | PCSS to PCSx time            | 13                             | -     | -     | ns     | -                                    |             8 |
| tSUI     | Input data setup time [6][7] | 15                             | -     | -     | ns     | Master, MTFE=0                       |             9 |
| tSUI     | Input data setup time [7][8] | 15 - N * ipg_clk_d spi_perio d | -     | -     | ns     | Master, MTFE=1, CPHA=0, SMPL_PTR = 1 |             9 |
| tSUI     | Input data setup time [7]    | 15                             | -     | -     | ns     | Master, MTFE=1, CPHA=1, SMPL_PTR = 1 |             9 |
| tSUI     | Input data setup time [7]    | 2                              | -     | -     | ns     | Slave Receive Mode                   |             9 |
| tHI      | Input data hold time [7]     | 0                              | -     | -     | ns     | Master, MTFE=0                       |            10 |
| tHI      | Input data hold time [7]     | 0 + N * ipg_clk_d spi_perio d  | -     | -     | ns     | Master, MTFE=1, CPHA=0, SMPL_PTR = 1 |            10 |
| tHI      | Input data hold time [7]     | 0                              | -     | -     | ns     | Master, MTFE=1, CPHA=1, SMPL_PTR = 1 |            10 |

Table continues on the next page...

S32G3 Data Sheet

## Table 28. SPI...continued

| Symbol   | Description                                    | Min                        | Typ   | Max                       | Unit   | Condition                                                    |   Spec Number |
|----------|------------------------------------------------|----------------------------|-------|---------------------------|--------|--------------------------------------------------------------|---------------|
| tHI      | Input data hold time [7]                       | 4                          | -     | -                         | ns     | Slave Receive Mode                                           |            10 |
| tSUO     | Output data valid time (after SCK edge) [9]    | -                          | -     | 5                         | ns     | Master, MTFE=0 max CLOAD=25pF, max pad drive setting         |            11 |
| tSUO     | Output data valid time (after SCK edge) [9]    | -                          | -     | 5 + ipg_clk_d spi_perio d | ns     | Master, MTFE=1, CPHA=0 max CLOAD=25pF, max pad drive setting |            11 |
| tSUO     | Output data valid time (after SCK edge) [9]    | -                          | -     | 5                         | ns     | Master, MTFE=1, CPHA=1 max CLOAD=25pF, max pad drive setting |            11 |
| tSUO     | Output data valid time (after SCK edge) [6][9] | -                          | -     | 16                        | ns     | Slave Transmit Mode                                          |            11 |
| tHO      | Output data hold time [9]                      | -2                         | -     | -                         | ns     | Master, MTFE=0 max CLOAD=25pF, max pad drive setting         |            12 |
| tHO      | Output data hold time [9]                      | -2 + ipg_clk_d spi_perio d | -     | -                         | ns     | Master, MTFE=1, CPHA=0 max CLOAD=25pF, max pad drive setting |            12 |
| tHO      | Output data hold time [9]                      | -2                         | -     | -                         | ns     | Master, MTFE=1, CPHA=1 max CLOAD=25pF, max pad drive setting |            12 |
| tHO      | Output data hold time [9]                      | 3                          | -     | -                         | ns     | Slave Transmit Mode                                          |            12 |

Slave mode timing values given below are applicable when device is in MTFE=0.

S32G3 Data Sheet

Figure 32. SPI Modified Transfer Format Timing - Master, CPHA = 1, MTFE=1

S32G3 Data Sheet

<!-- image -->

<!-- image -->

S32G3 Data Sheet

<!-- image -->

Figure 34. SPI Classic Timing - Slave CPHA = 1, MTFE=0

<!-- image -->

S32G3 Data Sheet

<!-- image -->

<!-- image -->

S32G3 Data Sheet

<!-- image -->

## 16.3.2 I2C

## 16.3.2.1 I2C Input

## Table 29. I2C Input

| Symbol   | Description                                                        | Min   | Typ   | Max   | Unit              | Condition                                               | Spec Number   |
|----------|--------------------------------------------------------------------|-------|-------|-------|-------------------|---------------------------------------------------------|---------------|
| Rate     | Operating Speed                                                    | -     | -     | 100   | kbps              | Standard Mode defined by the I2C protocol specification | -             |
| Rate     | Operating Speed                                                    | -     | -     | 400   | kbps              | Fast Mode defined by the I2C protocol specification     | -             |
| tIH_SC   | Input Start condition hold time [1][2]                             | 2     | -     | -     | MODULE _CLK cycle | -                                                       | 1             |
| tCL      | Input Clock low time [1][2]                                        | 8     | -     | -     | MODULE _CLK cycle | -                                                       | 2             |
| tIH      | Input Data hold time [1][2]                                        | 0     | -     | -     | ns                | SDA transitions after SCL falling edge                  | 4             |
| tCH      | Input Clock high time [1][2]                                       | 4     | -     | -     | MODULE _CLK cycle | -                                                       | 6             |
| tISU     | Input Data setup time (standard mode) [1][2][3]                    | 250   | -     | -     | ns                | SDA transitions before SCL rising edge                  | 7             |
| tISU_F   | Input Data setup time (fast mode) [1][2] [3]                       | 100   | -     | -     | ns                | SDA transitions before SCL rising edge                  | 7             |
| tISU_RSC | Input Start condition setup time (repeated start condition) [1][2] | 2     | -     | -     | MODULE _CLK cycle | -                                                       | 8             |
| tISU_SC  | Input Start condition setup time [1][2]                            | 2     | -     | -     | MODULE _CLK cycle | -                                                       | 9             |

S32G3 Data Sheet

I2C interface supports Fast Mode with a maximum data-rate of 400kbps. Higher data rates are not supported.

<!-- image -->

## 16.3.2.2 I2C Output

SRE[2:0]=110 is the required drive setting to meet the timing.

Programming IBFD (I2C bus Frequency Divider) with the maximum frequency results in the minimum output timings listed. The I2C interface is designed to scale the data transition time, moving it to the middle of the SCL low period. The actual position is affected by the prescale and division values programmed in IBFD.

Table 30. I2C Output

| Symbol   | Description                                       | Min   | Typ   | Max   | Unit              | Condition   | Spec Number   |
|----------|---------------------------------------------------|-------|-------|-------|-------------------|-------------|---------------|
| tOH_SC   | Output Start condition hold time [1][2]           | 6     | -     | -     | MODULE _CLK cycle | -           | 1             |
| tCL      | Output Clock low time [1][2]                      | 10    | -     | -     | MODULE _CLK cycle | -           | 2             |
| tRISE    | SDA/SCL rise time [1][2][3]                       | -     | -     | 300   | ns                | -           | -             |
| tOH      | Output Data hold time [1][2]                      | 7     | -     | -     | MODULE _CLK cycle | -           | 4             |
| tFALL    | SDA/SCL fall time [1] [2][3]                      | -     | -     | 100   | ns                | -           | 5             |
| tCH      | Output Clock high time [1][2]                     | 10    | -     | -     | MODULE _CLK cycle | -           | 6             |
| tOSU     | Output Data setup time [1][2]                     | 2     | -     | -     | MODULE _CLK cycle | -           | 7             |
| tOSU_RSC | Output repeated start condition setup time [1][2] | 20    | -     | -     | MODULE _CLK cycle | -           | 8             |
| tOSU_SC  | Output start condition setup time [1][2]          | 11    | -     | -     | MODULE _CLK cycle | -           | 9             |

- [1] MODULE\_CLK from the MC\_CGM is the clock driving the I2C block.
- [3] Because SCL and SDA are open-drain outputs, which the processor can only actively drive low, the time SCL or SDA takes to reach a high level depends on external signal capacitance and pullup resistor values

S32G3 Data Sheet

- [2] Timing valid for maximum external load CL = 400pF, at the maximum clock frequency defined by the I2C clock high and low time specifications.

<!-- image -->

## 16.3.4 LIN

SRE[2:0]=110 is the required drive setting to meet the timing.

## Table 31. LIN

| Symbol   | Description   | Min   | Typ   |   Max | Unit   | Condition   | Spec Number   |
|----------|---------------|-------|-------|-------|--------|-------------|---------------|
| RATE     | Bit Rate      | -     | -     |     2 | Mbps   | UART mode   | -             |
| RATE     | Bit Rate      | 4.8   | -     |    20 | Kbps   | LIN mode    | -             |

## 16.3.5 LPSPI

## Table 32. LPSPI

| Symbol   | Description                                     | Min              | Typ   | Max                  | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------------------|------------------|-------|----------------------|--------|-------------|---------------|
| fOP      | LPSPI operating frequency [1][2][3][4]          | fPER_CL K / 2048 | -     | 40                   | MHz    | Controller  | -             |
| fOP      | LPSPI operating frequency [1][2][5]             | -                | -     | 20                   | MHz    | Peripheral  | -             |
| tSPSCK   | SPSCK period [1][2][3] [4]                      | 25               | -     | 1 (fPER_C LK / 2048) | ns     | Controller  | -             |
| tSPSCK   | SPSCK period [1][2][5]                          | 50               | -     | -                    | ns     | Peripheral  | -             |
| tLEAD    | Enable lead time (PCS to SPSCK delay) [1][6][7] | tSPSCK - 3.5     | -     | -                    | ns     | Controller  | -             |
| tLEAD    | Enable lead time (PCS to SPSCK delay) [1][6]    | 25               | -     | -                    | ns     | Peripheral  | -             |

Table continues on the next page...

## Table 32. LPSPI...continued

| Symbol   | Description                                   | Min              | Typ   | Max              | Unit   | Condition                  | Spec Number   |
|----------|-----------------------------------------------|------------------|-------|------------------|--------|----------------------------|---------------|
| tLAG     | Enable lag time (after SPSCK delay) [1][8][9] | tSPSCK - 2.5     | -     | -                | ns     | Controller                 | -             |
| tLAG     | Enable lag time (after SPSCK delay) [1][8]    | 25               | -     | -                | ns     | Peripheral                 | -             |
| tSW      | Clock (SPSCK) high or low time (duty cycle)   | (tSPSCK / 2) - 3 | -     | (tSPSCK / 2) + 3 | ns     | Controller                 | -             |
| tSW      | Clock (SPSCK) high or low time (duty cycle)   | (tSPSCK / 2) - 3 | -     | (tSPSCK / 2) + 3 | ns     | Peripheral                 | -             |
| tSU      | Data setup time (inputs)                      | 12               | -     | -                | ns     | Controller                 | -             |
| tSU      | Data setup time (inputs)                      | 4                | -     | -                | ns     | Peripheral                 | -             |
| tHI      | Data hold time (inputs)                       | 0                | -     | -                | ns     | Controller                 | -             |
| tHI      | Data hold time (inputs)                       | 3                | -     | -                | ns     | Peripheral                 | -             |
| tA       | Peripheral access time                        | -                | -     | 12.5             | ns     | Peripheral                 | -             |
| tDIS     | Peripheral MISO disable time                  | -                | -     | 12.5             | ns     | Peripheral                 | -             |
| tV       | Data valid (after SPSCK edge) [1][10] [11]    | -                | -     | 6                | ns     | Controller, SRE[2:0] = 101 | -             |
| tV       | Data valid (after SPSCK edge) [1][10] [11]    | -                | -     | 20               | ns     | Peripheral, SRE[2:0] = 101 | -             |
| tHO      | Data hold time (outputs) [1][10][11]          | 0                | -     | -                | ns     | Controller, SRE[2:0] = 101 | 11            |
| tHO      | Data hold time (outputs) [1][10][11]          | 0                | -     | -                | ns     | Peripheral, SRE[2:0] = 101 | 11            |
| tRI_FI   | Rise / Fall time (input) [12]                 | -                | -     | 1                | ns     | Controller + Peripheral    | -             |

- [5] The maximum Peripheral mode LPSPI clock frequency can be no more than the peripheral clock frequency divided by 4.

[7] tPCSSCK = (PCSSCK+1) * (2**PRESCALE) * (1 / fPER\_CLK)

## S32G3

S32G3 Data Sheet

- [9] tSCKPCS = (SCKPCS+1) * (2**PRESCALE) * (1 / fPER\_CLK)

S32G3 Data Sheet

- [8] Set the SCKPCS configuration bit as 0, for a minimum of 1 delay cycle of LPSPI baud rate clock, where SCKPCS ranges from 0 to 255.
- [10] Timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50ohm, un-terminated, 5 inch microstrip trace on standard FR4 (1.5pF/inch), (25pF total with margin). For best signal integrity, the series resistance in the transmission line should be equal to the selected RDSON of the I/O pad output.
- [12] The input rise/fall time specification applies to both clock and data, and is required to guarantee related timing parameters.
- [11] Output rise/fall time is determined by the output load and GPIO pad drive strength setting. See the GPIO specifications for detail.

<!-- image -->

S32G3 Data Sheet

<!-- image -->

## 16.3.6 CAN

See GPIO pads for CAN specifications.

## 16.4 FlexRay

## 16.4.1 FlexRay - RxD

Table 33. FlexRay - RxD

| Symbol   | Description                                                                    | Min   | Typ   |   Max | Unit   | Condition   | Spec Number   |
|----------|--------------------------------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| C_CCRxD  | Input capacitance on RxD pin                                                   | -     | -     |     8 | pF     | -           | -             |
| dCCRxD01 | Sum of delay from actual input to the D input of the first FF, rising edge [1] | -     | -     |    10 | ns     | -           | -             |

Table continues on the next page...

## Table 33. FlexRay - RxD...continued

| Symbol             | Description                                                                     | Min   | Typ   |   Max | Unit   | Condition   | Spec Number   |
|--------------------|---------------------------------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| dCCRxD10           | Sum of delay from actual input to the D input of the first FF, falling edge [1] | -     | -     |    10 | ns     | -           | -             |
| dCCRxAsymAccept 15 | Acceptance of asymmetry at receiving CC with 15pF load [1]                      | -31.5 | -     |    44 | ns     | -           | -             |
| dCCRxAsymAccept 25 | Acceptance of asymmetry at receiving CC with 25pF load [1]                      | -30.5 | -     |    43 | ns     | -           | -             |

## 16.4.2 FlexRay - TxD

## Table 34. FlexRay - TxD

| Symbol                      | Description                                                                                | Min   | Typ   |   Max | Unit   | Condition                                                                  | Spec Number   |
|-----------------------------|--------------------------------------------------------------------------------------------|-------|-------|-------|--------|----------------------------------------------------------------------------|---------------|
| dCCTxAsym                   | Asymmetry of sending CC, dCCTxD50% - N x gdBit [1]                                         | -2.45 | -     |  2.45 | ns     | N=1, gdBit = 100ns, TxD load = 25pF max, SRE[2:0] = 110 (3.3V GPIO)        | -             |
| dCCTxDRISE25 + dCCTxDFALL25 | Sum of rise and fall time of TxD signal at the output pin [1]                              | -     | -     |  9    | ns     | TxD load = 25pF max, Z = 50ohms, delay = 0.6ns, SRE[2:0] = 110 (3.3V GPIO) | -             |
| dCCTxD01                    | Sum of delay between Clk to Q of the last FF and the final output buffer, rising edge [1]  | -     | -     | 25    | ns     | TxD load = 25pF max, SRE[2:0] = 110 (3.3V GPIO)                            | -             |
| dCCTxD10                    | Sum of delay between Clk to Q of the last FF and the final output buffer, falling edge [1] | -     | -     | 25    | ns     | TxD load = 25pF max, SRE[2:0] = 110 (3.3V GPIO)                            | -             |

S32G3 Data Sheet

<!-- image -->

## 16.4.3 FlexRay - TxEN

## Table 35. FlexRay - TxEN

| Symbol        | Description                                                                                | Min   | Typ   |   Max | Unit   | Condition                                        | Spec Number   |
|---------------|--------------------------------------------------------------------------------------------|-------|-------|-------|--------|--------------------------------------------------|---------------|
| dCCTxENRISE25 | Rise time of TxEN signal at CC [1]                                                         | -     | -     |     9 | ns     | TxEN load = 25pF max, SRE[2:0] = 110 (3.3V GPIO) | -             |
| dCCTxENFALL25 | Fall time of TxEN signal at CC [1]                                                         | -     | -     |     9 | ns     | TxEN load = 25pF max, SRE[2:0] = 110 (3.3V GPIO) | -             |
| dCCTxEN01     | Sum of delay between Clk to Q of the last FF and the final output buffer, rising edge [1]  | -     | -     |    25 | ns     | TxEN load = 25pF max, SRE[2:0] = 110 (3.3V GPIO) | -             |
| dCCTxEN10     | Sum of delay between Clk to Q of the last FF and the final output buffer, falling edge [1] | -     | -     |    25 | ns     | TxEN load = 25pF max, SRE[2:0] = 110 (3.3V GPIO) | -             |

S32G3 Data Sheet

- [1] Timing valid for maximum external load CL = 25pF, which is assumed to be a 8pF load at the end of a 50Ohm, un-terminated 5 inch microstrip trace on standard FR4 (1.5pF/inch), (25pF total with margin). For best signal integrity, the series resistance of the transmission line should be matched closely to the RDSON of the I/O pad output driver.

<!-- image -->

Figure 47. TxEN Signal Propagation Delay

<!-- image -->

## 16.9 PCIe

## Table 36. PCIe

Table continues on the next page...

| Symbol              | Description                           |     Min | Typ   | Max      | Unit   | Condition        | Spec Number   |
|---------------------|---------------------------------------|---------|-------|----------|--------|------------------|---------------|
| UI                  | Unit Interval [1]                     | 399.88  | -     | 400.12   | ps     | 2.5GT/s          | -             |
| UI                  | Unit Interval [1]                     | 199.94  | -     | 200.06   | ps     | 5.0GT/s          | -             |
| UI                  | Unit Interval [1]                     | 124.963 | -     | 125.0375 | ps     | 8.0GT/s          | -             |
| VTX-DIFF-PP         | Differential p-p Tx voltage swing [1] |   0.8   | -     | 1.2      | Vp-p   | 2.5GT/s, 5.0GT/s | -             |
| VTX-DE- RATIO-3.5dB | Tx de-emphasis level ratio [1]        |   2.5   | -     | 4.5      | dB     | 2.5GT/s, 5.0GT/s | -             |
| VTX-DE- RATIO-6dB   | Tx de-emphasis level ratio [1]        |   5     | -     | 7        | dB     | 5.0GT/s          | -             |
| TMIN-PULSE          | Instantaneous lone pulse width [1]    |   0.9   | -     | -        | UI     | 5.0GT/s          | -             |

## Table 36. PCIe...continued

| Symbol                       | Description                                                                  | Min   | Typ   | Max   | Unit         | Condition        | Spec Number   |
|------------------------------|------------------------------------------------------------------------------|-------|-------|-------|--------------|------------------|---------------|
| TTX-EYE                      | Transmitter Eye including all jitter sources [1]                             | 0.75  | -     | -     | UI           | 2.5GT/s, 5.0GT/s | -             |
| TTX-HF-DJ-DD                 | Tx deterministic jitter > 1.5 MHz [1]                                        | -     | -     | 0.15  | UI           | 5.0GT/s          | -             |
| TTX-LF-RMS                   | Tx RMS jitter < 1.5 MHz [1]                                                  | -     | 3     | -     | ps RMS       | 5.0GT/s          | -             |
| BWTX-PKG-PLL1                | Tx PLL BW corresponding to PKGTX-PLL1 [1]                                    | 8     | -     | 16    | MHz          | 5.0GT/s          | -             |
| BWTX-PKG-PLL1                | Tx PLL BW corresponding to PKGTX-PLL1 [1]                                    | 2     | -     | 4     | MHz          | 8.0GT/s          | -             |
| BWTX-PKG-PLL2                | Tx PLL BW corresponding to PKGTX-PLL2 [1]                                    | 5     | -     | 16    | MHz          | 5.0GT/s          | -             |
| BWTX-PKG-PLL2                | Tx PLL BW corresponding to PKGTX-PLL2 [1]                                    | 2     | -     | 5     | MHz          | 8.0GT/s          | -             |
| PKGTX-PLL1                   | Tx PLL peaking [1]                                                           | -     | -     | 3     | dB           | 5.0GT/s          | -             |
| PKGTX-PLL1                   | Tx PLL peaking [1]                                                           | -     | -     | 2     | dB           | 8.0GT/s          | -             |
| PKGTX-PLL2                   | Tx PLL peaking [1]                                                           | -     | -     | 1     | dB           | 5.0GT/s          | -             |
| PKGTX-PLL2                   | Tx PLL peaking [1]                                                           | -     | -     | 1     | dB           | 8.0GT/s          | -             |
| BWTX-PLL                     | Maximum Tx PLL bandwidth [1]                                                 | 1.5   | -     | 22    | MHz          | 2.5GT/s          | -             |
| TTX-EYE-MEDIAN- to-MAXJITTER | Maximum time between the jitter median and max deviation from the median [1] | -     | -     | 0.125 | UI           | 2.5GT/s          | -             |
| VTX-FS-NO-EQ                 | Full Swing Tx voltage with no TxEq [1]                                       | 800   | -     | 1300  | mVPP         | 8.0GT/s          | -             |
| VTX-EIEOS-FS                 | Min Swing during EIEOS for full swing [1]                                    | 250   | -     | -     | mVPP         | 8.0GT/s          | -             |
| TTX-UTJ                      | Tx uncorrelated total jitter [1]                                             | -     | -     | 31.25 | psPP@ 10e-12 | 8.0GT/s          | -             |
| TTX-UDJDD                    | Tx uncorrelated deterministic jitter [1]                                     | -     | -     | 12    | ps PP        | 8.0GT/s          | -             |

Table continues on the next page...

## Table 36. PCIe...continued

| Symbol         | Description                                                              | Min   | Typ   | Max   | Unit      | Condition                         | Spec Number   |
|----------------|--------------------------------------------------------------------------|-------|-------|-------|-----------|-----------------------------------|---------------|
| VTX-BOOST-FS   | Tx boost ratio for full swing [1]                                        | 8     | -     | -     | dB        | 8.0GT/s                           | -             |
| VRX-DIFF-PP-CC | Differential Rx peak- peak voltage for common Refclk Rx architecture [1] | 0.175 | -     | 1.2   | V         | 2.5GT/s                           | -             |
| VRX-DIFF-PP-CC | Differential Rx peak- peak voltage for common Refclk Rx architecture [1] | 0.12  | -     | 1.2   | V         | 5.0GT/s                           | -             |
| TRX-EYE        | Receiver eye time opening [1]                                            | 0.4   | -     | -     | UI        | 2.5GT/s                           | -             |
| TRX-TJ-CC      | Max Rx inherent timing error [1]                                         | -     | -     | 0.4   | UI        | 5.0GT/s                           | -             |
| TRX-DJ-DD_CC   | Max Rx deterministic timing error [1]                                    | -     | -     | 0.3   | UI        | 5.0GT/s                           | -             |
| VRX-EYE        | Receive eye voltage opening [1]                                          | -     | 120   | -     | mVPP diff | 5.0GT/s                           | -             |
| VRX-SV-8G      | Eye height at TP2P [1]                                                   | -     | 25    | -     | mVPP      | 8.0GT/s, -20dB Ch                 | -             |
| VRX-SV-8G      | Eye height at TP2P [1]                                                   | -     | 50    | -     | mVPP      | 8.0GT/s, -12dB Ch                 | -             |
| VRX-SV-8G      | Eye height at TP2P [1]                                                   | -     | 200   | -     | mVPP      | 8.0GT/s, -3dB Ch                  | -             |
| TRX-SV-8G      | Eye width at TP2P [1]                                                    | 0.3   | -     | 0.35  | UI        | 8.0GT/s                           | -             |
| TRX-SV-SJ-8G   | Sinusoidal Jitter at 100MHz [1]                                          | -     | 0.1   | -     | UI PP     | 8.0GT/s                           | -             |
| TRX-SV-RJ-8G   | Random Jitter [1]                                                        | -     | 2     | -     | ps RMS    | 8.0GT/s                           | -             |
| REXTPCIe       | External pin calibration resistance                                      | 198   | 200   | 202   | Ω         | -                                 | -             |
| RJREFCLK       | Reference clock random jitter (rms) [1]                                  | -     | -     | 3     | ps        | Integrated RJ from 12kHz to 20MHz | -             |
| RJREFCLK       | Reference clock random jitter (rms) [1]                                  | -     | -     | 2.2   | ps        | Integrated RJ from 2MHz to 20MHz  | -             |
| DJREFCLK       | Reference clock deterministic jitter (pk-pk) [1]                         | -     | -     | 5.7   | ps        | 200kHZ to 100MHz                  | -             |

Table continues on the next page...

## Table 36. PCIe...continued

| Symbol      | Description                                      | Min   | Typ   | Max          | Unit   | Condition                         | Spec Number   |
|-------------|--------------------------------------------------|-------|-------|--------------|--------|-----------------------------------|---------------|
| DJREFCLK    | Reference clock deterministic jitter (pk-pk) [1] | -     | -     | 2.8          | ps     | 1MHz to 20MHz                     | -             |
| RJ_SGMII    | Reference clock random jitter (rms)              | -     | -     | 2.3          | ps     | Integrated RJ from 12kHz to 20MHz | -             |
| RJ_SGMII    | Reference clock random jitter (rms)              | -     | -     | 1.7          | ps     | Integrated RJ from 2MHz to 20MHz  | -             |
| DJ_SGMII    | Reference clock deterministic jitter (pk-pk)     | -     | -     | 7.4          | ps     | 1MHz to 100MHz                    | -             |
| DJ_SGMII    | Reference clock deterministic jitter (pk-pk)     | -     | -     | 3.7          | ps     | 3MHz to 20MHz                     | -             |
| FREF_OFFSET | Reference clock frequency offset                 | -150  | -     | 150          | ppm    | -                                 | -             |
| DCREF_CLK   | Duty cycle                                       | 40    | -     | 60           | %      | -                                 | -             |
| VREF_CLK    | Voltage level                                    | 0     | -     | VDD_VP _PCIE | V      | -                                 | -             |
| IS_DIFF     | Differential input swing                         | 0.3   | -     | -            | Vpp    | -                                 | -             |
| SWREF_CLK   | Input edge rate                                  | 0.4   | -     | 2            | V/ns   | -                                 | -             |
| REF_CL_SKEW | Reference clock skew                             | -     | -     | 200          | ps     | -                                 | -             |

NXP completed PCI-SIG compliance testing with the following PHY registers modified from default settings as described below.  PHY register and programming details are provided in S32SERDESSUBSYSRM. PHY TX settings optimized for NXP validation board for SUP\_ANA\_TERM\_CTRL = 4 and TX\_VBOOST\_LVL = 4. PHY PLL bandwidth updated for MPLLB\_BW\_OVRD\_VAL = 218 and MPLLA\_BW\_OVRD\_VAL = 197.

NXP internally does PCI-SIG TX compliance testing using external reference clock source.

## 16.6 GMAC and PFE

## 16.6.1 GMAC and PFE Management Interface

SRE[2:0]=100 is the required drive setting to meet the timing.

S32G3 Data Sheet

Table 37. GMAC and PFE Management Interface

| Symbol   | Description                                                         | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|---------------------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| fMDC     | MDC clock frequency                                                 | -     | -     | 2.5   | MHz    | -           | MDC00         |
| MDIO_CH  | MDC pulse width high time                                           | 40    | -     | 60    | %      | -           | MDC14         |
| MDIO_CL  | MDC pulse width low time                                            | 40    | -     | 60    | %      | -           | MDC15         |
| MDIO_DOI | MDC falling edge to MDIO output invalid (minimum propagation delay) | 0     | -     | -     | ns     | -           | MDC10         |
| MDIO_DOV | MDC falling edge to MDIO output valid (maximum propagation delay)   | -     | -     | 15    | ns     | -           | MDC11         |
| MDIO_ISU | MDIO (input) to MDC rising edge setup time                          | 13    | -     | -     | ns     | -           | MDC12         |
| MDIO_IH  | MDIO (input) to MDC rising edge hold time                           | 0     | -     | -     | ns     | -           | MDC13         |

<!-- image -->

## 16.6.2 GMAC and PFE MII

SRE[2:0]=100 is the required drive setting to meet the timing.

S32G3 Data Sheet

## Table 38. GMAC and PFE MII

| Symbol   | Description                         | Min   | Typ      | Max   | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------|-------|----------|-------|--------|-------------|---------------|
| tCYC_RX  | RX_CLK period                       | -     | 40 / 400 | -     | ns     | 10/100 Mbps | -             |
| ΔtCYC_RX | RX_CLK duty cycle (tPWH / tCYC)     | 45    | -        | 55    | %      | -           | -             |
| tS       | Input setup time to RX_CLK [1]      | 5     | -        | -     | ns     | 10/100 Mbps | -             |
| tH       | Input hold time to RX_CLK [1]       | 5     | -        | -     | ns     | 10/100 Mbps | -             |
| tCYC_TX  | TX_CLK period [2]                   | -     | 40 / 400 | -     | ns     | 10/100 Mbps | -             |
| ΔtCYC_TX | TX_CLK duty cycle (tPWH / tCYC) [2] | 45    | -        | 55    | %      | -           | -             |
| tD       | Output delay from TX_CLK [2]        | 2     | -        | 25    | ns     | 10/100 Mbps | -             |

<!-- image -->

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

## 16.6.3 GMAC MII 50MHz

Note: GMAC MII 50MHz spec apply to GMAC only.

Table 39. GMAC MII 50MHz

| Symbol      | Description                                  | Min   | Typ   | Max   | Unit           | Condition   | Spec Number   |
|-------------|----------------------------------------------|-------|-------|-------|----------------|-------------|---------------|
| fRXCLK      | RXCLK frequency [1]                          | -     | -     | 50    | MHz            | -           | -             |
| dtRXCLK     | RXCLK pulse width high [1]                   | 35    | -     | 65    | % RXCLK period | -           | E3            |
| dtRXCLK     | RXCLK pulse width low [1]                    | 35    | -     | 65    | % RXCLK period | -           | E4            |
| tSETUP      | RXD[3:0], RXDV, RXER to RXCLK setup time [1] | 4     | -     | -     | ns             | -           | -             |
| tHOLD       | RXCLK to RXD[3:0], RXDV, RXER hold time [1]  | 2     | -     | -     | ns             | -           | -             |
| fTXCLK      | TXCLK frequency [2]                          | -     | -     | 50    | MHz            | -           | -             |
| dtTXCLK     | TXCLK pulse width high [2]                   | 35    | -     | 65    | % TXCLK period | -           | E7            |
| dtTXCLK     | TXCLK pulse width low [2]                    | 35    | -     | 65    | % TXCLK period | -           | E8            |
| tDATA_VALID | TXCLK to TXD[3:0], TXDV, TXER valid [2]      | -     | -     | 15    | ns             | -           | E6            |

Table continues on the next page...

Table 39. GMAC MII 50MHz...continued

| Symbol        | Description                               |   Min | Typ   | Max   | Unit   | Condition   | Spec Number   |
|---------------|-------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tDATA_INVALID | TXCLK to TXD[3:0], TXDV, TXER invalid [2] |     2 | -     | -     | ns     | -           | E5            |

- [1] Input timing assumes an input signal slew rate of 3ns (20%/80%).

[2] Output timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 5 inch microstrip trace on standard FR4 (1.5pF/inch, (25pF total with margin). For best signal integrity, the series resistance in the transmission line should be matched closely to the selected RDSON of the I/O pad output driver.

RXCLK/EXTAL

RXD[n:0]

RXDV,

RXER

Figure 52. MII 50MHz Receive Timing

<!-- image -->

## 16.6.4 GMAC and PFE RMII

SRE[2:0]=100 is the required drive setting to meet the timing.

Table 40. GMAC and PFE RMII

| Symbol     | Description                                       | Min   | Typ   | Max   | Unit   | Condition   | Spec Number    |
|------------|---------------------------------------------------|-------|-------|-------|--------|-------------|----------------|
| fRMII_CLK  | RMII input clock frequency (RMII_CLK)             | -     | -     | 50    | MHz    | -           | -              |
| ΔtRMII_CLK | RMII_CLK duty cycle (tPWH / tCYC)                 | 35    | -     | 65    | %      | -           | E3, E4, E7, E8 |
| tS         | RXD[1:0], CRS_DV, RXER to RMII_CLK setup time [1] | 4     | -     | -     | ns     | -           | E1             |

Table continues on the next page...

E4

E1

E3

E2

Valid data

S32G3 Data Sheet

Table 40. GMAC and PFE RMII...continued

| Symbol        | Description                                      | Min   | Typ   | Max   | Unit   | Condition    | Spec Number   |
|---------------|--------------------------------------------------|-------|-------|-------|--------|--------------|---------------|
| tH            | RMII_CLK to RXD[1:0], CRS_DV, RXER hold time [1] | 2     | -     | -     | ns     | -            | E2            |
| tDATA_VALID   | RMII_CLK to TXD[1:0], TXEN data valid [2]        | -     | -     | 14    | ns     | CLOAD = 25pF | E6            |
| tDATA_INVALID | RMII_CLK to TXD[1:0], TXEN data invalid [2]      | 2     | -     | -     | ns     | CLOAD = 25pF | E5            |

- [1] Input timing assumes an input signal slew rate of 3ns (20%/80%).
- [2] Output timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 5 inch microstrip trace on standard FR4 (1.5pF/inch), (25pF total with margin). For best signal integrity, the series resistance of the transmission line should be matched closely to the RDSON of the I/O pad output driver.

RXCLK/EXTAL (RMII)

RXD[n:0]

RXDV,

RXER

Figure 54. RMII Receive Timing

<!-- image -->

## 16.6.5 GMAC and PFE RGMII

You must set SRE[2:0]=101 for PFE\_MAC0\_TX\_CLK in RGMII mode of PFE GMAC0 at 3.3V.

SRE[2:0]=100 is the required drive setting to meet the timing.

Table 41. GMAC and PFE RGMII

| Symbol   | Description                       |   Min | Typ   |   Max | Unit   | Condition   | Spec Number   |
|----------|-----------------------------------|-------|-------|-------|--------|-------------|---------------|
| Tcyc     | Clock cycle duration [1][2][3][4] |   7.2 | -     |   8.8 | ns     | -           | -             |

Table continues on the next page...

E4

E1

E3

E2

Valid data

S32G3 Data Sheet

Table 41. GMAC and PFE RGMII...continued

| Symbol   | Description                                             |   Min | Typ   |   Max | Unit   | Condition   | Spec Number   |
|----------|---------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| TskewT   | Data to clock output skew (at transmitter) [1][3][4][5] |  -500 | -     | 500   | ps     | -           | -             |
| TskewR   | Data to clock input skew (at receiver) [3] [4][5]       |     1 | -     |   2.6 | ns     | -           | -             |
| Duty_G   | Clock duty cycle for Gigabit [3][4][6]                  |    45 | -     |  55   | %      | -           | -             |
| Duty_T   | Clock duty cycle for 10/100T [3][4][6]                  |    40 | -     |  60   | %      | -           | -             |

- [1] Output timing valid for maximum external load CL = 15pF, which is assumed to be a 8pF load at the end of a 50ohm, un-terminated, 2 inch microstrip trace on standard FR4 (1.5pF/inch). For best signal integrity, the series resistance of the transmission line should be matched closely to the selected RDSON of the I/O pad output driver.
- [3] Measured as defined in EIA/JESD 8-6 1995 with a timing threshold voltage of VDDQ/2
- [2] For 10 Mbps and 100 Mbps, Tcyc will scale to 400 ns ±40 ns and 40 ns ±4 ns respectively.
- [4] RGMII timing specifications are valid for both 1.8V and 3.3V nominal I/O pad supply voltage.
- [6] Duty cycle may be stretched/shrunk during speed changes or while transitioning to a received packet's clock domain as long as minimum duty cycle is not violated and stretching occurs for no more than three Tcyc of the lowest speed transitioned between.
- [5] For all versions prior to RGMII v2.0 specifications; This implies that PC board design will require clocks to be routed such that an additional delay of greater than 1.5 ns and less than 2 ns will be added to the associated clock signal. For 10/100, the max value is unspecified.

<!-- image -->

<!-- image -->

S32G3 Data Sheet

## 16.6.6 GMAC and PFE SGMII

## Table 42. GMAC and PFE SGMII

| Symbol          | Description                                                                           | Min     | Typ   |      Max | Unit   | Condition                                                                                     | Spec Number   |
|-----------------|---------------------------------------------------------------------------------------|---------|-------|----------|--------|-----------------------------------------------------------------------------------------------|---------------|
| UI              | Unit Interval (mean)                                                                  | 799.92  | 800   |  800.08  | ps     | 1.25 Gbps bit rate, applies to both transmitter and receiver and supports 1 Gbps data rate    | -             |
| UI              | Unit Interval (mean)                                                                  | 319.968 | 320   |  320.032 | ps     | 3.125 Gbps bit rate, applies to both transmitter and receiver and supports 2.5 Gbps data rate | -             |
| trise           | Transmit Vod rise time (20-80%)                                                       | -       | -     |  100     | ps     | -                                                                                             | -             |
| tfall           | Transmit Vod fall time (20-80%)                                                       | -       | -     |  100     | ps     | -                                                                                             | -             |
| &#124;VOD&#124; | Transmit Output Differential Voltage                                                  | 400     | -     |  600     | mV     | 1.25Gbps                                                                                      | -             |
| &#124;VOD&#124; | Transmit Output Differential Voltage [1]                                              | 400     | -     |  600     | mV     | 3.125Gbps                                                                                     | -             |
| RDOUT           | Transmit Differential Output Impedance                                                | 80      | 100   |  120     | Ohm    | -                                                                                             | -             |
| Dj              | Transmit Deterministic Jitter                                                         | -       | -     |    0.17  | UI     | -                                                                                             | -             |
| Tj              | Transmit Total Jitter                                                                 | -       | -     |    0.35  | UI     | -                                                                                             | -             |
| RDIN            | Receiver Differential Input Impedance                                                 | 80      | -     |  120     | Ohm    | -                                                                                             | -             |
| VIN             | Receiver Differential Input Voltage                                                   | 200     | -     | 1200     | mV     | -                                                                                             | -             |
| LOS             | Loss-of-signal threshold                                                              | 75      | -     |  200     | mV     | -                                                                                             | -             |
| Sjt             | Receiver deterministic jitter tolerance with sinusoidal noise [2]                     | -       | -     |    0.37  | UI     | -                                                                                             | -             |
| DRjt            | Receiver combined random and deterministic jitter tolerance with sinusoidal noise [2] | -       | -     |    0.55  | UI     | -                                                                                             | -             |

Table continues on the next page...

## Table 42. GMAC and PFE SGMII...continued

| Symbol   | Description                     | Min   | Typ   | Max    | Unit   | Condition   | Spec Number   |
|----------|---------------------------------|-------|-------|--------|--------|-------------|---------------|
| Tjt      | Receiver total jitter tolerance | -     | -     | 0.65   | UI     | -           | -             |
| BER      | Bit Error Rate                  | -     | -     | 10^-12 | -      | -           | -             |

- [1] VOD at 3.125Gbps is only applicable for PFE\_MAC0.
- [2] The sinusoidal jitter in the total jitter tolerance may have any amplitude and frequency in the un-shaded region of the figure below.

<!-- image -->

## 16.12 USB-ULPI

## Table 43. USB-ULPI

| Symbol   | Description                              | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| TCLK     | USB_CLKIN period                         | -     | 16.67 | -     | ns     | -           | U1            |
| DFCLK    | USB_CLKIN duty cycle                     | -     | 50    | -     | %      | -           | -             |
| tISU     | Input setup time (control and data) [1]  | 5     | -     | -     | ns     | -           | U2            |
| tIH      | Input hold time (control and data) [1]   | 1     | -     | -     | ns     | -           | U3            |
| tOV      | Output valid time (control and data) [2] | -     | -     | 9.5   | ns     | -           | U4            |
| tOH      | Output hold time (control and data) [2]  | 0     | -     | -     | ns     | -           | U5            |

- [1] Input timing assumes an input signal slew rate of 3ns (20%/80%).

<!-- image -->

S32G3 Data Sheet

S32G3 Data Sheet

- [2] Output timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 5 inch microstrip trace on standard FR4 with 1.5pF/inch (25pF total with margin). For best signal integrity, the series resistance of the transmission line should match closely to the RDSON of the I/O pad output driver.

<!-- image -->

## 16.8 Memory interfaces

## 16.8.1 QuadSPI

An external resistor is needed to pull up a QuadSPI chip select signal.

## 16.8.2 QuadSPI Quad 1.8V DDR 66MHz

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 44. QuadSPI Quad 1.8V DDR 66MHz

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition        | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|------------------|---------------|
| fSCK     | SCK clock frequency [1][2]          | -               | -     | 66             | MHz    | DLL mode enabled | -             |
| tCL_SCK  | SCK clock low time [1][2]           | 6.818           | -     | -              | ns     | -                | -             |
| tCH_SCK  | SCK clock high time [1][2]          | 6.818           | -     | -              | ns     | -                | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | 2.316           | -     | 4.802          | ns     | -                | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 5.016 - n/ fSCK | -     | 1.802 + m/fSCK | ns     | -                | -             |

Table continues on the next page...

## Table 44. QuadSPI Quad 1.8V DDR 66MHz...continued

| Symbol   | Description                            |   Min | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|----------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tDVW     | Input data valid window [1]            |  5.14 | -     | -     | ns     | -           | -             |
| tLSKEW   | Skew target for Auto-learning mode [4] |  1.89 | -     | -     | ns     | -           | -             |

## 16.8.3 QuadSPI Octal 1.8V SDR 133MHz

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

## Table 45. QuadSPI Octal 1.8V SDR 133MHz

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition       | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|-----------------|---------------|
| fSCK     | SCK clock frequency [1][2][3]       | -               | -     | 133            | MHz    | DLL Bypass mode | -             |
| tCL_SCK  | SCK clock low time [1][3]           | 3.383           | -     | -              | ns     | -               | -             |
| tCH_SCK  | SCK clock high time [1][3]          | 3.383           | -     | -              | ns     | -               | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [3]  | -1.594          | -     | 1.594          | ns     | -               | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [3][4] | 3.016 - n/ fSCK | -     | 2.704 + m/fSCK | ns     | -               | -             |
| tISU_SCK | Input setup time (w.r.t. SCK) [1]   | 0.580           | -     | -              | ns     | -               | -             |
| tIH_SCK  | Input hold time (w.r.t. SCK) [1]    | 0.9             | -     | -              | ns     | -               | -             |

## 16.8.4 QuadSPI Octal 1.8V DDR 100MHz

The information in this section applies to Octal- and Hyperflash.

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

## S32G3

<!-- image -->

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 46. QuadSPI Octal 1.8V DDR 100MHz

| Symbol   | Description                         | Min             | Typ   | Max             | Unit   | Condition                                              | Spec Number   |
|----------|-------------------------------------|-----------------|-------|-----------------|--------|--------------------------------------------------------|---------------|
| fSCK_DQS | SCK / DQS frequency [1][2]          | -               | -     | 100             | MHz    | fSCK duty cycle distortion is in the range of 45%-55%. | -             |
| tCL_SCK  | SCK low time [1][2]                 | 4.500           | -     | -               | ns     | -                                                      | -             |
| tCH_SCK  | SCK high time [1][2]                | 4.500           | -     | -               | ns     | -                                                      | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | 1.016           | -     | 3.484           | ns     | -                                                      | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 3.016 - n/ fSCK | -     | -0.016 + m/fSCK | ns     | -                                                      | -             |
| tISU_DQS | Input setup time (w.r.t. DQS) [1]   | -0.816          | -     | -               | ns     | -                                                      | -             |
| tIH_DQS  | Input hold time (w.r.t. DQS) [1]    | 3.684           | -     | -               | ns     | -                                                      | -             |

## 16.8.5 QuadSPI Octal 1.8V DDR 133MHz

The information in this section applies to Octal- and Hyperflash.

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 47. QuadSPI Octal 1.8V DDR 133MHz

| Symbol   | Description                        | Min   | Typ   | Max   | Unit   | Condition                                                                | Spec Number   |
|----------|------------------------------------|-------|-------|-------|--------|--------------------------------------------------------------------------|---------------|
| fSCK_DQS | SCK / DQS frequency [1][2][3]      | -     | -     | 133   | MHz    | DLL mode enabled, fSCK duty cycle distortion is in the range of 45%-55%. | -             |
| tCL_SCK  | SCK low time [1][3]                | 3.383 | -     | -     | ns     | -                                                                        | -             |
| tCH_SCK  | SCK high time [1][3]               | 3.383 | -     | -     | ns     | -                                                                        | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [3] | 0.816 | -     | 2.567 | ns     | -                                                                        | -             |

Table continues on the next page...

<!-- image -->

Table 47. QuadSPI Octal 1.8V DDR 133MHz...continued

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|-------------|---------------|
| tOD_CS   | CS output delay (w.r.t. SCK) [3][4] | 3.015 - n/ fSCK | -     | -1.33 + m/fSCK | ns     | -           | -             |
| tISU_DQS | Input setup time (w.r.t. DQS) [1]   | -0.616          | -     | -              | ns     | -           | -             |
| tIH_DQS  | Input hold time (w.r.t. DQS) [1]    | 2.767           | -     | -              | ns     | -           | -             |

## 16.8.6 QuadSPI Octal 1.8V SDR 100MHz

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 48. QuadSPI Octal 1.8V SDR 100MHz

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|-------------|---------------|
| fSCK     | SCK clock frequency [1][2]          | -               | -     | 100            | MHz    | -           | -             |
| tCL_SCK  | SCK clock low time [1][2]           | 4.5             | -     | -              | ns     | -           | -             |
| tCH_SCK  | SCK clock high time [1][2]          | 4.5             | -     | -              | ns     | -           | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | -2.822          | -     | 2.822          | ns     | -           | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 3.016 - n/ fSCK | -     | 5.160 + m/fSCK | ns     | -           | -             |
| tISU_SCK | Input setup time (w.r.t. SCK) [1]   | 3.036           | -     | -              | ns     | -           | -             |
| tIH_SCK  | Input hold time (w.r.t. SCK) [1]    | 0.9             | -     | -              | ns     | -           | -             |

## 16.8.7 QuadSPI Quad 1.8V SDR 133MHz

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

S32G3 Data Sheet

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 49. QuadSPI Quad 1.8V SDR 133MHz

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition       | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|-----------------|---------------|
| fSCK     | SCK clock frequency [1][2][3]       | -               | -     | 133            | MHz    | DLL Bypass mode | -             |
| tCL_SCK  | SCK low time [1][3]                 | 3.383           | -     | -              | ns     | -               | -             |
| tCH_SCK  | SCK high time [1][3]                | 3.383           | -     | -              | ns     | -               | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [3]  | -0.594          | -     | 1.594          | ns     | -               | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [3][4] | 4.016 - n/ fSCK | -     | 4.204 + m/fSCK | ns     | -               | -             |
| tISU_SCK | Input setup time (w.r.t. SCK) [1]   | 0.580           | -     | -              | ns     | -               | -             |
| tIH_SCK  | Input hold time (w.r.t. SCK) [1]    | 1.000           | -     | -              | ns     | -               | -             |

## 16.8.8 QuadSPI Quad 3.3V DDR 66MHz

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 50. QuadSPI Quad 3.3V DDR 66MHz

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition        | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|------------------|---------------|
| fSCK     | SCK clock frequency [1][2]          | -               | -     | 66             | MHz    | DLL mode enabled | -             |
| tCL_SCK  | SCK clock low time [1][2]           | 6.818           | -     | -              | ns     | -                | -             |
| tCH_SCK  | SCK clock high time [1][2]          | 6.818           | -     | -              | ns     | -                | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | 2.316           | -     | 4.802          | ns     | -                | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 5.016 - n/ fSCK | -     | 1.802 + m/fSCK | ns     | -                | -             |

Table continues on the next page...

<!-- image -->

Table 50. QuadSPI Quad 3.3V DDR 66MHz...continued

| Symbol   | Description                            |   Min | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|----------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tDVW     | Input data valid window [1]            |  5.14 | -     | -     | ns     | -           | -             |
| tLSKEW   | Skew target for Auto-learning mode [4] |  1.89 | -     | -     | ns     | -           | -             |

## 16.8.9 QuadSPI Quad 3.3V SDR 104MHz

The SRE[2:0]=100 for 18GPIO pads and SRE[2:0]=101 for 1833Fast pads is the required drive setting to meet the timing.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 51. QuadSPI Quad 3.3V SDR 104MHz

| Symbol   | Description                         | Min             | Typ   | Max            | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------|-----------------|-------|----------------|--------|-------------|---------------|
| fSCK     | SCK clock frequency [1][2]          | -               | -     | 104            | MHz    | -           | -             |
| tCL_SCK  | SCK clock low time [1][2]           | 4.327           | -     | -              | ns     | -           | -             |
| tCH_SCK  | SCK clock high time [1][2]          | 4.327           | -     | -              | ns     | -           | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | -2.330          | -     | 2.880          | ns     | -           | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 3.391 - n/ fSCK | -     | 5.901 + m/fSCK | ns     | -           | -             |
| tISU_SCK | Input setup time (w.r.t. SCK) [1]   | 2.152           | -     | -              | ns     | -           | -             |
| tIH_SCK  | Input hold time (w.r.t. SCK) [1]    | 2.0             | -     | -              | ns     | -           | -             |

## 16.8.10 QuadSPI Octal 1.8V DDR 166MHz

The information in this section applies to Octal- and Hyperflash.

The SRE[2:0]=000 for 18GPIO pads is the required drive setting to meet the timing.

<!-- image -->

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 52. QuadSPI Octal 1.8V DDR 166MHz

| Symbol   | Description                         | Min             | Typ   | Max             | Unit   | Condition                                              | Spec Number   |
|----------|-------------------------------------|-----------------|-------|-----------------|--------|--------------------------------------------------------|---------------|
| fSCK-DQS | SCK/DQS frequency [1][2]            | -               | -     | 166             | MHz    | fSCK duty cycle distortion is in the range of 45%-55%. | -             |
| tCL_SCK  | SCK low time [1][2]                 | 2.711           | -     | -               | ns     | -                                                      | -             |
| tCH_SCK  | SCK high time [1][2]                | 2.711           | -     | -               | ns     | -                                                      | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | 0.616           | -     | 2.095           | ns     | -                                                      | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 3.016 - n/ fSCK | -     | -1.805 + m/fSCK | ns     | -                                                      | -             |
| tIH_DQS  | Input hold time (w.r.t. DQS) [1]    | 2.105           | -     | -               | ns     | -                                                      | -             |
| tISU_DQS | Input setup time (w.r.t. DQS) [1]   | -0.616          | -     | -               | ns     | -                                                      | -             |

## 16.8.11 QuadSPI Octal 1.8V DDR 200MHz

In Single SRE configuration SRE[2:0]=000 for Data &amp; CLK both, and in Split SRE configuration SRE[2:0]=000 for Data &amp; SRE[2:0]=110 for CLK are the required drive settings to meet the timing for 18GPIO pad.

FLSHCR[TCSS] and FLSHCR[TCSH] should be set to 3.

Data transitions measured at 30%/70% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 53. QuadSPI Octal 1.8V DDR 200MHz

| Symbol   | Description                        | Min   | Typ   | Max   | Unit   | Condition                                              | Spec Number   |
|----------|------------------------------------|-------|-------|-------|--------|--------------------------------------------------------|---------------|
| fSCK-DQS | SCK/DQS frequency [1][2]           | -     | -     | 200   | MHz    | fSCK duty cycle distortion is in the range of 45%-55%. | -             |
| tCL_SCK  | SCK low time [1][2]                | 2.25  | -     | -     | ns     | -                                                      | -             |
| tCH_SCK  | SCK high time [1][2]               | 2.25  | -     | -     | ns     | -                                                      | -             |
| tOD_DATA | Data output delay (w.r.t. SCK) [2] | 0.616 | -     | 1.634 | ns     | Split SRE configuration, SRE[2:0]=000 for Data         | -             |

Table continues on the next page...

<!-- image -->

Table 53. QuadSPI Octal 1.8V DDR 200MHz...continued

| Symbol   | Description                         | Min             | Typ   | Max             | Unit   | Condition                              | Spec Number   |
|----------|-------------------------------------|-----------------|-------|-----------------|--------|----------------------------------------|---------------|
|          |                                     |                 |       |                 |        | and SRE[2:0]=110 for CLK               |               |
| tOD_DATA | Data output delay (w.r.t. SCK) [2]  | 0.772           | -     | 1.79            | ns     | Single SRE configuration, SRE[2:0]=000 | -             |
| tOD_CS   | CS output delay (w.r.t. SCK) [2][3] | 3.016 - n/ fSCK | -     | -2.266 + m/fSCK | ns     | -                                      | -             |
| tIH_DQS  | Input hold time (w.r.t. DQS) [1]    | 1.644           | -     | -               | ns     | -                                      | -             |
| tISU_DQS | Input setup time (w.r.t. DQS) [1]   | -0.586          | -     | -               | ns     | -                                      | -             |

## 16.8.12 QuadSPI configurations

The below table shows a subset of the QuadSPI module configurations for different speeds and data rates. The configuration values for each case are equally applicable to Quad, Octal and HyperFlash interfaces, so long as the maximum clock frequency as per Table 55 is not exceeded.

## Table 54. QuadSPI configurations

| -             | DDR-200MHz                | DDR-133MHz                | SDR-133MHz            | SDR-104MHz            | DDR-66MHz             |
|---------------|---------------------------|---------------------------|-----------------------|-----------------------|-----------------------|
| DQS mode      | External DQS Edge Aligned | External DQS Edge Aligned | Internal pad loopback | Internal pad loopback | Internal pad loopback |
| Sampling mode | DDR                       | DDR                       | SDR                   | SDR                   | DDR                   |
| DLL Mode      | DLL Enable                | DLL Enable                | DLL Bypass            | DLL Bypass            | DLL Enable            |
| Data Learning | No                        | No                        | No                    | No                    | Yes                   |
| IO Voltage    | 1.8V                      | 1.8V                      | 1.8V                  | 3.3V                  | 1.8V/3.3V             |
| Frequency     | 166/200 MHz               | 100/133 MHz               | 100/133 MHz           | 104 MHz               | 66 MHz                |
| FLSHCR[TDH]   | 1                         | 1                         | 0                     | 0                     | 1                     |
| FLSHCR[TCSH]  | 3                         | 3                         | 3                     | 3                     | 3                     |
| FLSHCR[TCSS]  | 3                         | 3                         | 3                     | 3                     | 3                     |
| MCR[DLPEN]    | 0                         | 0                         | 0                     | 0                     | 1                     |
| DLLCR[DLLEN]  | 1                         | 1                         | 0                     | 0                     | 1                     |

Table continues on the next page...

S32G3 Data Sheet

Table 54. QuadSPI configurations...continued

| -                      | DDR-200MHz              | DDR-133MHz   | SDR-133MHz   | SDR-104MHz   | DDR-66MHz   |
|------------------------|-------------------------|--------------|--------------|--------------|-------------|
| DLLCR[FREQEN]          | 1                       | 0            | 0            | 0            | 0           |
| DLLCR[DLL_REFCNTR]     | 2                       | 2            | NA           | NA           | 2           |
| DLLCR[DLLRES]          | 8                       | 8            | NA           | NA           | 8           |
| DLLCR[SLV_FINE_OFFSET] | 0                       | 0            | 0            | 0            | 0           |
| DLLCR[SLV_DLY_OFFSET]  | 0                       | 0            | 0            | 0            | 3           |
| DLLCR[SLV_DLY_COARSE]  | NA                      | NA           | 0            | 0            | 0           |
| DLLCR[SLAVE_AUTO_UPDT] | 1                       | 1            | 0            | 0            | 1           |
| DLLCR[SLV_EN]          | 1                       | 1            | 1            | 1            | 1           |
| DLLCR[SLV_DLL_BYPASS]  | 0                       | 0            | 1            | 1            | 0           |
| DLLCR[SLV_UPD]         | 1                       | 1            | 1            | 1            | 1           |
| SMPR[DLLFSMPF]         | 3 (200 Mhz) 4 (166 Mhz) | 4            | 0            | 0            | NA          |
| SMPR[FSDLY]            | 0                       | 0            | 0            | 0            | 1           |
| SMPR[FSPHS]            | NA                      | NA           | 1            | 1            | NA          |

## 16.8.13 QuadSPI interfaces

The QuadSPI module supports 2 interfaces; QSPI A &amp; QSPI B. These interfaces are not independent &amp; the QSPI chapter of the reference manual should be consulted for their usage. The table below summarizes which specifications are supported on each interface.

Table 55. QuadSPI interfaces

| Specification / Interface   | 3.3V Quad            | 1.8V Quad                | 1.8V Octal                             | 1.8V Hyperflash     |
|-----------------------------|----------------------|--------------------------|----------------------------------------|---------------------|
| QSPI A                      | n/a                  | SDR 100/133MHz DDR 66MHz | SDR 100/133MHz DDR 100/133/166/200 MHz | DDR 100/133/166 MHz |
| QSPI B                      | SDR 104MHz DDR 66MHz | SDR 100/133MHz DDR 66MHz | SDR 100/133MHz DDR 100/133MHz          | DDR 100/133MHz      |

## 16.8.14 QuadSPI timing diagrams

The sections shows the QuadSPI timing diagrams for all modes supported by the device. All data is based on a negative edge data launch from the device.

S32G3 Data Sheet

<!-- image -->

<!-- image -->

<!-- image -->

S32G3 Data Sheet

<!-- image -->

<!-- image -->

## 16.9 DDR

## 16.9.1 DDR

The chip supports the following memory types:

1. LPDDR4 SDRAM compliant to JEDEC209-4B LPDDR4 JEDEC standard release.
2. DDR3L SDRAM compliant to JESD79-3-1A DDR3L JEDEC standard release July, 2010.

DDR operation with the standards stated above is contingent upon the board DDR design adherence to the DDR design and layout requirements stated in the chip's Hardware Design Guide Document.

LPDDR4 routing constraints are documented in the chip's Hardware Design Guidelines Document.

## 16.9.2 DDR Common DC Input

The specifications given in the table below represent the common DC input conditions for all DDR interface modes. Unless otherwise specified, all input specifications (both common and DDR standard specific) are measured at the host PHY input pins. Subsequent sections list input parameters for the specific memory interface standards.

Table 56. DDR Common DC Input

| Symbol       | Description                    | Min         | Typ   | Max          | Unit   | Condition   | Spec Number   |
|--------------|--------------------------------|-------------|-------|--------------|--------|-------------|---------------|
| IIZ-VREF     | VREF input leakage current [1] | -50         | -     | 50           | uA     | -           | -             |
| IIZ-BP       | Input leakage current [2]      | -50         | -     | 50           | uA     | -           | -             |
| VIH-DC_BPDAT | Input high voltage threshold   | VREF+0. 085 | -     | -            | V      | -           | -             |
| VIL-DC_BPDAT | Input low voltage threshold    | -           | -     | vref - 0.085 | V      | -           | -             |

## 16.9.3 DDR Common DC Output

## Table 57. DDR Common DC Output

| Symbol   | Description                                                       | Min   | Typ        | Max   | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------------------------------------|-------|------------|-------|--------|-------------|---------------|
| ROnPu    | Output driver pull- up impedance: DQ, DQS outputs [1]             | -     | 120,60,4 0 | -     | Ohm    | -           | -             |
| ROnPd    | Output driver pull- down impedance: DQ, DQS outputs [1]           | -     | 120,60,4 0 | -     | Ohm    | -           | -             |
| ROnPu    | Output driver pull-up impedance: address, command [1]             | -     | 120,60,4 0 | -     | Ohm    | -           | -             |
| ROnPd    | Output driver pull- down impedance: address, command [1]          | -     | 120,60,4 0 | -     | Ohm    | -           | -             |
| ROnPu    | Output driver pull- up impedance: DDR0_RESET_B, CKE outputs [2]   | -     | 18-28      | -     | Ohm    | -           | -             |
| ROnPd    | Output driver pull- down impedance: DDR0_RESET_B, CKE outputs [2] | -     | 18-28      | -     | Ohm    | -           | -             |

NOTE: Refer to IBIS model for the complete IV curve characteristics.

S32G3 Data Sheet

## 16.9.4 DDR3L DC Input

## Table 58. DDR3L DC Input

| Symbol   | Description                    |   Min |   Typ |   Max | Unit         | Condition   | Spec Number   |
|----------|--------------------------------|-------|-------|-------|--------------|-------------|---------------|
| Vref     | Input reference voltage [1][2] |  30.1 |  31.1 |  32.1 | %VDD_I O_DDR | -           | -             |

- [1] If the external Vref to the receivers is enabled, DDR0\_VREF is expected to be set to a nominal value of (VDD\_IO\_DDR0/2)*RxAtten (RxAttenuation for DDR3L is 0.623) through a voltage divider in order to track VDD\_IO\_DDR0 level. It can be adjusted in the system to margin the input DQ signals, although this margin does not necessarily represent the eye height since a change in Vref also changes the input receiver common mode, altering receiver performance.

[2] Externally supplied Vref is not recommended. Internal Vref generation through local Vref generation at each receiver is preferred.

## 16.9.5 DDR3L Output Timing

## Table 59. DDR3L Output Timing

| Symbol    | Description                                                  | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|-----------|--------------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tCK(avg)  | Average clock period [1][2]                                  | -     | 1.25  | -     | ns     | -           | -             |
| tOS(Vref) | Command and address setup time to CK (to Vref levels) [1][2] | 350   | -     | -     | ps     | -           | -             |
| tOH(Vref) | Command and address hold time to CK (to Vref levels) [1] [2] | 350   | -     | -     | ps     | -           | -             |
| tDOeye    | Output data eye [1][2]                                       | 0.6   | -     | -     | UI     | -           | -             |

<!-- image -->

## 16.9.6 LPDDR4 DC Input timing

## Table 60. LPDDR4 DC Input timing

| Symbol   | Description                       | Min   | Typ      | Max   | Unit   | Condition   | Spec Number   |
|----------|-----------------------------------|-------|----------|-------|--------|-------------|---------------|
| Vref     | Internal reference voltage [1][2] | -     | Variable | -     | V      | -           | -             |

S32G3 Data Sheet

- [2] Externally supplied Vref is not recommended. Internal Vref generation through local Vref generation at each receiver is preferred.

S32G3 Data Sheet

- [1] Because termination at the DRAMs is configurable, there is no fixed setting. The Vref value is dependent on driver impedance Ron and system effective ODT impedance Rtt.

## 16.9.7 LPDDR4 Output Timing

## Table 61. LPDDR4 Output Timing

| Symbol   | Description                | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|----------------------------|-------|-------|-------|--------|-------------|---------------|
| tCK(avg) | Average clock period [1]   | -     | 0.625 | -     | ns     | -           | -             |
| tDOeye   | Output data eye [1][2] [3] | 0.55  | -     | -     | UI     | -           | -             |
| tCAOeye  | CA output data eye [1][4]  | 0.62  | -     | -     | UI     | UI=625ps    | -             |

- [1] Measurements were done with signals terminated with a 50ohm resistor terminated to VSS, Phy output is calibrated to a drive strength of 40ohms. Slew rate AtxSlewRate was set to 0x1FF (PreDrvMode=1, PreN=F,PreP=F); TxSlewRate was set 0x1FF (PreDrvMode=1, PreN=F, PreP=F).
- [3] Tx DQS to MCLK edges are trained to be aligned.
- [2] tDOeye is trained to be shifted min 200 ps from DQS edge (tDQS2DQ learning).
- [4] Addr/Cmd is centered aligned by training.

<!-- image -->

## 16.10 uSDHC

## 16.10.1 uSDHC SD3.0/eMMC5.1 DDR

The SRE[2:0]=101 is required drive setting to meet the timing.

Data transitions measured at 35%/65% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 62. uSDHC SD3.0/eMMC5.1 DDR

| Symbol   | Description                       | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|-----------------------------------|-------|-------|-------|--------|-------------|---------------|
| fpp      | Clock frequency (eMMC5.1 DDR) [1] | -     | -     | 52    | MHz    | -           | SD1           |
| fpp      | Clock frequency (SD3.0 DDR) [1]   | -     | -     | 50    | MHz    | -           | SD1           |
| tWL      | Clock low time                    | 8.8   | -     | -     | ns     | -           | -             |
| tWH      | Clock high time                   | 8.8   | -     | -     | ns     | -           | -             |

Table continues on the next page...

Table 62. uSDHC SD3.0/eMMC5.1 DDR...continued

| Symbol   | Description                          | Min   | Typ   | Max   | Unit   | Condition             | Spec Number                                                         |
|----------|--------------------------------------|-------|-------|-------|--------|-----------------------|---------------------------------------------------------------------|
| tTLH     | Clock rise time [1][2]               | -     | -     | 0.8   | ns     | -                     | SD9                                                                 |
| tTHL     | Clock fall time [1][2]               | -     | -     | 0.8   | ns     | -                     | SD10                                                                |
| tOD      | SDHC output delay (output valid) [1] | 2.7   | -     | 5.6   | ns     | SDHC_CLK to SDHC_ DAT | SD2                                                                 |
| tOD      | SDHC output delay (output valid) [1] | -5.6  | -     | 2.6   | ns     | SDHC_CLK to SDHC_ CMD | SD6 (See SD3.0/ SDIO3.0/ eMMC5. 1 SDR Mode Interface Timing figure) |
| tISU     | SDHC Input setup time [3]            | 1.6   | -     | -     | ns     | SDHC_DAT to SDHC_ CLK | SD3                                                                 |
| tISU     | SDHC Input setup time [3]            | 4.8   | -     | -     | ns     | SDHC_CMD to SDHC_ CLK | SD7 (See SD3.0/ SDIO3.0/ eMMC5. 1 SDR Mode Interface Timing figure) |
| tIH      | SDHC Input hold time [3]             | 1.5   | -     | -     | ns     | SDHC_CLK to SDHC_ DAT | SD4                                                                 |
| tIH      | SDHC Input hold time [3]             | 1.5   | -     | -     | ns     | SDHC_CLK to SDHC_ CMD | SD8 (See SD3.0/ SDIO3.0/ eMMC5. 1 SDR Mode Interface Timing figure) |

[3] Input signal timing assumes an input signal slew rate of 3ns (20%/80%).

[2] The SDHC\_CLK rise/fall time specification applies to the input clock transition required in order to meet the output delay specifications. SDHC\_CLK output transition time is dependent on output load and GPIO pad drive strength. See the GPIO pad specifications for detail.

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

## 16.10.2 uSDHC SD3.0/SDIO3.0/eMMC5.1 SDR

The SRE[2:0]=101 is required drive setting to meet the timing.

Data transitions measured at 35%/65% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 63. uSDHC SD3.0/SDIO3.0/eMMC5.1 SDR

| Symbol   | Description                                             | Min   | Typ   | Max   | Unit   | Condition                        | Spec Number   |
|----------|---------------------------------------------------------|-------|-------|-------|--------|----------------------------------|---------------|
| fpp      | Clock frequency (low speed) [1][2]                      | -     | -     | 400   | kHz    | -                                | SD1           |
| fpp      | Clock frequency (SD/SDIO full speed /high speed) [2][3] | -     | -     | 25/50 | MHz    | -                                | SD1           |
| fpp      | Clock frequency (eMMC full speed/ high speed) [2][4]    | -     | -     | 20/52 | MHz    | -                                | SD1           |
| fOD      | Clock frequency (identification mode) [2]               | 100   | -     | 400   | kHz    | -                                | SD1           |
| tWL      | Clock low time                                          | 8.8   | -     | -     | ns     | -                                | SD2           |
| tWH      | Clock high time                                         | 8.8   | -     | -     | ns     | -                                | SD3           |
| tTLH     | Clock rise time [2][5]                                  | -     | -     | 0.8   | ns     | -                                | SD4           |
| tTHL     | Clock fall time [2][5]                                  | -     | -     | 0.8   | ns     | -                                | SD5           |
| tOD      | SDHC output delay (output valid) [2]                    | -5.6  | -     | 2.6   | ns     | SDHC_CLK to SDHC_ CMD / SDHC_DAT | SD6           |
| tISU     | SDHC Input setup time [6]                               | 4.8   | -     | -     | ns     | SDHC_CMD / SDHC_ DAT to SDHC_CLK | SD7           |
| tIH      | SDHC Input hold time [6]                                | 1.5   | -     | -     | ns     | SDHC_CLK to SDHC_ CMD / SDHC_DAT | SD8           |

S32G3 Data Sheet

- [2] Output timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 5 inch microstrip trace on standard FR4 (1.5pF/inch), (25pF total with margin).
- [4] In normal (full) speed mode for MMC card, clock frequency can be any value between 0-20 MHz. In high-speed mode, clock frequency can be any value between 0-52 MHz.
- [3] In normal (full) speed mode for SD/SDIO card, clock frequency can be any value between 0-25 MHz. In high-speed mode, clock frequency can be any value between 0-50 MHz.
- [5] The SDHC\_CLK rise/fall time specification applies to the input clock transition required in order to meet the output delay specifications. SDHC\_CLK output transition time is dependent on output load and GPIO pad drive strength. See the GPIO pad specifications for detail.
- [6] Input signal timing assumes an input signal slew rate of 3ns (20%/80%).

<!-- image -->

## 16.10.3 uSDHC SDR-100MHz

The SRE[2:0]=101 is required drive setting to meet the timing.

Data transitions measured at 35%/65% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

Table 64. uSDHC SDR-100MHz

| Symbol   | Description                | Min   | Typ   | Max   | Unit   | Condition                        | Spec Number   |
|----------|----------------------------|-------|-------|-------|--------|----------------------------------|---------------|
| tCLK     | Clock frequency [1]        | -     | -     | 100   | MHz    | -                                | SD1           |
| tCL      | Clock low time             | 4.5   | -     | -     | ns     | -                                | SD2           |
| tCH      | Clock high time            | 4.5   | -     | -     | ns     | -                                | SD3           |
| tTLH     | Clock rise time [1][2]     | -     | -     | 0.8   | ns     | -                                | SD8           |
| tTHL     | Clock fall time [1][2]     | -     | -     | 0.8   | ns     | -                                | SD9           |
| tOD      | uSDHC output delay [1]     | -3.5  | -     | 1.3   | ns     | SDHC_CLK to SDHC_ CMD / SDHC_DAT | SD4           |
| tISU     | uSDHC input setup time [3] | 1.3   | -     | -     | ns     | SDHC_CMD / SDHC_ DAT to SDHC_CLK | SD6           |
| tIH      | uSDHC input hold time [3]  | 1.5   | -     | -     | ns     | SDHC_CLK to SDHC_ CMD / SDHC_DAT | SD7           |

- [1] Output timing valid for maximum external load CL = 15pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 2 inch microstrip trace on standard FR4 (1.5pF/inch). For best signal integrity, the series resistance of the transmission line should be matched closely to the RDSON of the I/O pad output driver.
- [3] Input signal timing assumes an input signal slew rate of 1ns (20%/80%).
- [2] The SDHC\_CLK rise/fall time specification applies to the input clock transition required in order to meet the output delay specifications. SDHC\_CLK output transition time is dependent on output load and GPIO pad drive strength. See the GPIO pad specifications for detail.

S32G3 Data Sheet

<!-- image -->

## 16.10.4 uSDHC SDR-HS200

The SRE[2:0]=000 is required drive setting to meet the timing.

Data transitions measured at 35%/65% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

## Table 65. uSDHC SDR-HS200

| Symbol   | Description            | Min   | Typ   | Max   | Unit   | Condition                        | Spec Number   |
|----------|------------------------|-------|-------|-------|--------|----------------------------------|---------------|
| tCLK     | Clock frequency [1]    | -     | -     | 200   | MHz    | -                                | SD1           |
| tCL      | Clock low time         | 2.2   | -     | -     | ns     | -                                | SD2           |
| tCH      | Clock high time        | 2.2   | -     | -     | ns     | -                                | SD3           |
| tTLH     | Clock rise time [1][2] | -     | -     | 0.8   | ns     | -                                | SD5           |
| tTHL     | Clock fall time [1][2] | -     | -     | 0.8   | ns     | -                                | SD6           |
| tOD      | uSDHC output delay [1] | -1.2  | -     | 0.6   | ns     | SDHC_CLK to SDHC_ CMD / SDHC_DAT | SD4           |
| tODW     | Input data window [3]  | 2.6   | -     | -     | ns     | SDHC_DAT / SDHC_ CMD             | SD8           |

- [1] Output timing valid for maximum external load CL = 15pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 2 inch microstrip trace on standard FR4 (1.5pF/inch). For best signal integrity, the series resistance of the transmission line should be matched closely to the RDSON of the the I/O pad output driver.
- [3] Input signal timing assumes an input signal slew rate of 1ns (20%/80%).
- [2] The SDHC\_CLK rise/fall time specification applies to the input clock transition required in order to meet the output delay specifications. SDHC\_CLK output transition time is dependent on output load and GPIO pad drive strength. See the GPIO pad specifications for detail.

<!-- image -->

## 16.10.5 uSDHC DDR-HS400

In Split SRE configuration SRE[2:0]=000 for Data/CMD and SRE[2:0]=111 for CLK are the required drive settings to meet the timing.

Data transitions measured at 35%/65% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid-supply.

## Table 66. uSDHC DDR-HS400

| Symbol   | Description                                 | Min   | Typ   | Max   | Unit   | Condition             | Spec Number   |
|----------|---------------------------------------------|-------|-------|-------|--------|-----------------------|---------------|
| fPP      | Clock frequency [1]                         | 133   | -     | 200   | MHz    | -                     | SD1           |
| tCL      | Clock low time                              | 2.35  | -     | -     | ns     | -                     | SD2           |
| tCH      | Clock high time                             | 2.35  | -     | -     | ns     | -                     | SD3           |
| tTLH     | Clock rise time [1][2]                      | -     | -     | 0.8   | ns     | -                     | SD8           |
| tTHL     | Clock fall time [1][2]                      | -     | -     | 0.8   | ns     | -                     | SD9           |
| tOD1     | Output skew from Edge of Data to SCK [1][3] | 0.65  | -     | -     | ns     | -                     | SD4           |
| tOD2     | Output skew from Edge of SCK to Data [1][3] | 0.65  | -     | -     | ns     | -                     | SD5           |
| tRQ      | Input skew (data) [4]                       | -     | -     | 0.45  | ns     | -                     | SD6           |
| tRQ      | Input skew (CMD) [4] [5]                    | -     | -     | 0.45  | ns     | -                     | SD8           |
| tRQH     | Hold skew (data) [4]                        | -     | -     | 0.45  | ns     | -                     | SD7           |
| tRQH     | Hold skew (CMD) [4] [5]                     | -     | -     | 0.45  | ns     | -                     | SD9           |
| tOD      | uSDHC Output delay [1]                      | -1.2  | -     | 0.9   | ns     | SDHC_CLK to SDHC_ CMD | -             |

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

## 16.11 Debug modules

## 16.11.1 JTAG Boundary Scan

The following table gives the JTAG specifications in boundary scan mode.

The SRE[2:0]=100 or SRE[2:0]=101 is required drive setting to meet the timing.

Table 67. JTAG Boundary Scan

| Symbol       | Description                          | Min   | Typ   | Max   | Unit   | Condition   |   Spec Number |
|--------------|--------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tJCYC        | TCK cycle time [1][2] [3]            | 100   | -     | -     | ns     | -           |             1 |
| tJDC         | TCK clock pulse width [1][3]         | 45    | -     | 55    | %      | -           |             2 |
| tTCKRISE     | TCK rise/fall time [1] [4]           | -     | -     | 3     | ns     | -           |             3 |
| tTMSS, tTDIS | TMS, TDI data setup time [1][5]      | 5     | -     | -     | ns     | -           |             4 |
| tTMSH, tTDIH | TMS, TDI data hold time [1][5]       | 5     | -     | -     | ns     | -           |             5 |
| tTDOV        | TCK low to TDO data valid [1][6][7]  | -     | -     | 17.5  | ns     | -           |             6 |
| tTDOI        | TCK low to TDO data invalid [1][7]   | 0     | -     | -     | ns     | -           |             7 |
| tTDOHZ       | TCK low to TDO high impedance [1][7] | -     | -     | 17.5  | ns     | -           |             8 |

Table continues on the next page...

Table 67. JTAG Boundary Scan...continued

| Symbol   | Description                                                   | Min   | Typ   | Max   | Unit   | Condition   |   Spec Number |
|----------|---------------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tJCMPPW  | JCOMP assertion time [1]                                      | 100   | -     | -     | ns     | -           |             9 |
| tJCMPS   | JCOMP setup time to TCK high [1]                              | 40    | -     | -     | ns     | -           |            10 |
| tBSDV    | TCK falling edge to output valid [1][7][8]                    | -     | -     | 600   | ns     | -           |            11 |
| tBSDVZ   | TCK falling edge to output valid out of high impedance [1][7] | -     | -     | 600   | ns     | -           |            12 |
| tBSDVHZ  | TCK falling edge to output high impedance [1][7]              | -     | -     | 600   | ns     | -           |            13 |
| tBSDST   | Boundary scan input valid to TCK rising edge [1]              | 15    | -     | -     | ns     | -           |            14 |
| tBSDHT   | TCK rising edge to boundary scan input invalid [1]            | 15    | -     | -     | ns     | -           |            15 |

- [1] These specifications apply to JTAG boundary scan mode only.
- [3] TCK pin must have an external pull down.
- [2] JTAG port interface speed only. Does not apply to boundary scan timing.
- [4] The TCK rise/fall time specification applies to the input clock transition required in order to meet the TDO output specifications that are relative to TCK.
- [6] Timing includes TCK pad delay, clock tree delay, logic delay and TDO output pad delay.
- [5] Input timing assumes an input signal slew rate of 3ns (20%/80%).
- [7] Output timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 5 inch microstrip trace on standard FR4 (1.5pF/inch), (25pF total with margin). For best signal integrity, the series resistance of the transmission line should be matched closely to the selected RDSON of the I/O pad output driver.
- [8] Applies to all pins, limited by pad slew rate. Refer to IO delay and transition specification and add 20 ns for JTAG delay.

<!-- image -->

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

<!-- image -->

S32G3 Data Sheet

<!-- image -->

## 16.11.2 JTAG Debug Interface Timing

The following table gives the JTAG specifications in debug interface mode.

## Table 68. JTAG Debug Interface Timing

Table continues on the next page...

| Symbol   | Description                                                             |   Min | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tTCYC    | Absolute minimum TCK cycle time (TDO sampled on posedge of TCK) [1] [2] |    50 | -     | -     | ns     | -           | -             |
| tTCYC    | Absolute minimum TCK cycle time (TDO sampled on negedge of TCK) [1] [2] |    25 | -     | -     | ns     | -           | -             |
| tJDC     | TCK clock pulse width                                                   |    45 | -     | 55    | %      | -           | -             |
| tNTDIS   | TDI data setup time [3]                                                 |     5 | -     | -     | ns     | -           | 11            |
| tNTDIH   | TDI data hold time [3]                                                  |     5 | -     | -     | ns     | -           | 12            |
| tNTMSS   | TMS data setup time                                                     |     5 | -     | -     | ns     | -           | 13            |
| tNTMSH   | TMS data hold time                                                      |     5 | -     | -     | ns     | -           | 14            |

Table 68. JTAG Debug Interface Timing...continued

| Symbol   | Description                                           | Min   | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|-------------------------------------------------------|-------|-------|-------|--------|-------------|---------------|
| tNTDOD   | TDO propagation delay from falling edge of TCK [4][5] | -     | -     | 17.5  | ns     | -           | 15            |
| tNTDOH   | TDO hold time with respect to falling edge of TCK [5] | 1     | -     | -     | ns     | -           | 16            |
| tTDOHZ   | TCK low to TDO high impedance [5]                     | -     | -     | 17.5  | ns     | -           | -             |

- [1] Maximum frequency for TCK is limited to 6MHz during BOOTROM startup of the device, when the system clock is the trimmed 48MHz FIRC.
- [3] Input timing assumes an input signal slew rate of 3ns (20%/80%).
- [2] TCK pin must have external pull down.
- [4] Timing includes TCK pad delay, clock tree delay, logic delay and TDO output pad delay.
- [5] Output timing valid for maximum external load CL = 25pF, which is assumed to be a 10pF load at the end of a 50Ohm, un-terminated, 5 inch microstrip trace on standard FR4 (1.5pF/inch), (25pF total with margin). For best signal integrity, the series resistance of the transmission line should be matched closely to the RDSON of the I/O pad output driver.

<!-- image -->

## 16.11.3 SWD electrical specifications

The following table describes the SWD electrical characteristics. Measurements are with maximum output load of 30pF, input transition of 1ns and pad configured SRE[2:0] =100.

S32G3 Data Sheet

## Table 69. SWD electrical specifications

| Symbol   | Description                                            | Min    | Typ   | Max   | Unit   | Condition   | Spec Number   |
|----------|--------------------------------------------------------|--------|-------|-------|--------|-------------|---------------|
| S1       | SWD_CLK frequency                                      | -      | -     | 33    | MHz    | -           | S1            |
| S2       | SWD_CLK cycle period                                   | 1 / S1 | -     | -     | ns     | -           | S2            |
| S3       | SWD_CLK pulse width                                    | 40     | -     | 60    | %      | -           | S3            |
| S4       | SWD_CLK rise and fall times                            | -      | -     | 1     | ns     | -           | S4            |
| S9       | SWD_DIO input data setup time to SWD_CLK rise          | 5      | -     | -     | ns     | -           | S9            |
| S10      | SWD_DIO input data hold time after SWD_CLK rising edge | 5      | -     | -     | ns     | -           | S10           |
| S11      | SWD_CLK high to SWD_DIO output data valid              | -      | -     | 22    | ns     | -           | S11           |
| S12      | SWD_CLK high to SWD_DIO output data hi-Z               | -      | -     | 22    | ns     | -           | S12           |
| S13      | SWD_CLK high to SWD_DIO output data invalid            | 0      | -     | -     | ns     | -           | S13           |

<!-- image -->

S32G3 Data Sheet

S32G3 Data Sheet

<!-- image -->

## 17 Pinouts

For package pinouts and signal descriptions, see device Reference Manual.

## 18 Packaging

The S32G3 is offered in the following package types.

| Package type   | Document number   |
|----------------|-------------------|
| 525-ball FCBGA | 98ASA01463D       |

Note: To find a package drawing, go to http://www.nxp.com and perform a keyword search for the drawing's document number or see below figures.

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

S32G3 Data Sheet

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

©

Figure 83. Package outline notes

S32G3 Data Sheet

## 19 Revision history

The following table lists the changes in this document.

| Document ID   | Release date      | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
|---------------|-------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| S32G3 v.4.0   | 29 September 2025 | • In features added OTFAD as supported. • In section "Ordering information" added new arm core speed identifier 'D' for 1400 MHz Cortex-A53 cores • In section "Operating conditions" updated fSYS_A53 from 1311 MHz to 1400 MHz. • In section "Clock frequency ranges" - Updated fA53_CORE_DIV2_CLK max from 655.5 MHz to 700 MHz - Updated fA53_CORE_DIV10_CLK max from 131.1 MHz to 140 MHz • In section "Total power specifications for 0.8V and 1.8V Analog Domains" added new power consumption entries for 1400 MHz across all S32G3 variants. • In section "Power-up" - updated sentence after "Step 5 and 6 can start before... - updated supply name from VDD_DDR_IO to VDD_IO_DDR. • In section "GPIO pads" extended footnote "Rise/fall time specifications are derived from simulation model... • SAR ADC Specification Characteristics figure is adjusted. • In section "FXOSC" ΔfXTAL_CLK (Input Clock Duty Cycle) is added. • In section "PLL": - updated fPLL_CORE_VCO from 2622 to 2800 MHz. - updated fPLL_CORE_PHI0 from 1311 to 1400 MHz. • In Section "LPSPI" used inclusive language to replace Master - Slave with Controller - Peripheral. • In section uSDHC: - represented rise and fall times in the figures. - This footnote is updated to add "signal", Input signal timing assumes an input signal slew rate of 3ns (20%/80%). - updated figure references in uSDHC SD3.0/eMMC5.1 DDR - In "uSDHC SDR-HS200" removed footnote "Input timing also applicable for SDHC_CMD also" and updated condition of tODW to add SDHC_DAT / SDHC_CMD. - In "uSDHC DDR-HS400" added seperate rows for tRQ for DATA and CMD. |
| S32G3 v.3.0   | October 2024      | • In section "Absolute Max Ratings" :                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
|---------------|----------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | - Removed duplicate spec "IINJ_LVDS" - Updated footnote "functional operation at the maxima..." to "functional operation beyond the operating condition..." • In Operating conditions added footnote "Applies only during power up while POR_B is asserted." , "Applies to multi-voltage supplies when operating in 1.8V range." and "Applies to multi-voltage supplies when operating in 3.3V range". • In Clock Frequency ranges updated "max value" to 50 MHzof spec "fSDHC_CLK" with condition "SDHC_CLK-DDR/SDR 52MHz" • "Power-up" Table moved from Power-Up to Power-Down section. • In GPIO pads : - Removed spec "RDSON_33, IOH_33, TR_TF_33" with condition "SRE[2:0]=000" - Updated footnote "On standard FR4 with approximately 1.5pF/inch" to "3.3pF/inch". • In FXOSC, updated the condition of spec "TCST" • In section "PLL": - Updated "System PLL" to "PLL" in table and footnote. • "SRE condition" is removed from modules, and mentioned at the top of the table • In section "I2C input": - added operating speed specs with symbol "Rate" - added information "I2C interface supports Fast Mode with a maximum data-rate of 400kbps. Higher data rates are not supported" • In section "I2C Output": - updated the max value of "tRISE" to 300ns - removed the footnote "Programming IBFD (I2C bus Frequency Divider) with the maximum frequency results in the minimum output timings listed...." and mentioned it at the top of table. • In LPSPI, updated "tHO" with conditon "Data hold time input" to "tHI". • In "QuadSPI", updated information from "All transitions measured at mid-supply (VDD_IO_QSPI/2).." to "Data transitions measured at 30%/70% supply for the write path. Data transitions...." • In "QuadSPI Quad 1.8V SDR 133MHz" and "QuadSPI Octal 1.8V SDR 133MHz": - For spec "fSCK", updated condition from DLL mode enabled to DLL Bypass Mode. • In "QuadSPI Octal 1.8V DDR 133MHz", "QuadSPI Quad 1.8V SDR 133MHz" and "QuadSPI Octal 1.8V SDR 133MHz" : |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|---------------|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | - Added footnote "fSCK of 133.33MHz is also acceptable" • In section "QuadSPI Timing diagrams", updated diagrams. • In "uSDHC" section, updated information from "All uSDHC parameters are measured at mid-supply (VDD_IO_SDHC/2)" to "Data transitions measured at 35%/65% supply for the write path. Data transitions measured at mid-supply for the read path. Clock transitions measured at mid..." • In "uSDHC DDR-HS400" : - Added new specs "trQ (input skew CMD)" and "tRQH(Hold skew CMKD)"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| S32G3 v.2.0   | February 2023  | • In section "Absolute Max Ratings", updated figure titlt to match with specifications "Input overshoot/undershoot voltage for each GPIO pad type". • In section "Operating conditions", added note to Tj and Ta as "The junction temperature (Tj) range specification...". • In section "Operating conditions", added figure "ADC supply sequencing". • In section "GPIO pads": - for TR_TF_33 with SRE[2:0] = 100 changed min from 1.75V to 1.90V. - for TR_TF_33 with SRE[2:0] = 101 changed min from 0.05V to 1.00V and max changed from 8.25V to 8.50V. - for TR_TF_33 with SRE[2:0] = 110 changed min from 0.01V to 0.50V and max changed from 7.0V to 7.30V. - for TR_TF_33 with SRE[2:0] = 111 changed min from 0.005V to 0.04V and max changed from 5.5V to 6.0V. • In section "SAR ADC", paragraph at top of table is updated to mention from "...capacitance at the input pin should..." to "...capacitance at the input pin and reference pin should...". • In section "Temperature Monitoring Unit (TMU)", updated TRANGE min as -45 and max as 130 and added a footnote "Accuracy outside of operating range (-40 to 125) is not guaranteed.". • In section "FXOSC", added paragraph as "In ALC disable mode the minimum...". • In section "PLL", added footnote to fPLL_DDR_PHI0 as "DDR PLL allows center-spread SSCG at...". • In section "PLL", added footnotes to Jitter specifications to mention jitter dependancy. • In section "FlexRay - RxD", deleted uCCLogic_1 and uCCLogic_2 specifications. • In section "PCIe", updated paragraph "NXP internally does PCI-SIG TX...". • In section "QuadSPI Octal 1.8V DDR 166MHz": |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
|---------------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | - Updated voltage measurement levels "Data transitions measured at 30%/70% supply...". - Updated tIH_DQS min from 2.145 ns to 2.105 ns - Updated tISU_DQS min from -0.496 ns to -0.616 ns • In section "QuadSPI Octal 1.8V DDR 200MHz": - Updated voltage measurement levels "Data transitions measured at 30%/70% supply...". - Updated SRE "In Single SRE configuration...". - Updated tOD_DATA for single and split SRE configurations. - Updated tIH_DQS min from 1.684 ns to 1.644 ns. - Updated tISU_DQS min from -0.466 ns to -0.586 ns. • In section "QuadSPI configurations" SMPR[DLLFSMPF] is updated to 4 for 166 MHz. • In section "uSDHC DDR-HS400": - Updated SRE "In Split SRE configuration SRE[2:0]=000...". - Updated voltage measurement levels "Data transitions measured at 35%/65% supply...". - Updated tCL and tCH min to 2.35 ns. - Updated descriptions of tOD1 and tOD2 and updated its value to 0.65 ns. - Added tOD (uSDHC Output delay). • Added package drawing. • Datasheet classification updated to "Technical Data". |
| S32G3 v.2.C   | September 2022 | • In "Absolute Max Ratings" - Added note "All specifications associated with VIN are measured at the SoC pin.". - Added spec Max LVDS RX or TX pin injection (IINJ_LVDS) - VIN specification: ◦ updated footnote "Absolute maximum DC VIN levels for a powered...". ◦ Added V_OS_US_10 for 1.8V and updated condition of overshoot and undershoot specifications. ◦ Added footnote "DC case limit. Overshoot/Undershoot beyond this range...". - For Overshoot/Undershoot specs updated footnote, "For AC Signals in a 3.3V supply domain, if...". • In section "Operating Conditions" Added footnoted to VIN_18 and VIN_33 "DC case limit. Overshoot/Undershoot beyond this range...".                                                                                                                                                                                                                                                                                                                                                                 |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
|---------------|----------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | • In section "Operating Conditions" IINJ_D is split into powered and unpowered and related footnotes added.". • In section "Clock frequency ranges" added fSDHC_CLK for DDR HS400. • In section "Device Power and Operating Current Specifications", for PVDD_STBY in condition corrected a typographic figure from VDD=0.8V, to VDD_STBY = 0.8V. • Added section "Power-down". • In section "Aurora PLL" added footnote to fPLL_CLKIN as "40MHz is the only internal input reference..". • In section "Reset Duration" added a paragraph as "The durations specified "Reset Duration" table and the corresponding figures...." and addded below three figures: - Reset_b pad detailed behavior during core supply brownout - Reset_b pad detailed behavior during pad HV supply brownout - Reset_b pad detailed behavior during power down • Below figure "RESET_B pad detailed behavior", added information as "he RESET_B pad behavior described in the diagram and the related VRSE_RESET_B parameter spec also apply to the case of core VDD droop after power-up.". • In section "SIRC", PTA description changed from "SIRC Post Trim Accuracy" to "SIRC trimming resolution" and "SIRC Frequency Variation" condition updated to "Frequency variation across voltage and temperature range". • In section "I2C" PER_CLK changed to MODULE_CLK. • Added section "CAN". • In QuadSPI sections, removed DQS and added condition as "fSCK duty cycle distortion is in the range of 45%-55%." • In uSDHC: - Changed title from "uSDHC DDR-52MHz" to "uSDHC SD3.0/eMMC5.1 DDR" and from "uSDHC SDR-52MHz" to "uSDHC SD3.0/SDIO3.0/ eMMC5.1 SDR" and other figure name updates. - In uSDHC added phrase as "All uSDHC parameters are measured at mid-supply (VDD_IO_SDHC/2)." - In "SDR-100 Mode Interface Timing" figure deleted SD5 and SD8. - In section "uSDHC SDR-HS200" added footnote to tODW as "Input timing also applicable for SDHC_CMD also.". - In "uSDHC DDR-HS400" added footnote to tRQ and tRQH as "Spec numbers SD6 and SD7 are also applicable for the CMD input timing for HS400 mode...". - Deleted some redundant figures. |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
|---------------|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| S32G3 v.2.B   | May 2022       | • In "GMAC and PFE RGMII" section added paragraph "You must set SRE[2:0]=101 for PFE_MAC0_TX_CLK in RGMII mode of PFE GMAC0 at 3.3V."                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| S32G3 v.2.A   | April 2022     | • In "Block diagram" mentioned that the diagram represents the features of S32G399A, the superset chip in the S32G3 family. • In section "Absolute maximum ratings": - Changed from ADC reference supply to ADC supply for "VAD_INPUT", min value changed from "VREFL_ADC - 0.6" to "VSS_ADC - 0.6" and max value changed from "VREFH_ADC + 0.5" to "VDD_ADC + 0.5". - Added more information to below footnotes attached to VIN: ◦ Absolute maximum DC VIN levels for a powered device.... ◦ Absolute minimum DC VIN level for a powered device is.... - Footnote attached to "IINJ_A" changed to "Allowed for a cumulative duration of 50 hours operation over the lifetime of the device at maximum Tj, with VDD_ADC <= 1.92V, VSS_ADC = 0V". - Added symbol names and footnote to overshoot specifications as "For AC signals, if VDD_IO ≤ 3.3V, max VIN overshoot is limited to...." • In section "Operating Conditions": - Changed from ADC reference supply to ADC supply for "VAD_INPUT", min value updated from "VREFL_ADC - 0.35" to "VSS_ADC - 0.35" and max value updated from "VREFH_ADC + 0.25" to "VDD_ADC + 0.25". - Footnote attached to frequency specs updated to correct the modulation depth used in formula. Changed "...plus the modulation depth (max 1.5%) ..." to "...plus half the modulation depth...". - For "VDD_EFUSE" specs, updated related footnote to add "See device hardware design guidelines document for more details." - Updated below footnotes attached to VIN_18 and VIN_33: ◦ From: "Additional +0.3V are supported for DC signal." to "For AC signals, allowed max VIN ≤ VDD_IO* for lifetime operation. If AC....". ◦ From: "Absolute minimum level for VIN signal is -0.3V." to "The min DC VIN level for a powered device is -0.3V. If AC.....". - Footnote attached to "VRAMP_LV" is updated "On slow ramps, the RESET_B pin may be observed to be asserted..." • Total power specifications updated for S32G398A (thermal use case) changed from 8.18 to 8.35 A, S32G379A (thermal use case) changed from 7.46 to 8.08 W, S32G378A (thermal use case) changed from 7.24 to 8.02 W. • In "Total power specifications" for 1.8V supply rail added in condition "All 1.8V supplies at 1.8V". |

Table continues on the next page...

Table continued from the previous page...

| Document ID   |              | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
|---------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               | Release date | • Max values updated for the specs in section "Static power specifications for I/O Domains" • In section "Device Power and Operating Current Specifications" : - For symbol "PVDD_STBY", typ value changed from 48 to 58 uW. - For symbol "PVDD_IO_STBY", typ value changed from 120 to 110 uW. • In section "Device Power and Operating Current Specifications" for symbol "PVDD_IO_PCIEn" (Powered down state), max value changed from 1.4 to 1.5 mW. • In section "Device Power and Operating Current Specifications" for symbol "PVDD_IO_PCIEn" with condition "All circuits enabled, VDD_IO_PCIEn=1.8V, Gen3 8Gbps, 2 lanes. Per IP instance", added footnote "This specification can be considered a worst case maximum..." • In section "GPIO Pads", added symbols "VOL" and "VOH" and added a footnote attached to these symbols "For current at this voltage see IOL/IOH specs respectively". • Removed a note "VOH/VOL values should be calculated based on the provided RDSON, IOH/IOL values and IBIS models" . • In figure "1.8V/3.3V GPIO pad detailed behavior during power up", updated "weak pull-down" to "weak pull-down as per ILKG_3318 specification". • Under the figure "1.8V/3.3V GPIO pad detailed behavior during power up", removed the paragraph "The weak pull-down is 100 Kohm and is separate from the usual selectable 12Kohm internal pull resistor…." • In section "SAR ADC" , for symbol "VAD_INPUT" min value changed to "VSS_ADC" and max value changed to "VDD_ADC". • In section "DFS", added symbol "PER_Jitter" with min value -30ps and max value 30ps with condition fDFS_CLKIN=2622 Mhz, Odd MFN. • In section "PLL" : - Added symbol "fPLL_DDR_PHI0" with description "DDR PLL PHI0 Frequency" and min, max value 758 Mhz and condition DDR_CLK (3032MT/s). - Footnote "PLL refers to the Core, Peripheral, Accelerator, and DDR reference PLLs on the device" and "Spread spectrum clock modulation is only available on the Core, Accelerator and DDR reference PLLs" moved to the top of the section. - The formula for calculating the max frequency is updated in the related footnote "The max frequency in case of center-spread SSCG enabled for a modulation....". • In PCIe specications external reference clock pins related specs are added. • In section "GMAC and PFE SGMII", For symbol UI the description updated to "Unit interval (mean)". |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
|---------------|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | • Added sentence "All transitions measured at mid-supply (VDD_IO_QSPI/2)" and removed "Clock measurements done with respect to VDD_IO_QSPI/2 level" in all QuadSPI modes. • Removed symbol "tDVW" from the following sections: - "QuadSPI Quad 1.8V SDR 133MHz" - "QuadSPI Octal 1.8V DDR 100MHz" - "QuadSPI Octal 1.8V DDR 133MHz" - "QuadSPI Octal 1.8V DDR 166MHz" - "QuadSPI Octal 1.8V DDR 200MHz" - "QuadSPI Octal 1.8V SDR 100MHz" - "QuadSPI Octal 1.8V SDR 133MHz" - "QuadSPI Quad 3.3V SDR 104MHz" • Added introduction sentence "The information in this section applies to Octal- and Hyperflash" in following sections : - QuadSPI Octal 1.8V DDR 100MHz - QuadSPI Octal 1.8V DDR 133MHz - QuadSPI Octal 1.8V DDR 166MHz • In section "QuadSPI configurations", added introduction "The below table shows a subset of the QuadSPI module configurations for different speeds and data rate….". • In section "QuadSPI configurations", updated SMPR[DLLFSMPF] setting for DDR-200MHz from 4 to 3. • In section "DDR", updated the sentence to "LPDDR4 SDRAM compliant to JEDEC209-4B LPDDR4 JEDEC standard release." • In section "DDR Common DC Output", for symbol "ROnPu" and "ROnPd", in description CLK changed to CKE outputs and footnote attached to them updated as "For the DDR0_RESET_B pin and CKE pin…." • Added section "DDR3L DC Input Timing". • Section name changed from "LPDDR4 DC Input" to "LPDDR4 DC Input Timing" and from "LPDDR4 Output" to "LPDDR4 Output Timing". • Section "uSDHC DDR-HS400" updated thoroughly. |
| S32G3 v.1.0   | Novemver 2021  | • Updated datasheet classification to "Advance information" • Updated Introduction, Feature comparison. • In section "Absolute Max Ratings" and "Operating conditions", VDD_LV_PLL is deleted as it is shorted with VDD inside the die and this supply no longer needs to be driven from outside.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
|---------------|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | • In section "Absolute Max Ratings", for Symbol "VAD_INPUT" Min changed from "-0.3" to "VREFL_ADC -0.6". • In section "Absolute Max Ratings", for Symbol "VAD_INPUT" Max changed from "VREFH_ADC" to "VREFH_ADC + 0.5". • In section "Absolute Max Ratings", for Symbol "VAD_INPUT" footnote added "Allowed for a cumulative duration of 50 ...". • In section "Absolute Max Ratings" two footnotes attached to VIN are updated: - Absolute maximum VIN levels ... - Absolute minimum VIN level for ... • In section "Absolute Max Ratings", for Symbol "IINJ_A" Min changed from "-2" to "-1". • In section "Absolute Max Ratings", for Symbol "IINJ_A" Max changed from "2" to "1". • In section "Absolute Max Ratings" in a footnote attached to IINJ_A "Non-disturb of ADC channels during current ...." • In section "Operating Conditions", added note "ΔVDD* specifications are applicable to the supplies mentioned ...". • In section "Operating Conditions", for Symbol "fSYS_A53" Max changed from "1100" to "1311". • In section "Operating Conditions", SVS feature is removed. • In section "operating conditions" removed "ΔVDD_IO_DDR" differential as this has a lone supply in its condition. • In section "Operating Conditions", Symbol "VRAMP_HV" is seperated for 1.8V and 3.3V IOs and 3.3V IOs limit is updated to 50V/ms. • In section "Operating Conditions", for Symbol "VAD_INPUT" Min changed from "VREFL_ADC" to "VREFL_ADC - 0.35". • In section "Operating Conditions", for Symbol "VAD_INPUT" Max changed from "VREFH_ADC" to "VREFH_ADC + 0.25". • In section "Operating Conditions", for Symbol "IINJ_A" Min changed from "-1 mA" to "-20 uA". • In section "Operating Conditions", for Symbol "IINJ_A" Max changed from "1 mA" to "20 uA". • In section "Operating Conditions", for Symbol "IINJ_A" footnote updated "The SAR ADC electrical specifications ar...". • In section "Operating conditions" for symbol "ΔVDD_HV_18_ANA" added footnotes to clarify VDD_EFUSE supply conditions and added another footnote to say "VREFH_ADCn has a differential voltage of +/-100mV.". • In section "Operating Conditions", for "LPDDR4 I/O voltage supply" typ value added as 1.1V. |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
|---------------|----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | • In section "Operating Conditions", footnote attached to IINJ_D is updated "IINJ_D specifications are per pin for an unpowered..." and removed one "GPIO electrical specifications and ...". • In section "Operating Conditions", added paragraph "The device hardware design guide summarizes ...". • In section "Clock frequency ranges", removed some non applicable clocks. • In section "Clock frequency ranges", for Symbol fA53_CORE_DIV2_CLK is updated to 655.5 MHz. • In section "Clock frequency ranges", for Symbol fA53_CORE_DIV10_CLK is updated to 131.1 MHz. • In section "Clock frequency ranges", for Symbol fXBAR_2X_CLK min added as 48 MHz. • In section "Clock frequency ranges", for Symbol fPFE_MAC_2_TX_CLK and fPFE_MAC_2_RX_CLK max updated to 312.5 MHz. • In section "Clock frequency ranges", for Symbol fSDHC_CLK min updated to 133 MHz. • In section "Thermal Characteristics", added values. • In section "Total power specifications for 0.8V and 1.8V Analog Domains", added 0.8V values. • In section "power sequencing" updated steps 3 and 4 and added note "For step 4, it is acceptable for the 1.8V ..." • In section "Power sequencing", added a figure "1.8V supply timing with respect to PMIC_VDD_OK during Standby Mode Exit". • In section "Aurora Pads", Symbol "VCM_LVDS_RX" and "VDIFF_LVDS_RX"is added. • In section "PMC Bandgap", values added. • In section "SAR ADC", added footnote to VAD_INPUT "The reduced limits for VAD_INPUT ....". • In section "DFS", Symbol "fDFS_CORE_CLK2" and "fDFS_PER_CLK5" are removed. • In section "DFS", formula is moved from footnote to sentence with some clarifications. • In section "DFS", for Symbol "fDFS_PER_CLK2" max updated to 628 MHz and fDFS_CLKIN max updated to 2622 MHz. • In section "FXOSC", added specs "VIH_EXTAL", "VIL_EXTAL", "CLOAD", "VCM_SE" • In section "FXOSC", removed differential bypass mode specs which includes fBYP_DIFF and related figure. |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
|---------------|----------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|               |                | • In section "PLL", removed ΔfPLL_MOD spec and all specs "with center-spread enabled" in conditon column. Added a footnote to specs which have "without center-spread enabled" in the condition column as "The max frequency in case of center-spread SSCG...". • In section "PLL" added footnote to fPLL_CORE_VCO, fPLL_ACCEL_VCO and fPLL_DDR_VCO as "Same min frequency value applies for center-spread...". • In section "PLL", for Symbol "fPLL_CORE_VCO" with condition "without center- spread SSCG enabled" Max changed from "2600" to "2622". • In section "PLL", for Symbol "fPLL_PER_PHI5" with condition "PERIPH_PLL_PHI5" Max changed from "500" to "125". • In section "PLL", for Symbol "fPLL_ACCEL_VCO" with condition "without center- spread SSCG enabled" Max changed from "2436" to "2400". • In section "PLL", for Symbol "fPLL_CORE_PHI0" max updated to 1311 MHz. • In section "SPI", for Symbol "tSUI" with condition "Master, MTFE=1, CPHA=0, SMPL_PTR = 1" footnote value added "N is number of protocol clock cycles whe...". • In section "FlexRay - TxD", a missing spec is added "dCCTxD10". • In all QuadSPI modes, moved footnote "Clock measurements done with respect to VDD_IO_QSPI/2 level." to top of the table • In section "QuadSPI Quad 1.8V DDR 66MHz", Symbol "tISU_SCK" and "tIH_SCK" are deleted. • In section "QuadSPI Quad 1.8V DDR 66MHz" added tLSKEW. • In section "QuadSPI Octal 1.8V DDR 100MHz", Symbol "tCK2CKmin", "tCK2CKmax", "tIH_PCS" and "tISU_PCS" are deleted. • In section "QuadSPI Octal 1.8V DDR 133MHz", Symbol "tCK2CKmin" and "tCK2CKmax" are deleted. • In section "QuadSPI Quad 3.3V DDR 66MHz", Symbol "tISU_SCK" and "tIH_SCK" are deleted. • In section "QuadSPI Quad 3.3V DDR 66MHz", Symbol "tLSKEW" is added. • In section "QuadSPI Octal 1.8V DDR 166MHz/200MHz", updated SRE. • In all QuadSPI sections updated TCSS and TCSH value is updated to 3. • Section "QuadSPI interfaces" and "QuadSPI configurations" are updated. • In section DDR, added paragraph "DDR operation with the standards stated..." and "LPDDR4 routing constraints are documented ..." • In section "uSDHC DDR-HS400" added min value to 133 MHz. • In section "JTAG Boundary Scan", updated "The SRE[2:0]=100 or SRE[2:0]=101 is required drive setting to meet the timing.". • In section "SWD electrical specifications", SRE updated to SRE[2:0]=100. |

Table continues on the next page...

Table continued from the previous page...

| Document ID   | Release date   | Description                                                                              |
|---------------|----------------|------------------------------------------------------------------------------------------|
|               |                | • Added section "Packaging". • Updated "Security" and "Suitability for use" disclaimers. |
| S32G3 v.1.E   | July 2021      | • Subsequent updates throughout the data sheet.                                          |
| S32G3 v.1.D   | April 2021     | • Subsequent updates throughout the data sheet.                                          |
| S32G3 v.1.C   | January 2021   | • Subsequent updates throughout the data sheet.                                          |
| S32G3 v.1.B   | April 2020     | • Subsequent updates throughout the data sheet.                                          |
| S32G3 v.1.A   | February 2020  | • Initial release.                                                                       |

S32G3 Data Sheet

## Legal information

## Data sheet status

| Document status [1][2]         | Product status [3]   | Definition                                                                            |
|--------------------------------|----------------------|---------------------------------------------------------------------------------------|
| Objective [short] data sheet   | Development          | This document contains data from the objective specification for product development. |
| Preliminary [short] data sheet | Qualification        | This document contains data from the preliminary specification.                       |
| Product [short] data sheet     | Production           | This document contains the product specification.                                     |

- [1] Please consult the most recently issued document before initiating or completing a design.

[3] The product status of device(s) described in this document may have changed since this document was published and may differ in case of multiple devices. The latest product status information is available on the Internet at URL https://www.nxp.com.

[2] The term 'short data sheet' is explained in section "Definitions".

## Definitions

Draft - A draft status on a document indicates that the content is still under internal review and subject to formal approval, which may result in modifications or additions. NXP Semiconductors does not give any representations or warranties as to the accuracy or completeness of information included in a draft version of a document and shall have no liability for the consequences of use of such information.

Short data sheet - A short data sheet is an extract from a full data sheet with the same product type number(s) and title. A short data sheet is intended for quick reference only and should not be relied upon to contain detailed and full information. For detailed and full information see the relevant full data sheet, which is available on request via the local NXP Semiconductors sales office. In case of any inconsistency or conflict with the short data sheet, the full data sheet shall prevail.

Product specification - The information and data provided in a Product data sheet shall define the specification of the product as agreed between NXP Semiconductors and its customer, unless NXP Semiconductors and customer have explicitly agreed otherwise in writing. In no event however, shall an agreement be valid in which the NXP Semiconductors product is deemed to offer functions and qualities beyond those described in the Product data sheet.

## Disclaimers

Limited warranty and liability - Information in this document is believed to be accurate and reliable. However, NXP Semiconductors does not give any representations or warranties, expressed or implied, as to the accuracy or completeness of such information and shall have no liability for the consequences of use of such information. NXP Semiconductors takes no responsibility for the content in this document if provided by an information source outside of NXP Semiconductors.

In no event shall NXP Semiconductors be liable for any indirect, incidental, punitive, special or consequential damages (including - without limitation lost profits, lost savings, business interruption, costs related to the removal or replacement of any products or rework charges) whether or not such damages are based on tort (including negligence), warranty, breach of contract or any other legal theory.

Notwithstanding any damages that customer might incur for any reason whatsoever, NXP Semiconductors' aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms and conditions of commercial sale of NXP Semiconductors.

Right to make changes - NXP Semiconductors reserves the right to make changes to information published in this document, including without limitation specifications and product descriptions, at any time and without notice. This document supersedes and replaces all information supplied prior to the publication hereof.

S32G3 Data Sheet

Applications - Applications that are described herein for any of these products are for illustrative purposes only. NXP Semiconductors makes no representation or warranty that such applications will be suitable for the specified use without further testing or modification.

Customers are responsible for the design and operation of their applications and products using NXP Semiconductors products, and NXP Semiconductors accepts no liability for any assistance with applications or customer product design. It is customer's sole responsibility to determine whether the NXP Semiconductors product is suitable and fit for the customer's applications and products planned, as well as for the planned application and use of customer's third party customer(s). Customers should provide appropriate design and operating safeguards to minimize the risks associated with their applications and products.

NXP Semiconductors does not accept any liability related to any default, damage, costs or problem which is based on any weakness or default in the customer's applications or products, or the application or use by customer's third party customer(s). Customer is responsible for doing all necessary testing for the customer's applications and products using NXP Semiconductors products in order to avoid a default of the applications and the products or of the application or use by customer's third party customer(s). NXP does not accept any liability in this respect.

Limiting values - Stress above one or more limiting values (as defined in the Absolute Maximum Ratings System of IEC 60134) will cause permanent damage to the device. Limiting values are stress ratings only and (proper) operation of the device at these or any other conditions above those given in the Recommended operating conditions section (if present) or the Characteristics sections of this document is not warranted. Constant or repeated exposure to limiting values will permanently and irreversibly affect the quality and reliability of the device.

Terms and conditions of commercial sale - NXP Semiconductors products are sold subject to the general terms and conditions of commercial sale, as published at https://www.nxp.com/profile/terms, unless otherwise agreed in a valid written individual agreement. In case an individual agreement is concluded only the terms and conditions of the respective agreement shall apply. NXP Semiconductors hereby expressly objects to applying the customer's general terms and conditions with regard to the purchase of NXP Semiconductors products by customer.

No offer to sell or license - Nothing in this document may be interpreted or construed as an offer to sell products that is open for acceptance or the grant, conveyance or implication of any license under any copyrights, patents or other industrial or intellectual property rights.

Quick reference data - The Quick reference data is an extract of the product data given in the Limiting values and Characteristics sections of this document, and as such is not complete, exhaustive or legally binding.

Export control - This document as well as the item(s) described herein may be subject to export control regulations. Export might require a prior authorization from competent authorities.

S32G3 Data Sheet

HTML publications - An HTML version, if available, of this document is provided as a courtesy. Definitive information is contained in the applicable document in PDF format. If there is a discrepancy between the HTML document and the PDF document, the PDF document has priority.

Translations - A non-English (translated) version of a document, including the legal information in that document, is for reference only. The English version shall prevail in case of any discrepancy between the translated and English versions.

Security - Customer understands that all NXP products may be subject to unidentified vulnerabilities or may support established security standards or specifications with known limitations. Customer is responsible for the design and operation of its applications and products throughout their lifecycles to reduce the effect of these vulnerabilities on customer's applications and products. Customer's responsibility also extends to other open and/or proprietary technologies supported by NXP products for use in customer's applications. NXP accepts no liability for any vulnerability. Customer should regularly check security updates from NXP and follow up appropriately.

Customer shall select products with security features that best meet rules, regulations, and standards of the intended application and make the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP.

NXP has a Product Security Incident Response Team (PSIRT) (reachable at PSIRT@nxp.com) that manages the investigation, reporting, and solution release to security vulnerabilities of NXP products.

Suitability for use in automotive applications (functional safety) - This NXP product has been qualified for use in automotive applications. It has been developed in accordance with ISO 26262, and has been ASIL classified accordingly. If this product is used by customer in the development of, or for incorporation into, products or services (a) used in safety critical applications or (b) in which failure could lead to death, personal injury, or severe physical or environmental damage (such products and services hereinafter referred to as 'Critical Applications'), then customer makes the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, safety, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP. As such, customer assumes all risk related to use of any products in Critical Applications and NXP and its suppliers shall not be liable for any such use by customer. Accordingly, customer will indemnify and hold NXP harmless from any claims, liabilities, damages and associated costs and expenses (including attorneys' fees) that NXP may incur related to customer's incorporation of any product in a Critical Application.

NXP B.V. - NXP B.V. is not an operating company and it does not distribute or sell products.

## Trademarks

Notice: All referenced brands, product names, service names, and trademarks are the property of their respective owners.

NXP - wordmark and logo are trademarks of NXP B.V.

AMBA, Arm, Arm7, Arm7TDMI, Arm9, Arm11, Artisan, big.LITTLE, Cordio, CoreLink, CoreSight, Cortex, DesignStart, DynamIQ, Jazelle, Keil, Mali, Mbed, Mbed Enabled, NEON, POP, RealView, SecurCore, Socrates, Thumb, TrustZone, ULINK, ULINK2, ULINK-ME, ULINK-PLUS, ULINKpro, μVision,

Versatile - are trademarks and/or registered trademarks of Arm Limited (or its subsidiaries or affiliates) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved.

Airfast - is a trademark of NXP B.V.

CodeWarrior - is a trademark of NXP B.V.

ColdFire - is a trademark of NXP B.V.

ColdFire+ - is a trademark of NXP B.V.

CoolFlux - is a trademark of NXP B.V.

CoolFlux DSP - is a trademark of NXP B.V.

DESFire - is a trademark of NXP B.V.

EdgeLock - is a trademark of NXP B.V.

EdgeVerse - is a trademark of NXP B.V.

eIQ - is a trademark of NXP B.V.

GreenChip - is a trademark of NXP B.V.

HITAG - is a trademark of NXP B.V.

ICODE - is a trademark of NXP B.V.

Immersiv3D - is a trademark of NXP B.V.

I2C-bus - logo is a trademark of NXP B.V.

Kinetis - is a trademark of NXP B.V.

<!-- image -->

S32G3 Data Sheet

Layerscape - is a trademark of NXP B.V.

MagniV - is a trademark of NXP B.V.

Mantis - is a trademark of NXP B.V.

MIFARE - is a trademark of NXP B.V.

MIFARE Classic - is a trademark of NXP B.V.

MIFARE4Mobile - is a trademark of NXP B.V.

MIFARE Plus - is a trademark of NXP B.V.

MIFARE Ultralight - is a trademark of NXP B.V.

MiGLO - wordmark and logo are trademarks of NXP B.V.

NTAG - is a trademark of NXP B.V.

PEG - is a trademark of NXP B.V.

Processor Expert - is a trademark of NXP B.V.

QorIQ - is a trademark of NXP B.V.

QorIQ Qonverge - is a trademark of NXP B.V.

RoadLINK - wordmark and logo are trademarks of NXP B.V.

SafeAssure - is a trademark of NXP B.V.

SafeAssure - logo is a trademark of NXP B.V.

Synopsys &amp; Designware - are registered trademarks of Synopsys, Inc.

Synopsys - Portions Copyright  ©  2018-2022 Synopsys, Inc. Used with permission. All rights reserved.

Tower - is a trademark of NXP B.V.

UCODE - is a trademark of NXP B.V.

VortiQa - is a trademark of NXP B.V.

<!-- image -->

## Contents

| 1             | Introduction.........................................................2                                                                        |    | 16.3.5          | LPSPI...............................................................                                                             | 69   |
|---------------|-----------------------------------------------------------------------------------------------------------------------------------------------|----|-----------------|----------------------------------------------------------------------------------------------------------------------------------|------|
| 1.1           | Overview............................................................                                                                          | 2  | 16.3.6          | CAN..................................................................72                                                          |      |
| 1.2           | Applications........................................................2                                                                         |    | 16.4            | FlexRay............................................................                                                              | 72   |
| 2             | Block diagram.....................................................3                                                                           |    | 16.4.1          | FlexRay - RxD..................................................72                                                                |      |
| 3             | Feature comparison...........................................                                                                                 | 3  | 16.4.2          | FlexRay - TxD..................................................                                                                  | 73   |
| 4             | Ordering information...........................................6                                                                              |    | 16.4.3          | FlexRay - TxEN................................................74                                                                 |      |
| 5             | Electrostatic Discharge (ESD) Characteristics...7                                                                                             |    | 16.9            | PCIe.................................................................                                                            | 75   |
| 6             | Absolute Maximum Ratings................................7                                                                                     |    | 16.6            | GMAC and PFE................................................78                                                                   |      |
| 7             | Operating conditions........................................                                                                                  | 11 | 16.6.1          | GMAC and PFE Management Interface...........78                                                                                   |      |
| 7.1           | Operating Conditions........................................11                                                                                |    | 16.6.2          | GMAC and PFE MII..........................................79                                                                     |      |
| 7.2           | Clock frequency ranges....................................16                                                                                  |    | 16.6.3          | GMAC MII 50MHz............................................                                                                       | 81   |
| 8             | Thermal Characteristics...................................                                                                                    | 19 | 16.6.4          | GMAC and PFE RMII.......................................82                                                                       |      |
| 9             | DC electricals...................................................                                                                             | 20 | 16.6.5          | GMAC and PFE RGMII....................................                                                                           | 83   |
| 9.1           | Total power specifications for 0.8V and 1.8V                                                                                                  |    | 16.6.6          | GMAC and PFE SGMII....................................                                                                           | 85   |
|               | Analog Domains...............................................20                                                                               |    | 16.12           | USB-ULPI.........................................................86                                                              |      |
| 9.2           | Static power specifications for I/O Domains.....23                                                                                            |    | 16.8            | Memory interfaces............................................87                                                                  |      |
| 9.3           | Device Power and Operating Current                                                                                                            |    | 16.8.1          | QuadSPI...........................................................87                                                             |      |
|               | Specifications...................................................                                                                             | 24 | 16.8.2          | QuadSPI Quad 1.8V DDR 66MHz...................                                                                                   | 87   |
| 10            | Power sequencing............................................28                                                                                |    | 16.8.3          | QuadSPI Octal 1.8V SDR 133MHz..................88                                                                                |      |
| 10.1          | Power-up..........................................................28                                                                          |    | 16.8.4          | QuadSPI Octal 1.8V DDR 100MHz..................88                                                                                |      |
| 10.2          | Power-down.....................................................                                                                               | 29 | 16.8.5          | QuadSPI Octal 1.8V DDR 133MHz..................89                                                                                |      |
| 11            | Electromagnetic compatibility (EMC)...............                                                                                            | 29 | 16.8.6          | QuadSPI Octal 1.8V SDR 100MHz..................90                                                                                |      |
| 12            | GPIO Pads.......................................................                                                                              | 29 | 16.8.7          | QuadSPI Quad 1.8V SDR 133MHz..................90                                                                                 |      |
| 13            | Aurora specifications........................................39                                                                               |    | 16.8.8          | QuadSPI Quad 3.3V DDR 66MHz...................                                                                                   | 91   |
| 13.1          | Aurora Pads.....................................................                                                                              | 39 | 16.8.9          | QuadSPI Quad 3.3V SDR 104MHz..................92                                                                                 |      |
| 13.2          | Aurora Port Timing...........................................                                                                                 | 41 | 16.8.10         | QuadSPI Octal 1.8V DDR 166MHz..................92                                                                                |      |
| 13.3          | Aurora PLL.......................................................                                                                             | 43 | 16.8.11         | QuadSPI Octal 1.8V DDR 200MHz..................93                                                                                |      |
| 14            | Power Management Controller (PMC).............                                                                                                | 45 | 16.8.12         | QuadSPI configurations...................................                                                                        | 94   |
| 14.1          | PMC Bandgap..................................................45                                                                               |    | 16.8.13         | QuadSPI interfaces..........................................                                                                     | 95   |
| 15            | Reset................................................................45                                                                       |    | 16.8.14         | QuadSPI timing diagrams................................                                                                          | 95   |
| 15.1          | Reset Duration.................................................                                                                               | 45 | 16.9            | DDR..................................................................97                                                          |      |
| 15.2          | Reset and Standby related pad electrical characteristics..................................................                                    | 49 | 16.9.1 16.9.2   | DDR..................................................................97 DDR Common DC Input...................................97 |      |
| 15.3          | PMIC Standby Mode Entry / Exit Protocol........51                                                                                             |    | 16.9.3          | DDR Common DC Output................................98                                                                           |      |
| 16            | Peripheral specifications..................................                                                                                   | 53 | 16.9.4          | DDR3L DC Input..............................................                                                                     | 99   |
| 16.1          | Analog Modules................................................53                                                                              |    | 16.9.5          | DDR3L Output Timing......................................99                                                                      |      |
| 16.1.1        | SAR ADC.........................................................                                                                              | 53 | 16.9.6          | LPDDR4 DC Input timing.................................                                                                          | 99   |
| 16.1.2        | Temperature Monitoring Unit (TMU)................                                                                                             | 55 | 16.9.7          | LPDDR4 Output Timing..................................100                                                                        |      |
| 16.1.3        | Glitch Filter.......................................................                                                                          | 56 | 16.10           | uSDHC...........................................................                                                                 | 100  |
| 16.1.4        | IRQ...................................................................56                                                                      |    | 16.10.1         | uSDHC SD3.0/eMMC5.1 DDR.......................100                                                                                |      |
| 16.2          | Clock and PLL Interfaces.................................                                                                                     | 57 | 16.10.2         | uSDHC SD3.0/SDIO3.0/eMMC5.1 SDR........                                                                                          | 102  |
| 16.2.1        | DFS..................................................................                                                                         | 57 | 16.10.3         | uSDHC SDR-100MHz....................................103                                                                          |      |
| 16.2.2        | FIRC.................................................................58                                                                       |    | 16.10.4         | uSDHC SDR-HS200......................................                                                                            | 104  |
| 16.2.3        | SIRC.................................................................58                                                                       |    | 16.10.5         | uSDHC DDR-HS400......................................                                                                            | 105  |
|               |                                                                                                                                               |    |                 |                                                                                                                                  | 106  |
| 16.2.4 16.2.5 | FXOSC.............................................................58 PLL...................................................................60 |    | 16.11           | Debug modules.............................................. JTAG Boundary Scan.....................................106           |      |
| 16.3          | Communication modules..................................62                                                                                     |    | 16.11.1 16.11.2 | JTAG Debug Interface Timing........................109                                                                           |      |
| 16.3.1        | SPI....................................................................62                                                                     |    | 16.11.3         | SWD electrical specifications.........................                                                                           | 110  |
| 16.3.2        | I2C....................................................................67                                                                     |    | 17              | Pinouts...........................................................                                                               | 112  |
| 16.3.4        | LIN....................................................................69                                                                     |    | 18              | Packaging.......................................................112                                                              |      |

19

S32G3

Revision history.............................................. 118

S32G3 Data Sheet

Legal information............................................130

All information provided in this document is subject to legal disclaimers.

©  2025 NXP B.V. All rights reserved.

Document feedback

<!-- image -->

Please be aware that important notices concerning this document and the product(s) described herein, have been included in section 'Legal information'.

<!-- image -->

For more information, please visit: https://www.nxp.com

All rights reserved.