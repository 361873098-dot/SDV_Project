## S32G3 HARDWARE PLATFORMS

F E B R U A R Y   2 0 2 3 Tao Xue

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## AGENDA

- HW Platforms Overview
- S32G-VNP-RDB3 Introduction
- S32G-VNP-EVB3 Introduction

<!-- image -->

## HW Platforms Overview

<!-- image -->

PUBLIC

3

## HW PLATFORMS OVERVIEW

## S32G-VNP-EVB3

S32G3 Evaluation Board 297mm x 210mm

<!-- image -->

## S32G-VNP-RDB3

S32G3 Reference Design Board 180mm x 140mm

<!-- image -->

S32G-VNP-GLDBOX3

<!-- image -->

S32G3 GoldBox 203mm x 161mm

<!-- image -->

## S32G-VNP-RDB3 Introduction

<!-- image -->

PUBLIC

5

## S32G-VNP-RDB3 AND S32G-VNP-GLDBOX3

The S32G-VNP-RDB3 and S32G-VNP-GLDBOX3 are compact, highly optimized and integrated board engineered for vehicle service-oriented gateways (SoG), domain control applications, high-performance processing, safety and security applications.

Based on octal Arm® Cortex®-A53 cores (with optional cluster lockstep) and quad dual-core lockstep Arm Cortex-M7 cores, the S32G-VNP-RDB3 offers a high-performance computing capacity and rich input/output (I/O), high levels of compute, real-time network performance, multi-Gigabit packet acceleration and security for a variety of typical and new automotive applications.

<!-- image -->

S32G-VNP-RDB3 Landing Page: https://nxp.com/S32G-VNP-RDB3

S32G-VNP-GLDBOX3 Landing Page:

https://www.nxp.com/GoldBox3

<!-- image -->

## S32G-VNP-RDB3 / S32G-VNP-GLDBOX3 OVERVIEW

- Part Number
- S32G-VNP-RDB3
- S32G-VNP-GLDBOX3 (w/enclosure)
- Applications
- A-sample-like design for development/demos/evaluation
- Gateway and Domain Controller Applications
- Central computer w/PCIe to other SoC(s)
- FOTA / Firewall demo
- Function safety and low-power design

<!-- image -->

<!-- image -->

x1

## S32G-VNP-RDB3 / S32G-VNP-GLDBOX3 HARDWARE RESOURCES

## S32G399A

- -Eight Arm Cortex-A53 cores and four Arm Cortex-M7 cores
- -Embedded Hardware Security Engine, HSE, supports SHE, HSM, EVITA
- -CAN, LIN and FlexRay offload with Low Latency Communications Engine
- -Gigabit Ethernet Packet Forwarding Engine (PFE)
- -20MB Embedded System RAM with ECC
- -32KB Standby RAM with ECC

## Ethernet-12ports

- -1 x 100BASE-TX
- -6 x 100BASE-T1
- -4 x 1000BASE-T
- -1 x 1000BASE-T/2.5GBASE-T

## LIN

- -4 x LLCE LIN
- -1 x LINFlexD

## FlexRay

- -1 x LLCE FlexRay
- External Storage / memory
- -1 x NOR Flash( 64MB )
- -1 x SD card slot
- -1 x eMMC (32GB)
- -1 x LPDDR4 (4GB)

## Scalable interface

- -1 x DSPI
- -5 x ADC
- -1 x I2C
- -1 x WKUP

## NXP Device

S32G399A

SJA1110A

VR5510

PF5300

FS5600

PF5020

TJA1043

TJA1153

TJA1463

TJA1081

NTS0102

Vehicle Network Processor Automotive Ethernet Switch

Power Management IC

Power Management IC

Power Management IC

Power Management IC

High-speed CAN Transceiver

Secure HS-CAN Transceiver

CAN FD Signal Improvement Transceiver

FlexRay Node Transceiver

Dual Supply Translating Transceiver

TJA1021 TJA1124 PCAL6524 NX3P1108 NX30P0121UK NX5P3363 PCA85073A CBTL02043A PCT2075 NX3DV3899

LIN Transceiver Quad LIN Transceiver I/O Expander Power Switch Power Switch USB Power Switch Real-Time Clock Multiplexer Digital temperature sensor Analog Switch

## PCIe

- -1 x M.2 M-key slot
- -1 x M.2 E-key slot
- -1 x PCIe X1 socket

## CAN/CAN FD

- -16 x LLCE CAN/CAN FD
- -2 x FlexCAN /CAN FD USB
- -1 x USB 2.0 port
- Debug
- -1 x 20PIN JTAG for S32G
- -1 x 10PIN JTAG for SJA1110A
- -1 x AURORA
- -2 x UART

## RTC

- -Support for external RTC

<!-- image -->

<!-- image -->

## BOARDS DIFFERENCE (SOFTWARE-RELATED)

| Items                     | RDB2 REVC                   | RDB2 REVD1                  | RDB2 REVD2                        | RDB2 REVD3                        | RDB2 REVE                          | RDB3 REVE                          | RDB3 REVF                          |
|---------------------------|-----------------------------|-----------------------------|-----------------------------------|-----------------------------------|------------------------------------|------------------------------------|------------------------------------|
| SOC                       | S32G274                     | S32G274                     | S32G274(Rev 2.0) S32G274AABK0VUCT | S32G274(Rev 2.0) S32G274AABK0VUCT | S32G274 (Rev 2.1) P32G274AABK1VUCT | S32G399 (Rev 1.0) P32G399AACK0VUCT | S32G399 (Rev 1.1) P32G399AACK1VUCT |
| PMIC (SOC)                | PVR5510AMDAHES              | PVR5510AMDAHES              | MVR5510AMDAHES                    | MVR5510AMDAHES                    | MVR5510AMDAHES                     | MVR5510AMDALES PPF53BDAMMA1ES      | MVR5510AMDALES PPF53BDAMMA1ES      |
| PMIC (Peripheral)         | FS5600 PF5020               | FS5600 PF5020               | FS5600 PF5020                     | FS5600 PF5020                     | FS5600 PF5020                      | FS5600 PF5020                      | FS5600 PF5020                      |
| DRAM                      | MT53D1024M32D4DT -046 AUT:D | MT53D1024M32D4DT -046 AUT:D | MT53D1024M32D4DT -046 AUT:D       | MT53D1024M32D4DT -046 AUT:D       | MT53E1G32D2FW- 046 AUT:B           | MT53D1024M32D4DT -046 AUT:D        | MT53E1G32D2FW- 046 AUT:B           |
| QuadSPI                   | MX25UW51245GXDR 00          | MX25UW51245GXDR 00          | MX25UW51245GXDR 00                | MX25UW51245GXDR 00                | MX25UW51245GXDR 00                 | MX25UW51245GXDR 00                 | MX25UW51245GXDR 00                 |
| uSDHC                     | MTFC32GAPALBH- AAT          | MTFC32GAPALBH- AAT          | MTFC32GAPALBH- AAT                | MTFC32GAZAQHD- AAT                | MTFC32GAZAQHD- AAT                 | MTFC32GAZAQHD- AAT                 | MTFC32GAZAQHD- AAT                 |
| CAN                       | 16ch+2ch                    | 16ch+2ch                    | 16ch+2ch                          | 16ch+2ch                          | 16ch+2ch                           | 16ch+2ch                           | 16ch+2ch                           |
| LINFlexD                  | 4ch+1ch                     | 4ch+1ch                     | 4ch+1ch                           | 4ch+1ch                           | 4ch+1ch                            | 4ch+1ch                            | 4ch+1ch                            |
| FlexRay                   | 1ch                         | 1ch                         | 1ch                               | 1ch                               | 1ch                                | 1ch                                | 1ch                                |
| Core current monitor(I2C) | No                          | Yes                         | Yes                               | Yes                               | Yes                                | Yes                                | Yes                                |
| Temp Sensor(I2C)          | No                          | Yes                         | Yes                               | Yes                               | Yes                                | Yes                                | Yes                                |
| SGMII PHY                 | AQR107 (0x03)               | AQR113C (0x08)              | AQR113C (0x08)                    | AQR113C (0x08)                    | AQR113C (0x08)                     | AQR113C (0x08)                     | AQR113C (0x08)                     |
| GPI/GPIO                  | 6ch                         | 6ch                         | 6ch                               | 6ch                               | 6ch                                | 6ch+1ch                            | 6ch+1ch                            |
| ADC                       | 5ch                         | 5ch                         | 5ch                               | 5ch                               | 5ch                                | 5ch                                | 5ch                                |
| Board version             | REVC (ADC_CH5=0.8V)         | REVD (ADC_CH5=1V)           | REVD (ADC_CH5=1V)                 | REVD (ADC_CH5=1V)                 | REVE (ADC_CH5=1.2V)                | REVE (ADC_CH5=1.2V)                | REVF (ADC_CH5=1.4V)                |
| SerDes Lanes              | Please see the next slide.  | Please see the next slide.  | Please see the next slide.        | Please see the next slide.        | Please see the next slide.         | Please see the next slide.         | Please see the next slide.         |

## BOARDS DIFFERENCE - SERDES LANES

<!-- image -->

<!-- image -->

## S32G-VNP-EVB3 Introduction

<!-- image -->

PUBLIC

1 1

## S32G-VNP-EVB3

The S32G-VNP-EVB3 is an evaluation and development board engineered for developing Vehicle Network Processing applications, such as service-oriented gateways.

Based on S32G2 and S32G3 processors for vehicle networking, the S32G-VNP-EVB3 offers a combination of automotive and enterprise networking technology with a wealth of interfaces (CAN/LIN/FlexRay/Ethernet) for vehicle networks, in addition to substantial safe compute performance.

The S32G-VNP-EVB3 includes peripheral devices with PCI Express and USB interfaces that can be leveraged by OEMs, Tier 1s, and software ecosystem partners to shorten time to market.

The EVB3 offers two-board approach:

- Platform board - S32GRV-PLATEVB
- Processor board - S32G-PROCEVB3-S

Landing Page: https://www.nxp.com/S32G-VNP-EVB3

<!-- image -->

<!-- image -->

## S32G-VNP-EVB3 PROCESSOR BOARD

- Part Number S32G-PROCEVB3-S
- Contains dedicated peripherals for S32G3 device
- Contains the Routing critical interfaces like LPDDR4/QSPI
- Can be used independently without Platform board with limited functionality

## NXP device on processor board

S32G399A

VR5510

PF5300

PF5020

TJA1051

NTSX2102

NX30P0121

NX5P3363

CBTL02043

Vehicle Network Processor (with socket)

Power Management IC

Power Management IC

Power Management IC

High-speed CAN Transceiver

Dual supply translating transceiver

Power Switch

Power Switch

Multiplexer

<!-- image -->

<!-- image -->

## S32G-VNP-EVB3 PLATFORM BOARD

- Part Number S32GRV-PLATEVB
- This is common Platform board for S32G/R/V devices
- Provides common set peripherals

## NXP device on platform board

FS5600

PF7100

MK26FN2

SJA1105Q

TJA1102

TJA1024

TJA1044

TJA1448

TJA1462

TJA1081

NTSX2102

Power Management IC

Power Management IC

Microcontroller

Automotive Ethernet Switch

100BASE-T1 Ethernet PHY

Quad LIN Transceiver

High-speed CAN transceiver

Dual High-speed CAN transceiver

CAN FD signal improvement transceiver

FlexRay Node Transceiver

Dual supply translating transceiver

<!-- image -->

<!-- image -->

## S32G-VNP-EVB3 BLOCK DIAGRAM

Processor Board

<!-- image -->

Platform board

<!-- image -->

## BOARDS DIFFERENCE

| Interface         | S32G-PROCEVB-S                                                       | S32G-PROCEVB3-S                                                        |
|-------------------|----------------------------------------------------------------------|------------------------------------------------------------------------|
| S32G              | socketed boards                                                      | socketed boards                                                        |
| Power Solution    | PVR5510AMMA4ES                                                       | PVR5510AMDALES + PF5300                                                |
| Power Connections | Supports connector for external PMIC validation board                | No connectors provided for alternate PMIC connections                  |
| QSPI Flash        | MX25UW51245G                                                         | MX25UW51245G                                                           |
| DDR               | LPDDR4 - MT53D1024M32D4DT                                            | LPDDR4 - MT53D1024M32D4DT                                              |
| eMMC              | MTFC32GAPALBH                                                        | MTFC32GAPALBH                                                          |
| Ethernet Phy      | RGMII PHY KSZ9031RNXCA SGMII PHYAQR107-B0-EG-Y SGMII PHYAddress: 0x4 | RGMII PHY KSZ9031RNXVB-VAO SGMII PHYAQR113C-B0-C SGMII PHYAddress: 0x8 |
| PCIe/SerDes       | Refer to further slides                                              | Refer to further slides                                                |
| USB               | SAF1508BET                                                           | USB83340AM                                                             |
| CAN               | TJF1051T/3                                                           | TJA1051T/3                                                             |
| EEPROM            | AT24C01C-XHM-T                                                       | AT24C01C-XPD-T                                                         |
| UART              | 1 UART                                                               | 2 UART                                                                 |

Note: The table above covers only key components.

Highlighted in brown are the changes across hardware

The platform boards (S32GRV-PLATEVB) remain the same

<!-- image -->

## BOARDS DIFFERENCE - SERDES LANES

## S32G-PROCEVB-S

<!-- image -->

## S32G-PROCEVB3-S

| SW17D:1]    | SDO Mode   | SDO_LO                           | SDO_L1                         | SDO Reference Clocl   | SD1 Mode   | SD1_LO                               | SD1_L1                              | SD1 Reference Cloc   |
|-------------|------------|----------------------------------|--------------------------------|-----------------------|------------|--------------------------------------|-------------------------------------|----------------------|
| 00          | PCle orly  | PCle X2 (P:PCle X16 C0N)         | PCl: X2 (P:PCle X16 CON)       | 100MHz                | PCle.SGMII | PCle X1 (D: PCle X1 Gold Finger)     | SGMII 1G (P: AQR107, PFE_MAC1)      | 100MHz               |
| 01 (defaut) | PCle orly  | PCle X2 (P:PCle X16 C0N)         | PCl X2 (P:PCle X16 CON)        | 100MHz                | SGMIl orly | SGMII 1G/2.5G (D: AQR113C, PFE_MAC0) | SGMII 1G/2.5G (P: AQR107, PFE MAC1) | 100/125MHz           |
| 10          | PCle/SGMII | PCle X1 (D: PCle X1 Gold Finger) | SGMIl 1G (P: AQR107, FFE_MAC2) | 100MHZ                |            |                                      |                                     |                      |
| 11          | SGMIl orly | SGMIl 1G (D: AQR113C, GMAC0)     | SGMII1G(P: AQR107, FFE_MAC2)   | 100MHz                |            |                                      |                                     |                      |

P:Platform Board P: Platform Board

D:

Processor Board

<!-- image -->

<!-- image -->

|          | PHY Lan   | PHY Lan                  | Connection         |
|----------|-----------|--------------------------|--------------------|
|          | Lan0      | PCIe X2 mode (Gen 3/2/1) | PCIe X16 connector |
|          | Lan1      |                          |                    |
| SerDes 1 | Lan0      | PCIe X1 mode (Gen 3/2/1) | PCIe X1 EP Gold    |
| SerDes 1 | Lan0      | SGMII 1G/2.5G            | AQR107             |
| SerDes 1 | Lan1      | SGMII 1G/2.5G            | AQR107             |