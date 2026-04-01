## NXP USB Stack Product Brief

## Contents

|   1. | Software Product Overview............................................... 1         |
|------|------------------------------------------------------------------------------------|
|    2 | Software Content ............................................................... 2 |
|    3 | Supported Targets.............................................................. 3  |
|    4 | Quality, Standards Compliance and Testing Approach...... 3                         |
|    5 | Document Information....................................................... 3      |

Document Number: 1.0

Rev 2.0,

## 1. Software Product Overview

The USB stack is an implementation of the USB standard. It is a port of the Kinetis USB  stack on NXP's automotive processors.

The current implementation supports:

- Mass storage devices on both the host controller and the OTG interface. The file system is an open source project, supported by Elm Chan and for the latest news and  releases please check: http://elmchan.org/fsw/ff/00index\_e.html.
- USB CDC-ECM communication model running on both the host controller and OTG interface (stack acting as a host)

- USB CDC peripheral/device mode (communication through Virtual Serial COM Port)  (stack acting as a peripheral/device)

<!-- image -->

## 2. Software Content

The USB stack API consists of three parts:

- USB API: implementing USB specific instructions
- FATFS API: implementing file system functionality. This layer is independent of the  USB stack and it uses disk I/O operations to communicate with the mass storage device.
- LWIPAPI: implementing ENET read/write functionality. This layer is dependent on the  USB stack, as it reads and writes packets on the USB port.

## 3. Supported Targets

The following table shows the supported platforms for USB stack.

Table 1. Supported platforms, toolchains, etc.

| Product                | Devices     | Toolchains       | IDEs              | Supported NXPSoftwares         | OS        |
|------------------------|-------------|------------------|-------------------|--------------------------------|-----------|
| USB stack for MPC574XG | MPC574XGGNU | C, GHS, DIAB     | S32 Design Studio | SDK drivers for MPC57XX family | Baremetal |
| USB stack for S32G2    | S32G2       | GNU C, GHS, DIAB | S32 Design Studio | RTD for S32G                   | Baremetal |
| USB stack for S32G3    | S32G3       | GNU C, GHS, DIAB | S32 Design Studio | RTD for S32G                   | Baremetal |

## 4. Quality, Standards Compliance and Testing Approach

USB Stack is developed according to NXP Software Development Processes that are  AutomotiveSPICE, IATF 16949 and ISO9001 compliant.

## 5. Document Information

Table 2. Revision History

| Revision   | Date       | Description     |
|------------|------------|-----------------|
| Rev 1.0    | 07/07/2021 | Initial version |
| Rev 2.0    | 02/07/2023 | Update          |

How to Reach Us: Home Page: nxp.com Web Support: nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C 5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  ARM, AMBA, ARM Powered, Artisan, Cortex, Jazelle, Keil, SecurCore, Thumb, TrustZone, and μVision are registered trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. ARM7, ARM9, ARM11, big.LITTLE, CoreLink, CoreSight, DesignStart, Mali, mbed, NEON, POP, Sensinode, Socrates, ULINK and Versatile are trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.

NXP B.V. 2023. All rights reserved.

Document Number: 1.0 Rev 2.0