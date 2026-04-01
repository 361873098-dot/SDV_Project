S32G-VNP-RDB3

REAL TIME DRIVER

EXAMPLE ENABLEMENT GUIDE

PUBLIC

MARCH 2023

<!-- image -->

<!-- image -->

<!-- image -->

## CONTENTS

- Hands on UART Real Time Driver example
- Hands on ETH Real Time Driver example
- Hands on CAN Real Time Driver example

<!-- image -->

## HARDWARE REQUIREMENT AND SOFTWARE INSTALLATION

## Hardware Requirement

- S32G-VNP-RDB3
- S32 Debug Probe
- AD/DC power supply
- Serial port cable for UART example

## Software Installation

- -Install S32DS 3.5 according to S32G-VNP-RDB3 Software Enablement Guide
- -Install SW32G\_RTD\_4.4\_4.0.0\_D2210(RTD) according to S32G-VNP-RDB3 Software Enablement Guide

<!-- image -->

## Hands on UART Example

<!-- image -->

PUBLIC

3

## HANDS ON UART: OBJECTIVE

- How to import the UART example into S32DS
- How to configure the clock of UART via S32DS
- How to configure the UART module via S32DS
- How to debug the UART example with S32 debug probe

<!-- image -->

## HANDS ON UART: IMPORT UART EXAMPLE PROJECT

Open S32 Design Studio, go to "File -&gt; New -&gt; S32DS Project From Example". Select " Linflexd\_Uart\_Ip\_Example\_S32G399A\_M7 " example, click on "Finish". The project should now be copied into the current workspace.

<!-- image -->

The  "Linflexd\_Uart\_Ip\_Example\_S32G399A\_M7" example is a simple application which shows the usage of UART driver.

<!-- image -->

<!-- image -->

## HANDS ON UART: PIN CONFIGURATION

Open the Pins configuration tool . According to schematic of RDB3, configure pins routing. By default, this example already has corresponding pin routing configuration.

<!-- image -->

<!-- image -->

## HANDS ON UART: CLOCK CONFIGURATION 1

## Open the Clocks Diagram:

- Right-click the Project
- Select S32 Configuration Tools
- Select Open Clocks

<!-- image -->

<!-- image -->

## HANDS ON UART: CLOCK CONFIGURATION 2

Open the Peripheral Clock View , and double-click the Lin module. The Clocks Diagram will show the clock tree of the LinFlexD. The default clock configuration of UART is 48 MHZ which comes from FIRC directly.

<!-- image -->

<!-- image -->

## HANDS ON UART: UART CONFIGURATION 1

## Open the Peripherals Diagram:

- Right-click the Project
- Select S32 Configuration Tools
- Select Open Peripherals

<!-- image -->

<!-- image -->

## HANDS ON UART: UART CONFIGURATION 2

The Components shows all drivers which used by this example, the Linflexd\_Uart Component includes the configuration of UART driver

<!-- image -->

<!-- image -->

## HANDS ON UART: UPDATE CODE

## Generate code method:

1. Open the view of  any configuration tool, like Pins, then click Update Code (ensure desired project is selected)
2. The Update Files window pops up. It shows the detailed update information. Click OK button.
3. The configuration .c and .h files will be generated in "generate" folder.

<!-- image -->

<!-- image -->

## HANDS ON UART: APPLICATION CODE 1

## Dissecting the main.c

```
MCU clock initialization and Interrupt initialization Initialize pins Initialize LINFlexD module Send the greeting message to console int main（void) /*Writeyourcode here*/ /*Bufferto storethereceived message*/ uint8 rxBuff[RX_MSG_LEN]; uint32varRemainingBytes; Linflexd_Uart_Ip_StatusTypetransmitStatus=LINFLEXD_UART_IP_STATUS_ERROR; Linflexd_Uart_Ip_StatusType receiveStatus=LINFLEXD_UART_IP_STATUS_ERROR; *Initialize and configure clocks Setup system clocks,dividers see clock manager component for more details Clock Ip_Init(&Mcu_aClockConfigPB[o]); /* Interruptscontrollerinitialization*/ IntCtrl_Ip_Init(&IntCtrlConfig_0); IntCtrl_Ip_ConfigIrqRouting(&intRouteConfig); *Initialize pins Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0); *Initialize LINFlexD moduleforUARTusage* Linflexd_Uart_Ip_Init（LINFLEXD_INSTANCE,&Linflexd_Uart_Ip_xHwConfigPB 1_VS_0); Send the greeting message to console*/ Linflexd_Uart_Ip_AsyncSend(LINFLEXD_INSTANCE,（uint8*)WELCOME_MSG,strlen(WELCOME_MSG)); *Waitfordatasend */ while(Linflexd_Uart_Ip_GetTransmitStatus(LINFLEXD_INSTANCE,&varRemainingBytes)==LINFLEXD_UART_IP_STATUS_BUSY); transmitStatus=Linflexd_Uart_Ip_GetTransmitStatus(LINFLEXD_INSTANCE,&varRemainingBytes);
```

<!-- image -->

## HANDS ON UART: APPLICATION CODE 2

## Dissecting the main.c

```
/*Infinite loop*/ for(;;)
```

```
Echo the received data back Receive data from user * Get the message sent by user from the console,using a-sync method Linflexd_Uart_Ip_AsyncReceive(LINFLEXD_INSTANCE, rxBuff, strlen("Hello")); Waitfordatareceive/ while(Linflexd_Uart_Ip_GetReceiveStatus(LINFLEXD_INSTANCE, &varRemainingBytes) == LINFLEXD_UART_IP_STATUS_BUSY); receiveStatus =Linflexd Uart Ip GetReceiveStatus(LINFLEXD INSTANCE,&varRemainingBytes): * If the user typed "Hello",reply with the "Hello world!" message again * if(strcmp((char*)rxBuff,"Hello") =0) Linflexd_Uart_Ip_AsyncSend(LINFLEXD_INSTANCE, (uint8*)MSG, strlen(MSG)); /*WaitfordataSend*/ while(Linflexd_Uart_Ip_GetTransmitStatus(LINFLEXD_INSTANCE, &varRemainingBytes) == LINFLEXD_UART_IP_STATUS_BUSY); break; else Linflexd_Uart_Ip_AsyncSend(LINFLEXD_INSTANCE,(uint8*)ERROR_MSG, strlen(ERROR_MSG)); /*Wait fordatasend*/ while(Linflexd_Uart_Ip_GetTransmitStatus(LINFLEXD_INSTANCE,&varRemainingBytes) == LINFLEXD_UART_IP_STATUS_BUSY); break;
```

<!-- image -->

## HANDS ON UART: BUILD AND DEBUG 1

## Build the target :

- Right-click the Project
- Select Build Project
- Print Build information on Console window
- Linflexd\_Uart\_Ip\_Example\_S32G399A\_M7.elf is generated

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON UART: BUILD AND DEBUG 2

## Go to debug configuration:

- Right-click the Project
- Select the Debug As
- Click on Debug Configurations

<!-- image -->

## Debug configuration setting:

- Connect the S32 Debug probe with PC and RDB3
- Click on target project
- Select the target device and core as S32G399A\_M7\_0
- Select target S32 Debug Probe

<!-- image -->

<!-- image -->

## HANDS ON UART : DEBUG AND RUN

Power on the RDB3, click on "Apply", then click on "Debug". The view will switch to the Debug Perspective, and you can use the controls to control the program flow.

<!-- image -->

<!-- image -->

Q3

## HANDS ON UART: TEST RESULT

## Check the test result:

- Connect UART1 with PC and RDB3
- Open Serial terminal like Tera Term and configure the serial port
- Click on the Resume option in Debug view
- The Serial terminal will print messages
- Then input "Hello" in step 3
- UART1 will output 'Hello World!' back

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

76

## Hands on ETH Example

<!-- image -->

PUBLIC

1 8

## HANDS ON ETH - OBJECTIVE

- -How to import the ETH example into S32DS
- -How to configure the clock of ETH via S32DS
- -How to configure the port of ETH via S32DS
- -How to use the ETH module to transmit/receive ETH frame
- -How to debug the ETH example using S32 debug probe

<!-- image -->

## HANDS ON ETH: IMPORT ETH EXAMPLE PROJECT

Open S32 Design Studio, go to "File -&gt; New -&gt; S32DS Project From Example". Select " Gmac\_Ip\_InternalLoopback\_S32G399A\_M7 " example, then click on "Finish". The project is copied into the current workspace.

<!-- image -->

This 'Gmac\_Ip\_InternalLoopback\_S32G399A\_M7' example demonstrates the GMAC transmission and reception in internal loopback mode. The ETH frame is transmitted back directly through GMAC, and the frame will not be transmitted to PHY.

<!-- image -->

<!-- image -->

## HANDS ON ETH : PORT CONFIGURATION

## Pins configuration setting:

- Right-click the Project
- Select S32 Configuration Tools
- Select Open Pins
- Configure pins to provide the external clock to Tx, Rx signals

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON ETH : CLOCK CONFIGURATION

Open the Peripheral Clock View , and double-click the GMAC0 module. The Clocks Diagram shows the clock tree of GMAC module

<!-- image -->

| Overview     | Peripheral ClockView   | Code Preview    | Registers   | 三Details   |
|--------------|------------------------|-----------------|-------------|------------|
| Clock Name   | Enable                 | Source          | Divider     | Frequency  |
| FLEXCAN3_CLK | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| FRAYO_CLK    | M                      | FIRC_CLK        | /2          | 24 MHz     |
| FTIMERO_CLK  | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| FTIMER1_CLK  | M                      | FIRC_CLK        | / 1         | 48 MHz     |
| GMACO_RX_CLK |                        | GMAC_EXT_RX_REF | /1          | 25 MHz     |
| GMACO_TS_CLK | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| GMACO_TX_CLK | ?                      | PERIPH PHI5     | /5          | 25 MHz     |
| 1ICO_CLK     |                        | XBAR_DIV3 CLK   | 71          | 8 MHz      |
| IC1_CLK      |                        | XBAR_DIV3_CLK   | /1          | 8 MHz      |
| 1IC2_CLK     | ?                      | XBAR_DIV3_CLK   | / 1         | 8 MHz      |
| IIC3_CLK     | ?                      | XBAR_DIV3_CLK   | / 1         | 8 MHz      |
| IIC4_CLK     |                        | XBAR_DIV3_CLK   | /1          | 8 MHz      |
| LBISTO_CLK   | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST1_CLK   | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST2_CLK   | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST3_CLK   | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST4_CLK   | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST5_CLK   | ?                      | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST6_CLK   |                        | FIRC_CLK        | / 1         | 48 MHz     |
| LBIST7_CLK   |                        | FIRC_CLK        | / 1         | 48 MHz     |

<!-- image -->

<!-- image -->

## HANDS ON ETH: ETH CONFIGURATION

Open the peripheral configuration:

- Right-click the Project
- Select S32 Configuration Tools
- Select Open Peripherals

<!-- image -->

Select Components to find out GMAC Driver and double-click

<!-- image -->

PUBLIC

<!-- image -->

## HANDS ON ETH: UPDATE CODE

## Generate code method:

1. Open the view of any configuration tool, like Pins, then click Update Code (ensure desired project is selected)
2. 2.The Update Files window pops up. It shows the detailed update information. Click OK button.
3. 3.The configuration .c and .h files will be generated in " generate " folder.

<!-- image -->

<!-- image -->

## HANDS ON ETH: APPLICATION CODE 1

## Dissecting the main.c

```
int main(void)
```

```
C
```

Initialize pins to provide the external clock for GMAC Enable GMAC controller, initialize Tx and Rx buffer via the function Gmac\_Ip\_Init and initialize transmission buffer Gmac\_Ip\_TxOptionsType txOptions ={TRUE,GMAC\_CRC\_AND\_PAD\_INSERTION,GMAC\_CHECKSUM\_INSERTION\_DISABLE}; Gmac\_Ip\_BufferType txBuffer={o}; Gmac\_Ip\_BufferType rxBuffer ={o}; Gmac\_Ip\_TxInfoType txInfo; Gmac\_Ip\_RxInfoType rxInfo; Gmac\_Ip\_StatusType status; uint8 macAddr[6U]={0U}; uint8 i; uint8j=0U; boolean result = TRUE; OsIf\_Init(NULL\_PTR); Siul2\_Port\_Ip\_Init(NUM\_OF\_CONFIGURED PINSo,g\_pin\_mux\_InitConfigArrO); Clock\_Ip\_Init(&amp;Mcu\_aClockConfigPB[o]); Gmac\_Ip\_Init(INST\_GMAC\_O,&amp;Gmac\_O\_ConfigPB\_BOARD\_INITPERIPHERALS); /*Setuptheframe withthe Macaddressandsize*/ Gmac\_Ip\_GetMacAddr(INST\_GMAC\_0,macAddr);

```
/* Request a buffer of at least 64 bytes */ txBuffer.1ength =64U; result =FALSE; for(i=0U;i<12U;i++) *((uint8 *)(&txBuffer.data[oU] + i))= macAddr[0 + j]; if(j<5U) j++; else { j=0U;
```

Apply for Txbuffer via the function Gmac\_Ip\_GetTxBuff

<!-- image -->

## HANDS ON ETH: APPLICATION CODE 2

## Dissecting the main.c

```
/Payload=Frame-（DstAddr + SrcAddr+ EtherType/Length + FCS)*/
```

```
（++9+9）-9=（（0+eep*gx）（u0)）
```

```
/Send the ETH frame */ txBuffer.1ength = 64U-4U; /Don't count FcS,because it is automatically inserted by the controller in this example */ if （GMAC_STATUS_SUCCESS != Gmac_Ip_SendFrame（INST_GMAC_θ,eU,&txBuffer,&txOptions）) result = FALSE;
```

```
/* Wait for the frame to be transmitted */ do status = Gmac_Ip_GetTransmitStatus（INST_GMAC_θ,OU,&txBuffer,&txInfo); while（statuS ==GMAC_STATUS_BUSY); /*Check the frame status */ if （（GMAC_STATUS_SUCCESS I= Status)Il （eU I= txInfo.errMask)) result = FALSE; /*Wait for the frame to be received */ do{ status = Gmac_Ip_ReadFrame（INST_GMAC_0,OU,&rxBuffer,&rxInfo); while（statuS == GMAC_STATUS_RX_QUEUE_EMPTY); /串 Check the frame status */ if （（GMAC_STATUS_SUCCESS I= Status)Il （eU I= rxInfo.errMask)) result = FALSE;
```

```
Gmac_Ip_ProvideRxBuff(INST_GMAC_O,OU,&rxBuffer); Gmac_Ip_DisableController(INST_GMAC_0);
```

Transmit frame via Gmac\_Ip\_SendFrame

Verify frame is transmitted or received

<!-- image -->

## HANDS ON ETH: BUILD AND DEBUG 1

## Build target Project:

- Right-click the Project
- Build Project
- The console print build information
- Gmac\_Ip\_InternalLoopback\_S32G399A\_M7.elf is created

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON ETH: BUILD AND DEBUG 2

## Go to debug configuration:

- Right-click the Project
- Select the Debug As
- Click on Debug Configurations

## Debug configuration setting:

- Connect the S32 Debug probe with PC and RDB3
- Click on target project
- Select the target device and core as S32G399A\_M7\_0
- Select target S32 Debug Probe

<!-- image -->

<!-- image -->

## HANDS ON ETH: DEBUG AND RUN

Power on the RDB3, click on "Apply", then click on "Debug". The view will switch to the Debug Perspective, and you can use the controls to control the program flow.

<!-- image -->

<!-- image -->

87

## HANDS ON ETH: TEST RESULT 1

In this project, the Ethernet module works in internal loopback mode. Add a breakpoint to the last line of the main function, then click on the Resume option. The received ETH frame can be watched from rxBuffer.

<!-- image -->

<!-- image -->

## HANDS ON ETH: TEST RESULT 2

The received frame can be watched in rxBuffer.

<!-- image -->

<!-- image -->

## Hands on CAN Example

<!-- image -->

PUBLIC

3 2

## HANDS ON CAN - OBJECTIVE

- -How to import the CAN example into S32DS
- -How to configure the clock of CAN via S32DS
- -How to configure the port of CAN via S32DS
- -How to modify the CAN loopback
- -How to debug the CAN example with S32 debug probe

<!-- image -->

## HANDS ON CAN : IMPORT CAN EXAMPLE PROJECT

" example, then click on 'Finish'. The project is copied into current

<!-- image -->

Open S32 Design Studio, go to "File -&gt; New -&gt; S32DS Project From Example". Select " FlexCAN\_Ip\_Example\_S32G399A\_M7 workspace. S32DS Project from Example.

By default, "FlexCAN\_Ip\_Example\_S32G399A\_M7" project only shows the LoopBack function of FlexCAN.

<!-- image -->

<!-- image -->

## HANDS ON CAN: MODIFY THE EXAMPLE

The "FlexCAN\_Ip\_Example\_S32G399A\_M7" project only supports loopback mode. This guide will demonstrate how to modify the default configuration to transmit CAN frame from FlexCAN\_0 to FlexCAN\_1

<!-- image -->

<!-- image -->

## HANDS ON CAN: PORT CONFIGURATION 1

## Go to Pin configuration view:

- Right-click the Project
- Select S32 Configuration Tools
- Select Open Pins
- Enable Pins

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON CAN: PORT CONFIGURATION 2

Add the Pins as the schematic of FlexCAN0 and FlexCAN1

+5V0

| Routed Pins for BOARD...   | Routed Pins for BOARD...   | 4      |          |       |            |               |           |               |            |              |
|----------------------------|----------------------------|--------|----------|-------|------------|---------------|-----------|---------------|------------|--------------|
| #                          | Peripheral                 | Signal | Route to | Label | Identifier | Power group   | Direction | Output Buffer | Open Drain | Input Buffer |
| D7                         | CAN_0                      | rxd    | PB_02    |       | n/a        | VDD_IO_B (OV) | Input     | Disabled      | Disabled   | Enabled      |
| E7                         | CAN_0                      | txd    | PB_01    |       | n/a        | VDD_IO_B (OV) | Output    | Enabled       | Disabled   | Disabled     |
| E8                         | CAN 1                      | rxd    | PB 04    |       | n/a        | VDD_IO_B (OV) | Input     | Disabled      | Disabled   | Enabled      |
| C6                         | CAN 1                      | txd    | PB_03    |       | n/a        | VDD_IO_B (OV) | Output    | Enabled       | Disabled   | Disabled     |

<!-- image -->

<!-- image -->

## HANDS ON CAN: PORT CONFIGURATION 3

## Add the Port configuration:

- Right-click the Project,
- Select S32 Configuration Tools
- Select Open Peripherals
- Click on the plus button
- Click on the Siul2\_Port component
- Click on OK
- The Siul2\_Port driver will be added

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON CAN: CLOCK CONFIGURATION 1

Switch to clocks configuration view:

- Right-click the Project,
- Select S32 Configuration Tools
- Select Open Clocks

<!-- image -->

<!-- image -->

## HANDS ON CAN: CLOCK CONFIGURATION 2

Open the Peripheral Clock View , double-click the FLEXCAN0\_CLK . The Clocks Diagram will show the clock tree and the key node can be re-set. The default clock configuration of FlexCAN is 48 MHZ. Switch the clock which source from FXOSC( 40 MHZ).

<!-- image -->

<!-- image -->

## HANDS ON CAN: CAN CONFIGURATION 1

Mode setting for FlexCAN0:

- Right-click the Project,
- Select S32 Configuration Tools
- Select Open Peripherals
- Double-click FlexCAN component
- Set mode for FlexCAN0

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON CAN: CAN CONFIGURATION 2

Configure the BaudRate as 500Kbps for FlexCAN0

- TimeQuantum (seconds) = Prescaler / CanClockFrequency
- No. of CanTimeQuantas = (1 / CancontrollerBaudRate) / TimeQuantum
- No. of CanTimeQuantas = 1 + CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2

<!-- image -->

<!-- image -->

## HANDS ON CAN: CAN CONFIGURATION 3

## Add FlexCAN1:

- Right-click the Project,
- Select S32 Configuration Tools
- Select Open Peripherals

<!-- image -->

<!-- image -->

## HANDS ON CAN: CAN CONFIGURATION 4

## Add FlexCAN1:

- Double-click FlexCAN component
- Click on plus button to add FlexCAN\_1
- Set Clock as 40MHz for FlexCAN\_1
- Set Bitrate as 500kbps

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON CAN: UPDATE CODE

## Generate code method:

1. Open the view of any configuration tool, like Pins, then click Update Code (ensure desired project is selected)
2. 2.The Update Files window pops up. It shows the detailed update information. Click OK button.
3. 3.The configuration .c and .h files will be generated at 'generate' folder.

<!-- image -->

<!-- image -->

## HANDS ON CAN: APPLICATION CODE 1

## Modify the main.c:

```
Add the Port includes and Port initialization function 15/*Includingnecessaryconfiguration files.*/ 16 #include"Mcal.h" 17 #include"Clock_Ip.h" 18 #include"FlexCAN_Ip.h" 19 #include"IntCtrl_Ip.h" 20 #include"check_example.h" 21 22 #include"Siul2_Port_Ip.h" 2 24 #define FLEXCANO INST OU 25 #define FLEXCAN1 INST 1U 26 #define MSG_ID 20u 27 #define RX_MB_IDX 1U 28 #define TX MB_IDXOU 29 volatileintexit_code=0; 30/*Userincludes*/ 31uint8dummyData[8]={1,2,3,4,5,6,7}; 320/*! EE \brief The main function for the project. 34 \details The startup initialization sequence IS tne 35 -startup asm routine 36 -main() 37 */ 38 extern voidCANo_ORED_o_7_MB_IRQHandler(void); 6 externVoidCAN1_ORED_o_7_MB_IRQHandler(void); 40 41=int main（void) 42 43 /*Write your codehere*/ 44 Clock_Ip_Init(&Mcu_aClockConfigPB[o]); 45 46 Siul2_Port_Ip_Init(NUM_OF_cONFIGURED_PINSo,g_pin_mux_InitConfigArro); 47 48 IntCtrl_Ip_EnableIrq(CANo_ORED_0_7_MB_IRQn); 49 IntCtr1_Ip_InstallHandler(CANO_ORED_0_7_MB_IRQn,CANO_ORED_O_7_MB_IRQHandler,NULL_PTR); 50 51 IntCtrl_Ip_EnableIrq(CAN1_ORED_0_7_MB_IRQn); 52 IntCtr1_Ip_Insta1lHandler(CAN1_ORED_0_7_MB_IRQn,CAN1_ORED_0_7_MB_IRQHandler,NULL_PTR); 53
```

<!-- image -->

<!-- image -->

## HANDS ON CAN: APPLICATION CODE 2

## Modify the main.c:

```
Initialize FlexCAN_1 Controller FlexCAN0 send the message FlexCAN1 receive the message Configure Rx MailBox for FlexCAN_1 Flexcan_Ip_DataInfoType rx_info = { .msg_id_type =FLEXCAN_MSG_ID_STD, .data_length = 8u, .is_polling = TRUE, .is_remote = FALSE Flexcan_Ip_MsgBuffType rxData; FlexCAN_Ip_Init(FLEXCANo_INST, &FlexCAN_StateO,&FlexCAN_Config0); FlexCAN_Ip_SetStartMode(FLEXCANo_INST); FlexCAN_Ip_Init(FLEXCAN1_INST,&FlexCAN_State1, &FlexCAN_Config1); FlexCAN_Ip_SetStartMode(FLEXCAN1_INST); FlexCAN_Ip_ConfigRxMb（FLEXCAN1_INST,RX_MB_IDX,&rX_info,MSG_ID); rX_info.is_polling =FALSE; FlexCAN_Ip_Send(FLEXCANO_INST,TX_MB_IDX,&rx_info,MSG_ID,(uint8 *)&dummyData) FlexCAN_Ip_Receive(FLEXCAN1_INST, RX_MB_IDX, &rxData, TRUE); while（FlexCAN_Ip_GetTransferStatus（FLEXCANl_INST,RX_MB_IDX) != FLEXCAW_STATUS_SUCCESS) [FlexCAN_Ip_MainFunctionRead（FLEXCAN1_INST,RX_MB_IDX); } FlexCAN_Ip_SetStopMode(FLEXCANo_INST); FlexCAN_Ip_SetStopMode(FLEXCAN1_INST); FlexCAN_Ip_Deinit(FLEXCANo_INST); FlexCAN_Ip_Deinit(FLEXCAN1_INST); Exit_Example（TRUE);
```

<!-- image -->

## HANDS ON CAN: BUILD AND DEBUG 1

## Build target Project:

- Right-click the Project
- Build Project
- The console will print build information
- FlexCAN\_Ip\_Example\_S32G399A\_M7.elf is created

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## HANDS ON CAN: BUILD AND DEBUG 2

## Go to debug configuration:

- Right-click the Project
- Select the Debug As
- Click on Debug Configurations

## Debug configuration setting:

- Connect the S32 Debug probe with PC and RDB3
- Click on target project
- Select the target device and core as S32G399A\_M7\_0
- Select target S32 Debug Probe

<!-- image -->

<!-- image -->

## HANDS ON CAN: DEBUG AND RUN

Power on the RDB3, click on 'Apply', then click on 'Debug'. The view will switch to the Debug Perspective, and you can use the controls to control the program flow.

<!-- image -->

<!-- image -->

## HANDS ON CAN: TEST RESULT

Add a breakpoint to the FlexCAN\_Ip\_SetStopMode function, then click on the Resume option. The received CAN frame can be watched from rxData.

<!-- image -->

Note: Make sure FlexCAN\_0 connect to FlexCAN\_1 via physical wiring

<!-- image -->

<!-- image -->

<!-- image -->

## LEGAL INFORMATION

## · Definitions

Draft -A draft status on a document indicates that the content is still under internal review and subject to formal approval, which may result in modifications or additions. NXP Semiconductors does not give any representations or warranties as to the accuracy or completeness of information included in a draft version of a document and shall have no liability for the consequences of use of such information.

## · Disclaimers

Limited warranty and liability -Information in this document is believed to be accurate and reliable. However, NXP Semiconductors does not give any representations or warranties, expressed or implied, as to the accuracy or completeness of such information and shall have no liability for the consequences of use of such information. NXP Semiconductors takes no responsibility for the content in this document if provided by an information source outside of NXP Semiconductors.

In no event shall NXP Semiconductors be liable for any indirect, incidental, punitive, special or consequential damages (including - without limitation - lost profits, lost savings, business interruption, costs related to the removal or replacement of any products or rework charges) whether or not such damages are based on tort (including negligence), warranty, breach of contract or any other legal theory.

Notwithstanding any damages that customer might incur for any reason whatsoever, NXP Semiconductors' aggregate and cumulative liability towards customer for the products described herein shall be limited in accordance with the Terms and conditions of commercial sale of NXP Semiconductors.

Right to make changes -NXP Semiconductors reserves the right to make changes to information published in this document, including without limitation specifications and product descriptions, at any time and without notice. This document supersedes and replaces all information supplied prior to the publication hereof.

<!-- image -->

## LEGAL INFORMATION

Applications -Applications that are described herein for any of these products are for illustrative purposes only. NXP Semiconductors makes no representation or warranty that such applications will be suitable for the specified use without further testing or modification.

Customers are responsible for the design and operation of their applications and products using NXP Semiconductors products, and NXP Semiconductors accepts no liability for any assistance with applications or customer product design. It is customer's sole responsibility to determine whether the NXP Semiconductors product is suitable and fit for the customer's applications and products planned, as well as for the planned application and use of customer's third party customer(s). Customers should provide appropriate design and operating safeguards to minimize the risks associated with their applications and products. NXP Semiconductors does not accept any liability related to any default, damage, costs or problem which is based on any weakness or default in the customer's applications or products, or the application or use by customer's third party customer(s). Customer is responsible for doing all necessary testing for the customer's applications and products using NXP Semiconductors products in order to avoid a default of the applications and the products or of the application or use by customer's third party customer(s). NXP does not accept any liability in this respect.

Terms and conditions of commercial sale -NXP Semiconductors products are sold subject to the general terms and conditions of commercial sale, as published at http://www.nxp.com/profile/terms, unless otherwise agreed in a valid written individual agreement. In case an individual agreement is concluded only the terms and conditions of the respective agreement shall apply. NXP Semiconductors hereby expressly objects to applying the customer's general terms and conditions with regard to the purchase of NXP Semiconductors products by customer.

5 4 PUBLIC Suitability for use in automotive applications -This NXP product has been qualified for use in automotive applications. If this product is used by customer in the development of, or for incorporation into, products or services (a) used in safety critical applications or (b) in which failure could lead to death, personal injury, or severe physical or environmental damage (such products and services hereinafter referred to as 'Critical Applications'), then customer makes the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, safety, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP. As such, customer assumes all risk related to use of any products in Critical Applications and NXP and its suppliers shall not be liable for any such use by customer. Accordingly, customer will indemnify and hold NXP harmless from any claims, liabilities, damages and associated costs and expenses (including attorneys' fees) that NXP may incur related to customer's incorporation of any product in a Critical Application.

## LEGAL INFORMATION

Export control -This document as well as the item(s) described herein may be subject to export control regulations. Export might require a prior authorization from competent authorities.

Translations -A non-English (translated) version of a document, including the legal information in that document, is for reference only. The English version shall prevail in case of any discrepancy between the translated and English versions.

Security -Customer understands that all NXP products may be subject to unidentified vulnerabilities or may support established security standards or specifications with known limitations. Customer is responsible for the design and operation of its applications and products throughout their lifecycles to reduce the effect of these vulnerabilities on customer's applications and products. Customer's responsibility also extends to other open and/or proprietary technologies supported by NXP products for use in customer's applications. NXP accepts no liability for any vulnerability. Customer should regularly check security updates from NXP and follow up appropriately.

Customer shall select products with security features that best meet rules, regulations, and standards of the intended application and make the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP.

NXP has a Product Security Incident Response Team (PSIRT) (reachable at PSIRT@nxp.com) that manages the investigation,reporting, and solution release to security vulnerabilities of NXP products.

## · Trademarks

Notice: All referenced brands, product names, service names, and trademarks are the property of their respective owners. NXP - wordmark and logo are trademarks of NXP B.V.

<!-- image -->