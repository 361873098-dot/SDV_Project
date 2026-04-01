## ACCELERATING THE AUTOMOTIVE SHIFT TO ZONAL ARCHITECTURES

NXP Semiconductors and Sonatus

F E B R U A R Y   1 6 ,   2 0 2 3

<!-- image -->

NXP

<!-- image -->

SONATUS

<!-- image -->

## INTRODUCTION

## VEHICLES ARE EVOLVING RAPIDLY

New zonal vehicle E/E architectures, automotive semiconductors and software

## NXP SOLUTIONS

S32 Automotive Platform for vehicle-wide processing Advanced analog support for power and networking Hardware, software and ecosystem enablement

## SONATUS SOFTWARE SOLUTION

Zonal Network Solution for full zonal architecture activation with observability and dynamic configurability

## SOFTWARE-DEFINED

HW ECUs → SW virtual ECUs New features through software Continual vehicle improvements

## VEHICLE DATA-DRIVEN

New capabilities/improvements Digital twins and machine learning Predictive maintenance

## CLOUD-CONNECTED

Development/test/production support Over-the-Air (OTA) services Vehicle edge and cloud collaboration

## SERVICE-ORIENTED

Decoupled hardware and software Dynamic configuration / data usage Accelerated vehicle innovations

<!-- image -->

PUBLIC

1

## ZONAL ARCHITECTURE TRENDS AND SOLUTIONS

F E B R U A R Y   2 0 2 3 Thomas Brown Automotive Processing Solutions

<!-- image -->

STRICTLY CONFIDENTIAL

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## VEHICLE ARCHITECTURE TRENDS

ZONAL CONTROLLER SOLUTIONS

NXP ZONAL PLATFORM &amp; POC

<!-- image -->

## AUTOMOTIVE MEGATRENDS

CLOUD

<!-- image -->

Over-the-Air (OTA) Services

<!-- image -->

<!-- image -->

Vehicle Data / Model

Autonomous

<!-- image -->

New sensing, thinking

Centralized Processing

Software-Defined Connected from cloud to edge

E/E transformation needed

Networking Technologies

Service Orientation

Electric New energy management

<!-- image -->

Zones and I/O Aggregation

<!-- image -->

## OEMS ARE CHANGING THEIR STRATEGIES

<!-- image -->

OPTIMIZE COSTS IN INEFFICIENT AREAS, RELEASING VALUE

## Optimize costs

Reduce SW/HW diversity, decrease number of modules

Simplify and lighten wiring harness

Lighten, speed up innovation cycle for new features

<!-- image -->

## RE-INVEST IN ELECTRICAL/ELECTRONIC ARCHITECTURES FITTING NEW MISSIONS

## Fit E/E architectures to new missions

EV → re-think power and torque distribution

AD → enable fully redundant and secured car systems

SO → provide car functions as shared services

<!-- image -->

ALL THAT, DEALING WITH REALWORLD CONSTRAINTS

## Manage real-world constraints

Cost, risk and expertise to migrate legacy systems

Scalability required to address fleet of vehicles

Organizational boundaries

<!-- image -->

<!-- image -->

## DOMAIN

Creates logical separation to isolate processing of domain functions with static network policies

## NEW E/E ARCHITECTURES ARE EMERGING TO MANAGE I NCREASING HARDWARE AND SOFTWARE COMPLEXITY

<!-- image -->

## BODY-ZONAL

Creates physical separation for body domain functions enabling smart data and power distribution and reducing wiring/weight/complexity

<!-- image -->

## X-DOMAIN ZONAL

Creates physical separation for crossdomain functions in zones for further wiring/weight/complexity reduction using distributed compute architecture

<!-- image -->

## SDV-OPTIMIZED

6 PUBLIC Centralized, service-oriented compute architecture with zones supporting SDV SW deployment and further wiring optimization

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## VEHICLE ARCHITECTURE TRENDS

## ZONE CONTROLLER SOLUTIONS

NXP ZONAL PLATFORM &amp; POC

<!-- image -->

## CHOICE OF ZONAL MODULES: THEORY VS. REALITY

<!-- image -->

<!-- image -->

## NXP SOLUTIONS ADDRESS ZONAL REQUIREMENTS

<!-- image -->

<!-- image -->

Advanced Low Power Modes &amp; Fast Wake-up

Direct I/O Control (e.g. Body, Motors)

Communications Acceleration (Gateway Offload)

Multi-ECU Isolation/Virtualization

<!-- image -->

<!-- image -->

## NXP AUTOMOTIVE MCU/MPU PORTFOLIO

## Low-Power MCU Family

<!-- image -->

## Performance MCU Family

<!-- image -->

## Integrated MCU+MPU Family

<!-- image -->

## Addressing low-power, zone and edge applications with scalable performance

- Advanced low-power modes, fast boot/wake up and high I/O feature set
- Arm ® Cortex ® -M4 and Cortex-M7 platform base, with embedded NVM

## Optimized for multi-application zones and future zone expansion

- Multi-application zones: MCU isolation, mixed criticalities, real-time virtualization
- Future growth OTA: Performance headroom (Arm Cortex-R52 &amp; DSP/ML coprocessor) with high-performance memory expansion (LPDDR Flash)

## MPU for Central Vehicle Computer

- -MCU functionality for low power &amp; functional safety
- -MPU functionality for FOTA server &amp; vehicle network firewalling
- -Advanced networking capabilities for vehicle network firewall

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## VEHICLE TRANSFORMATION

ZONE CONTROLLER SOLUTIONS

NXP ZONAL PLATFORM &amp; POC

<!-- image -->

## ETHERNET MOTOR CONTROL DEMO WITH TSN

<!-- image -->

<!-- image -->

## NETWORK OVERVIEW -I EEE 802.1AS (gPTP), IEEE 802.1CB

<!-- image -->

Redundant control data paths enabled between central compute platform and zonal controllers ( IEEE 802.1CB ) -allowing failure of single link between central compute platform and both zonal controllers without loosing speed loop integrity

## Multi-domain gPTP ( IEEE 802.1AS )

configuration for maintaining the local clock synchronization in case of a single link failure between central compute platform and one of the zonal controllers

<!-- image -->

## NETWORK OVERVIEW -I EEE 802.1Qbv

<!-- image -->

Time-aware shaper (TAS) scheduler configured with cycle time of 500 µs split evenly into time intervals:

- -Time interval 1: 250 µs, VLAN priority 7 (speed control)
- -Time interval 2: 250 µs, VLAN priorities 0..6 (other traffic)

Speed loop request timing is asynchronous to the gPTP counter and thus the TAS scheduler → speed loop latency kept in range of approx. 70-320 µs:

- -70 µs (best case): Both the request (actual speed from smart actuator) and response (required current from the central compute platform) frames are transmitted within the same schedule cycle / time interval
- -320 µs (worst case): Request and response transmitted in different schedule cycles (request delayed by TAS scheduler)

Making the speed loop request synchronous to the TAS scheduler would allow increase of cycle time to 1 ms with possible reduction of time interval 1 duration (with respect to amount of priority 7 traffic)

<!-- image -->

## 3-PHASE SYNCHRONOUS MOTOR: FIELD-ORIENTED CONTROL SOFTWARE STRUCTURE

<!-- image -->

<!-- image -->

## FIELD-ORIENTED CONTROL VS. APPLICATION LATENCY

<!-- image -->

FOC -field-oriented control is based on the cascade control structure, consisting of several control loops:

- Current loop -most inner loop, fastest loop (10 -50 kHz)
- Speed loop -outer loop, slow loop (usually 1-20x slower than speed loop, typically 10x)

<!-- image -->

## ETHERNET INTERCONNECT LATENCIES

| Interconnect   |                    | Packet Transmission Time [µs]   | Roundtrip Communication Latency [µs] for direct link without intermediate switch   | Total Application Latency [µs] incl. SW overhead   |
|----------------|--------------------|---------------------------------|------------------------------------------------------------------------------------|----------------------------------------------------|
| 100 Mbit/s     | min. Frame Size    | 6.72                            | 15                                                                                 | 70 - 300                                           |
| 100 Mbit/s     | max. Frame Size    | 123.68                          | 250                                                                                | 70 - 300                                           |
| 1 Gbit/s       | min. Frame Size    | 0.672                           | 1.5                                                                                | 50 - 125                                           |
| 1 Gbit/s       | max. Frame Size    | 12.368                          | 25                                                                                 | 50 - 125                                           |
| 10 Gbit/s      | min. Frame Size    | 0.0672                          | < 1                                                                                | 5 - 50                                             |
| 10 Gbit/s      | max. Frame Size    | 1.2368                          | 2.5                                                                                | 5 - 50                                             |
| PCIe           | (256 Bytes - 4 KB) |                                 | < 2                                                                                | < 10                                               |

Total application latency may vary with Ethernet frame size, the MCU performance, and different implementation of protocol stacks

<!-- image -->

## ANALYSIS OF CLOSED LOOP SYSTEMS

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

|                                             |               | Engine        | Fuel / oil    | Fuel pump -fast     |                      |                               |
|---------------------------------------------|---------------|---------------|---------------|---------------------|----------------------|-------------------------------|
| Application                                 | HVAC Blower   | cooling fans  | pump          | start-up            | EPS                  | eTurbo                        |
| ASIL-x                                      | QMto ASIL-B   | QMto ASIL-B   | QMto ASIL-B   | QMto ASIL-B         | ASIL-D               | QMto ASIL-B                   |
| Motor                                       | PMSM (FOC)    | BLDC (6-step) | PMSM (FOC)    | BLDC (6-step)       | PMSM (FOC)           | PMSM (FOC)                    |
| Sensor Type                                 | Sensorless    | Sensorless    | Sensorless    | Sensorless          | Resolver             | Sensorless/HALL               |
| Current Loop frequency / Commutation period | 10 kHz 100 µs | 20 kHz 50 µs  | 10 kHz 100 µs | 40 kHz 25 µs        | 20 kHz 50 µs         | > 30 kHz ≥ 33.3 µs            |
| Speed Loop period                           | 1000 µs       | 500 µs        | ~1000 µs      | ~125-250 µs         | ~500 µs              | ~250-330 µs                   |
| 100 Mbit/s Ethernet System Latency          | 70-300 µs     | 70-300 µs     | 70-300 µs     | 70-300 µs           | 70-300 µs            | 70-300 µs                     |
| 1Gb/s Ethernet System Latency               | 50-125 µs     | 50-125 µs     | 50-125 µs     | 50-125 µs           | 50-125 µs            | 50-125 µs                     |
| Remote Control                              | Can fit       | Can fit       | Can fit       | Limited performance | No fit due to ASIL-D | No fit due to fast speed loop |

<!-- image -->

<!-- image -->

## PUTTING NXP SOLUTIONS TO WORK: ZONAL ARCHITECTURE PROJECT

<!-- image -->

<!-- image -->

Physical Test Bed

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## Sonatus Zonal Network Solutions

## James Murphy, Sonatus

February 16, 2023

## Agenda

## Zonal Architecture Introduction

- Zonal Topologies

## Sonatus Solutions to Enable Zonal Architecture

- Zonal Architecture Software Overview
- Networking Challenges in the Zonal Architecture
- Zonal Data Plane (Traffic Protocols)
- Zonal Control Plane
- Time Synchronization (802.1AS)
- Mixed Criticality Support - Classification and Scheduling (QoS &amp; Performance)
- Mixed Criticality Support - Frame Replication and Elimination for Reliability (802.1CB)

<!-- image -->

## Speaker Background

James Murphy james.murphy@sonatus.com

35-year career in networking and software engineering starting with AT&amp;T Bell Labs and continuing with Cisco, Juniper, Arista, SpaceX as well as several startups.

Experience across a vast array of networking technologies including VoIP, QoS, core routing, Wi-Fi, Licensed Spectrum Wireless, SDN, Cloud/Virtual Routing, Satellite Networks and Automotive.

<!-- image -->

## Sonatus: Silicon Valley-Based Automotive SW Leader

<!-- image -->

<!-- image -->

Networking, Storage and Compute Systems

<!-- image -->

SONATUS

<!-- image -->

Communications

<!-- image -->

Proven solutions in production today with Hyundai, Kia, and Genesis ramping across their product line

A Successful Track Record in Production

Building on proven data center expertise

<!-- image -->

Security: Authentication, Encryption, VPN, FW

<!-- image -->

Cloud/Data Management

<!-- image -->

* Coming in 2023

Global Presence

<!-- image -->

Mobile and Cloud based Applications &amp; Services

<!-- image -->

Virtualization, Orchestration, SaaS, Managed Services

## Zonal Architecture Topologies

<!-- image -->

## Topology Options Overview

<!-- image -->

<!-- image -->

SONATUS

## Example of Typical Topology

<!-- image -->

<!-- image -->

SONATUS

## Sonatus Solutions To Enable Zonal Architecture

<!-- image -->

## Sonatus Solutions to Enable Zonal Architecture

Observability

Congestion

<!-- image -->

<!-- image -->

Link Faults

Application Behavior

<!-- image -->

SONATUS

Fault Detection Performance

Application Monitoring

Data Collection

<!-- image -->

Video Stream

Dynamic Configuration

New Security Threats New Applications

<!-- image -->

Full range of zonal architecture activation provided by Sonatus

Containerized Workloads

<!-- image -->

Traffic Engineering

## Networking Challenges in the Zonal Architecture

<!-- image -->

Domain-Based Architecture

- Mixed Criticality
- Classification, Policing, Scheduling
- Multiple Ethernet Switches
- Network Time Synchronization
- Link-level redundancy

<!-- image -->

Zonal Architecture

<!-- image -->

SONATUS

## The Network Data Plane in Zonal

The Zonal Architecture needs to be able to handle multiple types of traffic…

<!-- image -->

<!-- image -->

## Sonatus Network Control Plane to Manage Zonal

<!-- image -->

<!-- image -->

- Centralized Network Controller (SDN)
- Service Aware
- 802.1DG TSN Profile for Automotive
- Failure Recovery
- Dynamic Configuration for the SDV

## Time Synchronization (802.1AS)

<!-- image -->

<!-- image -->

SONATUS

## Key Attributes

- Network Based Time Synchronization
- Real-time control, media processing and data analysis require time sync
- Grand Master
- Relay
- End Instance

## Mixed Criticality Support - Classification and Scheduling

<!-- image -->

<!-- image -->

SONATUS

- 802.1Q Per-Stream Filtering and Policing(PSFP)
- 802.1Q Forwarding and Queuing for TSS (FQTSS)
- ●
- Example Traffic Streams ○ CAN3 - Critical Traffic to ECU1 ○ ECU3 - Low priority traffic to ECU1
- Network Control Plane Functions
- Observability

## Mixed Criticality Support

Frame Replication and Elimination for Reliability (FRER)

Ingress Stream Classification for Duplication &amp; R-TAG insertion (seqno)

FRER Stream Classification for Deduplication,  R-TAG elimination, forwarding to ECU 1 Egress Port

<!-- image -->

Credit-based scheduling with high priority for critical traffic on redundant paths

<!-- image -->

SONATUS

- 802.1CB Operation
- Link Failure Handling - Non- Conventional
- Example Traffic Streams
- CAN3 - Critical Traffic to ECU1 subjected to FRER
- ECU3 - Low priority traffic to ECU1
- Network Control Plane Functions
- Observability Attributes

Provision FRER stream transit forwarding

## Demo Video

<!-- image -->

Canvas5Trial

TENCY(useC)

50

25

Time

CAN msg latency within Zonal (excludes CAN-bus transmit-time)

ZoneFR

ZoneFL

CanvasJS.com

CanvasJSBi

100.5

GAP(msec)

100

99.5

ZoneRr

Time

CAN inter-message GAP (excludes jitter from the source)

© 2023 Sonatus Inc.

37

## Sonatus Zonal Network Solution enables dynamic SDV architectures

SDVs must support new applications with diverse profiles of criticality and safety requirements throughout the life of the vehicle

Zonal Architectures are a key ingredient to make that happen, but the network must be suitably flexible and configurable

The Zonal Network Solution allows SDV zonal networks to be dynamically configurable from the cloud at any time, including post-production

<!-- image -->

<!-- image -->

<!-- image -->

Accelerating Vehicle Software Innovation

## Thank You

www.sonatus.com contact@sonatus.com