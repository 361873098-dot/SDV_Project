## INTRODUCTION TO DIFFERENCE B/W S32G2 &amp; S32G3

## PUBLIC

J A N U A R Y   2 0 2 3 Chetan Sharma VCNS Solutions and Applications Engineer

<!-- image -->

<!-- image -->

## S32G2 TO S32G3 MIGRATION GUIDE

- EB00922 on NXP Secure Files (previously DocStore) to refer key considerations while migration from S32G2x to S32G3x devices

| Contents   | Contents                                     |
|------------|----------------------------------------------|
|            | Introduction... S32G3 Enhancements 0verS32G2 |
| 2          |                                              |
| 3          | S32G3 Hardware Design                        |
|            | Considerations....                           |
| 456        | S32G3 Software Considerations...10           |
|            | S32G3 Tools Considerations...... 10          |
|            | S32G2 Boards reusability for S32G3           |
|            | based development... .10                     |
| 7          | References... .11                            |
| 8          | Revision history.... 11                      |

<!-- image -->

<!-- image -->

## S32G FAMILY LINEUP

- Performance Scale
- MCU → MPU
- ASIL D MPU
- HW Compatibility
- Same SoC package and pinout
- PMIC scalability option
- Same peripherals and accelerators
- SW Compatibility
- Application code compatible
- Same BSP
- Same boot flow
- Same security

<!-- image -->

| Feature                                 | S32G234M S32G274A S32G378A S32G379A S32G398A S32G399A      | S32G233A                                                   | S32G254A                                                   | S32G234M S32G274A S32G378A S32G379A S32G398A S32G399A      | S32G234M S32G274A S32G378A S32G379A S32G398A S32G399A   | S32G234M S32G274A S32G378A S32G379A S32G398A S32G399A   | S32G234M S32G274A S32G378A S32G379A S32G398A S32G399A   | S32G234M S32G274A S32G378A S32G379A S32G398A S32G399A   |
|-----------------------------------------|------------------------------------------------------------|------------------------------------------------------------|------------------------------------------------------------|------------------------------------------------------------|---------------------------------------------------------|---------------------------------------------------------|---------------------------------------------------------|---------------------------------------------------------|
| Package Arm CPU Cluster 1               | -                                                          | 1x Cortex-A53 @1GHz                                        | 1x Cortex-A53 @1GHz                                        | 525 FC-PBGA, 2x Cortex-A53@ 1 GHz                          | 19x19mm 0.8pitch 2x Cortex-A53 @1.3 GHz                 | 19x19mm 0.8pitch 2x Cortex-A53 @1.3 GHz                 | 4x Cortex-A53 @1.3 GHz                                  | 4x Cortex-A53 @1.3 GHz                                  |
| Arm CPU Cluster 2                       | -                                                          | 1x Cortex-A53 @1GHz                                        | 1x Cortex-A53 @1GHz                                        | 2x Cortex-A53@ 1 GHz                                       | 2x Cortex-A53 @1.3 GHz                                  | 2x Cortex-A53 @1.3 GHz                                  | 4x Cortex-A53 @1.3 GHz                                  | 4x Cortex-A53 @1.3 GHz                                  |
| Applications DMIPS                      | -                                                          | 4680-6380                                                  | 4680-6380                                                  | 9360-12760                                                 | 12168-16588                                             | 12168-16588                                             | 24336-33176                                             | 24336-33176                                             |
| Arm RT CPU                              | 3x Cortex M7, 400 MHz                                      | 1x Cortex M7, 400 MHz                                      | 3x Cortex M7, 400 MHz                                      | 3x Cortex M7, 400 MHz                                      | 3x Cortex M7, 400 MHz                                   | 4x Cortex M7, 400 MHz                                   | 3x Cortex M7, 400 MHz                                   | 4x Cortex M7, 400 MHz                                   |
| Real-time DMIPS                         | 2940                                                       | 980                                                        | 2940                                                       |                                                            | 2940                                                    | 3920                                                    | 2940                                                    | 3920                                                    |
| DDR                                     | -                                                          | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                     | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                     | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                     | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                  | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                  | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                  | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                  |
| System SRAM                             | 8MB                                                        | 6MB                                                        | 8MB                                                        | 8MB                                                        | 15MB                                                    | 20MB                                                    | 15MB                                                    | 20MB                                                    |
| NVM-IF                                  | Octal DDR NOR, eMMC/SDXC NAND                              | Octal DDR NOR, eMMC/SDXC NAND                              | Octal DDR NOR, eMMC/SDXC NAND                              | Octal DDR NOR, eMMC/SDXC NAND                              | Octal DDR NOR, eMMC/SDXC NAND                           | Octal DDR NOR, eMMC/SDXC NAND                           | Octal DDR NOR, eMMC/SDXC NAND                           | Octal DDR NOR, eMMC/SDXC NAND                           |
| PCIe                                    | 1x PCIe2.0 (2lanes)                                        | 2x PCIe3.0 (2lanes)                                        | 2x PCIe3.0 (2lanes)                                        | 2x PCIe3.0 (2lanes)                                        | 2x PCIe3.0 (2lanes)                                     | 2x PCIe3.0 (2lanes)                                     | 2x PCIe3.0 (2lanes)                                     | 2x PCIe3.0 (2lanes)                                     |
| Ethernet Acceleration                   | Packet Forwarding Engine (PFE)                             | Packet Forwarding Engine (PFE)                             | Packet Forwarding Engine (PFE)                             | Packet Forwarding Engine (PFE)                             | Packet Forwarding Engine (PFE2)                         | Packet Forwarding Engine (PFE2)                         | Packet Forwarding Engine (PFE2)                         | Packet Forwarding Engine (PFE2)                         |
| Accelerated Ethernet Ports (PFE)        | 2x 1G/100M                                                 | 1x                                                         | 2.5G/1G/100M                                               | 2x 1G/100M                                                 | 3 ext ports                                             | 3x                                                      | 2.5G/1G/100M                                            | 3 ext ports                                             |
| Automotive                              | Low Latency Communication Engine (LLCE)                    | Low Latency Communication Engine (LLCE)                    | Low Latency Communication Engine (LLCE)                    | Low Latency Communication Engine (LLCE)                    | Low Latency Communication Engine (LLCE)                 | Low Latency Communication Engine (LLCE)                 | Low Latency Communication Engine (LLCE)                 | Low Latency Communication Engine (LLCE)                 |
| Network Acceleration Non-Accelerated IF | CAN FD x16 / LIN x4 / FR                                   | 4                                                          | 4                                                          | 4                                                          | CAN FD x16 / LIN x4 / FR x1                             | CAN FD x16 / LIN x4 / FR x1                             | CAN FD x16 / LIN x4 / FR x1                             | CAN FD x16 / LIN x4 / FR x1                             |
| CAN FD / LIN / FR Gb ETH / USB2.0       | 4 / 3 / 1 1 / 0                                            |                                                            |                                                            |                                                            | / 3 / 1                                                 |                                                         |                                                         |                                                         |
| SPI / I2C                               | 6 / 5                                                      | 6                                                          | 6                                                          | 6                                                          | 1 / 1 / 5                                               | 1 / 1 / 5                                               | 1 / 1 / 5                                               | 1 / 1 / 5                                               |
| Timer                                   |                                                            |                                                            |                                                            |                                                            |                                                         |                                                         |                                                         |                                                         |
|                                         | 12 FlexTimer, 7 System Timer, 7 Watchdog Timer 2x 6-ch SAR | 12 FlexTimer, 7 System Timer, 7 Watchdog Timer 2x 6-ch SAR | 12 FlexTimer, 7 System Timer, 7 Watchdog Timer 2x 6-ch SAR | 12 FlexTimer, 7 System Timer, 7 Watchdog Timer 2x 6-ch SAR | 12 FlexTimer, 13 System Timer, 12 Watchdog Timer        | 12 FlexTimer, 13 System Timer, 12 Watchdog Timer        | 12 FlexTimer, 13 System Timer, 12 Watchdog Timer        | 12 FlexTimer, 13 System Timer, 12 Watchdog Timer        |
| ADC                                     | ADC, 12-bit                                                | ADC, 12-bit                                                | ADC, 12-bit                                                | ADC, 12-bit                                                | ADC, 12-bit                                             | ADC, 12-bit                                             | ADC, 12-bit                                             | ADC, 12-bit                                             |
| Temp Range                              | -40 to 105  C (Tj=125°C)                                  | -40 to 105  C (Tj=125°C)                                  | -40 to 105  C (Tj=125°C)                                  | -40 to 105  C (Tj=125°C)                                  | -40 to 105  C (Tj=125°C)                               | -40 to 105  C (Tj=125°C)                               | -40 to 105  C (Tj=125°C)                               | -40 to 105  C (Tj=125°C)                               |

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

S32G274A

<!-- image -->

<!-- image -->

S32G398A

## S32G3 FAMILY BLOCK DIAGRAM

<!-- image -->

<!-- image -->

| Low Latency Comm Engine (LLCE)   | Low Latency Comm Engine (LLCE)   |
|----------------------------------|----------------------------------|
| BCAN x16                         | FlexRay x1                       |
| LINFlexD x4                      | SPI x4                           |
| Flexible Buffer                  | Flexible Buffer                  |
| Security Offload                 | Security Offload                 |
| Timestamping                     | Timestamping                     |

<!-- image -->

<!-- image -->

<!-- image -->

|                                                                        | S32G378A S32G378A                                                | S32G379A S32G379A                                                | S32G398A S32G398A                                                | S32G399A S32G399A                                                |
|------------------------------------------------------------------------|------------------------------------------------------------------|------------------------------------------------------------------|------------------------------------------------------------------|------------------------------------------------------------------|
| Feature                                                                | 525 FC-PBGA, 19x19mm 0.8pitch                                    | 525 FC-PBGA, 19x19mm 0.8pitch                                    | 525 FC-PBGA, 19x19mm 0.8pitch                                    | 525 FC-PBGA, 19x19mm 0.8pitch                                    |
| Package                                                                | 2x Cortex-A53 @1.3 GHz                                           | 2x Cortex-A53 @1.3 GHz                                           | 4x Cortex-A53 @1.3 GHz                                           | 4x Cortex-A53 @1.3 GHz                                           |
| Arm CPU Cluster 2                                                      | 2x Cortex-A53 @1.3 GHz                                           | 2x Cortex-A53 @1.3 GHz                                           | 4x Cortex-A53 @1.3 GHz                                           | 4x Cortex-A53 @1.3 GHz                                           |
| Applications DMIPS                                                     | 12168-16588                                                      | 12168-16588                                                      | 24336-33176                                                      | 24336-33176                                                      |
| Arm Real-time CPU                                                      | 3x Cortex-M7, 400 MHz                                            | 4x Cortex-M7, 400 MHz                                            | 3x Cortex-M7, 400 MHz                                            | 4x Cortex-M7, 400 MHz                                            |
| Real-time DMIPS                                                        | 2940                                                             | 3920                                                             | 2940                                                             | 3920                                                             |
| DDR                                                                    | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                           | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                           | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                           | LPDDR4 (Up to 4GB) / DDR3L (Up to 2GB)                           |
| System SRAM                                                            | 15 MB                                                            | 20 MB                                                            | 15 MB                                                            | 20 MB                                                            |
| NVM-IF                                                                 | Octal DDR NOR, eMMC/SDXC NAND                                    | Octal DDR NOR, eMMC/SDXC NAND                                    | Octal DDR NOR, eMMC/SDXC NAND                                    | Octal DDR NOR, eMMC/SDXC NAND                                    |
| PCIe                                                                   | 2x PCIe 2.0 (2 lanes ea.)                                        | 2x PCIe 2.0 (2 lanes ea.)                                        | 2x PCIe 2.0 (2 lanes ea.)                                        | 2x PCIe 2.0 (2 lanes ea.)                                        |
| Ethernet Acceleration                                                  | Packet Forwarding Engine PFE2 * 3Gbps@64B forwarding 3 ext ports | Packet Forwarding Engine PFE2 * 3Gbps@64B forwarding 3 ext ports | Packet Forwarding Engine PFE2 * 3Gbps@64B forwarding 3 ext ports | Packet Forwarding Engine PFE2 * 3Gbps@64B forwarding 3 ext ports |
| Accelerated Ethernet Ports (PFE) Automotive                            | 3x 2.5G/1G/100M Low                                              | Latency Communication                                            | Engine                                                           | (LLCE)                                                           |
| Non-Accelerated Interfaces CAN FD / LIN / FR Gb ETH / USB2.0 SPI / I2C | 4 / 3 / 1 1 / 1                                                  | 4 / 3 / 1 1 / 1                                                  | 4 / 3 / 1 1 / 1                                                  | 4 / 3 / 1 1 / 1                                                  |
| Timer                                                                  | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer           | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer           | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer           | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer           |
| ADC                                                                    |                                                                  |                                                                  |                                                                  |                                                                  |
|                                                                        | 2x 6-ch SAR ADC, 12-bit                                          | 2x 6-ch SAR ADC, 12-bit                                          | 2x 6-ch SAR ADC, 12-bit                                          | 2x 6-ch SAR ADC, 12-bit                                          |
| Temp Range                                                             | -40 to 105  C (Tj=125°C)                                        | -40 to 105  C (Tj=125°C)                                        | -40 to 105  C (Tj=125°C)                                        | -40 to 105  C (Tj=125°C)                                        |

<!-- image -->

## S32G3 vs S32G2: SRAM/DDR

## SRAM

| Features                                | S32G2                                                                               |                         | S32G3                                                                                |                         |
|-----------------------------------------|-------------------------------------------------------------------------------------|-------------------------|--------------------------------------------------------------------------------------|-------------------------|
| Real time memory                        | 8MB                                                                                 |                         | 20MB                                                                                 |                         |
| SRAM Controllers                        | 2x SRAM Controllers Each SRAM controls over 4MB region                              |                         | 4x SRAM Controllers Each SRAM controls over 5MB region                               |                         |
| SRAM alignment with Arm Cortex-M7 cores | OptimumArm Cortex-M7 cores to SRAM latency can be achieved in the following order.* |                         | OptimumArm Cortex-M7 cores to SRAM latency can be achieved in the following order.** |                         |
|                                         | Arm Cortex-M7 Core                                                                  | SRAM address range      | Arm Cortex-M7 Core                                                                   | SRAM address range      |
|                                         | Arm Cortex-M7_0                                                                     | 0x3400_0000-0x343F_FFFF | Arm Cortex-M7_0                                                                      | 0x3400_0000-0x344F_FFFF |
|                                         | Arm Cortex-M7_1                                                                     | 0x3440_0000-0x347F_FFFF | Arm Cortex-M7_3                                                                      | 0x3450_0000-0x347F_FFFF |
| DDR                                     | Arm Cortex-M7_2                                                                     | 0x3440_0000-0x347F_FFFF | Arm Cortex-M7_1                                                                      | 0x34A0_0000-0x347F_FFFF |
|                                         |                                                                                     |                         | Arm Cortex-M7_2                                                                      | 0x34F0_0000-0x347F_FFFF |

## DDR

| Features                   | S32G2                                                                         | S32G3                                                                                                            |
|----------------------------|-------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| Row address bit 17 support | Uses both chip select to access 4GB (dual ranks) of DRAM                      | Uses single chip select and row address bit 17 to access 4GB (single rank) of DRAM supporting row address bit 17 |
| ECC initialization         | DDR_GPR registers - DDR_Config_1 and DDR_Config_2 used for ECC initialization | UMCTL2_MP registers - SBRSTART0,1 and SBRRANGE0,1 used for ECC initialization                                    |

<!-- image -->

## S32G3 vs S32G2: PFE/SERDES

<!-- image -->

<!-- image -->

## S32G3 vs S32G2: LLCE

<!-- image -->

<!-- image -->

## S32G3 vs S32G2: HSE &amp; XRDC

<!-- image -->

<!-- image -->

## S32G3 vs S32G2: BootROM

<!-- image -->

<!-- image -->

## S32G3 vs S32G2: more ..

<!-- image -->

<!-- image -->

VBAT

Load

Switch

3.3V

3.3V

PCI

Express

## POWER MANAGEMENT MIGRATION FROM S32G2 TO S32G3

VR5510

HVBack

ACS9CE

BUCK1

25A

0.411.BV

BUCKO

254

0.41018V

BUCK3

25A

104.1V

1002

ALDO

ALDXO

BOOST

5V

3.3V

0.8V

1.1V

1.8V

1.8V

VBST=5V

0.8V

CAN

PHYS

S32G2

VDD\_3P3\_LP

VDD\_CORE

VDD\_DDR\_IO

VDD\_V1P8\_IO

VDD\_V1P8\_ANA

VDD\_3P3

VDD\_CORE\_STBY

<!-- image -->

## What is different?

- Core Supplied by PF53 instead of Buck1/2 of VR5510 in dual phase
- VDD\_V1P8 is supplied by Buck2 instead of LDO2
- LDO2 is now used to enable the external PF53 core supply
- Buck1 is now available to supply the Ethernet switch if needed for a better overall system solution
- With BOM options it is possible to switch to S32G2 solution with VR5510 only
- SVS is not supported with S32G3 (not a requirement today)

<!-- image -->

VBSTorV3P3

DC-DC

Buck

1.8V

uSD/EMMC

Filter

EthemetPHY

NORFlash

TJA1102

SJA1110C/A

VR5510 PMIC is capable of supplying S32G2 but it is underpowered for S32G3 due to the increased power demand on the core and 1.8V supplies

## Forward/Backward Compatibility supported with Board BOM Options

DC-DC

Buck

5V

5VUSB

TJA1024

3.3V

CAN

PHYS

LPDDR4

S32G3

Solution

Key-Off Rails

Additional RailsforDDRRefresh

<!-- image -->

## TECHNOLOGY SHOWROOM

## JOURNEYS BY DESIRED ENGAGEMENT

Self-guided tour Live-streaming at set times

Guided tours

## JOURNEYS BY DESIRED FOCUS

Edge &amp; AI/ML Safety &amp; Security Connectivity Analog

<!-- image -->

<!-- image -->

PUBLIC

1 2

## 40+ VIRTUAL DEMOS

Focus on system solutions Set up along NXP verticals

<!-- image -->

<!-- image -->

SHOWROOM.NXP.COM