## TJA1463

## CAN FD signal improvement transceiver with Sleep mode

Rev. 3.0 - 12 February 2025

## 1   General description

The TJA1463 is a member of the TJA146x family of transceivers that provide an interface between a Controller Area Network (CAN) or CAN FD (Flexible Data rate) protocol controller and the physical two-wire CAN bus. TJA146x transceivers implement the CAN physical layer as defined in ISO 11898-2:2024 third edition and SAE J2284-1 to SAE J2284-5, and are fully interoperable with high-speed Classical CAN and CAN FD transceivers.

The TJA1463 includes CAN signal improvement capability (SIC), as defined in ISO 11898-2:2024 parameter set C. CAN signal improvement significantly reduces signal ringing in a network, allowing reliable CAN FD communication to function in larger topologies. In addition, the TJA1463 features a much tighter bit timing symmetry performance to enable CAN FD communication up to 8 Mbit/s.

The TJA1463 is intended as a simple replacement for high-speed Classical CAN and CAN FD transceivers, such as the TJA1043 and TJA1443 from NXP. It offers pin compatibility and is designed to avoid changes to hardware and software design, allowing the TJA1463 to be easily retrofitted to existing applications.

An AEC-Q100 Grade 0 variant, the TJR1463, is available for high temperature applications, supporting operation at 150 °C ambient temperature.

## 2   Features and benefits

## 2.1  General

- ISO 11898-2:2024 parameter set A-C, SAE J2284-1 to SAE J2284-5 and SAE J1939-14 compliant
- Implements CAN Signal Improvement Capability as defined in ISO 11898-2:2024 parameter Set C to significantly reduce signal ringing effects in a network
- Tighter bit timing symmetry performance versus standard CAN FD transceivers allowing for data rates up to 8 Mbit/s
- Low Electromagnetic Emission (EME) and high Electromagnetic Immunity (EMI)
- Qualified according to AEC-Q100 Grade 1
- VIO input for interfacing with 3.3 V to 5 V microcontrollers
- Listen-only mode for node diagnosis and failure containment
- Available in SO14 and leadless HVSON14 (3.0 mm x 4.5 mm) packages; HVSON14 with improved Automated Optical Inspection (AOI) capability.
- Dark green product (halogen free and Restriction of Hazardous Substances (RoHS) compliant)

<!-- image -->

Product data sheet

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

## 2.2  Predictable and fail-safe behavior

- Undervoltage detection with defined handling on all supply pins
- Full functionality guaranteed from the undervoltage detection thresholds up to the maximum limiting voltage values
- Defined behavior below the undervoltage detection thresholds
- Transceiver disengages from the bus (high-ohmic) when the battery voltage drops below the Off mode threshold
- Internal biasing of TXD and mode selection input pins, to enable defined fail-safe behavior

## 2.3  Low-power management

- Very low-current Standby and Sleep modes, with local (WAKE pin), bus (CANH/CANL pins) and host (STB/EN pins) wake-up capability
- Entire node with TJA1463 can be powered down while still supporting local, bus and host wake-up
- CAN wake-up receiver powered by VBAT allowing VIO and VCC to be shut down
- CAN wake-up pattern filter time of 0.5 μs to 1.8 μs, meeting Classical CAN and CAN FD requirements

## 2.4  Diagnosis &amp; Protection

- Overtemperature diagnosis
- Transmit Data (TXD) dominant time-out and TXD-to-RXD short-circuit handler with diagnosis
- Bus dominant failure diagnosis
- Cold start diagnosis (first battery connection)
- High ESD handling capability on the bus pins
- Bus pins and VBAT protected against transients in automotive environments
- Thermally protected

## 3   Quick reference data

## Table 1. Quick reference data

| Symbol       | Parameter                                  | Conditions                                          | Min   | Typ   | Max   | Unit   |
|--------------|--------------------------------------------|-----------------------------------------------------|-------|-------|-------|--------|
| V BAT        | battery supply voltage                     | operating range                                     | 4.5   | -     | 28    | V      |
| I BAT        | battery supply current                     | Normal or Listen-only mode                          | -     | 80    | 300   | µA     |
| I BAT        | battery supply current                     | Standby or Sleep mode                               | -     | 13    | 26    | µA     |
| V uvd(VBAT)  | undervoltage detection voltage on pin VBAT |                                                     | 4     | -     | 4.5   | V      |
| V CC         | supply voltage                             |                                                     | 4.5   | -     | 5.5   | V      |
| I CC         | supply current                             | Normal mode, dominant                               | -     | 42    | 70    | mA     |
| I CC         | supply current                             | Normal mode, recessive                              | -     | 7     | 10    | mA     |
| I CC         | supply current                             | Listen-only mode                                    | -     | 5     | 8     | mA     |
| I CC         | supply current                             | Standby or Sleep mode                               | -     | -     | 2     | μA     |
| V uvd(VCC)   | undervoltage detection voltage on pin VCC  | V BAT > 4.5 V                                       | 4     | -     | 4.5   | V      |
| V uvhys(VCC) | undervoltage hysteresis voltage on pin VCC |                                                     | 50    | -     | -     | mV     |
| V IO         | supply voltage on pin VIO                  |                                                     | 2.95  | -     | 5.5   | V      |
| I IO         | supply current on pin VIO                  | Normal mode, dominant; V TXD = 0 V                  | -     | 90    | 250   | µA     |
| I IO         | supply current on pin VIO                  | Normal or Listen-only mode, recessive; V TXD = V IO | -     | -     | 3     | µA     |
| I IO         | supply current on pin VIO                  | Standby or Sleep mode                               | -     | -     | 2     | µA     |
| V uvd(VIO)   | undervoltage detection voltage on pin VIO  | V BAT > 4.5 V                                       | 2.65  | -     | 2.95  | V      |
| V uvhys(VIO) | undervoltage hysteresis voltage on pin VIO |                                                     | 50    | -     | -     | mV     |
| V ESD        | electrostatic discharge voltage            | IEC 61000-4-2 on pins CANH and CANL                 | -6    | -     | +6    | kV     |
| V CANH       | voltage on pin CANH                        | limiting value according to IEC 60134               | -36   | -     | +40   | V      |
| V CANL       | voltage on pin CANL                        | limiting value according to IEC 60134               | -36   | -     | +40   | V      |
| T vj         | virtual junction temperature               |                                                     | -40   | -     | +150  | °C     |

## 4   Ordering information

## Table 2. Ordering information

| Type number   | Package   | Package                                                                                                  | Package   |
|---------------|-----------|----------------------------------------------------------------------------------------------------------|-----------|
|               | Name      | Description                                                                                              | Version   |
| TJA1463AT     | SO14      | plastic small outline package; 14 leads; body width 3.9 mm                                               | SOT108-1  |
| TJA1463ATK    | HVSON14   | plastic thermal enhanced very thin small outline package; no leads; 14 terminals; body 3 × 4.5 × 0.85 mm | SOT1086-2 |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

## Table 3. TJA1463 feature overview

See Section 18 for a feature overview of the complete TJx14(41/42/43/48)x, TJx14(62/63)x , TJF1441 family.

|            | Modes   | Modes   | Modes   | Modes              | Modes          | Supplies   | Supplies   | Supplies   | Data rate             | Data rate             | Additional features    | Additional features            | Additional features                  | Additional features           | Additional features   | Additional features             |
|------------|---------|---------|---------|--------------------|----------------|------------|------------|------------|-----------------------|-----------------------|------------------------|--------------------------------|--------------------------------------|-------------------------------|-----------------------|---------------------------------|
| Device [1] | Normal  | Standby | Sleep   | Silent/Listen-only | Selectable Off | VCC pin    | VIO pin    | VBAT pin   | Up to 5 Mbit/s CAN FD | Up to 8 Mbit/s CAN FD | Signal improvement [2] | Wake-up source recognition [3] | Short WUP support [0.5 - 1.8 µs] [4] | Single supply pin wake-up [5] | TXD dominant time-out | Local diagnostics via ERR_N pin |
| TJA1463A   | ●       | ●       | ●       | ●                  |                | ●          | ●          | ●          | ●                     | ●                     | ●                      | ●                              | ●                                    | ●                             | ●                     | ●                               |

- [2] CAN FD Signal Improvement Capability (SIC) according to ISO 11898-2:2024 parameter set C.
- [3] RXD is held LOW after wake-up request, enabling wake-up source recognition.
- [4] WUP = wake-up pattern according to Figure 7 in ISO 11898-2:2024.

[5] Only VBAT supply needed for wake-up.

<!-- image -->

## TJA1463

CAN FD signal improvement transceiver with Sleep mode

## 5   Block diagram

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

## 6   Pinning information

## 6.1  Pinning

<!-- image -->

## 6.2  Pin description

## Table 4. Pin description

| Symbol   |   Pin | Type [1]   | Description                                                                                     |
|----------|-------|------------|-------------------------------------------------------------------------------------------------|
| TXD      |     1 | I          | transmit data input; inputs data (from the CAN controller) to be written to the bus lines       |
| GND [2]  |     2 | G          | ground                                                                                          |
| VCC      |     3 | P          | 5 V supply voltage input                                                                        |
| RXD      |     4 | O          | receive data output; outputs data read from the bus lines (to the CAN controller)               |
| VIO      |     5 | P          | supply voltage input for I/O level adapter                                                      |
| EN       |     6 | I          | enable control input                                                                            |
| INH      |     7 | AO         | inhibit output for switching external voltage regulators                                        |
| ERR_N    |     8 | O          | local failure detection; wake-up source recognition and power-on indication output (active-LOW) |
| WAKE     |     9 | AI         | local wake-up input                                                                             |
| VBAT     |    10 | P          | battery supply voltage input                                                                    |
| n.c.     |    11 | -          | not connected                                                                                   |
| CANL     |    12 | AIO        | LOW-level CAN bus line                                                                          |
| CANH     |    13 | AIO        | HIGH-level CAN bus line                                                                         |
| STB_N    |    14 | I          | Standby mode control input (active-LOW)                                                         |

CAN FD signal improvement transceiver with Sleep mode

## 7   Functional description

## 7.1  Operating modes

The TJA1463 contains two independent state machines, a system state machine and a CAN state machine. Two state machines are needed to secure flag handling during undervoltage conditions. These state machines support a number of interdependent operating modes. The system state machine controls the CAN state machine, but both state machines are independently affected by the VCC undervoltage status. For both state machines, undervoltage detection is defined as Vx &lt; Vuvd(x) for t &gt; tdet(uv)  and undervoltage recovery is defined as Vx &gt; Vuvd(x)  for t &gt; t rec(uv) .

## 7.1.1  System operating modes

The system state machine in the TJA1463 supports five system operating modes. Control pins STB\_N and EN are used to select the operating mode. Figure 3 describes how to switch between operating modes. Mode changes are completed after transition time tt(moch). Fail-safe diagnostic information, as described in Section 7.2, is available on pin ERR\_N with a delay of td(moch-ERR\_N) after a mode change.

<!-- image -->

## 7.1.1.1  Off mode

The TJA1463 switches to Off mode from any mode mode when the battery voltage falls below the undervoltage detection threshold, Vuvd(VBAT). The device starts up in Off mode when the battery is connected for the first time (cold start). Pins INH and ERR\_N are in a high-ohmic state in Off mode.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

## 7.1.1.2  Standby mode

Standby mode is the first-level power-saving mode of the TJA1463. When VBAT rises above the undervoltage detection threshold, Vuvd(VBAT), the TJA1463 starts to boot up, triggering an initialization procedure. It switches to Standby mode after tstartup, resulting in a HIGH level on pin INH.

When VIO rises above the undervoltage detection threshold, Vuvd(VIO), the TJA1463 switches to Normal mode if pins STB\_N and EN are HIGH, and to Listen-only mode if STB\_N is HIGH and EN is LOW. It will remain in Standby mode if STB\_N is LOW.

The TJA1463 will switch to Sleep mode if VIO remains below Vuvd(VIO) for tdet(uv)long and/or VCC remains below Vuvd(VCC) for t det(uv)long. A transition from Standby mode to Sleep mode can also be triggered by holding STB\_N LOW and EN HIGH for th(gotosleep) (also known as a 'go-to-sleep' command). This 'go-to-sleep' command is overruled if the Wake flag is set, in which case the device remains in Standby mode.

## 7.1.1.3  Normal mode

HIGH levels on pin STB\_N and pin EN selects Normal mode, provided the battery supply voltage, VBAT, and VIO are present. Pin INH remains HIGH, so voltage regulators controlled by pin INH will also be active (see Figure 10).

## 7.1.1.4  Listen-only mode

A HIGH level on pin STB\_N and a LOW level on pin EN selects Listen-only mode, provided VBAT and VIO are present. Pin INH remains HIGH, so voltage regulators controlled by pin INH will also be active.

In Listen-only mode the receiver is enabled, but the transmitter is disabled.

## 7.1.1.5  Sleep mode

Sleep mode is the second-level power-saving mode of the TJA1463. Sleep mode is entered in a number of ways:

- via Standby mode, in response to a 'go-to-sleep' command
- via Standby mode as a result of a VIO undervoltage longer than tdet(uv)long
- via all other modes, except Off mode, as a result of a VCC undervoltage longer than tdet(uv)long

In Sleep mode, the transceiver behaves as described for Standby mode, with the exception that pin INH is set high-ohmic. Voltage regulators controlled by this pin are switched off and the current into pin VBAT is reduced to a minimum.

A number of events will cause the TJA1463 to exit Sleep mode, switching to Standby mode:

- setting the Wake flag
- a rising edge on pin STB\_N (if VIO &gt; Vuvd(VIO))
- VCC &gt; Vuvd(VCC), VIO &gt; Vuvd(VIO), STB\_N = HIGH and the 'go-to-sleep' command has not been activated. After entering Standby mode, the TJA1463 will enter Normal or Listen-Only if STB\_N is HIGH.

## 7.1.1.6  System operating modes and gap-free operation

Gap-free operation guarantees defined behavior at all voltage levels. Supply voltage-to-operating mode mapping is detailed in Figure 4.

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Figure 4. TJA1463 supply voltage ranges and gap-free operation

<!-- image -->

## 7.1.2  CAN operating modes

The CAN state machine supports six operating modes.

<!-- image -->

## 7.1.2.1  CAN Off mode

When the TJA1463 system state machine is in Off mode, the CAN state machine will be in CAN Off mode, with the bus pins and pin RXD in a high-ohmic state.

## 7.1.2.2  CAN Offline mode

When the TJA1463 system state machine is in Sleep or Standby mode and the Wake flag has not been set, the CAN state machine will be in CAN Offline mode. The bus pins are biased to ground.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

The transceiver is unable to transmit or receive data and the low-power receiver is activated to monitor the bus for a wake-up pattern. Pin RXD is HIGH.

## 7.1.2.3  CAN Wake mode

When the TJA1463 system state machine is in Sleep or Standby mode and the wake flag has been set, the CAN state machine will be in CAN Wake mode. Pin RXD will be LOW, reflecting the active wake-up request. The bus pins are biased to ground.

## 7.1.2.4  CAN Pass-through mode

When the TJA1463 system state machine is in Normal or Listen-only mode and VCC is below the undervoltage detection threshold, Vuvd(VCC), the CAN state machine will be in CAN Pass-through mode.

The transceiver cannot transmit data via the bus lines in this mode. The output voltage on the bus pins is biased to ground. Differential data on the bus pins is converted to digital data via the low-power receiver and the results are output on pin RXD.

## 7.1.2.5  CAN Active mode

When the TJA1463 system state machine is in Normal mode and VCC is above the undervoltage detection threshold, Vuvd(VCC), the CAN state machine will be in CAN Active mode. The transceiver can transmit and receive data via bus lines CANH and CANL. Pin TXD must be HIGH at least once in CAN Active mode before the first transmission can begin. The differential receiver converts the analog data on the bus lines into digital data on pin RXD. In order to support high bit rates, especially in CAN FD systems, the Signal Improvement function largely eliminates topology-related reflections and impedance mismatches. In recessive state, the output voltage on the bus pins is VCC/2.

## 7.1.2.6  CAN Listen-only mode

When the TJA1463 system state machine is in Listen-only mode and VCC is above the undervoltage detection threshold, Vuvd(VCC), the CAN state machine will be in CAN Listen-only mode. The transmitter is disabled. The differential receiver converts the analog data on the bus lines into digital data on pin RXD. As in CAN Active mode, the bus pins are biased to VCC/2.

## 7.2  Internal flags

The device makes use of four internal flags for fail-safe fallback control and system diagnosis. These flags can be polled by the controller via pin ERR\_N while VIO is active. Which flag is available on pin ERR\_N at any time depends on the current system operating mode; see Table 5.

Table 5. Accessing internal flags via pin ERR\_N

| Internal flag   | Flag available on pin ERR_N [1]                                  | Flag status: set [2]                                                                                               | Flag status: not set [2]                 | Flag cleared                                                                                                                                                                                                                     |
|-----------------|------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Pwon            | in Listen-only mode (coming from Standby or Sleep mode)          | V BAT has risen above V uvd(VBAT)                                                                                  | V BAT has not risen above V uvd(VBAT)    | on entering Normal mode                                                                                                                                                                                                          |
| Wake            | in Standby and Sleep modes (provided V IO and V BAT are present) | remote or local wake-up detected OR Pwon flag has been set                                                         | no remote or local wake-up detected      | on entering Normal mode or long VIO/ VCC undervoltage                                                                                                                                                                            |
| Wake-up source  | in Normal mode                                                   | local wake-up OR Pwon flag has been set                                                                            | remote wake-up OR no wake-up             | on leaving Normal mode                                                                                                                                                                                                           |
| Local failure   | in Listen-only mode (coming from Normal mode)                    | on occurrence of: - TXD dominant failure OR - TXD-RXD short circuit OR - Bus dominant failure OR - Overtemperature | none of the set conditions have been met | when Pwon flag is set or, provided all local failures have been resolved, when: - device enters Normal mode OR - RXD dominant while TXD recessive OR - bus dominant failure resolved AND no other local failure has set the flag |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

- [1] Pin ERR\_N is an active-LOW output; a LOW level indicates a set flag and a HIGH level indicates the flag has not been set.
- [2] Status since flag was last cleared.

## 7.2.1  Pwon flag

Pwon is the VBAT power-on flag. This flag is set when the voltage on pin VBAT recovers after previously dropping below Vuvd(VBAT) (usually because the battery was disconnected). The Pwon flag can be used for cold start diagnosis. The Wake and Wake-up source flags are set to ensure consistent system power-up under all supply conditions. Coming from Sleep or Standby and entering Listen-Only mode, a LOW level on pin ERR\_N signals that the Pwon flag has been set. The flag is cleared when the transceiver enters Normal mode.

## 7.2.2  Wake flag

The Wake flag is set when the transceiver detects a local or remote wake-up request.

## 7.2.2.1  Local wake-up (via WAKE pin)

A local wake-up request is registered when the logic level on pin WAKE changes and the new level remains stable for at least t wake . The system state machine can set the Wake flag in Standby or Sleep mode. Setting the Wake flag clears the twake timer. Once set, the Wake flag status is immediately available on pins ERR\_N and RXD (provided VIO and VBAT are present). This flag is also set at power-on and cleared when the transceiver enters Normal mode.

## 7.2.2.2  Remote wake-up (via the CAN bus)

The TJA1463 wakes up from Sleep to Standby mode when a dedicated wake-up pattern (according to Figure 7 in ISO 11898-2: 2024) is detected on the bus.

The wake-up pattern consists of:

- a dominant phase of at least twake(busdom) followed by
- a recessive phase of at least twake(busrec)  followed by
- a dominant phase of at least twake(busdom)

Dominant or recessive bits between the above mentioned phases that are shorter than twake(busdom) and t wake(busrec)  respectively are ignored.

The complete dominant-recessive-dominant pattern must be received within tto(wake)bus to be recognized as a valid wake-up pattern (see Figure 6). Otherwise, the internal wake-up logic is reset. The complete wake-up pattern then needs to be retransmitted to trigger a wake-up event. Pins RXD and ERR\_N remain HIGH until the wake-up event has been triggered and then switch LOW after tstartup(RXD)/tstartup(ERR\_N). Pin INH remains floating until the wake-up event has been triggered and then switches HIGH after tstartup(INH).

A wake-up event is not flagged on RXD if any of the following events occurs while a valid wake-up pattern is being received:

- The device switches to Normal mode
- The complete wake-up pattern was not received within tto(wake)bus
- A VCC or VIO undervoltage is detected

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## 7.2.3  Wake-up source flag

Wake-up source recognition is provided via the Wake-up source flag. It is set after the Wake flag has been set by a local wake-up request via the WAKE pin. The Wake-up source flag can be polled via the ERR\_N pin in Normal mode (see Table 5). This flag is also set at power-on and cleared when the transceiver leaves Normal mode.

## 7.2.4  Local failure flag

In Normal and Listen-only modes, the transceiver can distinguish four local failure events, any of which will cause the Local failure flag to be set. The four local failure events are:

- TXD dominant failures
- TXD-to-RXD short circuit
- Bus dominant failures
- Overtemperature

The nature and detection of these local failures is described in Section 7.3. The Local failure flag can be polled via the ERR\_N pin in Listen-only mode, when coming from Normal mode (see Table 5).

This flag is cleared at power-on when the Pwon flag is set or, provided all local failures have been resolved, when:

- The device enters Normal mode OR
- RXD is dominant while TXD is recessive OR
- Bus dominant failure has been resolved AND no other local failure has set the flag

## 7.3  Local failure events

The TJA1463 can detect four different local failure conditions, any of which will set the Local failure flag. In most cases, the transmitter is disabled.

## 7.3.1  TXD dominant failures

A hardware and/or software application failure that caused pin TXD to be held LOW would drive the bus lines to a permanent dominant state (blocking all network communications). The TXD dominant time-out function prevents such a network lock-up. A 'TXD dominant time-out' timer is started when pin TXD goes LOW. If the LOW state on this pin persists for longer than tto(dom)TXD, the transmitter is disabled, releasing the bus lines to recessive state. The transmitter remains disabled until the Local failure flag has been cleared. The TXD dominant time-out timer is reset when pin TXD is set HIGH.

## 7.3.2  TXD-to-RXD short circuit

A short-circuit between pins RXD and TXD would lock the bus in a permanent dominant state once it had been driven dominant, because the low-side driver of RXD is typically stronger than the high-side driver of the controller connected to TXD. TXD-to-RXD short-circuit detection prevents such a network lock-up by disabling the transmitter. The transmitter remains disabled until the Local failure flag has been cleared.

## 7.3.3  Bus dominant failures

A CAN bus short circuit (to VBAT, VCC or GND) or a failure in one of the other network nodes could result in a differential voltage on the bus high enough to represent a bus dominant state. Because a node will not begin to transmit while the bus is dominant, the host controller would not be able to detect this failure condition. However, bus dominant clamping detection will detect the short circuit. The Local failure flag is set if the dominant state on the bus persists for longer than tto(dom)bus. By checking this flag, the controller can determine if a clamped bus is blocking network communications. There is no need to disable the transmitter. Note that the Local failure flag is reset as soon as the bus returns to recessive state.

## 7.3.4  Overtemperature

The device is protected against overtemperature conditions. If the junction temperature exceeds the shutdown junction temperature, Tj(sd) , the CAN bus drivers are disabled. The transmitter will remain disabled until the junction temperature drops below Tj(sd)rel and the Local failure flag has been cleared.

## 7.4  I/O levels

Pin VIO should be connected to the same supply voltage used to supply the microcontroller. This adjusts the signal levels on pins TXD, RXD, STB\_N, EN and ERR\_N to the I/O levels of the microcontroller, allowing for direct interfacing without additional glue logic. Spurious signals from the microcontroller on pins STB\_N and EN are filtered out with a filter time of t fltr(IO) .

## 7.5  WAKE pin

A local wake-up event is triggered by a LOW-to-HIGH or HIGH-to-LOW transition on the WAKE pin when VWAKE crosses the wake-up threshold, Vth(wake). After the transition, the new HIGH or LOW level should remain stable for at least tWAKE. This allows for maximum flexibility when designing a local wake-up circuit.

A local wake-up is guaranteed in the case of:

- a LOW-to-HIGH transition from VWAKE &lt; Vth(wake)min to VWAKE &gt; Vth(wake)max, followed by VWAKE &gt;

Vth(wake)max  for t &gt; tWAKE(max)

- a HIGH-to-LOW transition from VWAKE &gt; Vth(wake)max to VWAKE &lt; Vth(wake)min, followed by VWAKE &lt;

Vth(wake)min  for t &gt; tWAKE(max)

A local wake-up is guaranteed not to occur for a transient (L-H-L or H-L-H) of duration t &lt; t(WAKE)min, irrespective of the VWAKE voltage level.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

To minimize current consumption, the internal bias voltage follows the logic state on the pin after a delay of tWAKE. A HIGH level on pin WAKE is followed by an internal pull-up to 5 V (see Figure 1). A LOW level on pin WAKE is followed by an internal pull-down towards GND. In applications that do not make use of the local wake-up facility, it is recommended to connect the WAKE pin to pin VBAT or GND for optimal EMI performance.

## 7.6  Internal biasing of TXD, STB\_N and EN input pins

Pin TXD has an internal pull-up to VIO and pins STB\_N and EN have internal pull-downs to GND to ensure a safe, defined state in case one, or all, of these pins is left floating. Pull-up/pull-down resistors are present on these pins in all states. Pull-down on pin EN is only active when VBAT is present.

## 8   Limiting values

## Table 6. Limiting values

In accordance with the Absolute Maximum Rating System (IEC 60134); all voltages are referenced to pin GND, unless otherwise specified; positive currents flow into the IC.

| Symbol        | Parameter                             | Conditions                                                      |      | Min   | Max            | Unit   |
|---------------|---------------------------------------|-----------------------------------------------------------------|------|-------|----------------|--------|
| V x           | Voltage on pin x [1]                  | pins VCC, VIO, TXD, STB_N, EN                                   |      | -0.3  | +6             | V      |
| V x           | Voltage on pin x [1]                  | pins VCC, VIO, TXD, STB_N, EN                                   |      | -     | +7 [2]         | V      |
| V x           | Voltage on pin x [1]                  | pin VBAT, load dump                                             |      | -     | +40 [3]        | V      |
| V x           | Voltage on pin x [1]                  | pin INH                                                         |      | -0.3  | V BAT +0.3 [4] | V      |
| V x           | Voltage on pin x [1]                  | pins CANH, CANL, WAKE                                           |      | -36   | +40            | V      |
| V x           | Voltage on pin x [1]                  | pins RXD, ERR_N                                                 |      | -0.3  | V IO +0.3 [5]  | V      |
| I O(INH)      | output current on pin INH             |                                                                 |      | -2    | -              | mA     |
| I r(VBAT)     | reverse current on pin VBAT           | assuming the voltage on pin VBAT is below ground level          |      | -10   | -              | mA     |
| V (CANH-CANL) | voltage between pin CANH and pin CANL |                                                                 |      | -40   | +40            | V      |
| V trt         | transient voltage                     | on pins VBAT, WAKE, CANH, CANL                                  | [6]  |       |                |        |
| V trt         | transient voltage                     | pulse 1                                                         |      | -100  | -              | V      |
| V trt         | transient voltage                     | pulse 2a                                                        |      | -     | +75            | V      |
| V trt         | transient voltage                     | pulse 3a                                                        |      | -150  | -              | V      |
| V trt         | transient voltage                     | pulse 3b                                                        |      | -     | +100           | V      |
| V ESD         | electrostatic discharge voltage       | IEC 61000-4-2 (150 pF, 330 Ω discharge circuit)                 | [7]  |       |                |        |
| V ESD         | electrostatic discharge voltage       | on pins CANH, CANL                                              |      | -6    | +6             | kV     |
| V ESD         | electrostatic discharge voltage       | on pin VBAT with 100 nF capacitor; pin WAKE with 33 kΩ resistor |      | -8    | +8             | kV     |
| V ESD         | electrostatic discharge voltage       | SAE J2962-2:2019 (330 pF, 2kΩ) on pins CANH, CANL               | [8]  |       |                |        |
| V ESD         | electrostatic discharge voltage       | powered air discharge                                           |      | -15   | +15            | kV     |
| V ESD         | electrostatic discharge voltage       | powered contact discharge                                       |      | -8    | +8             | kV     |
| V ESD         | electrostatic discharge voltage       | Human Body Model (HBM)                                          |      |       |                |        |
| V ESD         | electrostatic discharge voltage       | on any pin                                                      | [9]  | -4    | +4             | kV     |
| V ESD         |                                       | on pins CANH, CANL                                              | [10] | -8    | +8             | kV     |
| V ESD         |                                       | Charged Device Model (CDM)                                      | [11] |       |                |        |
| V ESD         |                                       | on corner pins                                                  |      | -750  | +750           | V      |
| V ESD         |                                       | on any other pin                                                |      | -500  | +500           | V      |
| T vj          | virtual junction temperature          |                                                                 | [12] | -40   | +150           | °C     |
| T stg         | storage temperature                   |                                                                 | [13] | -55   | +150           | °C     |

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

- [4] Absolute maximum of 40 V under the conditions defined in Table note 3 above.
- [5] Subject to the qualifications detailed in Table notes 1 and 2 above for pins VCC, VIO, TXD, STB\_N and EN.
- [6] Verified by an external test house according to IEC TS 62228, Section 4.2.4; parameters for standard pulses defined in ISO 7637, Part 2.
- [7] Verified by an external test house according to IEC TS 62228, Section 4.3.
- [8] Verified by an external test house according to ISO 10605.
- [9] According to AEC-Q100-002.
- [10] Pins stressed to reference group containing all ground and supply pins, emulating the application circuit (Figure 10). HBM pulse as specified in AECQ100-002 used.
- [11] According to AEC-Q100-011.
- [12] In accordance with IEC 60747-1. An alternative definition of virtual junction temperature is: Tvj = Tamb + P × Rth(j-a), where Rth(j-a)  is a fixed value used in the calculation of T vj . The rating for T vj  limits the allowable combinations of power dissipation (P) and ambient temperature (T amb ).
- [13] Tstg  in application according to IEC61360-4. For component transport and storage conditions, see instead IEC61760-2.

## 9   Thermal characteristics

Value determined for free convection conditions on a JEDEC 2S2P board. Table 7. Thermal characteristics

| Symbol    | Parameter                                                          | Conditions [1]   |   Typ | Unit   |
|-----------|--------------------------------------------------------------------|------------------|-------|--------|
| R th(j-a) | thermal resistance from junction to ambient                        | SO14             |    74 | K/W    |
|           |                                                                    | HVSON14          |    46 | K/W    |
| R th(j-c) | thermal resistance from junction to case [2]                       | HVSON14          |    13 | K/W    |
| Ѱ j-top   | thermal characterization parameter from junction to top of package | SO14             |    13 | K/W    |
|           |                                                                    | HVSON14          |     7 | K/W    |

## 10   Static characteristics

## Table 8. Static characteristics

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified otherwise; all voltages are defined with respect to ground; positive currents flow into the IC. [1]

| Symbol                            | Parameter                         | Conditions                                                                 | Min                               | Typ                               | Max                               | Unit                              |
|-----------------------------------|-----------------------------------|----------------------------------------------------------------------------|-----------------------------------|-----------------------------------|-----------------------------------|-----------------------------------|
| Supply; pin VCC                   | Supply; pin VCC                   | Supply; pin VCC                                                            | Supply; pin VCC                   | Supply; pin VCC                   | Supply; pin VCC                   | Supply; pin VCC                   |
| V CC                              | supply voltage                    |                                                                            | 4.5                               | -                                 | 5.5                               | V                                 |
| V uvd                             | undervoltage detection voltage    |                                                                            | 4                                 | -                                 | 4.5                               | V                                 |
| V uvhys                           | undervoltage hysteresis voltage   |                                                                            | 50                                | -                                 | -                                 | mV                                |
| I CC                              | supply current                    | Normal mode                                                                |                                   |                                   |                                   |                                   |
| I CC                              | supply current                    | dominant; V TXD = 0 V; t < t to(dom)TXD                                    | -                                 | 42                                | 70                                | mA                                |
| I CC                              | supply current                    | V TXD = 0 V; -3 V < (V CANH = V CANL ) < +40 V; short circuit on bus lines | -                                 | -                                 | 125                               | mA                                |
| I CC                              | supply current                    | Normal mode, recessive; V TXD = V IO                                       | -                                 | 7                                 | 10                                | mA                                |
| I CC                              | supply current                    | Listen-only mode                                                           | -                                 | 5                                 | 8                                 | mA                                |
| I CC                              | supply current                    | Standby or Sleep mode; T vj < 85 °C                                        | -                                 | -                                 | 2                                 | µA                                |
| I/O level adapter supply; pin VIO | I/O level adapter supply; pin VIO | I/O level adapter supply; pin VIO                                          | I/O level adapter supply; pin VIO | I/O level adapter supply; pin VIO | I/O level adapter supply; pin VIO | I/O level adapter supply; pin VIO |
| V IO                              | supply voltage                    |                                                                            | 2.95                              | -                                 | 5.5                               | V                                 |
| V uvd                             | undervoltage detection voltage    |                                                                            | 2.65                              | -                                 | 2.95                              | V                                 |
| V uvhys                           | undervoltage hysteresis voltage   |                                                                            | 50                                | -                                 | -                                 | mV                                |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified [1]

otherwise; all voltages are defined with respect to ground; positive currents flow into the IC. Table 8. Static characteristics ...continued

| Symbol                                                            | Parameter                                                         | Conditions                                                                  |                                                                   | Min                                                               | Typ                                                               | Max                                                               | Unit                                                              |
|-------------------------------------------------------------------|-------------------------------------------------------------------|-----------------------------------------------------------------------------|-------------------------------------------------------------------|-------------------------------------------------------------------|-------------------------------------------------------------------|-------------------------------------------------------------------|-------------------------------------------------------------------|
| I IO                                                              | supply current                                                    | Normal mode, dominant; V TXD = 0 V                                          |                                                                   | -                                                                 | 90                                                                | 250                                                               | µA                                                                |
| I IO                                                              | supply current                                                    | Normal mode, recessive, V TXD = V IO or Listen-only mode                    |                                                                   | -                                                                 | -                                                                 | 3                                                                 | µA                                                                |
| I IO                                                              | supply current                                                    | Standby or Sleep mode; T vj < 85 °C                                         |                                                                   | -                                                                 | -                                                                 | 2                                                                 | µA                                                                |
| Supply; pin VBAT                                                  | Supply; pin VBAT                                                  | Supply; pin VBAT                                                            | Supply; pin VBAT                                                  | Supply; pin VBAT                                                  | Supply; pin VBAT                                                  | Supply; pin VBAT                                                  | Supply; pin VBAT                                                  |
| V BAT                                                             | battery supply voltage                                            |                                                                             |                                                                   | 4.5                                                               | -                                                                 | 28                                                                | V                                                                 |
| V uvd                                                             | undervoltage detection voltage                                    |                                                                             | [2]                                                               | 4                                                                 | -                                                                 | 4.5                                                               | V                                                                 |
| I BAT                                                             | battery supply current                                            | Normal or Listen-only mode; pin INH left open                               |                                                                   | -                                                                 | 80                                                                | 300                                                               | µA                                                                |
| I BAT                                                             | battery supply current                                            | Normal or Listen-only mode; pin INH left open; T vj ≤ 25 °C; V BAT = 14.5 V |                                                                   | -                                                                 | 80                                                                | 100                                                               | µA                                                                |
| I BAT                                                             | battery supply current                                            | Standby mode; pin INH left open; V WAKE = V BAT or GND; T vj < 85 °C        |                                                                   | -                                                                 | 13                                                                | 26                                                                | µA                                                                |
| I BAT                                                             | battery supply current                                            | Sleep mode; V WAKE = V BAT or GND; T vj < 85 °C                             |                                                                   | -                                                                 | 13                                                                | 26                                                                | µA                                                                |
| CAN transmit data input; pin TXD                                  | CAN transmit data input; pin TXD                                  | CAN transmit data input; pin TXD                                            | CAN transmit data input; pin TXD                                  | CAN transmit data input; pin TXD                                  | CAN transmit data input; pin TXD                                  | CAN transmit data input; pin TXD                                  | CAN transmit data input; pin TXD                                  |
| V IH                                                              | HIGH-level input voltage                                          |                                                                             |                                                                   | 0.7V IO                                                           | -                                                                 | -                                                                 | V                                                                 |
| V IL                                                              | LOW-level input voltage                                           |                                                                             |                                                                   | -                                                                 | -                                                                 | 0.3V IO                                                           | V                                                                 |
| V hys(TXD)                                                        | hysteresis voltage on pin TXD                                     |                                                                             |                                                                   | 50                                                                | -                                                                 | -                                                                 | mV                                                                |
| R pu                                                              | pull-up resistance                                                |                                                                             |                                                                   | 20                                                                | -                                                                 | 80                                                                | kΩ                                                                |
| C i                                                               | input capacitance                                                 |                                                                             | [3]                                                               | -                                                                 | -                                                                 | 10                                                                | pF                                                                |
| CAN receive data output; pin RXD                                  | CAN receive data output; pin RXD                                  | CAN receive data output; pin RXD                                            | CAN receive data output; pin RXD                                  | CAN receive data output; pin RXD                                  | CAN receive data output; pin RXD                                  | CAN receive data output; pin RXD                                  | CAN receive data output; pin RXD                                  |
| I OH                                                              | HIGH-level output current                                         | V RXD = V IO - 0.4 V                                                        |                                                                   | -10                                                               | -                                                                 | -1                                                                | mA                                                                |
| I OL                                                              | LOW-level output current                                          | V RXD = 0.4 V                                                               |                                                                   | 1                                                                 | -                                                                 | 10                                                                | mA                                                                |
| Standby and enable control inputs; pins STB_N and EN              | Standby and enable control inputs; pins STB_N and EN              | Standby and enable control inputs; pins STB_N and EN                        | Standby and enable control inputs; pins STB_N and EN              | Standby and enable control inputs; pins STB_N and EN              | Standby and enable control inputs; pins STB_N and EN              | Standby and enable control inputs; pins STB_N and EN              | Standby and enable control inputs; pins STB_N and EN              |
| V IH                                                              | HIGH-level input voltage                                          |                                                                             |                                                                   | 0.7V IO                                                           | -                                                                 | -                                                                 | V                                                                 |
| V IL                                                              | LOW-level input voltage                                           |                                                                             |                                                                   | -                                                                 | -                                                                 | 0.3V IO                                                           | V                                                                 |
| V hys                                                             | hysteresis voltage                                                |                                                                             |                                                                   | 50                                                                | -                                                                 | -                                                                 | mV                                                                |
| R pd                                                              | pull-down resistance                                              |                                                                             | [4]                                                               | 20                                                                | -                                                                 | 80                                                                | kΩ                                                                |
| C i                                                               | input capacitance                                                 |                                                                             | [3]                                                               | -                                                                 | -                                                                 | 10                                                                | pF                                                                |
| Local failure detection and power-on indication output; pin ERR_N | Local failure detection and power-on indication output; pin ERR_N | Local failure detection and power-on indication output; pin ERR_N           | Local failure detection and power-on indication output; pin ERR_N | Local failure detection and power-on indication output; pin ERR_N | Local failure detection and power-on indication output; pin ERR_N | Local failure detection and power-on indication output; pin ERR_N | Local failure detection and power-on indication output; pin ERR_N |
| I OH                                                              | HIGH-level output current                                         | V ERR_N = V IO - 0.4 V                                                      |                                                                   | -50                                                               | -                                                                 | -4                                                                | µA                                                                |
| I OL                                                              | LOW-level output current                                          | V ERR_N = 0.4 V                                                             |                                                                   | 0.1                                                               | -                                                                 | 2                                                                 | mA                                                                |
| Local wake-up input; pin WAKE                                     | Local wake-up input; pin WAKE                                     | Local wake-up input; pin WAKE                                               | Local wake-up input; pin WAKE                                     | Local wake-up input; pin WAKE                                     | Local wake-up input; pin WAKE                                     | Local wake-up input; pin WAKE                                     | Local wake-up input; pin WAKE                                     |
| R pu                                                              | pull-up resistance                                                | V WAKE > V th(wake)(max) for t > t wake(max)                                |                                                                   | 100                                                               | -                                                                 | 400                                                               | kΩ                                                                |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified [1]

otherwise; all voltages are defined with respect to ground; positive currents flow into the IC. Table 8. Static characteristics ...continued

| Symbol                        | Parameter                               | Conditions                                                                      | Min Typ                       | Max                           |                               | Unit                          |                               |
|-------------------------------|-----------------------------------------|---------------------------------------------------------------------------------|-------------------------------|-------------------------------|-------------------------------|-------------------------------|-------------------------------|
| R pd                          | pull-down resistance                    | V WAKE < V th(wake)(min) for t > t wake(max)                                    | 100                           | -                             | 400                           | kΩ                            |                               |
| V th(wake)                    | wake-up threshold voltage               | Sleep or Standby mode                                                           | 1.8                           | -                             | 2.6                           | V                             |                               |
| V hys                         | hysteresis voltage                      |                                                                                 | 90                            | -                             | -                             | mV                            |                               |
| Inhibit output; pin INH       | Inhibit output; pin INH                 | Inhibit output; pin INH                                                         | Inhibit output; pin INH       | Inhibit output; pin INH       | Inhibit output; pin INH       | Inhibit output; pin INH       | Inhibit output; pin INH       |
| ΔV H                          | HIGH-level voltage drop                 | ΔV H = V BAT - V INH ; I INH = -1 mA                                            | 0                             | -                             | 1                             | V                             |                               |
|                               |                                         | ΔV H = V BAT - V INH ; I INH = -2 mA                                            | 0                             | -                             | 2                             | V                             |                               |
| I L                           | leakage current                         | Sleep mode; Off mode                                                            | -2                            | -                             | +2                            | µA                            |                               |
| I O(sc)                       | short-circuit output current            | V INH = 0 V                                                                     | -15                           | -                             | -                             | mA                            |                               |
| Bus lines; pins CANH and CANL | Bus lines; pins CANH and CANL           | Bus lines; pins CANH and CANL                                                   | Bus lines; pins CANH and CANL | Bus lines; pins CANH and CANL | Bus lines; pins CANH and CANL | Bus lines; pins CANH and CANL | Bus lines; pins CANH and CANL |
| V O(dom)                      | dominant output voltage                 | V TXD = 0 V; t < t to(dom)TXD ; V CC = 4.75 V to 5.25 V                         |                               |                               |                               |                               |                               |
|                               |                                         | pin CANH; R L = 50 Ω to 65 Ω                                                    | 2.89                          | 3.5                           | 4.26                          | V                             |                               |
|                               |                                         | pin CANL; R L = 50 Ω to 65 Ω                                                    | 0.77                          | 1.5                           | 2.13                          | V                             |                               |
| V TXsym                       | transmitter voltage symmetry            | V TXsym = V CANH + V CANL ; C SPLIT = 4.7 nF; f TXD = 250 kHz, 1 MHz or 2.5 MHz | 0.9V CC                       | -                             | 1.1V CC                       | V                             |                               |
| V cm(step)                    | common mode voltage step                |                                                                                 | -150                          | -                             | +150                          | mV                            |                               |
| V cm(p-p)                     | peak-to-peak common mode voltage        |                                                                                 | -300                          | -                             | +300                          | mV                            |                               |
| V O(dif)                      | differential output voltage             | dominant; Normal mode; V TXD = 0 V; t < t to(dom)TXD ; V CC = 4.75 V to 5.25 V  |                               |                               |                               |                               |                               |
|                               |                                         | R L = 50 Ω to 65 Ω                                                              | 1.5                           | -                             | 2.75                          | V                             |                               |
|                               |                                         | R L = 45 Ω to 70 Ω                                                              | 1.4                           | -                             | 3.3                           | V                             |                               |
|                               |                                         | R L = 2240 Ω                                                                    | 1.5                           | -                             | 5                             | V                             |                               |
|                               |                                         | recessive; no load                                                              |                               |                               |                               |                               |                               |
|                               |                                         | Normal or Listen-only mode; V TXD = V IO                                        | -50                           | -                             | +50                           | mV                            |                               |
|                               |                                         | Standby or Sleep mode                                                           | -0.2                          | -                             | +0.2                          | V                             |                               |
| V O(rec)                      | recessive output voltage                | Normal or Listen-only mode; V TXD = V IO ; no load                              | 2                             | 2.5                           | 3                             | V                             |                               |
|                               |                                         | Standby or Sleep mode; no load                                                  | -0.1                          | 0                             | +0.1                          | V                             |                               |
| V th(RX)dif                   | differential receiver threshold voltage | -12 V ≤ V CANH ≤ +12 V; -12 V ≤ V CANL ≤ +12 V                                  |                               |                               |                               |                               |                               |
|                               |                                         | Normal or Listen-only mode                                                      | 0.5                           | -                             | 0.9                           | V                             |                               |
|                               |                                         | Standby or Sleep mode                                                           | 0.4                           | -                             | 1.1                           | V                             |                               |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified otherwise; all voltages are defined with respect to ground; positive currents flow into the IC. [1] Table 8. Static characteristics ...continued

| Symbol                                                                              | Parameter                                                                           | Conditions                                                                                                                   | Min                                                                                 | Typ                                                                                 | Max                                                                                 | Unit                                                                                |
|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| V rec(RX)                                                                           | receiver recessive voltage                                                          | -12 V ≤ V CANH ≤ +12 V; -12 V ≤ V CANL ≤ +12 V                                                                               |                                                                                     |                                                                                     |                                                                                     |                                                                                     |
| V rec(RX)                                                                           | receiver recessive voltage                                                          | Normal or Listen-only mode                                                                                                   | -8                                                                                  | -                                                                                   | +0.5                                                                                | V                                                                                   |
| V rec(RX)                                                                           | receiver recessive voltage                                                          | Standby or Sleep mode                                                                                                        | -8                                                                                  | -                                                                                   | +0.4                                                                                | V                                                                                   |
| V dom(RX)                                                                           | receiver dominant voltage                                                           | -12 V ≤ V CANH ≤ +12 V; -12 V ≤ V CANL ≤ +12 V                                                                               |                                                                                     |                                                                                     |                                                                                     |                                                                                     |
| V dom(RX)                                                                           | receiver dominant voltage                                                           | Normal or Listen-only mode                                                                                                   | 0.9                                                                                 | -                                                                                   | 9                                                                                   | V                                                                                   |
| V dom(RX)                                                                           | receiver dominant voltage                                                           | Standby or Sleep mode                                                                                                        | 1.1                                                                                 | -                                                                                   | 9                                                                                   | V                                                                                   |
| V hys(RX)dif                                                                        | differential receiver hysteresis voltage                                            | -12 V ≤ V CANH ≤ +12 V; -12 V ≤ V CANL ≤ +12 V; Normal or Listen-only mode                                                   | 100                                                                                 | -                                                                                   | -                                                                                   | mV                                                                                  |
| I O(sc)                                                                             | short-circuit output current                                                        | -15 V ≤ V CANH ≤ +40 V; -15 V ≤ V CANL ≤ +40 V                                                                               | -                                                                                   | -                                                                                   | 115                                                                                 | mA                                                                                  |
| I O(sc)rec                                                                          | recessive short-circuit output current                                              | -27 V ≤ V CANH ≤ +32 V; -27 V ≤ V CANL ≤ +32 V; Normal or Listen-only mode; V TXD = V IO for t > t d(TXD-buspasrec)start [7] | -3                                                                                  | -                                                                                   | +3                                                                                  | mA                                                                                  |
| I L                                                                                 | leakage current                                                                     | V CC = V IO = V BAT = 0 V or pins shorted to GND via 47 kΩ; V CANH = V CANL = 5 V                                            | -10                                                                                 | -                                                                                   | +10                                                                                 | µA                                                                                  |
| R i                                                                                 | input resistance                                                                    | -2 V ≤ V CANL ≤ +7 V; -2 V ≤ V CANH ≤ +7 V; passive recessive [8]                                                            | 25                                                                                  | 40                                                                                  | 50                                                                                  | kΩ                                                                                  |
| ΔR i                                                                                | input resistance deviation                                                          | 0 V ≤ V CANL ≤ +5 V; 0 V ≤ V CANH ≤ +5 V; passive recessive [8]                                                              | -3                                                                                  | -                                                                                   | +3                                                                                  | %                                                                                   |
| R i(dif)                                                                            | differential input resistance                                                       | -2 V ≤ V CANL ≤ +7 V; -2 V ≤ V CANH ≤ +7 V; passive recessive [8]                                                            | 50                                                                                  | 80                                                                                  | 100                                                                                 | kΩ                                                                                  |
| C i(cm)                                                                             | common-mode input capacitance                                                       |                                                                                                                              | -                                                                                   | -                                                                                   | 30                                                                                  | pF                                                                                  |
| C i(dif)                                                                            | differential input capacitance                                                      |                                                                                                                              | -                                                                                   | -                                                                                   | 15                                                                                  | pF                                                                                  |
| Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9 | Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9 | Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9                                          | Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9 | Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9 | Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9 | Signal Improvement function on CANH or CANL; +4.75 V ≤ V CC ≤ +5.25 V; see Figure 9 |
| R i(dom)                                                                            | dominant phase input resistance                                                     | bus dominant; V CC - 1.6 V ≤ V CANH ≤ V CC - 1.2 V;                                                                          | -                                                                                   | -                                                                                   | 30                                                                                  | Ω                                                                                   |
| R i(dif)dom                                                                         | dominant phase differential input resistance                                        | +1.2 V ≤ V CANL ≤ +1.6 V; R i(dif)dom = R i(dom)CANH + R i(dom)CANL                                                          | -                                                                                   | -                                                                                   | 60                                                                                  | Ω                                                                                   |
| R i(actrec)                                                                         | active recessive phase input resistance [9]                                         | bus dominant-to-recessive transition +1.5 V ≤ V CANH ≤ V CC - 1.5 V;                                                         | 37.5                                                                                | -                                                                                   | 62.5                                                                                | Ω                                                                                   |
| R i(dif)actrec                                                                      | active recessive phase differential input resistance [9]                            | +1.5 V ≤ V CANL ≤ V CC - 1.5 V; R i(dif)actrec = R i(actrec)CANH + R i(actrec)CANL                                           | 75                                                                                  | -                                                                                   | 125                                                                                 | Ω                                                                                   |

## Table 8. Static characteristics ...continued

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified otherwise; all voltages are defined with respect to ground; positive currents flow into the IC. [1]

| Symbol                | Parameter                             | Conditions            | Min                   | Typ                   | Max                   | Unit                  |
|-----------------------|---------------------------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|
| Temperature detection | Temperature detection                 | Temperature detection | Temperature detection | Temperature detection | Temperature detection | Temperature detection |
| T j(sd)               | shutdown junction temperature         |                       | [3]                   | 180 -                 | 200                   | °C                    |
| T j(sd)rel            | release shutdown junction temperature |                       | [3]                   | 175 -                 | 195                   | °C                    |

- [1] All parameters are guaranteed over the junction temperature range by design. Factory testing uses correlated test conditions to cover the specified temperature and power supply voltage ranges.
- [2] Undervoltage is detected between min and max values. Undervoltage is guaranteed to be detected below min value and guaranteed not to be detected above max value.
- [3] Not tested in production; guaranteed by design.
- [4] Pull-down on EN pin is only active when VBAT is present.
- [5] The test circuit used to measure the bus output voltage symmetry and the common-mode voltages (which includes CSPLIT) is shown in Figure 12.
- [6] See Figure 7.
- [7] This parameter is defined in ISO 11898-2:2024 parameter set C and is specified in the Dynamic Characteristics table (see Table 9 and Figure 9).
- [8] Passive recessive in accordance with ISO 11898-2. Input impedance is passive once the signal improvement phase has come to an end (active recessive end).
- [9] Active recessive phases are not DC states and are only valid for a limited time after a dominant-to-recessive transition on pin TXD. The maximum value specified is lower than proscribed in ISO11898-2:2024 parameter set C (a lower value is preferred).
- [10] Both conditions and the maximum specified values are tighter, thus better than prescribed in ISO11898-2:2024 parameter set C.

<!-- image -->

Figure 7. CAN bus common-mode voltage according to SAE 1939-14

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

## 11   Dynamic characteristics

Table 9. Dynamic characteristics

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified otherwise; all voltages are defined with respect to ground. [1]

| Symbol                                                                                                                                                                      | Parameter                                                                                                                                                                   | Conditions                                                                                                                                                                  |                                                                                                                                                                             | Min                                                                                                                                                                         | Typ                                                                                                                                                                         | Max                                                                                                                                                                         | Unit                                                                                                                                                                        |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        | CAN timing characteristics according to ISO 11898-2:2024; see Figure 8 and Figure 11                                                                                        |
| t d(TXDL-RXDL)                                                                                                                                                              | delay time from TXD LOW to RXD LOW                                                                                                                                          | Normal mode                                                                                                                                                                 |                                                                                                                                                                             | -                                                                                                                                                                           | -                                                                                                                                                                           | 255                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(TXDH-RXDH)                                                                                                                                                              | delay time from TXD HIGH to RXD HIGH                                                                                                                                        | Normal mode                                                                                                                                                                 |                                                                                                                                                                             | -                                                                                                                                                                           | -                                                                                                                                                                           | 255                                                                                                                                                                         | ns                                                                                                                                                                          |
| CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     | CAN timing characteristics according to ISO 11898-2:2024; V CC = 4.75 V to 5.25 V; see Figure 8, Figure 9 and Figure 11                                                     |
| t d(TXD-busdom)                                                                                                                                                             | delay time from TXD to bus dominant                                                                                                                                         | Normal mode                                                                                                                                                                 |                                                                                                                                                                             | -                                                                                                                                                                           | -                                                                                                                                                                           | 80                                                                                                                                                                          | ns                                                                                                                                                                          |
| t d(TXD-busrec)                                                                                                                                                             | delay time from TXD to bus recessive                                                                                                                                        | Normal mode                                                                                                                                                                 | -                                                                                                                                                                           |                                                                                                                                                                             | -                                                                                                                                                                           | 80                                                                                                                                                                          | ns                                                                                                                                                                          |
| t d(busdom-RXD)                                                                                                                                                             | delay time from bus dominant to RXD                                                                                                                                         | Normal or Listen-Only mode                                                                                                                                                  | -                                                                                                                                                                           |                                                                                                                                                                             | -                                                                                                                                                                           | 110                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(busrec-RXD)                                                                                                                                                             | delay time from bus recessive to RXD                                                                                                                                        | Normal or Listen-Only mode                                                                                                                                                  | -                                                                                                                                                                           |                                                                                                                                                                             | -                                                                                                                                                                           | 110                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(TXDL-RXDL)                                                                                                                                                              | delay time from TXD LOW to RXD LOW                                                                                                                                          | Normal mode                                                                                                                                                                 | -                                                                                                                                                                           |                                                                                                                                                                             | -                                                                                                                                                                           | 190                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(TXDH-RXDH)                                                                                                                                                              | delay time from TXD HIGH to RXD HIGH                                                                                                                                        | Normal mode                                                                                                                                                                 | -                                                                                                                                                                           |                                                                                                                                                                             | -                                                                                                                                                                           | 190                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(TXD- buspasrec)start                                                                                                                                                    | delay time from TXD to bus passive recessive start                                                                                                                          | Normal mode                                                                                                                                                                 | [2] [3] 415                                                                                                                                                                 | -                                                                                                                                                                           |                                                                                                                                                                             | 530                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(TXD- busactrec)start                                                                                                                                                    | delay time from TXD to bus active recessive start                                                                                                                           | Normal mode                                                                                                                                                                 | [2] 70                                                                                                                                                                      | -                                                                                                                                                                           |                                                                                                                                                                             | 120                                                                                                                                                                         | ns                                                                                                                                                                          |
| t d(TXD- busactrec)end                                                                                                                                                      | delay time from TXD to bus active recessive end                                                                                                                             | Normal mode                                                                                                                                                                 | [2] 355                                                                                                                                                                     | -                                                                                                                                                                           |                                                                                                                                                                             | 480                                                                                                                                                                         | ns                                                                                                                                                                          |
| CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 | CAN FD timing characteristics according to ISO 11898-2:2024 parameter set C (t bit(TXD) ≥ 125 ns, up to 8 Mbit/s) [4] ; V CC = 4.75 V to 5.25 V; see Figure 8 and Figure 11 |
| Δt bit(bus)                                                                                                                                                                 | transmitted recessive bit width deviation                                                                                                                                   | Δt bit(bus) = t bit(bus) - t bit(TXD)                                                                                                                                       |                                                                                                                                                                             | -10                                                                                                                                                                         | -                                                                                                                                                                           | +10                                                                                                                                                                         | ns                                                                                                                                                                          |
| Δt rec                                                                                                                                                                      | receiver timing symmetry                                                                                                                                                    | Δt rec = t bit(RXD) - t bit(bus)                                                                                                                                            |                                                                                                                                                                             | -20                                                                                                                                                                         | -                                                                                                                                                                           | +15                                                                                                                                                                         | ns                                                                                                                                                                          |
| Δt bit(RXD)                                                                                                                                                                 | received recessive bit width deviation                                                                                                                                      | Δt bit(RXD) = t bit(RXD) - t bit(TXD)                                                                                                                                       | -30                                                                                                                                                                         | -                                                                                                                                                                           |                                                                                                                                                                             | +20                                                                                                                                                                         | ns                                                                                                                                                                          |
| CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        | CAN FD timing characteristics (t bit(TXD) ≥ 200 ns, up to 5 Mbit/s) [5] ; see Figure 8 and Figure 11                                                                        |
| Δt bit(bus)                                                                                                                                                                 | transmitted recessive bit width deviation                                                                                                                                   | Δt bit(bus) = t bit(bus) - t bit(TXD)                                                                                                                                       |                                                                                                                                                                             | -30                                                                                                                                                                         | -                                                                                                                                                                           | +30                                                                                                                                                                         | ns                                                                                                                                                                          |
| Δt rec                                                                                                                                                                      | receiver timing symmetry                                                                                                                                                    | Δt rec = t bit(RXD) - t bit(bus)                                                                                                                                            |                                                                                                                                                                             | -45                                                                                                                                                                         | -                                                                                                                                                                           | +15                                                                                                                                                                         | ns                                                                                                                                                                          |
| Δt bit(RXD)                                                                                                                                                                 | received recessive bit width deviation                                                                                                                                      | Δt bit(RXD) = t bit(RXD) - t bit(TXD)                                                                                                                                       | -50                                                                                                                                                                         | -                                                                                                                                                                           |                                                                                                                                                                             | +40                                                                                                                                                                         | ns                                                                                                                                                                          |
| Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     | Dominant time-out times                                                                                                                                                     |
| t to(dom)TXD                                                                                                                                                                | TXD dominant time-out time                                                                                                                                                  | V TXD = 0 V; Normal mode                                                                                                                                                    | [2] [6] 0.8                                                                                                                                                                 | -                                                                                                                                                                           |                                                                                                                                                                             | 9                                                                                                                                                                           | ms                                                                                                                                                                          |
| t to(dom)bus                                                                                                                                                                | bus dominant time-out time                                                                                                                                                  | V O(dif) > 0.9 V; Normal or Listen- Only mode                                                                                                                               | [2] [6] 0.8                                                                                                                                                                 | -                                                                                                                                                                           |                                                                                                                                                                             | 9                                                                                                                                                                           | ms                                                                                                                                                                          |
| Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         | Bus wake-up times; pins CANH and CANL; see Figure 6                                                                                                                         |
| t wake(busdom)                                                                                                                                                              | bus dominant wake-up time                                                                                                                                                   | Standby or Sleep mode                                                                                                                                                       | [2] [7]                                                                                                                                                                     | 0.5                                                                                                                                                                         | -                                                                                                                                                                           | 1.8                                                                                                                                                                         | µs                                                                                                                                                                          |
| t wake(busrec)                                                                                                                                                              | bus recessive wake-up time                                                                                                                                                  | Standby or Sleep mode                                                                                                                                                       | [2] [7]                                                                                                                                                                     | 0.5                                                                                                                                                                         | -                                                                                                                                                                           | 1.8                                                                                                                                                                         | µs                                                                                                                                                                          |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Table 9. Dynamic characteristics ...continued

Tvj  = -40 °C to +150 °C; VCC = 4.5 V to 5.5 V; VIO = 2.95 V to 5.5 V; VBAT = 4.5 V to 28 V; RL = 60 Ω unless specified otherwise; all voltages are defined with respect to ground. [1]

| Symbol                                                 | Parameter                                              | Conditions                                                                 |                                                        | Min                                                    | Typ                                                    | Max                                                    | Unit                                                   |
|--------------------------------------------------------|--------------------------------------------------------|----------------------------------------------------------------------------|--------------------------------------------------------|--------------------------------------------------------|--------------------------------------------------------|--------------------------------------------------------|--------------------------------------------------------|
| t to(wake)bus                                          | bus wake-up time-out time                              | Standby or Sleep mode                                                      | [2] [6]                                                | 0.8                                                    | -                                                      | 9                                                      | ms                                                     |
| Mode transitions; see Section 7.1 and Figure 6         | Mode transitions; see Section 7.1 and Figure 6         | Mode transitions; see Section 7.1 and Figure 6                             |                                                        |                                                        |                                                        |                                                        |                                                        |
| t t(moch)                                              | mode change transition time                            |                                                                            | [2]                                                    | -                                                      | -                                                      | 50                                                     | µs                                                     |
| t startup                                              | start-up time                                          |                                                                            | [2]                                                    | -                                                      | -                                                      | 1.5                                                    | ms                                                     |
| t startup(RXD)                                         | RXD start-up time                                      | after local or remote wake-up detected                                     | [2] [8]                                                | 4                                                      | -                                                      | 20                                                     | µs                                                     |
| t startup(INH)                                         | INH start-up time                                      | after local or remote wake-up detected; transition from Sleep to Standby   | [2] [9]                                                | 4                                                      | -                                                      | 50                                                     | µs                                                     |
| t startup(ERR_N)                                       | ERR_N start-up time                                    | after local or remote wake-up detected                                     | [2]                                                    | 4                                                      | -                                                      | 20                                                     | µs                                                     |
| t h(gotosleep)                                         | go-to-sleep hold time                                  | STB_N = LOW and EN = HIGH hold time for entering Sleep mode                | [2] [10]                                               | 24                                                     | -                                                      | 50                                                     | µs                                                     |
| t d(moch-ERR_N)                                        | delay time from mode change to ERR_N                   | to ERR_N stable in response to a mode transition                           | [2]                                                    | -                                                      | -                                                      | 20                                                     | µs                                                     |
| Local wake-up input; pin WAKE                          | Local wake-up input; pin WAKE                          | Local wake-up input; pin WAKE                                              | Local wake-up input; pin WAKE                          | Local wake-up input; pin WAKE                          | Local wake-up input; pin WAKE                          | Local wake-up input; pin WAKE                          | Local wake-up input; pin WAKE                          |
| t WAKE                                                 | wake-up time                                           | in response to a falling or rising edge on pin WAKE; Standby or Sleep mode | [11]                                                   | 20                                                     | -                                                      | 50                                                     | µs                                                     |
| IO filter; pins STB_N, EN                              | IO filter; pins STB_N, EN                              | IO filter; pins STB_N, EN                                                  | IO filter; pins STB_N, EN                              | IO filter; pins STB_N, EN                              | IO filter; pins STB_N, EN                              | IO filter; pins STB_N, EN                              | IO filter; pins STB_N, EN                              |
| t fltr(IO)                                             | I/O filter time                                        |                                                                            | [12]                                                   | 1                                                      | -                                                      | 5                                                      | µs                                                     |
| Undervoltage detection; see Section 7.1.1 and Figure 5 | Undervoltage detection; see Section 7.1.1 and Figure 5 | Undervoltage detection; see Section 7.1.1 and Figure 5                     | Undervoltage detection; see Section 7.1.1 and Figure 5 | Undervoltage detection; see Section 7.1.1 and Figure 5 | Undervoltage detection; see Section 7.1.1 and Figure 5 | Undervoltage detection; see Section 7.1.1 and Figure 5 | Undervoltage detection; see Section 7.1.1 and Figure 5 |
| t det(uv)                                              | undervoltage detection time                            | on pin VBAT                                                                | [2]                                                    | -                                                      | -                                                      | 30                                                     | µs                                                     |
| t det(uv)                                              | undervoltage detection time                            | on pin VCC                                                                 | [2]                                                    | -                                                      | -                                                      | 30                                                     | µs                                                     |
| t det(uv)                                              | undervoltage detection time                            | on pin VIO                                                                 | [2]                                                    | -                                                      | -                                                      | 30                                                     | µs                                                     |
| t det(uv)long                                          | long undervoltage detection time                       | on pins VCC and/or VIO                                                     | [2] [13]                                               | 100                                                    | -                                                      | 150                                                    | ms                                                     |
| t rec(uv)                                              | undervoltage recovery time                             | on pin VCC                                                                 | [2]                                                    | -                                                      | -                                                      | 50                                                     | µs                                                     |
| t rec(uv)                                              |                                                        | on pin VIO                                                                 | [2]                                                    | -                                                      | -                                                      | 50                                                     | µs                                                     |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

- [9] INH switches HIGH between the min and max values after a wake-up had been detected. INH is guaranteed to be floating below the min value and guaranteed to be HIGH above the max value; see Figure 6.
- [10] The device is guaranteed to switch to Sleep mode when STB\_N = LOW and EN = HIGH for longer than max value, and guaranteed not to switch to Sleep mode when less than the min value.
- [11] The device is guaranteed to wake up above 50 μs and guaranteed not to wake up below 20 μs.
- [12] Pulses shorter than the min value are guaranteed to be filtered out; pulses longer than the max value are guaranteed to be processed.
- [13] An undervoltage longer than the max value is guaranteed to force a transition to Sleep mode; an undervoltage shorter than the min value is guaranteed not to force a transition to Sleep mode.

Figure 8. CAN transceiver timing diagram according to ISO 11898-2:2024

<!-- image -->

- (1) Active recessive phase (2) Release phase.

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Figure 9. Transmitter impedance and timing diagram for dominant-to-passive recessive transition according to ISO11898-2:2024 parameter set C

<!-- image -->

## 12   Application information

## 12.1  Application diagram

<!-- image -->

## 12.2  Application hints

Further information on the application of the TJA1463 can be found in NXP application hints AH2002 'TJx144x/ TJx146x Application Hints' , available on request from NXP Semiconductors.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

## 13   Test information

<!-- image -->

<!-- image -->

## 13.1  Quality information

This product has been qualified in accordance with the Automotive Electronics Council (AEC) standard Q100 Rev-H - Failure mechanism based stress test qualification for integrated circuits , and is suitable for use in automotive applications.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

## 14   Package outline

| OUTLINE VERSION   | REFERENCES   | REFERENCES   | REFERENCES   | EUROPEAN   | ISSUE DATE        |
|-------------------|--------------|--------------|--------------|------------|-------------------|
| OUTLINE VERSION   | IEC          | JEDEC        | JEITA        | PROJECTION |                   |
| SOT108-1          | 076E06       | MS-012       |              |            | 99-12-27 03-02-19 |

<!-- image -->

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Figure 14. Package outline SOT1086-2 (HVSON14)

<!-- image -->

## 15   Handling information

All input and output pins are protected against ElectroStatic Discharge (ESD) under normal handling. When handling ensure that the appropriate precautions are taken as described in JESD625-A or equivalent standards.

## 16   Soldering of SMD packages

This text provides a very brief insight into a complex technology. A more in-depth account of soldering ICs can be found in Application Note AN10365 'Surface mount reflow soldering description' .

## 16.1  Introduction to soldering

Soldering is one of the most common methods through which packages are attached to Printed Circuit Boards (PCBs), to form electrical circuits. The soldered joint provides both the mechanical and the electrical connection. There is no single soldering method that is ideal for all IC packages. Wave soldering is often preferred when through-hole and Surface Mount Devices (SMDs) are mixed on one printed wiring board; however, it is not suitable for fine pitch SMDs. Reflow soldering is ideal for the small pitches and high densities that come with increased miniaturization.

## 16.2  Wave and reflow soldering

Wave soldering is a joining technology in which the joints are made by solder coming from a standing wave of liquid solder. The wave soldering process is suitable for the following:

- Through-hole components
- Leaded or leadless SMDs, which are glued to the surface of the printed circuit board

Not all SMDs can be wave soldered. Packages with solder balls, and some leadless packages which have solder lands underneath the body, cannot be wave soldered. Also, leaded SMDs with leads having a pitch smaller than ~0.6 mm cannot be wave soldered, due to an increased probability of bridging.

The reflow soldering process involves applying solder paste to a board, followed by component placement and exposure to a temperature profile. Leaded packages, packages with solder balls, and leadless packages are all reflow solderable.

Key characteristics in both wave and reflow soldering are:

- Board specifications, including the board finish, solder masks and vias
- Package footprints, including solder thieves and orientation
- The moisture sensitivity level of the packages
- Package placement
- Inspection and repair
- Lead-free soldering versus SnPb soldering

## 16.3  Wave soldering

Key characteristics in wave soldering are:

- Process issues, such as application of adhesive and flux, clinching of leads, board transport, the solder wave parameters, and the time during which components are exposed to the wave
- Solder bath specifications, including temperature and impurities

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

## 16.4  Reflow soldering

Key characteristics in reflow soldering are:

- Lead-free versus SnPb soldering; note that a lead-free reflow process usually leads to higher minimum peak temperatures (see Figure 15) than a SnPb process, thus reducing the process window
- Solder paste printing issues including smearing, release, and adjusting the process window for a mix of large and small components on one board
- Reflow temperature profile; this profile includes preheat, reflow (in which the board is heated to the peak temperature) and cooling down. It is imperative that the peak temperature is high enough for the solder to make reliable solder joints (a solder paste characteristic). In addition, the peak temperature must be low enough that the packages and/or boards are not damaged. The peak temperature of the package depends on package thickness and volume and is classified in accordance with Table 10 and Table 11

Table 10. SnPb eutectic process (from J-STD-020D)

| Package thickness (mm)   | Package reflow temperature (°C)   | Package reflow temperature (°C)   |
|--------------------------|-----------------------------------|-----------------------------------|
|                          | Volume (mm³)                      | Volume (mm³)                      |
|                          | < 350                             | ≥ 350                             |
| < 2.5                    | 235                               | 220                               |
| ≥ 2.5                    | 220                               | 220                               |

Table 11. Lead-free process (from J-STD-020D)

| Package thickness (mm)   | Package reflow temperature (°C)   | Package reflow temperature (°C)   | Package reflow temperature (°C)   |
|--------------------------|-----------------------------------|-----------------------------------|-----------------------------------|
|                          | Volume (mm³)                      | Volume (mm³)                      | Volume (mm³)                      |
|                          | < 350                             | 350 to 2000                       | > 2000                            |
| < 1.6                    | 260                               | 260                               | 260                               |
| 1.6 to 2.5               | 260                               | 250                               | 245                               |
| > 2.5                    | 250                               | 245                               | 245                               |

Moisture sensitivity precautions, as indicated on the packing, must be respected at all times.

Studies have shown that small packages reach higher temperatures during reflow soldering, see Figure 15.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

For further information on temperature profiles, refer to Application Note AN10365 'Surface mount reflow soldering description' .

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

## 17   Appendix: ISO 11898-2:2024 parameter cross-reference lists

## Table 12. ISO 11898-2:2024 to NXP data sheet parameter conversion [1]

| ISO 11898-2:2024                                                                                               |                                                                                                                | NXP data sheet                                                                                                 | NXP data sheet                                                                                                 |
|----------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Parameter                                                                                                      | Notation                                                                                                       | Symbol                                                                                                         | Parameter                                                                                                      |
| HS-PMA maximum ratings of V CAN_H , V CAN_L and V Diff                                                         | HS-PMA maximum ratings of V CAN_H , V CAN_L and V Diff                                                         | HS-PMA maximum ratings of V CAN_H , V CAN_L and V Diff                                                         | HS-PMA maximum ratings of V CAN_H , V CAN_L and V Diff                                                         |
| Maximum rating                                                                                                 | V Diff                                                                                                         | V (CANH-CANL)                                                                                                  | voltage between pin CANH and pin CANL                                                                          |
| General maximum rating                                                                                         | V CAN_H                                                                                                        | V x                                                                                                            | voltage on pin x                                                                                               |
| Optional: Extended maximum rating V CAN_L HS-PMA recessive output characteristics, bus biasing active/inactive | Optional: Extended maximum rating V CAN_L HS-PMA recessive output characteristics, bus biasing active/inactive | Optional: Extended maximum rating V CAN_L HS-PMA recessive output characteristics, bus biasing active/inactive | Optional: Extended maximum rating V CAN_L HS-PMA recessive output characteristics, bus biasing active/inactive |
| Single ended output voltage on CAN_H                                                                           | V CAN_H                                                                                                        | V O(rec)                                                                                                       | recessive output voltage                                                                                       |
| Single ended output voltage on CAN_L                                                                           | V CAN_L                                                                                                        |                                                                                                                |                                                                                                                |
| Differential output voltage                                                                                    | V Diff                                                                                                         | V O(dif)                                                                                                       | differential output voltage                                                                                    |
| HS-PMA dominant output characteristics                                                                         | HS-PMA dominant output characteristics                                                                         | HS-PMA dominant output characteristics                                                                         | HS-PMA dominant output characteristics                                                                         |
| Single ended voltage on CAN_H                                                                                  | V CAN_H                                                                                                        | V O(dom)                                                                                                       | dominant output voltage                                                                                        |
| Single ended voltage on CAN_L                                                                                  | V CAN_L                                                                                                        |                                                                                                                |                                                                                                                |
| Differential voltage on normal bus load                                                                        | V Diff                                                                                                         | V O(dif)                                                                                                       | differential output voltage                                                                                    |
| Differential voltage on effective resistance during arbitration                                                |                                                                                                                |                                                                                                                |                                                                                                                |
| Optional: Differential voltage on extended bus load range                                                      |                                                                                                                |                                                                                                                |                                                                                                                |
| Maximum HS-PMA driver output current                                                                           | Maximum HS-PMA driver output current                                                                           | Maximum HS-PMA driver output current                                                                           | Maximum HS-PMA driver output current                                                                           |
| Absolute current on CAN_H                                                                                      | I CAN_H                                                                                                        | I O(sc)                                                                                                        | short-circuit output current                                                                                   |
| Absolute current on CAN_L                                                                                      | I CAN_L                                                                                                        |                                                                                                                |                                                                                                                |
| HS-PMA static receiver input characteristics, bus biasing active/inactive                                      | HS-PMA static receiver input characteristics, bus biasing active/inactive                                      | HS-PMA static receiver input characteristics, bus biasing active/inactive                                      | HS-PMA static receiver input characteristics, bus biasing active/inactive                                      |
| Recessive state differential input voltage range Dominant state differential input voltage range               | V Diff                                                                                                         | V th(RX)dif                                                                                                    | differential receiver threshold voltage                                                                        |
| Recessive state differential input voltage range Dominant state differential input voltage range               | V Diff                                                                                                         | V rec(RX)                                                                                                      | receiver recessive voltage                                                                                     |
| Recessive state differential input voltage range Dominant state differential input voltage range               | V Diff                                                                                                         | V dom(RX)                                                                                                      | receiver dominant voltage                                                                                      |
| HS-PMA receiver input resistance (matching)                                                                    | HS-PMA receiver input resistance (matching)                                                                    | HS-PMA receiver input resistance (matching)                                                                    | HS-PMA receiver input resistance (matching)                                                                    |
| Differential internal resistance                                                                               | R DIFF_pas_rec                                                                                                 | R i(dif)                                                                                                       | differential input resistance                                                                                  |
| Single-ended internal resistance                                                                               | R SE_pas_rec_H R SE_pas_rec_L                                                                                  | R i                                                                                                            | input resistance                                                                                               |
| Matching of internal resistance                                                                                | m R                                                                                                            | ΔR i                                                                                                           | input resistance deviation                                                                                     |
| HS-PMA maximum leakage currents on CAN_H and CAN_L, unpowered                                                  | HS-PMA maximum leakage currents on CAN_H and CAN_L, unpowered                                                  | HS-PMA maximum leakage currents on CAN_H and CAN_L, unpowered                                                  | HS-PMA maximum leakage currents on CAN_H and CAN_L, unpowered                                                  |
| Leakage current on CAN_H, CAN_L                                                                                | I CAN_H I CAN_L                                                                                                | I L                                                                                                            | leakage current                                                                                                |
| HS-PMA driver symmetry                                                                                         | HS-PMA driver symmetry                                                                                         | HS-PMA driver symmetry                                                                                         | HS-PMA driver symmetry                                                                                         |
| Driver symmetry                                                                                                | V sym_vcc                                                                                                      | V TXsym                                                                                                        | transmitter voltage symmetry                                                                                   |
| Optional HS-PMA transmit dominant time-out                                                                     | Optional HS-PMA transmit dominant time-out                                                                     | Optional HS-PMA transmit dominant time-out                                                                     | Optional HS-PMA transmit dominant time-out                                                                     |
| Transmit dominant time-out                                                                                     | t dom                                                                                                          | t to(dom)TXD                                                                                                   | TXD dominant time-out time                                                                                     |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Table 12. ISO 11898-2:2024 to NXP data sheet parameter conversion [1] ...continued

| ISO 11898-2:2024                                                                    |                                                                                     | NXP data sheet                                                                      | NXP data sheet                                                                      |
|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| Parameter                                                                           | Notation                                                                            | Symbol                                                                              | Parameter                                                                           |
| HS-PMA implementation loop delay requirements for parameter sets A, B and C         | HS-PMA implementation loop delay requirements for parameter sets A, B and C         | HS-PMA implementation loop delay requirements for parameter sets A, B and C         | HS-PMA implementation loop delay requirements for parameter sets A, B and C         |
| Loop delay for parameter sets A and B                                               | t Loop                                                                              | t d(TXDH-RXDH)                                                                      | delay time from TXD HIGH to RXD HIGH                                                |
| Loop delay for parameter set C                                                      |                                                                                     | t d(TXDL-RXDL)                                                                      | delay time from TXD LOW to RXD LOW                                                  |
| Propagation delay from TXD to CAN_H/CAN_L for parameter set C                       | t prop(TXD_BUS)                                                                     | t d(TXD-busdom)                                                                     | delay time from TXD to bus dominant                                                 |
| Propagation delay from CAN_H/CAN_L to RXD for parameter set C                       |                                                                                     | t d(TXD-busrec)                                                                     | delay time from TXD to bus recessive                                                |
|                                                                                     | t prop(BUS_RXD)                                                                     | t d(busdom-RXD)                                                                     | delay time from bus dominent to RXD                                                 |
|                                                                                     |                                                                                     | t d(busrec-RXD)                                                                     | delay time from bus recessive to RXD                                                |
| HS-PMA implementation data signal timing requirements for parameter sets A, B and C | HS-PMA implementation data signal timing requirements for parameter sets A, B and C | HS-PMA implementation data signal timing requirements for parameter sets A, B and C | HS-PMA implementation data signal timing requirements for parameter sets A, B and C |
| Transmitted recessive bit width variation                                           | t ΔBit(Bus)                                                                         | Δt bit(bus)                                                                         | transmitted recessive bit width deviation                                           |
| Received recessive bit width variation                                              | t ΔBit(RXD)                                                                         | Δt bit(RXD)                                                                         | received recessive bit width deviation                                              |
| Receiver timing symmetry                                                            | t ΔREC                                                                              | Δt rec                                                                              | receiver timing symmetry                                                            |
| HS-PMA implementation SIC timing and impedance for parameter set C                  | HS-PMA implementation SIC timing and impedance for parameter set C                  | HS-PMA implementation SIC timing and impedance for parameter set C                  | HS-PMA implementation SIC timing and impedance for parameter set C                  |
| Differential internal resistance (CAN_H to CAN_L)                                   | R DIFF_act_rec                                                                      | R i(dif)actrec                                                                      | active recessive phase differential input resistance                                |
| Internal single-ended resistance                                                    | R SE_act_rec                                                                        | R i(actrec)                                                                         | active recessive phase input resistance                                             |
| Start time of active signal improvement phase                                       | t act_rec_start                                                                     | t d(TXD- busactrec)start                                                            | delay time from TXD to bus active recessive start                                   |
| End time of active signal improvement phase                                         | t act_rec_end                                                                       | t d(TXD- busactrec)end                                                              | delay time from TXD to bus active recessive end                                     |
| Start time of passive recessive phase                                               | t pas_rec_start                                                                     | t d(TXD- buspasrec)start                                                            | delay time from TXD to bus passive recessive start                                  |
| PMA voltage wake-up control timing                                                  | PMA voltage wake-up control timing                                                  | PMA voltage wake-up control timing                                                  | PMA voltage wake-up control timing                                                  |
| CAN activity filter time, long/short                                                | t Filter                                                                            | t wake(busdom) t wake(busrec)                                                       | bus dominant wake-up time bus recessive wake-up time                                |
| Wake-up time-out                                                                    | t Wake                                                                              | t to(wake)bus                                                                       | bus wake-up time-out time                                                           |
| Wake-up pattern signaling                                                           | t Flag                                                                              | t startup(RXD)                                                                      | RXD start-up time                                                                   |
| Wake-up pattern signaling                                                           |                                                                                     | t startup(INH)                                                                      | INH start-up time                                                                   |
| Wake-up pattern signaling                                                           |                                                                                     | t startup(ERR_N)                                                                    | ERR_N start-up time                                                                 |
| Number of recessive bits before next SOF                                            | Number of recessive bits before next SOF                                            | Number of recessive bits before next SOF                                            | Number of recessive bits before next SOF                                            |
| Number of recessive bits before a new SOF shall be accepted                         | n Bits_idle                                                                         | N bit(idle)                                                                         | number of idle bits before a SOF is accepted                                        |
| BitFilter in CAN FD data phase                                                      | BitFilter in CAN FD data phase                                                      | BitFilter in CAN FD data phase                                                      | BitFilter in CAN FD data phase                                                      |
| CAN FD data phase bitfilter (option 1)                                              | ρ Bitfilter_option1                                                                 | t fltr(bit)dom                                                                      | dominant bit filter time                                                            |
| CAN FD data phase bitfilter (option 2)                                              | ρ Bitfilter_option2                                                                 |                                                                                     |                                                                                     |
| HS-PMA bus biasing control timing                                                   | HS-PMA bus biasing control timing                                                   | HS-PMA bus biasing control timing                                                   | HS-PMA bus biasing control timing                                                   |
| Time-out for bus inactivity                                                         | t Silence                                                                           | t to(silence)                                                                       | bus silence time-out time                                                           |
| Bus bias reaction time                                                              | t Bias                                                                              | t d(busact-bias)                                                                    | bus bias reaction time                                                              |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

[1] A number of proprietary NXP parameters are equivalent to parameters defined in ISO 11898-2:2024, but use different symbols. This conversion table allows ISO parameters to be cross-referenced with their NXP counterparts. The NXP parameters are defined in the Static and Dynamic characteristics tables. The conversion table provides a comprehensive listing - individual devices may not include all parameters.

## 18   Appendix: TJx14(41/42/43/48)x, TJx14(62/63)x , TJF1441 family overview

Table 13. Feature overview of the complete TJx14(41/42/43/48)x, TJx14(62/63)x , TJF1441 family

|            | Modes   | Modes   | Modes   | Modes              | Supplies   | Supplies   | Supplies   | Data rate             | Data rate                 | Additional features    | Additional features            | Additional features                  | Additional features           | Additional features   | Additional features             |
|------------|---------|---------|---------|--------------------|------------|------------|------------|-----------------------|---------------------------|------------------------|--------------------------------|--------------------------------------|-------------------------------|-----------------------|---------------------------------|
| Device [1] | Normal  | Standby | Sleep   | Silent/Listen-only | VCC pin    | VIO pin    | VBAT pin   | Up to 5 Mbit/s CAN FD | Up to 8 Mbit/s CAN FD [2] | Signal improvement [3] | Wake-up source recognition [4] | Short WUP support [0.5 - 1.8 µs] [5] | Single supply pin wake-up [6] | TXD dominant time-out | Local diagnostics via ERR_N pin |
| TJx1441A   | ●       |         |         | ●                  | ●          | ●          |            | ●                     |                           |                        |                                |                                      |                               | ●                     |                                 |
| TJx1441B   | ●       |         |         | ●                  | ●          |            |            | ●                     |                           |                        |                                |                                      |                               | ●                     |                                 |
| TJx1441D   | ●       |         |         | ●                  | ●          |            |            | ●                     |                           |                        |                                |                                      |                               | ●                     |                                 |
| TJF1441A   | ●       |         |         | ●                  | ●          | ●          |            | ●                     |                           |                        |                                |                                      |                               | [7]                   |                                 |
| TJx1442A   | ●       | ●       |         |                    | ●          | ●          |            | ●                     |                           |                        |                                | ●                                    | ●                             | ●                     |                                 |
| TJx1442B   | ●       | ●       |         |                    | ●          |            |            | ●                     |                           |                        |                                | ●                                    |                               | ●                     |                                 |
| TJx1443A   | ●       | ●       | ●       | ●                  | ●          | ●          | ●          | ●                     |                           |                        | ●                              | ●                                    | ●                             | ●                     | ●                               |
| TJx1448A   | ●       | ●       |         |                    | ●          | ●          |            | ●                     |                           |                        |                                | ●                                    | ●                             | ●                     |                                 |
| TJx1448B   | ●       | ●       |         |                    | ●          |            |            | ●                     |                           |                        |                                | ●                                    |                               | ●                     |                                 |
| TJx1448C   | ●       | ●       |         |                    | ●          | ●          |            | ●                     |                           |                        | ●                              | ●                                    | ●                             | ●                     |                                 |
| TJx1462A   | ●       | ●       |         |                    | ●          | ●          |            | ●                     | ●                         | ●                      |                                | ●                                    | ●                             | ●                     |                                 |
| TJx1462B   | ●       | ●       |         |                    | ●          |            |            | ●                     | ●                         | ●                      |                                | ●                                    |                               | ●                     |                                 |
| TJx1463A   | ●       | ●       | ●       | ●                  | ●          | ●          | ●          | ●                     | ●                         | ●                      | ●                              | ●                                    | ●                             | ●                     | ●                               |

## 19   Revision history

Table 14. Revision history

| Document ID   | Release date     | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
|---------------|------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| TJA1463 v.3.0 | 12 February 2025 | • ISO 11898-2:2016 upgraded to ISO 11898-2:2024 throughout • Replaced CiA 601-4:2019 with ISO 11898-2:2024 parameter set C throughout • Section 2.1: 3rd list item revised (on bit timing symmetry) • Table 3: table title and table notes 2 and 4 amended • Section 7.1.1.5: text of last list item amended (STB_N = HIGH added) • Section 7.2.2.1: text changed ('timer' changed to 't wake timer') • Section 7.2.2.2: text of 1st and 4th paragraphs amended (t startup(ERR_N) added in 4th paragraph) • Section 7.5: text revised • Table 6: - parameter I r(VBAT) added; V x : pin VBAT min value removed - SAE J2962-2:2019 V ESD entries added • Table 8: - measurement conditions amended: I CC , I BAT , I O(sc)rec , I L , R i , ΔR i , R i(dif) - values changed: V rec(RX) - parameters deleted: R i(extdom) , R i(dif)extdom - table notes 7 and 8 (now 9) revised - table notes 8 and 10 added • Table 9: - formatting of CAN (FD) timing characteristics revised (including table notes) - parameters added: t d(TXD-buspasrec)start , t startup(ERR_N) - parameter value changed: t d(TXD-busactrec)end (min) - parameters deleted: t d(TXD-busrec)end , t d(TXD-busdom)end , t d(extbusdom)end • Original Figs. 7 and 8 combined in new single Figure 8 • Redundant Fig. 11 removed • Figure 9 revised (absolute values deleted) • Original Section 17 deleted • Section 18: section title, table title and table notes 2, 3 and 5 amended • Section 17: cross-reference tables updated • Legal information: HTML publications disclaimer added |
| TJA1463 v.2.0 | 15 October 2021  | -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| TJA1463 v.1.0 | 12 August 2020   | • Initial version                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

## Legal information

## Data sheet status

| Document status [1][2]         | Product status [3]   | Definition                                                                            |
|--------------------------------|----------------------|---------------------------------------------------------------------------------------|
| Objective [short] data sheet   | Development          | This document contains data from the objective specification for product development. |
| Preliminary [short] data sheet | Qualification        | This document contains data from the preliminary specification.                       |
| Product [short] data sheet     | Production           | This document contains the product specification.                                     |

- [1] Please consult the most recently issued document before initiating or completing a design.

[2] The term 'short data sheet' is explained in section "Definitions".

- [3] The product status of device(s) described in this document may have changed since this document was published and may differ in case of multiple devices. The latest product status information is available on the Internet at URL https://www.nxp.com.

## Definitions

Draft - A draft status on a document indicates that the content is still under internal review and subject to formal approval, which may result in modifications or additions. NXP Semiconductors does not give any representations or warranties as to the accuracy or completeness of information included in a draft version of a document and shall have no liability for the consequences of use of such information.

Short data sheet - A short data sheet is an extract from a full data sheet with the same product type number(s) and title. A short data sheet is intended for quick reference only and should not be relied upon to contain detailed and full information. For detailed and full information see the relevant full data sheet, which is available on request via the local NXP Semiconductors sales office. In case of any inconsistency or conflict with the short data sheet, the full data sheet shall prevail.

Product specification - The information and data provided in a Product data sheet shall define the specification of the product as agreed between NXP Semiconductors and its customer, unless NXP Semiconductors and customer have explicitly agreed otherwise in writing. In no event however, shall an agreement be valid in which the NXP Semiconductors product is deemed to offer functions and qualities beyond those described in the Product data sheet.

## Disclaimers

Limited warranty and liability - Information in this document is believed to be accurate and reliable. However, NXP Semiconductors does not give any representations or warranties, expressed or implied, as to the accuracy or completeness of such information and shall have no liability for the consequences of use of such information. NXP Semiconductors takes no responsibility for the content in this document if provided by an information source outside of NXP Semiconductors.

In no event shall NXP Semiconductors be liable for any indirect, incidental, punitive, special or consequential damages (including - without limitation lost profits, lost savings, business interruption, costs related to the removal or replacement of any products or rework charges) whether or not such damages are based on tort (including negligence), warranty, breach of contract or any other legal theory.

Notwithstanding any damages that customer might incur for any reason whatsoever, NXP Semiconductors' aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms and conditions of commercial sale of NXP Semiconductors.

Right to make changes - NXP Semiconductors reserves the right to make changes to information published in this document, including without limitation specifications and product descriptions, at any time and without notice. This document supersedes and replaces all information supplied prior to the publication hereof.

Applications - Applications that are described herein for any of these products are for illustrative purposes only. NXP Semiconductors makes no representation or warranty that such applications will be suitable for the specified use without further testing or modification.

Customers are responsible for the design and operation of their applications and products using NXP Semiconductors products, and NXP Semiconductors accepts no liability for any assistance with applications or customer product design. It is customer's sole responsibility to determine whether the NXP Semiconductors product is suitable and fit for the customer's applications and products planned, as well as for the planned application and use of customer's third party customer(s). Customers should provide appropriate design and operating safeguards to minimize the risks associated with their applications and products.

NXP Semiconductors does not accept any liability related to any default, damage, costs or problem which is based on any weakness or default in the customer's applications or products, or the application or use by customer's third party customer(s). Customer is responsible for doing all necessary testing for the customer's applications and products using NXP Semiconductors products in order to avoid a default of the applications and the products or of the application or use by customer's third party customer(s). NXP does not accept any liability in this respect.

Limiting values - Stress above one or more limiting values (as defined in the Absolute Maximum Ratings System of IEC 60134) will cause permanent damage to the device. Limiting values are stress ratings only and (proper) operation of the device at these or any other conditions above those given in the Recommended operating conditions section (if present) or the Characteristics sections of this document is not warranted. Constant or repeated exposure to limiting values will permanently and irreversibly affect the quality and reliability of the device.

Terms and conditions of commercial sale - NXP Semiconductors products are sold subject to the general terms and conditions of commercial sale, as published at https://www.nxp.com/profile/terms, unless otherwise agreed in a valid written individual agreement. In case an individual agreement is concluded only the terms and conditions of the respective agreement shall apply. NXP Semiconductors hereby expressly objects to applying the customer's general terms and conditions with regard to the purchase of NXP Semiconductors products by customer.

No offer to sell or license - Nothing in this document may be interpreted or construed as an offer to sell products that is open for acceptance or the grant, conveyance or implication of any license under any copyrights, patents or other industrial or intellectual property rights.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode

<!-- image -->

## CAN FD signal improvement transceiver with Sleep mode

Suitability for use in automotive applications - This NXP product has been qualified for use in automotive applications. If this product is used by customer in the development of, or for incorporation into, products or services (a) used in safety critical applications or (b) in which failure could lead to death, personal injury, or severe physical or environmental damage (such products and services hereinafter referred to as 'Critical Applications'), then customer makes the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, safety, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP. As such, customer assumes all risk related to use of any products in Critical Applications and NXP and its suppliers shall not be liable for any such use by customer. Accordingly, customer will indemnify and hold NXP harmless from any claims, liabilities, damages and associated costs and expenses (including attorneys' fees) that NXP may incur related to customer's incorporation of any product in a Critical Application.

Translations - A non-English (translated) version of a document, including the legal information in that document, is for reference only. The English version shall prevail in case of any discrepancy between the translated and English versions.

Quick reference data - The Quick reference data is an extract of the product data given in the Limiting values and Characteristics sections of this document, and as such is not complete, exhaustive or legally binding.

Export control - This document as well as the item(s) described herein may be subject to export control regulations. Export might require a prior authorization from competent authorities.

HTML publications - An HTML version, if available, of this document is provided as a courtesy. Definitive information is contained in the applicable document in PDF format. If there is a discrepancy between the HTML document and the PDF document, the PDF document has priority.

Security - Customer understands that all NXP products may be subject to unidentified vulnerabilities or may support established security standards or specifications with known limitations. Customer is responsible for the design and operation of its applications and products throughout their lifecycles to reduce the effect of these vulnerabilities on customer's applications and products. Customer's responsibility also extends to other open and/or proprietary technologies supported by NXP products for use in customer's applications. NXP accepts no liability for any vulnerability. Customer should regularly check security updates from NXP and follow up appropriately. Customer shall select products with security features that best meet rules, regulations, and standards of the intended application and make the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP.

NXP has a Product Security Incident Response Team (PSIRT) (reachable at PSIRT@nxp.com) that manages the investigation, reporting, and solution release to security vulnerabilities of NXP products.

NXP B.V. - NXP B.V. is not an operating company and it does not distribute or sell products.

## Trademarks

Notice: All referenced brands, product names, service names, and trademarks are the property of their respective owners.

NXP - wordmark and logo are trademarks of NXP B.V.

## Contents

| 1         | General description .........................................1                                                                   |    | 13.1   | Quality information ...........................................28   |    |
|-----------|----------------------------------------------------------------------------------------------------------------------------------|----|--------|---------------------------------------------------------------------|----|
| 2         | Features and benefits ..................................... 1                                                                    |    | 14     | Package outline .............................................       | 29 |
| 2.1       | General ..............................................................1                                                          |    | 15     | Handling information .....................................31        |    |
| 2.2       | Predictable and fail-safe behavior .....................                                                                         | 2  | 16     | Soldering of SMD packages .........................                 | 31 |
| 2.3       | Low-power management ...................................                                                                         | 2  | 16.1   | Introduction to soldering .............................             |    |
| 2.4       | Diagnosis & Protection ......................................2                                                                   |    | 16.2   | Wave and reflow soldering .........................                 |    |
| 3         | Quick reference data .......................................3                                                                    |    | 16.3   | Wave soldering ...........................................          |    |
| 4         | Ordering information .......................................3                                                                    |    | 16.4   | Reflow soldering .........................................          |    |
| 5         | Block diagram ..................................................5                                                                |    | 17     | Appendix: ISO 11898-2:2024 parameter                                |    |
| 6         | Pinning information .........................................6                                                                   |    |        | cross-reference lists ......................................34      |    |
| 6.1       | Pinning ...............................................................6                                                         |    | 18     | Appendix: TJx14(41/42/43/48)x,                                      |    |
| 6.2       | Pin description                                                                                                                  |    |        | TJx14(62/63)x , TJF1441 family overview ....                        | 36 |
| 7         | ...................................................6 Functional description ....................................                 | 7  | 19     | Revision history .............................................37    |    |
| 7.1       | Operating modes ...............................................7                                                                 |    |        | Legal information ...........................................38     |    |
| 7.1.1     | System operating modes ...................................7                                                                      |    |        |                                                                     |    |
| 7.1.1.1   | Off mode ............................................................7                                                           |    |        |                                                                     |    |
| 7.1.1.2   | Standby mode ...................................................                                                                 | 8  |        |                                                                     |    |
| 7.1.1.3   | Normal mode .....................................................8                                                               |    |        |                                                                     |    |
| 7.1.1.4   | Listen-only mode ...............................................                                                                 | 8  |        |                                                                     |    |
| 7.1.1.5   | Sleep mode .......................................................                                                               | 8  |        |                                                                     |    |
| 7.1.1.6   | System operating modes and gap-free operation ............................................................8                      |    |        |                                                                     |    |
| 7.1.2     | CAN operating modes .....................................10                                                                      |    |        |                                                                     |    |
| 7.1.2.1   | CAN Off mode .................................................10                                                                 |    |        |                                                                     |    |
| 7.1.2.2   | CAN Offline mode ...........................................                                                                     | 10 |        |                                                                     |    |
| 7.1.2.3   | CAN Wake mode .............................................11                                                                    |    |        |                                                                     |    |
| 7.1.2.4   | CAN Pass-through mode .................................11                                                                        |    |        |                                                                     |    |
| 7.1.2.5   | CAN Active mode ............................................11                                                                   |    |        |                                                                     |    |
| 7.1.2.6   | CAN Listen-only mode .....................................11                                                                     |    |        |                                                                     |    |
| 7.2       | Internal flags ....................................................11                                                            |    |        |                                                                     |    |
| 7.2.1     | Pwon flag .........................................................12                                                            |    |        |                                                                     |    |
| 7.2.2     | Wake flag .........................................................12                                                            |    |        |                                                                     |    |
| 7.2.2.1   | Local wake-up (via WAKE pin) ........................12                                                                          |    |        |                                                                     |    |
| 7.2.2.2   | Remote wake-up (via the CAN bus) ................12                                                                              |    |        |                                                                     |    |
| 7.2.3     | Wake-up source flag ........................................13                                                                   |    |        |                                                                     |    |
| 7.2.4     | Local failure flag ..............................................                                                                | 13 |        |                                                                     |    |
| 7.3       | Local failure events .........................................                                                                   | 13 |        |                                                                     |    |
| 7.3.1     | TXD dominant failures .....................................14                                                                    |    |        |                                                                     |    |
| 7.3.2     | TXD-to-RXD short circuit .................................14                                                                     |    |        |                                                                     |    |
| 7.3.3     | Bus dominant failures ......................................14                                                                   |    |        |                                                                     |    |
| 7.3.4     | Overtemperature ..............................................14                                                                 |    |        |                                                                     |    |
| 7.4       | I/O levels ..........................................................14                                                          |    |        |                                                                     |    |
| 7.5       | WAKE pin ........................................................                                                                | 14 |        |                                                                     |    |
| 7.6       | Internal biasing of TXD, STB_N and EN input pins .........................................................15                     |    |        |                                                                     |    |
| 8         | Limiting values ...............................................16                                                                |    |        |                                                                     |    |
| 9         | Thermal characteristics ................................                                                                         | 18 |        |                                                                     |    |
| 10        | Static characteristics .....................................18                                                                   |    |        |                                                                     |    |
| 11        | Dynamic characteristics ...............................                                                                          | 23 |        |                                                                     |    |
| 12        | Application information ................................                                                                         | 27 |        |                                                                     |    |
| 12.1 12.2 | Application diagram .........................................27 Application hints .............................................. | 27 |        |                                                                     |    |
|           | .............................................28                                                                                  |    |        |                                                                     |    |
| 13        | Test information                                                                                                                 |    |        |                                                                     |    |

Please be aware that important notices concerning this document and the product(s) described herein, have been included in section 'Legal information'.

<!-- image -->

CAN FD signal improvement transceiver with Sleep mode