- [**论坛**](https:\community.nxp.com\t5\NXP-Forums\ct-p\NXP-Forums)

- [**知识库**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**观点**](https:\community.nxp.com\t5\Ideas\idb-p\Ideas)

- [**博文**](https:\community.nxp.com\t5\Blogs\bg-p\blog)

- [**NXP.COM**](https:\www.nxp.com)

[**登录**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32G%2FSAF-eMCEM-Normal-Operation-Faults-S32G3%2Fm-p%2F2114114) [**帮助**](https:\community.nxp.com\t5\help\faqpage)

语言

- [Home](https:\community.nxp.com)

- [产品论坛](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32G](https:\community.nxp.com\t5\S32G\bd-p\S32G)

- SAF eMCEM - Normal Operation Faults - S32G3

**SAF eMCEM - Normal Operation Faults - S32G3**

窗体顶端

窗体底端

‎06-10-2025 09:30 PM

379 次查看

<!-- image -->

[**SHIVRAJ**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\251448)

Contributor II

Hello team!

I'm currently working on integrating SAF into BSW. While referring the eMCEM Safety Manual, there are 300+ S32G3 Faults listed.

1) Wanted to know if we are supposed to handle all of them?

2) If we can shortlist them, on what basis has it to be done?

3) On what basis do we forward them to either the Alarm Handler or the NMI Handler?

I'd really appreciate if anyone could help me out.
Thank you!

- 标记:
- [S32G3 SAF eMCEM](https:\community.nxp.com\t5\tag\S32G3%20SAF%20eMCEM\tg-p\board-id\S32G)
- [所有论坛主题](https:\community.nxp.com\t5\S32G\bd-p\S32G\page\249)
- [前一个主题](https:\community.nxp.com\t5\S32G\Read-FCCU-faults-S32G3\td-p\2113633)
- [下一个主题](https:\community.nxp.com\t5\S32G\How-to-config-the-Default-Fault-Reaction-and-Reaction-type-of\td-p\2113116)

**1 回复**

‎06-11-2025 08:00 PM

348 次查看

<!-- image -->

<!-- image -->

chenyin\_h

NXP Employee

Hello, [@SHIVRAJ](https:\community.nxp.com\t5\user\viewprofilepage\user-id\251448)

Thanks for your post.

1. The fault tables you mentioned present the FCCU fault symbolic names and their mapping to the NCFs of the S32G devices. It also contains the EIM channels. These EIM defines are valid for fault injection, which are not for fault reporting, so these EMCEM\_FCCU* faults need to be handled.

2. FCCU can be configured to enter Alarm state when a fault is detected. In Alarm state, eMCEM module identifies which fault source or sources are active and calls a fault handler registered by the user for that source or sources. When the fault handler does not recover the fault before the alarm timeout interval expires, or when no fault handler is available, FCCU enters Fault State and generates a non-maskable interrupt. eMCEM module handles this interrupt and call Software Recovery (sReco) component in S32 SAF to records the fault information and issues a software functional reset.

BR

Chenyin

<!-- image -->

- [**关于恩智浦**](https:\www.nxp.com.cn\company\about-nxp:ABOUT-NXP)
- [**人才招聘**](https:\www.nxp.com.cn\company\about-nxp\careers:CAREERS)
- [**投资者**](https:\www.nxp.com.cn\company\about-nxp\investor-relations:INVESTOR-RELATIONS)
- [**新闻和博客**](https:\www.nxp.com.cn\company\about-nxp\newsroom:NEWSROOM)
- [**联系**](https:\www.nxp.com.cn\company\about-nxp\contact-us:CONTACTUS)
- [**我的恩智浦账号优势**](https:\www.nxp.com\support\my-nxp-account-benefits:NXP-ACCOUNT-BENEFITS)
- [隐私政策](https:\www.nxp.com.cn\about\privacy:PRIVACYPRACTICES)
- [使用条款](https:\www.nxp.com.cn\about\terms-of-use:TERMSOFUSE)
- [销售条款](https:\www.nxp.com.cn\company\about-nxp\our-terms-and-conditions-of-commercial-sale:TERMSCONDITIONSSALE)
- [关于禁止贩卖和奴役人口的声明](https:\www.nxp.com.cn\company\about-nxp\sustainability\social-responsibility\labor-and-human-rights:LABOR-AND-HUMAN-RIGHTS)
- [辅助功能](https:\www.nxp.com.cn\company\our-company\about-nxp\accessibility:ACCESSIBILITY)
- [Website Feedback](https:\www.nxp.com\products\website-feedback:WEBSITE-FEEDBACK)

©2006-2026 NXP Semiconductors. All rights reserved.