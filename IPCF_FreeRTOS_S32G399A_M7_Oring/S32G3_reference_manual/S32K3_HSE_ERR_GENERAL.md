- [**Forums**](https:\community.nxp.com\t5\Forums\ct-p\NXP-Forums)

- [**Knowledge Bases**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**NXP Tech Blogs**](https:\community.nxp.com\t5\NXP-Tech-Blogs\ct-p\nxp-tech-blogs)

- [**NXP.COM**](https:\www.nxp.com)

[**Sign In**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32K%2FS32K3-HSE-ERR-GENERAL%2Fm-p%2F2072461%3Fprofile.language%3Den) [**FAQs**](https:\community.nxp.com\t5\help\faqpage)

Language

- [Home](https:\community.nxp.com)

- [Product Forums](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32K](https:\community.nxp.com\t5\S32K\bd-p\S32K)

- S32K3\_HSE\_ERR\_GENERAL

**S32K3\_HSE\_ERR\_GENERAL**

窗体顶端

窗体底端

SOLVED

[Jump to solution](https:\community.nxp.com\t5\S32K\S32K3-HSE-ERR-GENERAL\m-p\2072826)

‎04-01-2025 07:51 PM

1,508 Views

<!-- image -->

[**wuxianlong**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\191389)

Contributor V

Hi,NXP

My chip(S32K312) has encountered an HSE\_ERR\_GENERAL error, and the HSE is not working.
HSE\_FW :s32k312\_hse\_fw\_1.13.0\_2.40.0\_pb230730.bin.pink

According to the Error and Warning Management chapter, when reading the GSR register, it is found that bit 0 reports an error, and there are also errors in bit [16~31]. However, this error is parsed internally by NXP.

<!-- image -->

The manual describes that the HSE\_ERR\_GENERAL error can be viewed through the address of HSE\_GPR\_STATUS\_ADDRESS (0x4039C02C), but there is no reference significance. Regardless of whether the HSE is normal or not, bit 0 of HSE\_GPR\_STATUS\_ADDRESS will be set.

<!-- image -->

How should I analyze the problem now? How can I restore my HSE? I tried POR and performing W1C on the GSR register, but both were ineffective.


Best Regards,
xianlong

Solved! [Go to Solution.](https:\community.nxp.com\t5\S32K\S32K3-HSE-ERR-GENERAL\m-p\2072826)

**1 Solution**

‎04-02-2025 04:28 AM

1,477 Views

<!-- image -->

<!-- image -->

lukaszadrapa

NXP TechSupport

Hi [@wuxianlong](https:\community.nxp.com\t5\user\viewprofilepage\user-id\191389)

Generally, first step is to check HSE GPR at 0x4039\_C028 if bit 0 is set. If bit 0 is ‘0’ after reset, HSE firmware is not present at all, it is erased completely by SBAF due to fatal error.

If the bit 0 in HSE GPR is ‘1’ (HSE FW present) but HSE\_STATUS\_INIT\_OK remains ‘0’ after reset, it means that the firmware is present but it did not start. It’s necessary to start the handshake procedure.

Updated version of HSE Firmware Reference Manual was released recently (version 2.4). It’s slightly updated and clarified in comparison with v2.3.

Take a look at section:

14.6.7  HSE Firmware Handshake

And also at new section:

9.3.2  General use

It depends on HSE and SBAF version how many resets are needed. But even if you have newer versions, more resets can still be needed.

We don’t have sample code for handshake but it should be as simple as this: if HSE GPR bit 0 is ‘1’ (i.e. the firmware is present) but the HSE\_STATUS\_INIT\_OK does not get set, trigger functional reset. SBAF will do the counting of resets/attempts for you, SBAF will restore the firmware from backup if possible or SBAF will erase the firmware completely. Just keep checking the condition above after each reset and keep triggering the functional resets. Once the HSE\_STATUS\_INIT\_OK gets set to ‘1’, it was successful and you can use HSE again. Once the bit 0 in HSE GPR is cleared to ‘0’, it means it was not possible to recover and user is required to install the HSE FW again.

If HSE\_STATUS\_INIT\_OK is set, there’s an option to run HSE\_SRV\_ID\_FW\_INTEGRITY\_CHECK service which checks the integrity of HSE FW and SYS-IMG.

As described in “10.2.2.4 Code Flash Firmware Integrity Check” in HSE FW RM, it’s highly recommended to run this service after each reset.

If general error is not set right after reset, it's caused by some HSE service which was triggered by your application. Such error usually happens when HSE does not have access to some memory - for example, when you provide wrong pointer to input parameters, when there's double bit ECC error or when HSE does not have access right to that memory due to XRDC settings. In this case, just try to find which service caused the error and check all the parameters of that service.

Regards,

Lukas

[View solution in original post](https:\community.nxp.com\t5\S32K\S32K3-HSE-ERR-GENERAL\m-p\2072826)

- [All forum topics](https:\community.nxp.com\t5\S32K\bd-p\S32K\page\1074)
- [Previous Topic](https:\community.nxp.com\t5\S32K\FlexCAN-through-DMA-for-S32K322\td-p\2069218)
- [Next Topic](https:\community.nxp.com\t5\S32K\S32K344-development-board-JTAG-connection\td-p\2072630)

**5 Replies**

‎04-01-2025 08:53 PM

1,487 Views

<!-- image -->

[**wuxianlong**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\191389)

Contributor V

<!-- image -->

Hi, NXP

I tried to restore in MU mode. But it did not take effect. After writing 0xA5 and resetting, the Sbaf flag will not be set to 1 and there is no data in MU\_RR.（0x4038c280）

Best Regards,
xianlong

‎04-02-2025 04:28 AM

1,478 Views

<!-- image -->

<!-- image -->

lukaszadrapa

NXP TechSupport

Hi [@wuxianlong](https:\community.nxp.com\t5\user\viewprofilepage\user-id\191389)

Generally, first step is to check HSE GPR at 0x4039\_C028 if bit 0 is set. If bit 0 is ‘0’ after reset, HSE firmware is not present at all, it is erased completely by SBAF due to fatal error.

If the bit 0 in HSE GPR is ‘1’ (HSE FW present) but HSE\_STATUS\_INIT\_OK remains ‘0’ after reset, it means that the firmware is present but it did not start. It’s necessary to start the handshake procedure.

Updated version of HSE Firmware Reference Manual was released recently (version 2.4). It’s slightly updated and clarified in comparison with v2.3.

Take a look at section:

14.6.7  HSE Firmware Handshake

And also at new section:

9.3.2  General use

It depends on HSE and SBAF version how many resets are needed. But even if you have newer versions, more resets can still be needed.

We don’t have sample code for handshake but it should be as simple as this: if HSE GPR bit 0 is ‘1’ (i.e. the firmware is present) but the HSE\_STATUS\_INIT\_OK does not get set, trigger functional reset. SBAF will do the counting of resets/attempts for you, SBAF will restore the firmware from backup if possible or SBAF will erase the firmware completely. Just keep checking the condition above after each reset and keep triggering the functional resets. Once the HSE\_STATUS\_INIT\_OK gets set to ‘1’, it was successful and you can use HSE again. Once the bit 0 in HSE GPR is cleared to ‘0’, it means it was not possible to recover and user is required to install the HSE FW again.

If HSE\_STATUS\_INIT\_OK is set, there’s an option to run HSE\_SRV\_ID\_FW\_INTEGRITY\_CHECK service which checks the integrity of HSE FW and SYS-IMG.

As described in “10.2.2.4 Code Flash Firmware Integrity Check” in HSE FW RM, it’s highly recommended to run this service after each reset.

If general error is not set right after reset, it's caused by some HSE service which was triggered by your application. Such error usually happens when HSE does not have access to some memory - for example, when you provide wrong pointer to input parameters, when there's double bit ECC error or when HSE does not have access right to that memory due to XRDC settings. In this case, just try to find which service caused the error and check all the parameters of that service.

Regards,

Lukas

‎04-02-2025 05:17 AM

1,459 Views

<!-- image -->

[**wuxianlong**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\191389)

Contributor V

Hi, [@lukaszadrapa](https:\community.nxp.com\t5\user\viewprofilepage\user-id\37795) Thank you very much for your information.
I see in the manual that the HSE will judge the EER bit of the MCRS of FLASH. So I enabled PFCR4[DERR\_SUP]. Then, after multiple resets, the HSE returned to normal. I don't have other chips to test whether only a reset is needed.

At present, can I understand it this way? The HSE has implemented abnormal recovery measures to prevent the HSE in the chip from hanging. For example, the ECC error of the HSE this time, or even other more serious exceptions.

We just need to perform multiple resets simply. If the exception can be recovered, the HSE can be restored. If it cannot be recovered, the HSE will also be completely erased, allowing us to reinstall it through MU.

Best Regards,
xianlong

‎04-02-2025 04:31 AM

1,475 Views

<!-- image -->

<!-- image -->

lukaszadrapa

NXP TechSupport

... and what is your HSE\_CLK? If it is configured to 120MHz, it's necessary to update MISC DCF record in UTEST. Try to set 60MHz to see if it makes a difference (no change in DCF is needed when 60MHz is used).

‎04-01-2025 08:33 PM

1,493 Views

<!-- image -->

[**wuxianlong**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\191389)

Contributor V

<!-- image -->

Hi, 

Add a piece of information: FLASH generated an ECC error.


Best Regards,
xianlong

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