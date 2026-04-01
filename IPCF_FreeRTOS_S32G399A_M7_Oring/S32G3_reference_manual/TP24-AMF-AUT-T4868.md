<!-- image -->

## Using S32G Family as High-Performance Compute and Central Gateway

## Kushal Shah

Automotive Processors Marketing, US August 2024

2

<!-- image -->

|  NXP  |

Public

## Agenda

- S32 automotive processing platform
- S32G family of processors
- S32G applications (automotive and beyond)
- S32G enablement and ecosystem
- S32G vehicle integration platform (GoldVIP)

## NXP S32 automotive processing platform

<!-- image -->

NXP offers scalable, diverse automotive processing with a common software foundation.

## NXP S32G family - two compatible series of processors

<!-- image -->

<!-- image -->

## NXP S32G family scalability

<!-- image -->

## NXP S32G Processors -Key Features and Target Applications

<!-- image -->

## NXP S32G3 Processors -Technical Highlights

## SAFE PROCESSING

Up to 4 Dual-Core Lockstep Arm ®

Cortex ® -M7 cores @ 400 MHz Up to 8 Cluster Lockstep Arm Cortex-A53 cores @ 1.4 GHz 16 Resource Isolation Domains

<!-- image -->

<!-- image -->

## SAFETY &amp; SECURITY

ASIL D Functional Safety Support Advanced Hardware Security Engine

## NETWORKING

20x CAN/CAN FD Interfaces LIN and FlexRay® Interfaces 1x GbE + 3x 2.5 GbE Interfaces 2x 2-lane PCI Express Gen 3 Interfaces

## NETWORK ACCELERATION

Low Latency Communication Engine Ethernet Packet Forwarding Engine

<!-- image -->

## S32G Family Lineup

## · Performance Scale

- -9.9 kDMIPS to 38.7 kDMIPS
- -ASIL D MPU

## · HW Compatibility

- -Same SoC package and pinout
- -PMIC scalability option
- PCIe -Same peripherals and accelerators

## · SW Compatibility

- -Application code compatible
- -Same BSP
- -Same boot flow
- -Same security

<!-- image -->

S32G3 Enhancements over S32G2

<!-- image -->

<!-- image -->

| Feature                                            | S32G254A                                                                                          | Feature S32G274A                                                                                  | S32G378A                                                            | S32G379A                                                            | S32G398A                                                            | S32G399A                                                            |
|----------------------------------------------------|---------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|---------------------------------------------------------------------|---------------------------------------------------------------------|---------------------------------------------------------------------|---------------------------------------------------------------------|
| Package                                            | Package 525 FC-PBGA, 19x19mm 0.8pitch                                                             | Package 525 FC-PBGA, 19x19mm 0.8pitch                                                             | 525 FC-PBGA, 19x19mm 0.8pitch                                       | 525 FC-PBGA, 19x19mm 0.8pitch                                       | 525 FC-PBGA, 19x19mm 0.8pitch                                       | 525 FC-PBGA, 19x19mm 0.8pitch                                       |
| Arm CPU Cluster 1                                  | 1x Cortex-A53 @1 GHz                                                                              | Arm Core Cluster 1 2x Cortex-A53 @1 GHz                                                           | 2x Cortex-A53@ 1.4 GHz                                              | 2x Cortex-A53@ 1.4 GHz                                              | 4x Cortex-A53 @1.4 GHz                                              | 4x Cortex-A53 @1.4 GHz                                              |
| Arm CPU Cluster 2                                  | 1x Cortex-A53 @1 GHz                                                                              | Arm Core Cluster 2 2x Cortex-A53 @1 GHz                                                           | 2x Cortex-A53@ 1.4 GHz                                              | 2x Cortex-A53@ 1.4 GHz                                              | 4x Cortex-A53 @1.4 GHz                                              | 4x Cortex-A53 @1.4 GHz                                              |
| Apps DMIPS                                         | 4600-5990 (*)                                                                                     | Applications DMIPS 9200-11980 (*)                                                                 | 12000-15500**                                                       | 12000-15500**                                                       | 24000-33500**                                                       | 24000-33500**                                                       |
| Arm RT CPU                                         | 3x Cortex M7, 400 MHz                                                                             | Arm Real-time LS Cores 3x Cortex M7, 400 MHz                                                      | 3x Cortex-M7, 400 MHz                                               | 4x Cortex-M7, 400 MHz                                               | 3x Cortex-M7, 400 MHz                                               | 4x Cortex-M7, 400 MHz                                               |
| RT DMIPS                                           | 3900                                                                                              | DMIPS 3900                                                                                        | 3900                                                                | 5200                                                                | 3900                                                                | 5200                                                                |
| DDR                                                | Real-time DDR LPDDR4 / DDR3L 32-bit (Up to 4 GB)                                                  | Real-time DDR LPDDR4 / DDR3L 32-bit (Up to 4 GB)                                                  | LPDDR4 / DDR3L 32-bit (Up to 4GB)                                   | LPDDR4 / DDR3L 32-bit (Up to 4GB)                                   | LPDDR4 / DDR3L 32-bit (Up to 4GB)                                   | LPDDR4 / DDR3L 32-bit (Up to 4GB)                                   |
| System SRAM                                        | System SRAM 8 MB                                                                                  | System SRAM 8 MB                                                                                  | 15 MB                                                               | 20 MB                                                               | 15 MB                                                               | 20 MB                                                               |
| NVM-IF                                             | NVM-IF Octal DDR NOR, eMMC/SDXC NAND                                                              | NVM-IF Octal DDR NOR, eMMC/SDXC NAND                                                              | Octal DDR NOR, eMMC/SDXC NAND                                       | Octal DDR NOR, eMMC/SDXC NAND                                       | Octal DDR NOR, eMMC/SDXC NAND                                       | Octal DDR NOR, eMMC/SDXC NAND                                       |
| AI/ML                                              | Arm Cortex Neon: 16 GFLOPS                                                                        | AI/ML Arm Cortex Neon: 32 GFLOPS                                                                  | Arm Cortex Neon: 41.6 GFLOPS                                        | Arm Cortex Neon: 41.6 GFLOPS                                        | Arm Cortex Neon: 83.2 GFLOPS                                        | Arm Cortex Neon: 83.2 GFLOPS                                        |
| PCIe Ethernet Acceleration                         | PCIe 2x PCIe3.0 (2 lanes each) Packet Forwarding                                                  | Ethernet Acceleration Engine (PFE)                                                                | 2x PCIe 2.0 (2 lanes ea.) Packet Forwarding Engine PFE2 *           | 2x PCIe 2.0 (2 lanes ea.) Packet Forwarding Engine PFE2 *           | 2x PCIe 2.0 (2 lanes ea.) Packet Forwarding Engine PFE2 *           | 2x PCIe 2.0 (2 lanes ea.) Packet Forwarding Engine PFE2 *           |
| Accelerated Ethernet Ports (PFE)                   | Accelerated Ethernet Ports (PFE) 3 ext ports 2x 1G/100M 1x 2.5G/1G/100M                           | Accelerated Ethernet Ports (PFE) 3 ext ports 2x 1G/100M 1x 2.5G/1G/100M                           | 3 ext ports 3x 2.5G/1G/100M                                         | 3 ext ports 3x 2.5G/1G/100M                                         | 3 ext ports 3x 2.5G/1G/100M                                         | 3 ext ports 3x 2.5G/1G/100M                                         |
| Automotive NetworkAcceleration None Accelerated IF | Automotive NetworkAcceleration LowLatency Communication Engine (LLCE) CAN FD x16 / LIN x4 / FR x1 | Automotive NetworkAcceleration LowLatency Communication Engine (LLCE) CAN FD x16 / LIN x4 / FR x1 | LowLatency Communication Engine (LLCE2) CAN FD x16 / LIN x4 / FR x1 | LowLatency Communication Engine (LLCE2) CAN FD x16 / LIN x4 / FR x1 | LowLatency Communication Engine (LLCE2) CAN FD x16 / LIN x4 / FR x1 | LowLatency Communication Engine (LLCE2) CAN FD x16 / LIN x4 / FR x1 |
| CAN FD / LIN / FR Gb ETH / USB2.0 SPI / I2C        | Non-Accelerated Interfaces CAN FD / LIN / FR Gb ETH / USB2.0 4 / 3 / 1 1 / 1                      | 6 / 5                                                                                             | 4 / 3 / 1 1 / 1                                                     | 4 / 3 / 1 1 / 1                                                     | 4 / 3 / 1 1 / 1                                                     | 4 / 3 / 1 1 / 1                                                     |
| Timer                                              | SPI / I2C Timer 12 FlexTimer, 8 System Timer, 7 Watchdog Timer                                    | SPI / I2C Timer 12 FlexTimer, 8 System Timer, 7 Watchdog Timer                                    | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer              | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer              | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer              | 6 / 5 12 FlexTimer, 13 System Timer, 12 Watchdog Timer              |
| ADC                                                | ADC                                                                                               | ADC                                                                                               |                                                                     |                                                                     |                                                                     |                                                                     |
|                                                    | 2x 6-ch SAR ADC, 12-bit                                                                           | 2x 6-ch SAR ADC, 12-bit                                                                           | 2x 6-ch SAR ADC, 12-bit                                             | 2x 6-ch SAR ADC, 12-bit                                             | 2x 6-ch SAR ADC, 12-bit                                             | 2x 6-ch SAR ADC, 12-bit                                             |
| Temp Range                                         | Temp Range -40 to 105°C (Tj=125°C)                                                                | Temp Range -40 to 105°C (Tj=125°C)                                                                | -40 to 105°C (Tj=125°C)                                             | -40 to 105°C (Tj=125°C)                                             | -40 to 105°C (Tj=125°C)                                             | -40 to 105°C (Tj=125°C)                                             |

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## NXP S32G399A Processor Block Diagram

## Memory

20MBSystemSRAM

StandbySRAM

DDR3L/LPDDR4I/F

NORFlashMemoryVF

NANDFlashMemoryI/Fs

## System

FCCUandMBIST/LBIST

PLLS

2xSafeDMA

Debug andTrace Unit

16xXRDCDomains

## Security

## Hardware Security Engine

AsymmetricHardware Accelerators

SymmetricHardware Accelerators

Secure Memory

Random Number Generators

<!-- image -->

## Fabric

## Safe Interconnect

## Serial Communication

6xSPI

5×1²C

## Networking

4xCANFD

3×LIN/UART

FlexRay

USB2.0OTG

1-GbEw/TSN

2xPCle3.0

## TimersandADCs

12xWatchdogTimer

13xSystem Timer

12xFlexTimer

2xSARADCs（12-ch)

## NetworkAcceleration

## AutomotiveNetworks

Low Latency Communication Engine TransportLayerOffload

16xCANFD FlexRay

Flexible Buffers

4XLIN

4xSPI

SecurityOffload

Global Timestamping

## EthernetNetworks

PacketForwarding Engine

Stateful Inspection Firewall

Classification

HeaderManipulation

IEEE1588v2+AVB

2.5-GbE2.5-GbE2.5-GbE MAC MAC MAC

## NXP S32G Processors Support Many Vehicle Needs Simultaneously

## Central Vehicle Computer / Service-oriented Gateway

## Safe Real-time Processing

## (Arm® Cortex®-M7 cores)

- CAN data filtering
- CAN gateway
- Sensor processing
- Safety processing

## Safe Applications Processing

(Arm Cortex-A53 cores)

- Secure cloud communications
- Data management
- Vehicle services
- OTA updates management
- ECU consolidation
- ECU consolidation
- Machine learning inferencing

Vehicle Networking + Acceleration

- Vehicle management
- Deep packet inspection
- Edge analytics
- Container orchestration

ASIL D Functional Safety Infrastructure

- Ethernet Gateway / Router
- Intrusion Detection and Prevention System
- Fail-Operational - Recovery

## Firewalled Security Processing

(NXP HSE)

- Trusted boot
- Cryptography
- Authentication
- Secure services
- Key management

Firewalled Hardware Security Engine

- Root of Trust (RoT)

## S32G processor in AD/ADAS applications

<!-- image -->

- Safe Processing
- -ASIL D decision making / redundancy
- Sensor Data Fusion
- -Front-end data processing
- HD Map Localization
- -Match camera data to HD map
- Network Connectivity
- -Between ECUs within domain
- -To other domains for sensors/actuation
- Centralized Storage
- -Sharing information between central compute processors

## Addresses Applications Beyond Automotive

- Ideal for applications involving:
- -Real-time + application processing
- -Networking (CAN and Ethernet)
- -High-level of functional safety (SIL / ISO 26262 ASIL D) and security (ISO/SAE 21434)
- -Longevity of supply (15+ years)

Data Logger

<!-- image -->

<!-- image -->

Transportation

<!-- image -->

Energy Storage

<!-- image -->

Robotics

<!-- image -->

Test&amp;Measurement

<!-- image -->

Machinery

<!-- image -->

FactoryAutomation

<!-- image -->

## S32G processors are used in adjacent transportation applications

<!-- image -->

- Developed to ISO 21434/ISO 26262
- Vehicle networking Reference design :
- -S32G-VNP-RDB2, GoldBox
- -S32G-VNP-RDB3, GoldBox 3
- Hardware customization and engineering services :
- -MicroSys ' miriac S32G SoMs
- Tessolve's TERA products
- TTTech's N4 network controller
- Sonatus' HL Klemove central communication unit
- Inventec's central gateway
- -Automotive premium engineering service

## NXP partner S32G platforms

I N V E N T E C   C E N T R A L   G A T E W A Y   ( C G W )

<!-- image -->

MICROSYS MIRIAC S B C s   A N D   S O M s

<!-- image -->

<!-- image -->

S32G2SOM

<!-- image -->

HL KLEMOVE + SONATUS CENTRAL COMMUNICATION UNIT

<!-- image -->

TERAGW

<!-- image -->

TERALiTE

TTTECH AUTO N4 NETWORK CONTROLLER

<!-- image -->

<!-- image -->

TERAACE

<!-- image -->

TERAOBD-I

## S32G3 Reference Design (RDB3) and GoldBox 3

- Automotive reference design
- 12x Ethernet, 18x CAN FD, 5x LIN, 1x FlexRay® interfaces
- A-sample-like design for evaluation, development and demonstrations -schematics, BoM, layout provided
- PCI Express x1 slot for system expansion and USB 2.0 OTG connector
- JTAG debug and Aurora trace support
- 2x M.2 slot support for SSD storage and AI/ML acceleration modules
- Rugged enclosure with integrated thermal management

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## S32G Enablement Support: by NXP Software Tools and Strong Ecosystem of Partners

<!-- image -->

<!-- image -->

NXP S32G Ecosystem Partners

## Solution Focused Enablement for S32G Customers

<!-- image -->

## S32G GoldVIP Software (Vehicle Integration Platform)

<!-- image -->

To learn more:  NXP GoldVIP: Integration Platform for Intelligent Connected Vehicles -- NXP and Mouser Electronics (youtube.com)

## NXP GoldVIP -Software Development Environment

<!-- image -->

## NXP GoldVIP -Deliverables AND Demonstration Setup

<!-- image -->

## A Snapshot of GoldVIP Folders

<!-- image -->

## NXP GoldVIP Resources

<!-- image -->

- For more information: nxp.com/GoldVIP
- -GoldVIP training academy
- -GoldVIP software page
- -#GoldVIP @ S32G support community

## S32G ecosystem partners

Cloud Services

<!-- image -->

## Top 5 S32G unique value propositions

- 1 Network acceleration (LLCE/PFE) offloads processor cores to focus on valued services
- 2 Fault-tolerant design supports fail-operational recovery complying to ISO 26262:2018
- 3 High level of ASIL D processing, including unique lockstep Cortex-A53 processor clusters
- 4 Hardware Security Engine (HSE) with Public Key (PKI), PQC and Physical Protection Support
- 5 Scalable, pin-compatible family of processors that span a wide range of applications

<!-- image -->

<!-- image -->

<!-- image -->

Business Creation and Management(BCaM)Process Functionalsafetymanagementforautomotivesafetyrelated projectsuptoASILDaccordingtoISO26262:2018

<!-- image -->

## Start developing with S32G today!

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

| TOOL                                                                             | PRICE                         | STATUS                                    |
|----------------------------------------------------------------------------------|-------------------------------|-------------------------------------------|
| S32G3RDB3 S32G Reference Design Board 3                                          | S32G-VNP-RDB3 CHECK ONLINE    | PRODUCTION Available through distributors |
| S32G3 GoldBox 3 S32G RDB3 + Enclosure                                            | S32G-VNP-GLDBOX3 CHECK ONLINE | PRODUCTION Available through distributors |
| GoldVIP S32G Vehicle Integration Platform                                        | FREE OF CHARGE                | AVAILABLE nxp.com/GoldVIP                 |
| &#124; NXP &#124; Public 25 S32 Design Studio Integrated Development Environment | FREE OF CHARGE                | AVAILABLE nxp.com/S32DS-S32PLATFORM       |

<!-- image -->

## Get in touch

Kushal Shah kushal.shah@nxp.com

nxp.com

<!-- image -->

<!-- image -->