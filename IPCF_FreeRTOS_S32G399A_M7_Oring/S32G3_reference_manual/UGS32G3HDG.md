## UG\_S32G3

## User guide S32G3 Hardware Design Guidelines

Rev. 3.1 - 19 January 2024

## Document information

User guide

| Information   | Content                                                                                   |
|---------------|-------------------------------------------------------------------------------------------|
| Keywords      | S32G3, Hardware Design Guide, S32G-VNP-EVB3                                               |
| Abstract      | This document summarizes the recommended guidelines for designing a S32G3 based hardware. |

<!-- image -->

## 1   Introduction

S32G3 (supports S32G378A, S32G379A, S32G398A, S32G399A) is a high-performance automotive networking processor family, combining CAN/LIN/FlexRay networking with high data rate ethernet networking. It combines a functional safety core infrastructure with performance MPU cores, along with a high level of security features. The S32G3 chips are pin-for-pin compatible with S32G2 chips, providing over 2x performance and system RAM.

The purpose of this document is to define requirements and guidelines for S32G3 based hardware. It covers topics such as voltage regulator and power considerations, clock generation, decoupling, memory interface, etc. Detailed reference design schematics and descriptions of the main components, as well as some general hardware recommendations, are provided within this document. It gives examples of the board layout, design checklists to ensure first-pass success, and solutions to avoid board bring-up problems. Engineers must understand board layouts and board hardware terminology.

## Note:

- This document represents the features offered for the superset S32G399A with exceptions mentioned in each applicable section. To compare the detailed feature of S32G3 variants, refer to the latest revision of the S32G3 reference manual and data sheet.
- The device details contained in this document are correct at the time of writing. However, the latest version of the S32G3 data sheet, reference manual, and errata document should always be consulted for the latest specs.
- The latest errata sheet for the device should always be consulted as there may be specific errata that could impact the hardware design.

## 1.1  Acronyms and definition

Table 1. Acronyms and definition

| Acronym   | Definition                                          |
|-----------|-----------------------------------------------------|
| Arm       | Advanced RISC Machines processor architecture       |
| BGA       | Ball Grid Array package                             |
| BOM       | Bill of Materials                                   |
| BSDL      | Boundary Scan Description Language                  |
| CAN       | Controller Area Network                             |
| DDR       | Dual Data Rate DRAM                                 |
| DDR3L     | Low voltage DDR3 DRAM                               |
| EEPROM    | Electrically Erasable Programmable Read-Only Memory |
| ETM       | Embedded Trace Macrocell                            |
| GND       | Ground                                              |
| GPIO      | General Purpose Input/Output                        |
| I 2 C     | Inter-integrated Circuit interface                  |
| IBIS      | Input-Output Buffer Information Specification       |
| IOMUX     | Input-Output Multiplexing                           |
| JTAG      | Joint Test Action Group                             |
| LDO       | Low Drop-Out regulator                              |
| LPDDR4    | Low Power DDR4 DRAM                                 |

UG\_S32G3

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

Table 1. Acronyms and definition ...continued

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

| Acronym   | Definition                                  |
|-----------|---------------------------------------------|
| LVDS      | Low-Voltage Differential Signaling          |
| LIN       | Local Interconnect Network                  |
| MAC       | Media Access Control                        |
| MDIO      | Management Data Input/Output                |
| MII       | Media Independent Interface                 |
| NC        | Not Connect                                 |
| NMI       | Non-Maskable Interrupt                      |
| ODT       | On-Die Termination                          |
| PCB       | Printed Circuit Board                       |
| PCIe      | PCI Express                                 |
| PDN       | Power Delivery Network                      |
| PHY       | Physical Layer Interface                    |
| PMIC      | Power Management Integrated Circuit         |
| POR       | Power-On Reset                              |
| QSPI      | Quad serial peripheral interface.           |
| RGM       | Reset Generation Module                     |
| RGMII     | Reduced Gigabit Media Independent Interface |
| ROM       | Read-Only Memory                            |
| SerDes    | Serializer/Deserializer                     |
| SGMII     | Serial Gigabit Media Independent Interface  |
| SDHC      | Secure Digital High Capacity                |
| SDR       | Single Data Rate                            |
| STBY      | Standby                                     |
| ULPI      | UTMI Low Pin Interface                      |
| USB       | Universal Serial Bus                        |
| WKUP      | Wake Up                                     |

## 1.2  Package information

S32G3 family of devices is available in a single physical package, 525 flip-chip plastic ball grid array (525 FCPBGA), 19mm x19mm, 0.8mm pitch.

## 1.3  References

This guide is supplementary to the S32G3 reference manual and data sheet. For the list of current documents, see www.nxp.com or contact your local NXP sales office.

The following documentation provides useful information about the Arm processor architecture:

- For information about the Arm Cortex-A53 ® processor, see: https://developer.arm.com/ip-products/processors/ cortex-a/cortex-a53.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

- For information about the Arm Cortex-M7 ® processor, see: https://developer.arm.com/ip-products/processors/ cortex-m/cortex-m7.

The following documentation provides useful information about high-speed board design:

- Right the first time- a practical handbook on high-speed pcb and system design - Volumes I &amp; II - Lee W. Ritchey (Speeding Edge) - ISBN 0-9741936- 0-72.
- Signal and power integrity simplified (2nd edition) - Eric Bogatin (Prentice Hall)- ISBN 0-13-703502-0.
- High-speed digital design- a handbook of black magic - Howard W. Johnson &amp; Martin Graham (Prentice Hall) ISBN 0-13-395724-1.
- High-speed signal propagation- advanced black magic - Howard W. Johnson &amp; Martin Graham - (Prentice Hall) - ISBN 0-13-084408-X.
- High-speed digital system design- a handbook of interconnect theory and practice - Hall, Hall, and McCall (Wiley Interscience 2000) - ISBN 0-36090-2.
- Signal integrity issues and printed circuit design - Doug Brooks (Prentice Hall) ISBN 0-13-141884-X.
- PCB design for real-world emi control - Bruce R. Archambeault (Kluwer Academic Publishers Group) - ISBN 1-4020-7130-2.
- Digital design for interference specifications - a practical handbook for EMI Suppression -David L. Terrell &amp; R. Kenneth Keenan (Newnes publishing) - ISBN 0- 7506-7282-X.
- Electromagnetic compatibility engineering- Henry Ott (1st edition - John Wiley and Sons) - ISBN 0-471-85068-3.
- Introduction to electromagnetic compatibility - Clayton R. Paul (John Wiley and Sons) - ISBN 978-0-470-18930-6.
- Grounding &amp; shielding techniques - Ralph Morrison (5th edition - John Wiley &amp; Sons) - ISBN 0-471-24518-6.
- EMC for product engineers - Tim Williams (Newnes publishing) - ISBN 0-7506-2466-3.

The following application notes have been referenced in this document:

- AN12422 - S32G boot process
- AN13456 - S32G3 boot process
- AN12530 - S32x Arm Aurora Trace Connector
- AN12880 - VR5510 low-power Standby mode

## 2   Getting started on hardware design

The first step in designing a hardware platform is to create a detailed block diagram. The block diagram should contain all major system ICs and illustrate which I/O ports are used for device interconnection. The system blocks should be able to answer the below questions:

- Define the power tree of the platform.
- Any low power requirements of the design.
- What is the boot medium planned?
- How will the external NVMs be programmed?
- Which peripherals will be used to move data in and out of the processor?
- What is the speed and organization of the memory interfaces used?
- What are the specific requirements of communication protocols used?
- Certain protocols may have clock precision constraints, can these be supplied externally or does the system clock need to follow the same precision.
- Confirm pin multiplexing compatibility.
- …. and so on.

© 2024 NXP B.V. All rights reserved.

## 3   Hardware changes from S32G2

Below are the major changes that impact hardware design for S32G3 based applications when compared to S32G2 based hardware design:

- Pad H15, VDD\_LV\_PLL, is an NC on S32G3. This should be left unconnected to the hardware. The S32G3 silicon can however be used with S32G2 compatible hardware designs which have an external supply connected to this pin.
- The worst-case power consumption of S32G3 is higher compared to that for S32G2 (Refer to the latest device Data Sheet for details on power). This exceeds the maximum output of the VR5510 and therefore requires the use of an additional regulator for the 0.8 V supply. NXP recommends PPF53BDAMMA1ES to be used for the 0.8 V supply in companion mode to VR5510.

## 4   Power Supply

The S32G3 device has multiple supply pins for the core, I/O, fuses, and analog supplies. All such pins must be connected to the proper supply voltage for proper operation. All VSS pins need to be connected to the external power supply ground.

All power rails on the S32G3 must be connected to their respective voltage even if they are not used. The associated decoupling capacitors can be avoided if a particular function is not being used.

## 4.1  Power tree

The following table shows the recommended power supply grouping and their status during Standby mode.

<!-- image -->

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

## 4.2  Power sequencing

Refer to S32G3 data sheet for the latest information on power sequencing. The power sequencing requirements are identical for S32G3 and S32G2.

The recommended PMIC solution by NXP ensures that the sequencing order is maintained. For any design not involving recommended PMIC solution, this dependency should be handled externally.

## 4.3  Power connections

The following table shows the recommended S32G3 power supply grouping for each PMIC output under the assumption that a VR5510 is used as PMIC. Details on VDD\_EFUSE supply are provided in VDD\_EFUSE power.

Figure 2. PMIC/S32G3 supply connections

| PMIC (VR5510 and PF5300)   | Voltage domain   | S32G3 Supplies                                                                                                                                                                                                                                             |
|----------------------------|------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| VPRE                       | 3.3V             | VDD_IO_STBY,VDD_IO_B                                                                                                                                                                                                                                       |
| LD03                       | 3.3 V            | VDD_IO_A,VDD_IO_B, VDD_IO_SDHC, VDD_IO_USB, VDD_IO_GMAC0, VDDIOGMAC1                                                                                                                                                                                       |
| LD02                       | 1.8 V            |                                                                                                                                                                                                                                                            |
| LD01                       | 1.8 V            | VDD HV PLLAUR, VDDHV_PLL_DDRO, VDD ）VREF,VDD_HV_PLL, VDD _ADC,VREFH_ADCO, VDD _FIRC,VREFH_ADC1, VDD_FXOSC,VDD_TMU, VDD_DDRO,VDD_EFUSE, VDD_IO_PCIE0, VDD_IO_PCIE1, VDD_IO_AUR, VDD_IO_CLKOUT, VDD_IO_SDHC,VDD_IO_USB, VDD_IO_GMAC0, VDDI0 GMAC1,VDDIO QSPI |
| BUCK3                      | 1.1 V            | VDD_10 DDRO                                                                                                                                                                                                                                                |
| BUCK2                      | 1.1 V            | Available for application usage                                                                                                                                                                                                                            |
| BUCK1                      | 1.8 V            | VDD_10_ QSPI                                                                                                                                                                                                                                               |
| HVLDO                      | 0.8V             | VDD_STBY                                                                                                                                                                                                                                                   |
| PF5300_OUT                 | 0.8V             | VDD,VDD_LV_PLL_AUR, VDD_LV_PLL_DDRO, VDDVPPCIE0,VDDVPPCIE1                                                                                                                                                                                                 |

## Note:

- LDO2 output is used as enable for PF5300.
- The supply denoted in blue color is a 3.3 V supply that can be in either the VPRE or the LDO3 power supplies.
- The supply denoted in green color is a 1.8 V supply that can be in either the LDO1 or the BUCK1 power supplies.
- Each supply denoted in red color is a 1.8/3.3 V supply that can be in either the LDO3 or LDO1 power supplies.

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

User guide S32G3 Hardware Design Guidelines

- Default OTP configuration of PVR5510AMDALES programs BUCK2 output to 1.1 V. This can be used for any additional on-board requirement. Users can generate custom OTP configuration that programs BUCK2 output to other voltage levels as per their system power requirement.

## 4.4  PMIC S32G3 control signals connections

The block diagram shows the interface connections between S32G3, PF5300, and VR5510 PMIC. The interface connections must be correctly handled if using any other PMIC. Refer to S32G3 reference manual for more details on each signal.

<!-- image -->

## Note:

- The I2C\_4 instance shown in the block diagram above is an example only. Any available I2C instance can be used.

User guide S32G3 Hardware Design Guidelines

- The interface connections must be correctly handled if using a different PMIC solution. Refer to S32G3 RM for more details on each signal.

## 4.4.1  PMIC sense and VDD\_STBY

The S32G3 device features a voltage feedback sense pin (PMIC\_SENSE) for the VDD supply, which supports IR drop compensation from the PMIC to the S32G3 device. "IR drop" refers to the voltage drop due to the supply current "I" flowing into the PCB power plane resistance "R". This allows precise voltage monitoring and adjustment of the PMIC output voltage to compensate for the drop across PCB traces and internal bond wires of the S32G3 device. PMIC\_SENSE must be connected to the feedback input of the PF5300 to allow the regulator to correctly compensate for any voltage drop across the board traces and internal wire bond of the device.

In addition to this, the LV\_HVLDO\_IN pin for HVLDO must be routed from the 0.8 V supply near S32G3 to have the same regulated voltage at the VDD\_STBY in run mode.

## 4.5  Voltage monitoring

The PMIC (VR5510) supports voltage monitoring provision. There is a straight connection between monitoring and voltage output regulators.

Below is the recommended VR5510 monitors usage:

- VCOREMON: dedicated to BUCK1 supply monitoring.
- HVLDOMON: connected internally to HVLDO output.
- VDDIOMON: connected internally to VDDIO input .
- Connection using external resistor divider:
- -VMON1, VMON2, VMON3, and VMON4.
- -Allows monitoring of various voltages level.
- -EVB3 usage: VMON1 for 0.8 V Core supply, VMON2 for BUCK3, VMON3 for VPRE and VMON4 for LDO1.

## 4.6  S32G3 supplies in Standby mode

Each application may have a different standby requirement. Hence, the S32G3 supplies required in Standby mode are grouped into 'required' and 'optional'. All other supply sources must be turned off by appropriate programming of VR5510 PMIC.

- Required:
- -VDD\_STBY - provided by VR5510 HVLDO.
- -VDD\_IO\_STBY - provided by VR5510 VPRE.
- Optional:
- -VDD\_IO\_B - Can optionally be kept enabled if the IOs interfacing with S32G3 running on VDD\_IO\_B are pulled up on the board or from external ICs, but this will result in additional Standby mode current consumption.
- -For use cases with DDR self-refresh mode:
- -VDD\_IO\_DDR0 (1.1/1.35 V).
- -BUCK1 can be used as an additional supply ON during standby for powering the LPDDR4 memory. VDD\_IO\_QSPI should also be powered by the same BUCK in case QSPI is required to be powered in standby. The QSPI flash must be configured in deep power-down state during Standby mode. BUCK1 should be connected only to the domain/components that are required in Standby mode.

© 2024 NXP B.V. All rights reserved.

## 4.6.1  I/O pad behavior in Standby mode

23 wakeup pads remain powered in Standby mode. These pads are in the VDD\_IO\_STBY power domain and are input-only pads, typically used as Rx pins for comms interfaces.

All other GPIO pads are powered down. However, any active pull-up on a powered down pad causes unwanted current flow through the pad, increasing the standby current. A strong pull-up on a powered down pad can also lead to failure of standby entry.

<!-- image -->

## 4.6.2  VDD\_IO\_B options in Standby mode

Typically, the CAN\_Rx pins double up as wakeup inputs and therefore are present in the VDD\_IO\_STBY domain. The corresponding CAN\_Tx pins are present in the VDD\_IO\_B domain. In the case of 'wakeup from CAN' use case, internal pullups from CAN PHY is present on CAN\_Tx pads in Standby mode. The leakage on these CAN\_Tx pads thus becomes a concern in Standby mode.

Depending on the hardware design either of the below two strategies can be followed to minimize the standby consumption:

1. Power down VDD\_IO\_B and minimize leakage. This however results in additional leakage per CAN Phy with wake-up capability.
1. Keep the VDD\_IO\_B domain powered during Standby mode. This adds 40 pins to the standby domain. This domain covers all Tx pin for all CAN interfaces.

<!-- image -->

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

User guide S32G3 Hardware Design Guidelines

<!-- image -->

Trade-off needs to be made between these methods depending on the use case. The option which results in the lowest standby current must be selected.

Pins that remain powered in standby (i.e., all pins in VDD\_IO\_STBY and optionally all pins in VDD\_IO\_B) can remain floating and have no impact on leakage current.

- If powered pins are pulled up, then there will be an adder of 0.3 uA per pin on to associated I/O segment for pin leakage.
- There is no adder for pins that are pulled low.

Unpowered pins need to be undriven from outside or pulled down otherwise there will be additional leakage current.

## 4.6.3  Standby mode entry/exit considerations

The power supplies are not turned off during Standby mode until PMIC\_STANDBY\_MODE\_B goes low (0 V). Turning OFF switchable power supplies during Standby mode entry does not cause the supplies still ON to have voltage over/undershoots. Once all switchable supplies are turned OFF completely (100 mV or below), the PMIC\_VDD\_OK input signal to S32G3 goes low (0 V).

Switchable power supplies are not turned ON during Standby mode exit until the PMIC\_STANDBY\_MODE\_B goes high (3.3 V). Turning ON switchable power supplies during Standby mode exit does not cause any voltage over/undershoot on the already available supplies. After all switchable supplies are turned ON and they reach the operating levels, PMIC\_VDD\_OK should go high (3.3 V).

<!-- image -->

Refer to the VR5510 low-power Standby mode application note for the Standby mode entry and exit of the VR5510 PMIC.

## 4.7  Decoupling/bypass circuit

The following table shows all power domains and the mandatory (minimum) decoupling (decap) and/or filter capacitors for their corresponding pins.

© 2024 NXP B.V. All rights reserved.

## User guide S32G3 Hardware Design Guidelines

NXP also recommends using ferrite beads on certain power groups. The recommendation for beads and power grouping is as shown in the below table. It is recommended to use a Ferrite bead similar in characteristics to MPZ2012S101A from TDK.

Table 2. Decaps and ferrite bead requirement

|   S. No. | Supply name   |   No. of pin | Cap (decap)   | Other cap          | Ferrite bead requirement   |
|----------|---------------|--------------|---------------|--------------------|----------------------------|
|        1 | VDD           |           30 | 2.2 µf*30     | 0.1µf              |                            |
|        1 | VDD           |           30 | 2.2 µf*30     | 10 µf*2 (DNP)      |                            |
|        2 | VDD_ADC       |            1 | 1000 pF       | 0.1 µf             |                            |
|        2 | VDD_ADC       |            1 | 1000 pF       | 10 µf              |                            |
|        3 | VDD_VREF      |            1 | 0.01 µf       | 0.1 µf 10 µf (DNP) | ✓                          |
|        4 | VREFH_ADC0    |            1 | 0.01 µf       | 0.1 µf             |                            |
|        5 | VREFH_ADC1    |            1 | 0.01 µf       | 0.1 µf             |                            |
|        6 | VDD_DDR0      |            1 | 0.1 µf        | 1.0 µf             | ✓                          |
|        6 | VDD_DDR0      |            1 | 0.1 µf        | 10 µf              | ✓                          |
|        7 | VDD_EFUSE     |            1 | 0.01 µf       | 0.1 µf 4.7 µf      |                            |
|        8 | VDD_FIRC      |            1 | 0.01 µf       | 0.1 µf             | ✓                          |
|        9 | VDD_FXOSC     |            1 | 0.01 µf       | 0.1 µf             | ✓                          |
|       10 | VDD_TMU       |            1 | 0.01 µf       | 0.1 µf             | ✓                          |
|       11 | VDD_IO_A      |            2 | 0.01 µf*2     | 0.1 µf*2           |                            |
|       11 | VDD_IO_A      |            2 | 0.01 µf*2     | 4.7 µf             |                            |
|       12 | VDD_IO_B      |            2 | 0.01 µf*2     | 0.1 µf*2           |                            |
|       12 | VDD_IO_B      |            2 | 0.01 µf*2     | 4.7 µf             |                            |
|       13 | VDD_IO_AUR    |            2 | 0.1 µf*2      | 10 µf (DNP)        |                            |
|       14 | VDD_IO_CLKOUT |            1 | 0.01 µf       | 0.1 µf 10 µf       |                            |
|       15 | VDD_STBY      |            2 | 0.1 µf*2      | 10 µf              |                            |
|       16 | VDD_IO_STBY   |            1 | 0.1 µf        | 10 µf              |                            |
|       17 | VDD_IO_DDR0   |           16 | 0.1 µf*16     | 1.0 µf 10 µf       |                            |
|       18 | VDD_IO_GMAC0  |            1 | 0.01 µf       | 0.1µf              |                            |
|       18 | VDD_IO_GMAC0  |            1 | 0.01 µf       | 10 µf              |                            |
|       19 | VDD_IO_GMAC1  |            2 | 0.01 µf*2     | 0.1 µf*2           |                            |
|       19 | VDD_IO_GMAC1  |            2 | 0.01 µf*2     | 10 µf              |                            |
|       20 | VDD_IO_QSPI   |            1 | 0.01 µf       | 0.1 µf 10 µf       |                            |

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 2. Decaps and ferrite bead requirement ...continued

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

|   S. No. | Supply name     |   No. of pin | Cap (decap)   | Other cap   | Ferrite bead requirement   |
|----------|-----------------|--------------|---------------|-------------|----------------------------|
|       21 | VDD_IO_SDHC     |            1 | 0.1 µf        | 10 µf       |                            |
|       22 | VDD_IO_USB      |            1 | 0.1 µf        | 10 µf       |                            |
|       23 | VDD_LV_PLL      |            1 | 0.1µf         | 10µf        |                            |
|       24 | VDD_LV_PLL_AUR  |            1 | 0.1 µf        | 10 µf       | ✓                          |
|       25 | VDD_LV_PLL_DDR0 |            1 | 0.1 µf        | 1.0 µf      | ✓                          |
|       25 | VDD_LV_PLL_DDR0 |            1 | 0.1 µf        | 10 µf       | ✓                          |
|       26 | VDD_HV_PLL      |            1 | 0.1 µf        | 10 µf       | ✓                          |
|       27 | VDD_HV_PLL_AUR  |            1 | 0.1 µf        | 10 µf       | ✓                          |
|       28 | VDD_HV_PLL_DDR0 |            1 | 0.1 µf        | 10 µf       | ✓                          |
|       29 | VDD_VP_PCIE0    |            2 | 0.01 µf*2     | 0.1 µf*2    | ✓                          |
|       29 | VDD_VP_PCIE0    |            2 | 0.01 µf*2     | 10 µf       | ✓                          |
|       30 | VDD_VP_PCIE1    |            2 | 0.01µf*2      | 0.1 µf*2    | ✓                          |
|       30 | VDD_VP_PCIE1    |            2 | 0.01µf*2      | 10 µf       | ✓                          |
|       31 | VDD_IO_PCIE0    |            2 | 0.1 µf*2      | 10 µf       | ✓                          |
|       32 | VDD_IO_PCIE1    |            2 | 0.1 µf*2      | 10 µf       | ✓                          |

## Note:

- Each power pin must have one decap placed adjacent to the pin.
- Other caps must be placed near to corresponding ferrite beads.
- DNP cap pads are added so that in case needs arise, then parts can be populated.
- It is recommended that the power delivery network AC impedance is extracted, and the impedance is checked vs the guidelines provided in the PDN (Power Delivery Network) Guidelines section.

## 4.7.1  Placing decoupling capacitors

Place small decoupling and larger bulk capacitors on the bottom side of the PCB. The 0201 or 0402 decoupling and 0603 or larger bulk capacitors must be mounted as close as possible to the power vias. The distance must be less than 50 mils. Additional bulk capacitors can be placed near the edge of the BGA via array. Placing the decoupling capacitors close to the power balls is critical to minimize inductance and ensure the high-speed transient current required by the processor. See the NXP S32G3 reference board layouts for an example of the required decoupling capacitor placement.

The following list introduces how to choose the correct decoupling scheme:

- Place the largest capacitance in the smallest package that budget and manufacturing can support.
- For high-speed bypassing, select the required capacitance with the smallest package (for example - 0.1 µf, 0.22 µf, 1.0 µf, or even 2.2 µf in a 0201 package size).
- Minimize trace length (inductance) to small caps.
- Series inductance cancels out capacitance.
- Tie caps to GND plane directly with a via.
- Place capacitors close to the power ball of the associated package from the schematic.

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

## 4.8  PDN (Power Delivery Network) requirements

A well-designed Power Delivery Network (PDN) includes the following components.

- A considered PCB stack-up with adequate copper thicknesses and layer assignments/utilization. Refer to Section 13.
- Optimize the placement and routing of the PDN - This includes good placement of the decoupling capacitors and connecting them to the power ground planes with as short and wide trace/plane as possible (as the increased inductance of a longer etch will degrade the effectivity of the capacitor).
- Optimize the DC IR drop - This involves using very wide traces/plane fills to route high-current power nets (VDD) to ensure an adequate number of vias on power net layer transitions. Neck down of fill areas and current density must be minimized.
- AC resonance check - The target impedance at different frequencies must meet or undershoot the specified values.

Table 3. PDN impedance targets

| Supply input       |   < 20 MHz (max mOhm) |   20 MHz - 100 MHz (max mOhm) |
|--------------------|-----------------------|-------------------------------|
| VDD (0.8 V)        |                     5 |                            25 |
| VDD_DDR_IO (1.1 V) |                    20 |                            80 |

Note:

The on-chip die caps are capable of handling frequencies beyond 100 MHz.

## 4.9  VDD\_EFUSE power

The S32G3 device features an in-built fusebox to allow device data to be stored in a permanent state, surviving reset and power cycles. To program fuses during development and factory programming and potentially infield, it is required to supply power to the VDD\_EFUSE pin of the device. This supply allows the programming operation to take place.

The VDD\_EFUSE supply must only be powered when a fuse programming operation is required. For all other instances, it must be grounded. This protects the fuses from any chance of unwanted fuse programming operations. Therefore, it is mandatory to ground the VDD\_EFUSE supply when fuse operation is not required. This can be achieved in several ways and is dependent on the functionality required in the final application.

## 4.9.1  Application controlled VDD\_EFUSE supply

This option provides flexibility and allows software control for enabling/disabling the VDD\_EFUSE supply. This can be achieved with a dedicated PMIC/regulator output that allows switchable supplies, or a GPIO controlled external switch which enables/disables the 1.8 V connection with VDD\_EFUSE as per application requirement.

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

<!-- image -->

## This is recommended to be used for all applications using HSE due to the following reasons :

1. HSE firmware may need to blow a certain fuse during boot time, permanently grounding VDD\_EFUSE hampers this operation.
2. An in-field update to the HSE firmware also requires fuses to be blown as a means of 'roll-back protection' (i.e., a mechanism to ensure that an older FW version cannot be re-installed in the future to potentially re-open a patched security exploit). Due to this requirement, the option of permanently grounding the VDD\_EFUSE supply is not available to hardware that needs to support Over The Air (OTA) updates.

Refer to HSE firmware manuals to see how HSE controls the VDD\_EFUSE. The scheme is similar in both S32G2 and S32G3 based hardware designs.

Note: If a dedicated power regulator output is available for VDD\_EFUSE, the output must be kept disabled during the power-up sequence and must be enabled only when fuse write is required.

## 4.9.2  Permanently grounding VDD\_EFUSE

This option ensures that the hardware will never allow any unintentional fuse alteration to take place. For this solution, the supply ball can be connected directly to the ground. This is recommended for applications not using HSE firmware and having no requirement to update the fuse configurations in the field.

The lifecycle fuses or some other fuses may still be required to be blown, however the same can be accomplished on a production setup with any hardware mechanism providing VDD\_EFUSE supply externally.

## 5   Reset

## 5.1  External reset sources

## 5.1.1  POR\_B pin

The active-low POR\_B pin uses a weak pull-down on its input. During chip power-up, PMIC asserts the POR\_B pin as soon as its circuit becomes functional.

During normal operation, PMIC asserts the POR\_B pin when any of the voltages monitored by PMIC (VR5510) fall below its corresponding threshold.

Circuit recommendations:

- POR\_B pin of S32G3 is connected to PMIC (VR5510) PGOOD pin.

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

- POR\_B pull-up resistor must be less than or equal to 2 kOhm.
- The POR\_B signal must be immune to on-board noises. A low pass filter can be added close to the POR\_B pin on S32G3 to eliminate any unwanted reset events.

## 5.1.2  RESET\_B pin

The active-low RESET\_B is an open-drain bidirectional pin with an internal weak pull-up. It is used primarily as an output from S32G3 to indicate when the chip is in its reset state. It can also be used as an input when debugging the chip both as a functional reset source and to extend the reset sequence exit to allow the debugger to set up the debug session. When using RESET\_B as a reset source, it is important to not use it for this purpose during Standby mode entry or exit.

Circuit recommendations:

- The RESET\_B pin is connected to the PMIC (VR5510) RSTB output. An external pull-up of less than or equal to 10 kOhm external pull-up is required on the board.
- The RESET\_B signal must be immune to on-board noises. A low pass filter can be added close to the RESET \_B pin on S32G3 to eliminate any unwanted reset events.

## 6   Clocking

## 6.1  Crystal consideration

Table 4. Oscillator/crystal recommendations

|   S. No. | Recommendations                                                                                                                                               | Explanation/Supplemental Recommendations                                                                                                                                                                                                                                                                                                                         |
|----------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|        1 | Choose one of the following clocking options: • Connect a 40 MHz crystal between EXTAL and XTAL. • Connect a suitable 40 MHz single end clock input to EXTAL. | This clock is used as the source of core, system, and other IP clocks in S32G3. Follow the manufacturer's recommendation for load capacitance. Refer to S32G3 data sheet for crystal parameters and specifications.                                                                                                                                              |
|        2 | Crystal tolerance                                                                                                                                             | Tolerance requirements for external crystal is governed by the peripheral modes/protocol used in the application. e.g., RGMII mode specifies a clock source with max tolerance of 50 ppm. In such cases, the tolerance of the selected crystal must follow this specification. The designer must verify all tolerances per the official protocol specifications. |

## 6.2  Clocking layout requirements

The following requirements need to be followed for clocking layout:

- An external feedback resistor is not needed because it's already integrated into the device.
- Keep the oscillator circuit as compact as possible to minimize emissions.
- VSS \_FXOSC must be connected directly to the ground plane so that return currents can flow easily between VSS \_FXOSC and the two capacitors (C1 and C2).
- Avoid other high-frequency signals near the crystal circuitry. These can influence the crystal.
- Layout/configure the ground supply based on low impedance.
- Do not layout sensitive signals near the crystal.
- The VSS pin close to the XTAL pins must be connected to the ground plane and decoupled to the closest VDD pin.
- Capacitors must be placed at both ends of the crystal, directly connected to the ground plane while keeping the overall loop as small as possible.

© 2024 NXP B.V. All rights reserved.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

- To isolate the noise from or to a special area of the PCB, a guard ring can be used. That will almost surround this area with the ground (except in one point) and thus there will be no current flowing through this guard ring in normal operation.
- A solid GND plane must be directly under crystals, associated with components and traces.

## 7   Boot Configuration

## 7.1  Boot related I/Os

- Logic levels on BOOTMOD[0] (PA\_02) and BOOTMOD[1] (PA\_03), just before RESET\_B is released, define the boot mode for S32G3. Values on BOOTMODE pins must be stable while RESET\_B is low.
- Recommended pull-up on BOOTMOD[0/1] pins is 1 kOhm.
- Different boot settings are selected using the BOOTMOD and RCON pins, these are used by BOOTROM to select booting options.
- Refer to AN12422 and AN13456 for more details.
- For production systems, it is recommended that the FUSE\_SEL fuse is blown. In this case, the detailed boot configuration is retrieved from the BOOT\_CFG fuses.
- For development where the FUSE\_SEL is not blown, then the detailed boot configuration is retrieved from GPIO pins. Two options are possible;
- -BOOT\_CFG is read from a serial EEPROM.
- -BOOT\_CFG is read from 32 GPIO RCON pins.
- RCON pins map directly to the BOOT\_CFG1 bits, refer to the S32G3 reference manual and fuse map file attached to the reference manual for the individual bit meanings.

Note: To allow the BOOTMOD and RCON pins to be properly sampled, the application must ensure that the corresponding I/O power domains are sufficiently powered as per the S32G3 data sheet specifications. Failure to do so could lead to an incorrect boot or even to not being able to boot at all.  Refer to the IOMUX file attached to the S32G3 reference manual to see which I/O power domains correspond to these pins.

## 7.2  Boot configuration from serial EEPROM

- If RCON8/PB\_01 is high at the release of RESET\_B, the boot configuration is read from a serial EEPROM. In this case, RCON7/PB\_00 is used for the SDA signal and RCON8/PB\_01 is the SCL signal.
- I2C address for the serial EEPROM must be 0xA0.
- S32G3 reads the first 4 bytes of data (from offset 0x0) from the EEPROM device to retrieve the RCON configuration. The data format is little-endian so RCON7-0 (msb to lsb) is the first byte, then RCON15-8, RCON23-16, and RCON31-24 on the subsequent bytes.
- When using EEPROM for serial RCON information, the EEPROM must be programmed before trying to boot the S32G3.

## 7.3  Boot configuration from GPIO pins

Boot configuration can also be read from the GPIO pins listed in the table below as RESET\_B is released. External pull-up or pull-downs resistors can be used to set the boot configuration in this case.

Table 5. GPIO RCON pins

| Signal name   | Reset config. bit   |
|---------------|---------------------|
| PA_09         | RCON0               |
| PA_10         | RCON1               |
| PA_11         | RCON2               |

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 5. GPIO RCON pins ...continued

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

| Signal name   | Reset config. bit   |
|---------------|---------------------|
| PA_12         | RCON3               |
| PA_13         | RCON4               |
| PA_14         | RCON5               |
| PA_15         | RCON6               |
| PB_00         | RCON7               |
| PB_01         | RCON8               |
| PB_02         | RCON9               |
| PB_03         | RCON10              |
| PB_04         | RCON11              |
| PB_05         | RCON12              |
| PB_06         | RCON13              |
| PB_07         | RCON14              |
| PB_08         | RCON15              |
| PB_09         | RCON16              |
| PB_10         | RCON17              |
| PB_11         | RCON18              |
| PB_12         | RCON19              |
| PB_13         | RCON20              |
| PB_14         | RCON21              |
| PB_15         | RCON22              |
| PC_00         | RCON23              |
| PC_01         | RCON24              |
| PC_02         | RCON25              |
| PC_03         | RCON26              |
| PC_04         | RCON27              |
| PC_05         | RCON28              |
| PC_06         | RCON29              |
| PC_07         | RCON30              |
| PC_08         | RCON31              |

## 8   Debug interface

The S32G3 device includes JTAGC and high-speed Aurora debug interfaces. Refer to the latest revision of AN12530 for schematic and layout guidelines on available debug interfaces.

Note: 'KEEP-OUT" areas may be required by some tools. Consult the preferred tool vendor to determine any area that must remain clear around the debug connector. Some tool vendors may include an extension cable to minimize 'KEEP-OUT' areas but the use of an extension will degrade the signal. In many cases, this

<!-- image -->

User guide S32G3 Hardware Design Guidelines degradation will be insignificant, but it depends on many factors including clock frequency and target board layout.

## 9   Memories

## 9.1  DRAM memory interface

The S32G3 processor can be used with either LPDDR4 memory or DDR3L memory. If the DRAM interface is not used, the interface pins can be left unconnected on board.

## 9.1.1  LPDDR4 memory

The circuit and layout recommendations can vary as per specific memory part and vendor used.

Table 6. LPDDR4 recommendations

|   S.No. | Requirements                                                                                                    | Explanation/supplemental recommendations                                                                         |
|---------|-----------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
|       1 | Connect the DDR0_ZN ball on the processor to 120 Ohm, 1 %resistors to GND.                                      | This is a reference used during Controller output buffer driver calibration.                                     |
|       2 | The ZQ0 and ZQ1 balls on LPDDR4 memory must be connected through 240 Ohm, 1 %resistors to the LPDDR4 VDDQ rail. | These are used during DRAM output buffer driver calibration.                                                     |
|       3 | Place a 10 kOhm, 5 %resistor to ground on the LPDDR4 memory reset signal and connect to DDR0_ RESET_B.          | This ensures adherence to the JEDEC specification until the controller is configured and starts driving the DDR. |
|       4 | Internal VREF generation mode is used.                                                                          | DDR0_VREF must not be used to drive VREF on external DRAMs. DDR0_VREF balls can be left unconnected.             |
|       5 | Check DDR0_A_06-07, DDR0_A_14-17, DDR0_A_19, DDR0_A_26-27, DDR0_A_34-39 are left unconnected.                   | These are unused in LPDDR4 mode.                                                                                 |
|       6 | The architecture for each chip inside the DRAM package must be x16 or x32.                                      | The processor does not support byte mode.                                                                        |
|       7 | The processor ball DDR0_ALERT_NMTEST, must be left unconnected.                                                 | These are observability ports for manufacturing and are not used otherwise.                                      |

## 9.1.1.1  LPDDR4 connection information

The S32G3 processor can be used with multiple memory types. As these memory types have different I/O signals, there are multiple generically named functional balls, depending on the type of memory used. See the following table for the connectivity of these generic balls for LPDDR4.

Table 7. LPDDR4 connectivity

| Ball name   | LPDDR4 function   |
|-------------|-------------------|
| DDR0_A_00   | CKE0_A            |
| DDR0_A_01   | CKE1_A            |
| DDR0_A_02   | CS0_A             |
| DDR0_A_03   | CS1_A             |
| DDR0_A_04   | CK_t_A            |
| DDR0_A_05   | CK_c_A            |

Table 7. LPDDR4 connectivity ...continued

## User guide S32G3 Hardware Design Guidelines

| Ball name         | LPDDR4 function   |
|-------------------|-------------------|
| DDR0_A_06         | -                 |
| DDR0_A_07         | -                 |
| DDR0_A_08         | CA0_A             |
| DDR0_A_09         | CA1_A             |
| DDR0_A_10         | CA2_A             |
| DDR0_A_11         | CA3_A             |
| DDR0_A_12         | CA4_A             |
| DDR0_A_13         | CA5_A             |
| DDR0_A_14         | -                 |
| DDR0_A_15         | -                 |
| DDR0_A_16         | -                 |
| DDR0_A_17         | -                 |
| DDR0_A_19         | -                 |
| DDR0_A_20         | CKE0_B            |
| DDR0_A_21         | CKE1_B            |
| DDR0_A_22         | CS1_B**           |
| DDR0_A_23         | CS0_B**           |
| DDR0_A_24         | CK_t_B            |
| DDR0_A_25         | CK_c_B            |
| DDR0_A_26         | -                 |
| DDR0_A_27         | -                 |
| DDR0_A_28         | CA0_B             |
| DDR0_A_29         | CA1_B             |
| DDR0_A_30         | CA2_B             |
| DDR0_A_31         | CA3_B             |
| DDR0_A_32         | CA4_B             |
| DDR0_A_33         | CA5_B             |
| DDR0_A_34         | -                 |
| DDR0_A_35         | -                 |
| DDR0_A_36         | -                 |
| DDR0_A_37         | -                 |
| DDR0_A_38         | -                 |
| DDR0_A_39         | -                 |
| DDR0_ALERT_NMTEST | -                 |
| DDR0_D_00         | D0                |
| DDR0_D_01         | D1                |

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 7. LPDDR4 connectivity ...continued

## User guide S32G3 Hardware Design Guidelines

| Ball name   | LPDDR4 function   |
|-------------|-------------------|
| DDR0_D_02   | D2                |
| DDR0_D_03   | D3                |
| DDR0_D_04   | D4                |
| DDR0_D_05   | D5                |
| DDR0_D_06   | D6                |
| DDR0_D_07   | D7                |
| DDR0_D_08   | DMI0_A            |
| DDR0_D_09   | DQS0_t_A          |
| DDR0_D_10   | DQS0_c_A          |
| DDR0_D_12   | D8                |
| DDR0_D_13   | D9                |
| DDR0_D_14   | D10               |
| DDR0_D_15   | D11               |
| DDR0_D_16   | D12               |
| DDR0_D_17   | D13               |
| DDR0_D_18   | D14               |
| DDR0_D_19   | D15               |
| DDR0_D_20   | DMI1_A            |
| DDR0_D_21   | DQS1_t_A          |
| DDR0_D_22   | DQS1_c_A          |
| DDR0_D_24   | D16               |
| DDR0_D_25   | D17               |
| DDR0_D_26   | D18               |
| DDR0_D_27   | D19               |
| DDR0_D_28   | D20               |
| DDR0_D_29   | D21               |
| DDR0_D_30   | D22               |
| DDR0_D_31   | D23               |
| DDR0_D_32   | DMI0_B            |
| DDR0_D_33   | DQS0_t_B          |
| DDR0_D_34   | DQS0_c_B          |
| DDR0_D_36   | D24               |
| DDR0_D_37   | D25               |
| DDR0_D_38   | D26               |
| DDR0_D_39   | D27               |
| DDR0_D_40   | D28               |

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 7. LPDDR4 connectivity ...continued

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

| Ball name   | LPDDR4 function   |
|-------------|-------------------|
| DDR0_D_41   | D29               |
| DDR0_D_42   | D30               |
| DDR0_D_43   | D31               |
| DDR0_D_44   | DMI1_B            |
| DDR0_D_45   | DQS1_t_B          |
| DDR0_D_46   | DQS1_c_B          |
| DDR_RESET   | RESET_B           |

## Note:

- Use CS0/CKE0 and leave CS1/CKE1 unconnected for each channel, if there's only one chip select per channel.
- CS0 and CS1 are not in the same sequence in Channel B as in Channel A.

## 9.1.1.2  Data bits and bytes swapping limitations

There could be a requirement of data bit and byte swapping in board design layout analysis, e.g., to match data line lengths on a board.

Consider the below limitations regarding bit and byte swapping for LPDDR4 DRAM usage.

For LPDDR4 system, the signal association is:

- Channel A: Byte0 and Byte1, CA\_A[5:0], CKE0\_A, CKE1\_A, CS0\_A, CS1\_A
- Channel B: Byte2 and Byte3, CA\_B[5:0], CKE0\_B, CKE1\_B, CS0\_B, CS1\_B

Data bits (DQ) swapping is allowed within each byte only.

Data bytes swapping is allowed each within a channel only (Example: byte0 can be swapped with byte1and byte2 can be swapped with byte3).

Note: There is no need to swap the channel CS and CKE signals if byte are swapped in that channel.

## 9.1.1.3  LPDDR4 layout guidelines

The following guidelines must be followed for the LPDDR4 layout.

- It is expected that the Layout engineer and design team already has experience and training with DDR designs at speeds of 1.6 GHz/3200 MT/s.
- It is recommended to route all DQ nets on the same layer.
- If there are DQ net layer transitions, we recommend routing ground vias next to signal vias for good shielding and to maintain constant impedance.
- All trace impedances are referenced to the associated ground plane.
- Do not route over splits and voids.
- It is recommended to design the data bus PCB traces for lower Z\_0. The recommended Z\_0 is 40 Ohm (+/-10%) for single-ended and 80 Ohm (+/-10%) for differential pairs.
- Signal spacing must be at least 2x the distance to the respective reference plane to limit cross-talk influence. Distance between different groups and to differential signals is better kept at least to 3x. Keep plenty of distance to edges of reference planes.
- Keep via count in each signal path to a minimum. Reaching a count of two for a signal could potentially be a problem to be checked, going beyond is very likely a problem.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

- The maximum trace length is highly dependent on several parameters of the system such as trace topologies, transmitter driver strengths, terminations, etc. Accurate post-layout SI/PI simulations are the best way to ensure adequate voltage and timing margins on any system design.
- Make sure in any power simulation that you model loads in a way that no surprises occur on the LPDDR4 later due to fast switching patterns. Power supply impedance does matter. In order of priority: #1 Maximize plane size as it is fastest to supply electrons, #2 use close physically small decoupling caps (which are fast but slower than the plane) to refeed the plane, #3 use bulk caps (which are slow) to refeed the small caps and the plane.
- Keep via count for tightly related signals (e.g., DQ's +DM and Differential pairs) the same. It is usually best to have any needed vias at the beginning and the end of a trace only.
- Lengths of vias must also be considered when performing trace matching calculations.
- Proper GND stitching is strictly needed to switch reference planes. If the signal is switching planes, check if GND needs to be stitched right next to the signal via. Differential signal pairs must switch at the same place and need paired GND stitching on ref plane changes.
- Grouping related signals on the same layer could help routing.
- Byte swapping in the same channel is acceptable. Bit swapping in a byte can also be done. However, to simplify bring up software reuse, it may be good to align to the NXP EVB design when possible. Swaps matter to the software setup and need to be clearly documented or the software team may not be able to enable the LPDDR4 interface effectively.
- The ground plane must provide a low-impedance (low-Z) return path for digital circuits.

Table 8. S32G3 LPDDR4 routing constraints

| LPDDR4 signal (each 16-bit channel)   | Group                    | Pin to DRAM prop delay   | Pin to DRAM prop delay   | Considerations                                                                                                      |
|---------------------------------------|--------------------------|--------------------------|--------------------------|---------------------------------------------------------------------------------------------------------------------|
| LPDDR4 signal (each 16-bit channel)   | Group                    | Min                      | Max                      | Considerations                                                                                                      |
| Ck_t/CK_c                             | Clock                    | Short as possible        | 375 ps                   | Match the true/ complement signals within 1 ps                                                                      |
| CA[5:0]                               | Address/command/ control | CK_t - 10 ps             | CK_t + 10 ps             | Keep max PCB skew of CA/CTL signal group within +/- 10.0 ps of CK_t.                                                |
| CS                                    | Address/command/ control | CK_t - 10 ps             | CK_t + 10 ps             | Keep max PCB skew of CA/CTL signal group within +/- 10.0 ps of CK_t.                                                |
| CKE                                   | Address/command/ control | CK_t - 10 ps             | CK_t + 10 ps             | Keep max PCB skew of CA/CTL signal group within +/- 10.0 ps of CK_t.                                                |
| DQ[7:0]                               | Byte 0                   | CK_t - 50 ps             | CK_t + 50 ps             | Match the true/complement signals of DQS within 1.0 ps. Keep PCB skew of DQS/DQ/DMI signal group within +/- 3.0 ps. |
| DM0                                   | Byte 0                   | CK_t - 50 ps             | CK_t + 50 ps             | Match the true/complement signals of DQS within 1.0 ps. Keep PCB skew of DQS/DQ/DMI signal group within +/- 3.0 ps. |
| DQS0_t/DQS0_c                         | Byte 0                   | CK_t - 50 ps             | CK_t + 50 ps             | Match the true/complement signals of DQS within 1.0 ps. Keep PCB skew of DQS/DQ/DMI signal group within +/- 3.0 ps. |
| DQ[15:8]                              | Byte 1                   | CK_t - 50 ps             | CK_t + 50 ps             | Match the true/complement signals of DQS within 1.0 ps. Keep PCB skew of DQS/DQ/DMI group within +/- 3.0 ps.        |
| DM1                                   | Byte 1                   | CK_t - 50 ps             | CK_t + 50 ps             | Match the true/complement signals of DQS within 1.0 ps. Keep PCB skew of DQS/DQ/DMI group within +/- 3.0 ps.        |
| DQS1_t/DQS1_c                         | Byte 1                   | CK_t - 50 ps             | CK_t + 50 ps             | Match the true/complement signals of DQS within 1.0 ps. Keep PCB skew of DQS/DQ/DMI group within +/- 3.0 ps.        |

## Note:

Additionally, the following JEDEC requirements must be satisfied -JEDEC LPDDR4 SDRAM specification, JESD209-4A.

## 9.1.2  DDR3L memory

The circuit and layout recommendations can vary as per specific memory part and vendor used.

Table 9. DDR3L recommendations

## User guide S32G3 Hardware Design Guidelines

|   S.No. | Recommendations                                                                                  | Explanation/supplemental recommendations                                     |
|---------|--------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|
|       1 | Connect the DDR0_ZN ball on the processor to 120 Ohm, 1 %resistors to GND.                       | This is a reference used during controller output buffer driver calibration. |
|       2 | The ZQ0 and ZQ1 balls on DDR3L memory must be connected through 240 Ohm, to the ground.          | These are used during DRAM output buffer driver calibration.                 |
|       3 | External VREF must be used.                                                                      |                                                                              |
|       4 | Check DDR0_A_03, DDR0_A_19, DDR0_A_22- 23, DDR0_A_27, DDR0_A_32, DDR0_A_39 are left unconnected. | These are unused in DDR3L mode.                                              |
|       5 | The processor ball DDR0_ALERT_NMTEST must be left unconnected.                                   | These are observability ports for manufacturing and are not used otherwise.  |

## 9.1.2.1  DDR3L connection information

The following table mentions the connectivity of generic balls for the DDR3L memory interface.

Table 10. DDR3L connectivity

| Ball name   | DDR3L function   |
|-------------|------------------|
| DDR0_A_00   | CKE0             |
| DDR0_A_01   | CKE1             |
| DDR0_A_02   | CS_N_0           |
| DDR0_A_03   | -                |
| DDR0_A_04   | BA2              |
| DDR0_A_05   | A14              |
| DDR0_A_06   | A15              |
| DDR0_A_07   | A9               |
| DDR0_A_08   | A12              |
| DDR0_A_09   | A11              |
| DDR0_A_10   | A7               |
| DDR0_A_11   | A8               |
| DDR0_A_12   | A6               |
| DDR0_A_13   | A5               |
| DDR0_A_14   | A4               |
| DDR0_A_15   | A3               |
| DDR0_A_16   | CK0_P            |
| DDR0_A_17   | CK0_N            |
| DDR0_A_19   | -                |
| DDR0_A_20   | CK1_P            |
| DDR0_A_21   | CK1_N            |
| DDR0_A_22   | -                |
| DDR0_A_23   | -                |

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 10. DDR3L connectivity ...continued

## User guide S32G3 Hardware Design Guidelines

| Ball name         | DDR3L function   |
|-------------------|------------------|
| DDR0_A_24         | A2               |
| DDR0_A_25         | A1               |
| DDR0_A_26         | BA1              |
| DDR0_A_27         | -                |
| DDR0_A_28         | A13              |
| DDR0_A_29         | BA0              |
| DDR0_A_30         | A10              |
| DDR0_A_31         | A0               |
| DDR0_A_32         | -                |
| DDR0_A_33         | CAS              |
| DDR0_A_34         | WE               |
| DDR0_A_35         | RAS              |
| DDR0_A_36         | ODT              |
| DDR0_A_37         | ODT1             |
| DDR0_A_38         | CS1              |
| DDR0_A_39         | -                |
| DDR0_ALERT_NMTEST | -                |
| DDR0_D_00         | D0               |
| DDR0_D_01         | D1               |
| DDR0_D_02         | D2               |
| DDR0_D_03         | D3               |
| DDR0_D_04         | D4               |
| DDR0_D_05         | D5               |
| DDR0_D_06         | D6               |
| DDR0_D_07         | D7               |
| DDR0_D_08         | DM0              |
| DDR0_D_09         | DQS0_P           |
| DDR0_D_10         | DQS0_N           |
| DDR0_D_12         | D8               |
| DDR0_D_13         | D9               |
| DDR0_D_14         | D10              |
| DDR0_D_15         | D11              |
| DDR0_D_16         | D12              |
| DDR0_D_17         | D13              |
| DDR0_D_18         | D14              |
| DDR0_D_19         | D15              |

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 10. DDR3L connectivity ...continued

## User guide S32G3 Hardware Design Guidelines

| Ball name   | DDR3L function   |
|-------------|------------------|
| DDR0_D_20   | DM1              |
| DDR0_D_21   | DQS1_P           |
| DDR0_D_22   | DQS1_N           |
| DDR0_D_24   | D16              |
| DDR0_D_25   | D17              |
| DDR0_D_26   | D18              |
| DDR0_D_27   | D19              |
| DDR0_D_28   | D20              |
| DDR0_D_29   | D21              |
| DDR0_D_30   | D22              |
| DDR0_D_31   | D23              |
| DDR0_D_32   | DM2              |
| DDR0_D_33   | DQS2_P           |
| DDR0_D_34   | DQS2_N           |
| DDR0_D_36   | D24              |
| DDR0_D_37   | D25              |
| DDR0_D_38   | D26              |
| DDR0_D_39   | D27              |
| DDR0_D_40   | D28              |
| DDR0_D_41   | D29              |
| DDR0_D_42   | D30              |
| DDR0_D_43   | D31              |
| DDR0_D_44   | DM3              |
| DDR0_D_45   | DQS3_P           |
| DDR0_D_46   | DQS3_N           |
| DDR_RESET   | DDR_RESET_B      |

## 9.1.2.2  Data bits and byte swapping limitations

There could be a requirement of data bit and byte swapping in board design layout analysis, for example, to match data line lengths on a board.

Consider the below limitations regarding bit and byte swapping for DDR3L DRAM usage:

- Data bits (DQ) swapping is allowed within each byte only.
- There are two x16 channels to make x32 configurations and each channel has two byte. Byte-swapping is allowed within a channel only.

## 9.1.2.3  DDR3L layout guidelines

The following guidelines must be followed for the DDR3L layout:

© 2024 NXP B.V. All rights reserved.

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

- VREF\_DDR to be routed as a thick trace and not as a plane.
- CK/CK# must be routed as a point-to-point from the controller to DRAM and must also be length matched for both 16-bit DRAMs. The recommended Z0 is 50 Ohm for single-ended and 100 Ohm for differential.
- ADD/CMD must be routed with T (star) topology terminated with 40 Ohm with VTT at T- point.
- For better signal integrity, ADD/CMD must be routed at 40 Ohm before VTT termination and at 50 Ohm after VTT-termination. T-point must be kept as close to the memory.
- Recommends designing data bus PCB traces for lower Z0. The recommended Z0 would be 50 Ohm (+/-10%) for single-ended and 100 Ohm (+/- 10%) for differential pairs.

## 9.2  QSPI

The QSPI (QuadSPI) module acts as an interface to a single or two external serial flash devices (via QSPI A and QSPI B ports), each with up to eight bidirectional data lines.

Either QSPI A or B can be selected to connect to the flash boot device. QSPI\_A only supports 1.8 V operation, whereas QSPI\_B can be powered to either 1.8 V or 3.3 V. The QSPI\_B interface shares the IO pins with the SDHC interface.

For 1.8 V QSPI flash devices, care must be taken over the reset signal to the flash device. If RESET\_B is used, then a suitable level shifter needs to be used as these are 3.3 V domain signals.

## 9.2.1  Recommendations for QSPI interface

Table 11. QSPI recommendations

|   S.No. | Recommendations                                                                                                                           | Explanation/supplemental recommendations                                                     |
|---------|-------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
|       1 | QSPI CS signal to be pulled up with 2 -10 kOhm resistor value.                                                                            | Chip select is an active low signal.                                                         |
|       2 | QSPI SCK signal can be connected with a series termination.                                                                               | Termination depends on the length of the clock line from the processor to the QSPI memory.   |
|       3 | QSPI reset signal can be connected with system reset signal and provide a pull-up to this pin for the reset to be de-asserted by default. | For QSPI to be available in default mode after every system reset, refer to the below point. |
|       4 | QSPI selected must have "SDR 1-bit mode for Initial Read".                                                                                | BOOTROM supports this mode for initial read.                                                 |
|       5 | S32G3 supports a differential clock also for the QSPI interface.                                                                          |                                                                                              |

Table 12. QSPI connections

| Signal Name        | Recommendation                             | Explanation                                                                  |
|--------------------|--------------------------------------------|------------------------------------------------------------------------------|
| QSPI_DATA_A/B[0-7] | Connect to data lines on NOR flash device. | Single, dual, quad, and octal NOR flash including hyper-flash are supported. |
| QSPI_DQS_A/B       | Connect to data strobe on NOR flash.       |                                                                              |
| QSPI_INTA/B        | Connect to flash ECC error-out signal.     |                                                                              |
| QSPI_CK_A/B        | Connect to the clock input on NOR Flash.   | Main clock signal to flash.                                                  |

Table 12. QSPI connections ...continued

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

| Signal Name    | Recommendation                                   | Explanation    |
|----------------|--------------------------------------------------|----------------|
| QSPI_CK_A/B_b  | Connect to inverted clock input for Hyper-flash. |                |
| QSPI_CK_2A/B   | Optionally connect to CK_2, if supported.        | Shifted clock. |
| QSPI_CK_2A/B_b | Optionally connect to CK_2b, if supported.       | Inverted CK_2. |
| QSPI_CS_A/B0   | Connect to chip select.                          |                |
| QSPI_CS_A/B1   | Optional 2nd chip select.                        |                |

## 9.2.2  QSPI layout guidelines

## 9.2.2.1  Maximum total length

- The absolute maximum total length of DQ signals (including RWDS) with respect to its reference plane is defined by the total load capacitance.
- Total load capacitance must be &lt; 15 pf.
- Total load capacitance includes the following:
- -Total line length capacitance (~3.3 pf/inch with FR4 assumption).
- -Max package pin capacitance of the controller package.
- -Any parasitic capacitance associated with vias, etc.

## 9.2.2.2  Length matching

Length matching from the QSPI flash package pin to the signal pin of the controller must be +/- 50 mils.

## 10   Communication Peripherals

## 10.1  Ethernet recommendations

Table 13. Ethernet recommendations

|   S.No. | Recommendations                                                                                                                    | Explanation/supplemental recommendations                                                                 |
|---------|------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------|
|       1 | Selection of PHY depends on the MII interface being used and must meet timing and electrical requirements as per S32G3 data sheet. | -                                                                                                        |
|       2 | All Tx lines either from MAC or PHY must have provision to add series termination.                                                 | This is done for impedance mismatching and avoiding signal integrity issues.                             |
|       3 | S32G3 provides programmable drive strength options to match the impedance of data lines.                                           | In this case, there may not be a need of termination resistor on MAC Tx lines.                           |
|       4 | PHY reset pin connected to RESET_B pin from S32G3.                                                                                 | This RESET_B signal from S32G3 can be connected to multiple peripherals to serve as system reset signal. |
|       5 | Clocking in the RGMII interface must be source- synchronous and must also have the provision of series termination.                | The clock speed for 1G operation must be 125 MHz and for 10/100 must be 2.5/25 MHz respectively.         |
|       6 | Reference clock source                                                                                                             | RGMII requires the clock source tolerance to be 50 ppm maximum. As PLL is the only                       |

UG\_S32G3

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

Table 13. Ethernet recommendations ...continued

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

| S.No.                | Recommendations                                                                                                                 | Explanation/supplemental recommendations                                                                                           |
|----------------------|---------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------|
|                      | Use an appropriate clock source as per the MII protocol requirement.                                                            | recommended clock source for RGMII_TX_CLK, hence the crystal being used to generate the system clock must meet this specification. |
| 7                    | All protocols requiring an external clock must ensure that the clock is shut down or disconnected before entering Standby mode. |                                                                                                                                    |
| Management Operation | Management Operation                                                                                                            | Management Operation                                                                                                               |
| 8                    | MDIO pin - pull-up through a 2-10 kOhm resistor to IO voltage of PHY.                                                           | MDIO pin is configured as open drain.                                                                                              |

## 10.1.1  RGMII signal routing requirements

- Tx Pair and Rx pair must be routed in a single layer.
- Air gap between signals must be 2 W (width).
- Ninety degrees trace corners must be avoided.
- Max length to be achieved not more than three inches from MAC to PHY.
- The purpose of the series termination is to reduce reflections and to improve the signal quality
- Try to keep spacing between intergroup and intragroup signals more than 3W (width) spacing.
- All TX, TXCLK, and RX, RXCLK signals group must be matched with +/- 50 mils tolerance.
- The RJ45 is recommended to have metal shielding that connects to chassis ground to reduce EMI emission.
- MDI pairs must be routed close together in parallel to reduce EMI emission and common mode noise.
- Consider the required Clock to Data skew as per the RGMII specification. Refer to S32G3 data sheet for timing delays.

## 10.2  SerDes communication

S32G3 has two SerDes instances, each SerDes instance has a mux option between PCIe and SGMII. The following mux option can be chosen on the SerDes channels.

<!-- image -->

© 2024 NXP B.V. All rights reserved.

## 10.2.1  PCIe recommendation

Table 14. PCIe recommendation

|   S.No. | Recommendations                                                                                                                                                                                                                                                                                     | Explanation/supplemental recommendations                                                                                                                     |
|---------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
|       1 | Reference clock source Use an appropriate PCIe reference clock generator.                                                                                                                                                                                                                           | An external reference clock is required which meets PCIe Gen3 clock specifications. The internal reference clock can be used up to PCIe Gen2 speeds(5 Gbps). |
|       2 | AC coupling of transmission lines The differential transmitters from the processor must be AC coupled. Use a 0.22 μf cap on both the PCIE_TXP and PCIE_TXN outputs.                                                                                                                                 | To ensure PCIe specification compliance, ac coupling is required at each transmitter. The receiver must be DC coupled.                                       |
|       3 | Reference resistor recommendations The PCIEx_REXT ball must be connected to the ground through a 200 Ohm, 1% resistor.                                                                                                                                                                              | The impedance calibration process requires the connection of this reference resistor.                                                                        |
|       4 | PCIe Jitter compliance For PCIe Gen3 operation, an external clock source is needed to meet the PCIe jitter requirements for 8 Gbps operation. In all other scenarios (i.e., PCIe Gen1/Gen2, SGMII 1G/2.5G), either the internal PLL reference clock source or an external clock source can be used. | Refer to reference manual section: Clocking-> Communication modules -> SerDes.                                                                               |

## 10.2.2  SGMII recommendation

Table 15. SGMII recommendations

|   S.No. | Recommendations                                                                                                                                                                             | Explanation/Supplemental Recommendations                                                                         |
|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
|       1 | Reference Clock Source Use an appropriate SGMII reference clock generator.                                                                                                                  | Internal reference clock SERDES_REF_CLK, when configured appropriately per Figure 9, can also be used for SGMII. |
|       2 | AC Coupling of transmission lines Check AC coupling capacitors requirements as per connected SGMII PHY recommendations on Transmit and Receive pairs. Generally, a value of 0.1 µf is used. |                                                                                                                  |
|       3 | Reference resistor recommendations The PCIEx_REXT ball must be connected to the ground through a 200 Ohm, 1% resistor.                                                                      | The impedance calibration process requires connection of this reference resistor.                                |

## 10.2.3  PCIe/SGMII unused lanes recommendations

You must configure unused lanes as shown in the following table with the appropriate software settings applied to disable the SerDes PHY or lane. Dedicated supplies must remain actively powered.

Table 16. Signal configuration for unused PHY or lane

| Signal                  | When using only one SerDes lane   | When not using the PHY at all   |
|-------------------------|-----------------------------------|---------------------------------|
| PCI_TXn_P and PCI_TXn_N | Float                             | Float                           |
| PCI_RXn_P and PCI_RXn_N | Tie low                           | Float or Tie low                |
| PCI_CLK_P and PCI_CLK_N | -                                 | Tie low                         |
| PCI_RESREF              | -                                 | Float                           |

© 2024 NXP B.V. All rights reserved.

User guide S32G3 Hardware Design Guidelines

## 10.2.4  PCIe/SGMII design recommendations

S32G3 has two PCIe interfaces. Each has a pair of pins named PCIE n \_CLK\_P/N. These pins are used to feed a reference clock to the PHY from external clock source. These are input-only pins and have no capability to output clock. Do not connect them to PCIe connector or PCIe device.

## 10.2.5  PCIe/SerDes signal layout requirements

The following requirements must be followed for PCIe/SerDes layout.

- Route traces over continuous planes (power and ground).
- -They must not pass over any power/GND plane slots or anti-etch.
- -When placing connectors, make sure the ground plane clear-outs around each pin have ground continuity between all pins.
- PCIE\_REXT trace length between the pin and the resistor must be minimized.
- Do not route differential pair traces under oscillators or parallel to clock traces and/or data buses.
- No layer interchange in the signal connectivity.
- Diff pair routes must be kept as short as possible.
- Route all differential pairs with 100 Ohm impedance.
- No variation in trace width or spacing must be done on the board during routing of signals.
- Maintain the skew matching between DP and DM, and match the overall differential length difference to less than 5 mils.
- Vias must not be used during routing. If vias cannot be eliminated, then use the same type and number of via across each differential pair and across all pairs in an interface.
- Add on for the GND vias along with the signal layer changing vias for the differential pairs located at the same distance from each signal via.

## 10.3  USBOTG

USBOTG is a USB 2.0-compliant serial interface engine for implementing a USB interface. The registers and data structures are based on the Enhanced Host Controller Interface specification for universal serial bus (EHCI) from Intel Corporation. This module can act as a host, a device, or an On-The-Go (OTG) negotiable host or device on the USB bus.

The USBOTG controller interfaces with the processor's core. The controller is configured to support host or device operations under firmware control. The ULPI (UTMI Low Pin Interface) interface supports HS, full-speed (FS), and low-speed (LS) applications.

Table 17. USBOTG recommendations

|   S.No. | Recommendations                                                                                                                            | Explanation/supplemental recommendations                                    |
|---------|--------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
|       1 | USB_DIR pin Weak Pull-down is required on the DIR pin of ULPI interface.                                                                   |                                                                             |
|       2 | ULPI Clock Signal (ULPI_CLK) Have a series termination placeholder for this signal.                                                        | ULPI PHY supplies a 60 MHz USB reference clock input to the USB Controller. |
|       3 | ULPI_NXT PHY asserts ULPI_NXT to throttle data. When USB port sends data to the PHY, ULPI_NXT indicates when PHY accepts the current byte. | It is synchronous to ULPI_CLK.                                              |
|       4 | ULPI_STP Asserted-USB asserts this signal for one clock cycle to stop the data stream currently on the bus.                                | It is synchronous to ULPI_CLK.                                              |

© 2024 NXP B.V. All rights reserved.

User guide S32G3 Hardware Design Guidelines

Table 17. USBOTG recommendations ...continued

|   S.No. | Recommendations                                                                                                                                                        | Explanation/supplemental recommendations   |
|---------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------|
|       5 | ULPI_DATA [7:0] Data bit n is bit n of the 8-bit, bi-directional data bus used to carry USB, register, and interrupt data between the USB port controller and the PHY. | It is synchronous to ULPI_CLK.             |

## 11   Input/output pins

The following table summarizes the types of pins/pads available on S32G3. Information on the individual pad types and signal multiplexing is available in the S32G3 reference manual and data sheet.

Table 18. S32G3 pad types

| Pad type                           | Abbreviation   | Description                                                                                       |
|------------------------------------|----------------|---------------------------------------------------------------------------------------------------|
| 3.3 V GPIO                         | 33GPIO         | Standard 3.3 V general purpose I/O pad.                                                           |
| 3.3 V GPI                          | 33GPI          | Standard 3.3 V general purpose Input only pad.                                                    |
| 1.8 V GPIO                         | 18GPIO         | Standard 1.8 V general purpose I/O pad. These have GPIO functionality or QSPI functionality only. |
| Selectable 1.8 V / 3.3 V Fast GPIO | 1833Fast       | These pads can operate either at 1.8 V or 3.3 V levels.                                           |
| Analog Pad 1                       | ANALOG         | Analog only pad which is used for the ADC inputs, or other analog functionality on the device.    |
| LVDS Pad 1                         | AUR_LVDS       | High speed pads for differential LVDS interfaces such as Aurora.                                  |
| PCIe Pad 1                         | PCIE_PAD       | High speed pads for PCIe signals only.                                                            |
| LPDDR4 pad 1                       | LPDDR4         | Pads used for DRAM (LPDDR4/DDR3L) interface.                                                      |

Each of these pad types (except single purpose pins without special properties that need to be controlled) have programmable features that are controlled in a signal configuration register (MSCR). All pins with more than a single dedicated function on the device have an MSCR. MSCR controls the function, direction, and other capabilities of the pin, which provides great flexibility but means that some software configuration of the pin is required to use a specific functionality.

## 11.1  Understanding pin multiplexing

Each pin (or pad) of the S32G3 can be used for multiple functions. Software can select which function is available on the ball. For detailed info on all pads, refer to IOMUX file attached with the S32G3 Reference Manual. Figure below shows a snapshot from the IOMUX file.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

<!-- image -->

## 11.2  Pad slew rate

The slow-, fast- pads, implement a slew rate control (SRC) selection in the Pad Configuration Register (MSCR). Slew rate is used to slow down the time taken by the signal to switch from a low to a high or from a high to a low.

For more details, see the S32G3 reference manual and IOMux file attached to the reference manual.

## 11.3  Injection current

All pins implement protection diodes that protect against electrostatic discharge (ESD). In some applications, both digital and analog pins may be connected to voltages that are higher than the operating voltage of the device pin; e.g., due to supply sequencing constraints between different components or interfaces on a board. In these cases, it should be noted that the datasheet supports current injection so long as the part is powered off. However, once the part is powered-up, it is the users responsibility to ensure that the voltage appearing at these pins does not exceed the allowed operating limits. Unlike earlier technology generations, the user cannot depend on the pin ESD protection diodes to keep the voltage at the pin within a safe level as per the abs max or operating condition values.

Additional circuits on the pins can be enabled only by fast ESD transients. In normal operation, these circuits have no effect on the pin characteristics and are triggered by fast high-voltage transients. To prevent turning on these circuits during normal power-up sequences, the ramp rate of the power supplies the limits as specified in the device datasheet.

## 11.4  Handling unused pins

- Leave unused GPIO pins unconnected, disable the input and output buffers (SIUL2 MSCR bits OBE and IBE =0), and enable the internal pulls (PUE = 1).
- CLKOUT\_P and CLKOUT\_N, POST\_AN pins are NXP internal test pins, must be left open
- TMU\_ANODE and TMU\_CATHODE: The preferred connection for these test inputs is to tie to VSS. If an existing hardware cannot support this recommendation then the pins can be left unconnected.
- All unused ADC channels must be pulled down to GND
- Test pin must always be tied to VSS.

All information provided in this document is subject to legal disclaimers.

© 2024 NXP B.V. All rights reserved.

## 11.5  S32G3 model support

Following models are available for S32G3 from NXP:

- IBIS model
- BSDL model
- DDR S-parameters model

## 12   S32G3 thermal considerations

Thermal management is a very complex discipline with numerous variables that need to be considered. In order to determine whether the system is capable of stable operation (no thermal runaways) in the given use case or to identify potentially overlooked issues, thermal simulations must be performed.

NXP can provide Mentor FloTHERM/Ansys Icepak simulation models for S32G3 series processor family and strongly recommends users to perform thermal simulations using these models in their form factor designs and specific use cases to get a holistic system thermal design and identify possible thermal bottlenecks. Thermal simulations become increasingly important in small form factor designs and operation in high ambient temperatures.

Heatsink considerations:

The most frequently employed passive cooling device is the heat sink. It is a mass of thermally conductive metal which is physically mounted to a heat generating component like S32G3. Adding a heat sink to the processor is an excellent method to dissipate heat. Commonly used heatsink materials are copper and aluminum.

Design considerations (addition of heatsink):

- Ensure adequate spacing around the device to accommodate the heatsink.
- Avoid routing circuitry in the area where mounting holes will be placed, try to use heatsink with no or small size mounting holes.
- Consider also the bottom side of the PCB where space for support may be required.
- Backing plate may be necessary on the back side of the printed circuit board opposite the flip-chip device to prevent board warpage.
- Ensure that temperature sensitive components are not placed below the heatsink to prevent overheating and damage.
- Ensure the orientation and spacing of the fins cause the heat to move as quickly as possible from the heat source.

## 12.1  Internal package conduction resistance

For the package, the intrinsic internal conduction thermal resistance paths are as follows:

- The die junction-to-case thermal resistance
- The die junction-to-board thermal resistance

The following figure shows the primary heat transfer paths for a package with an attached heat sink mounted to a PCB.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

<!-- image -->

## User guide S32G3 Hardware Design Guidelines

<!-- image -->

The heat sink removes most of the heat from the device. Heat generated on the active side of the chip is conducted through the silicon and through the heat sink attach material (or thermal interface material), and finally to the heat sink.

## 13   S32G3 layout and routing recommendations

## 13.1  General design recommendations

When using the Allegro design tool, the schematic symbol and PCB footprint created by NXP is recommended. When not using the Allegro tool, use the Allegro footprint import feature supported by many tools. If import is not possible, create the footprint per the package dimensions outlined in the S32G3 data sheet.

## 13.2  Stack-up recommendations

Due to the number of balls on the S32G3 processor in the package, a minimum 8-layer PCB stack-up is recommended. Of the 8-layers on the PCB, a sufficient number of layers need to be dedicated to power on routing.

The constraints for the trace width depends on factors such as the board stack-up and associated dielectric and copper thickness, required impedance and required current for power traces.

The stack-up also determines the constraints for routing and spacing. Consider the following requirements when designing the stack-up and selecting board material:

- Board stack-up is critical for high-speed signal quality.
- Preplanning impedance of critical traces is required.
- High-speed signals must have reference planes on adjacent layers to minimize crosstalk.

## 13.3  High-speed routing recommendations

The following lists the general routing guidelines for high-speed signals (LPDDR4, DDR3, PCIe/SGMII, RGMII, QSPI, etc.).

© 2024 NXP B.V. All rights reserved.

User guide S32G3 Hardware Design Guidelines

The propagation delay and the impedance control must match to ensure the correct communication with the devices.

- Route them with higher priority than low-speed signals.
- Controlled impedance of the traces must be used.
- High-speed signals must not cross gaps in the reference plane.
- Avoid creating slots, voids and splits in reference planes. Review via placements to ensure that they don't inadvertently create splits/voids (i.e. space via's out to eliminate this possibility).
- Ensure that ground stitching vias are present within very small distance from signal layer transition vias on high-speed signals when transitioning between different reference ground planes.
- A solid GND plane must be directly under crystals, associated to components and traces.
- Do not cross-split reference planes during the routing.
- Clocks or strobes that are on the same layer need at least 2.5x height from reference plane spacing from adjacent traces to reduce crosstalk.
- All synchronous interfaces must have appropriate bus length matching and relative clock length control.

## 13.4  PCB material parameters (affecting high frequency operation)

Dielectric constant - Dielectric constant is a measure of the charge retention capacity of a medium. The dielectric constant varies with frequency and generally decreases as frequency increases. Some materials have less of a change in relative permittivity than others. Materials suitable for high frequency applications are those whose dielectric constant remains relatively the same over a wide frequency range-from a few 100 MHz to several GHz.

Loss tangent - The dielectric loss tangent is defined by the angle between the capacitor's impedance vector and the negative reactive axis. It determines the loss of the medium. Similar to dielectric constant, low loss tangents result in a "fast" substrate while large loss tangents result in a "slow" substrate.

## 13.5  Impact on signal integrity due to PCB material parameters

Signal power loss - The lower a material's loss tangent, the less power lost. Tan δ of most PCB materials range from 0.02 for the most commonly used materials to 0.001 for the very low-loss high-end materials. It also varies with frequency, increasing as frequency increases. It is a very important parameter for analog signals, as it determines the degree of signal attenuation and thus affects the signal to noise ratio at various points along signal traces. Meaning bad eye diagrams, with less margins.

Propagation Delay - In general, low dielectric constants (i.e., polypropylene) result in a "fast" substrate while large dielectric constants (i.e., Alumina) result in a "slow" substrate. Timing - setup margins are impacted.

## 13.6  Optimum value of PCB material parameters to support microwave and radio frequency range signals

Loss tangent - Generally, FR4 material have dissipation factor in the range of 0.02 - 0.01. High-speed material have dissipation factor in the range of 0.009 - 0.002.

Dielectric constant - Generally, FR4 material have dielectric constant in the range from 4.2 - 4.5. High-speed FR4 material (high resin) have dielectric constant is in the range from 3.7 - 3.3.

## 13.7  Layout practices to reduce impact on signal integrity due to PCB material

Keep the length of the traces as small as possible to reduce the dielectric loss of the path to the minimum. This help to retain signal levels proper.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

Keep high-speed signal layer closely coupled with its adjacent ground layer to have the minimum return length as shown in the following figure.

<!-- image -->

Keep ground layer tightly coupled with power layer to maintain proper decoupling.

This also helps when signal is routed with returns between power and ground planes, return energy will transfer as shown in the following figure, even though a change of reference plane types should be avoided if at all possible:

<!-- image -->

Route high-speed interface as microstrip and not stripline because top and bottom layers have lower propagation delays in comparison to internal layers.

It is very important to check if any impact is seen on signal integrity due to PCB material parameters change.

## 14   Avoiding board bring-up problems

This chapter introduces how to avoid mistakes when bringing up a board for the first time. The recommendations below consist of basic techniques for detecting board issues and preventing/locating the three issues encountered power, clocks, and reset.

## 14.1  Avoiding power pitfalls current

Excessive current can damage the board. Use a current-limiting laboratory supply set to the expected main current draw (at most). Monitor the main supply current with an ammeter when powering up the board for the first time. You can use the supply's internal ammeter if there is. By monitoring the main supply current and controlling the current limit, any excessive current can be detected before permanent damage occurs.

Before the board test, you can ohm out the board power rails to the ground to verify that there are no short circuits. Then, you can power on the board and there will not be any damage to the board and/or components.

## 14.2  Avoiding power pitfalls voltage

To avoid incorrect voltage rails, create a basic table called a voltage report prior to board bring up/testing. The table helps to validate that all the supplies are reaching the expected levels.

To create a voltage report, list the following:

- Board voltage sources.
- Default power-up values for the board voltage sources.
- Best location on the board to measure the voltage level of each supply.

Determine the best measurement location for each power supply to avoid a large voltage drop (IR drop) on the board. The drop causes inaccurate voltage values. The following guidelines help produce the best voltage measurements:

- Measure closest to the load (in the case of the S32G3 processor).
- Make two measurements, the first after initial board power-up and the second while running a heavy use-case that stresses the S32G3 processor.

Ensure that the S32G3 power supply meets the DC electrical specifications as listed in the S32G3 data sheet.

## 14.3  Checking for clock pitfalls

Problems with the external clocks are another board bring-up issue. Ensure that all the clock sources are running as expected.

The XTAL/EXTAL pins and the internal fast IRC clock (48 MHz) are the main clock sources for S32G3. When checking crystal frequencies, use an active probe to avoid excessive loading. A passive probe may inhibit the crystal oscillator from starting up.

## 14.4  Avoiding reset pitfalls

Follow these guidelines to ensure that you are booting correctly.

- During initial power-on while asserting the POR\_B reset signal, ensure that crystal or oscillator EXTAL/XTAL is active before releasing POR\_B.
- Follow the recommended power-up sequence specified in S32G3 data sheet.
- Ensure the POR\_B signal remains asserted (low) until all voltage rails are within specification.

For a more detailed description about the boot modes, see the system boot chapter in the S32G3 reference manual.

## 15   Schematic review

Refer to the attached "S32G3\_Schematic\_Checklist.xlsx" for a final schematic review. The sheet summarizes all the requirements and must be used as a final check. In case a schematic review is requested from NXP, the attached sheet filled with all the inputs must be provided.

## 16   Frequently asked questions

## Ques: Can we use the S32G2 based hardware for evaluating S32G3?

Ans: Assuming that the peripheral usage is the same, S32G2 based hardware can be used for evaluating S32G3 in typical lab conditions. This setup can be used for development activities till the time S32G3 based hardware is not available. S32G3 has a considerably higher power consumption which cannot be fulfilled by

User guide S32G3 Hardware Design Guidelines

<!-- image -->

User guide S32G3 Hardware Design Guidelines

VR5510 alone at higher temperatures. So, power stress tests (including any high temperature tests) for S32G3 must not be run on a S32G2 based hardware. Refer to Hardware changes from S32G2 .

## Ques: Can we make hardware aligned with S32G3 (keeping the VR5510 and PF53) and use it for S32G2?

Ans: Assuming that the peripheral usage is the same. S32G2 uses SVS (refer to S32G2 hardware design guidelines) to optimize power consumption. S32G2 software needs to read DIE\_PROCESS bits and adjust the BUCK1/2\_VR5510 output. S32G3 with VR5510 and PF53 does not require SVS support. When using S32G2 on a hardware with VR5510 and PF53, SVS cannot be supported due to safety implications. In this case, the peak power consumption of S32G2 may go beyond the one specified in S32G2 Data Sheet.

## Ques: Do both power schemes (only VR5510 and VR5510 with PF53) use the same VR5510 configuration?

Ans: No, the OTP configurations for VR5510 are different. These are identified by complete part number of VR5510 PMIC. For example, S32G-VNP-EVB uses PVR5510AMMA4ES while S32G-VNP-EVB3 uses PVR5510AMDALES in combination with PF5300.

Ques: Is SVS handling not required in S32G3?

Ans: No, the user application does not need to take care of SVS.

## Ques: Can we reduce the recommended capacitors values in a custom design?

Ans: The capacitor values recommended in Decoupling/Bypass circuit consider the peak power consumption of the silicon. The decap values are recommended keeping in mind any sudden power surge requirement from the application. In case any of the above conditions is not a requirement for customer, they can consider changing the capacitor value. However, this is then solely the responsibility of user and NXP cannot provide any support on issues arising due to these changes.

## Ques: Can we remove the recommended ferrite beads in a custom design?

Ans: The ferrite beads are mandatory to eliminate AC noise from the supplies. Failures due to deviation are responsibility of application developer.

## Ques: How can NXP help in the schematic development process?

Ans: NXP FAE and AE team can help in review of S32G3 specific sections. The prerequisite is to fill in the attached 'S32G3\_Schematic\_Checklist.xlsx'. User can also use the collaterals associated with reference design boards from NXP for further alignment.

## Ques: Does NXP recommend any specific crystal, or how can a user select crystal?

Ans: NXP validation boards use NX5032GA and NX3225GA. A user application may use any other crystal that meets the specification provided in section ' Peripheral specifications-&gt; Clock and PLL interfaces -&gt; FXOSC ' in the S32G3 Data Sheet.

## Ques: If a certain peripheral is not used in an application, can the corresponding supply be NC (not connected)?

Ans: All VDD pads need to be powered to operating levels even if a peripheral is not being used. Refer to Power Supply.

## Ques: Use of MEMRESET and CKE signals to prevent overshoot/undershoot conditions?

Ans: Ensure proper termination is used for MEMRESET and CKE signals to prevent any excessive overshoot/ undershoot. Such termination must also allow the minimum slew rate to be met at the DRAM.

## 17   Revision history

## Table 19. Revsion history

| Document ID     | Release date    | Changes                                                                                                                                                                                                                                           |
|-----------------|-----------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| UG_S32G3 v. 3.1 | 19 January 2024 | • Updated the value from '20' to '25' under column 20 MHz - 100 MHz (max mOhm) in Table 3 • Updated S32G3_ Schematic_checklist.xls.                                                                                                               |
| UG_S32G3 v. 3   | March 2023      | • Removed Company Confidential footer.                                                                                                                                                                                                            |
| UG_S32G3 v. 2.1 | December 2022   | • Added information on MEMRESET and CKE signals in Frequently asked questions.                                                                                                                                                                    |
| UG_S32G3 v. 2   | June 2022       | • Editorial updates throughout the document • Updated Injection current • Updated Hardware Changes from S32G2 • LPDDR4 function field in Linktext-Table_ aligned with S32G2HDG • Decoupling/Bypass circuit is now shown as mandatory requirement. |
| UG_S32G3 v. 1   | November 2021   | • Attachment 'S32G3_schematic_checklist.xlsx' corrected • Added additional note to Table1 • Pull condition added to BOOTMOD pins • More FAQs added                                                                                                |
| UG_S32G3 v. 0   | July 2021       | Initial release                                                                                                                                                                                                                                   |

## User guide S32G3 Hardware Design Guidelines

## 18   Legal information

## 18.1  Definitions

Draft - A draft status on a document indicates that the content is still under internal review and subject to formal approval, which may result in modifications or additions. NXP Semiconductors does not give any representations or warranties as to the accuracy or completeness of information included in a draft version of a document and shall have no liability for the consequences of use of such information.

## 18.2  Disclaimers

Limited warranty and liability - Information in this document is believed to be accurate and reliable. However, NXP Semiconductors does not give any representations or warranties, expressed or implied, as to the accuracy or completeness of such information and shall have no liability for the consequences of use of such information. NXP Semiconductors takes no responsibility for the content in this document if provided by an information source outside of NXP Semiconductors.

In no event shall NXP Semiconductors be liable for any indirect, incidental, punitive, special or consequential damages (including - without limitation lost profits, lost savings, business interruption, costs related to the removal or replacement of any products or rework charges) whether or not such damages are based on tort (including negligence), warranty, breach of contract or any other legal theory.

Notwithstanding any damages that customer might incur for any reason whatsoever, NXP Semiconductors' aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms and conditions of commercial sale of NXP Semiconductors.

Right to make changes - NXP Semiconductors reserves the right to make changes to information published in this document, including without limitation specifications and product descriptions, at any time and without notice. This document supersedes and replaces all information supplied prior to the publication hereof.

Applications - Applications that are described herein for any of these products are for illustrative purposes only. NXP Semiconductors makes no representation or warranty that such applications will be suitable for the specified use without further testing or modification.

Customers are responsible for the design and operation of their applications and products using NXP Semiconductors products, and NXP Semiconductors accepts no liability for any assistance with applications or customer product design. It is customer's sole responsibility to determine whether the NXP Semiconductors product is suitable and fit for the customer's applications and products planned, as well as for the planned application and use of customer's third party customer(s). Customers should provide appropriate design and operating safeguards to minimize the risks associated with their applications and products.

NXP Semiconductors does not accept any liability related to any default, damage, costs or problem which is based on any weakness or default in the customer's applications or products, or the application or use by customer's third party customer(s). Customer is responsible for doing all necessary testing for the customer's applications and products using NXP Semiconductors products in order to avoid a default of the applications and the products or of the application or use by customer's third party customer(s). NXP does not accept any liability in this respect.

<!-- image -->

User guide S32G3 Hardware Design Guidelines

Terms and conditions of commercial sale - NXP Semiconductors products are sold subject to the general terms and conditions of commercial sale, as published at http://www.nxp.com/profile/terms, unless otherwise agreed in a valid written individual agreement. In case an individual agreement is concluded only the terms and conditions of the respective agreement shall apply. NXP Semiconductors hereby expressly objects to applying the customer's general terms and conditions with regard to the purchase of NXP Semiconductors products by customer.

Suitability for use in automotive applications - This NXP product has been qualified for use in automotive applications. If this product is used by customer in the development of, or for incorporation into, products or services (a) used in safety critical applications or (b) in which failure could lead to death, personal injury, or severe physical or environmental damage (such products and services hereinafter referred to as 'Critical Applications'), then customer makes the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, safety, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP. As such, customer assumes all risk related to use of any products in Critical Applications and NXP and its suppliers shall not be liable for any such use by customer. Accordingly, customer will indemnify and hold NXP harmless from any claims, liabilities, damages and associated costs and expenses (including attorneys' fees) that NXP may incur related to customer's incorporation of any product in a Critical Application.

Export control - This document as well as the item(s) described herein may be subject to export control regulations. Export might require a prior authorization from competent authorities.

Translations - A non-English (translated) version of a document, including the legal information in that document, is for reference only. The English version shall prevail in case of any discrepancy between the translated and English versions.

Security - Customer understands that all NXP products may be subject to unidentified vulnerabilities or may support established security standards or specifications with known limitations. Customer is responsible for the design and operation of its applications and products throughout their lifecycles to reduce the effect of these vulnerabilities on customer's applications and products. Customer's responsibility also extends to other open and/or proprietary technologies supported by NXP products for use in customer's applications. NXP accepts no liability for any vulnerability. Customer should regularly check security updates from NXP and follow up appropriately. Customer shall select products with security features that best meet rules, regulations, and standards of the intended application and make the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP.

NXP has a Product Security Incident Response Team (PSIRT) (reachable at PSIRT@nxp.com) that manages the investigation, reporting, and solution release to security vulnerabilities of NXP products.

NXP B.V. - NXP B.V. is not an operating company and it does not distribute or sell products.

## 18.3  Trademarks

Notice: All referenced brands, product names, service names, and trademarks are the property of their respective owners.

NXP - wordmark and logo are trademarks of NXP B.V.

## Contents

| 1             | Introduction .........................................................                                                  | 2                                                 | 10.1.1    | RGMII signal routing requirements ..................28                                                         |                                          |
|---------------|-------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------|------------------------------------------|
| 1.1           | Acronyms and definition ....................................                                                            | 2                                                 | 10.2      | SerDes communication ....................................28                                                    |                                          |
| 1.2           | Package information ..........................................3                                                         |                                                   | 10.2.1    | PCIe recommendation .....................................29                                                    |                                          |
| 1.3           | References                                                                                                              |                                                   | 10.2.2    | SGMII recommendation ...................................29                                                     |                                          |
| 2             | .........................................................3 Getting started on hardware design ..................4       |                                                   | 10.2.3    | PCIe/SGMII unused lanes                                                                                        |                                          |
| 3             | Hardware changes from S32G2 .........................5                                                                  |                                                   |           | recommendations ............................................                                                   | 29                                       |
| 4             | Power Supply ......................................................                                                     | 5                                                 | 10.2.4    | PCIe/SGMII design recommendations                                                                              | .............30                          |
| 4.1           | Power tree .........................................................5                                                   |                                                   | 10.2.5    | PCIe/SerDes signal layout requirements                                                                         | .........30                              |
| 4.2           | Power sequencing .............................................6                                                         |                                                   | 10.3      | USBOTG ..........................................................30                                            |                                          |
| 4.3           | Power connections                                                                                                       | ............................................ 6    | 11        | Input/output pins ...............................................31                                            |                                          |
| 4.4           | PMIC S32G3 control signals connections ..........7                                                                      |                                                   | 11.1      | Understanding pin multiplexing ........................31                                                      |                                          |
| 4.4.1         | PMIC sense and VDD_STBY ............................8                                                                   |                                                   | 11.2      | Pad slew rate ..................................................                                               | 32                                       |
| 4.5           | Voltage monitoring                                                                                                      | .............................................8    | 11.3      | Injection current ...............................................32                                            |                                          |
| 4.6           | S32G3 supplies in Standby mode .....................                                                                    | 8                                                 | 11.4      | Handling unused pins                                                                                           | ......................................32 |
| 4.6.1         | I/O pad behavior in Standby mode ....................9                                                                  |                                                   | 11.5      | S32G3 model support ......................................33                                                   |                                          |
| 4.6.2         | VDD_IO_B options in Standby mode ................                                                                       | 9                                                 | 12        | S32G3 thermal considerations ........................                                                          | 33                                       |
| 4.6.3         | Standby mode entry/exit considerations ..........10                                                                     |                                                   | 12.1      | Internal package conduction resistance ...........33                                                           |                                          |
| 4.7           | Decoupling/bypass circuit ................................10                                                            |                                                   | 13        | S32G3 layout and routing                                                                                       |                                          |
| 4.7.1         | Placing decoupling capacitors .........................                                                                 | 12                                                |           | recommendations .............................................                                                  | 34                                       |
| 4.8           | PDN (Power Delivery Network) requirements ....................................................13                        |                                                   | 13.1      | General design recommendations ...................34 Stack-up recommendations .............................34  |                                          |
| 4.9 4.9.1     | VDD_EFUSE power ........................................ Application controlled VDD_EFUSE supply .....13                | 13                                                | 13.2 13.3 | High-speed routing recommendations PCB material parameters (affecting high                                     | .............34                          |
| 4.9.2         | Permanently grounding VDD_EFUSE .............                                                                           | 14                                                | 13.4      | frequency operation) ........................................35                                                |                                          |
| 5             | Reset ...................................................................14                                             |                                                   | 13.5      | Impact on signal integrity due to PCB                                                                          |                                          |
| 5.1           | External reset sources .....................................14                                                          |                                                   | 13.6      | material parameters .........................................35 Optimum value of PCB material parameters       |                                          |
| 5.1.1         | POR_B pin .......................................................14                                                     |                                                   |           | to support microwave and radio frequency                                                                       |                                          |
| 5.1.2         | RESET_B pin ..................................................                                                          | 15                                                |           |                                                                                                                |                                          |
| 6             | Clocking .............................................................                                                  | 15                                                |           | range signals ...................................................                                              | 35                                       |
| 6.1           | Crystal consideration .......................................                                                           | 15                                                | 13.7      | Layout practices to reduce impact on signal                                                                    |                                          |
| 6.2 7         | Clocking layout requirements .......................... Boot Configuration ...........................................  | 15 16                                             | 14        | integrity due to PCB material ...........................35 Avoiding board bring-up problems ................. | 36                                       |
| 7.1           | Boot related I/Os .............................................                                                         | 16                                                | 14.1      | Avoiding power pitfalls current                                                                                | .........................36              |
| 7.2           | Boot configuration from serial EEPROM ..........16                                                                      |                                                   | 14.2      | Avoiding power pitfalls voltage ........................                                                       | 37                                       |
| 7.3           | Boot configuration from GPIO pins ..................16                                                                  |                                                   | 14.3      | Checking for clock pitfalls ................................37                                                 |                                          |
| 8             | Debug interface .................................................17                                                     |                                                   | 14.4      | Avoiding reset pitfalls .......................................37                                              |                                          |
| 9             | Memories ............................................................18                                                 |                                                   | 15        | Schematic review ..............................................37                                              |                                          |
| 9.1           | DRAM memory interface .................................                                                                 | 18                                                | 16        | Frequently asked questions .............................37                                                     |                                          |
| 9.1.1         | LPDDR4 memory .............................................18                                                           |                                                   | 17        | Revision history ................................................39                                            |                                          |
| 9.1.1.1       | LPDDR4 connection information .....................                                                                     | 18                                                | 18        | Legal information ..............................................40                                             |                                          |
| 9.1.1.2       | Data bits and bytes swapping limitations .........21                                                                    |                                                   |           |                                                                                                                |                                          |
| 9.1.1.3       | LPDDR4 layout guidelines ...............................21                                                              |                                                   |           |                                                                                                                |                                          |
| 9.1.2         | DDR3L memory                                                                                                            | ...............................................22 |           |                                                                                                                |                                          |
| 9.1.2.1       | DDR3L connection information ........................23                                                                 |                                                   |           |                                                                                                                |                                          |
| 9.1.2.2       | Data bits and byte swapping limitations ...........25                                                                   |                                                   |           |                                                                                                                |                                          |
| 9.1.2.3       | DDR3L layout guidelines .................................25                                                             |                                                   |           |                                                                                                                |                                          |
| 9.2           | QSPI ................................................................                                                   | 26                                                |           |                                                                                                                |                                          |
| 9.2.1         | Recommendations for QSPI interface .............                                                                        | 26                                                |           |                                                                                                                |                                          |
| 9.2.2 9.2.2.1 | QSPI layout guidelines .................................... Maximum total length ...................................... | 27 27                                             |           |                                                                                                                |                                          |
| 9.2.2.2       | Length matching ..............................................27                                                        |                                                   |           |                                                                                                                |                                          |
| 10            | Communication Peripherals .............................27                                                               |                                                   |           |                                                                                                                |                                          |
| 10.1          | Ethernet recommendations ..............................27                                                               |                                                   |           |                                                                                                                |                                          |

Please be aware that important notices concerning this document and the product(s) described herein, have been included in section 'Legal information'.

<!-- image -->

User guide S32G3 Hardware Design Guidelines