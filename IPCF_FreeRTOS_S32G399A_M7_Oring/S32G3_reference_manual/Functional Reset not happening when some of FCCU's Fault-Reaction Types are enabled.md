- [**Forums**](https:\community.nxp.com\t5\Forums\ct-p\NXP-Forums)

- [**Knowledge Bases**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**NXP Tech Blogs**](https:\community.nxp.com\t5\NXP-Tech-Blogs\ct-p\nxp-tech-blogs)

- [**NXP.COM**](https:\www.nxp.com)

[**Sign In**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32K%2FFunctional-Reset-not-happening-when-some-of-FCCU-s-Fault%2Fm-p%2F1980149) [**FAQs**](https:\community.nxp.com\t5\help\faqpage)

Language

- [Home](https:\community.nxp.com)

- [Product Forums](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32K](https:\community.nxp.com\t5\S32K\bd-p\S32K)

- Functional Reset not happening when some of FCCU's Fault-Reaction Types are enabled

**Functional Reset not happening when some of FCCU's Fault-Reaction Types are enabled**

窗体顶端

窗体底端

‎10-23-2024 03:57 AM

15,841 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello everyone,

I'm having some trouble with FCCU and FS26's Microcontroller Recovery Strategy when i want to perform a functional reset on the microcontroller.

So, in FS26's documentation it explains how when a fault occurs and it is transmitted through the EOUT Pins to FS26, the SBC can enter a "microcontroller recovery strategy" in which the objective is to try and recover the fault inside a time window (WDW\_RECOVERY) and not give the microcontroller a reset, i.e., the FS26 send a reset command to the microcontroller.

That being so, i configured my time window with 1024ms and, when i inject a fault and the EOUT Pins indicate a faulty condition to FS26, it will open that window and there i will try to perform a functional reset (SW\_FUNC\_RST or FCCU\_RST) so my program restarts and clears the fault in FCCU's initialization, "eMcem\_Init()" API Function, and then refreshes the watchdog after FS26's initialization process. With this, the system would go back to a Normal State and no resets were needed to happen.

The problem is that the program only restarts, i.e., the microcontroller is given a functional reset, when the fault-reaction type enabled is " **Activate EOUT Pins"** . When i enable any of the other reaction-types (Recovery Timeout, Alarm State Interrupt or Fault State NMI), the RESET\_B Pin gets asserted, **but the program doesn't restart** .

In the annexes of this post i'm leaving one of the tests i made showing this behavior. It may be confusing, but i'm going to try to make a resume of what happens during each stage:

(1) The program begins in the main function and starts initializing the MCU, Peripherals, SPI, Timers, etc

(2) The FCCU initialization begins with "eMcem\_Init()" API Function (which clears all faults) and then FS26 is initialized (and the watchdog refreshing begins, look at D11 - SBC WATCHDOG NOTIFICATION Pin)

(3) A fault, with nFaultID = 72, is injected with "eMcem\_InjectFault(nFaultID)". The program initially enters the ALARM State and, since it can't clear the fault (D8 - ERR\_NOT\_RECOVERED Pin), FCCU's state machine enters Fault State and indicates a Faulty Condition to off-chips on the EOUT Pins

(4) The WDW\_RECOVERY window opens from FS26's side

(5) As a fault-reaction, a functional reset happens (FCCU\_RST is active in TRACE32's window)

(6) The program doesn't restart (when it was supposed to) and, after WDW\_RECOVERY window reaches its timeout value, FS26 will start its initialization phase which won't be addressed because the program didn't restart (and is stuck in the NMI Handler)

(7) Since FS26's INIT\_FS isn't addressed, the Fault Error Counter maximum value will be reached, thus making the FS26 initiate a Power-On-Reset, which will eventually start the program again.

As you can see this isn't the behavior that we're expecting to happen considering the "microcontroller recovery strategy"'s definition.

I contacted an NXP Employee and they tried my project on a similar board, S32K344EVB-Q257, but it had a different behavior, and so i was told to create this post here in the community to get some help.

Is anyone with a similar issue or someone that could help me?

Best Regards,

JRodrigues

- Tags:
- [fault reaction](https:\community.nxp.com\t5\tag\fault%20reaction\tg-p\board-id\S32K)
- [fccu](https:\community.nxp.com\t5\tag\fccu\tg-p\board-id\S32K)
- [fs26](https:\community.nxp.com\t5\tag\fs26\tg-p\board-id\S32K)
- [functional reset](https:\community.nxp.com\t5\tag\functional%20reset\tg-p\board-id\S32K)
- [Microcontroller Recovery Strategy](https:\community.nxp.com\t5\tag\Microcontroller%20Recovery%20Strategy\tg-p\board-id\S32K)
- [reset](https:\community.nxp.com\t5\tag\reset\tg-p\board-id\S32K)
- [s32k](https:\community.nxp.com\t5\tag\s32k\tg-p\board-id\S32K)
- [S32K344](https:\community.nxp.com\t5\tag\S32K344\tg-p\board-id\S32K)
- [sbc](https:\community.nxp.com\t5\tag\sbc\tg-p\board-id\S32K)

[**Fault\_Injected.png**](https:\community.nxp.com\t5\S32K\Functional-Reset-not-happening-when-some-of-FCCU-s-Fault\m-p\1980149\thread-id\42432?attachment-id=185418)

506 KB

- [All forum topics](https:\community.nxp.com\t5\S32K\bd-p\S32K\page\963)
- [Previous Topic](https:\community.nxp.com\t5\S32K\MC33665A-footprint-and-datasheet-not-found\td-p\1987796)
- [Next Topic](https:\community.nxp.com\t5\S32K\Need-Help-with-Hardware-Comparator-Settings-for-ADC-with-DM\td-p\1985979)

**15 Replies**

‎10-24-2024 03:30 AM

15,796 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello everyone,

I would like to make some corrections to the first post and i will do so in this reply since i can't edit my initial post.

"The problem is that the program only restarts, i.e., the microcontroller is given a functional reset..."

When i say "the microcontroller is given a functional reset", i don't mean that the microcontroller receives a functional reset command from FS26's side, but rather the FCCU\_RST happens since the fault-reaction type set for the fault i am injecting is a **short reset** reaction.

(3) A fault, with nFaultID = 72, is injected with "eMcem\_InjectFault(nFaultID)".

That fault is actually injected with the "eMcem\_AssertSWFault(nFaultID)" API function, since it belongs to the "Software Notification" group of faults!

(5) As a fault-reaction, a functional reset happens (FCCU\_RST is active in TRACE32's window)

Once again, the fault-reaction type for that fault is set to **short reset** , thus the FCCU\_RST being set in TRACE32's window.

Also, and to add to the post, i will leave here an image with the microcontroller's behavior when the functional reset happens **and the program restarts** .

**Note 1:** The program didn't restart during the WDW\_RECOVERY window, but i think that's because no watchdog refresh is happening during that time, which won't make the microcontroller go back to its normal operation mode. To make it go to its "normal operation mode", both of these points need to happen:

- All faults need to be cleared
- A good watchdog refresh needs to happen

That's why FS26 eventually resets and starts its initialization phase again!

**Note 2:** I suspect the functional reset in this case might be happening because the FOSU is activated since all other reaction types are disabled, and it generates the functional reset, but please correct me if i am wrong.

- Tags:
- [fccu](https:\community.nxp.com\t5\tag\fccu\tg-p\board-id\S32K)
- [fs26](https:\community.nxp.com\t5\tag\fs26\tg-p\board-id\S32K)
- [functional reset](https:\community.nxp.com\t5\tag\functional%20reset\tg-p\board-id\S32K)
- [Microcontroller Recovery Strategy](https:\community.nxp.com\t5\tag\Microcontroller%20Recovery%20Strategy\tg-p\board-id\S32K)
- [reset](https:\community.nxp.com\t5\tag\reset\tg-p\board-id\S32K)
- [s32k](https:\community.nxp.com\t5\tag\s32k\tg-p\board-id\S32K)
- [S32K344](https:\community.nxp.com\t5\tag\S32K344\tg-p\board-id\S32K)
- [sbc](https:\community.nxp.com\t5\tag\sbc\tg-p\board-id\S32K)

[**R3\_FaultReaction.png**](https:\community.nxp.com\t5\S32K\Functional-Reset-not-happening-when-some-of-FCCU-s-Fault\m-p\1980149\thread-id\42432?attachment-id=185504)

266 KB

‎10-24-2024 08:24 AM

15,771 Views

<!-- image -->

<!-- image -->

[**quangvuanh**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202)

NXP Employee

Hi [@JRodrigues](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Here is my assumption:

After the program triggered FCCU  fault, FS26 would be in FS0B\_ASSERTED state. Then the microcontroller recovered from functional reset, invoked Sbc\_fs26\_InitDevice() again, but at that moment, the function cannot start wdg service routine as the device's current state is in FS0B\_ASSERTED.

My suggestion is to force FS26 device back to INIT\_FS after functional reset, by invoking Sbc\_fs26\_GotoInitFS() , before invoking Sbc\_fs26\_InitDevice() again.

‎10-24-2024 09:00 AM

15,753 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

I just tested that and it worked for the case where only "Activate EOUT Pins" is enabled.

I tested the other fault-reaction types by doing the following configuration:

- Reaction type: **short reset reaction**
- Recovery Timeout: **Enabled**
- Alarm State Interrupt: **Enabled**
- Fault State NMI: **Disabled**
- Activate EOUT Pins: **Enabled**

and inside the Alarm Handler i return "ERR\_NOT\_RECOVERED" so that FCCU goes to the FAULT State, signals the faulty condition to the EOUT Pins and starts the functional reset, but in this case the program doesn't restart.

Best Regards,

JRodrigues

[**ProgramNotRestarting.png**](https:\community.nxp.com\t5\S32K\Functional-Reset-not-happening-when-some-of-FCCU-s-Fault\m-p\1980149\thread-id\42432?attachment-id=185528)

212 KB

‎10-24-2024 09:57 AM

15,736 Views

<!-- image -->

<!-- image -->

[**quangvuanh**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202)

NXP Employee

I have more experience on FS26, not much knowledge on eMCEM. However, can you please try to add other signal that is more realiable (eg. assert GPIO pin before calling eMCEM\_Init) than eMCEM EOUT signal because I am thinking that there is an issue with eMCEM\_Init, it cannot clear injected fault.

Another assumption: is there any possibility that after functional reset, the program jump into Alarm\_Handler again because the fault was not clear?

‎10-25-2024 01:00 AM

15,687 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

I tried to test what you suggested, but as you can see in the image annexed, since the program doesn't restart, the GPIO Pin only toggles at the start of the first "program run" (right before eMcem\_Init) and then at the functional reset...

Regarding the program jumping to the ALARM Handler again after the reset, i have left another image with the FCCU Registers right after the Functional Reset. The program is in the Fault State still.

Best Regards,

JRodrigues

[**FCCU Registers After Reset.png**](https:\community.nxp.com\t5\S32K\Functional-Reset-not-happening-when-some-of-FCCU-s-Fault\m-p\1980149\thread-id\42432?attachment-id=185578)

70 KB

[**GPIO Pin Toggling.png**](https:\community.nxp.com\t5\S32K\Functional-Reset-not-happening-when-some-of-FCCU-s-Fault\m-p\1980149\thread-id\42432?attachment-id=185579)

105 KB

‎10-28-2024 08:28 PM

15,609 Views

<!-- image -->

<!-- image -->

[**quangvuanh**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202)

NXP Employee

Hi [@JRodrigues](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

We are trying to set up the board to reproduce the issue, technically I dont see any reason why the functional reset didnot work as expect.

I would also like to ask for a confirmation, can you try to you remove the sequence related to FS26 and see if the functional reset worked?

‎10-29-2024 02:49 AM

15,587 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

I had another project (without the sequence related to FS26) where the functional reset was working as expected, but there was a slight difference in the configurations.

In the MCU Driver, under the McuModeSettingConf tab and in the McuPeripheral tab, PLL was **disabled.**

I discussed some clock issues with [@RadoslavB](https:\community.nxp.com\t5\user\viewprofilepage\user-id\155006) before, and the problem i had (which was a PIT interrupt not happening every X seconds, it happened at random times) was solved after enabling the PLL Clock under the McuPeripheral tab, and doing this initialization:

<!-- image -->

So, i guess the issue might be here. When the PLL Clock is **enabled** , the functional reset **doesn't happen** .

When it is **disabled** , the functional reset **works as expected.**

Are these two topics related to one another?

Best Regards,

JRodrigues

‎10-29-2024 07:15 AM

15,572 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

Another note on this test:

When PLL is **enabled** , and right after the reset, the program seems to be stuck inside the NMI Handler and maybe that's why it never restarts the program, because once the microcontroller begins the program, it automatically jumps to the NMI Handler due to faults being present in the FCCU that have the "Fault State NMI Enable" reaction type enabled.

Is there a way to fix this?

Best Regards,

JRodrigues

‎10-29-2024 08:39 AM

15,566 Views

<!-- image -->

<!-- image -->

[**quangvuanh**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202)

NXP Employee

Hi [@JRodrigues](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926) , I found this information being mentioned in the User Manual of eMCEM module.

<!-- image -->

<!-- image -->

To overcome this issue, I think [@RadoslavB](https:\community.nxp.com\t5\user\viewprofilepage\user-id\155006) could have more experience than me, please take a look and consider.

Additionally, with your current tests you see that functional reset **does not work** in both cases when **PLL is enabled** right? Regardless of FS26 configuration?

‎10-29-2024 09:04 AM

15,555 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

functional reset **does not work** in both cases when **PLL is enabled** right? Regardless of FS26 configuration?

The reset happens, but when the program restarts it goes immediately to the NMI Handler (in both cases). At least that's what i could see when i attached Lauterbach right after the functional reset.

I found this information being mentioned in the User Manual of eMCEM module.

I do understand that, but wouldn't that go against the purpose of the Microcontroller Recovery Strategy described in FS26's documentation?

My idea, and what i discussed with [@RadoslavB](https:\community.nxp.com\t5\user\viewprofilepage\user-id\155006) , was that once the program entered the NMI Handler, the FCCU\_RST would trigger and the program would restart (in the main function), clear all faults when "eMcem\_Init()" is called and then proceed to FS26's initialization.

Once this was over we would have achieved the 2 conditions to go back to normal mode (All faults cleared and a good watchdog refresh) and we would avoid resetting the microcontroller from the SBC side.

Am i thinking wrong here?

Best Regards,

JRodrigues

‎10-29-2024 09:49 AM

15,522 Views

<!-- image -->

<!-- image -->

[**quangvuanh**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202)

NXP Employee

Hi [@JRodrigues](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

I do understand that, but wouldn't that go against the purpose of the Microcontroller Recovery Strategy described in FS26's documentation?

It does not go against the Recovery Strategy. If Mcu gets stuck in NMI Handler, means it failed to recover from faults, then FS26 acts as external observer to prevent your MCU from being stuck forever there. Vice versa, if Mcu recovers successfully and refresh wdg recovery timer of FS26, the application program goes back to its normal state.

‎10-29-2024 10:04 AM

15,518 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

I'm sorry for insisting on this, but i truly don't understand it.

Because any fault that i inject that goes to the NMI Handler (and the purpose of the NMI is to store the fault information and then perform a **functional reset** , following the documentation), makes the program go back to the NMI Handler, and since i don't do anything to clear the faulty condition, the SBC will eventually send a POR.

So, what exactly is the purpose of the Microcontroller Recovery Strategy if in the end every fault will make the program get stuck in the NMI and the SBC will send the POR? I don't see the purpose.. In that case i would just ignore the Microcontroller Recovery Strategy and the SBC would instantly perform the POR after the EOUT Pins indicated a faulty condition.

Please enlighten me and, if needed, contact me through the private messages so we can schedule a meeting to discuss this issue.

Best Regards,

JRodrigues

‎10-28-2024 06:40 AM

15,627 Views

<!-- image -->

[**JRodrigues**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\232926)

Contributor III

Hello [@quangvuanh](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202) ,

Do you have any news on this topic?

Best Regards,

JRodrigues

‎11-05-2024 09:17 AM

15,352 Views

<!-- image -->

<!-- image -->

[**RadoslavB**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\155006)

NXP Employee

Hello,

as per last debug session we have found out that LockStep error is present which is causing eMcem\_Init() failing because the LockStep error can't be cleared.
This HW issue is raised only when debugger is connected and system reset is performed (by Lauterbach CMM script in this case).

Please use updated project.cmm script from the attachment.
When the debugger stops in the beginning of the main() please check FCCU NCF\_S0 register, it should have now value of 0 - no faults.

Now eMcem\_Init() should return E\_OK and rest of the application functionality will be not affected by the lockstep error and should not cause the reset issues.


Kind Regards,
Radoslav

**project.zip**

‎10-24-2024 08:53 AM

15,759 Views

<!-- image -->

<!-- image -->

[**quangvuanh**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\220202)

NXP Employee

[@RadoslavB](https:\community.nxp.com\t5\user\viewprofilepage\user-id\155006)

<!-- image -->

- [**About NXP**](https:\www.nxp.com\company\about-nxp:ABOUT-NXP)
- [**Careers**](https:\www.nxp.com\company\about-nxp\careers:CAREERS)
- [**Investors**](https:\www.nxp.com\company\about-nxp\investor-relations:INVESTOR-RELATIONS)
- [**Media**](https:\www.nxp.com\company\about-nxp\newsroom:NEWSROOM)
- [**Contact**](https:\www.nxp.com\company\about-nxp\contact-us:CONTACTUS)
- [**My NXP Account Benefits**](https:\www.nxp.com\support\support\my-nxp-account-benefits:NXP-ACCOUNT-BENEFITS)
- [Privacy](https:\www.nxp.com\company\about-nxp\privacy-statement:PRIVACYPRACTICES)
- [Terms of Use](https:\www.nxp.com\company\about-nxp\terms-of-use:TERMSOFUSE)
- [Terms of Sale](https:\www.nxp.com\company\about-nxp\our-terms-and-conditions-of-commercial-sale:TERMSCONDITIONSSALE)
- [Modern Slavery Report](https:\www.nxp.com\company\about-nxp\sustainability\social-responsibility\labor-and-human-rights:LABOR-AND-HUMAN-RIGHTS)
- [Accessibility](https:\www.nxp.com\company\about-nxp\accessibility:ACCESSIBILITY)
- [Website Feedback](https:\www.nxp.com\products\website-feedback:WEBSITE-FEEDBACK)

©2006-2026 NXP Semiconductors. All rights reserved.