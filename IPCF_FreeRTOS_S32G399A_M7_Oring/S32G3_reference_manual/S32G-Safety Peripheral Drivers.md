## NXP Semiconductors Product Brief

Document Number: 1

Rev. 1  ,    01/2023

## Safety Peripheral Drivers

## Contents

|   1. | Software Product Overview............................................... 1         |
|------|------------------------------------------------------------------------------------|
|    2 | Software Content ............................................................... 3 |
|    3 | Supported Targets.............................................................. 5  |
|    4 | Quality, Standards Compliance and Testing Approach...... 6                         |
|    5 | Document Information....................................................... 7      |

## 1. Software Product Overview

The Safety Peripheral Drivers (SPD) is a software product containing software components to control the safety related on-chip peripheral modules present on the device and thus it complements the S32 Real Time Drivers (RTD) product to provide software support for all on-chip peripheral modules.

The users can use it to develop their own safety solutions compliant with ISO 26262 functional safety. It allows integration up to ASIL D automotive safety integrity level. It is developed as Safety Element out of Context (SEooC). The Safety Peripheral Drivers software is designed to be integrated with AUTOSAR ®  and non - AUTOSAR applications. It is available for all NXP S32 Automotive Platform devices.

<!-- image -->

The Safety Peripheral Drivers package provides two software modules which are also included in the respective S32 Safety Software Framework (SAF, nxp.com/saf), see Figure 1.

Figure 1. NXP's S32 SAF and SPD content

<!-- image -->

The software modules provided in SPD are:

- BIST Manager - Built in Self-Test Manager covering both LBIST (Logic BIST) and MBIST (Memory BIST)
- eMCEM - extended Microcontroller Error Manager

## 2. Software Content

The Safety Peripheral Drivers software is essential to achieve safety solution on applications on S32 Automotive Platform. The main features of the Safety Peripheral Drivers are as follows:

- BIST management and deployment to provide high availability
- Handling and reaction to detected faults
- Compliance with ISO 26262

## BIST Manager (Built in Self-Test Manager)

- A driver for MBIST and LBIST HW modules
- Analyzes the results provided by LBIST and MBIST HW and initiates their execution

Figure 2. BIST Manager

<!-- image -->

## eMCEM (extended Microcontroller Error Manager)

- Fault management of the microcontroller (FCCU HW IP)
- Configuration of fault reactions (reset, alarm IRQ, NMI, no reaction)
- Sophisticated error handling mechanism
- Allows to register an individual alarm handler for each FCCU fault
- Fault status reporting and fault clearing
- Error injection
- Memory error reporting

Figure 3. eMCEM (extended Microcontroller Error Manager)

<!-- image -->

## 3. Supported Targets

The Safety Peripheral Drivers described in this product brief are intended to be used with NXP Semiconductors S32G devices.

## 4. Quality, Standards Compliance and Testing Approach

The Safety Peripheral Drivers software product is developed according to NXP Software Development Processes that is ISO 26262, Automotive-SPICE, IATF 16949 and ISO 9001 compliant.

## 5. Document Information

Table 1. Revision History

|   Revision number | Date    | Substantive changes      |
|-------------------|---------|--------------------------|
|                 1 | 05/2022 | Initial version          |
|                 2 | 01/2023 | Updated figure captions. |

How to Reach Us: Home Page: nxp.com Web Support: nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C 5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  ARM, AMBA, ARM Powered, Artisan, Cortex, Jazelle, Keil, SecurCore, Thumb, TrustZone, and μVision are registered trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. ARM7, ARM9, ARM11, big.LITTLE, CoreLink, CoreSight, DesignStart, Mali, mbed, NEON, POP, Sensinode, Socrates, ULINK and Versatile are trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.

© 2023 NXP B.V.

Document Number: 1 Rev. 1 01/2023