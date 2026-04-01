<!-- image -->

## S32G-VNP-RDB3 Reference Manual

Version: 0.4

<!-- image -->

## Contents

| Contents                       | Contents                       | Contents                       |   2 |
|--------------------------------|--------------------------------|--------------------------------|-----|
| Tables                         | Tables                         | Tables                         |   4 |
| Figures                        | Figures                        | Figures                        |   5 |
| 1 Introduction                 | 1 Introduction                 | 1 Introduction                 |   6 |
| 1.1                            | Acronyms and Abbreviations     | Acronyms and Abbreviations     |   6 |
| 1.2                            | Related documentation          | Related documentation          |   7 |
| 1.3                            | Board Version                  | Board Version                  |   8 |
| 2 S32G-VNP-RDB3 Specifications | 2 S32G-VNP-RDB3 Specifications | 2 S32G-VNP-RDB3 Specifications |   9 |
| 2.1                            | Hardware Resources             | Hardware Resources             |   9 |
| 2.2                            | Block diagram                  | Block diagram                  |  10 |
| 2.3                            | PCB specification              | PCB specification              |  11 |
| 2.4                            | S32G-VNP-RDB3 top view         | S32G-VNP-RDB3 top view         |  11 |
| 2.5                            | Connector                      | Connector                      |  12 |
| 2.6                            | Buttons                        | Buttons                        |  13 |
| 2.7                            | Power Switch                   | Power Switch                   |  13 |
| 2.8                            | DIP Switch                     | DIP Switch                     |  14 |
| 2.9                            | Jumpers                        | Jumpers                        |  16 |
| 2.10                           | LEDs                           | LEDs                           |  17 |
| Functional Description         | Functional Description         | Functional Description         |  18 |
| 3.1                            | Power supplies                 | Power supplies                 |  18 |
| 3.2                            | Boot                           | Boot                           |  19 |
| 3.3                            | Reset                          | Reset                          |  21 |
| 3.4                            | Clocks                         | Clocks                         |  22 |
| 3.5                            | JTAG                           | JTAG                           |  23 |
| 3.6                            | Aurora Trace                   | Aurora Trace                   |  23 |
| 3.7                            | External Memory and Storage    | External Memory and Storage    |  23 |
|                                |                                |                                |  23 |
| 3.7.1                          | 3.7.1                          | LPDDR4 NOR flash               |  24 |
| 3.7.2 3.7.3                    | 3.7.2 3.7.3                    | SD/eMMC                        |  25 |
| 3.8 SerDes Interface           | 3.8 SerDes Interface           | 3.8 SerDes Interface           |  26 |

<!-- image -->

| 3.9                  | Ethernet             | Ethernet             |   28 |
|----------------------|----------------------|----------------------|------|
| 3.9.1                | 3.9.1                | Ethernet switch      |   29 |
| 3.9.2                | 3.9.2                | Ethernet PHY         |   29 |
| 3.9.3                | 3.9.3                | SMI Interface        |   30 |
| 3.10                 | CAN                  | CAN                  |   30 |
| 3.11                 | LIN and UART         | LIN and UART         |   34 |
| 3.12                 | FlexRay              | FlexRay              |   35 |
| 3.13                 | DSPI                 | DSPI                 |   36 |
| 3.14                 | I2C                  | I2C                  |   36 |
| 3.15                 | USB                  | USB                  |   37 |
| 4 Cables Description | 4 Cables Description | 4 Cables Description |   38 |
| 5                    | Revision History     | Revision History     |   42 |

<!-- image -->

## Tables

| Table 1. Acronyms and abbreviations ................................................................................6                        |                                                                                                                       |
|----------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| Table 2. Related documentation ...........................................................................................7                  |                                                                                                                       |
| Table 3. S32G-VNP-RDB3 Board Version ......................................................................8                                 |                                                                                                                       |
| Table 4. Hardware Resources ...............................................................................................9                 |                                                                                                                       |
| Table 5. S32G-VNP-RDB3 PCB Specifications .........................................................11                                        |                                                                                                                       |
| Table 6. The connectors of S32G-VNP-RDB3 ............................................................12                                      |                                                                                                                       |
| Table 7. The button of S32G-VNP-RDB3 ......................................................................13                                |                                                                                                                       |
| Table 8. The power switch of S32G-VNP-RDB3                                                                                                   | .......................................................13                                                             |
| Table 9. DIP switches ............................................................................................................14         |                                                                                                                       |
| Table 10. The setting of boot modes ...............................................................................15                        |                                                                                                                       |
| Table 11. Jumpers ....................................................................................................................16     |                                                                                                                       |
| Table 12. LEDs ...........................................................................................................................17 |                                                                                                                       |
| Table 13. Values of boot mode pins ................................................................................19                        |                                                                                                                       |
| Table 14. The memory map of DDR and NOR Flash ..............................................23                                               |                                                                                                                       |
| Table 15. The multiplexing setting of SerDes ..............................................................26                                |                                                                                                                       |
| Table 16. SJA1110 port description .................................................................................29                       |                                                                                                                       |
| Table 17. Ethernet PHYs description ..............................................................................29                         |                                                                                                                       |
| Table 18. SMI Interface ..........................................................................................................30         |                                                                                                                       |
| Table 19. CAN transceiver Connections ........................................................................30                             |                                                                                                                       |
| Table 20. LIN and UART Connections ...........................................................................34                             |                                                                                                                       |
| Table 21. FlexRay Connections .........................................................................................35                    |                                                                                                                       |
| Table 22. DSPI Connections ...............................................................................................36                 |                                                                                                                       |
| Table 23. I2C Connections ...................................................................................................36              |                                                                                                                       |
| Table 24. USB Connections .................................................................................................37                |                                                                                                                       |
| Table 25. J6 Cable ...................................................................................................................38     |                                                                                                                       |
| Table 26. J5 Cable                                                                                                                           | ...................................................................................................................39 |
| Table 27. J53 Cable                                                                                                                          | .................................................................................................................40   |

<!-- image -->

## Figures

| Figure 1. The block diagram of S32G-VNP-RDB3 ....................................................10                                   |
|---------------------------------------------------------------------------------------------------------------------------------------|
| Figure 2. The top view of S32G-VNP-RDB3 ................................................................11                            |
| Figure 3. The power supply block diagram of S32G-VNP-RDB3 ......................18                                                    |
| Figure 4. Boot mode pins ......................................................................................................19     |
| Figure 5. RCON pins ...............................................................................................................20 |
| Figure 6. Reset Tree of S32G-VNP-RDB3 ...................................................................21                           |
| Figure 7. Clock Tree of S32G-VNP-RDB3 ....................................................................22                          |
| Figure 8. The connection of LPDDR4 SDRAM ...........................................................24                                |
| Figure 9. The connection between S32G399A and MX25UW51245G ...........24                                                              |
| Figure 10. The connection of S32G399A and SD/eMMC ......................................25                                            |
| Figure 11. SerDes routing diagram of S32G-VNP-RDB3 ......................................26                                           |
| Figure 12. Ethernet connections of S32G-VNP-RDB3 ...........................................28                                        |

<!-- image -->

## 1    Introduction

The S32G-VNP-RDB3 is a compact, highly-optimized and integrated reference design board featuring the S32G399A vehicle network processor. With its high-performance computing capacity and rich input/output(I/O), this board can provide reference for a variety of typical automotive applications, such as service-oriented gateway, high-performance central compute unit, safety controller for ADAS and autonomous driving, FOTA master controlling image download and distribution, black-box for vehicle data logging, security services  and  key  management, smart  antennas  etc.  It  can  be  directly  used  by  carmakers,  suppliers  and software ecosystem partners to accelerate development for shorter time-to-market.

This document describes the board specifications, block diagram, connectors and interfaces.

## 1.1    Acronyms and Abbreviations

The table below lists commonly used acronyms and abbreviations.

Table 1. Acronyms and abbreviations

| Acronym/abbreviation   | Description                              |
|------------------------|------------------------------------------|
| CAN                    | Controller Area Network                  |
| CAN FD                 | CAN with Flexible Data-Rate              |
| DDR                    | Double Data Rate SDRAM                   |
| ECC                    | Error correcting code                    |
| eMMC                   | Embedded multimedia card                 |
| FOTA                   | Firmware Updates Over The Air            |
| GMAC                   | Gigabit Ethernet Media Access Controller |
| GPIO                   | General Purpose In/Out                   |
| I2C                    | Inter-integrated circuit                 |
| JTAG                   | Joint Test Action Group                  |
| LIN                    | Local Interconnect Network               |
| LLCE                   | Low Latency Communications Engine        |

<!-- image -->

| MII    | Media Independent Interface                 |
|--------|---------------------------------------------|
| PCBA   | Printed Circuit Board Assembly              |
| PFE    | Packet Forwarding Engine                    |
| PHY    | Physical Layer                              |
| RGMII  | Reduced General Media Independent Interface |
| SerDes | Serializer/Deserializer                     |
| SGMII  | Serial Gigabit Media Independent Interface  |
| SMI    | Serial Management Interface                 |
| SPDT   | Single Pole Double Throw                    |
| SSD    | Solid State Drive                           |
| TSN    | Time Sensitive Network                      |
| USB    | Universal serial bus                        |
| uSDHC  | Ultra Secured Digital Host Controller       |

## 1.2    Related documentation

The table below lists and explains the additional documents and resources that you can refer to for more information on the S32G-VNP-RDB3. Some of the documents listed below may be available only under a nondisclosure agreement (NDA). To request access to these documents, contact your local field applications engineer (FAE) or sales representative.

Table 2. Related documentation

| Document               | Description                                                                                                   |
|------------------------|---------------------------------------------------------------------------------------------------------------|
| S32G3 Product Brief    | Provides a brief overview of the S32G3 series.                                                                |
| S32G3 Reference Manual | Provides a detailed description of the S32G3 multicore processor and its features, such as memory map, serial |

<!-- image -->

|                          | interfaces, chip features, and clock information.                                            |
|--------------------------|----------------------------------------------------------------------------------------------|
| S32G3 Data Sheet         | Provides information about S32G3 electrical characteristics, and ordering information.       |
| S32G-VNP-RDB3 User Guide | Provides an overview of the S32G-VNP- RDB3, and describes how to quickly bring up the board. |

## 1.3    Board Version

The table below lists the board version of S32G-VNP-RDB3. For detailed revision information, please refer to the "Revision History" chapter of the schematic.

Table 3. S32G-VNP-RDB3 Board Version

| PCBA version Schematic   | Brief revision information                                                                                                                                                                                                                                                     |
|--------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| REV E SCH-53060_E1       | S32G-VNP-RDB3 first orderable version.                                                                                                                                                                                                                                         |
| REV E SCH-53060_E3       | Change eMMC part U28 from MTFC32GAPALBH-AAT to MTFC32GAZAQHD-AAT.                                                                                                                                                                                                              |
| REV F                    | SCH-53060_F 1. Update U43 part number from P32G399AACK0VUCT to P32G399AACK1VUCT. 2. Update U42 from MT53D1024M32D4DT-046 AUT:D to MT53E1G32D2FW-046 AUT:B. 3. Update board version to F by changing R229 to 15K and R244 to 11k. 4. Change U9 from TJA1024HG to TJA1124CHG/0Z. |

The board assembly version is printed on a label which is pasted on the bottom side of the PCB.

<!-- image -->

## 2    S32G-VNP-RDB3 Specifications

This section describes the hardware resources, specifications, and mechanical information of S32G-VNPRDB3.

## 2.1    Hardware Resources

The resources of S32G-VNP-RDB3 are listed as below.

## Table 4. Hardware Resources

| Items         | Resources          | Description                                                                                                                                                                                                                                                |
|---------------|--------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Processor     | S32G399A processor | 4 x Cortex-A53 LS (8 x Cortex-A53) 4 x Cortex-M7 LS 1 x Hardware Security Engine (HSE) 1 x Low Latency Communications Engine(LLCE) 1 x Gigabit Ethernet Packet Forwarding Engine (PFE) 1 x 20MB Embedded System RAM with ECC 1 x 32KB Standby RAM with ECC |
| Memory        | LPDDR4             | 1 x LPDDR4 (4GB) with inline-ECC and self-refresh                                                                                                                                                                                                          |
| Memory        | NOR flash          | 1 x NOR Flash (64MB)                                                                                                                                                                                                                                       |
| Memory        | eMMC               | 1 x eMMC (32GB)                                                                                                                                                                                                                                            |
| Memory        | SD card            | 1 x Slot for SD card                                                                                                                                                                                                                                       |
| Connectivity  | Ethernet           | 1 x 100BASE-TX 6 x 100BASE-T1 4 x 1000BASE-T 1 x 2.5BASE-T/1000BASE-T                                                                                                                                                                                      |
| Connectivity  | USB                | 1x USB 2.0 I/F Host/Device mode                                                                                                                                                                                                                            |
| Connectivity  | FlexRay            | 1 x LLCE FlexRay                                                                                                                                                                                                                                           |
| Connectivity  | LIN                | 4 x LLCE LIN as master mode by default 1 x LINFlexD as slave mode by default                                                                                                                                                                               |
| Connectivity  | CAN/CAN_FD         | 16 x LLCE CAN/CAN FD 2 x FlexCAN /CAN FD                                                                                                                                                                                                                   |
| Connectivity  | ADC                | 5 x ADC                                                                                                                                                                                                                                                    |
| Connectivity  | GPIO               | 7 x GPI/GPIO with multiplexable functions: I2C, DSPI, EIRQ, Wakeup input, FTM                                                                                                                                                                              |
| Debug & Trace | UART               | 2 x UART                                                                                                                                                                                                                                                   |

<!-- image -->

|                     | JTAG           | 1 x 20PIN JTAG for S32G399A 1 x 10PIN JTAG for SJA1110A                                                                            |
|---------------------|----------------|------------------------------------------------------------------------------------------------------------------------------------|
|                     | Aurora Trace   | 1 x AURORA                                                                                                                         |
| Additional Features | Low-power mode | Supports Low-power mode with DDR self-refresh                                                                                      |
| Additional Features | RTC            | Supports internal RTC and on-board external RTC                                                                                    |
| Expansion Connector | M.2 slot       | 1 x M.2 M-key slot 1 x M.2 E-key slot Note: When M.2 M-key card is inserted, M.2 E-key slot will not be available, and vice versa. |
| Expansion Connector | PCIe x1 socket | 1 x PCIe x1 socket                                                                                                                 |

## 2.2    Block diagram

The figure below shows S32G-VNP-RDB3 block diagram.

Figure 1. The block diagram of S32G-VNP-RDB3

<!-- image -->

<!-- image -->

## 2.3    PCB specification

The table below lists the PCB specifications of S32G-VNP-RDB3.

## Table 5. S32G-VNP-RDB3 PCB Specifications

| Items               | Specifications           |
|---------------------|--------------------------|
| Ambient Temperature | ~ 35° C, Lab environment |
| PCB dimensions      | 180mm x 140mm            |

## 2.4    S32G-VNP-RDB3 top view

The figure below shows the top view of S32G-VNP-RDB3.

Figure 2. The top view of S32G-VNP-RDB3

<!-- image -->

<!-- image -->

## 2.5    Connector

The table below shows the connectors of S32G-VNP-RDB3 and their corresponding signals. For more details on the connector signals, please refer to schematic.

Table 6. The connectors of S32G-VNP-RDB3

| Part   | Connector type             | Description                                                                                   | Typical connection                                                                                                                                                                                             |
|--------|----------------------------|-----------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| J1     | USB 2.0 Micro-AB connector | Console port (UART1)                                                                          | Connects to host computer.                                                                                                                                                                                     |
| J2     | USB 2.0 Micro-AB connector | Console port (UART0)                                                                          | Connects to host computer.                                                                                                                                                                                     |
| J3     | SD card slot               | SD card slot                                                                                  | Connects to the SD card.                                                                                                                                                                                       |
| J4     | USB 2.0 Micro-AB connector | Supports USB 2.0 host/device mode.                                                            | Host mode: Connects to OTG cable. Device mode: Connects to USB-A to Micro-B cable.                                                                                                                             |
| J5     | 2 x 13 connector           | Connector for GPIO, ADC, LIN, I2C, DSPI, power supply                                         | Connects to the cable provided in accessories.                                                                                                                                                                 |
| J6     | 2 x 20 connector           | Connector for CAN and FlexRay                                                                 | Connects to the cable provided in accessories.                                                                                                                                                                 |
| J44    | 2 x 10 connector           | SJA1110 JTAG port                                                                             | Connects to a debugger of SJA1110.                                                                                                                                                                             |
| J47    | M.2 M-key slot             | PCIe x2 M.2 slot with M-key ， Supports PCIe x2 (Gen3, Gen2, Gen1) ,PCIe x1 (Gen3, Gen2, Gen1) | Connects to PCIe x2 module(size: 2242, key:M key, B+M key) Recommended to connect 2242 B+M key NVME SSD(Netac N930ES-128GB NVMe SSD is already tested on S32G- VNP-RDB3) If J47 is used, J56 is not available. |
| J48    | 2 x 10 connector           | S32G399A JTAG port                                                                            | Connects to a debugger of S32G399A.                                                                                                                                                                            |
| J50    | 2 x 3 connector            | Fan power connector                                                                           | Connects to the fan if needed.                                                                                                                                                                                 |
| J53    | 2 x 12 connector           | Connector for 100BASE-T1 interfaces                                                           | Connects to the cable in accessories.                                                                                                                                                                          |
| J56    | M.2 E-key slot             | PCIe x2 M.2 slot with E-key ， Supports PCIe x2 (Gen3, Gen2, Gen1) ,PCIe x1 (Gen3, Gen2, Gen1) | Connects to PCIe x2 module (size: 2242, key: E key, A+E key) If J56 is used, J47 is not available                                                                                                              |
| J57    | 2 x 20 connector           | S32G399A Aurora trace port                                                                    | Connects to a debugger of S32G399A                                                                                                                                                                             |
| J176   | DC power jack              | 12V DC power supply input port                                                                | Connects to 12V AC-DC power adapter                                                                                                                                                                            |

<!-- image -->

| P1   | PCIe x1 socket             | Supports PCIe x1 (Gen3, Gen2, Gen1)                                                       | Connects to PCIe x1 EP device   |
|------|----------------------------|-------------------------------------------------------------------------------------------|---------------------------------|
| P2   | Dual-port RJ45 connector   | Ethernet port with Magnetics for 1000BASE-T/ 100BASE-TX connectivity P2A(bottom) P2B(top) | Connects to RJ45 Ethernet cable |
| P3   | Dual-port RJ45 connector   | Ethernet port with Magnetics for 1000BASE-T/ 100BASE-TX connectivity P3A(bottom) P3B(top) | Connects to RJ45 Ethernet cable |
| P4   | Single-port RJ45 connector | Ethernet port with Magnetics for 100BASE-TX connectivity                                  | Connects to RJ45 Ethernet cable |
| P5   | Single-port RJ45 connector | Ethernet port with Magnetics for 2.5GBASE-T/ 1000BASE- T/100BASE-TX connectivity          | Connects to RJ45 Ethernet cable |

## 2.6    Buttons

The table below describes the buttons.

Table 7. The button of S32G-VNP-RDB3

| Part   | Name    | Description                                                                                                       |
|--------|---------|-------------------------------------------------------------------------------------------------------------------|
| SW1    | POR_B   | Press SW1: S32G399A performs power-on reset. Refer to chapter 3.3 to get to know if other components are reset.   |
| SW2    | RESET_B | Press SW2: S32G399A performs functional reset. Refer to chapter 3.3 to get to know if other components are reset. |
| SW16   | NMI     | Press SW16 to assert non-maskable interrupt.                                                                      |

## 2.7    Power Switch

The table below describes the main switch for the board power supply.

Table 8. The power switch of S32G-VNP-RDB3

| Switch   | Default setting   | Description                                                                  | Description                                                                  | Description                                                                  |
|----------|-------------------|------------------------------------------------------------------------------|------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| SW15     | POS. 2            | SW15 is an SPDT switch. The figure below shows that actuator can be moved to | SW15 is an SPDT switch. The figure below shows that actuator can be moved to | SW15 is an SPDT switch. The figure below shows that actuator can be moved to |
| SW15     | POS. 2            |                                                                              |                                                                              |                                                                              |
| SW15     | POS. 2            |                                                                              |                                                                              |                                                                              |

<!-- image -->

<!-- image -->

## 2.8    DIP Switch

The table below describes the DIP switches of S32G-VNP-RDB3.

Table 9.  DIP switches

| Switch   | Default setting   | Description                                                                                                        |
|----------|-------------------|--------------------------------------------------------------------------------------------------------------------|
| SW4[x]   | OFF               | ON : S32G399A parallel RCON[x-1] = 1, where x = 1d to 8d OFF: S32G399A parallel RCON [x-1] = 0, where x = 1d to 8d |
| SW5[x]   | OFF               | ON : S32G399A Parallel RCON[x+7] = 1, where x = 1d to 8d OFF: S32G399A Parallel RCON[x+7] = 0, where x = 1d to 8d  |

<!-- image -->

| SW6[x]   | OFF   | ON : S32G399A Parallel RCON[x+15] = 1, where x = 1d to 8d OFF: S32G399A Parallel RCON[x+15] = 0, where x = 1d to 8d                        |
|----------|-------|--------------------------------------------------------------------------------------------------------------------------------------------|
| SW7[x]   | OFF   | ON : S32G399A Parallel RCON[x+23] = 1, where x = 1d to 8d OFF: S32G399A Parallel RCON[x+23] = 0, where x = 1d to 8d                        |
| SW3[1]   | ON    | ON : Connects the S32G399A uSDHC interface to SD card. OFF : Connects the S32G399A uSDHC interface to eMMC chip.                           |
| SW8[1]   | ON    | Please refer to chapter3.8 SerDes Interface of this document                                                                               |
| SW17[1]  | ON    | Please refer to chapter3.8 SerDes Interface of this document                                                                               |
| SW17[2]  | ON    | Please refer to chapter3.8 SerDes Interface of this document                                                                               |
| SW17[3]  | ON    | Please refer to chapter3.8 SerDes Interface of this document                                                                               |
| SW17[4]  | ON    | Please refer to chapter3.8 SerDes Interface of this document                                                                               |
| SW11[1]  | OFF   | ON : Connects GPIO6,GPIO7,GPIO95 to U128(RGB LED) OFF : Connects GPIO6,GPIO7,GPIO95 to J5 connector                                        |
| SW9[1]   | OFF   | 1-OFF, 2-OFF : BOOTMOD1 value=0 1-ON, 2-OFF : BOOTMOD1 value=1 1-OFF,2-ON : BOOTMOD1 value=RESET_B                                         |
| SW9[2]   | OFF   | 1-ON, 2-ON : BOOTMOD1 value=INV_RESET_B                                                                                                    |
| SW10[1]  | ON    | 1-OFF, 2-OFF : BOOTMOD0 value=0 1-ON, 2-OFF : BOOTMOD0 value=1 1-OFF,2-ON : BOOTMOD0 value=RESET_B 1-ON, 2-ON : BOOTMOD0 value=INV_RESET_B |
| SW10[2]  | OFF   | 1-OFF, 2-OFF : BOOTMOD0 value=0 1-ON, 2-OFF : BOOTMOD0 value=1 1-OFF,2-ON : BOOTMOD0 value=RESET_B 1-ON, 2-ON : BOOTMOD0 value=INV_RESET_B |

The Parallel RCON[x] is used to configure the value of BOOT\_CFG1 when S32G399A is in BOOT from RCON mode.  To  understand  the  BOOT\_CFG1,  please  refer  to  the  S32G3\_fuse\_map.xlsx  attached  to  S32G3 Reference Manual.

The table below describes the necessary switch setting of multiple boot modes.

Table 10. The setting of boot modes

| Switch   | SD Boot Mode Setting (default)   | eMMC Boot Mode Setting   | NOR Flash Boot Mode Setting   | Serial Boot Mode Setting   |
|----------|----------------------------------|--------------------------|-------------------------------|----------------------------|
| SW3      | ON                               | OFF                      | -                             | -                          |
| SW4      | 7-ON, REST-OFF                   | 6,7-ON, REST-OFF         | ALL-OFF                       | ALL-OFF                    |
| SW5      | ALL-OFF                          | ALL-OFF                  | ALL-OFF                       | ALL-OFF                    |

<!-- image -->

| SW6   | ALL-OFF      | ALL-OFF      | ALL-OFF      | ALL-OFF      |
|-------|--------------|--------------|--------------|--------------|
| SW7   | ALL-OFF      | ALL-OFF      | ALL-OFF      | ALL-OFF      |
| SW9   | 1-OFF, 2-OFF | 1-OFF, 2-OFF | 1-OFF, 2-OFF | 1-OFF, 2-OFF |
| SW10  | 1-ON, 2-OFF  | 1-ON, 2-OFF  | 1-ON, 2-OFF  | 1-OFF, 2-OFF |

## 2.9    Jumpers

The table below describes the jumpers of S32G-VNP-RDB3.

Table 11. Jumpers

| Part   | Type            | Default setting         | Description                                                                                                                                                                             |
|--------|-----------------|-------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| J184   | 1 x 2 connector | 1-2 Shorted             | 1-2 Open : VR5510 enters normal mode after power on.(The VR5510 watchdog will be enabled) 1-2 Shorted : VR5510 enters debug mode after power on. (The VR5510 watchdog will be disabled) |
| J180   | 2 x 2 connector | 1-2 Shorted 3-4 Shorted | Reserved                                                                                                                                                                                |
| J181   | 1 x 2 connector | 1-2 Open                | Reserved                                                                                                                                                                                |
| J185   | 1 x 2 connector | 1-2 Open                | 1-2 Open : Disconnect the VR5510 FS0B signal to the functional safety management circuit. 1-2 Shorted : Connect the VR5510 FS0B signal to the functional safety management circuit.     |
| J186   | 2 x 2 connector | 1-2 Open 3-4 Shorted    | 1-2 Open, 3-4 Shorted: RVBUS resistor value is 22Kohm. 1-2 Shorted, 3-4 Open: RVBUS resistor value is 1Kohm. Note: For details, please refer to the USB PHY datasheet.                  |
| J189   | 2 x 2 connector | 1-2 Open 3-4 Shorted    | 1-2 Open, 3-4 Shorted: SJA1110 performs NVM boot(SPI Flash). 1-2 Shorted, 3-4 Shorted: SJA1110 performs SDL boot. 1-2 Open, 3-4 Open: Reserved 1-2 Shorted, 3-4 Open: Reserved          |

<!-- image -->

| J190   | 3 x 2 connector   | 1-2 Shorted 3-4 Shorted 5-6 Shorted   | J190 can be used for CAN PHY testing.   |
|--------|-------------------|---------------------------------------|-----------------------------------------|
| J191   | 3 x 2 connector   | 1-2 Shorted 3-4 Open 5-6 Shorted      | J191 can be used for CAN PHY testing.   |
| J192   | 3 x 2 connector   | 1-2 Shorted 3-4 Open 5-6 Shorted      | J192 can be used for CAN PHY testing.   |
| J193   | 3 x 2 connector   | 1-2 Shorted 3-4 Shorted 5-6 Shorted   | J193 can be used for CAN PHY testing.   |
| J194   | 3 x 2 connector   | 1-2 Shorted 3-4 Open 5-6 Shorted      | J194 can be used for CAN PHY testing.   |
| J195   | 3 x 2 connector   | 1-2 Shorted 3-4 Open 5-6 Shorted      | J194 can be used for CAN PHY testing.   |

## 2.10    LEDs

The table below describes the LEDs of S32G-VNP-RDB3.

Table 12. LEDs

| LED                                                              | Color         | Description                                                        |
|------------------------------------------------------------------|---------------|--------------------------------------------------------------------|
| D33                                                              | Green         | Glows when SJA1110 configuration is OK                             |
| D7                                                               | Red/Green     | Red: UART1 output is in progress Green: UART1 input is in progress |
| D8                                                               | Red/Green     | Red: UART0 output is in progress Green: UART0 input is in progress |
| D36                                                              | Green         | Glows when SSD works in normal                                     |
| D2                                                               | Red(top)      | Glows when board is resetting.                                     |
| D2                                                               | Green(bottom) | Glows when board is power-on.                                      |
| U128 Note: To control U128, SW11[1] should be set to 'ON' status | Green         | Glows when GPIO95 is Low level.                                    |
| U128 Note: To control U128, SW11[1] should be set to 'ON' status | Red           | Glows when GPIO7 is Low level.                                     |
| U128 Note: To control U128, SW11[1] should be set to 'ON' status | Blue          | Glows when GPIO6 is Low level.                                     |

<!-- image -->

## 3    Functional Description

## 3.1    Power supplies

The power supply of S32G-VNP-RDB3 is comprised of two parts: external 12V AC-DC power adapter and onboard PMIC.

The specifications of the 12V AC-DC power adapter are as follows:

- Input: 110-240V AC, 50/60 Hz
- Output: 12 VDC, 6.67A, 80W MAX

The figure below shows the S32G-VNP-RDB3 power supply block diagram.

Figure 3. The power supply block diagram of S32G-VNP-RDB3

<!-- image -->

<!-- image -->

## 3.2    Boot

The BootROM of S32G399A is responsible for booting customer applications and the HSE\_H FW. It supports Serial Boot, Boot from RCON, Boot from Fuses. Combined value of Boot mode pins, FUSE\_SEL fuse status and Lifecycle control the boot mode  1 . Boot from fuses needs to blow the FUSE\_SEL fuse of S32G399A. By default, the FUSE\_SEL fuse of S32G399A is not blown  2 . So out of factory, the S32G-VNPRDB3 supports two boot modes: serial boot mode and boot from RCON. The figure below shows the related circuit of boot mode pin0 and pin1.

Figure 4. Boot mode pins

<!-- image -->

The values of boot mode pin0 and pin1 are set by SW9 and SW10. The table below shows the relationship of  boot mode pin values and the setting of SW9 and SW10.

Table 13. Values of boot mode pins

| Switch   | Setting     | Value of boot mode pins   |
|----------|-------------|---------------------------|
| SW9      | 1-OFF,2-OFF | BOOTMOD1 value=0          |
| SW9      | 1-ON, 2-OFF | BOOTMOD1 value=1          |

<!-- image -->

| 1-OFF,2-ON   | BOOTMOD1 value=RESET_B     |
|--------------|----------------------------|
| 1-ON, 2-ON   | BOOTMOD1 value=INV_RESET_B |
| 1-OFF,2-OFF  | BOOTMOD0 value=0           |
| 1-ON, 2-OFF  | BOOTMOD0 value=1           |
| 1-OFF,2-ON   | BOOTMOD0 value=RESET_B     |
| 1-ON, 2-ON   | BOOTMOD0 value=INV_RESET_B |

RCON uses up to 32 general-purpose I/O pins, RCON[0] to RCON[31]. They are latched on functional reset deassertion. RCON[31:0] pins corresponds bit by bit to values in the fuse word BOOT\_CFG1[31:0]. Values of these pins will be sampled during S32G399A reset, and these pins can be used for other functions after boot (to be precise after the sample stage). The figure below shows the diagram of RCON pins.

Figure 5. RCON pins

<!-- image -->

MAX4886ETO+ is a signal multiplexing chip. In Figure5, by changing the settings of SW4, SW5, SW6 and SW7, the values of the RCON pins will be changed during reset. Combined with the boot mode pins, users can select different boot modes, boot media, speed, etc..

For detailed information of RCON pins, please refer to the S32G3\_fuse\_map.xlsx in the attachment of S32G3 Reference Manual.

1. Please refer to Chapter 31 of S32G3 Reference Manual to know more detailed information for boot mode.

2. For method of blowing FUSE\_SEL fuse, contact your local field applications engineer (FAE) or sales representative.

<!-- image -->

## 3.3    Reset

S32G-VNP-RDB3 supports two kinds of reset: power-on reset and warm reset. Both could reset most of hardware components on board. Power-on reset will be initiated by depressing SW1 and self-triggered reset (warm reset) will be initiated by depressing SW2. Except for the entire board reset, the Ethernet switch and PHY can be individually reset by S32G399A GPIOs. The figure below shows the Reset Tree of S32G-VNPRDB3.

Figure 6. Reset Tree of S32G-VNP-RDB3

<!-- image -->

<!-- image -->

## 3.4    Clocks

The S32G399A has multiple clock sources including FIRC, SIRC, FXOSC. They can be selected to drive clock of system peripherals, cores, and infrastructure. S32G-VNP-RDB3 uses a 40 MHz crystal oscillator as FXOSC. FIRC and SIRC are internal clocks on chip.

The figure below shows the Clock Tree of S32G-VNP-RDB3.

Figure 7. Clock Tree of S32G-VNP-RDB3

<!-- image -->

<!-- image -->

## 3.5    JTAG

JTAG debug is supported by direct connection to the header connector J48. Users can connect a dedicated debugger, such as Lauterbach or S32 Debug Probe.

On the S32G-VNP-RDB3, the 20-pin JTAG header connector carries JTAG signals and the additional signals for S32G399A debugging, and the 10-pin JTAG header connector carries JTAG signals for SJA1110 debugging.

## 3.6    Aurora Trace

The S32G-VNP-RDB3 supports Aurora trace for S32G399A, which can be accessed through J57.

## 3.7    External Memory and Storage

The S32G-VNP-RDB3 supports three kinds of external memories: LPDDR4, NOR Flash and SD/eMMC. The table below shows the memory map of the DDR and NOR Flash.

Table 14. The memory map of DDR and NOR Flash

| Memory    | Start                                                 | End                                                    |
|-----------|-------------------------------------------------------|--------------------------------------------------------|
| DDR(M7)   | 0x00_6000_0000(0~2G bytes)                            | 0x00_DFFF_FFFF(0~2G bytes)                             |
| DDR(A53)  | 0x00_8000_0000(0~2G bytes) 0x08_0000_0000(0~4G bytes) | 0x00_ FFFF_FFFF(0~2G bytes) 0x08_FFFF_FFFF(0~4G bytes) |
| NOR Flash | 0x00_0000_0000(0~64M bytes)                           | 0x00_03FF_FFFF(0~64M bytes)                            |

## 3.7.1    LPDDR4

The S32G-VNP-RDB3 uses a 1024 Meg x 32 (2 channels x 16 I/O) LPDDR4 SDRAM chip for a total RAM memory of 4GB, and it supports inline-ECC and self-refresh.

This LPDDR4 SDRAM need to be supplied by 1.1V and 1.8V DC power, that are respectively supplied by the BUCK3 and LDO2 of VR5510. The figure below shows the connection of LPDDR4 SDRAM.

<!-- image -->

Figure 8. The connection of LPDDR4 SDRAM

<!-- image -->

## 3.7.2    NOR flash

The S32G399A QuadSPI module provides a common interface to single, dual, and octal NOR flash memory, including Hyperflash memory.

On S32G-VNP-RDB3, QuadSPI module is connected to a MX25UW51245G 64MB octal flash memory chip. This chip supports octal flash interface with simultaneous read and write, double transfer rate(DTR) mode and clock frequency up to 200 MHz. The figure below shows the connection between S32G399A and MX25UW51245G.

Figure 9. The connection between S32G399A and MX25UW51245G

<!-- image -->

<!-- image -->

## 3.7.3    SD/eMMC

On S32G-VNP-RDB3, SD card interface and eMMC are connected to the S32G399A uSDHC module with a multiplexed logic.

The uSDHC module acts as a bridge, passing host bus transactions to the SD/eMMC cards by sending commands and performing data accesses to/from the cards. The figure below shows the connection between the S32G399A and SD/eMMC.

Figure 10. The connection of S32G399A and SD/eMMC

<!-- image -->

There are two analog switches MAX4886 on the S32G-VNP-RDB3.  One is used for multiplexing control signals, and the other is used for multiplexing data signals.

Users can select the connection of the SD card or eMMC by SW3. When SW3 is set to 'ON' status, the S32G399A is connected to SD card interface, and IO level can be selected by VSELECT(PD\_09) pin. If VSELECT pin is low level or Hi-Z state, the uSDHC IO level is 3.3V; if VSELECT is high level, the uSDHC IO level is 1.8V. When SW3 is set to 'OFF' status, the S32G399A is connected to eMMC, the IO level is always 1.8V.

<!-- image -->

## 3.8    SerDes Interface

The S32G399A has two SerDes instances, and each instance supports two lanes. The S32G-VNP-RDB3 supports both SGMII and PCI Express high-speed serial communication interfaces.

The figure below shows the SerDes routing diagram of S32G-VNP-RDB3.

Figure 11. SerDes routing diagram of S32G-VNP-RDB3

<!-- image -->

The table below describes the optional SerDes connection on S32G-VNP-RDB3.

Table 15. The multiplexing setting of SerDes

| SW17 -bit1   | SW17 -bit2   | SW17 -bit3   | SW17 -bit4   | SW8   | SerDes   | Lan0                   | Lan1                 |
|--------------|--------------|--------------|--------------|-------|----------|------------------------|----------------------|
| ON           | ON           | X            | OFF          | ON    | SerDes1  | SJA1110 PORT4          | AQR113C              |
| ON           | ON           | X            | OFF          | ON    | SerDes0  | M.2 E-key slot (J56)   | M.2 E-key slot (J56) |
| ON           | ON           | X            | OFF          | OFF   | SerDes1  | PCIe X1 socket (P1)    | SJA1110 PORT4        |
| ON           | ON           | X            | OFF          | OFF   | SerDes0  | M.2 E-key slot (J56)   | M.2 E-key slot (J56) |
| ON           | ON           | X            | ON           | ON    | SerDes1  | SJA1110 PORT4          | AQR113C              |
| ON           | ON           | X            | ON           | ON    | SerDes0  | M.2 M-key slot (J47)   | M.2 M-key slot (J47) |
| ON           | ON           | X            | ON           | OFF   | SerDes1  | PCIe X1 Connector (P1) | SJA1110 PORT4        |
| ON           | ON           | X            | ON           | OFF   | SerDes0  | M.2 M-key slot (J47)   | M.2 M-key slot (J47) |
| ON           | OFF          | OFF          | X            | ON    | SerDes1  | SJA1110 PORT4          | AQR113C              |

<!-- image -->

|     |     |     |    |     | SerDes0   | SJA1110 PORT1       | NA            |
|-----|-----|-----|----|-----|-----------|---------------------|---------------|
| ON  | OFF | OFF | X  | OFF | SerDes1   | PCIe X1 socket (P1) | SJA1110 PORT4 |
| ON  | OFF | OFF | X  | OFF | SerDes0   | SJA1110 PORT1       | NA            |
| OFF | OFF | OFF | X  | ON  | SerDes1   | NA                  | AQR113C       |
| OFF | OFF | OFF | X  | ON  | SerDes0   | SJA1110 PORT1/NA    | SJA1110 PORT4 |
| OFF | OFF | OFF | X  | OFF | SerDes1   | PCIe X1 socket (P1) | NA            |
| OFF | OFF | OFF | X  | OFF | SerDes0   | SJA1110 PORT1/NA    | SJA1110 PORT4 |

<!-- image -->

## 3.9    Ethernet

The GMAC and PFE of the S32G399A enables a host application to transmit and receive data over an Ethernet network in compliance with IEEE 802.3-2015, and the PFE of S32G399A additionally offloads the processing of Ethernet packets from the host cores, yielding higher performance and lower power than pure software processing can achieve.

The figure below shows the Ethernet connections of S32G-VNP-RDB3.

Figure 12. Ethernet connections of S32G-VNP-RDB3

<!-- image -->

*: For detailed configuration of the multiplexer, please refer to the chapter3.8 SerDes Interface.

<!-- image -->

## 3.9.1    Ethernet switch

The SJA1110 is a firmware based automotive ethernet switch, with an embedded ARM Cortex-M7 core. It has a SPI interface which is used to communicate with S32G399A. Apart from the SPI\_HOST, it also contains the SPI\_PER interface which can operate as a SPI master for access to other SPI slaves or as a SPI slave to enable inter-processor communication applications. The ENET block of SJA1110 provides an Ethernet connectivity with the internal switch core and supports the SMI\_OUT, which is an SMI master to provide access to SMI slaves.

Table 16. SJA1110 port description

| SJA1110 PORT   | Function             | Connection       |
|----------------|----------------------|------------------|
| PORT1          | 100BASE-TX (default) | RJ45 connector   |
| PORT1          | SGMII                | S32G399A         |
| PORT2          | RGMII                | AR8035           |
| PORT3          | RGMII                | AR8035           |
| PORT4          | SGMII                | S32G399A         |
| PORT5          | 100BASE-T1           | Mini50 connector |
| PORT6          | 100BASE-T1           | Mini50 connector |
| PORT7          | 100BASE-T1           | Mini50 connector |
| PORT8          | 100BASE-T1           | Mini50 connector |
| PORT9          | 100BASE-T1           | Mini50 connector |
| PORT10         | 100BASE-T1           | Mini50 connector |

## 3.9.2    Ethernet PHY

The table below describes the Ethernet PHYs that are used on the S32G-VNP-RDB3.

Table 17. Ethernet PHYs description

| Part   | P/N    | Connection    | Signal   | Description   |
|--------|--------|---------------|----------|---------------|
| U56    | AR8035 | SJA1110 Port3 | RGMII    | 1000BASE-T    |

<!-- image -->

| U57   | AR8035   | SJA1110 Port2     | RGMII   | 1000BASE-T                                                                                                   |
|-------|----------|-------------------|---------|--------------------------------------------------------------------------------------------------------------|
| U58   | KSZ9031  | S32G399A PFE_MAC2 | RGMII   | 1000BASE-T                                                                                                   |
| U84   | KSZ9031  | S32G399A GMAC0    | RGMII   | 1000BASE-T                                                                                                   |
| U86   | AQR113C  | S32G399A PFE_MAC1 | SGMII   | AQR113C supports multiple speed operation modes. For more details, please refer to chapter SerDes Interface. |

## 3.9.3    SMI Interface

The table below describes the SMI Interfaces of S32G-VNP-RDB3.

Table 18. SMI Interface

| SMI bus                          | Part        | SMI Address                                                                                                                                                                   |
|----------------------------------|-------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| S32G399A PD_12(MDC) PD_13(MDIO)  | U84 KSZ9031 | 0X01                                                                                                                                                                          |
| S32G399A PD_12(MDC) PD_13(MDIO)  | U86 AQR113C | 0X08                                                                                                                                                                          |
| S32G399A PE_15(MDIO) PF_02(MDC)  | U58 KSZ9031 | 0X04                                                                                                                                                                          |
| S32G399A PE_15(MDIO) PF_02(MDC)  | U46 SJA1110 | 100BASE-T1 PHY1(Port5 ) 0X09 100BASE-T1 PHY2(Port6 ) 0X0A 100BASE-T1 PHY3(Port7 ) 0X0B 100BASE-T1 PHY4(Port8 ) 0X0C 100BASE-T1 PHY5(Port9 ) 0X0D 100BASE-T1 PHY6(Port10) 0X0E |
| SJA1110 SMI_OUT_MDC SMI_OUT_MDIO | U57 AR8035  | 0X04                                                                                                                                                                          |
| SJA1110 SMI_OUT_MDC SMI_OUT_MDIO | U56 AR8035  | 0X05                                                                                                                                                                          |

## 3.10    CAN

The table below describes the CAN transceiver connections on the S32G-VNP-RDB3.

Table 19. CAN transceiver Connections

| CAN transceiver   | CAN transceiver   | Connection   | Connection   | Signal        |
|-------------------|-------------------|--------------|--------------|---------------|
| U17 TJA1043       | TXD               | U43 S32G399A | PC_12        | LLCE_CAN0_TXD |

<!-- image -->

| RXD   | U43 S32G399A     | PC_11   | LLCE_CAN0_RXD   |
|-------|------------------|---------|-----------------|
| EN    | U24 PCAL6524HEAZ | P0_1    | LLCE_CAN01_EN   |
| STB   | U24 PCAL6524HEAZ | P0_0    | LLCE_CAN01_STB  |
| TXD   | U43 S32G399A     | PJ_01   | LLCE_CAN1_TXD   |
| RXD   | U43 S32G399A     | PJ_02   | LLCE_CAN1_RXD   |
| EN    | U24 PCAL6524HEAZ | P0_1    | LLCE_CAN01_EN   |
| STB   | U24 PCAL6524HEAZ | P0_0    | LLCE_CAN01_STB  |
| TXD   | U43 S32G399A     | PJ_03   | LLCE_CAN2_TXD   |
| RXD   | U43 S32G399A     | PJ_04   | LLCE_CAN2_RXD   |
| EN    | U24 PCAL6524HEAZ | P0_3    | LLCE_CAN2_EN    |
| STB   | U24 PCAL6524HEAZ | P0_2    | LLCE_CAN2_STB   |
| TXD   | U43 S32G399A     | PJ_05   | LLCE_CAN3_TXD   |
| RXD   | U43 S32G399A     | PJ_06   | LLCE_CAN3_RXD   |
| EN    | U24 PCAL6524HEAZ | P0_5    | LLCE_CAN3_EN    |
| STB   | U24 PCAL6524HEAZ | P0_4    | LLCE_CAN3_STB   |
| TXD   | U43 S32G399A     | PJ_11   | LLCE_CAN6_TXD   |
| RXD   | U43 S32G399A     | PJ_12   | LLCE_CAN6_RXD   |
| EN    | U24 PCAL6524HEAZ | P1_1    | LLCE_CAN67_EN   |
| STB   | U24 PCAL6524HEAZ | P1_0    | LLCE_CAN67_STB  |

<!-- image -->

| U69 TJA1153   | TXD   | U43 S32G399A     | PJ_13   | LLCE_CAN7_TXD   |
|---------------|-------|------------------|---------|-----------------|
| U69 TJA1153   | RXD   | U43 S32G399A     | PJ_14   | LLCE_CAN7_RXD   |
| U69 TJA1153   | EN    | U24 PCAL6524HEAZ | P1_1    | LLCE_CAN67_EN   |
| U69 TJA1153   | STB   | U24 PCAL6524HEAZ | P1_0    | LLCE_CAN67_STB  |
|               | TXD   | U43 S32G399A     | PK_03   | LLCE_CAN10_TXD  |
|               | RXD   | U43 S32G399A     | PK_04   | LLCE_CAN10_RXD  |
|               | EN    | U24 PCAL6524HEAZ | P1_5    | LLCE_CANAB_EN   |
|               | STB   | U24 PCAL6524HEAZ | P1_4    | LLCE_CANAB_STB  |
|               | TXD   | U43 S32G399A     | PK_05   | LLCE_CAN11_TXD  |
|               | RXD   | U43 S32G399A     | PK_06   | LLCE_CAN11_RXD  |
|               | EN    | U24 PCAL6524HEAZ | P1_5    | LLCE_CANAB_EN   |
|               | STB   | U24 PCAL6524HEAZ | P1_4    | LLCE_CANAB_STB  |
|               | TXD   | U43 S32G399A     | PK_11   | LLCE_CAN14_TXD  |
|               | RXD   | U43 S32G399A     | PK_12   | LLCE_CAN14_RXD  |
|               | EN    | U24 PCAL6524HEAZ | P2_1    | LLCE_CANEF_EN   |
|               | STB   | U24 PCAL6524HEAZ | P2_0    | LLCE_CANEF_STB  |
|               | TXD   | U43 S32G399A     | PK_13   | LLCE_CAN15_TXD  |
|               | RXD   | U43 S32G399A     | PK_14   | LLCE_CAN15_RXD  |
|               | EN    | U24 PCAL6524HEAZ | P2_1    | LLCE_CANEF_EN   |

<!-- image -->

|             | STB   | U24 PCAL6524HEAZ   | P2_0   | LLCE_CANEF_STB   |
|-------------|-------|--------------------|--------|------------------|
| U19 TJA1153 | TXD   | U43 S32G399A       | PJ_07  | LLCE_CAN4_TXD    |
| U19 TJA1153 | RXD   | U43 S32G399A       | PJ_08  | LLCE_CAN4_RXD    |
| U19 TJA1153 | EN    | U24 PCAL6524HEAZ   | P0_7   | LLCE_CAN45_EN    |
| U19 TJA1153 | STB   | U24 PCAL6524HEAZ   | P0_6   | LLCE_CAN45_STB   |
|             | TXD   | U43 S32G399A       | PJ_09  | LLCE_CAN5_TXD    |
|             | RXD   | U43 S32G399A       | PJ_10  | LLCE_CAN5_RXD    |
|             | EN    | U24 PCAL6524HEAZ   | P0_7   | LLCE_CAN45_EN    |
|             | STB   | U24 PCAL6524HEAZ   | P0_6   | LLCE_CAN45_STB   |
|             | TXD   | U43 S32G399A       | PJ_15  | LLCE_CAN8_TXD    |
|             | RXD   | U43 S32G399A       | PK_00  | LLCE_CAN8_RXD    |
|             | EN    | U24 PCAL6524HEAZ   | P1_3   | LLCE_CAN89_EN    |
|             | STB   | U24 PCAL6524HEAZ   | P1_2   | LLCE_CAN89_STB   |
|             | TXD   | U43 S32G399A       | PK_01  | LLCE_CAN9_TXD    |
|             | RXD   | U43 S32G399A       | PK_02  | LLCE_CAN9_RXD    |
|             | EN    | U24 PCAL6524HEAZ   | P1_3   | LLCE_CAN89_EN    |
|             | STB   | U24 PCAL6524HEAZ   | P1_2   | LLCE_CAN89_STB   |
| U22 TJA1463 | TXD   | U43 S32G399A       | PK_07  | LLCE_CAN12_TXD   |
| U22 TJA1463 | RXD   | U43 S32G399A       | PK_08  | LLCE_CAN12_RXD   |

<!-- image -->

|             | EN   | U24 PCAL6524HEAZ   | P1_7   | LLCE_CANCD_EN   |
|-------------|------|--------------------|--------|-----------------|
|             | STB  | U24 PCAL6524HEAZ   | P1_6   | LLCE_CANCD_STB  |
| U67 TJA1463 | TXD  | U43 S32G399A       | PK_09  | LLCE_CAN13_TXD  |
| U67 TJA1463 | RXD  | U43 S32G399A       | PK_10  | LLCE_CAN13_RXD  |
| U67 TJA1463 | EN   | U24 PCAL6524HEAZ   | P1_7   | LLCE_CANCD_EN   |
| U67 TJA1463 | STB  | U24 PCAL6524HEAZ   | P1_6   | LLCE_CANCD_STB  |
| U15 TJA1043 | TXD  | U43 S32G399A       | PB_01  | FLEX_CAN0_TXD   |
| U15 TJA1043 | RXD  | U43 S32G399A       | PB_02  | FLEX_CAN0_RXD   |
| U15 TJA1043 | EN   | U24 PCAL6524HEAZ   | P2_3   | FLEX_CAN0_EN    |
| U15 TJA1043 | STB  | U24 PCAL6524HEAZ   | P2_2   | FLEX_CAN0_STB   |
|             | TXD  | U43 S32G399A       | PB_03  | FLEX_CAN1_TXD   |
|             | RXD  | U43 S32G399A       | PB_04  | FLEX_CAN1_RXD   |
|             | EN   | U24 PCAL6524HEAZ   | P2_5   | FLEX_CAN1_EN    |
|             | STB  | U24 PCAL6524HEAZ   | P2_4   | FLEX_CAN1_STB   |

## 3.11    LIN and UART

The table below describes the LIN and UART connections on the S32G-VNP-RDB3.

Table 20. LIN and UART Connections

| LIN PHY    | LIN PHY   | S32G399A IO   | Description   |
|------------|-----------|---------------|---------------|
| U3 FT232RQ | TXD       | PC_09         | UART0         |

<!-- image -->

| U2 FT232RQ    | TXD   | PA_13   | UART1                   |
|---------------|-------|---------|-------------------------|
| U2 FT232RQ    | RXD   | PB_00   | UART1                   |
|               | TXD1  | PK_15   | LLCE_LIN0 (Master mode) |
|               | RXD1  | PL_00   | LLCE_LIN0 (Master mode) |
|               | TXD2  | PC_08   | LLCE_LIN1 (Master mode) |
|               | RXD2  | PC_04   | LLCE_LIN1 (Master mode) |
|               | TXD3  | PC_05   | LLCE_LIN2 (Master mode) |
|               | RXD3  | PC_06   | LLCE_LIN2 (Master mode) |
|               | TXD4  | PC_07   | LLCE_LIN3 (Master mode) |
|               | RXD4  | PL_07   | LLCE_LIN3 (Master mode) |
| U100 TJA1021T | TXD   | PB_11   | FLEX_LIN2 (Slave mode)  |
| U100 TJA1021T | RXD   | PB_12   | FLEX_LIN2 (Slave mode)  |

## 3.12    FlexRay

The table below describes the FlexRay connections on the S32G-VNP-RDB3.

Table 21. FlexRay Connections

| FlexRay PHY   | FlexRay PHY   | Connection       | Connection   | Signal        |
|---------------|---------------|------------------|--------------|---------------|
| U23 TJA1081   | TXD           | U43 S32G399A     | PL_02        | LLCE_FR_TXD_A |
| U23 TJA1081   | TXEN          | U43 S32G399A     | PL_01        | LLCE_FR_TXE_A |
| U23 TJA1081   | RXD           | U43 S32G399A     | PL_03        | LLCE_FR_RXD_A |
| U23 TJA1081   | STBN          | U24 PCAL6524HEAZ | P2_6         | EIO_FR_STBN_A |

<!-- image -->

| EN   | U24 PCAL6524HEAZ   | P2_7   | EIO_FR_EN_A   |
|------|--------------------|--------|---------------|

## 3.13    DSPI

The table below describes the DSPI connections on the S32G-VNP-RDB3.

Table 22. DSPI Connections

| Interface   | S32G399A Port   | S32G399A Port   | Connection                      |
|-------------|-----------------|-----------------|---------------------------------|
| DSPI1       | SOUT            | PA_06           | Connects to J5. (SW11[1] = OFF) |
| DSPI1       | SIN             | PF_15           | Connects to J5. (SW11[1] = OFF) |
| DSPI1       | SCK             | PA_08           | Connects to J5. (SW11[1] = OFF) |
| DSPI1       | PCS0            | PA_07           | Connects to J5.                 |
| DSPI5       | SOUT            | PA_11           | Connects to SJA1110.            |
| DSPI5       | SIN             | PA_10           | Connects to SJA1110.            |
| DSPI5       | SCK             | PA_09           | Connects to SJA1110.            |
| DSPI5       | PCS0            | PA_12           | Connects to SJA1110.            |
| DSPI5       | GPIO(PCS)       | PB_14           | Connects to SJA1110.            |

## 3.14    I2C

The I2C module is a functional unit that provides a two-wire bidirectional serial bus. Its operating speeds is up to 100 kbps in the standard mode defined and up to 400 kbps in the fast mode.

The table below describes the I2C connections on the S32G-VNP-RDB3.

Table 23. I2C Connections

| S32G399A Interface            | Part   | Part      | Address          | Description                                                                                                                       |
|-------------------------------|--------|-----------|------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| I2C0_SDA PB_00 I2C0_SCL PB_01 | U145   | AT24C01C  | 1010001R/W 0x50  | I2C signal is not connected by default. If the serial RCON function is to be used, please populate R1244, R1245, remove R16, R141 |
| I2C0_SCL PC_00 I2C0_SDA PB_15 | U83    | PCA85073A | 1010001R/W, 0x51 |                                                                                                                                   |
| I2C0_SCL PC_00 I2C0_SDA PB_15 | U59    | Si5332    | 1101010R/W, 0x6A | I2C signal is not connected by default.                                                                                           |

<!-- image -->

|                               | P1     | PCIe x1 socket   |                                                  |
|-------------------------------|--------|------------------|--------------------------------------------------|
|                               | U24    | PCAL6524HEAZ     | 0100010R/W, 0x22                                 |
|                               | U137 1 | PCT2075          | 1001000R/W, 0x48                                 |
| I2C4_SDA PC_01 I2C4_SCL PC_02 | U41    | VR5510           | Main : 0100000R/W, 0x20 Safety: 0100001R/W, 0x21 |
| I2C4_SDA PC_01 I2C4_SCL PC_02 | U94    | PFS5600          | 0011000R/W, 0x18                                 |
|                               | U92    | PF5300           | 0101000R/W, 0x28                                 |
|                               | U108   | PF5020           | 0001000R/W, 0x08                                 |
|                               | U96    | PF5020           | 0001001R/W, 0x09                                 |
|                               | U136   | INA231           | 1000000R/W, 0x40                                 |
| I2C2_SCL PB_05 I2C2_SDA PB_06 | J5     | Connector        |                                                  |

## 3.15    USB

The USB PHY connects to external USB devices through J4 (MICRO\_AB). It supports both Host and Device mode. When the USB-A to Micro-B cable is plugged in, the USB PHY works in Device mode. When the OTG cable is plugged in, the USB PHY works in Host mode. When using Host mode, it is recommended the load current is less than 1A.

The table below describes the USB connections on the S32G-VNP-RDB3.

Table 24. USB Connections

| USB PHY     | USB PHY   | S32G399A Interface   |
|-------------|-----------|----------------------|
| U8 USB83340 | DATA0     | PD_14                |
| U8 USB83340 | DATA1     | PD_15                |
| U8 USB83340 | DATA2     | PE_00                |
| U8 USB83340 | DATA3     | PE_01                |
| U8 USB83340 | DATA4     | PL_12                |
| U8 USB83340 | DATA5     | PL_13                |
| U8 USB83340 | DATA6     | PL_14                |
| U8 USB83340 | DATA7     | PH_00                |
| U8 USB83340 | NXT       | PL_11                |
| U8 USB83340 | STP       | PL_10                |
| U8 USB83340 | DIR       | PL_09                |

<!-- image -->

| CLKOUT   | PL_08   |
|----------|---------|

## 4    Cables Description

The table below describes the Cable of Connector J6.

## Table 25. J6 Cable

| Signal       | Cable color   |   connector |   connector | Cable color   | Signal       |
|--------------|---------------|-------------|-------------|---------------|--------------|
| FlexRay_BP   | Blue          |           2 |           1 | White         | FlexRay_BM   |
| FlexCAN0_H   | Green         |           4 |           3 | White         | FlexCAN0_L   |
| FlexCAN1_H   | Green         |           6 |           5 | White         | FlexCAN1_L   |
| LLCE_CAN0_H  | Yellow        |           8 |           7 | White         | LLCE_CAN0_L  |
| LLCE_CAN1_H  | Yellow        |          10 |           9 | White         | LLCE_CAN1_L  |
| LLCE_CAN2_H  | Yellow        |          12 |          11 | White         | LLCE_CAN2_L  |
| LLCE_CAN3_H  | Yellow        |          14 |          13 | White         | LLCE_CAN3_L  |
| LLCE_CAN4_H  | Yellow        |          16 |          15 | White         | LLCE_CAN4_L  |
| LLCE_CAN5_H  | Yellow        |          18 |          17 | White         | LLCE_CAN5_L  |
| LLCE_CAN6_H  | Yellow        |          20 |          19 | White         | LLCE_CAN6_L  |
| LLCE_CAN7_H  | Yellow        |          22 |          21 | White         | LLCE_CAN7_L  |
| LLCE_CAN8_H  | Yellow        |          24 |          23 | White         | LLCE_CAN8_L  |
| LLCE_CAN9_H  | Yellow        |          26 |          25 | White         | LLCE_CAN9_L  |
| LLCE_CAN10_H | Yellow        |          28 |          27 | White         | LLCE_CAN10_L |
| LLCE_CAN11_H | Yellow        |          30 |          29 | White         | LLCE_CAN11_L |
| LLCE_CAN12_H | Yellow        |          32 |          31 | White         | LLCE_CAN12_L |

<!-- image -->

| LLCE_CAN13_H   | Yellow   |   34 |   33 | White   | LLCE_CAN13_L   |
|----------------|----------|------|------|---------|----------------|
| LLCE_CAN14_H   | Yellow   |   36 |   35 | White   | LLCE_CAN14_L   |
| LLCE_CAN15_H   | Yellow   |   38 |   37 | White   | LLCE_CAN15_L   |
| GND            | Black    |   40 |   39 | Black   | GND            |

The table below describes the Cable of Connector J5.

## Table 26. J5 Cable

| Signal                                | Cable color   |   connector |   connector | Cable color   | Signal                                |
|---------------------------------------|---------------|-------------|-------------|---------------|---------------------------------------|
| 12_VIN                                | Red           |           2 |           1 | Orange        | 5V_OUT                                |
| 12V_OUT                               | Orange        |           4 |           3 | Orange        | 3V3_OUT                               |
| GND                                   | Black         |           6 |           5 | Black         | GND                                   |
| FLEX_LIN2                             | Blue          |           8 |           7 | Black         | GND                                   |
| LLCE_LIN0                             | Blue          |          10 |           9 | Blue          | LLCE_LIN1                             |
| LLCE_LIN2                             | Blue          |          12 |          11 | Blue          | LLCE_LIN3                             |
| PB_05 GPIO[21] I2C2_SCL External IRQ2 | White         |          14 |          13 | White         | PB_06 GPIO[22] I2C2_SDA External IRQ3 |
| PA_06 GPIO[6] DSPI1_SOUT FTM1_CH2     | Yellow        |          16 |          15 | Yellow        | PF_15 GPIO[95] DSPI1_SIN FTM1_CH1     |
| PA_08 GPIO[8] DSPI1_SCK FTM1_CH0      | Yellow        |          18 |          17 | Yellow        | PA_07 GPIO[7] DSPI1_PCS0 FTM1_CH3     |
| GND                                   | Black         |          20 |          19 | White         | GPI[182] WKUP21 External IRQ7         |
| ADC_IN0                               | Green         |          22 |          21 | Black         | GND                                   |

<!-- image -->

| ADC_IN1   | Green   |   24 |   23 | Green   | ADC_IN2   |
|-----------|---------|------|------|---------|-----------|
| ADC_IN3   | Green   |   26 |   25 | Green   | ADC_IN4   |

The table below describes the Cable of Connector J53.

Table 27. J53 Cable

|   Connector | Signal          | Cable color   |
|-------------|-----------------|---------------|
|           1 |                 |               |
|           2 |                 |               |
|           3 | 100Base-T1 TRX6 | White         |
|           4 | 100Base-T1 TRX6 | Yellow        |
|           5 |                 |               |
|           6 |                 |               |
|           7 | 100Base-T1 TRX9 | White         |
|           8 | 100Base-T1 TRX9 | Yellow        |
|           9 |                 |               |
|          10 |                 |               |
|          11 | 100Base-T1 TRX5 | White         |
|          12 | 100Base-T1 TRX5 | Yellow        |
|          13 |                 |               |
|          14 |                 |               |
|          15 | 100Base-T1 TRX7 | White         |

<!-- image -->

|   16 |                  | Yellow   |
|------|------------------|----------|
|   17 |                  |          |
|   18 |                  |          |
|   19 | 100Base-T1 TRX8  | White    |
|   20 | 100Base-T1 TRX8  | Yellow   |
|   21 |                  |          |
|   22 |                  |          |
|   23 | 100Base-T1 TRX10 | White    |
|   24 |                  | Yellow   |

<!-- image -->

## 5    Revision History

| Date        |   Version | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
|-------------|-----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 28 Dec 2021 |       0.1 | Revised Initial Draft                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| 14 Jan 2022 |       0.2 | Updated format and grammar.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| 21 Jan 2022 |       0.3 | Updated format and grammar.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| 1 Mar 2023  |       0.4 | • In section "Board Version": - Added description "For detailed revision information, please refer to..." - Added brief revision information for REV E3 and REV F in table "S32G-VNP-RDB3 Board Version" • In section "Block diagram": - Removed "TJA1024HG" in "The block diagram of S32G- VNP-RDB3" • In section "S32G-VNP-RDB3 top view": - Updated the photo of "The top view of S32G-VNP-RDB3" • In section "Jumpers": - Added J190, J191, J192, J193, J194, J195 to table "Jumpers" • In section "Power supplies": - Updated the size of "The power supply block diagram of S32G-VNP-RDB3" • In section "Reset": |

<!-- image -->

## Disclaimer

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals', must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others.

While NXP has implemented advanced security features, all products may be subject to unidentified vulnerabilities. Customers are responsible for the design and operation of their applications and products to reduce the effect of these vulnerabilities on customer's applications and products, and NXP accepts no liability for any vulnerability that is discovered. Customers should implement appropriate design and operating safeguards to minimize the risks associated with their applications and products.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C -5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C -Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners. AMBA, Arm, Arm7, Arm7TDMI, Arm9, Arm11, Artisan, big.LITTLE, Cordio, CoreLink, CoreSight, Cortex, DesignStart, DynamIQ, Jazelle, Keil, Mali, Mbed, Mbed Enabled, NEON, POP, RealView, SecurCore, Socrates, Thumb, TrustZone, ULINK, ULINK2, ULINK-ME, ULINKPLUS, ULINKpro, μVision, Versatile are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.