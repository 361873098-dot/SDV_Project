## NXP Semiconductors

Product Brief

Document Number: 1

Rev. 2  ,    02/2023

## S32G VEHICLE INTEGRATION PLATFORM (GoldVIP) - Product Brief

## Contents

| 1.   | Software Product Overview............................................... 1                 | Software Product Overview............................................... 1                 |
|------|--------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| 2.   | Software Content ............................................................... 3         | Software Content ............................................................... 3         |
|      | 2.1.                                                                                       | Linux BSP............................................................... 3                 |
|      | 2.2.                                                                                       | Low Latency Communication Engine (LLCE) driver                                             |
|      | and standard firmware........................................................... 3         | and standard firmware........................................................... 3         |
|      | 2.3.                                                                                       | Packet Forwarding Engine driver and standard                                               |
|      | firmware................................................................................ 3 | firmware................................................................................ 3 |
|      | 2.4.                                                                                       | Real-Time Drivers .................................................. 4                     |
|      | 2.5.                                                                                       | Inter-Platform Communication Framework............ 4                                       |
|      | 2.6.                                                                                       | Hardware Security Engine standard firmware ........ 4                                      |
|      | 2.7.                                                                                       | Platform Software Integration Bootloader .............. 4                                  |
|      | 2.8.                                                                                       | S32 Safety Software Framework ............................ 4                               |
|      | 2.9.                                                                                       | eIQ Auto Deep Learning toolkit ............................. 4                             |
|      | 2.10. SJA1110 Ethernet Switch standard firmware and                                        | 2.10. SJA1110 Ethernet Switch standard firmware and                                        |
|      | telemetry application............................................................. 4       | telemetry application............................................................. 4       |
|      | 2.11.                                                                                      | Yocto Project .......................................................... 5                 |
|      | 2.12.                                                                                      | AWS IoT Greengrass.............................................. 5                         |
|      | 2.13.                                                                                      | AWS IoT FleetWise................................................ 5                        |
|      | 2.14.                                                                                      | Argus IDPS............................................................. 5                  |
|      | 2.15.                                                                                      | EB tresos AutoCore................................................ 5                       |
|      | 2.16.                                                                                      | Airbiquity OTAmatic Software .............................. 5                              |
|      | 2.17.                                                                                      | K3s Kubernetes Distribution................................... 5                           |
|      | 2.18.                                                                                      | Docker Engine ........................................................ 5                   |
| 3.   | Supported Targets.............................................................. 6          | Supported Targets.............................................................. 6          |
| 4.   | Quality, Standards Compliance and Testing Approach...... 7                                 | Quality, Standards Compliance and Testing Approach...... 7                                 |
| 5.   | Document Information....................................................... 8              | Document Information....................................................... 8              |

## 1. Software Product Overview

GoldVIP provides a reference software integration platform for vehicle network processing applications like vehicle computers and service-oriented gateways. It streamlines S32G hardware evaluation and accelerates software development with ease-of-use, hardware abstraction, software integration and visualization.

GoldVIP provides out-of-the-box integration of opensource software components and third-party software on top of the S32G software ecosystem, offering both AUTOSAR ™  and Linux ®  rapid development and sample applications. The key value propositions of the S32G hardware accelerators are showcased through example use cases, fast deployment and visualization.

The targeted use cases include, but are not limited to:

- CAN and Ethernet data routing with and without acceleration and Intrusion Detection and Prevention functionalities;
- Connected vehicle including over-the-air (OTA) updates and Vehicle-to-Cloud support using AWS IoT Greengrass;
- In-vehicle services deployment with support for virtualization and containers;

S32G VEHICLE INTEGRATION PLATFORM (GoldVIP) - Product Brief, Product Brief , Rev. 2, 02/2022

## Software Product Overview

- Vehicle network processing applications, network security and security services;

Figure 1 . S32G VEHICLE INTEGRATION PLATFORM (GoldVIP) Block Diagram

## 2. Software Content

This section contains a description of the modules integrated in the GoldVIP deliverable:

- Linux BSP
- Low Latency Communication Engine (LLCE) driver and standard firmware
- Packet Forwarding Engine (PFE) driver and standard firmware
- Real-Time Drivers (RTD)
- Inter-Platform Communication Framework (IPCF)
- Hardware Security Engine standard firmware
- Platform Software Integration Bootloader
- S32 Safety Software Framework (SAF)
- eIQ Auto Deep Learning toolkit
- SJA1110 Ethernet Switch standard firmware and telemetry application
- Yocto Project ®  support
- AWS IoT Greengrass
- AWS IoT FleetWise
- Argus IDPS
- EB tresos AutoCore
- Airbiquity OTAmatic ®  Software
- K3s Kubernetes Distribution
- Docker ® Engine

## 2.1. Linux BSP

NXP Automotive Linux BSP follows the general layout of a BSP, containing a bootloader (U-Boot), a hypervisor (Xen ®  Project), Arm ®  Trusted Firmware (ATF), the Linux kernel, a root file system, which can contain various libraries and middleware, and sample applications. The objective is to enable more hardware platforms, to build on top of the NXP Automotive Processing (AP) Linux BSP and add supplemental components such as drivers or applications.

## 2.2. Low Latency Communication Engine (LLCE) driver and standard firmware

The Low Latency Communication Engine (LLCE) controls the traditional automotive communication interfaces such as CAN, LIN, and FlexRay™. The LLCE offloads the Host CPU from all interface level tasks, while maintaining performance and compatibility with the AUTOSAR standard. LLCE enablement consist of binary images for the code running on each of the LLCE cores. The firmware services are integrated into the AUTOSAR Communication stack via AUTOSAR MCAL drivers that are provided by NXP.

## 2.3. Packet Forwarding Engine driver and standard firmware

The Packet Forwarding Engine (PFE) consists of three software components: PFE Firmware, Ethernet drivers, Configuration API - FCI (Fast Control Interface). The PFE is capable of offloading the

S32G VEHICLE INTEGRATION PLATFORM (GoldVIP) - Product Brief, Product Brief , Rev. 2 , 02 /2023

computing intensive operations of Ethernet packet routing from the application cores, while providing a high degree of configuration through the FCI.

## 2.4. Real-Time Drivers

The Real-Time Drivers (RTD) is a set of AUTOSAR compliant device drivers responsible for hardware abstraction and enablement of the NXP devices. The Complex Device Drivers provided on top of the required AUTOSAR drivers create a rich ecosystem for developers and applications.

## 2.5. Inter-Platform Communication Framework

The Inter-Platform Communication Framework (IPCF) is a subsystem which enables applications, running on multiple homogenous or heterogenous processing cores, located on the same chip or different chips, running on different operating systems (e.g., AUTOSAR, Linux, FreeRTOS ™ ), to communicate over various transport interfaces.

## 2.6. Hardware Security Engine standard firmware

The Hardware Security Engine (HSE) is an NXP dedicated security core that runs secure firmware. The HSE enables offloading of the most common security algorithms from the CPU to the dedicated hardware, key storage, secure boot, while serving as a secure enclave. The HSE Security (standard) Firmware is delivered in executable form, encrypted and signed by NXP.

## 2.7. Platform Software Integration Bootloader

The Platform Software Integration Bootloader prepares the system to be able to execute code by loading application images from Non-Volatile Memory to RAM. The bootloader prepares the system partitioning for the applications, ensures data integrity using the HSE and performs a safety check on the system using the SAF.

## 2.8. S32 Safety Software Framework

The S32 Safety Software Framework (SAF) is a software product containing software components for establishing the safety foundation for customer's safety applications compliant with ISO 26262 functional safety. It allows integration up to ASIL D automotive safety integrity level.

## 2.9. eIQ Auto Deep Learning toolkit

The eIQ Auto Deep Learning toolkit is an automotive-grade deep learning (DL) toolkit enabling developers to transition their DL algorithms seamlessly from the development environment to full implementation application. The eIQ Auto toolkit is comprised of software, accompanying tools, and libraries that helps to satisfy stringent automotive quality and reliability standards.

## 2.10. SJA1110 Ethernet Switch standard firmware and telemetry application

The NXP SJA1110 is a family of four, pin-compatible and software-compatible automotive Ethernet Switch SoC offering a scalable solution for all automotive applications. All SJA1110 variants come with hardware-assisted security and safety capabilities, multi-gigabit SGMII interfaces and the latest AVB and TSN standards. In one of GoldVIP telemetry use cases, a telemetry application making use of AWS IoT Greengrass which was added on top of the standard SJA1110 firmware to allow statistics from the Ethernet Switch to be sent to the cloud.

## 2.11. Yocto Project

The Yocto component is responsible for providing a way of building all GoldVIP components and tools necessary to create the binary images that run on the target NXP hardware. It gives developers and clients the flexibility to supplement the provided images with other tools, binaries and utilities that should be part of the final root file system on the target hardware.

## 2.12. AWS IoT Greengrass

AWS IoT Greengrass is an Internet of Things (IoT) open source edge runtime and cloud service that helps you build, deploy, and manage device software.

## 2.13. AWS IoT FleetWise

AWS IoT FleetWise makes it easier to collect, transform, and transfer vehicle data to the cloud in near real time and use that data to improve vehicle quality, safety, and autonomy.

## 2.14. Argus IDPS

Argus Intrusion Detection Prevention System monitors and analyzes in-vehicle network communication in real time to detect cyber security attacks and suspicious network activity. Argus network protection uses various techniques, such as deep packet inspection and timing and context analysis, to provide accurate, detailed alerts of suspicious events in CAN and Ethernet networks.

## 2.15. EB tresos AutoCore

EB tresos AutoCore is an industry-leading implementation of AUTOSAR-compliant basic software for automotive electronic control units (ECUs). This versatile solution is based on AUTOSAR 4.x. It provides a modular and extensible framework and is a perfect software base for developing innovative ECU software applications.

## 2.16. Airbiquity OTAmatic Software

Airbiquity OTAmatic software is an automated and secure Over-The-Air (OTA) service delivery tailored for automotive applications. It consists of three main software components: OTAmatic Server, Client and Agent. These three components operate in a secure and safe manner ensuring A/B swap capabilities and data integrity.

## 2.17. K3s Kubernetes Distribution

K3s is a highly available, certified Kubernetes distribution designed for production workloads in unattended, resource-constrained, remote locations or inside IoT appliances.

## 2.18. Docker Engine

A Docker image recipe is provided, containing demo scripts for ease of use and a Graphical User Interface (GUI) ready to be deployed on an Ubuntu ®  target. This ensures an Out-Of-The-BoxExperience for the user and provides a lot of insight into the S32G and its capabilities for developers.

S32G VEHICLE INTEGRATION PLATFORM (GoldVIP) - Product Brief, Product Brief , Rev. 2 , 02 /2023

## 3. Supported Targets

The software described in this document is intended to be used with the NXP Semiconductors S32G devices.

Hardware platforms supported:

- S32G Reference Design Board 2 (RDB2) - (S32G-VNP-RDB2)
- S32G Reference Design Board 3 (RDB3) - (S32G-VNP-RDB3)
- S32G2 GoldBox - (S32G-VNP-GLDBOX)
- S32G3 GoldBox 3 - (S32G-VNP-GLDBOX3)

## NXP S32G Hardware Platforms

## 4. Quality, Standards Compliance and Testing Approach

The GoldVIP product is developed according to NXP Software Development Processes that are Automotive-SPICE (tailored for open source), IATF16949 and ISO 9001 compliant.

S32G VEHICLE INTEGRATION PLATFORM (GoldVIP) - Product Brief, Product Brief , Rev. 2 , 02 /2023

## 5. Document Information

Table 1. Sample revision history

|   Revision number | Date    | Substantive changes                                    |
|-------------------|---------|--------------------------------------------------------|
|                 1 | 02/2022 | Initial release                                        |
|                 2 | 02/2023 | Update Software Content and Supported Targets chapters |

How to Reach Us: Home Page: nxp.com Web Support: nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C 5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  ARM, AMBA, ARM Powered, Artisan, Cortex, Jazelle, Keil, SecurCore, Thumb, TrustZone, and μVision are registered trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. ARM7, ARM9, ARM11, big.LITTLE, CoreLink, CoreSight, DesignStart, Mali, mbed, NEON, POP, Sensinode, Socrates, ULINK and Versatile are trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.

© 2023 NXP B.V.

Document Number: 1 Rev. 2 02/2023