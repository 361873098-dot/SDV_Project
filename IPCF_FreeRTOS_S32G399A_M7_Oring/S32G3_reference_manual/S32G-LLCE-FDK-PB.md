Document Number: 1.

Rev. 1.7  ,    10/2023

## S32G2/G3 LLCE Firmware Development Kit Product Brief

## Contents

| 1.   | Software Product Overview ...............................................1        |
|------|-----------------------------------------------------------------------------------|
| 2.   | Software Content................................................................3 |
| 2.1. | LLCE FDK.............................................................. 4          |
| 2.2. | High-Level Architecture of the LLCE Firmware....5                                 |
| 3.   | Supported Targets ..............................................................8 |
| 4.   | Quality, Standards Compliance and Testing Approach......9                         |
| 5.   | Document Information.....................................................10       |

## 1. Software Product Overview

## NXP Low Latency Communication Engine

(LLCE) controls the traditional automotive communication interfaces such as CAN, LIN, and FlexRay TM . The LLCE offloads the Host CPU from all interface level tasks along with validating, authenticating of frames for security and also handles the encryption/decryption process of frames with the help of on-chip Hardware Security Module (HSE).

It provides a platform to develop software to customize the processing of communication interfaces and handshaking with the host CPU.

## LLCE is aimed to offer:

- Low latency processing of communication interface
- Offloading of host CPU for all interface related tasks
- Direct data transfer to/from HSE for security related tasks

S32G2/G3 LLCE Firmware Development Kit Product Brief, Product Brief , Rev. 1.7 , 10/2023

The communication interfaces handled by LLCE are as below:

- 16 CAN interfaces, capable of CAN2.0 and CAN FD (Flexible Data rate) (5 Mbps)
- 4 LIN interfaces, capable of 20 Kbps each
- 1 FlexRay interface (20 Mbps)

NXP  Low  Latency  Communication  Engine  runs  a  multicore  application  that  controls  the  hardware communication interfaces and is called 'firmware' Its architecture is described in Figure 1.

S32G2/G3 LLCE Firmware Development Kit Product Brief, Product Brief , Rev. 1.7 , 10/ 2023

<!-- image -->

Figure 1. LLCE Architecture Diagram

## 2. Software Content

NXP solution is a fully programmable engine with firmware that supports:

- Offload of host CPU for all communication interface related tasks
- o Reduced interrupt load on the host core
- o Advanced software filtering
- Flexible control and data interface exposed to the Host cores
- Hardware acceleration for filtering and prioritization of messages

The firmware services are integrated into the AUTOSAR® Communication stack via AUTOSAR® MCAL drivers that are provided by NXP:

- CAN\_LLCE
- LIN\_LLCE
- FR\_LLCE

AUTOSAR® drivers for LLCE run in parallel with the CAN/LIN/FR drivers for the standard communication modules (from the NXP MCAL package).

AUTOSAR® CAN driver for LLCE was developed according to AUTOSAR® multicore concept supporting up to 2 cores.

To configure the Advanced features supported in the firmware another AUTOSAR® plugin is provided:

- LLCE\_AF

Configuration of all drivers can be done with Elektrobit Tresos tool or S32 Design Studio Configuration Tool.

NXP LLCE firmware can support advanced extensions created by NXP or by the customers. Example of such advanced extensions include:

- CAN to CAN frame router
- CAN Frame ID remapping during internal routing
- Fast autonomous startup mode
- Routing received CAN frames to PCIe interface
- CAN tunnelling over Ethernet using IEEE1722a and UDP encapsulation protocol

S32G2/G3 LLCE Firmware Development Kit Product Brief, Product Brief , Rev. 1.7 , 10/ 2023

- o CAN to Ethernet
- o Ethernet to CAN
- CAN Frame logging to a host core
- CAN frame authentication with HSE services

## 2.1. LLCE FDK

It consists of source code repository for the entire LLCE firmware. Can be used to develop extensions. By applying configuration sets, various firmware images can be generated (enablement and premium). Includes all features of LLCE Standard + the following extra features:

- Logging frames to a different host
- Direct authentication of CAN frames by using HSE crypto accelerator

The filtering support is different between S32G2 and S32G3:

- S32G2: Support for up to 1024 filters and 2000 message buffers
- S32G3: Support for up to 4096 filters,  1732 long message buffers and 2364 short message buffers

## 2.1.1. Release package content

- AUTOSAR® drivers for CAN, LIN, FlexRay and LLCE\_AF CDD
- Firmware binaries for the 4 cores (DTE, PPE\_RX, PPE\_TX, FRPE)
- LLCE firmware user guide
- LLCE host interface header files + data structures
- LLCE firmware source code + makefiles to rebuild the firmware images
- Documentation of internal FDK C language modules.
- Sample applications (CAN, LIN, Flexray)
- Quick Start Guide
- Release notes
- Quality Package - delivered to customers for RTM releases

## 2.2. High-Level Architecture of the LLCE Firmware

## 2.2.1. Host Interface

Interface with host cores is done through the LLCE host interface. It consists of messages exchanged via shared memory, hardware FIFOs and Core2Core hardware communication module.

- Host side applications interacts with LLCE firmware by using 3 different interfaces for each type of protocols: CAN, LIN and FlexRay. In case of CAN protocol, the LLCE firmware can be used by maximum 2 different host applications simultaneously.
- The host interface for each bus is composed from independent hardware (HW) elements.
- All the source files servicing each bus behavior are compiled together and the execution is distributed between multiple internal cores

Figure 2. LLCE interface with host

<!-- image -->

## 2.2.2. CAN protocol

High level architecture of the LLCE CAN communication firmware is presented in Figure 3 .

- LLCE CAN firmware is distributed and runs on all 4 internal cores
- Interactions between host applications and CAN firmware is done by using multiple custom interfaces composed from different shared memory areas and HW FIFOs
- HW FIFOs are used also as inter-core communication mechanism inside LLCE
- Data Transfer Engine (DTE) core run fully in polling mode in order to get all frames from all BCANs

S32G2/G3 LLCE Firmware Development Kit Product Brief, Product Brief , Rev. 1.7 , 10/ 2023

Figure 3. LLCE Firmware architecture for CAN

<!-- image -->

## 2.2.3. LIN Protocol

High level architecture of the LLCE LIN communication firmware is presented in Figure 4 .

- LLCE LIN firmware is running fully on the Tx PPE(Core2) core
- LIN firmware behave like a master or slave on the LIN bus
- LIN firmware reacts only by responding to the host commands
- Host driver writes into shared memory the command parameters and notify LIN firmware by raising a flag inside Core2Core module
- Support LIN protocol processing on the host side by forwarding  interrupts

Figure 4. LLCE Firmware architecture for LIN

<!-- image -->

## 2.2.4. FlexRay Protocol

High level architecture of the LLCE FlexRay communication firmware is presented in Figure 5 .

Due to the fact that the Flexray interrupts are not routed directly to the host cores, it was needed that the LLCE  firmware  to  implement  a  mechanism  in  order  to  forward  the  Flexray  interrupts  to  host applications.

Figure 5. LLCE Firmware architecture for FlexRay

<!-- image -->

## 2.2.5. SPI Protocol

Due to the fact that the SPI interrupts are not routed directly to the host cores, it needed that the LLCE firmware to implement a mechanism in order to forward the SPI interrupts to host applications. This is similar with the Flexray mechanism.

## 3. Supported Targets

The software described in this document is intended to be used with NXP Semiconductors S32G2/G3 devices.

## 4. Quality, Standards Compliance and Testing Approach

LLCE Firmware product is developed according to NXP Software Development Processes that are Automotive-SPICE, ISO21434, IATF16949 and ISO 9001 compliant.

LLCE Firmware Releases starting with Beta are accompanied by SW quality packages containing at minimum the following deliverables:

- -Requirements Specification and Traceability Matrix (features-design-code-test);
- -Test Specification;
- -Test Report;
- -Static Analysis Report (MISRA, CERTC, CWE) Report;
- -Code Coverage Report.

SW Testing approach is documented in LLCE Firmware Test Strategy document that contains the following information and can be shared with customers in request.

- -Testing scope and objectives;
- -Test levels: unit tests, unit integration tests;
- -Test types: functional, non-functional, regression tests, robustness, performance tests, conformance testing;
- -Test techniques: white-box, black-box tests;
- -Test cases organization and prioritization;
- -Test deliverables (test report, test specification, code coverage report, traceability matrix, static analysis report).

S32G2/G3 LLCE Firmware Development Kit Product Brief, Product Brief , Rev. 1.7 , 10/ 2023

## 5. Document Information

Table 1. Sample revision history

|   Revision number | Date    | Substantive changes   |
|-------------------|---------|-----------------------|
|               1   | 10/2021 | Initial release       |
|               1.6 | 02/2023 | Updated for S32G3     |
|               1.7 | 10/2023 | Added new features    |

How to Reach Us: Home Page: nxp.com Web Support: nxp.com/support

Information in this document is provided solely to enable system and software implementers to use NXP products. There are no express or implied copyright licenses granted hereunder to design or fabricate any integrated circuits based on the information in this document. NXP reserves the right to make changes without further notice to any products herein.

NXP makes no warranty, representation, or guarantee regarding the suitability of its products for any particular purpose, nor does NXP assume any liability arising out of the application or use of any product or circuit, and specifically disclaims any and all liability, including without limitation consequential or incidental damages. 'Typical' parameters that may be provided in NXP data sheets and/or specifications can and do vary in different applications, and actual performance may vary over time. All operating parameters, including 'typicals,' must be validated for each customer application by customer's technical experts. NXP does not convey any license under its patent rights nor the rights of others. NXP sells products pursuant to standard terms and conditions of sale, which can be found at the following address: nxp.com/SalesTermsandConditions.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX, EMBRACE, GREENCHIP, HITAG, I2C BUS, ICODE, JCOP, LIFE VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, Freescale, the Freescale logo, AltiVec, C 5, CodeTEST, CodeWarrior, ColdFire, ColdFire+, C Ware, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, mobileGT, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, Ready Play, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, SMARTMOS, Tower, TurboLink, and UMEMS are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  ARM, AMBA, ARM Powered, Artisan, Cortex, Jazelle, Keil, SecurCore, Thumb, TrustZone, and μVision are registered trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. ARM7, ARM9, ARM11, big.LITTLE, CoreLink, CoreSight, DesignStart, Mali, mbed, NEON, POP, Sensinode, Socrates, ULINK and Versatile are trademarks of ARM Limited (or its subsidiaries) in the EU and/or elsewhere. All rights reserved . Oracle and Java are registered trademarks of Oracle and/or its affiliates. The Power Architecture and Power.org word marks and the Power and Power.org logos and related marks are trademarks and service marks licensed by Power.org.

© 2023 NXP B.V.

Document Number: 1. Rev. 1.7 10/2023

<!-- image -->