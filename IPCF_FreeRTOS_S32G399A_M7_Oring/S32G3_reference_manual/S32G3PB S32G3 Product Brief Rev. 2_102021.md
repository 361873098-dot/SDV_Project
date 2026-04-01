## S32G3PB S32G3 Product Brief

## High-performance vehicle network processor based on Arm Cortex-M7 and Cortex-A53

## technology

Rev. 2 - 10/2021

## 1 Overview

S32G3 is a family of high-performance vehicle network processors that combine controller area network (CAN), local interconnect network (LIN), and FlexRay networking with high data rate Ethernet networking. It also combines a functional safe-core infrastructure with MPU cores and includes high-level security features. The S32G3 chips are pin-for-pin compatible with S32G2 chips, providing over 2x performance and over 2x system RAM.

Table 1. S32G3 family key enhancements

| Feature                      | Enhancements                                                                                  |
|------------------------------|-----------------------------------------------------------------------------------------------|
| Compute performance          | Up to 2.6 x increase in applications performance (doubling Cortex-A53 cores @ 1.3x frequency) |
| Real-time memory             | Increase SRAM from 6 MB / 8 MB to 15 MB / 20 MB                                               |
| Real-time performance        | Additional pair of Cortex-M7 lockstep cores                                                   |
| Ethernet interface bandwidth | Increased speed from 1 Gbps to 2.5 Gbps on two SGMII interfaces                               |
| Ethernet packet routing      | Performance target increase from 2 Gbps@64B to 3 Gbps@64B                                     |

## Contents

|   1 | Overview...................................1                                |
|-----|-----------------------------------------------------------------------------|
|   2 | Applications..............................2                                 |
|   3 | Block diagram...........................2                                   |
|   4 | Feature comparison..................2                                       |
|   5 | Process technology and power design.......................................5 |
|   6 | Operating parameters.............. 5                                        |
|   7 | Operating conditions and environmental constraints....... 6                 |
|   8 | Module features........................7                                    |
|   9 | Packaging...............................26                                  |
|  10 | Ordering Information.............27                                         |
|  11 | Glossary..................................27                                |

<!-- image -->

S32G3 family includes the following variants:

- S32G399A
- S32G398A
- S32G379A

Product Brief

<!-- image -->

- S32G378A

This document primarily represents the features offered by the superset S32G399A. To compare the features of the S32G3 family variants, see Feature comparison.

## 2 Applications

Combining ASIL D safety, hardware security, high-performance real-time and application processing and network acceleration, this chip targets applications that includes:

- Service-oriented gateways and domain controllers
- Safety processor for ADAS and autonomous driving
- High-performance central compute nodes
- FOTA masters controlling secure software image downloads and their distribution to the ECUs in the network
- Security services and key management
- Smart antennas

## 3 Block diagram

The following is the block diagram for S32G399A, the superset chip in the S32G3 family.

Figure 2. Block diagram

<!-- image -->

## 4 Feature comparison

This table compares the features of the chips in the S32G3 family.

Applications

Table 2. S32G3 feature list and supported functionality

| Feature                      | S32G399A                                                                                 | S32G398A                                                                                 | S32G379A                                                                                 | S32G378A                                                                                 |
|------------------------------|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------|
| Compute and bus modules      | Compute and bus modules                                                                  | Compute and bus modules                                                                  | Compute and bus modules                                                                  | Compute and bus modules                                                                  |
| Applications CPUs            | 4 x Cortex-A53 LS (8 x Cortex-A53)                                                       | 4 x Cortex-A53 LS (8 x Cortex-A53)                                                       | 2 x Cortex-A53 LS (4 x Cortex-A53) 1                                                     | 2 x Cortex-A53 LS (4 x Cortex-A53) 1                                                     |
| Real-time CPUs               | 4 x Cortex-M7 LS                                                                         | 3 x Cortex-M7 LS 2                                                                       | 4 x Cortex-M7 LS                                                                         | 3 x Cortex-M7 LS 2                                                                       |
| Cortex-A53                   | Cortex-A53                                                                               | Cortex-A53                                                                               | Cortex-A53                                                                               | Cortex-A53                                                                               |
| L1 cache                     | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core                                      | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core                                      | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core                                      | 32 KB I-cache and 32 KB D-cache per Cortex-A53 core                                      |
| L2 cache                     | 1 MB per cluster                                                                         | 1 MB per cluster                                                                         | 1 MB per cluster                                                                         | 1 MB per cluster                                                                         |
| Cache coherency interconnect | Supported                                                                                | Supported                                                                                | Supported                                                                                | Supported                                                                                |
| Interrupt controller         | GIC-500                                                                                  | GIC-500                                                                                  | GIC-500                                                                                  | GIC-500                                                                                  |
| Maximum frequency            | Up to 1.3 GHz                                                                            | Up to 1.3 GHz                                                                            | Up to 1.3 GHz                                                                            | Up to 1.3 GHz                                                                            |
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
| Internal RAM                 | 20 MB                                                                                    | 15 MB 3                                                                                  | 20 MB                                                                                    | 15 MB 3                                                                                  |
| RAM ports                    | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes | 16 (four groups of four ports each), and ports in each group are interleaved at 64 bytes |
| DRAM                         | DDR3L and LPDDR4 - up to 4 GB                                                            | DDR3L and LPDDR4 - up to 4 GB                                                            | DDR3L and LPDDR4 - up to 4 GB                                                            | DDR3L and LPDDR4 - up to 4 GB                                                            |
| DRAM PHY                     | x32                                                                                      | x32                                                                                      | x32                                                                                      | x32                                                                                      |
| QuadSPI instances            | 1                                                                                        | 1                                                                                        | 1                                                                                        | 1                                                                                        |

Table continues on the next page...

Table 2. S32G3 feature list and supported functionality (continued)

| Feature                               | S32G399A                                                     | S32G398A                                                     | S32G379A                                                     | S32G378A                                                     |
|---------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|
| uSDHC instances                       | 1                                                            | 1                                                            | 1                                                            | 1                                                            |
| Fuses                                 | 8 KB bank                                                    | 8 KB bank                                                    | 8 KB bank                                                    | 8 KB bank                                                    |
| Standby SRAM with ECC                 | 32 KB                                                        | 32 KB                                                        | 32 KB                                                        | 32 KB                                                        |
| Security modules                      | Security modules                                             | Security modules                                             | Security modules                                             | Security modules                                             |
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

Table continues on the next page...

Table 2. S32G3 feature list and supported functionality (continued)

| Feature                               | S32G399A                                                     | S32G398A                                                     | S32G379A                                                     | S32G378A                                                     |
|---------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|--------------------------------------------------------------|
| Clocking, power, and reset modules    | Clocking, power, and reset modules                           | Clocking, power, and reset modules                           | Clocking, power, and reset modules                           | Clocking, power, and reset modules                           |
| FIRC frequency                        | 48 MHz                                                       | 48 MHz                                                       | 48 MHz                                                       | 48 MHz                                                       |
| SIRC frequency                        | 32 KHz                                                       | 32 KHz                                                       | 32 KHz                                                       | 32 KHz                                                       |
| FXOSC frequency                       | 20-40 MHz                                                    | 20-40 MHz                                                    | 20-40 MHz                                                    | 20-40 MHz                                                    |
| PLLDIG instances                      | 5                                                            | 5                                                            | 5                                                            | 5                                                            |
| Low-power mode                        | Supported                                                    | Supported                                                    | Supported                                                    | Supported                                                    |
| RTC                                   | 1 with API function                                          | 1 with API function                                          | 1 with API function                                          | 1 with API function                                          |
| Wake-up                               | 24 wake-up sources                                           | 24 wake-up sources                                           | 24 wake-up sources                                           | 24 wake-up sources                                           |
| Miscellaneous                         | Miscellaneous                                                | Miscellaneous                                                | Miscellaneous                                                | Miscellaneous                                                |
| Package specifications and dimensions | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm | 525 flip-chip plastic ball-grid array; 19 mm x 19mm x 0.8 mm |

1. Cortex-A53\_2 and Cortex-A53\_3 have been defeatured in cluster 0 and cluster 1.
3. SRAM (12, 13, 14, 15) i.e., the highest address range (0x34F0\_0000-0x353F\_FFFF) associated to Cortex-M7\_2 have been defeatured. See the System RAM Controller chapter of the S32G3 Reference Manual for details on internal RAM support across the family.
2. Cortex-M7\_2 has been defeatured. See the System RAM Controller chapter of the S32G3 Reference Manual for details.

## 5 Process technology and power design

The S32G3 chip family is based on the following process technology and general power design concepts:

- Fabricated in 16nm FinFET (16FFC) process technology
- Low-power design
- Dynamic clock gating of cores and peripherals
- Standby power-gated mode allowing wake-up (with 32 KB retained RAM) from a subset of input pins, a timer, or both
- Software-controlled clock gating of peripherals

## 6 Operating parameters

The S32G3 processor operating parameters are as follows:

- 0.8 V for digital core input supply voltage
- 1.8 V and 3.3 V digital I/O rail
- 1.8 V digital I/O rail, PCIe
- 1.1 V/1.35 V DDR pads for LPDDR4/DDR3L and a 1.8 V pre-driver supply
- 1.8 V for A/D converter reference and analog input pins
- Selectable output edge rate control (slow/medium/fast)
- Designed with EMI reduction techniques
- Phase locked loop
- Core and System clock with frequency modulation

- On-chip bypass capacitance
- Software-selectable output edge rate control
- Schmitt trigger on selected inputs
- Configurable pins
- Selectable pullup, pulldown or no pull on all SIUL controlled pins
- Selectable open drain
- Unused pins configurable as GPIO
- Compatible with NXP VR5510 PMIC + PF53 core supply

## 7 Operating conditions and environmental constraints

This section describes the operating conditions and environmental constraints under which the S32G3 chip is fully operational.

- Fully static operation: 0 MHz to 1.3 GHz with frequency modulation support (CORE\_CLK)
- Digital I/O input supply voltage (for pad segments supporting 1.8 and 3.3 V nominal supply voltage): 1.68 V to 1.92 V/3.08 V to 3.52 V (minimum tolerance)
- Digital I/O input supply voltage (for pad segments supporting 1.8V only nominal supply voltage): 1.68 V to 1.92 V (minimum tolerance)
- Digital core input supply voltage: 0.75 V to 0.87 V
- A/D converter reference and analog input pins: 1.68 V to 1.92 V
- A/D reference pins supply both converter reference and internal switch
- Junction temperature: -40°C to +125°C
- Particle Radiation:
- Alpha Particles
- Alpha particle flux: &lt; 0.001 alpha/cm 2 /h
- low alpha mold compound material required (if applicable)
- low bump flux required
- High-energy cosmic neutrons
- Neutron flux: &lt; 14 neutrons/cm 2 /h (from 10 to 800 MeV), following the JESD-89 standard (normal background neutron flux at sea level at New York City, NY)
- Mission profile:
- Lifetime: 10 years, with 10% operating time, the chip is powered off outside of operating time (equivalent to 8760 hours of active operation).
- Weighted junction temperature over lifetime: 105°C
- The following need to be supported for operation:
- Maximum junction temperature: 125°C
- Minimum junction temperature: -40°C
- Electrostatic discharge (ESD):
- 250V CDM AEC Q100-011 Level C3
- 2kV HBM AEC Q100-002 Level H2

## 8 Module features

## 8.1 Compute and bus modules

## 8.1.1 Cortex-A53 Core Complex

- Two clusters with each cluster with dual or quad Cortex-A53 processors running up to 1.3 GHz and a Snoop Control Unit (SCU) that can be used to ensure coherency within the cluster. The two clusters are connected with a cache coherent interconnect
- Optionally configurable lock step capability between clusters (second cluster to be lock stepped with first cluster)
- Implements Armv8-A AArch64 and AArch32 ISAs
- AArch64 execution state
- Features 31 64-bit general purpose registers, with a 64-bit Program Counter (PC), Stack Pointer (SP), and Exception Link Registers (ELRs).
- Provides a single instruction set, A64
- Defines the Armv8 exception model, with four exception levels, EL0-EL3, that provide an execution privilege hierarchy.
- Features Virtual Addresses (VAs) held in 64-bit registers. The Cortex-A53 VMSA implementation maps these to 40-bit Physical Address (PA) maps.
- Defines a number of PSTATE elements that hold processor state. The A64 instruction set includes instructions that operate directly on various PSTATE elements.
- Names each System register using a suffix that indicates the lowest exception level at which the register can be accessed.
- AArch32 execution state. This execution state is backwards-compatible with implementations of the Armv7-A architecture profile that include the Security Extensions and the Virtualization Extensions:
- Features 13 32-bit general purpose registers, and a 32-bit PC, SP, and link register (LR). Some of these registers have multiple banked instances for use in different processor modes.
- Provides two instruction sets, A32 and T32
- Provides an exception model that maps the Armv7 exception model onto the Armv8 exception model and Exception levels. For exceptions taken to an Exception level that is using AArch32, this supports the Armv7 exception model use of processor modes.
- Features 32-bit VAs. The VMSA maps these to PA maps that can support PAs of up to 40 bits.
- Collects processor state into the Current Processor State Register (CPSR).
- 32 KB/32 KB L1 Instruction/Data Cache
- 1 MB L2 Cache for each cluster
- 8-Stage pipeline
- 2.8 to 3.2 DMIPS/MHz (depending on compiler options)
- Private Timer per core
- Cortex-A53 Neon MPE(Media Processing Engine) coprocessor
- Vector Floating-Point version 3 (VFPv3) architecture extension for floating-point computation that is fully compliant with the IEEE 754 standard
- The Cortex-A53 processor implements the Arm Generic Interrupt Controller (GIC) GICv4 architecture profile.
- 1x 128-bit AXI master interface per cluster
- Parity or ECC protection for the SRAMs (the L1 and L2 caches and other memories) within the cluster

## 8.1.2 Generic Interrupt Controller (GIC)

The CoreLink ™ GIC-500 Generic Interrupt Controller is used together with the Cortex-A53 cluster to handle interrupts. It implements the Arm ® Generic Interrupt Controller Architecture Specification version 3.0 to enable support for Armv8 cores.

With the following software-configurable settings of the GIC-500, interrupts can be:

- Enabled or disabled
- Assigned to one of two groups, Group 0 or Group 1
- Prioritized
- Signaled to different processors in multiprocessor implementations
- Either level-sensitive or edge-triggered

The GIC-500 implements:

- The GIC Security Extensions, that support:
- Using Group 0 interrupts as Secure interrupts, and Group 1 interrupts as Non-secure interrupts
- The GIC Virtualization Extensions, that provide hardware support for managing virtualized interrupts

The GIC-500 implements the interrupt types:

- 16 Software Generated Interrupts (SGIs)
- Private Peripheral Interrupts (PPIs) for each processor
- A configurable number of Shared Peripheral Interrupt (SPIs)
- Interrupts generated by writing to the AXI4 slave port, known as message-based interrupts
- An Interrupt Translation Service (ITS) that provides ID translation and core migration for message-based interrupts

## 8.1.3 Cache Coherency Interconnect (CCI)

CCI maintains the coherency of the Arm Cortex-A53 clusters, with non-CPU master accesses to system resources.

- Support for fully coherent initiators: Arm Cortex-A53 CPUs
- Support for I/O coherent initiators: PCIe, Ethernet

## 8.1.4 Arm Cortex-M7 Core Complex

The main features of the Cortex-M7 processor include:

- Up to 400 MHz
- An in-order issue, super-scalar pipeline with dynamic branch prediction.
- DSP extensions
- FPU
- The Armv7-M Thumb instruction set, defined in the Arm ® v7-M Architecture Reference Manual.
- 2 way set-associative 32 KB/32 KB L1 Instruction/Data Cache with parity error/ECC protection
- 64 KB of DTCM split equally between lower and upper TCM
- Backdoor system bus port that provides TCM access to other bus masters
- Configurable nested vectored interrupt controller (NVIC)
- Memory protection unit (MPU) with 16 regions
- Advanced configurable debug and trace components
- Embedded Trace Macrocell (ETM)

- Low-power features including architectural clock gating, sleep mode and Wake-up Interrupt Controller (WIC).
- Delayed Lock step operation with output comparison for ISO 26262

## 8.1.5 Nested Vectored Interrupt Controller (NVIC)

The integrated NVIC supports and manages low latency interrupt processing:

- Registers for managing interrupt sources, interrupt behavior, and interrupt routing to the Cortex-M7
- Enabling, disabling, and generating processor interrupts from hardware (peripheral) interrupt sources
- Generating software interrupts
- Interrupt masking and prioritization

## 8.1.6 Safe Enhanced DMA Controller (eDMA3)

The eDMA3 controller is a third-generation module capable of performing complex data movements via 32 programmable channels, with minimal intervention from the host processor. The hardware micro architecture includes a DMA engine which performs source and destination address calculations, and the actual data movement operations, along with an SRAM-based memory containing the TCDs for the channels. This implementation is utilized to minimize the overall block size.

The eDMA3 module provides the following features:

- 32 channels support independent 8, 16, or 32-bit single value or block transfers
- Supports variable sized queues and circular queues
- Source and destination address registers are independently configured to post-increment or remain constant
- Each transfer is initiated by a peripheral, CPU, or eDMA channel request
- Each eDMA channel can optionally send an interrupt request to the CPU on completion of a single value or block transfer
- DMA transfers possible between system memories and peripheral registers like serial interfaces, ADC, Timer, etc.
- Programmable DMA Channel Mux allows assignment of any DMA source to any available DMA channel.
- eDMA abort operation through software
- Buffer memory with ECC protection and fault insertion
- Built-in CRC generation for transferred data
- Virtualization support (channel programming model organized in 4 KB pages per channel)

The operation of two identical eDMA3 blocks in a delayed lockstep configuration is compared with RCCUs and discrepancies reported to the FCCU block for an according system reaction to the fault.

## 8.1.7 DMA Channel Multiplexer (DMAMUX)

The chip has two DMAMUX instances per eDMA3 pair with different trigger inputs.

Each DMAMUX has the following main features:

- Independently selectable DMA channel routers (inputs) for each DMA peripheral slot
- 8 periodic DMA triggers from PIT (4x PIT\_0, 4x PIT\_1)
- Total of 32 DMA slots (output of DMAMUX)
- Each channel router is assigned to one of the following sources
- One of the peripheral DMA sources
- The always-enabled source

## 8.1.8 Debug

The debug system consists of the following ports:

- Support for CoreSight debug infrastructure
- JTAG (IEEE 1149.1) with up to five pins (TDI, TDO, TMS, TCK and JCOMP{TRST})
- Debug of all computing engines, including accelerators (access via APB interface)
- Support for breakpoints and run control
- Security related features:
- A range of security levels from NO JTAG to fully Open based on eFuse configuration for both debug and Test
- Support for secured and non-secured invasive/non-invasive debug to allow further granularity in debug accesses
- Support for field return parts to open access for debug and test to allow failure analysis
- Following debug capabilities are supported:
- Access to core and memory mapped resource examination and modification
- Support for monitor mode and halt mode
- Breakpoint/ Watchpoint control
- Cortex-A53 supports six breakpoints and four watchpoints
- System profiling and performance monitoring
- Following trace capabilities are supported:
- Instruction trace of all Cortex-A53 CPUs
- Instrumentation trace of all Cortex-A53 CPUs
- Instruction trace of all Cortex-M7 CPUs
- Instruction trace of Sequence CPUs
- Data trace of AHB peripherals
- Data trace of AHB bus masters
- Data trace of external DRAM traffic (with address filtering)
- Data trace of internal SRAM traffic (with address filtering)
- Single and multi core trace generation
- Global time stamping
- Support Arm Real Time trace Interfaces: Aurora Trace Port
- For Aurora trace port: 4x lanes with up to 2.5 GHz
- Support for trace to internal memory
- Cross trigger support
- Watchpoints in the SRAM controller and DDR controller data path:
- Comparators to monitor address and master ID
- Support for pairing of comparators to create address and master ID ranges
- Configurable for any or all: read access; write access; execute access
- Breakpoint generation for watchpoint hits

## 8.1.9 Software Watchdog Timer (SWT)

SWT has the following features:

- 32-bit timeout register to set the timeout period
- Timer running on 48 MHz internal RC-oscillator clock for increased functional safety
- Programmable selection of window mode or regular servicing
- Programmable selection of reset or interrupt on an initial time-out
- Master access protection
- Hard- and soft- configuration lock bits
- Reset configuration inputs allow timer to be enabled out of reset

## 8.1.10 System Timer Module (STM)

STM implements these features:

- 32-bit up counter with 8-bit pre-scaler
- Four 32-bit compare channels
- Independent interrupt source for each channel
- Counter can be stopped in Debug mode

## 8.2 Memory modules

## 8.2.1 SRAM Controller (SRAMC)

SRAMC nterfaces between the bus system and the System RAM arrays. The chip contains multiple SRAM controllers that are implemented in an interleaved scheme across the full SRAM block.

- 16 SRAM controllers (4 group of 4 SRAM Controllers) interleaved at 64 byte for ports in each group, supporting 1.25 MB RAM array per controller (20 MB total)
- Interleaved on 64-byte boundaries, aligned to 128-bit wide cache line access
- 128-bit data, non-blocking, interface to system interconnect, supporting multiple outstanding transactions
- ECC support on 64-bit boundaries

## 8.2.2 DDR memory Controller (DDRCTRL)

The DDR subsystem contains one 32-bit wide DDR memory controller to connect to off-chip DDR memories.

The DDR subsystem supports the following features:

- DDR3L and LPDDR4 DRAM types
- Support for 16-bit and 32-bit DRAM modules, allowing up to two ranks
- Support for one or two DRAM devices to be connected per DDR memory controller in parallel
- Clock Frequency of up to 800 MHz (DDR-1600: 1600 MHz double data rate) on the DDR memory interface for DDR3L
- Clock Frequency of up to 1600 MHz (DDR-3200: 3200 MHz double data rate) on the DDR memory interface for LPDDR4
- Up to 32 bits addressable memory space for the DDR memory controller.
- Scheduler and re-ordering queue to optimize transaction order for reads and writes to improve utilization (out of order execution of reads)
- Quality of service features to accelerate critical transactions

- Inline ECC scheme to protect the data stored in DRAM (single error correct, double error detect), optimized to reduce bandwidth impact
- Region support for the inline ECC with seven configurable regions

## 8.2.3 Quad Serial Peripheral Interface (QuadSPI)

QuadSPI is an interface for external serial Flash memories for code / data storage and code execution.

- Supports industry standard single, dual, quad, octal mode serial flashes
- Support for 1.8 V and 3.3 V interface
- Supports DDR serial flash for high performance
- Support of the following modes:
- 1 x 4-bit, 1 x 1-bit with up to 80 MHz clock in DDR mode and 108 MHz in SDR mode
- Octal I/O serial flash with data strobe support: 1 x 8-bit
- Octal I/O in DDR mode with 200 MHz clock, 8 bit data
- Octal I/O in SDR mode with 120 MHz, 8 bit data
- Differential clock support for 1.8 V HyperFlash devices
- Controller architecture enables access to external flash resulting peak read bandwidth of 400 MBytes/s
- Execute in Place (XiP)
- Flexible buffering scheme
- Multi-master, prioritized access
- The embedded On-the-Fly AES Decryption (OTFAD) module adds zero cycles of additional latency to decrypt the code and data fetched from the external flash memory.
- Supports CTR-AES128 decryption
- The external memory access is completely offloaded to the QuadSPI and OTFAD. For example, a core reads from a memory mapped QuadSPI address location and the QuadSPI module fetches the data over SPI from the external NOR flash and decrypt the data stream returning the plain text data to the core.
- Support for parity on the interface to flash memories

## 8.2.4 Ultra Secured Digital Host Controller (uSDHC)

uSDHC supports the following type of cards:

- Conforms to the SD Host Controller Standard Specification version 3.1
- Compatible with the MMC System Specification version 4.2/4.3/4.4/4.41/4.5/5.0/5.1
- Compatible with the SD Memory Card Specification version 3.0 and supports the Extended Capacity SD Memory Card
- Compatible with the SDIO Card Specification version 3.0
- Designed to work with SD Memory, miniSD Memory, SDIO, miniSDIO, SD Combo, MMC, MMC-plus, and RS-MMC cards
- Card bus clock frequency up to 200 MHz, HS200/HS400/HS400 Enhanced Strobe
- Supports 1-bit / 4-bit SD and SDIO modes, 1-bit / 4-bit / 8-bit MMC modes
- SDIO cards using 4 parallel data lines
- In SDR mode: Up to 832 Mbps of data transfer
- In DDR mode: Up to 400 Mbps of data transfer
- SDXC cards using 4 parallel data lines

- In SDR mode: Up to 832 Mbps of data transfer
- In DDR mode: Up to 400 Mbps of data transfer
- MMC cards using 8 parallel data lines
- In SDR mode: Up to 1600 Mbps of data transfer
- In DDR mode: Up to 3200 Mbps of data transfer
- Supports single block/multi-block read and write
- Supports block sizes of 1 ~ 4096 bytes
- Supports the write protection switch for write operations
- Supports both synchronous and asynchronous abort
- Supports pause during the data transfer at block gap
- Supports SDIO Read Wait and Suspend Resume operations
- Supports Auto CMD12 for multi-block transfer
- Host can initiate non-data transfer command while data transfer is in progress
- Allows cards to interrupt the host in 1-bit and 4-bit SDIO modes, also supports interrupt period
- Embodies a fully configurable 256x32-bit FIFO for read/write data
- Supports internal and external DMA capabilities
- Support voltage selection by configuring vendor specific register bit
- Supports Advanced DMA to perform linked memory access

## 8.3 Security and boot modules

## 8.3.1 Hardware Security Engine (HSE\_H)

HSE\_H is a subsystem that implements the security functions for the chip. It provides cryptographic services to host CPUs and the network accelerators, targeting current security specifications (e.g. SHE, HSM, EVITA Full). HSE\_H is responsible for establishing the root of trust on the chip during the boot process.

HSE\_H includes the following features:

- Secure boot of customer code using Asymmetric or Symmetric keys
- Highly-featured Symmetric &amp; Asymmetric Accelerators
- The following cryptographic functions are supported in hardware:
- AES (up to 256)
- SHA-1, SHA-2, and SHA-3
- Wide support of Elliptic curves (ECC)
- RSA (up to 4096)
- Arm Cortex-M7 CPU, at 400 MHz operation
- Up to 830 KB Secure RAM
- TRNG
- PRNG
- Side Channel physical protection
- Glitch Attack counter-measures

- Firmware Over-the-Air (FOTA) support

## 8.3.2 Extended Resource Domain Controller (XRDC)

XRDC provides an integrated, scalable architectural framework for access control, system memory protection and peripheral isolation. It allows software to assign chip resources including processor cores, non-core bus masters, memory regions and slave peripherals to processing domains to support enforcement of robust operational environments. First, each bus mastering resource is assigned to a domain identifier (domain ID). Next, the access control policies for the individual domains are programmed into any number of slave memory region descriptors and slave peripheral domain access control registers. Finally, all accesses throughout the chip are monitored concurrently to determine the validity of each and every access. If a reference from a given domain has sufficient access rights, it is allowed to continue, else the access is aborted and error information captured.

The access control scheme defined by the XRDC supports a 4-level model, combining the traditional privileged (also known as supervisor) and user modes with an additional signal defining the secure, non-secure attributes of each memory reference. The result is a 4-level hierarchical access control mechanism, where:

SecurePriv(ileged) &gt; SecureUser &gt; Non-securePriv(ileged) &gt; Non-secureUser with different access control policies based on read and write references. Combined with the user/privileged and secure/nonsecure attributes, a domain ID is associated with every system bus transaction and forms the hardware basis for implementation of the XRDC's access control mechanisms.

Access to shared memory regions and slave peripherals can be dynamically controlled with a hardware semaphore. If a hardware semaphore is enabled for a given address space or peripheral, then writes to the targeted address space are only allowed if the requesting domain owns the semaphore. This capability allows the access control policy for a given resource to be dynamically revised based on hardware semaphore ownership.

The key features of the XRDC include:

- Assignment of chip resources to processing 'domains'. Resources are categorized into 4 groups
- Processor cores, non-core bus masters, slave memories and slave peripherals
- Each domain is assigned a unique domain identifier (domain ID, DID)
- Domain ID is a new attribute associated with every system bus transaction
- Used in conjunction with user/privileged, secure/non-secure attributes
- Access rights to slave targets defined in region descriptor registers for memories, access control registers for peripherals
- Supports sharing of memory and peripherals with inclusion of hardware semaphores to dynamically determine access rights
- Built upon a 4-level hierarchical access control model
- SecurePriv(ileged) &gt; SecureUser &gt; Non-securePriv(ileged) &gt; Non-secureUser
- Encoded into a 3-bit per-domain access control policy (ACP) used throughout the XRDC
- Certain processors do not support the Non-securePriv state. For these cores, the model simplifies to a 3-state definition: SecurePriv &gt; SecureUser &gt; Non-secureUser

## 8.3.3 Arm TrustZone Technology

The Arm TrustZone security extensions are supported in the Arm Cortex-A53 processors. The TrustZone signals from the processors are used within the Extended Resource Domain Controller (XRDC) to maintain resource isolation at a system level. At a processor level, the Arm TrustZone software stack is compatible, to elevate between secure and non-secure privilege states. At a system level, XRDC configures the system resource isolation.

## 8.3.4 Lifecycle

The chip supports a lifecycle mechanism that is progressively increasing security through product development and production.

- Controls level of protection for key access, boot configuration and debug.

- 4 Lifecycle states supported:
- Customer Deliverable
- OEM Production
- In Field
- Failure Analysis
- Lifecycle states can only progress forwards, onto the next sequential state.

## 8.3.5 Boot Assist ROM (BAR)

BAR is the default location from which the chip always starts the boot process.

BAR provides the following features:

- The boot process depends on the reset type, boot configuration pins and eFuses.
- Read the image vector table and boot data structures. Optionally, download image to memory.
- Allow download and decryption of AES encrypted images from external flash
- Retrieve Device Configuration Data (DCD) from the external program image
- Alternate serial boot-loading via FlexCAN, UART
- Execute image
- Initiates download of the HSE\_H firmware and supports secure boot

The execution of the BAR code starts from the HSE\_H.

Execution of customer application code is configurable to start on either Arm Cortex-M7 or Arm Cortex-A53 processors

## 8.4 Clocking, power and reset

## 8.4.1 Fast Internal RC Oscillator (FIRC)

This chip has a 48 MHz RC oscillator that provides these features:

- Nominal frequency 48 MHz
- Capacitor trimming bits and resistor trimming bits
- Inverter based comparator which does not requires current source
- ±5% variation over voltage and temperature after process trim
- Clock output of the RC oscillator serves as system clock source in case loss of lock or loss of clock is detected by the PLL
- RC oscillator is used as the default system clock during startup

## 8.4.2 Slow Internal RC Oscillator (SIRC)

The chip supports a 32 KHz internal RC oscillator for low-power operation (Standby).

## 8.4.3 Fast External Crystal Oscillator (FXOSC)

FXOSC provides these features:

- Crystal Input mode
- Oscillator input frequency of 20 MHz, 24 MHz, and 40 MHz
- PLL reference
- Bypass capability

## 8.4.4 Phase Locked Loops (PLL)

The chip offers several PLLs:

- One Core PLL for CPUs and high speed chip interconnect supporting frequency modulation (programmable)
- One DDR PLL for the DRAM interface
- One PERIPH PLL for the peripherals including CAN and FlexRay (not frequency modulated)
- One AURORA PLL for Aurora debug interface
- One ACCEL PLL for Packet Forwarding Engine

The PLLs have the following major features:

- Modes of operation:
- Bypass mode
- Normal PLL mode with crystal reference (default)
- Normal PLL mode with external reference
- Normal PLL mode with internal RC oscillator input (for example, for operation during boot up)
- Lock monitor circuitry with lock status
- Loss of Lock detection
- Option to switch on and off the frequency modulation
- Digital fractional synthesis (DFS) outputs for additional fractionally divided clock domains

## 8.4.5 Power management

The power management architecture contains functionality for the following features:

- Interface to an external PMIC that provides all the chip voltages
- Go/No-Go detectors for all power segments
- Power Modes:
- Run mode
- Standby mode
- Hardware control of Run mode entry
- Software control of Standby mode entry, and wake-up event management for Standby exit
- Software control of subsystem disabling to reduce power consumption during Run mode
- A Standby low power mode is supported. Whilst in Standby mode, the following functionality is available:
- 23 external wake-up sources
- Real-time clock, using internal 32 KHz SIRC
- Autonomous Periodic Interrupt, supporting wake-up
- 32 KB Retained RAM

## 8.4.6 Real-Time Clock / Autonomous Periodic Interrupt (RTC-API)

The chip contains one RTC and one API, where both can perform 32-bit comparisons.

- Both RTC and API timers can generate interrupts as well as wakeup from Standby mode
- 32-bit counter
- Selectable clock source from 32 KHz SIRC, 48 MHz FIRC, and external pin

- Optional 512 prescaler and optional 32 prescaler connected in series in the clock path feeding the 32-bit counter
- 32-bit counter supports times up to greater than 1.5 months with 1 ms resolution
- 32-bit compare value to support interrupt intervals of 1 second up to greater than 1 hour with 1 second resolution
- 32-bit compare value to support wakeup intervals of 1.0 ms to 1 second
- Wakeup logic has separate enable to support changing compare value while RTC running
- Operates in all modes of operation

## 8.4.7 Wakeup Unit (WKPU)

WKPU supports these features:

- Non-maskable Interrupt support with:
- 1 external NMI pin
- Glitch filter
- Active (rise/fall) edge selection control for events
- External wakeup and interrupt support with:
- 23 external wakeup and interrupt pins
- Individual glitch filters
- Independent interrupt mask
- Individual active (rise/fall) edge selection control for events
- Configurable system wakeup triggering from all interrupt sources
- Individual wakeup boot mode selection
- Individual pin pullup/pulldown enable control

## 8.5 Safety modules

## 8.5.1 Redundancy Control and Checker Unit (RCCU)

RCCU checks all outputs of the delayed lock step blocks (addresses, data, control signals). It has the following features:

- Guarantees highest possible diagnostic coverage (check of checker)
- Used as checkers on the eDMA, Cortex-M7 and Cortex-A53 output signals.
- Redundancy of the checks by replicated compare units for the ECC encoded signal groups

## 8.5.2 Fault Collection and Control Unit (FCCU)

FCCU provides an independent fault reporting mechanism even in case the CPU is misbehaving.

FCCU has the following features:

- Redundant collection of hardware checker results
- Redundant collection of error information and latch of faults from critical modules on the chip
- Collection of test results
- FCCU status register reporting the chip status
- User selection of critical signals from different fault sources inside the chip
- Configurable and graded fault control
- Internal reactions (programmable via SW)

- No reaction
- Latched into a register
- Alarm interrupt or NMI
- Request RGM (reaction programmed in RGM to Reset)
- External reaction
- Failure is reported to the outside world via two configurable output pins
- Disabling of a set of communication controllers (for example FlexRay, CAN, Ethernet)
- FCCU output supervision unit (FOSU)
- Five fault inputs directly triggerable by SW

## 8.5.3 Thermal Monitoring Unit (TMU)

TMU is a temperature sensor with the following key parameters:

- Targeting high temperature checks for functional safety
- Nominal temperature range from -40 °C to +125 °C
- Accuracy at +125 °C is +/- 5°C (including accuracy of calibration during production test), at lower temperatures accuracy is +/- 10°C
- Temperature sensor output is readable via digital interface or alternatively measured via on-chip ADC to provide digital code corresponding to temperature
- Calibration table for trimming of temperature sensor
- Multiple sites to sense temperature

## 8.5.4 Built In Self-Test modules (BIST)

This chip includes the following protection against latent faults:

- Software triggered self-test of volatile memory (SRAM) and read-only memory (test pattern written and checked by MBIST) and random logic (scan-chain based test pattern generated and checked by LBIST)

## 8.5.5 Safety by Software (SBSW)

SBSW has the following features.

- 64 instances of TMC
- Each TMC implements a comparator where the comparison event is observed by TMC time monitor for proper timing behavior.
- Interface for TMWDP with 64 automata. TMWDP models and observes the correct logical and temporal sequence of application events.
- TMWDP timer for driving TMWDP clock period.
- A controller that aggregates TMWDP and TMC statuses, controls the access to TMC and TMWDP configuration registers, and drives the fault reporting to FCCU.

## 8.6 Communication interface modules

## 8.6.1 Low Latency Communications Engine (LLCE)

LLCE is a dedicated subsystem optimized to manage CAN, LIN, and FlexRAY communications. LLCE includes the following functionality:

- 16 BCAN channels

- 4 LIN channels
- 1 FlexRay (dual channel)
- 4 SPI

LLCE is a firmware-based architecture.The standard NXP LLCE firmware provides the following features:

- TX look-up hardware acceleration
- RX look-up hardware acceleration
- Provides an efficient fire and forget interface for the host interface. Reducing the load on host CPU by enabling a non-blocking interface
- Provides time synchronization across all interfaces. Enabling common time-bases across all networks
- Full implementation of the classic CAN and CAN FD protocol specification, version ISO11898-1:2015
- Full implementation of the FlexRay Communications System Protocol specification, version 2.1 Rev A
- Full implementation of the LIN protocol specification, version 1.3, 2.0, 2.1 and 2.2

The LLCE is a firmware based solution so there is the potential to develop advanced features:

- Data Consistency checking
- Data formatting
- Diagnostic mirroring
- Local routing tables
- Intrusion detection software
- Security offload using the HSE to secure all CAN, LIN, and FlexRay frames
- Enabling security services at the lowest possible layer
- SPI expansion ports to add additional interfaces (for example, SPI-to-QuadLIN)

A subset of the BCAN, FlexRay, and LIN modules are implemented outside of the LLCE (see Feature comparison). These are implemented on the main peripheral bus and do not fully utilize all features of the LLCE. This is shown in the following diagram.

<!-- image -->

## 8.6.2 Ethernet Packet Forwarding Engine (PFE)

The chip uses a PFE to provide high-performance Ethernet interfaces.

All ports support MII/RMII and RGMII at 10/100 and 100/1G respectively. SGMII is supported on three ports at 100M/1G/2.5G.

PFE provides the following features:

- Performs the IEEE 802.3 protocol for 10/100/1000/2500 Mbps (rates depend on PHY interface mode)
- Supports packet sizes from 64 bytes up to 1522 bytes
- L2/3/4 packet classification and header modification (for example, NAT)
- Supports autonomous handling of all packets belonging to a given stream, without Host CPU intervention, following stream creation
- Capable of addressing DDR and internal SRAM
- Closely coupled interaction with security co-processor for IPsec offload
- Capable of routing/bridging an aggregate of 3 Gbps of traffic at minimum packet sizes
- Ingress QoS support
- Support for TSN time synchronization (802.1AS-Rev)
- Firmware based architecture

One of the four S32G Ethernet interfaces is not supported by PFE. This Ethernet interface (GMAC0) additionally supports TSN time aware shaping (802.1Qbv) and pre-emption (802.1Qbu) functionality. The following figure shows the available interfaces.

Module features

<!-- image -->

## 8.6.3 PCI Express Gen 3 (PCIe)

The chip contains two PCI Express communication interfaces with integrated PHY.

- Supports PCI Express root complex mode
- Supports PCI Express endpoint mode
- Supports Dual Mode (DM)
- PCI Express 3.0 specification, backwards compatible with PCIe 2.1 (5 Gbps) and PCIe 1.1 (2.5 Gbps)
- 2 lane configuration for up to 8 Gbps per lane. 16 Gbps total. (1.97G Bytes/sec net bandwidth after 128/130 bit encoding/decoding)
- Supports transaction layer, link layer and physical layer
- Integrated PHY includes transmitter, receiver, PLL, digital core, and ESD.
- Payload size of max. 256 Bytes per packet.
- The AXI Bridge Module supports the following features.
- AXI Master and Slave interfaces for inbound and outbound PCI Express requests.
- Multi-function support (up to 8 functions) [EP mode only].
- All types of PCI Express transactions supported through the AXI Bridge.

- A shared AXI Slave interface to access native core's CDM registers
- Programmable buffer sizes for AXI master and slave requests.
- Programmable MSI Interrupt controller to detect and terminate inbound MSI TLP's in the bridge for RC and DM
- Internal DMA support to off-load CPU
- Supports common clock mode with an external reference clock generation for Gen3 and as option an internal reference clock generation for speeds up to Gen2.
- Each PHY lane can be optionally used for SGMII mode of the Ethernet module. The possible configurations are shown in the following diagram. Speed options for SerDes modes are detailed in the SerDes chapter of the S32G3 Reference Manual.

<!-- image -->

## 8.6.4 Universal Serial Bus OTG Controller (USBOTG)

The USB 2.0 controller with ULPI interface provides point-to-point connectivity that complies with the USB specification Rev. 2.0. The chip supports an external USB 2.0 PHY using the ULPI interface.

Key features of the USB 2.0 controller include the following:

- Complies with USB specification, Rev. 2.0
- Supports high-speed (480 Mbps), full-speed (12 Mbps) and low-speed (1.5 Mbps) modes
- USB Host/Device mode (OTG - Dual role)
- Support Suspend mode and low power mode of operation

- Connects to external PHY using ULPI interface

## 8.6.5 Inter-Integrated Circuit (I 2 C)

- Compatible with I 2 C bus standard and SMBus version 2 features
- Multi-master operation
- Software programmable for one of 256 different serial clock frequencies
- Programmable slave address and glitch input filter
- Software selectable acknowledge bit
- Interrupt driven byte-by-byte data transfer
- Arbitration lost interrupt with automatic mode switching from master to slave
- Calling address identification interrupt
- Start and stop signal generation/detection
- Repeated start signal generation
- Acknowledge bit generation/detection
- Bus busy detection
- DMA support

## 8.6.6 Serial Peripheral Interface (SPI)

SPI provides a synchronous serial interface for communication between the MCU and external devices such as sensors.

SPI provides these features:

- Full duplex, three-wire synchronous transfers
- Master or slave operation
- Programmable master bit rates
- Programmable clock polarity and phase
- End-of-transmission interrupt flag
- Programmable transfer baud rate
- Programmable data frames from 4 to 16 bits
- Extended mode for SPI frames of 32-bit size
- Up to five chip select lines, depending on package and pin multiplexing
- 6 clock and transfer attributes registers
- Chip select strobe available as alternate function on one of the chip select pins for de-glitching
- FIFOs for buffering as many as five transfers on the transmit and receive side
- Queueing operation possible through use of the eDMA
- TX and RX FIFOs can be disabled individually for low-latency updates to SPI queues
- Visibility into TX and RX FIFOs for ease of debugging
- Programmable transfer attributes on a per-frame basis
- Modified SPI transfer formats for communication with slower peripheral devices

## 8.6.7 Cyclic Redundancy Check (CRC)

CRC is a configurable multiple data flow unit to compute CRC on data written to input register

The CRC unit has the following features:

- 3 sets of registers to allow three concurrent contexts with possibly different CRC computations; each of them with different polynomial and seed
- Computes 8-bit, 16-bit or 32-bit wide CRC on the fly (single-cycle computation) and stores result in internal register. The following standard CRC polynomials are implemented:
- x 8 +x 4 +x 3 +x 2 +1 [for bits CRC7:CRC0 as defined in VDA CAN protocol according to SAEJ1850]. The bit field 28:29 of the register CRC\_CFG for each context shall be used to select the polynomial preserving compatibility with previous versions of this IP
- x 16  + x 12  + x 5  + 1 [16-bit CRC-CCITT]

<!-- formula-not-decoded -->

- x 5  + x 3  + x 2 + x + 1 [CRC-8-H2F AUTOSAR polynomial]
- Key engine to be coupled with communication periphery where CRC application is added to allow implementation of safe communication protocol
- Offloads core from cycle consuming CRC and helps checking configuration signature for safe start-up or periodic procedures
- CRC unit connected as peripheral bus on IP bus
- DMA support

## 8.7 Generic modules

## 8.7.1 Periodic Interrupt Timer (PIT)

PIT offers these features:

- Eight general purpose interrupt timers for PIT0 and PIT1
- 32-bit counter resolution, chaining mode to implement a 64-bit timer
- Clocked by 133 MHz clock
- Channels 0 to 3 can be used as trigger for a DMA request

## 8.7.2 12-bit Analog to Digital Converter (ADC)

- Linear successive approximation algorithm with up to 12-bit resolution at 1.8 V
- Up to 0.5 MS/s sampling rate
- Up to 6 single-ended external analog inputs plus additional inputs coming from internal sources, per ADC
- Single or continuous conversion
- Single-ended 12-bit
- Configurable sample time and conversion speed
- Conversion complete flag and interrupt
- Power down mode (ADC in inactive state)
- Selectable asynchronous hardware conversion trigger
- Automatic compare with interrupt for various programmable values
- Temperature sensor connected to one channel
- Monitoring of internal supply voltages

- Self-calibration mode and self-test capabilities (supply and capacitive self-test)
- Software selectable presampling
- 4 analog watchdogs comparing ADC results against predefined levels (low, high, range) before results are stored in the appropriate ADC result location
- Programmable DMA enable for each channel

## 8.7.3 FlexTimer Module (FTM)

FTM features include:

- Selectable source clock
- Selectable clock source from peripheral PLL, 48 MHz FIRC, and external pin
- Selecting external clock connects FTM clock to a chip level input pin therefore allowing to synchronize the FTM counter with an off-chip clock source
- Prescaler divide-by 1, 2, 4, 8, 16, 32, 64, or 128
- 16-bit counter
- 6 channels supported
- Each channel can be configured for input capture, output compare, or edge-aligned PWM mode
- All channels can be configured for center-aligned PWM mode
- Each pair of channels can be combined to generate a PWM signal with independent control of both edges of PWM signal
- The FTM channels can operate as pairs with equal outputs, pairs with complementary outputs, or independent channels with independent outputs
- The dead time insertion is available for each complementary pair
- The polarity of each channel is configurable
- The generation of an interrupt per channel
- The generation of an interrupt when the counter overflows
- Testing of input captures for a stuck at zero and one conditions
- Dual edge capture for pulse and period width measurement
- Quadrature decoder with input filter, relative position counting and interrupt on position count or capture of position count on external event (channel 0/1)
- Trigger input signal from Ethernet IEEE 1588 module

## 8.7.4 Cross Trigger Unit (CTU)

CTU allows automatic generation of ADC conversion requests on user selected conditions without CPU load during the PWM period and with minimized CPU load for dynamic configuration.

CTU implements the following features:

- Cross triggering between ADC and FlexPWM
- Double buffered trigger generation unit with up to 8 independent triggers generated from external triggers
- Trigger generation unit configurable in sequential mode or in triggered mode
- Trigger delay unit to compensate the delay of external low pass filter
- Double buffered global trigger unit allowing eTimer synchronization and/or ADC command generation
- Double buffered ADC command list pointers to minimize ADC-trigger unit update

- Double buffered ADC conversion command list with up to 24 ADC commands
- Each trigger has the capability to generate consecutive commands
- ADC conversion command allows to control ADC channel from each ADC, single or synchronous sampling, independent result queue selection
- DMA support with safety features

## 8.7.5 Semaphores2 (SEMA42)

SEMA42 is a memory-mapped module that provides robust hardware support needed in multi-core systems for implementing semaphores and provides a simple mechanism to achieve "lock and unlock" operations via a single write access. The hardware semaphore module provides hardware-enforced gates as well as other useful system functions related to the gating mechanisms.

- Supports 16 hardware-enforced gates in a multi-processor configuration
- Gates appear as a 16-entry byte-size array with read and write accesses.
- Each hardware gate appears as a 16-state, 4-bit state machine.
- Uses the logical bus master number as a reference attribute plus the specified data patterns to validate all write operations.
- Once locked, the gate can (and must) be unlocked by a write of zeroes from the locking processor.
- Secure reset mechanisms are supported to clear the contents of individual gates, as well as a clear\_all capability.

## 9 Packaging

S32G3 chips are pin-compatible within the family and with S32G2 family chips. The following package are available:

- 525 FC-PBGA, 525 balls, mechanical dimensions: 19 mm x 19 mm, pitch 0.8 mm
- 23 x 23 array with corner balls depopulated

## 10 Ordering information

<!-- image -->

## 11 Glossary

| ADAS   | Advanced driver-assistance systems           |
|--------|----------------------------------------------|
| BCAN   | Basic CAN module; part of the LLCE subsystem |
| DDR    | Double data rate                             |
| DRAM   | Dynamic random-access memory                 |
| DTCM   | Data tightly-coupled memory                  |
| ECC    | Error correction code                        |
| ECU    | Electronic control unit                      |
| FPU    | Floating-point unit                          |
| PRNG   | Pseudo random number generator               |
| SDR    | Single data rate                             |

|                      | S32G378A   | S32G379A   | S32G398A   | S32G399A   |
|----------------------|------------|------------|------------|------------|
| ARM Cortex-M7 Cores  | 3          | 4          | 3          | 4          |
| ARM Cortex-A53 Cores | 4          | 4          | 8          | 8          |
| SystemRAM Size       | 15MB       | 20MB       | 15MB       | 20MB       |

| TCD   | Transfer control descriptor                  |
|-------|----------------------------------------------|
| TCM   | Tightly-coupled memory                       |
| TMC   | Time-monitored comparator; part of SBSW      |
| TMWDP | Timed multi-watchdog processor; part of SBSW |
| TRNG  | True random number generator                 |

## How To Reach Us

Home Page: nxp.com Web Support: nxp.com/support

Limited warranty and liability - Information in this document is believed to be accurate and reliable. However, NXP Semiconductors does not give any representations or warranties, expressed or implied, as to the accuracy or completeness of such information and shall have no liability for the consequences of use of such information. NXP Semiconductors takes no responsibility for the content in this document if provided by an information source outside of NXP Semiconductors. In no event shall NXP Semiconductors be liable for any indirect, incidental, punitive, special or consequential damages (including - without limitation - lost profits, lost savings, business interruption, costs related to the removal or replacement of any products or rework charges) whether or not such damages are based on tort (including negligence), warranty, breach of contract or any other legal theory.

Notwithstanding any damages that customer might incur for any reason whatsoever, NXP Semiconductors' aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms and conditions of commercial sale of NXP Semiconductors.

Security - Customer understands that all NXP products may be subject to unidentified or documented vulnerabilities. Customer is responsible for the design and operation of its applications and products throughout their lifecycles to reduce the effect of these vulnerabilities on customer's applications and products. Customer's responsibility also extends to other open and/or proprietary technologies supported by NXP products for use in customer's applications. NXP accepts no liability for any vulnerability. Customer should regularly check security updates from NXP and follow up appropriately.

Customer shall select products with security features that best meet rules, regulations, and standards of the intended application and make the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP. NXP has a Product Security Incident Response Team (PSIRT) (reachable at PSIRT@nxp.com) that manages the investigation, reporting, and solution release to security vulnerabilities of NXP products.

Right to make changes - NXP Semiconductors reserves the right to make changes to information published in this document, including without limitation specifications and product descriptions, at any time and without notice. This document supersedes and replaces all information supplied prior to the publication hereof.

Applications - Applications that are described herein for any of these products are for illustrative purposes only. NXP Semiconductors makes no representation or warranty that such applications will be suitable for the specified use without further testing or modification.

Customers are responsible for the design and operation of their applications and products using NXP Semiconductors products, and NXP Semiconductors accepts no liability for any assistance with applications or customer product design. It is customer's sole responsibility to determine whether the NXP Semiconductors product is suitable and fit for the customer's applications and products planned, as well as for the planned application and use of customer's third party customer(s). Customers should provide appropriate design and operating safeguards to minimize the risks associated with their applications and products.

NXP Semiconductors does not accept any liability related to any default, damage, costs or problem which is based on any weakness or default in the customer's applications or products, or the application or use by customer's third party customer(s). Customer is responsible for doing all necessary testing for the customer's applications and products using NXP Semiconductors products in order to avoid a default of the applications and the products or of the application or use by customer's third party customer(s). NXP does not accept any liability in this respect.

Limiting values - Stress above one or more limiting values (as defined in the Absolute Maximum Ratings System of IEC 60134) will cause permanent damage to the device. Limiting values are stress ratings only and (proper) operation of the device at these or any other conditions above those given in the Recommended operating conditions section (if present) or the Characteristics sections of this document is not warranted. Constant or repeated exposure to limiting values will permanently and irreversibly affect the quality and reliability of the device.

Evaluation products -This product is provided on an 'as is' and 'with all faults' basis for evaluation purposes only. NXP Semiconductors, its affiliates and their suppliers expressly disclaim all warranties, whether express, implied or statutory, including but not limited to the implied warranties of non-infringement, merchantability and fitness for

Table continues on the next page...

<!-- image -->

<!-- image -->

a particular purpose. The entire risk as to the quality, or arising out of the use or performance, of this product remains with customer. In no event shall NXP Semiconductors, its affiliates or their suppliers be liable to customer for any special, indirect, consequential, punitive or incidental damages (including without limitation damages for loss of business, business interruption, loss of use, loss of data or information, and the like) arising out the use of or inability to use the product, whether or not based on tort (including negligence), strict liability, breach of contract, breach of warranty or any other theory, even if advised of the possibility of such damages.

Notwithstanding any damages that customer might incur for any reason whatsoever (including without limitation, all damages referenced above and all direct or general damages), the entire liability of NXP Semiconductors, its affiliates and their suppliers and customer's exclusive remedy for all of the foregoing shall be limited to actual damages incurred by customer based on reasonable reliance up to the greater of the amount actually paid by customer for the product or five dollars (US$5.00). The foregoing limitations, exclusions and disclaimers shall apply to the maximum extent permitted by applicable law, even if any remedy fails of its essential purpose.

Translations - A non-English (translated) version of a document is for reference only. The English version shall prevail in case of any discrepancy between the translated and English versions.

NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, COOLFLUX,EMBRACE, GREENCHIP, HITAG, ICODE, JCOP, LIFE, VIBES, MIFARE, MIFARE CLASSIC, MIFARE DESFire, MIFARE PLUS, MIFARE FLEX, MANTIS, MIFARE ULTRALIGHT, MIFARE4MOBILE, MIGLO, NTAG, ROADLINK, SMARTLX, SMARTMX, STARPLUG, TOPFET, TRENCHMOS, UCODE, AltiVec, CodeWarrior, ColdFire, ColdFire+, the Energy Efficient Solutions logo, Kinetis, Layerscape, MagniV, PEG, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, SafeAssure, the SafeAssure logo, StarCore, Symphony, VortiQa, Vybrid, Airfast, BeeKit, BeeStack, CoreNet, Flexis, MXC, Platform in a Package, QUICC Engine, Tower, TurboLink, EdgeScale, EdgeLock, eIQ, and Immersive3D are trademarks of NXP B.V. All other product or service names are the property of their respective owners.  AMBA, Arm, Arm7, Arm7TDMI, Arm9, Arm11, Artisan, big.LITTLE, Cordio, CoreLink, CoreSight, Cortex, DesignStart, DynamIQ, Jazelle, Keil, Mali, Mbed, Mbed Enabled, NEON, POP, RealView, SecurCore, Socrates, Thumb, TrustZone, ULINK, ULINK2, ULINK-ME, ULINK-PLUS, ULINKpro, µVision, Versatile are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved. Oracle and Java are registered trademarks of Oracle and/or its affiliates. Synopsys and Designware are registered trademarks of Synopsys, Inc. Portions © 2017, 2019 Synopsys, Inc. Used with permission. All rights reserved.

All rights reserved.

For more information, please visit: http://www.nxp.com For sales office addresses, please send an email to: salesaddresses@nxp.com

Date of release: 10/2021

Document identifier: S32G3PB