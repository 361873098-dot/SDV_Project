<!-- image -->

## VSS Data Management Intelligent

<!-- image -->

## Intelligent VSS Data Management

## Demonstrating CAN to COVESA Vehicle Signal Specification (VSS) data management solution

Gergely Simon, Principal Engineer, Automotive System Engineering and Marketing, NXP Semiconductors

Curt Hillier, Fellow, Automotive System Engineering and Marketing, NXP Semiconductors

Tristan McDaniel, Automotive Applications and Systems Engineer, NXP Semiconductors

Thomas Hentschel, Solutions Architect, aicas GmbH

## Table of contents

| Introduction and market motivation ........................................................................................3                                   |    |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------|----|
| Signal selection/pre-processing at the edge.....................................................................4                                              |    |
| COVESA Vehicle Signal Specification (VSS)..........................................................................4                                           |    |
| AWS IoT FleetWise and VSS .............................................................................................................5                       |    |
| System overview.....................................................................................................................................6          |    |
| Signal walkthrough...............................................................................................................................7             |    |
| NXP GreenBox 3.......................................................................................................................................8         |    |
| S32G3 GoldBox service-oriented gateway............................................................................9                                            |    |
| Edge processing and signal selection.....................................................................................                                      | 10 |
| Signal conversion and normalization.......................................................................................                                     | 11 |
| Signal selection via Data Collection Scheme (DCS)......................................................                                                        | 12 |
| Signal transfer..........................................................................................................................................      | 13 |
| Simulated vehicle fleet.......................................................................................................................                 | 13 |
| Real-time data dashboards in aicas EDG.............................................................................                                            | 13 |
| Product list.................................................................................................................................................. | 13 |
| aicas contributions...............................................................................................................................             | 13 |
| NXP contributions...................................................................................................................................           | 14 |
| AWS contributions .................................................................................................................................            | 14 |
| Conclusion..................................................................................................................................................   | 14 |
| Appendix...................................................................................................................................................... | 15 |

## Introduction and market motivation

Vehicle telemetry and signal data collection has been conducted for several decades, with the initial motivations being government-mandated emission checks and diagnosing vehicle faults at service centers. Previously, diagnostic tools required a wired connection to the backend system.

With the advent of relatively cheap wireless technology, such as LTE or 5G, and transmission protocols from the Internet of Things (IoT) world, vehicle Original Equipment Manufacturers (OEMs) have been embarking on ways to bring this vehicle signal data into their data centers while the vehicle is being used. However, the current ways of doing so have several limitations.

For one, there is no common taxonomy which defines the vehicle's logical signal makeup in a common way across the board. Current vehicle signal definitions are either proprietary (i.e., Controller Area Network CAN .dbc), or in the case of OBD-II, centered around emission and engine performance.

In the case of CAN signals, vehicle definitions from the same manufacturer (or even the same model line) can differ widely and typically have no required meta-information (such as unit, min/max, signal frequency) associated. For standardized OBD-II signals, a large set of signals that may be helpful are not defined and thus not available - i.e., in order to determine the context of a situation.

Second, the quality of those signals can wildly differ in their accuracy and sampling frequency between manufacturers and between vehicle models. To normalize these signals to a common base requires proprietary information and in-depth knowledge of each vehicle model.

Third, even though there have been efforts to create a more common view and implementation of vehicle internals such as AUTOSAR, these efforts tend to be proprietary and not openly published.

Fourth, even with the advances of wireless transmission technology, it may not be feasible to transmit all or even most signals that a vehicle generates. Given the number of discrete signals and image feeds that a modern vehicle can generate, a smart and flexible way based-on common standards is required that selects the signal data transmitted to the data centers, which can be changed over the lifetime of the vehicle.

Finally, it is no longer just the automotive manufacturers that have a high interest in creating a live view into the performance of their fleet. It's also rental car companies, insurers and large fleet managers that show keen interest. OEMs need to be able to accommodate those needs.

Figure 1: Vehicle Signal Specification (VSS) data management solution Source: aicas GmbH, 2024

<!-- image -->

## Signal selection/pre-processing at the edge

The proposed solution, which is implemented in the joint demonstration between NXP and aicas, is to use the available compute power of a vehicle edge gateway like the NXP® S32G3 Vehicle Network Processor, and implement vehicle target agent software with the following characteristics:

-  It uses a common vehicle taxonomy based on an open standard (COVESA 'Vehicle Signal Specification' - VSS), which creates a logical view of the vehicles that is the same for all users of the system.
-  The necessary (meta) information to normalize the signal data is part of the VSS signal specification for each vehicle model, which is applied in the vehicle gateway. This means the data is normalized to a common standard before it leaves the vehicle, and thus all data that is ingested in the data center is of a common taxonomy, format, and type.
-  The common logical view of the vehicle models, and generic format of the signal data now allows us to develop a data collection scheme which is applied inside the vehicle gateway, and which allows for flexible, scenario-based selection of data to be sent to the data center.
-  To make the development of this collection scheme as easy as possible, we utilize a graphical editor that shows the data collection management of the target system as a flow, where raw signal inputs send their data to logical 'nodes' (functions), which determine when the signal data is eligible to be sent from the vehicle to the data center.
-  The flexibility of this approach also lets us synthesize signals from existing raw data, or map additional, non-standard signals into the collection scheme.

## COVESA Vehicle Signal Specification (VSS)

The Vehicle Signal Specification (VSS) created by COVESA introduces a domain taxonomy for vehicle signals. In short, this means that VSS introduces:

-  A catalog of signals related to vehicles
-  A syntax for defining and organizing vehicle signals in a structured manner

VSS serves as a standard in automotive applications to communicate information around the logical composition of the vehicle, which is semantically well defined. It focuses on vehicle signals, in the sense of classical attributes, sensors and actuators with the raw data communicated over vehicle buses.

The VSS for a particular vehicle forms a JavaScript Object Notation (JSON) structure as a named tree, with branches organizing vehicle subsystems, and leaf objects defining sensors or actuators in the vehicle. Individual leaf objects are defined by their properties, such as the data type, unit, min/max values, and similar.

Figure 2 shows how the VSS signal catalog for a particular vehicle type is displayed in the application.

Figure 2: COVESA Vehicle Signal Specification

<!-- image -->

| Vehicle                                        |
|------------------------------------------------|
| Vehicle.ABS                                    |
| Vehicle.Chassis                                |
| Vehicle.Chassis.Odometer                       |
| Vehicle.Chassis.OutsideHumidity                |
| Vehicle.Chassis.OutsideTemperature             |
| Vehicle.Chassis.Axle.Row1.SteeringAngle        |
| Vehicle.Chassis.Raindetection.Intensity        |
| Vehicle.CurrentLocation                        |
| Vehicle.CurrentLocation.Latitude               |
| Vehicle.CurrentLocation.Longitude              |
| Vehicle.Drivetrain                             |
| Vehicle.Drivetrain.Brakes.BrakePedalPressure   |
| Vehicle.Drivetrain.Engine.AtmosphericPressure  |
| Vehicle.Drivetrain.Engine.DriverDesiredTorque  |
| Vehicle.Drivetrain.Engine.EngineSpeed          |
| Vehicle.Drivetrain.Engine.EngineTemperature    |
| Vehicle.Drivetrain.Engine.FuelConsumption      |
| Vehicle.Drivetrain.Engine.Power                |
| Vehicle.Drivetrain.Engine.ThrottlePosition     |
| Vehicle.Drivetrain.Engine.Torque               |
| Vehicle.Drivetrain.Engine.PowerUnit1.Frequency |
| Vehicle.Drivetrain.Engine.PowerUnit1.Power     |
| Vehicle.Drivetrain.FuelSystem.FuelLevel        |
| Vehicle.Drivetrain.FuelSystem.Range            |
| Vehicle.Drivetrain.FuelSystem.Temperature      |
| Vehicle.Drivetrain.Transmission.Speed          |

Domain Taxonomy

Sources: https://covesa.global/vehicle-signal-specification/ https://github.com/COVESA/vehicle\_signal\_specification

## AWS IoT FleetWise and VSS

AWS IoT FleetWise is a software service by AWS, which allows a user to create the necessary definitions to upload data generated by vehicle targets  into the AWS cloud.  It does so in a tiered approach:

1.  The user creates a 'signal catalog', a collection of all possible signals, in any targeted vehicle types called 'vehicle models', organized in a VSS tree structure. This structure describes signals in their logical form, i.e., organized within components or locations in the vehicle types. There is only one signal catalog.
2. The user derives 'vehicle models', which are prototypes for actual vehicle targets. For this, the user selects all relevant signals for this vehicle model from the signal catalog. So far, this only explains the logical make-up in terms of signals for a vehicle target. It does not yet have any information on how the signal data is gathered and converted/normalized.
3. To obtain signal values, the vehicle model must be augmented with what is termed a 'decoder manifest'. The decoder manifest has the necessary information to obtain the raw signal data from any of the internal vehicle data networks and convert that data into a usable format - i.e., the CAN network, the CAN Message ID, where in the message the signal value is located, and which formulae to apply to the raw value. The user creates this decoder manifest by matching signals contained in the vehicle model with external conversion parameters, for example obtained from a CAN DBC file.
4.  At this point, the user creates actual vehicle instances in the AWS IoT FleetWise system and associates its vehicle model. For each vehicle instance, a vehicle ID is required. Since the communication to the actual vehicle target is encrypted, the user at this point also creates the necessary X.509 certificates associated with each vehicle instance. This - together with the target agent software - is installed inside the actual vehicle on a Service-oriented gateway like the NXP® GoldBox 3 Vehicle Networking Development Platform. At this point, the vehicle's service gateway can communicate with the FleetWise service cloud backend.
5.  The user can group a number of vehicle instances into a 'fleet' which allows that subset of vehicles to be operated as one entity.
6.  The last part needed to collect and send vehicle data from the vehicle to the cloud backend is determined by the 'Data Collection Scheme'. The user selects the signal data to collect, and the conditions under which these signals are to be collected - i.e., collect a set of data when the coolant temperature exceeds certain limits, etc.

This data collection scheme, when associated with a fleet, becomes a 'campaign'. This campaign must be approved, at which point the cloud backend sends the collection configuration - consisting of the decoder manifest and the data collection scheme(s)to the target vehicles in the fleet.

At this point, the service gateways of the fleet vehicles start to transmit data to the FleetWise cloud backend.

AWS provides a reference implementation for a FleetWise vehicle gateway target agent.  This implementation is fully functional and runs on the NXP GoldBox  3.  In addition, AWS uses the NXP GoldBox 3 system as the reference platform for their target agent.

The implementation of this target agent has the following characteristics:

-  The reference implementation is monolithic - which means that in order to add new features (such as adding a new driver for signal data), the entire software stack must be updated. This means that a customer is forced to update even the parts of the software he didn't have any intention of changing.
-  The reference implementation supports Linux systems based on AMD x86 64-bit and Arm® 64-bit. If the customer runs a different operating system (such as BlackBerry QNX), that customer will have to port or re-implement that target agent.
-  As it stands, the reference implementation supports CAN signals as signal input data. Although CAN is certainly still the largest data source in vehicles, other data sources, such as IP-based protocols, Bluetooth, USB and others are gaining momentum.
-  The design and user interface of the Data Collection Scheme is rigid. It allows two types of data collections:
- -A time-based collection that collects all signals for a certain period
- -A condition-based collection, which allows for simple conditions that determine when a set of signals is collected

The two types may cover a percentage of anticipated collection scenarios, but they remain limited for more complex scenarios.

aicas GmbH has developed a plug-and-play target agent for AWS IoT FleetWise - based on the

## System overview

The system that allows real-time vehicle data access and management can be seen in Figure 3 . It comprises four main parts:

NXP® GreenBox 3 Real-Time Development Platform (number 2 in figure), GoldBox 3 (3), Node-RED (1) and cloud dashboards (4).

The user can configure data selection flows related to vehicle dynamics, battery management and energy management within Node-RED (screen marked 1 in

JamaicaAMS platform. This target agent addresses the problems mentioned earlier and allows for much more flexible collection scenarios. The following pages detail the functionality of the demonstration system developed by NXP and aicas.

figure) and investigate the collected data on cloud dashboards (screen marked 4 in the figure). The low-code environment offered by Node-RED allows dynamic remote reconfiguration on-the-fly for easy prototyping. A real vehicle system is illustrated by the GreenBox 3 (CAN data source; number 2 in figure), and the GoldBox 3 (CAN receiver and data processor; number 3 in figure) combination from NXP, connected via a physical CAN bus.

Figure 3: The demonstration system with NXP hardware and aicas software showcasing VSS data management Source: NXP Semiconductors, 2024

<!-- image -->

## Signal walkthrough

Figure 4: Overview of the signal flow

<!-- image -->

Source: https://nodered.org/ and https://www.aicas.com/

## NXP GreenBox 3

For this demo example, the NXP GreenBox 3 acts as the data source of vehicle signals, such as position, speed, temperature of the battery pack and so on. For the full list of signals, please refer to the Appendix. The source of data is an F1 race car recording, that has been conditioned to include additional signals not available in the original dataset. The GreenBox 3 continuously provides these signals on the CAN bus in the form of 13 packets every 500 milliseconds.

The GreenBox 3 platform includes the NXP S32E288 Safe and Secure High-Performance Real-Time Processor (block diagram shown in Figure 5 ). The processor features 8 Arm® Cortex® R52 cores (with

S32E2 PROCESSOR BLOCK DIAGRAM

Figure 5: Block diagram of the NXP S32E2 real-time processor

<!-- image -->

flexible split-lock/lockstep options) with Neon™ SIMD engines, various volatile and non-volatile memory options; dedicated hardware elements for security, Ethernet acceleration and Automotive communication acceleration, such as CAN. A DSP/ML co-processor can aid high performance execution of time-critical motor control or Artificial Intelligence (AI) applications. For this demo, one core is used to periodically send the CAN frames. Customers can deploy other mixed-criticality workloads and applications in a well-isolated environment using the remaining cores to the needs.

## S32G3 GoldBox service-oriented gateway

The GoldBox 3 within this demo is responsible for receiving the CAN frames, interpreting them and carrying out data processing within the aicas EdgeSuite deployed on top of a standard Linux BSP from NXP. Once the data is processed in the userdefined Node-RED flow, it is then forwarded up to the AWS Cloud by an MQTT connector.

The NXP GoldBox 3 provides a reference design for the NXP S32G3 Vehicle Network Processor (see Figure 6 ) for secure in-vehicle connectivity, high-performance compute using multiple (up to 8 split-lock/lockstep) Arm A-class cores, real time embedded operation

S32G399A BLOCK DIAGRAM

Figure 6: Block diagram of the NXP S32G3 vehicle network processor

<!-- image -->

using Arm M-Class cores (up to 4 dual-core lockstep), and a wide array of vehicle connectivity (including multi Gbps hardware acceleration for Ethernet). Customers can deploy real-time operating systems, such as AUTOSAR, on the M-cores for safety critical execution, while Linux running on the application cores can provide an environment for flexible high-level processing.

AUTOSAR, on the M-cores for safety critical execution, while Linux running on the application cores can provide an environment for flexible high-level processing.

## Edge processing and signal selection

The software agent that is running on the NXP S32G3 vehicle gateway is implemented as a set of services running inside the JamaicaAMS application management runtime system.

JamaicaAMS is a framework for component-based applications. With JamaicaAMS, embedded systems can be easily and flexibly updated and reconfigured, remotely and at any time during runtime.

JamaicaAMS enables the management of modularized, service-oriented applications, as well as isolation, control, and updating of individual software components. The ability to reuse components on various supported systems provides full scalability for applications across fleets of vehicles. JamaicaAMS is part of the larger aicas EdgeSuite ( Figure 7 ). The aicas EdgeSuite of products connects edge devices to the cloud, providing developers and data analysts with full software management capabilities and access to data.

Figure 7: aicas EdgeSuite for edge device to cloud connectivity Source: aicas, 2024

<!-- image -->

Within the JamaicaAMS component system, the AWS FleetWise compatible data collection system is implemented as a set of individual and independent software modules which communicate asynchronously with each other via the JamaicaAMS internal message bus ( Figure 8 ).

The 3 major components of this demonstration are:

1.  Signal Conversion and Normalization, which picks up the raw CAN signal from the vehicles' CAN bus system, converts the CAN bitstream into discrete signal values and normalizes the signal data to a common VSS-based data structure
2. Signal Selection, which uses a visual flow-based editor to establish the logic which signals under what conditions are being collected
3. Signal Transfer, which encodes, batches, spools and transfers the collected data to the data center or cloud

Figure 8: The main components of the data processing framework: signal collection and normalization, signal selection, and signal transfer Source: aicas, 2024

<!-- image -->

## Signal conversion and normalization

Signals from the vehicle can arrive at the signal gateway as binary or ASCII-encoded data streams. In the case of this demonstration, we only use a raw CAN signal stream generated by the NXP GreenBox 3, which is typical for an automotive application. However, other signal types (such as Ethernet, USB, Bluetooth) could be processed in a similar fashion. The binary signal stream is picked up at the builtin CAN interface and relayed to the CAN decoder running inside the aicas data collection application.

The CAN decoder component is a driver-level component which parses the incoming CAN data for signals defined as part of the application configuration, based on what's termed the 'Decoder Manifest'. The decoder manifest provides the linkage between the raw, incoming CAN signals and the VSS signals defined for this vehicle - it maps the CAN message ID from the CAN signal to a signal defined in the VSS catalog ( Figure 9 ). In addition, it contains the knowledge for each VSS signal which part (position and length) of the individual binary stream is to be used, and how that part is to be converted into an actual, human-usable signal value.

The resulting data structure is normalized to a namevalue map of maps posted to the aicas J-AMS internal message bus, from which any interested other component can subscribe to for signal updates (see next section).

In addition to the signal data normalization, the CAN decoder component also allows for configuration of rolling-average (boxcar) filtering to avoid large amounts of noise-induced signal updates, and the request-based generation and sampling of OBDII signal values 1 .

Figure 9: Decoder Manifest: creates mapping between the raw CAN signals and their VSS counterpart Source: Amazon Web Services, Inc.

<!-- image -->

1. We will note that the CAN decoder component is only one option for collecting and normalizing hardware signals. Other options available include signal collection from Ethernet, Bluetooth, or other interfaces - all of which normalize the incoming data streams to the same VSS-style format.

## Signal selection via Data Collection Scheme (DCS)

The CAN decoder component detailed in the last section decodes and normalizes all VSS signals available in the vehicle. It may not make sense to transmit all those data values at all times, based on internal conditions in the vehicle, or external operational needs. The next component in the data transmission chain selects the data based on those criteria for transmission to the cloud-based backend.

For this to be effective, it has to be robust, flexible and yet still easy to use for data engineers. The aicas system uses a flow-based 'Data Collection Scheme' with a Node-RED Editor, adapted to aicas' specific needs. Via the editor, the user defines which data points to collect and under which circumstances. The graphical editor makes it easy to create the required logic based on 'flow nodes' symbolizing signal inputs, conditions, transformations, filters, synthetizations, and output collector nodes, which are logically connected ('wired') to represent the signal data flow ( Figure 10 ).

This typically starts on the 'left' side via an 'input node', which selects one of the signals defined in the vehicle's VSS scheme.

Next the operator adds data transformations, such as adding a Unit of Measurement, or a condition, to

Figure 10: Node-RED is a low-code framework that is used to create data streams and collection schemes Source: https://nodered.org/

<!-- image -->

the signal path. In the case of a condition node, all signals that feed into the condition are passed if the condition is valid or blocked if the condition is not made.

If a signal is not present as an input node signal, but it can be mathematically derived from existing inputs, the user can synthesize a fully valid VSS signal.

The signal path terminates at a node that represents the campaign the signal should be collected for. From there the data is forwarded to the next component in the chain (see next section).

Once the desired DCS flow is established, it can be exported into aicas EDP (or any other CI/CD pipeline) for test and delivery to a vehicle fleet. The exported artifact is a simple JSON text file and does not require any additional alteration or compilation - it will run on the vehicle target exactly the same as on the system where it was developed.

It should be mentioned that the flow execution does not require any interpretation on the target side - the flow works simply by connecting the message data flow between pre-compiled, native functions.

## Signal transfer

The last component in the signal flow transmits the collected data to the cloud backend. When started, it establishes a secure TLS connection with the cloud backend. The configuration for this authentication can be changed or revoked from the control interface.

In the default AWS IoT FleetWise mode, signals are batched, encoded via a custom AWS FleetWise Protobuf scheme and sent via an MQTT channel to the cloud (AWS IoT Core). If the connection is not available, the component spools the data packets and later splices the spooled data into the upload stream once the connection is re-established. The demo supports this transportation mode.

As an alternative, the signal data can be encoded and sent via Sparkplug B. Sparkplug B is an industrial protocol that rides on top of MQTT, and which provides end-to-end life cycle management for the transport, meta-information defining the connecting client and fail-over in case of connection or broker problems. The Sparkplug B protocol defines the topic namespace within MQTT and the encoding scheme for signal data.

The Sparkplug B protocol works very well with the VSS definition, and in our demonstration, we use the VSS signal description directly as the meta-data for Sparkplug B metrics. This enables the cloud side when a new vehicle connects - based on the metainformation about vehicle type, fleet, campaign or other characteristics, to identify the vehicle and to route its signal data to the correct place.

## Simulated vehicle fleet

In addition to the demonstration system on the stand, there are more vehicles shown on the dashboard. Those vehicles are simulated in the cloud, using the AWS EC2 servers. In these simulations, the aicas JamaicaAMS target system is running inside Docker containers. The vehicle data is generated via NodeRED simulation running on the same systems.

## Real-time data dashboards in aicas EDG

The data transmitted by the vehicle fleet is consumed on the cloud side into aicas Edge Data Gateway (EDG). This system provides scalable backend data management with a simple to use interface. The ingested data is handled via a rule chain which allows for flexible filtering and disposition into databases, cloud backends, file systems or direct display on dashboards.

In this case, a layered dashboard is used, which at its landing page displays the entire vehicle fleet on a map with select data points and allows for drilling down into each vehicle's detailed dashboard and historical data diagrams.

## Product list

## aicas contributions

-  aicas JamaicaAMS

The aicas JamaicaAMS application management system is a framework for component-based applications built on aicas' proven JamaicaVM. JamaicaAMS enables the management of modularized, service-oriented applications, as well as control and updating of individual software components.

-  aicas Edge Data Gateway (EDG)

The aicas Edge Data Gateway (EDG) provides direct, unified, and cross-application access to data from edge systems. Supporting many different communication protocols, it is scalable across heterogeneous fleets of devices and target systems. Custom dashboards can be configured for data visualization and live data monitoring. Its flow editor allows to filter, aggregate, and route data to third-party applications.

Figure 11: Example cloud dashboards for visualizing collected fleet and vehicle data

<!-- image -->

Source: aicas.com

## NXP contributions

## •  GoldBox 3

The NXP GoldBox 3 is a compact, highly optimized and integrated board engineered for vehicle service-oriented gateway (SoG), domain control applications, high-performance processing, safety and security applications.

## •  GreenBox 3

The NXP GreenBox 3 is a development platform providing advanced performance, peripherals, and multi-core Arm ecosystem for engineers to begin development on NXP's next generation of electric vehicle (xEV) and internal combustion engine microcontrollers.

## AWS contributions

-  AWS IoT FleetWise

The demo application relies in part on AWS IoT FleetWise. AWS IoT FleetWise makes it easier for you to efficiently collect vehicle data and organize it in the cloud so you can use the data to improve vehicle quality, performance, and autonomy. AWS IoT FleetWise integrates with the following AWS services:

- -Amazon Timestream - time series database to store and analyze vehicle data
- -AWS IoT Core - register and control AWS IoT devices
- -Amazon S3 - Simple Storage Service to store and manage vehicle data

## Conclusion

The VSS solution provided by NXP and aicas showcases standardized signal representation. Thanks to the integration of VSS, the solution provides these key values:

- (1) Reduction in vehicle data fragmentation
- (2) Easier integration of Tier-1 software and ECUs
- (3)   Collaboration with off-vehicle actors (e.g. charging stations)

The aicas EdgeSuite products allow customers to get started quickly with data collection and management solutions without having to create systems from scratch. Their embedded and cloud dashboards provide sophisticated data management for fleet operators.

The solution utilizes two of NXP's automotive processors.  First, the NXP S32G3 Vehicle Network Processor provides high-speed vehicle networking, POSIX compute with Arm Cortex-A53 cores and ASIL D capable compute using Arm Cortex-M7 cores in lockstep. Second, the solution includes the NXP S32E2 real-time processor, which is ideal for safety processing, domain control, electric vehicle (xEV) control and smart actuation.

The aicas and NXP partnership enables powerful implementation of VSS through aicas EdgeSuite, powerful vehicle and fleet data management, and advanced compute using NXP's automotive processors.

## Appendix

## Signal List

| CAN ID decimal (hex)   | Data contained                    | Notes                                                       |
|------------------------|-----------------------------------|-------------------------------------------------------------|
| 1557 (0x615)           | • External temperature • Humidity |                                                             |
| 1556 (0x614)           | • Odometer                        |                                                             |
| 921 (0x399)            | • Frequency • Power               | Frequency: how frequently data is being updated             |
| 911 (0x38F)            | • Rain intensity                  |                                                             |
| 901 (0x385)            | • Fuel system range • Temperature |                                                             |
| 824 (0x338)            | • Throttle position               |                                                             |
| 809 (0x329)            | • Engine temp                     |                                                             |
| 791 (0x317)            | • Engine power                    |                                                             |
| 790 (0x316)            | • Engine torque • RPM             |                                                             |
| 532 (0x214)            | • Brake pressure • Position       | Position: relative position to some other position on track |
| 501 (0x1F5)            | • Steering angle                  |                                                             |
| 340 (0x154)            | • Latitude/longitude              |                                                             |
| 339 (0x153)            | • Transmission speed              |                                                             |

<!-- image -->

Gergely Simon Principal Engineer, Automotive System Engineering and Marketing NXP Semiconductors Glasgow, Scotland

Gergely has been with NXP for almost three years. Over this period, he specialized in artificial intelligence, machine learning, and data management solutions. With a background originally in application engineering, he had supported S32G and related products including the eIQ Auto AI/ML Software Development Environment, built demonstrations for tradeshows and exhibitions. Recently his focus has been on edge AI applications and deployment of AI/ML models to various NXP devices. Prior to NXP he had worked in cloud-native finite element modeling for delivering efficient distributed compute solutions for mobile filter simulations.

Thomas Hentschel Solutions Architect aicas GmbH San Francisco Bay Area, U.S.A.

<!-- image -->

30-year veteran in semiconductor processing, and embedded systems for automotive. Spearheaded control system development at Novellus Systems/ Lam Research for the VECTOR PECVD systems. Holds multiple patents related to semiconductor processing and equipment. Now leading efforts at aicas in software standardization/optimization for the automotive industry.

## nxp.com

NXP and the NXP logo are trademarks of NXP B.V. Arm, Neon, and Cortex are trademarks and/or registered trademarks of Arm Limited (or its subsidiaries or affiliates) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved. Amazon Web Services, AWS IoT FleetWise, Amazon Timestream, Amazon S3 and all related marks are trademarks of Amazon.com, Inc. or its affiliates. Oracle and Java are registered trademarks of Oracle and/or its affiliates. © 2025 NXP B.V.

Curt Hillier Austin, Texas U.S.A.

<!-- image -->

Fellow, Automotive System Engineering and Marketing NXP Semiconductors

Curt has been at NXP for more than 13 years. In this time span, Curt's area of responsibility has included radar, hybrid and electric vehicle propulsion, battery management and vehicle connectivity domains. He has a background in applications engineering which covers customer support and delivering advanced solutions and demonstrations for tradeshows, conferences and customer workshops. Recently, his focus has been on the connected and electrified vehicle. In this domain, NXP and our partners are developing solutions for real-time propulsion (such as energy management systems, electric motor control and battery cell state estimation) and non-real-time vehicle health applications. He is also leading teams to pioneer new cloud-based solutions for automotive software development and validation.

Tristan McDaniel Automotive Applications and

<!-- image -->

Systems Engineer NXP Semiconductors Austin, Texas U.S.A.

Tristan McDaniel is a Systems and Applications Engineer with NXP Semiconductors (4 years) focusing-on advanced automotive central compute and gateway processors. Expertise includes integrating embedded systems with cloud compute and supporting the deployment of powertrain and edge processing applications in the vehicle. Tristan holds a B.S. in Electrical Engineering from the University of Texas at Austin.