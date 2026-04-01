## S32 Design Studio Tools for S32 Platform

## Mike Doidge

Software Development Tools Engineering

NXP Automotive Microcontroller &amp; Processors

June 2019  |  Session #AMF-AUT-T3654

<!-- image -->

<!-- image -->

<!-- image -->

## Agenda

- Overview of S32 Design Studio for Next Generation Products
- -Modular Tooling
- -Base S32 Support Tools
- -Application S32 Specific Tools
- -New 'Getting Started' Page
- S32 Debugger + S32 Debug Probe
- -S32 Configuration Tool
- Pins, Clock, Peripheral, DCD, and IVT Tools
- FreeMASTER Lite
- Virtual Development Environment : VDK
- New S32 Design Studio Vision Tools vs S32 Design Studio for Vision Tool - What is the Difference?
- Conclusion

<!-- image -->

<!-- image -->

<!-- image -->

## What is S32 Design Studio?

- Integrated Development Environment for NXP Automotive and Ultra-Reliable ARM® based microcontrollers
- Component-based architecture
- Build Integration for various toolchains (Managed Make Facility, error parser)
- Resource Management (projects system, folders, and files)
- Code Editor (syntax coloring, code-completion, source navigation, refactoring)
- Debugging (breakpoints, disassembler, memory monitor, register view, variables)
- Based on Eclipse software framework
- Free, open-source IDE platform
- C/C++ Development Tools (CDT) plug-in
- Extensible plug-in system
- Allow customization for user-specific needs
- Supports plugins from partners
- Community collaborative effort

<!-- image -->

<!-- image -->

<!-- image -->

## S32 Design Studio Features

## Integrate additional features

- NXP GNU toolchain for bare-metal and Linux ARM targets
- NXP toolchains for accelerators (APEX, ISP, PAX, SPT, LAX)
- GNU GDB Debugger with Python support
- Multicore debugging, Semihosting support
- S32 Debug Probe support provided with S32 Debugger and S32 Trace
- Support for Lauterbach and P&amp;E debuggers
- Support for Simulators (VDK, VLAB)
- S32DS Extensions and Updates tool
- Visual graph tools to support accelerators program development
- S32 Configuration Tool framework
- Integrated NXP Software (S32 SDKs, Math and Motor Control Libraries)
- SDK Manager
- S32 Flash Tool
- RTOS aware debug support (FreeRTOS, MQX)
- Peripherals Register View
- DDR configuration and validation tools
- Collateral page providing convenient access to product manuals, tool guides, how-to videos and application notes
- Supported 64 bit host operating systems: Windows 7/8/10, Ubuntu 16.04, Debian 8, CentOS 7

<!-- image -->

<!-- image -->

## S32 Design Studio V3.x Modular Design

## New Component-based Architecture for more Flexible Product Support and Enablement

- Platform package (Base Tools)
- -Basic IDE, Modular Installer, Documentation, Integration mechanisms
- Tools package
- -Compilers, Debuggers, MSYS2, S32 Configuration tools
- Development package
- -NPI specific support: NPW, S32 Configuration tools, SDK, Libraries
- Extension package
- -Accelerator Compiler, Debugger, Graph Tool, SDK

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## S32 Design Studio Base Tools

## · S32 Design Studio Base Download

- -GCC 6.3.x Compilers for all ARM Cores
- -S32 Debugger and S32 Debug Probe
- -S32 Configuration Tool
- -S32 Flash Tool
- -Software Library Manager
- -New Project Wizard
- -"Getting Started" - Collateral Access Page

<!-- image -->

## S32DS Extensions and Updates

## Special tool to install, update and install packages

- Communicates with the product's website
- Access to new products and features
- Reduce DS download size
- Display actual information about packages
- Pop-up notification about updates
- User can download the latest product updates manually

<!-- image -->

<!-- image -->

## Radar Extension Packages for S32R: SPT, DSP, LAX

## · Radar Extension Package

- LAX Compiler
- SPT assembler
- Radar SDK integration
- Wizard to create project with SPT/LAX
- Examples with SPT using RSDK
- Software manifests for RSDK
- Simulation on Synopsys VDK
- SPT Explorer
- S32 Debugger support for accelerators

## · DSP Add-On Package

- -Xtensa Software Developer's Toolkit
- -IDE integration for Xtensa build tools
- -Wizard to create project with DSP
- ISS debugging via standard GBD interface

<!-- image -->

<!-- image -->

## Vision Extension Packages for S32V: APEX, ISP/PAX

## · S32V support

- -NXP APU Compiler
- -ISP assembler
- -Vision SDK integration
- -Wizard to create project with APEX/ISP
- -Examples with APEX and ISP using VSDK
- -Software manifests for VSDK
- -Graph tools to support APEX/ISP program development
- -S32 Debugger support for accelerators
- -APEX and ISP GDB clients

## · S32V support

- -PAX assembler and IDE integration
- -VSKY SDK EAR 0.4.9 integration
- -Wizard to create project with PAX
- -Graph tools to support PAX program development

<!-- image -->

<!-- image -->

## Tool and SW Download

- Different Elements of the end Environment
- Base NPI Support
- App NPI Support
- SW Base Support
- SW App Support
- Tool and SW Bug fixes
- Tools Team does Tool Package
- SW Team Does SW Packages

<!-- image -->

<!-- image -->

## S32 Design Studio - New 'Getting Started' Page

Created for Users to Have Easy Access to Collateral

<!-- image -->

<!-- image -->

## S32 Debugger: S32 Debug Probe

- USB and Ethernet connections
- Supports Remote access to target system, allowing to interactive debug with target system over the network
- Mid-range ~ $500 (Includes 10 pin and 20 pin JTAG probe tips)
- 400 MHz, 16MB DDR
- Debug features
- -Read Write access to registers and memory
- -Automatic core recognition
- -Scripting and logging
- -GDB, command line
- -Asymmetric multicore debug with cross trigger support
- Start/Stop cores simultaneously or individually
- Step through 1 core while others are running or stopped
- BP on 1 core stops execution on all cores
- BP on core A with conditions on core B
- -Semi-hosting support for single and multicore devices
- -Flash programming (through JTAG)
- -Target Reset Supported
- -Debug through Reset and Low Power
- -Hot connect
- -Secure debug authentication
- -Debug and Trace support for accelerators
- APEX-D, LAX, PAX, SPT

<!-- image -->

<!-- image -->

## S32 Debugger

- New NXP Debugger for AMP Common Chassis Devices
- S32 Debugger is an S32 Design Studio component
- Standard GNU Debug Views
- Breakpoints
- Expressions
- Memory
- Disassembly
- -Multi-Core Support
- -Attach scenario
- -Accelerator Core Support
- Source Code Debug
- -Specialized Register View
- -General Core Register Views
- -Trace Configuration
- -Trace Visualization Support
- Flash Programmer

<!-- image -->

<!-- image -->

## S32 Debugger: Trace/Profiling Features Support

## Trace Viewer

<!-- image -->

## Code Coverage Viewer

## Hierarchical Profiler Viewer

<!-- image -->

## Call Tree Viewer

<!-- image -->

<!-- image -->

## Timeline Viewer

<!-- image -->

<!-- image -->

## SDK Management

- Mechanism to inject SDK dependencies to project
- Toolchain build options
- Libraries
- Includes
- Source files
- Linker file
- Startup files
- External SDKs support
- User can create Custom SDK
- SDK descriptors
- XML file to describe SDK dependencies
- Hierarchical structure: SDKs can be combined in one module
- Easy can be used by SDK teams to provide dependencies for DS
- New Project Wizard Integration
- Build options are taken from XML descriptors, no 'hardcode' in Wizard's template

<!-- image -->

<!-- image -->

## S32 Configuration Tools

## Pins Tool

<!-- image -->

## Clocks Tool

<!-- image -->

## IVT Tool

<!-- image -->

## Peripherals Tool

<!-- image -->

<!-- image -->

## S32 Configuration Tool: Pins Tool

## Caption showing Pins Tool for S32S2xx - BGA501 package

<!-- image -->

## Quick configuration of pins from:

1. Peripherals View
2. Pins View
3. Package View
4. Resource View
- Setting allowed properties for each pin (5)
- Validation of pins selection (5)
- Support &amp; help for managing conflicts (5)
- Registers modified information (6)
- Configuration C - Code Generation (7)
- Multiple Configuration Support (8)
- Wizard for quick configuration
- Power Groups Highlight

<!-- image -->

<!-- image -->

## S32 Configuration Tool: Graphical Clock Tool

## Caption Showing Clock Tool for S32S2xx

<!-- image -->

- Quick configuration of clock from:
- Clock Diagram View (1)
- Clock Summary Table
- Sources (2)
- Outputs (3)
- Setting values for clock tree elements
- PLLs
- DFS
- Dividers
- Selectors
- Validation of selected choices (7)
- Support &amp; help for managing conflicts (4)
- Registers modified information (5)
- Configuration C - Code Generation (6)
- Multiple Configurations Support (8)
- Various power modes for example

<!-- image -->

## S32 Configuration Tools: Peripheral Tool

<!-- image -->

- Quick configuration of IP with code generation on top of AMP SDK
1. Select the peripherals to configure
2. Apply desired setup
3. Generate Configuration C - Code
4. Validation of Selected Choices
- Multiple Configurations Support
- Supports Configuration of SDK
- Device Drivers and RTOS

Note: No Common Chassis SDK in 2018

<!-- image -->

## S32 Configuration Tools - Device Configuration Data (DCD) Tool

<!-- image -->

- DCD Tool used mainly to define SoC IP configurations prior to HSE Firmware boot-up or Application Boot Code execution.
- DCD Tool Supports following commands:
- -1.WRITE - writes a memory area
- -3.CHECK - checks a memory area
- -2.NOP - introduces a wait
- DCD Tool generates a binary (5) which incorporates all the settings done.
- Main scenario flow:
- -Import an existing DCD binary image
- -Update it with graphical view
- -Save it and export it in binary or C format.

<!-- image -->

## What is Image Vector Table (IVT) Tool?

- IVT is the main entry point in the boot flow:
- -Aggregates required images for the entire boot flow
- -Provides a fail-safe mechanism for corrupted images
- -Configures the boot flow (secure / non-secure)

## • IVT Composer tool

- -Assembles the required information from all the component images into a single flash binary
- -Provides a  flash memory mapping mechanism
- -Guards against memory overlapping errors
- -Automatic alignment of images to avoid memory segments overlapping

<!-- image -->

## S32 Configuration Tools - IVT Tool Features Summary

<!-- image -->

- Memory layout overview and segment overlapping detection. (1)
- Automatic memory segments alignment. Using a starting alignment  address the tool will generate start address for all images. (2)
- Export in binary and C format.
- Validation of selected choices. (3)
- Table with the list of images. Size of the image can be automatically determine if the user provides full path of the file. (4)

<!-- image -->

## S32 Design Studio Simulation Environment

- Pre-Silicon Development
- Allows the software development to take place before the hardware is ready, thus helping to validate design decisions
- Synopsys Virtualizer Development Kits (VDKs)
- Virtual prototypes (a simulation model of an embedded system) for S32S, S32G, S32V, S32R
- Embedded software samples and debugging tools
- VP Explorer Plug-In
- VLAB
- S32K2 support
- S32 Virtual Platform Toolbox

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## S32 Design Studio: Community

## Created for users to have easy access to support &amp; latest documentation

- Can post questions
- -Supported by NXP experts
- -Any community member can respond, reducing demand for NXP support
- -Browse existing threads, questions may have already been answered
- HOWTOs, videos, tutorials, examples
- -Can be posted anytime instead of waiting for next release
- Announce releases
- New products
- -New versions
- -Updates/bug patches
- -Advertisements for other communities
- Links to other communities
- Gather metrics
- -Identify popular topics/issues

<!-- image -->

<!-- image -->

| S32 Design Studio for Vision 2018.R1                                                                                                               | S32 Design Studio V3.x                                                                                                                                         |
|----------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| GNU Tools for ARM® (v4.9) GNU Bare-Metal Targeted Tools for ARM® 32-bit/64-bit (GCC version 6.3)                                                   | GNU Bare-Metal Targeted Tools for Arm® 32-bit/64-bit (GCC version 6.3)                                                                                         |
| GNU Linux Targeted Tools for ARM® 64-bit (GCC version 6.3)                                                                                         | GNU Linux Targeted Tools for Arm® 64-bit (GCC version 6.3)                                                                                                     |
| Libraries: NewLib, NewLib Nano, EWL, and EWLNano NXP APU compiler version 4.0.1                                                                    | Libraries: NewLib, NewLib Nano, EWL, and EWLNano NXP APU compiler version 4.0.1                                                                                |
| ISP assembler                                                                                                                                      | ISP assembler                                                                                                                                                  |
| Semihosting for Arm® 32-bit and 64-bit bare-metal target toolchains                                                                                | Semihosting for Arm® 32-bit and 64-bit bare-metal target toolchains                                                                                            |
| MSYS2 32bit version 1.0.0 GDB 7.12.1 with Python support                                                                                           | MSYS2 32bit version 1.0.0 GDB 7.12.1 with Python support                                                                                                       |
| GNU GDB clients for APEX2 and ISP coprocessor S32 Flash Tool                                                                                       | GNU GDB clients for APEX2 and ISP coprocessor S32 Flash Tool                                                                                                   |
| The wizards for creating application, library projects and projects from project examples for the supported processor families                     | The wizards for creating application, library projects and projects from project examples for the supported processor families                                 |
| A53 S32 Debugger                                                                                                                                   | Trace/Profiling Tools S32 Debugger                                                                                                                             |
| S32 Debug Probe support P&E Multilink/Cyclone/OpenSDA (with P&E GDB Server)=                                                                       | S32 Debug Probe support P&E Multilink/Cyclone/OpenSDA                                                                                                          |
| Integrated Vision SDK v1.2.0, Vision SDK project examples, Support for wizard creating projects from Vision SDK project examples                   | (with P&E GDB Server) Integrated Vision SDK v1.3.0, Vision SDK project examples, Support for wizard creating projects from Vision SDK project examples         |
| New project wizard to create application, library and Visual Graph Tools Visual Graph Tools to support ISP and APEX2 targeted software development | New project wizards to create Visual Graph Tools projects Visual Graph Tools to support the ISP and APEX2 targeted software design                             |
| Lauterbach debugger supported by the project creation wizard                                                                                       | Lauterbach Trace32® support                                                                                                                                    |
| EmbSys Registers view                                                                                                                              | EmbSys Registers view S32 Configuration Tool (provided by MCU-specific development packages) with the Pin, Clock, Peripheral (Part of S32 SDK for S32V23x) and |
| DDR Configuration and Validation DDR Stress Test tool                                                                                              | DDR Configuration Tools DDR Stress Test tool                                                                                                                   |
| Kernel Aware debugging for FreeRTOS, OSEK                                                                                                          | Kernel Aware debugging for FreeRTOS, OSEK                                                                                                                      |
| SDK management                                                                                                                                     | SDK management Integrated S32 SDK for S32V23x BETA 0.9.0 (Windows                                                                                              |
|                                                                                                                                                    | only)                                                                                                                                                          |
|                                                                                                                                                    | Integrated AMMCLIB SDKs for S32V234 version 1.1.15                                                                                                             |
| The Getting Started page                                                                                                                           | The Getting Started page                                                                                                                                       |
|                                                                                                                                                    | Support for importing MCAL configuration to a custom                                                                                                           |
|                                                                                                                                                    | SDK                                                                                                                                                            |

## Support provided via S32V2xx Extension Package

## Support provided via S32V2xx Development Package

<!-- image -->

## Conclusion S32 Design Studio for Next Generation Devices

- New S32 Design Studio Tool
- Modular Tooling
- Base NPI Support Development Packages
- Accelerator Support Extension Packages
- Support for all S32 Next Gen Parts
- Enhanced SDK Management
- SDK decoupling
- New ' Getting Started ' Page
- Extended Support for users
- New S32 Debugger
- New S32 Debug Probe
- Trace and Profiling Capability
- S32 Configuration Tool
- -Pins Tool
- -Graphical Clock Configuration
- -DCD Tool
- -Peripheral Configuration Tool
- -IVT Composer Tool
- -DDR Configuration Tool
- Virtual Development Environment
- -Integration with S32 Design Studio
- -Supports pre-silicon development
- -Support SW test and validation development

<!-- image -->