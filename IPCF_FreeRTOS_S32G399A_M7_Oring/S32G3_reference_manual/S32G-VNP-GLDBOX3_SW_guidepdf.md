## S32G-VNP-GLDBOX3 SOFTWARE ENABLEMENT GUIDE

ＭＡＲＣＨ 2 0 2 3

<!-- image -->

<!-- image -->

## CONTENTS SOFTWARE ENABLEMENT GUIDE

- Get Software and Tools for S32G3
- Install Software and Tools for S32G3
- Light Up RGB LED using S32 Real Time Drivers
- Enable Linux BSP On Cortex-A53 Core

<!-- image -->

## Get Software and Tools for S32G3

<!-- image -->

PUBLIC

2

## GET SOFTWARE AND TOOLS FOR S32G3

- Please go to: S32G Processors for Vehicle Networking and use your NXP account to sign in.
- Please firstly download the below software for enablement

<!-- image -->

| Production                         | Install Packages                                               |
|------------------------------------|----------------------------------------------------------------|
| S32 Design Studio for S32 Platform | SW32G_S32DS_3.5.1_D2210.zip S32DS.3.5_b220726_win32.x86_64.exe |
| S32G3 - Real Time Drivers          | SW32_RTD_4.4_4.0.0_DS_updatesite_D2210.zip                     |

<!-- image -->

## GET SOFTWARE AND TOOLS FOR S32G3

- Download S32G3 - Real Time Drivers and S32DS update package:
- a. Please go to: https://www.nxp.com/app-autopackagemgr/software-package-manager:AUTO-SW-PACKAGE-MANAGER and choose S32G3 integrated Software Bundle(2023.02).
- b. Choose Real-Time-Drivers 4.0.0 item and S32 Design Studio and Configuration Tools 3.5.1\_D2210, download NXP\_Multi\_Install\_XXX.exe.
- c. Double click on NXP\_Multi\_Install\_XXX.exe on your local PC to download the packages . You will find SW32\_RTD\_4.4\_4.0.0\_DS\_updates ite\_D2210.zip and SW32G\_S32DS\_3.5.1\_D2210.zip  in  NXP\_Multi\_Installer\_XXX folder.

<!-- image -->

<!-- image -->

<!-- image -->

## GET SOFTWARE AND TOOLS FOR S32G3

- Download S32DS.3.5\_b220726\_win32.x86\_64.exe from https://www.nxp.com/design/software/development-software/s32-designstudio-ide/s32-design-studio-for-s32-platform:S32DS-S32PLATFORM

<!-- image -->

<!-- image -->

## GET SOFTWARE AND TOOLS FOR S32G3

- Get S32DS activation Code:

## Product Download

<!-- image -->

<!-- image -->

## Install Software and Tools for S32G3

<!-- image -->

PUBLIC

7

## STEP 1: INSTALL S32 DESIGN STUDIO 3.5

- Double click on the downloaded S32DS.3.5\_b220726\_win32.x86\_64.exe file to start installation.
- Click 'Next' to install the software step by step. Input the Activation code got from page 5 and choose 'Online'.

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 2: INSTALL DEVELOPMENT PACKAGES FOR S32G

- Open S32DS 3.5 and select a directory as workspace and select 'Install New Software …' option on Help menu.
- Add update package of S32DS.
- a. Click on 'Add' button '
- b. Click on 'Archive' button in Add Repository dialog
- c. Select the file SW32G\_S32DS\_3.5.1\_D2210.zip and click on 'open'
- d. Click on 'Add' button in Add Repository dialog

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 2: INSTALL DEVELOPMENT PACKAGES FOR S32G

- Select the four items as below and click on 'Next&gt;' button.
- Click on 'Next&gt;' button

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 2: INSTALL DEVELOPMENT PACKAGES FOR S32G

- Select the 'I accept the terms of the license agreements' button and click on 'Finish' button.
- Waiting for finishing the installation process and click on ' Restart Now ' button.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 3: INSTALL S32G REAL-TIME DRIVERS

- Open S32DS 3.5 and select a directory as workspace and click 'Install New Software …' option on help menu
- Add development package of S32DS a. Click on 'Add…'
- b. Click on 'Archive' button in Add Repository dialog
- c. Select SW32\_RTD\_4.4\_4.0.0\_DS\_updatesite\_D2210.zip file and click on 'open'
- d. Click on 'Add' button in Add Repository dialog.

<!-- image -->

<!-- image -->

<!-- image -->

c

<!-- image -->

<!-- image -->

## STEP 3: INSTALL S32G REAL-TIME DRIVERS

- Check the two items as below and click on 'Next' to install step by step
- Click on 'Next&gt;' button

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 3: INSTALL S32G REAL-TIME DRIVERS

- Choose 'I accept the terms of the license agreement.' option and click on 'Finish' button.
- Select 'NXP USA\,INC;null;NXP USA\,INC.' option and click on 'Accept selected' button.

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 3: INSTALL S32G REAL-TIME DRIVERS

- Waiting for finishing the installation process and click on ' Restart Now ' button.

<!-- image -->

<!-- image -->

<!-- image -->

## Light Up RGB LED using S32 Real Time Drivers

<!-- image -->

PUBLIC

1 6

## LIGHT UP RGB LED: HARDWARE RESOURCES

- Resources to be used: on-board RGB LED
- An RGB LED is a combination of three LED in one package: 1x Blue LED, 1x Red LED and 1x Green LED.
- On this guide, only the Blue LED(GPIO6) is used.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: CREATE PROJECT

- Create a new S32DS Application Project
- Input project name, select S32G399A(Boot core:M7) as processor, then click on 'Next' button.
- Select required core and SDKs
- a. Check only Cortex-M7\_0 core option and uncheck other cores options.
- b. Select 'PlatfprmSDK\_S32XX**(4.0.0) as SDKs and click on 'ok' button.
- c. Click on 'Finish' button to complete configuration.

<!-- image -->

<!-- image -->

3

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: PINS CONFIGURATION

- Select the created project and open Pins tool
- Select peripheral Signals, input 'SIUL2\_0' and find out SIUL2\_0 item
- Configure the corresponding gpio pins.
- a. Check gpio, 6 option.
- b. Click on 'Output'  button and 'OK' button to complete the pin configuration.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: ADD GPIO DRIVERS

- Select the created project and open Peripherals tool
- Select Components to find out Drivers option and Click on '+' option.
- Select 'Siul2\_Dio' option and click on 'OK' button to add Siul2\_Dio driver.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: CHECK CONFIGURATION AND UPDATE CODE

- Open Pins tool to check configuration
- Open Peripherals tool to check configuration
- Click on 'Update Code' button.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: CHECK CONFIGURATION AND UPDATE CODE

- Click on 'OK' button to start to update codes.

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: APPLICATION CODE

- Add header files of project configuration and module drivers in main.c file

```
1 All Rights Reserved. * NxP Confidential. This software is owned or controlled by NxP and may only be used strictly in accordance with the applicable license terms. By expressly B accepting such terms or by downloading. installing, activating and/or otherwise 6 using the software, you are agreeing that you have read, and that you agree to comply with and are bound by, such license terms. If you do not agree to be bound by the applicable license terms, then you may not retain, install, activate or otherwise use the software. @file main.c @addtogcoup, main_module main module documentation Including configuration files #include "Mcal.h" #include "Clock_Ip.h" #include "Siul2_Dio_Ip.h" #inelude "Siul2_Port_Ip.h" volatileintexit_code=U; * User includes */ 9 \brief The main function for the project. 2 \details The startup initialization sequence is the following: 3 -startup asm routine 4 -main() 5
```

## · Initialize clocks

2

crrhal

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: APPLICATION CODE

## · Initialize SIUL2

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: APPLICATION CODE

- Add the implementation of lighting up LED

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: BUILD PROJECT AND GENERATE .BIN FILE

- Open and modify the link file according to the noted information from reference manual of S32G3
- Select and build project, the .elf file will be generated
- Open the properties of project
- Check the 'Create flash image' box and click on 'Apply and Close'

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: BUILD PROJECT AND GENERATE .BIN FILE

- Re-open the properties of project, select 'Raw binary' as output file format and click on 'Apply and Close'
- Re-build the project
- The .bin file will be generated.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: MAKE IMAGE BY IVT TOOL

- Select the created project and open IVT tool
- Select M7\_0 as Boot Target core and select SD/MMC/eMMC as Boot device type
- Uncheck Self-Test DCD, DCD and HSE to be reserved

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: MAKE IMAGE BY IVT TOOL

- Configure Application Boot Image according to .ld file and .map file

<!-- image -->

Click browse to select .bin files generated from Page 26 and set Application bootloader (backup) Unreserved.

<!-- image -->

## LIGHT UP RGB LED: MAKE IMAGE BY IVT TOOL

- Export and save image
- Click on 'Align' button to align address.
- Click on 'Export Blob Image' to generate blob image and save final blob image.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: DOWNLOAD IMAGE INTO SD CARD

- Connect the UART0 port of S32G-VNP-GLDBOX3 with PC.
- Open S32FlashTool
- Set the port name of COM interface according to the actual condition of local PC.

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: DOWNLOAD IMAGE INTO SD CARD

- Select S32G3xxx as the target image and set SD as Algorithm

<!-- image -->

•

<!-- image -->

- Insert SD Card into the slot of S32G-VNP-GLDBOX3, set SW3 on and set SW9,10 to select serial boot mode (Refer to APPENDIX A)

| Part Reference Number   | Setting      |
|-------------------------|--------------|
| SW9                     | 1-OFF, 2-OFF |
| SW10                    | 1-OFF, 2-OFF |
| SW3                     | ON           |

<!-- image -->

## LIGHT UP RGB LED: DOWNLOAD IMAGE INTO SD CARD

- Click on 'Upload target and algorithm to hardware…' button and the log should be shown as below.
- Click 'Upload file to device…' button, set start address as 0x00 and select the generated blob image from page 30, click on 'OK' button.

<!-- image -->

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: DOWNLOAD IMAGE INTO SD CARD

- If the image downloading process is successful, the result log should be the similar as below.

<!-- image -->

<!-- image -->

## LIGHT UP RGB LED: SET RDB2 AND RUN APPLICATION

- Set SW3, 4, 9,10 to select SD card boot mode and set SW11 into 'ON' to connect RGB LED with S32G3 pin(Refer to APPENDIX B)
- Power on GLDBOX3, the RGB LED (U128) will be lighted in blue color.

| Part Reference Number   | Setting         |
|-------------------------|-----------------|
| SW3                     | ON              |
| SW4                     | 7-ON, Other-OFF |
| SW9                     | 1-OFF, 2-OFF    |
| SW10                    | 1-ON, 2-OFF     |
| SW11                    | ON              |

<!-- image -->

<!-- image -->

## Enable Linux BSP On Cortex-A53 Cores

<!-- image -->

PUBLIC

3 6

## STEP 1: INSTALL DEPENDENCES FOR DEFAULT YOCOTO

- The steps below have been validated on Ubuntu-18.04 LTS.
- Update the package manager sudo apt-get update
- Install python 2x - 2.6 or newer sudo apt-get install python
- Install git 1.8.3 or newer sudo apt-get install git
- Install curl sudo apt-get install curl
- Install repo mkdir ~/bin curl http://commondatastorage.googleapis.com /git-repo-downloads/repo &gt; ~/bin/repo chmod a+x ~/bin/repo PATH=${PATH}:~/bin
- Configure your git environment (you may skip this option if you have git already configured): git config --global user.email "you@example.com"

git config --global user.name "Your Name"

<!-- image -->

## STEP 2: DOWNLOAD YOCTO PROJECT ENVIRONMENT

- Create a dedicated directory for BSP

mkdir fsl-auto-yocto-bsp cd fsl-auto-yocto-bsp

- Choose the BSP branch and initialize the Yocto project for BSP

repo init -u https://github.com/nxp-auto-linux/auto\_yocto\_bsp -b release/bsp35.0 repo sync

<!-- image -->

## STEP 3: BUILD LINUX BSP IMAGE

- Prepare and confirm the building environment for the BSP

( Enter the directory fsl-auto-yocto-bsp)

./sources/meta-alb/scripts/host-prepare.sh

- Create build directory for target platform board

source nxp-setup-alb.sh -m s32g399ardb3

- Build BSP base Image

bitbake fsl-image-base

<!-- image -->

## STEP 3: BUILD LINUX BSP IMAGE

- Waiting for the building process finish, the BSP image will be generated like below.
- The generated BSP image(fsl-images32g399ardb3-xxx.rootfs.sdcard) is located at ' &lt;builddirectory&gt;/tmp/deploy/images/s32g399ar db3/ '.

<!-- image -->

<!-- image -->

<!-- image -->

## STEP 4: DOWNLOAD BSP IMAGE INTO SD CARD: IN LINUX

- Insert SD/MMC card reader into PC and identify the device node assigned to the SD/MMC card. It is assumed that the device assigned is /dev/sdb.
- Copy the generated image from page 39 to SD card device using dd command like below:

<!-- image -->

sudo dd if=./ fsl-image-base-s32g399ardb3xxx.rootfs.sdcard of=/dev/sdb bs=1M &amp;&amp; sync

```
jevon@jevon-virtual:~/Desktop/authurS sudo dd if=./fsl-image-base-s32g399ardb3-2 0220609034839.rootfs.sdcardof=/dev/sdbbs=1M&&sync sudo] password for jevon: 17+1recordsin 17+1recordsout 18493440bytes （18MB，18MiB） copied,3.96248S,4.7MB/s
```

Note: The steps in this page are only supported in Linux environment, if the user want to download the BSP image into SD card on Windows, please follow the steps on the next page.

<!-- image -->

## STEP 4: DOWNLOAD BSP IMAGE INTO SD CARD: IN WINDOWS

1. Install and Run Cygwin as administrator
2. Before inserting SD card into the slot, run 'cat /proc/partitions' cmd and note the current devices.
3. After inserting SD card into the slot, run cat /proc/partitions again and find out the SD card descriptor
4. Erase the sub-partition info on the SD card
5. dd if=/dev/zero of=/dev/sdb bs=512 count=1 &amp;&amp; sync
5. Copy the generated BSP image to the local folder on Windows and switch to the directory of folder by Cygwin. Burn all contents of the BSP image but the first four mega bytes into the SD card.

<!-- image -->

<!-- image -->

```
IPP$ if=/dev/zero of=/dev/sdb bs=512 count=1 && sync 1+0 records in 1+0 records out 512 bytes copied, 0.0033774 5, 152 kB/s
```

dd if= fsl-image-base-s32g399ardb3-xxx.rootfs.sdcard of=/dev/sdb bs=1M skip=4  seek=4 &amp;&amp; sync

<!-- image -->

6. Burn the first four mega bytes of the BSP image into the SD card

dd if= fsl-image-base-s32g399ardb3-xxx.rootfs.sdcard of=/dev/sdb bs=1M count=4 &amp;&amp; sync

```
dd i if=fs1-image-base-s32g399ardb3-20220609034839.rootfs.sdcard of=/dev/sdb bs=1M count=4 && sync 4+0 records in 4+0 records out 4194304 bytes (4.2 MB 4.0 MiB) copied, 0.564993 S , 7 .4 MB /s
```

```
Note: If the following prompt appears, please follow the steps below ① Take out the SD card and insert it again ② Execute dd if=/dev/zero of=/dev/sdb bs=512 count=1 && sync ③ Take out the SD card and insert it again dd: error /dev/sdb Permission denied 1+0 records in 0+0 records out bytes copied, 0.0063647 S 0.0 kB/s
```

- ④ Burn the image to the SD card

<!-- image -->

## STEP 5: SELECT BOOT MODE OF RDB2

- Set GLDBOX3 to SD card boot mode

<!-- image -->

| Part Reference Number   | Setting         |
|-------------------------|-----------------|
| SW3                     | ON              |
| SW4                     | 7-ON, Other-OFF |
| SW9                     | 1-OFF, 2-OFF    |
| SW10                    | 1-ON, 2-OFF     |

<!-- image -->

## STEP 6: RUN LINUX BSP

- Connect UART cable to UART0. Then open serial terminal and configure COM port, the baud rate is 115200.
- Power up the S32G-VNP-GLDBOX3 and view print message in serial terminal

<!-- image -->

<!-- image -->

<!-- image -->

## APPENDIX A: S32G-VNP-GLDBOX3 SERIAL BOOT SWITCH SETTINGS

<!-- image -->

<!-- image -->

## APPENDIX B: S32G-VNP-GLDBOX3 SD-CARD BOOT AND LED LIGHT UP SWITCH SETTINGS

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

4 8 PUBLIC Suitability for use in automotive applications -This NXP product has been qualified for use in automotive applications. If this product is used by customer in the development of, or for incorporation into, products or services (a) used in safety critical applications or (b) in which failure could lead to death, personal injury, or severe physical or environmental damage (such products and services hereinafter referred to as 'Critical Applications'), then customer makes the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, safety, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP. As such, customer assumes all risk related to use of any products in Critical Applications and NXP and its suppliers shall not be liable for any such use by customer. Accordingly, customer will indemnify and hold NXP harmless from any claims, liabilities, damages and associated costs and expenses (including attorneys' fees) that NXP may incur related to customer's incorporation of any product in a Critical Application.

## LEGAL INFORMATION

Export control -This document as well as the item(s) described herein may be subject to export control regulations. Export might require a prior authorization from competent authorities.

Translations -A non-English (translated) version of a document, including the legal information in that document, is for reference only. The English version shall prevail in case of any discrepancy between the translated and English versions.

Security -Customer understands that all NXP products may be subject to unidentified vulnerabilities or may support established security standards or specifications with known limitations. Customer is responsible for the design and operation of its applications and products throughout their lifecycles to reduce the effect of these vulnerabilities on customer's applications and products. Customer's responsibility also extends to other open and/or proprietary technologies supported by NXP products for use in customer's applications. NXP accepts no liability for any vulnerability. Customer should regularly check security updates from NXP and follow up appropriately. Customer shall select products with security features that best meet rules, regulations, and standards of the intended application and make the ultimate design decisions regarding its products and is solely responsible for compliance with all legal, regulatory, and security related requirements concerning its products, regardless of any information or support that may be provided by NXP.

NXP has a Product Security Incident Response Team (PSIRT) (reachable at PSIRT@nxp.com) that manages the investigation,reporting, and solution release to security vulnerabilities of NXP products.

## · Trademarks

Notice: All referenced brands, product names, service names, and trademarks are the property of their respective owners. NXP - wordmark and logo are trademarks of NXP B.V.

<!-- image -->