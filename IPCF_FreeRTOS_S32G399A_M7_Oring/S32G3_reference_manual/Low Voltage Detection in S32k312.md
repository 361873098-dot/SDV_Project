- [**Forums**](https:\community.nxp.com\t5\Forums\ct-p\NXP-Forums)

- [**Knowledge Bases**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**NXP Tech Blogs**](https:\community.nxp.com\t5\NXP-Tech-Blogs\ct-p\nxp-tech-blogs)

- [**NXP.COM**](https:\www.nxp.com)

[**Sign In**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32K%2FLow-Voltage-Detection-in-S32k312%2Fm-p%2F2127364) [**FAQs**](https:\community.nxp.com\t5\help\faqpage)

Language

- [Home](https:\community.nxp.com)

- [Product Forums](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32K](https:\community.nxp.com\t5\S32K\bd-p\S32K)

- Low Voltage Detection in S32k312

**Low Voltage Detection in S32k312**

窗体顶端

窗体底端

‎07-02-2025 08:34 AM

1,119 Views

<!-- image -->

[**emerging**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\173289)

Contributor III

Hello NXP team,

We need to generate an interrupt in s32k312 when the microcontroller input voltage reaches on LVD.

The below steps are followed for this configuration

- /Mcu/Mcu/McuModuleConfiguration/McuPowerControl/McuPMC\_Config - enabled

-/Mcu/Mcu/McuGeneralConfiguration[0: McuVoltageErrorIsrUsed] - set to TRUE

-/ActiveEcuC/Os/ PMC \_LVD ISR configured with category 2

-/Mcu/Mcu/McuGeneralConfiguration[0: McuErrorIsrNotification (set a call back here)]

but we are not getting any interrupt call back to the specified notification function.

Could you please look into this issue and let us know if we missed any necessary configurations

Thanks and regards,

- Tags:
- [lvd](https:\community.nxp.com\t5\tag\lvd\tg-p\board-id\S32K)
- [s32k](https:\community.nxp.com\t5\tag\s32k\tg-p\board-id\S32K)
- [S32k312 LVD detection](https:\community.nxp.com\t5\tag\S32k312%20LVD%20detection\tg-p\board-id\S32K)
- [All forum topics](https:\community.nxp.com\t5\S32K\bd-p\S32K\page\1157)
- [Previous Topic](https:\community.nxp.com\t5\S32K\EB-tresos-Studio-28-2-download\td-p\1539444)
- [Next Topic](https:\community.nxp.com\t5\S32K\s32k-SAF-Evaluation-Installer\td-p\2129299)

**5 Replies**

‎07-02-2025 11:34 AM

1,100 Views

<!-- image -->

<!-- image -->

Julián\_AragónM

NXP TechSupport

Hi [@emerging](https:\community.nxp.com\t5\user\viewprofilepage\user-id\173289) ,

Could you check if **PMC.CONFIG[LVDIE]** is set? LVD circuitry is always reporting if voltages in VDD\_HV\_A &amp; V15 domains are okay, via **LVSC** register, so the software can poll the corresponding flags. But the S32K3 will only be interrupted if the **LVDIE** is set in the P **MC-&gt;CONFIG** register.

Best regards,
Julián

‎07-02-2025 10:30 PM

1,087 Views

<!-- image -->

[**emerging**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\173289)

Contributor III

Hello Julian,

Yes the LVDIE is set for us I have attached the register reading for reference

<!-- image -->

Please check and reply your comments

‎07-03-2025 11:33 AM

1,072 Views

<!-- image -->

<!-- image -->

Julián\_AragónM

NXP TechSupport

Hi [@emerging](https:\community.nxp.com\t5\user\viewprofilepage\user-id\173289) ,

How are you testing the low voltage for the MCU? You can try limiting the external supply current or supply voltage, which maybe can generate a LVR and LVD events. You can look at section **6.2** from the S32K3 datasheet for the LVR assert threshold.

You could also start by polling the flags in the PMC register to see if the low voltage is being triggered correctly, for example:

uint32\_t PMC\_Status = 0;

boolean LVR11F = 0;

boolean LVR25F = 0;

boolean LVRAF = 0;

int main(void)

{

...........

PMC\_Status = IP\_PMC-&gt;LVSC;//get LVSC register vaule

if((PMC\_Status &amp; PMC\_LVSC\_PORF\_MASK) &gt;&gt; 31)// LVSC-&gt;PORF,a power-on reset event has occurred.

{

LVR11F = (PMC\_Status &gt;&gt; 22) &amp; 0x01;//LVSC bit 22

LVR25F = (PMC\_Status &gt;&gt; 20) &amp; 0x01;//LVSC bit 20

LVRAF  = (PMC\_Status &gt;&gt; 16) &amp; 0x01;//LVSC bit 16

}

IP\_PMC-&gt;LVSC = 0xFFFFFFFF;//clear all flags

............

for(;;)

{

......;

}

}

Best regards,
Julián

‎07-03-2025 07:22 PM

1,051 Views

<!-- image -->

[**emerging**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\173289)

Contributor III

Hello Julian,

Thanks for your reply, I will check as per your suggestion. Also, could you please let me know Why do we clear the register with IP\_PMC-&gt;LVSC = 0xFFFFFFFF;? What is the purpose of this action?"

I want to clarify that I need to implement Low Voltage Detection (LVD), not Low Voltage Reset (LVR). I hope your explanation pertains to LVD.

Thanks and Regards,

Emerging

‎07-07-2025 03:21 PM

1,026 Views

<!-- image -->

<!-- image -->

Julián\_AragónM

NXP TechSupport

Hi [@emerging](https:\community.nxp.com\t5\user\viewprofilepage\user-id\173289) ,

This is a simple routine for low voltage reset check. I understand you want to implement LVD, but the code checks for LVR in order to confirm you are indeed limiting the external supply correctly to generate a LVD interrupt.

I hope this is clear. Were you able to generate a LVR and LVD event?

Best regards,
Julián

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