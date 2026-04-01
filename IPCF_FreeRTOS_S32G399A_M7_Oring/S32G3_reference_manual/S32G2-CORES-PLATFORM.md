## S32G2 CORES AND PLATFORM

APRIL  2 0 2 1

<!-- image -->

<!-- image -->

## CORES AND PLATFORMS

- Common Chassis
- Block Diagram Overview
- Cores
- incl. IPC
- incl. Hypervisor
- Platform Overview
- Coherency
- FlexNoC
- Memory Map
- Clocking Overview
- Reset Overview

<!-- image -->

## S32G2

<!-- image -->

PUBLIC

2

## S32G2 BLOCK DIAGRAM

<!-- image -->

<!-- image -->

## S32G2 BLOCK DIAGRAM

<!-- image -->

<!-- image -->

Arm, Cortex are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved.

## S32 Platform

<!-- image -->

PUBLIC

5

## AUTO PROCESSORS TOMORROW - NXP'S UNIQUE S32 PLATFORM

<!-- image -->

The World's First Fully Scalable Safe Auto Compute Platform

## Reduces SW R&amp;D 1 by 35%

Unified HW with identical SW environment

## 10x the Performance 2

Multiple real time OS ADAS AI accelerators

## Safe and Secure

4 independent ASIL D paths HW security engine Ready for OTA

<!-- image -->

## NXP INTRODUCED THE S32 FAMILY OF PROCESSORS

<!-- image -->

## Performance

Optimized for functional domains

Real-time and high-performance

Scalable

<!-- image -->

## Safe

ASIL D Functional Safety

Process certified to ISO 26262:2018

<!-- image -->

## Secure

Powerful hardware security engine (HSE)

Firmwareupgradable public key encryption

## OTA Updates

OTA updates while driving

Fault recovery rollbacks

## Processors

Arm ® cores across portfolio

Arm Cortex ®  -A, -R, and -M cores

<!-- image -->

The World's First Fully Scalable Safe Auto Compute Platform

<!-- image -->

## SW Reuse

Maximizes software re-use within and across application domains

Cost savings for customers

<!-- image -->

## Block Diagram Overview

<!-- image -->

PUBLIC

8

## S32G274A BLOCK DIAGRAM

<!-- image -->

<!-- image -->

Arm, Cortex are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved.

Off-chassis to DRAM 1

RDC\_MRC

DRAM 1

DRAM 1

## S32G274A CPUS

<!-- image -->

To LLCE

Sys/6 Clk

<!-- image -->

xRDC\_MRC

DRAM0

xRDC\_MRC

xRDC\_MRC

xRDC\_MRC

xRDC\_MRC

xRDC\_MRC

53/M7 Common

## S32G274A SECURITY AND DMA

Chassis

Clock Domains tex-M7

layed Lockstep Cluster 0

Debug

CPU

CPU

SP FPU

MPU

FPU

NVIC

XIM

I-M

Delay

Comp

Delay

AXIM

AXI-S

Delay

<!-- image -->

C

P

ull

\_MRC

L

OCP2IPS\_0

OCP2IPS\_1

OCP2IPS\_2

OCP2IPS\_3

<!-- image -->

PCIe, PPFE, USB-to-SRAM

PCIe, PPFE, USB-to-DRAM

lave)

PCIe, PPFE, USB-to-on\_chassis slaves

Sys/4 Clk

128

64

## S32G274A MEMORIES

64

Legend

Cluster 0

Core 0

Debug

Debug

Core 1

Cortex-A53

NEON / FPU

Cortex-A53

NEON / FPU

Core clk

0

1

Cluster 1

Core 2

Debug

Debug

Core 3

Cortex-A53

NEON / FPU

Cortex-A53

NEON / FPU

lockstep

Debug

CPU

CPU

SP FPU

MPU

32K

I-cache

ECC/EDC

32K

D-cache

ECC/EDC

64K

D-TCM

FPU

Debug

CPU

CPU

SP FPU

MPU

AXIM

AXI-S

Delay

Comp

Delay xRDC\_MRC

xRDC

OCP

POST

MTR

STAM

TST\_CLK\_MU

2x CGM

PERIPH\_PLL

FPU

<!-- image -->

SIRC

<!-- image -->

CORE\_DFS

32K

I-cach

ECC/ED

32K

D-cach

ECC/ED

64K

D-TCM

ECC

Periph

Bus

AXI

Delay

Off-chassis t

Off-chassis t

MRC

SRAM CTRL

SRAM CTRL

SRAM CTRL

640K SRAM

PCIe, PPFE, USB-to-SRAM

PCIe, PPFE, USB-to-DRAM

PCIe, PPFE, USB-to-on\_chassis slaves

640K SRAM

640K SRAM

bable IP

le option implemented

B-Lite Slave)

le option removed ation register interface

OTC

MAP

DRAM Clk

OTC

MAP

128

128

## Sys/4 Clk S32G2 PERIPHERALS (CC) Safe\_Full

ASIL-D Main FlexNoC

64

xRDC\_MRC

xRDC\_MRC

xRDC\_MRC

DRAM0 M7/eDMA to DRAM 1 A53/Concerto to DRAM 1 Connection to LLCE

xRDC\_MRC

<!-- image -->

128

64

128

64

C

OTC

MAP

OTC

MAP

xRDC\_MRC

Core 0

Delay

OTC

MAP

Delay

Cluster 0

Debug

Core 1

Debug

Comp

Comp

Core clk

Core 2

OTC

MAP

0

1

Cluster 1

Debug

Core 3

Debug

CPU

xRDC\_MRC

<!-- image -->

Legend

Non-stubbable IP

OTC

MAP

lockstep

OTC

MAP

Cortex-M7

Delayed Lockstep Cluster 0

Debug

32K

I-cache

ECC/EDC

32K

D-cache

ECC/EDC

64K

D-TCM

ECC

Periph

Bus

AXIF

Delay

Comp

CPU

CPU

SP FPU

MPU

FPU

NVIC

AXIM

AXI-M

Delay

Comp

AXI-S

AXIM

Delay

Comp

Cortex-M7

Delayed Lockstep Cluster 1

Debug

32K

I-cache

ECC/EDC

32K

D-cache

ECC/EDC

64K

D-TCM

ECC

Periph

Bus

AXIF

Delay

Comp

Delay

Delay

Delay

Delay

## Clock, Power, Reset Control

## Interfaces:

OTC

MAP

5x I2C (incl. PMIC ctrl)

4x LINFlex (LIN, UART)

4x FlexCAN

6x DSPI

2x PIT

1x CRC

7x SWT

7x STM

xRDC\_PDAC xRDC\_MRC 2x 6-channel FlexTimer 2x 6-channel SAR ADC

OCP2IPS\_0

POST

STCU

MTR

STAM

TST\_CLK\_MUX

2x CGM

PERIPH\_PLL

SIRC

CORE\_DFS

ATX

TMU

2x ADC BIST

CORE\_PLL

Aurora\_PLL

XOSC

PERIPH\_DFS

<!-- image -->

CPU

AXI-S

AXIM

Delay

Comp

Delay xRDC\_MRC

Corte

Delay

C

F

N

AXI

AXI-M

Delay

OTC

MAP

## S32G2 COMMUNICATION INTERFACES

DRAM Clk

<!-- image -->

STM

ERM

Debug ETR

xRDC\_MRC

128

128

64

64

From off\_chassis

To off\_chassis

From LLCE

xRDC\_MRC

Off-chassis to DRAM 1

xRDC\_MRC

General access to DRAM 1

M7/eDMA to DRAM 1

A53/Concerto to DRAM 1

128

64

128

<!-- image -->

xR

## DATA FLOWS: CAN GW

<!-- image -->

<!-- image -->

## DATA FLOWS: ETHERNET FAST PATH (L3 FORWARDING)

<!-- image -->

<!-- image -->

## DATA FLOWS: ETHERNET SLOW PATH

<!-- image -->

<!-- image -->

## DATA FLOWS: BOOT

<!-- image -->

<!-- image -->

## DATA FLOWS: SECURITY OFFLOAD

<!-- image -->

<!-- image -->

## Cores

<!-- image -->

PUBLIC

2 0

## ARM INSTRUCTION SET COMPATIBILITY

## Newer Cortex-A processors are all ARMv8-A 64/32 bit

- They can still run traditional 32-bit as well as the newer 64-bit
- They are generally a superset of R and M profiles of ISA
- This includes extended SIMD/vector and Floating-point extensions

## Upcoming Cortex-R and Cortex-M are all ARMv8-R and ARMv8-M

- This includes FPU, some SIMD, and saturating math

<!-- image -->

Base of all ARM processors is the ARM/Thumb2 ISA Gives common behavior and optimization options

## ISAs are not Binary Compatible Interrupt Handling different Normal C/C++ compiles cleanly on any of the processors

- Allowing reuse of algorithms and testing
- Some C optimization for one processor may give less optimal behavior
- ARM and NXP provided Libraries are individually optimized for each, allowing reuse without compromise
- Compilers have sub-architecture specific instruction sequence selection that optimize use of a processor and its pipeline, bus. e.g., can recognize SIMD, can order instructions for super-scalar, can pipeline FPU uses
- Only use of special 'Intrinsics' would cause problems, and may not map across different cores

<!-- image -->

ore/2 Clk

## ARM ® CORTEX ® M7 CPUS

Core 0

32KB

I cache

ECC /

L-D SRAM FlexNoC

\_MRC

SRAM CTRL

SRAM CTRL

40K SRAM

40K SRAM

SRAM CTRL

40K SRAM

<!-- image -->

POST

STCU

4x SWT

HSE

OTC

- Specs:
- Freq: 400 MHz
- -32-bit core
- ARMv7E-M architecture
- -Pipeline: 6-stage dual-issue + branch prediction
- Code space: SRAM
- Data space: SRAM / TCM
- 32 KB/32KB L1 I-Cache &amp; D-Cache (w/ECC)
- 64 KB D-TCM (w/ECC) To LLCE Delayed Delayed LLCE
- -16 entry Memory Protection Unit (MPU) Lock-step pair Lock-step pair
- Interrupt Controller: NVIC 2x DMAChMux 32 ch eDMA 32 ch eDMA 2x DMAChMux 32 ch eDMA 32 ch eDMA
- -256 Hardware Vectors DMA CRC DMA CRC

OTC

OTC

MAP

- Interfaces (32-bit address): MAP MAP
- -64-bit AXI-M: To RAM (code/data) &amp; Systems (data)

xRDC\_MRC

- -32-bit AHB-M: To Peripherals
- -64-bit AXI-S: Backdoor to TCM Sys/6 Clk

More Info in ARM Docs: 'DDI0489D\_cortex\_m7\_trm' xRDC\_PDAC xRDC\_PDAC

OCP2IPS\_2

4x SWT

OCP2IPS\_3

RCCU

<!-- image -->

## CORTEX-M7 INTERFACES

<!-- image -->

<!-- image -->

## CORTEX-M7 MEMORY PROTECTION UNIT (MPU)

- Each Cortex-M7 has an MPU
- 16 regions
- Each region can have 8 sub-regions (if &gt;=256-byte)
- Sub-regions are equal size
- Min. region size 32-bytes
- Priority: Region 15 highest, 0 lowest
- Overlapping regions allowed
- Separation of Privileged / Unprivileged accesses
- MPU regions determine M7 L1-Cache usage
- i.e., cacheable / non-cacheable regions
- MPU provides protection against M7 access only
- XRDC provides wider system access control
- Across all system bus masters
- Reference ARM docs: 'DDI0403E\_B\_armv7m\_arm'

<!-- image -->

<!-- image -->

## CORTEX-M7 COHERENCY

<!-- image -->

- M7 does not support coherency hardware
- -If using shared memory space with any other masters, need to be aware.
- Options for coherent shared regions:
- -Disable cache (e.g., peripherals)
- -Enable cache and manage in SW
- -Enable cache in write-through mode ▪ If M7/DMA

<!-- image -->

## CORTEX-M7 NESTED VECTORED INTERRUPT CONTROLLER (NVIC)

- Each M7 has an NVIC
- Handles interrupts for the CPU
- NVIC supports 256 HW Vectors
- Exception [1:15] - ARM std exceptions
- Exception [16:256] - S32G specific
- Known as IRQ[0:239]
- See IRQ Map sheet in S32G2 Ref Manual
- Priorities
- Exception[1:3] have fixed priority
- All other are SW defined ('0' by default)
- Sub-priorities supported
- MSCM handles system wide interrupt routing

## NVIC Exception [0:15] - ARM standard

PRI: -3

PRI: -2

PRI: -1

| PRI:   |
|--------|
| PRI:   |
| PRI:   |

## NVIC Exception [16:256] - S32G2 Specific

| VectorOffset Address   |   Cortex-M7 Exception Number |   NVICInterrupt ID | Instance   |
|------------------------|------------------------------|--------------------|------------|
| 40                     |                           16 |                  0 | MSCM       |
| 44                     |                           17 |                  1 | MSCM       |
| 48                     |                           18 |                  2 | MSCM       |
| 4C                     |                           19 |                  3 | MSCM       |
| 50                     |                           20 |                  4 | MSCM       |
| 54                     |                           21 |                  5 | MSCM       |
| 58                     |                           22 |                  6 | MSCM       |
| 5C                     |                           23 |                  7 | MCM        |
| 60                     |                           24 |                  8 | eDMA_0     |
| 64                     |                           25 |                  9 | eDMA_0     |
| 68                     |                           26 |                 10 | eDMA_0     |
| 6C                     |                           27 |                 11 | eDMA_1     |
| 70                     |                           28 |                 12 | eDMA_1     |
| 74                     |                           29 |                 13 | eDMA_1     |
| 78                     |                           30 |                 14 | SWT_0      |
| 7C                     |                           31 |                 15 | SWT_1      |
| 80                     |                           32 |                 16 | SWT_2      |
| 84                     |                           33 |                 17 | SWT_3      |
| 88                     |                           34 |                 18 | SWT_4      |
| 8C                     |                           35 |                 19 | SWT_5      |
| 90                     |                           36 |                 20 | SWT_6      |
| 94                     |                           37 |                 21 | SWT_7      |
| 98                     |                           38 |                 22 | Reserved   |
| 9C                     |                           39 |                 23 | Reserved   |
| AO                     |                           40 |                 24 | STM_0      |

<!-- image -->

## M7 EXAMPLE WORKLOADS

<!-- image -->

e.g., (M7\_0)

<!-- image -->

## Single Task - CAN Gateway / IDS

- -Repetitive code flow
- (e.g., CAN frame RX -&gt; process -&gt; TX)
- I-Cache friendly
- -Many data accesses
- Poor D-Cache efficiency
- -Big Data structures
- Suitable for D-TCM

## *Example tasks:

(e.g., Diagnostics, OTA, ECU Config, Security strategy, Network time master, Top Level vehicle strategy (energy), Body overspill, ECU enrolment, etc…)

- For a Gateway Application
- M7 typically run CAN Gateway
- May have many smaller tasks/apps, covering range of functions
- Workloads generally split into 2 groups
- Single Task
- Many Task
- Other applications (e.g., Domain Controller) have to consider any generalised use of M7
- i.e., not 'fixed function' CPU

<!-- image -->

## ARM ® CORTEX ® A53 CPUS

Off-chassis to DRAM 1

xRDC\_MRC

General access to DRAM 1

M7/eDMA to DRAM 1

*32-bit boot not supported

<!-- image -->

A53/Concerto to DRAM 1

## · Specs:

- -Freq: 1 GHz

## A53/M7 Common Chassis Clock Domains

- -64-bit core (32-bit supported*)
- -ARMv8-A architecture
- -Pipeline: 8-stage dual issue + branch prediction
- -Code &amp; Data space: DRAM / SRAM

Cortex-M7

Cortex-M7

- -32 KB/32 KB L1 I-Cache and D-Cache (w/ECC) per A53 Delayed Lockstep Cluster 1 Delayed Lockstep Cluster 2

Debug

- -512KB L2 (w/ECC) per Cluster 32K I-cache Debug 32K I-cache
- -Memory Management Unit (MMU) 32K ECC/EDC 32K ECC/EDC
- -NEON (SIMD), Instructions to accel crypto operations  (AES / SHA) D-cache ECC/EDC CPU D-cache ECC/EDC

CPU

CPU

SP FPU

MPU

FPU

NVIC

ECC

ECC

NVIC

AXIM

CPU

- -Trustzone (secure state) and VM hardware extensions (hypervisor state) To LLCE 64K D-TCM 64K D-TCM SP FPU MPU FPU

## · Cache Coherency: AXIF Periph Bus AXIM AXI-M AXIM AXI-S AXI-M

AXIF

Periph

Bus

AXIM

AXI-S

Delay

- -Snoop control until (SCU) per cluster

Comp

Delay

- -NCORE handles coherency outside cluster Delay Delay Delay Delay Delay
- -Cache coherency for L1/L2 cache within cluster HSE Delay Comp Delay Comp Delay Comp Delay Comp Delay Comp

Delayed

Lock-step pair

32 ch eDMA

2x DMAChMux

32 ch eDMA

DMA CRC

- Interrupt Controller: GIC500

OTC

- -Implementing 256 Hardware Vectors (common to NVIC) OTC OTC OTC

MAP

Delayed

Lock-step pair

32 ch eDMA

2x DMAChMux

32 ch eDMA

DMA CRC

OTC

- -Virtual Interrupt Vector support (e.g., PCI Root Complex, VM IRQs) MAP MAP MAP MAP
- Interfaces (per cluster, 40-bit address):
- -128-bit AXI-M: All accesses, 500 MHz (A53 Freq/2) xRDC\_MRC xRDC\_MRC

More Info in ARM Docs: 'DDI0500G\_cortex\_a53\_trm'

ASIL-B Peripheral FlexNoC

xRDC\_MRC

xRDC\_PDAC

xRDC\_PDAC

OCP2IPS\_1

xRDC\_PDAC

OCP2IPS\_2

xRDC\_PDAC

Sys/6 Clk

LLCE

<!-- image -->

## CORTEX-A53 INTERFACES

<!-- image -->

<!-- image -->

## CORTEX-A53 MEMORY PROTECTION

<!-- image -->

- Isolation within A53 compute
- MMU HW isolation
- Hypervisor managing MMUs
- A53 supports virtualisation extensions in HW
- Dedicated EL2 state
- Allows Hypervisor MMU / Guest OS MMU
- Simplifies Guest OS Application
- System wide protection using XRDC
- Granularity of A53 ID
- No support for Virtualisation
- Recommend:
- XRDC: Crude isolation of A53 / M7
- MMU: Fine grain isolation of A53 applications (w/ Hypervisor)

<!-- image -->

## CORTEX-A53 VIRTUALISATION

- ARMv8-A Architecture, Cortex-A53 CPU
- -Virtualisation Extensions (ARM standard)
- -Dedicated privilege level for hypervisor (EL2)
- Control over register/memory accesses from EL0/1
- Manage IRQs for Guests
- -Supporting bare metal (Type-1) and hosted (Type-2) hypervisors
- -Interrupt controller (GIC500) is virtualisation aware
- Industry wide support / ecosystem for ARMv8-A virtualisation architecture

## · System / IO MMU (IOMMU) not supported

- -Re-translation required between guest and system master (e.g., DMA) in hypervisor
- -Reduced flexibility on protecting guest accesses to memory / peripheral resources

<!-- image -->

+ AArch64permitted only if EL1is usingAArch64 +AArch64permitted only if EL2is usingAArch64

<!-- image -->

## CORTEX-A53 COHERENCY

<!-- image -->

<!-- image -->

(2GB)

## CORTEX-A53 GIC-500

<!-- image -->

| …  Cortex-A53  GICInterruptID (O-  Name  Vector  480)  Instance  Cortex A53 Cluster AXI  16-31  0-15  CortexA53  CortexA53 ClusterAXI  32  16  Cortex A53  Reserved  EE  17  CortexA53  Reserved  34  18  Cortex A53  Reserved  35  19  CortexA53  Reserved  36  20  Cortex A53  Reserved  37  21  CortexA53  CortexA53 COMM  38  22  CortexA53  Cortex A53 PMU  39  23  CortexA53  Cortex A53 CTI  40  24  Cortex A53  Cortex A53 Maintenance IRQ  41  25  CortexA53  Cortex A53 HYP timer  42  26  Cortex A53  CortexA53Virtualtimer  43  27  Cortex A53  CortexA53-onlyEL2virtualtimer  44  28  CortexA53  CortexA53-onlyEL3timer  45  29  CortexA53  Cortex A53 EL1 Timer  46  30  Cortex A53  Reserved  47  31  CortexA53  Pcie\_1 MSl interrupt to M7/A53  48  32  MSCM  CPU toM7/A53interrupt#0  49  EE  MSCM  CPU to M7/A53interrupt#1  50  34  MSCM  CPUtoM7/A53interrupt#2  51  35  MSCM  Pcie\_0 MSlinterrupt to M7/A53  52  36  MSCM  M7 CTlinterrupt  53  37  MSCM  M7 CTlinterrupt  54  38  MSCM  Directed Cortex-M7(=MCM)  55  39  MCM  56  40  eDMA\_0  57  41  eDMA\_0  58  42  eDMA\_0   |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

PPI

SPI

- GICv3 interrupt controller is tightly integrated in the A53 architecture
- 1 lock-step pair of GICs
- Software configuration of interrupt distribution to the cores within a cluster
- Interrupt types:
- -SGI: 16 * Software Generated Interrupts
- Triggered by writing to a register within the interrupt controller
- -PPI: 16 * Private Peripheral Interrupts
- Peripheral interrupt private to an individual core
- -SPI: 32-960 * Shared Peripheral Interrupts
- Interrupts available to all cores
- S32G274 supports up to 255 SPIs
- -LPI: Up to 57K * Locality Specific Peripheral Interrupts
- Message based interrupts (e.g., PCIE Root Complex)
- 32 priority values
- Interrupt Translation Service (ITS)
- -Can map message based IRQs directly into a Guest VM (i.e., Hypervisor assigns guest OS ownership of IRQ - avoids need for Hypervisor to process)
- -Uses LPIs to translate IRQ to guest OS

<!-- image -->

## CORTEX-A53 GIC-500 ROUTING AFFINITY

<!-- image -->

- Routing affinity used to assign IRQs to specific A53 CPUs
- E.g., 0.0.1.0 - Cluster1, CPU0
- 'Linear' represents order of CPUs

<!-- image -->

## A53 WORKLOADS

- Wide variation of use cases and workloads
- Workloads:
- -Math based (e.g., analytics application)
- Compute heavy, utilise NEON, cache friendly
- -Traffic based (e.g., networking application - GW, firewall, IDPS, forensics)
- Repetitive flow, up/down stacks, many lookup operations (many data accesses)
- Frequent use of security services
- -Hypervisor (managing multiple VMs)
- Trapping exceptions and context switching
- -General Purpose → customer will dream many interesting future workloads!

<!-- image -->

## I N T E R - P L AT F O R M   C O M M U N I C AT I O N   F R A M E W O R K   ( I P C F )

- NXP IPC SW available for inter-core communication
- e.g., A53 to M7
- Supports Multicore &amp; Multichip
- Socket based connection
- connectionless or connection-orientated

<!-- image -->

<!-- image -->

<!-- image -->

## Platform Overview

<!-- image -->

PUBLIC

3 9

Sys/2 Clk

DRAM Clk

Sys/4 Clk

STAM

## SYSTEM COHERENCY: NCORE

<!-- image -->

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

40K SRAM

128

64

128

xRDC\_MRC

- System Cache Coherency A53/M7 Common
- -Access to memory through selected masters (left) can be directed via NCore Chassis Clock Domains
- -This monitors addresses and compares to tag status of A53 Cluster L2 Cortex-M7 Delayed Lockstep Cluster 0 Cortex-M7 Delayed Lockstep Cluster 1 Cortex-M7 Delayed Lockstep Cluster 2

32K

Debug

Debug

32K

Debug

- -Ensures that A53 caches (L2) are coherent across clusters and specific system masters CPU CPU 32K D-cache I-cache ECC/EDC CPU CPU 32K D-cache I-cache ECC/EDC CPU CPU 32K D-cache I-cache ECC/EDC

MPU

32K

- e.g., Cluser0 L2 is coherent with Cluster1 L2 64K D-TCM SP FPU MPU FPU ECC/EDC 64K D-TCM SP FPU MPU FPU ECC/EDC 64K SP FPU FPU ECC/EDC

D-TCM

ECC

Periph

Bus

AXI-S

AXIF

Delayed

Lock-step pair

To LLCE

Delayed

Lock-step pair

- e.g., Networking buffer space in DDR AXIF Periph ECC NVIC AXIM AXI-S AXIF Periph AXIM AXI-M ECC NVIC AXIM AXI-S AXIM NVIC AXIM

AXI-M

Bus

AXIM

Delay

Delay

Comp

Delay

Comp

- Example: Delay Comp Delay Comp

Bus

AXI-M

Delay

Comp

Comp

Delay

Delay

Comp

Comp

Delay

Comp

- -New Ethernet frame for A53 Host arrives into PFE and is written to buffer descriptor (BD) in DDR. DMA CRC Delay Delay Delay Delay Delay Delay Delay Delay Delay

OTC

MAP

32 ch eDMA

32 ch eDMA

2x DMAChMux

DMA CRC

- A53 may have cached BD space (to improve network stack processing), with previous frame in its L2 cache. OTC MAP OTC MAP OTC MAP OTC MAP

OTC

MAP

- NCore will detect write by PFE and tag specific L2 cache line as dirty, forcing a fetch to DDR when A53 accesses BD.

Safe\_Full xRDC\_MRC

- Why?
- -Avoid working on stale/old datasets

ASIL-B Peripheral FlexNoC

- -Coherency h/w simplifies programming model vs SW approach OCP2IPS\_2 OCP2IPS\_1 OCP2IPS\_0 xRDC\_PDAC xRDC\_PDAC xRDC\_PDAC xRDC\_MRC

SeqQueL

uadSPI /

OTFAD

32 ch eDMA

32 ch eDMA

2x DMAChMux xRDC\_MRC

POST

MTR

STAM

STCU

ATX

TMU

4x SWT

4x STM

2x DMAMUX

HSE

xRDC\_MRC

4x SWT

4x STM

2x DMAMUX

xRDC\_PDAC

OCP2IPS\_3

RCCU

<!-- image -->

8x ERM

Sys/6 Clk

## FLEXNOC - SWITCH FABRIC

<!-- image -->

<!-- image -->

## WHAT IS A NETWORK ON CHIP (NOC)

<!-- image -->

## Bus Masters (128-bit)

<!-- image -->

Bus Slaves (128-bit)

## FlexNOC (e.g., S32G2)

'Packetize' access in NIU

(e.g., 1x 128-bit = 4x32-bit)

- Trade of latency

Reduce routing paths inside NoC Add duplication on paths (safety resilience) QoS (BW control, traffic urgency)

- AXBS fine for lower complexity processors
- -As scale, wiring o/h and routing complexity is costly (die/latency)
- e.g., 20+ master, 128-bit d-width, mixed freq, etc…
- NoC Architecture suited for high complexity/performance MPU
- -Optimise individual paths for bandwidth or latency
- trade-off wiring and latency
- -Not all paths are connected (reducing wiring)
- -Protocol and frequency translation at port (NIU)
- FlexNOC is vendor specific implementation of a NoC architecture
- -Resilience package supported for ASIL-D
- -QoS features for optimising bandwidth for application

<!-- image -->

## MEMORY MAP

- See excel memory map file (attached to S32G2 Reference Manual)
- Common memory map between all systems resources*

<!-- image -->

<!-- image -->

## MEMORY MAP - 40-BIT MASTERS

- Master which support 40-bit addressing: PCIE0, PCIE1, HSE *, Cortex-A53
- Extended PCIE window, 4GB DDR support
- Other masters can access 32-bit address space only

## &gt;4GB address space:

| ExtendedAddressMap   | ExtendedAddressMap   | Size(GB)   |
|----------------------|----------------------|------------|
| 0x01_0000_0000       | 0x07_FFFF_FFFF       | 28         |
| 0x08_0000_0000       | 0x08_3FFF_FFFF       |            |
| 0x08_4000_0000       | 0x08_7FFF_FFFF       |            |
| 0x08_8000_0000       | 0X08_FFFF_FFFF       | 2          |
| 0x09_0000_0000       | 0XOF_FFFF_FFFF       | 28         |
| 0x10_0000_0000       | 0X3F_FFFF_FFFF       | 192        |
| 0x40_0000_0000       | 0x47_FFFF_FFFF       | 32         |
| 0x48_0000_0000       | 0X4F_FFFF_FFFF       | 32         |
| 0x50_0000_0000       | 0x7F_FFFF_FFFF       | 192        |
| 0x80_0000_0000       | 0x80_3FFF_FFFF       | 1          |
| 0x80_4000_0000       | 0x80_FFFF_FFFF       | 3          |
| 0x81_0000_0000       | 0X87_FFFF_FFFF       | 28         |
| 0x88_0000_0000       | 0X8F_FFFF_FFFF       | 32         |
| 0x90_0000_0000       | 0XFF_FFFF_FFFF       | 448        |

<!-- image -->

<!-- image -->

<!-- image -->

## I N T E R R U P T   R O U T I N G

- Each M7 has a dedicated NVIC
- Fast ISR entry and exit capabilities
- Accessed via Private Peripheral Bus (PPB)
- A53s share a GIC-500
- Implemented in lockstep to meet ASIL-D
- Platform interrupt router:
- Used to multiplex interrupts to GIC and NVICs
- All interrupts routed to Cortex M7 cores
- All interrupts routed to Cortex A53 cores
- Support core-to-core interrupts

<!-- image -->

<!-- image -->

## I N T E R R U P T   R O U T I N G   - EXAMPLE

<!-- image -->

| Vector Offset Address   |   Cortex-M7 Exception Number |   NVIC Interrupt ID |   Cortex- A53/R52 Vector | GIC InterruptID (0-480)   | Module   | Instance   | Interrupt Type (Level sensitive unless specified otherwise)   |
|-------------------------|------------------------------|---------------------|--------------------------|---------------------------|----------|------------|---------------------------------------------------------------|
| 60                      |                           24 |                   8 |                       56 | 40                        | eDMA     | eDMAO      | Interrupt for DMA Channels 0-15                               |
| 64                      |                           25 |                   6 |                       57 |                           | eDMA     | eDMAO      | Interrupt for DMA Channels 16-31                              |
| 68                      |                           26 |                  10 |                       58 | 42                        | eDMA     | eDMAO      | Interrupt for DMA Channels 0-31                               |
| 6C                      |                           27 |                  11 |                       59 | 43                        | eDMA     | eDMA1      | Interrupt for DMA Channels 0-15                               |
| 70                      |                           28 |                  12 |                       09 | 44                        | eDMA     | eDMA1      | Interrupt for DMA Channels 16-31                              |
| 74                      |                           29 |                  13 |                       61 | 45                        | eDMA     | eDMA1      | Interrupt for DMA Channels 0-31                               |
| 78                      |                           30 |                  14 |                       62 | 46                        | swt_ips  | SWTO       | Interrupt Request                                             |
| 7C                      |                           31 |                  15 |                       63 | 47                        | swt_ips  | SWT1       | Interrupt Request                                             |
| 80                      |                           32 |                  16 |                       64 | 48                        | swt_ips  | SWT2       | Interrupt Request                                             |

## Configure MSCM Routing Control Register:

- By default, interrupt will be disabled
- Decide if interrupt is routed to M7\_0/M7\_1/M7\_2/GIC
- Can route to multiple cores

Configure this entry in the NVIC / GIC table

- Table contains a pointer to the ISR

<!-- image -->

## MSCM INTERRUPT HANDLING

<!-- image -->

## Shared Peripheral Interrupt (SPI) Routing:

- SPIs can be routed to the GIC or NVIC for a specific M7/A53 CPU
- One register per SPI - IRSPRC0-532
- LOCK bit only cleared by Reset

<!-- image -->

## Message Signalled Interrupt (MSI) Routing:

- M7 NVIC has no support for MSI - MSCM provides solution.
- GIC-500 supports directly
- MSIs are interrupts the are indirectly broadcast to a target core by writing configuration bits in the MSCM.
- MSIs can either be initiated by:
- One core targeting another core in the system-these are known as core-to-core interrupts
- PCIe targeting a core in the system, these are known as PCIeto-core interrupts.
- MSIs are initiated via the writes to the IRCP n IGR x and managed thru the IRCP n ISR x registers, where n indicates the logical core number (0-3) and x represents the interrupt number (0-3).

<!-- image -->

MSCM: PCIE-TO-M7 INTERRUPT GENERATION

- MSCM has been updated to include support for M7 Message Based Interrupts

<!-- image -->

<!-- image -->

## DMA

- 2 lockstep DMA pairs
- 1 register interface per lockstep pair
- Each DMA is 32-channel
- Two 64 → 16 Channel Mux per lock step pair
- ON-Chassis muxing is common across all CC products
- OFF-Chassis muxing specific to individual product families

<!-- image -->

<!-- image -->

## DMA LOCKSTEP IMPLEMENTATION

## DMA Lockstep

<!-- image -->

<!-- image -->

## S32G274A DMA MUX

On-CC sources {1:35}

Off-CC sources {36:63}

## DMAMUX\_0/2

| Device                                                           | Instance          |                |
|------------------------------------------------------------------|-------------------|----------------|
| Slot_Num DMA_Request @ Description DMArequest                    | CAN_FD_0          |                |
| DMA request                                                      | CAN_FD_1          |                |
| 3 Internal DMA TX request0                                       | LinFlexD_0        |                |
| Internal DMA RX request0                                         | LinFlexD_0        |                |
| Internal DMA TX request0                                         | LinFlexD_1        |                |
| 6 Internsl DMA RX request0                                       | LinFlexD_1        |                |
| TXFIFOFull                                                       | DSP_0             |                |
| 8 RXFIFO Drsin                                                   | DSPI_0            |                |
| 9 CMD FIFO Full                                                  | DSP_0             |                |
| 10 TX FIFO Full                                                  | DSPL_1            |                |
| 11 RX FIFO Drsin                                                 | DSPI_1            |                |
| 12 CMD FIFO Full                                                 | DSPL_1            |                |
| 13 TX FIFO Full                                                  | DSPI_2            |                |
| 14 RX FIFO Drain                                                 | DSP_2             |                |
| 15 CMD FIFO Full                                                 | DSP_2             |                |
| 16 RXDMA req                                                     | I2C_0             |                |
| 17 TXDMA req                                                     | I2C_0             |                |
| 18 RXDMAreq                                                      | I2C_1             |                |
| 19 TXDMA req                                                     | I2C_1             |                |
| 20 FIFO0 watermark DMA Request                                   | CTU               |                |
| 21 FIFO1 wstermark DMA Request                                   | CTU               |                |
| 22 FIFO2 watermark DMA Request                                   | CTU               |                |
| 23 FIFO3 Wstermark DMA Request                                   | CTU               |                |
| 24 Command Request on Master Reload Signal                       |                   |                |
| 25 DMA request 0                                                 | CTU SIUL_0        |                |
| 26 DMA request 1                                                 |                   |                |
|                                                                  | SIUL_0            |                |
| 27 DMA request 4 28 DMA request 5                                | SIUL_0 SIUL_0     |                |
| 29 DMA request 8 30 DMA request 9                                | SIUL_0            |                |
| 31                                                               | SIUL_0            |                |
|                                                                  | RESERVED          |                |
| 32 DMA request after channel conversion completiS                | RESERVED          |                |
| 33                                                               | SARADC_0          |                |
| 34                                                               | RESERVED          |                |
| 35 36                                                            | RESERVED RESERVED |                |
| 37                                                               |                   |                |
| 38                                                               | RESERVED          |                |
| 39                                                               | RESERVED          |                |
| 40 41                                                            | RESERVED          |                |
|                                                                  | RESERVED          |                |
| 42                                                               | RESERVED          |                |
| 43                                                               | RESERVED          |                |
| 44 45                                                            | RESERVED          |                |
|                                                                  | RESERVED RESERVED |                |
| 46                                                               |                   |                |
| 47 DMA request 0                                                 | SIUL_1            |                |
| 48 DMA request 1                                                 |                   |                |
| 43 DMA request 4                                                 | SIUL_1            |                |
| 50 DMA request 5                                                 | SIUL_1            |                |
| 51                                                               | RESERVED          |                |
| 52 Channel O DMA transfer request 53                             | FTM_0             |                |
| Channel 1 DMA transfer request 54                                | FTM_0             |                |
| Channel 2 DMA transfer request 55 Channel 3 DMA transfer request | FTM_0 FTM_0       |                |
| 56 Channel 4 DMA transfer request                                | FTM_0             |                |
| 57 Channel 5 DMA transfer request                                | FTM_0             |                |
| 58 Channel 6 DMA transfer request                                | FTM_0             |                |
| 59 Channel 7 DMA transfer request                                | FTM_0             |                |
| 60                                                               | Always Ensbled    |                |
| 61                                                               |                   |                |
| 62                                                               | Always Ensbled    |                |
| 63                                                               | Always Ensbled    |                |
|                                                                  | Always Ensbled    | Always Ensbled |
|                                                                  | RESERVED          | RESERVED       |
|                                                                  | SIUL_1            | SIUL_1         |

## DMAMUX\_1/3

| Device                                                              |                                              |                                             |
|---------------------------------------------------------------------|----------------------------------------------|---------------------------------------------|
| Slot_Num DMA_Request @ Description                                  | Instance                                     |                                             |
| DMA request                                                         | CAN_FD_2                                     |                                             |
| 2 DMArequest                                                        | CAN_FD_3                                     |                                             |
| 3 Internol DMATX request0                                           | LinFlexD_2                                   |                                             |
| 4 Internal DMA RX request0                                          | LinFlexD_2                                   |                                             |
| TX Buffer Fill DMA Request                                          | QuadSPI                                      |                                             |
| 6 RX Buffer Drsin DMA Request                                       | QuadSPI                                      |                                             |
| 7 TXFIFO Full                                                       | DSPI_3                                       |                                             |
| 8 RX FIFO Drain                                                     | DSPL_3                                       |                                             |
| 9 CMD FIFO Full                                                     | DSPI_3                                       |                                             |
| 10 TX FIFO Full                                                     | DSPI_4                                       |                                             |
| 11 RX FIFO Drain                                                    | DSP_4                                        |                                             |
| 12 CMD FIFO Full                                                    | DSP_4                                        |                                             |
| 13 TX FIFO Full                                                     | DSP_5                                        |                                             |
| 14 RX FIFO Drsin                                                    | DSPI_5                                       |                                             |
| 15 CMD FIFO Full                                                    | DSPL_5                                       |                                             |
| 16 RXDMAreq                                                         | 12C_2                                        |                                             |
| 17 TX DMAreq                                                        | 12C_2                                        |                                             |
| 18 RXDMAreq                                                         | 12C_3                                        |                                             |
| 19 TXDMA req                                                        | 12C_3                                        |                                             |
| 20 RX DMA req                                                       | 12C_4                                        |                                             |
| 21 TXDMA req                                                        | 12C_4                                        |                                             |
| 22 DMA Req.for InputCopture/Output Compare EE 23                    | Ethernet_0 Ethernet_0                        |                                             |
| DMA Request - channel 1 24 DMA Request - channel 2                  | Ethernet_0                                   |                                             |
| 25 DMA request 2                                                    | SIUL_0                                       |                                             |
| 26 DMA request 3                                                    | SIUL_0                                       |                                             |
| 27 DMA request 6                                                    | SIUL_0                                       |                                             |
| 28 DMA request 7                                                    | SIUL_0                                       |                                             |
| 29 DMA request 10                                                   | SIUL_0                                       |                                             |
| 30 DMA request 11                                                   | SIUL_0                                       |                                             |
| 31                                                                  | RESERVED                                     |                                             |
| 32 DMA request after channel conversion completiS                   | SARADC_1                                     |                                             |
| 33 DMA Request - channel 3                                          | Ethernet_0                                   |                                             |
| 34                                                                  | RESERVED                                     |                                             |
| 35                                                                  | RESERVED                                     |                                             |
|                                                                     | RESERVED                                     |                                             |
| 36                                                                  |                                              |                                             |
| 37 38 DMA Request for medis clock recovery/genera                   |                                              |                                             |
| 39                                                                  | PFE_MAC1                                     |                                             |
|                                                                     | RESERVED                                     |                                             |
|                                                                     | RESERVED                                     |                                             |
|                                                                     | RESERVED                                     |                                             |
| 43                                                                  | RESERVED                                     |                                             |
| 44                                                                  | RESERVED                                     |                                             |
| 45                                                                  | RESERVED RESERVED                            |                                             |
| 47 DMA request 2 48                                                 | SIUL_1                                       |                                             |
| DMA request 3 49                                                    | SIUL_1                                       |                                             |
|                                                                     | SIUL_1 SIUL_1                                |                                             |
| 50 DMA request 7                                                    |                                              |                                             |
| 51                                                                  | RESERVED                                     |                                             |
| 52 Channel O DMA transfer request 53 Channel 1 DMA transfer request | FTM_.1 FTM_1                                 |                                             |
| 54 Channel 2DMA transfer request                                    | FTM_1                                        |                                             |
| 55 Channel 3 DMA transfer request                                   | FTM_1                                        |                                             |
| 56 Channel 4 DMA transfer request                                   | FTM_1                                        |                                             |
| 57 Channel 5 DMA transfer request 58                                | FTM_1 FTM_1                                  |                                             |
| Channel 6DMA transfer request                                       |                                              |                                             |
| 59                                                                  | FTM_1                                        |                                             |
| Channel 7 DMA transfer request 60                                   |                                              |                                             |
|                                                                     | Always Ensbled                               |                                             |
| 61                                                                  | Alwayc Ensbled                               |                                             |
| 62                                                                  | Always Ensbled                               |                                             |
| 63                                                                  |                                              |                                             |
|                                                                     | Alwayc Ensbled                               |                                             |
|                                                                     | PFE_MAC2                                     |                                             |
| DMA request 6                                                       | DMA request 6                                | DMA request 6                               |
| 40 41                                                               |                                              |                                             |
| DMA Request for medis clock recoverylgenera                         | DMA Request for medis clock recoverylgenera  | DMA Request for medis clock recoverylgenera |
|                                                                     | DMA Request for media clock recoverylgeneral |                                             |
|                                                                     | PFE_MAC0                                     |                                             |
| 42                                                                  |                                              |                                             |
| 46                                                                  |                                              |                                             |

<!-- image -->

## DMA CRC

The following list summarizes the key features:

- Peripheral interface for accessing CRC's control and status registers
- Supports up to 8 CRC channels which can be enabled/disable per DMA channel
- Supports up to 6 different polynomials (8-bit, 16-bit and 32-bit). Each chancel can have its own polynomial or share the same polynomial. The following polynomials are supported:
1. Ethernet (IEEE 802,3) CCITT32 CRC-32
2. CASTAGNOLI, iSCSI CRC-32
3. E2E Profile 4 CRC-32
4. X.25 CCITT16 CRC-16
5. H2F, AUSTOSAR 4.0 CRC-8
6. VDA CAN, SAE-J180 CRC-8
- The CRC checksum is calculated on the read data when the DMA does its normal operation that is reading from its source address and writing to the its destination.
- The checksum can be reset to an initial value at the start of each major transfer loop, or it can continue to accumulate from the previous read transactions.

<!-- image -->

## SIUL: I/O  CONTROL

- S32G2 features an On-Chassis SIUL and an Off-Chassis SIUL
- On-Chassis IP can be multiplexed out through the Off-Chassis SIUL and vice-versa

<!-- image -->

<!-- image -->

## SIUL: INTERRUPTS AND DMA TRIGGERS

## Interrupts:

- Only SIUL\_1 can trigger an interrupt, no interrupts available from SIUL\_0
- SIUL\_1 has 32 pins with interrupt generating capability (EIRQ pins)
- There is a single interrupt source which is an OR of all 32 EIRQ pins
- Once interrupt occurs, Status Register can be read in the ISR to find out which pin was the source

<!-- image -->

## DMA:

- Only SIUL\_1 can trigger DMA transfers, no DMA requests available from SIUL\_0
- SIUL\_1 supports 8 DMA requests
- These requests are mapped to EIRQ[0:7] pins

<!-- image -->

|   47 | DMA request 2 (EIRQ2)   | SIUL1   |
|------|-------------------------|---------|
|   48 | DMA request 3 ( (EIRQ3) | SIUL 1  |
|   49 | DMA request 6 (EIRQ6)   | SIVL 1  |
|   50 | DMA request 7 (EIRQ7)   | SIUL 1  |

<!-- image -->

## Clocking Overview

<!-- image -->

PUBLIC

5 5

## CLOCKING OVERVIEW

## PLL sources:

- FXOSC: 20-40 MHz
- External crystal
- FIRC: 48 MHz
- Default out of reset
- SIRC: 32 kHz
- Standby support for RTC
- Control
- Clock Gating

<!-- image -->

<!-- image -->

## CLOCKING COMPONENTS

## 5xPLLs:

| PLL         | VCO Spec      | Use                                                                   |
|-------------|---------------|-----------------------------------------------------------------------|
| Core PLL    | 1.3 - 2 GHz   | • A53 / Concerto • M7 • HSE • FlexNOC • LLCE • IPS_CLK • LBIST • SBSW |
| Periph PLL: | 1.3 - 2 GHz   | Everything Else                                                       |
| Accel PLL   | 1.3 - 2.4 GHz | PFE                                                                   |
| DDR PLL     | 1.3 - 1.6 GHz | DRAM Controller                                                       |
| Aurora PLL  | 3 - 5 GHz     | Trace Debug                                                           |

## Dividers:

## CGM and PLL:

- Integer Divider only

## DFS:

- Fractional Divider

- 1/36 granularity

<!-- image -->

## CORE PLL

<!-- image -->

<!-- image -->

## ACCEL PLL

=External connection

X=Not used in this implementation

<!-- image -->

<!-- image -->

## PERIPH PLL

<!-- image -->

<!-- image -->

## CLOCK GATING

- The following subsystems can be independently clock gated in order to remove dynamic current:

## Block or Subsystem:

M7 Cluster 0

M7 Cluster 1

M7 Cluster 2

A53 cores 0 and 1

A53 cores 2 and 3

DRAM Controller

PFE

LLCE

<!-- image -->

## WHAT IS DFS?

- DFS is D igital F requency S ynthesizer designed to reduce number of PLLs in SoC that are needed due to independent clock domains and non-multiplying frequencies
- DFS generates 6 independently controlled outputs from single PLL clock
- Each output can generate fractional divide of PLL clock frequency
- Resolution of fraction division is (1/36)

<!-- image -->

## CLOCK GENERATION USING DFS

<!-- image -->

- PLL generates 9 phase clock from ring oscillator @ 1.3G-2.6G
- DFS generates 36 phase of divide by 2 clock using 9 phase input clock
- 36 phase are used by digital logic to generate 6 independent clock outputs
- Relationship between input and output clock frequency for each output

Fdfsclkout =Fdfsclkin /(2*[mfi+(mfn/36)])

mfi: Integer part of division [1:255]

mfn: Fractional part of division [0:35]

<!-- image -->

## PHASE GENERATOR EXAMPLE (3-12 PHASE GENERATION)

<!-- image -->

<!-- image -->

## EXAMPLE

<!-- image -->

<!-- image -->

## WHAT IS PCFS (PROGRESSIVE CLOCK FREQUENCY SWITCHING)?

- After reset, SOC is running at 48MHz, with only Cortex M7 running and most peripherals are clock gated.
- Load current at ambient temperature is negligible (Leakage very small and only the dynamic current for M7 and system infrastructure)
- If all peripherals are enabled and clock is switched to Maximum (1GMHz, load will increase within a few nS from a few mW to a few W.
- This load change will cause power supply droop and may cause a reset.
- PCFS provides hardware control to allow the system frequency to be ramped, thus slowing down the rate of load change and minimising supply droop

<!-- image -->

<!-- image -->

## PCFS BLOCK DIAGRAM

<!-- image -->

- Fractional clock divider, divides the clock to a low frequency so peripherals can be enabled with small load changes.
- Ramp Profile Generator allows the Fractional divide ratio to be automatically modified at a pre-programmed rate to slowing increase the system frequency.
- The ramp is triggered in software by a Mode change in MC-CGM.
- The status of the ramp can be monitored via registers in MC-CGM.

<!-- image -->

## Reset Overview

<!-- image -->

PUBLIC

6 8

## RESET OVERVIEW

- Escalating hierarchy of reset
- PoR
- Destructive Reset
- Functional Reset

## • External Pins

<!-- image -->

| External Pin          | Type   | Internal Pull                                                             | Description                                                                                                      |
|-----------------------|--------|---------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| Input                 | Down   | Active-low power-on reset indicator from PMIC - Source for Power-on-Reset | POR_B                                                                                                            |
| RESET_B Bidirectional | Up     | indicator                                                                 | Active-low open-drain external reset - Input is source for functional reset - Signal will drive low on any reset |

<!-- image -->

<!-- image -->

## RESET: SOURCES &amp; SOFTWARE CONTROLLABLE

## Power-on-Reset Source

POR\_B pin assertion

0.8V Coarse POR error

1.8V Coarse POR error

3.3V Coarse POR error

Critical go/no-go error

POR watchdog timeout

## Destructive Reset Source

'functional' reset escalation go/no-go detectors fail

OCOTP uncorrectable ECC error

FCCU failure to react

STCU unrecoverable fault

FXOSC failure

CORE\_PLL loss of lock

PERIPH\_PLL loss of lock

DDR\_PLL loss of lock

ACCEL\_PLL loss of lock

XBAR\_DIV3\_CLK failure life-cycle error

software 'destructive' reset debug 'destructive' reset

## Functional Reset Source

RESET\_B pin assertion

FCCU reset reaction self-test done

HSE SWT timeout

HSE SNVS tamper detected

HSE memory ECC error boot ROM ECC error

boot failure error

HSE M7 core lock software 'functional' reset

debug 'functional' reset

## Software Resetable Modules

Cortex-A53 Cluster 0 &amp; 1

Cortex-A53 Cluster 0

Cortex-A53 Cluster 1

LLCE

## Control via RGM

All CPUs (Cortex-M7 / A53) support independent reset via CPU control.

<!-- image -->

## RESET ACTION

<!-- image -->

| Destructive Reset Entry Actions: (only retains status flags; all events are concurrent) Memories can be corrupted   | Dependancies          |
|---------------------------------------------------------------------------------------------------------------------|-----------------------|
| reset requested                                                                                                     | out of reset sequence |
| requesting module/MC will store source of reset                                                                     | reset requested       |
| assert reset pin out and put the external pins in the default state                                                 | reset requested       |
| Mask HVDsignals                                                                                                     | reset requested       |
| switch to IRC source without clock glitches (maybe use clk gate)                                                    | reset requested       |
| turn off PLL, leave XOSC on                                                                                         |                       |
| Dest reset signal asserted to entire SoC                                                                            | reset requested       |

| Short Reset Entry Actions:   | Short Reset Entry Actions:                                                                            | Dependancies                              |
|------------------------------|-------------------------------------------------------------------------------------------------------|-------------------------------------------|
|                              | reset requested                                                                                       | out of reset sequence                     |
|                              | requesting module/MC will store source of reset                                                       | reset requested                           |
|                              | enable DDRself refresh                                                                                | reset requested;DDR available             |
|                              | assert reset pin out and put the external pins in the default state                                   | DDRrefresh completed                      |
|                              | disable all module enables to blocks synchronize and isolate the interfaces (i.e. IPS/IHB/FLEXNOC/Clk | LBIST has completed abort;reset requested |
|                              | blocks/SRAMs/Flash)                                                                                   |                                           |
|                              | If LBIST is active, assert abort input                                                                | reset pin asserted; DDRrefresh completed  |
|                              | If LBIST was running, wait for LBIST to abort                                                         | LBIST abort input asserted                |
|                              | execute PCFS to switch back to IRC                                                                    | mod_en disabled                           |
|                              | turn off PLL, leave XOSC on                                                                           |                                           |
|                              | short reset signal asserted to entire SoC                                                             | PCFS done                                 |

<!-- image -->

## RESET ESCALATION

## • Short Reset Escalation:

If a predefined number of Short resets occur without software intervention, the next reset is escalated to a Destructive reset.

## • Destructive Reset Escalation:

If a predefined number of destructive resets occur without software intervention, the next reset is escalated to a permanent reset condition (held in reset).

The only exit from this condition is to assert POR pin.

This is a functional safety feature. A fault that causes a reset will not keep repeating the reset sequence until something else breaks.

<!-- image -->

## Platform Resource Isolation

<!-- image -->

PUBLIC

7 3

## ARM TRUSTZONE + NXP RESOURCE DOMAIN CONTROLLER (XRDC) FOR ISOLATION

- Combination of TrustZone + XRDC enables a Trusted Execution Environment (TEE)
- Logically isolates secure code + allocated resources from non-secure code
- Cortex-A53 treats access as TZ access operation, but XRDC handles system-level isolation
- XRDC provides additional resource isolation at the S32G2 system level
- For access control, system memory protection, and peripheral isolation
- Proven IP used in other NXP devices
- Understands and leverages TZ as qualifier for isolation
- Many domains can be created in parallel (ASIL B, ASIL D, QM safety)
- Can be used by Cortex-M7 processor without TZ to assign to secure domain
- Internal resources/interfaces (not external)

TrustZone + XRDC are complementary and independent of HSE for security isolation.

<!-- image -->

<!-- image -->