- [**Forums**](https:\community.nxp.com\t5\Forums\ct-p\NXP-Forums)

- [**Knowledge Bases**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**NXP Tech Blogs**](https:\community.nxp.com\t5\NXP-Tech-Blogs\ct-p\nxp-tech-blogs)

- [**NXP.COM**](https:\www.nxp.com)

[**Sign In**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32G%2Fs32g-BootRom-amp-reset%2Fm-p%2F2028867) [**FAQs**](https:\community.nxp.com\t5\help\faqpage)

Language

- [Home](https:\community.nxp.com)

- [Product Forums](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32G](https:\community.nxp.com\t5\S32G\bd-p\S32G)

- s32g BootRom &amp;amp; reset

**s32g BootRom &amp; reset**

窗体顶端

窗体底端

SOLVED

[Jump to solution](https:\community.nxp.com\t5\S32G\s32g-BootRom-amp-reset\m-p\2029196)

‎01-16-2025 01:52 AM

1,108 Views

<!-- image -->

[**jiajun\_cheng**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\241854)

Contributor III

Hi, Dear nxp fellow:

I have some questions when reading the S32G3 RM manual recently.

1. When reading the Boot chapter of the s32g3 RM manual, it mentions boot

The HSE\_H core begins executing firmware from the HSE\_H ROM module that contains the BootROM firmware.

So I would like to ask, where is the bootrom stored, doesn't the s32g3 have on-chip flash, and what is the size of the bootrom? I didn't see it in the attached "S32G3\_memory\_map.xlsx" table

2. Pass control to outside the HSE\_H subsystem,Is it possible to specify M7 or A53?

In a *non-secure boot* , firmware passes control to customer software that runs on a processor core that is outside the HSE\_H subsystem.

3. In RDB3 Schematic,the "SOFT\_RESET" it determines whether some S32G3 pins are connected to BOOT\_RCON or other peripherals. I know that SOFT\_RESET is high after power-on, so that the S32G3 pins are no longer connected to BOOT\_RCON, but I don't know the specific time, such as after the PMIC is stable or other

<!-- image -->

<!-- image -->

Please help answer the above questions,thanks

Solved! [Go to Solution.](https:\community.nxp.com\t5\S32G\s32g-BootRom-amp-reset\m-p\2029196)

**1 Solution**

‎01-16-2025 11:19 AM

1,082 Views

<!-- image -->

<!-- image -->

alejandro\_e

NXP TechSupport

Hello [@jiajun\_cheng](https:\community.nxp.com\t5\user\viewprofilepage\user-id\241854) ,

Here are my answers to your questions:

Q1) When reading the Boot chapter of the s32g3 RM manual, it mentions boot

The HSE\_H core begins executing firmware from the HSE\_H ROM module that contains the BootROM firmware.

So I would like to ask, where is the bootrom stored, doesn't the s32g3 have on-chip flash, and what is the size of the bootrom? I didn't see it in the attached "S32G3\_memory\_map.xlsx" table

A1) The bootROM is stored in the S32G3, the exact details about the implementation of how it is stored, accessed and executed are not publicly available. In any case, it is not configurable or customizable in any way, so you won't have to worry about it.

Q2) Pass control to outside the HSE\_H subsystem, Is it possible to specify M7 or A53?

In a *non-secure boot* , firmware passes control to customer software that runs on a processor core that is outside the HSE\_H subsystem.

A2) Yes it is possible to select M7 or A53, you can learn mor about it in this app note [AN13456 - S32G3 Boot Process](https:\www.nxp.com\docs\en\application-note\AN13456.pdf) , in particular check page 8:

<!-- image -->

You can learn more about the IVT in the reference manual [page 1320, S32G3 Reference Manual, Rev. 4, 02/2024 ]:

<!-- image -->

Q3) In RDB3 Schematic,the "SOFT\_RESET" it determines whether some S32G3 pins are connected to BOOT\_RCON or other peripherals. I know that SOFT\_RESET is high after power-on, so that the S32G3 pins are no longer connected to BOOT\_RCON, but I don't know the specific time, such as after the PMIC is stable or other

A3) as you can see from the schematic, this signals depends on the PMIC's PGOOD signal:

<!-- image -->

the VR5510 releases the reset pin only after all the voltage lines have the correct values, this means that the SOC does not have control over the delay for the reset release [page 15 of the VR5510 datasheet, Rev. 6 — 31 July 2023]:

<!-- image -->

it is also possible to add a delay to this process via an one time programable (OTP) register. [page 177]:

<!-- image -->

Let me know if this fully answers your questions.

[View solution in original post](https:\community.nxp.com\t5\S32G\s32g-BootRom-amp-reset\m-p\2029196)

- [All forum topics](https:\community.nxp.com\t5\S32G\bd-p\S32G\page\216)
- [Previous Topic](https:\community.nxp.com\t5\S32G\Wakeup-from-standby-happens-prematurely-for-S32G3-VNP-RDB3\td-p\2026926)
- [Next Topic](https:\community.nxp.com\t5\S32G\Emulate-S32G399ARDB3-with-QEMU\td-p\2026788)

**1 Reply**

‎01-16-2025 11:19 AM

1,083 Views

<!-- image -->

<!-- image -->

alejandro\_e

NXP TechSupport

Hello [@jiajun\_cheng](https:\community.nxp.com\t5\user\viewprofilepage\user-id\241854) ,

Here are my answers to your questions:

Q1) When reading the Boot chapter of the s32g3 RM manual, it mentions boot

The HSE\_H core begins executing firmware from the HSE\_H ROM module that contains the BootROM firmware.

So I would like to ask, where is the bootrom stored, doesn't the s32g3 have on-chip flash, and what is the size of the bootrom? I didn't see it in the attached "S32G3\_memory\_map.xlsx" table

A1) The bootROM is stored in the S32G3, the exact details about the implementation of how it is stored, accessed and executed are not publicly available. In any case, it is not configurable or customizable in any way, so you won't have to worry about it.

Q2) Pass control to outside the HSE\_H subsystem, Is it possible to specify M7 or A53?

In a *non-secure boot* , firmware passes control to customer software that runs on a processor core that is outside the HSE\_H subsystem.

A2) Yes it is possible to select M7 or A53, you can learn mor about it in this app note [AN13456 - S32G3 Boot Process](https:\www.nxp.com\docs\en\application-note\AN13456.pdf) , in particular check page 8:

<!-- image -->

You can learn more about the IVT in the reference manual [page 1320, S32G3 Reference Manual, Rev. 4, 02/2024 ]:

<!-- image -->

Q3) In RDB3 Schematic,the "SOFT\_RESET" it determines whether some S32G3 pins are connected to BOOT\_RCON or other peripherals. I know that SOFT\_RESET is high after power-on, so that the S32G3 pins are no longer connected to BOOT\_RCON, but I don't know the specific time, such as after the PMIC is stable or other

A3) as you can see from the schematic, this signals depends on the PMIC's PGOOD signal:

<!-- image -->

the VR5510 releases the reset pin only after all the voltage lines have the correct values, this means that the SOC does not have control over the delay for the reset release [page 15 of the VR5510 datasheet, Rev. 6 — 31 July 2023]:

<!-- image -->

it is also possible to add a delay to this process via an one time programable (OTP) register. [page 177]:

<!-- image -->

Let me know if this fully answers your questions.

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