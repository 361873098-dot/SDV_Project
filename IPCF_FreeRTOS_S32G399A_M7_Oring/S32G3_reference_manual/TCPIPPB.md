## NXP TCP/IP Stack Product Brief

## Contents

|   1. | Software Product Overview............................................... 1         |
|------|------------------------------------------------------------------------------------|
|    2 | Software Content ............................................................... 2 |
|    3 | Supported Targets.............................................................. 3  |
|    4 | Quality, Standards Compliance and Testing Approach...... 4                         |
|    5 | Document Information....................................................... 5      |

Document Number: 1.0

Rev 3.0,

## 1. Software Product Overview

The TCP/IP stack is a light-weight implementation of the TCP/IP protocol suite. It is a port of lwIP stack for NXP automotive processors.

lwIP was originally written by Adam Dunkels at the Computer and Networks Architectures (CNA) lab of the Swedish Institute of Computer Science but now is being actively developed by a team of developers distributed world-wide headed by Kieran Mansley. The development homepage has the latest news and releases: http:// savannah.nongnu.org/projects/lwip

The focus of the lwIP TCP/IP implementation is to reduce the RAM usage while still having a fullscale TCP.

lwIP is freely available (under a BSD-style license) in C source code format and can be downloaded from the development homepage.

.

<!-- image -->

## 2. Software Content

lwIP has three application programming interfaces (APIs) designed for different purposes:

- Raw API is a native lwIP API. This API provides the best performance and minimal code size, but adds some complexity to application design because the handling of asynchronous events is done using callbacks.
- Netconn API is a high-level sequential API built on top of Raw API. The Netconn API enables multithreaded operations and therefore it requires an operating system (RTOS). It offers increased usability at the expense of lower performance and higher memory footprint.
- BSD Socket API Berkeley-like Socket API (developed on top of the Netconn API). It offers portability while sharing the same drawbacks as Netconn API.

## 3. Supported Targets

The following table shows the supported platforms for TCP/IP stack.

Table 1. Supported platforms, toolchains, etc.

| Product                   | Devices      | Toolchains IDEs   |                   | Supported NXP Software   | OS       |
|---------------------------|--------------|-------------------|-------------------|--------------------------|----------|
| TCP/IP stack for MPC5744P | MPC5744P GNU | C                 | S32 Design Studio | S32 SDKfor MPC5744P      | FreeRTOS |
| TCP/IP stack for MPC5748G | MPC5748G GNU | C                 | S32 Design Studio | S32 SDKfor MPC5748G      | FreeRTOS |
| TCP/IP stack for S32K148  | S32K148      | GNU C             | S32 Design Studio | S32 SDK for S32K148      | FreeRTOS |
| TCP/IP stack for S32R274  | S32R274      | GNU C             | S32 Design Studio | S32 SDK for S32R274      | FreeRTOS |
| TCP/IP stack for MPC5746R | MPC5746R     | GNU C             | S32 Design Studio | S32 SDKfor MPC5746R      | FreeRTOS |
| TCP/IP stack for MPC5777C | MPC5777C     | GNU C             | S32 Design Studio | S32 SDKfor MPC5777C      | FreeRTOS |
| TCP/IP stack for S32V234  | S32V234      | GNU C             | S32 Design Studio | S32 SDK for S32V234      | FreeRTOS |
| TCP/IP stack for S32R294  | S32R294      | GNU C             | S32 Design Studio | SDKdrivers for S32R294   | FreeRTOS |
| TCP/IP stack for S32G274  | S32G274      | GNU C             | S32 Design Studio | RTDdrivers for S32G274   | FreeRTOS |
| TCP/IP stack for SJA1110  | SJA1110      | GNU C             | S32 Design Studio | SDKdrivers for SJA1110   | FreeRTOS |
| TCP/IP stack for S32K344  | S32K344      | GNUC, GHS, DIAB   | S32 Design Studio | RTDdrivers for S32K344   | FreeRTOS |
| TCP/IP stack for SAF85XX  | SAF85XX      | GNUC, GHS, DIAB   | S32 Design Studio | RTDdrivers for SAF85XX   | NXPOS    |
| TCP/IP stack for S32R41   | S32R41       | GNUC, GHS, DIAB   | S32 Design Studio | RTDdrivers for S32R41    | NXPOS    |
| TCP/IP stack for SAF86XX  | SAF86XX      | GNUC, GHS, DIAB   | S32 Design Studio | RTDdrivers for SAF86XX   | NXPOS    |
| TCP/IP stack for S32ZE    | S32ZE        | GNUC, GHS, DIAB   | S32 Design Studio | RTD drivers for S32ZE    | FreeRTOS |
| TCP/IP stack for S32G     | S32G3 S32G2  | GNUC, GHS, DIAB   | S32 Design Studio | RTD for S32G             | FreeRTOS |

## 4. Quality, Standards Compliance and Testing Approach

TCP/IP Stack is developed according to NXP Software Development Processes that are AutomotiveSPICE, IATF 16949 and ISO9001 compliant.

## 5. Document Information

## Table 2. Revision History

| Revision   | Date       | Description                         |
|------------|------------|-------------------------------------|
| Rev 1.0    | 07/07/2021 | Initial version                     |
| Rev 2.0    | 26/09/2022 | Add new product(SAF85/SAF86/ S32ZE) |
| Rev 3.0    | 07/02/2023 | Update S32G product                 |

How to Reach Us: Home Page: nxp.com Web Support: nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C 5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  ARM, AMBA, ARM Powered, Artisan, Cortex, Jazelle, Keil, SecurCore, Thumb, TrustZone, and μVision are registered trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. ARM7, ARM9, ARM11, big.LITTLE, CoreLink, CoreSight, DesignStart, Mali, mbed, NEON, POP, Sensinode, Socrates, ULINK and Versatile are trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.

NXP B.V. 2023. All rights reserved.

Document Number: 1.0 Rev 3.0