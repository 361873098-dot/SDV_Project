- [**论坛**](https:\community.nxp.com\t5\NXP-Forums\ct-p\NXP-Forums)

- [**知识库**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**观点**](https:\community.nxp.com\t5\Ideas\idb-p\Ideas)

- [**博文**](https:\community.nxp.com\t5\Blogs\bg-p\blog)

- [**NXP.COM**](https:\www.nxp.com)

[**登录**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32G%2FHow-to-config-the-Default-Fault-Reaction-and-Reaction-type-of%2Fm-p%2F2113116) [**帮助**](https:\community.nxp.com\t5\help\faqpage)

语言

- [Home](https:\community.nxp.com)

- [产品论坛](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32G](https:\community.nxp.com\t5\S32G\bd-p\S32G)

- How to config the Default Fault Reaction and Reaction type of S32G FCCU
## How to config the Default Fault Reaction and Reaction type of S32G FCCU
窗体顶端
窗体底端
已解决
[跳至解决方案](https:\community.nxp.com\t5\S32G\How-to-config-the-Default-Fault-Reaction-and-Reaction-type-of\m-p\2113873)
‎06-09-2025 06:32 PM
697 次查看
<!-- image -->
[**RAYL\_LAMS**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\228967)
Contributor II
Hi，
For the S32G RM, I found the section:
28.5.3.1 FCCU reset reaction
The FCCU reset reaction reset is asserted by the FCCU when a fault is detected by the FCCU and the fault is configured to
generate a soft reaction.
The FCCU reset reaction reset is deasserted automatically by the FCCU after assertion and immediately on destructive reset and
POR sequence entries.
Software can determine which fault caused the FCCU reset reaction by reading a status register in the FCCU.
My question is how to configure the Default Fault Reaction and  Reaction type by register:
    1. Set "Enable" and "Disable" for NCF channels
    2. Set "ShortResetReaction" and "NoResetReaction" for NCF channels
I found the register list:
    1. Non-critical Fault Configuration
    2. Non-critical Fault-State Configuration
    3. Non-critical Fault Enable
Which Register Table I can use for config the FCCU?
Thanks for your great help~~~
[S32G2](https:\community.nxp.com\t5\c-pwmxy87654\S32G2\pd-p\S32G2)已解决！ [转到解答。](https:\community.nxp.com\t5\S32G\How-to-config-the-Default-Fault-Reaction-and-Reaction-type-of\m-p\2113873)
    - 标记:
    - [hi](https:\community.nxp.com\t5\tag\hi\tg-p\board-id\S32G)
    - [S32G FCCU](https:\community.nxp.com\t5\tag\S32G%20FCCU\tg-p\board-id\S32G)
**1 解答**
‎06-10-2025 01:55 PM
654 次查看
<!-- image -->
<!-- image -->
carlos\_o
NXP TechSupportHi [@RAYL\_LAMS](https:\community.nxp.com\t5\user\viewprofilepage\user-id\228967) ,
The register to configure the FCCU are listed at the chapter 67.7.1 FCCU register descriptions.
To set Enable, disable any NCF change the 67.7.1.6 Non-critical Fault-State Configuration (NCFS\_CFG0 - NCFS\_CFG7)
<!-- image -->
<!-- image -->
You need to enable the non-critical faults at the register 67.7.1.9 Non-critical Fault Enable (NCF\_E0 - NCF\_E3)
<!-- image -->
<!-- image -->
Also, the NCF list is available attached to the S32G Reference Manual, open it with acrobat reader to see the attached files and see the S32G2\_Fault\_Map.xlsx
[在原帖中查看解决方案](https:\community.nxp.com\t5\S32G\How-to-config-the-Default-Fault-Reaction-and-Reaction-type-of\m-p\2113873)
    - [所有论坛主题](https:\community.nxp.com\t5\S32G\bd-p\S32G\page\249)
    - [前一个主题](https:\community.nxp.com\t5\S32G\SAF-eMCEM-Normal-Operation-Faults-S32G3\td-p\2114114)
    - [下一个主题](https:\community.nxp.com\t5\S32G\How-does-an-A-core-application-compiled-with-s32g274\td-p\2112835)
**2 回复数**
‎06-10-2025 01:55 PM
655 次查看
<!-- image -->
<!-- image -->
carlos\_o
NXP TechSupportHi [@RAYL\_LAMS](https:\community.nxp.com\t5\user\viewprofilepage\user-id\228967) ,
The register to configure the FCCU are listed at the chapter 67.7.1 FCCU register descriptions.
To set Enable, disable any NCF change the 67.7.1.6 Non-critical Fault-State Configuration (NCFS\_CFG0 - NCFS\_CFG7)
<!-- image -->
<!-- image -->
You need to enable the non-critical faults at the register 67.7.1.9 Non-critical Fault Enable (NCF\_E0 - NCF\_E3)
<!-- image -->
<!-- image -->
Also, the NCF list is available attached to the S32G Reference Manual, open it with acrobat reader to see the attached files and see the S32G2\_Fault\_Map.xlsx
‎06-11-2025 06:21 PM
630 次查看
<!-- image -->
[**RAYL\_LAMS**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\228967)
Contributor II
Thanks~ Sloved my questions.
<!-- image -->
    - [**关于恩智浦**](https:\www.nxp.com.cn\company\about-nxp:ABOUT-NXP)
    - [**人才招聘**](https:\www.nxp.com.cn\company\about-nxp\careers:CAREERS)
    - [**投资者**](https:\www.nxp.com.cn\company\about-nxp\investor-relations:INVESTOR-RELATIONS)
    - [**新闻和博客**](https:\www.nxp.com.cn\company\about-nxp\newsroom:NEWSROOM)
    - [**联系**](https:\www.nxp.com.cn\company\about-nxp\contact-us:CONTACTUS)
    - [**我的恩智浦账号优势**](https:\www.nxp.com\support\my-nxp-account-benefits:NXP-ACCOUNT-BENEFITS)
    <!-- image -->
    - [沪公网安备 31010602004586 号](http:\www.beian.gov.cn\portal\registerSystemInfo?recordcode=31010602004586)
    - [沪ICP备18047220号](https:\beian.miit.gov.cn)
    - [隐私政策](https:\www.nxp.com.cn\about\privacy:PRIVACYPRACTICES)
    - [使用条款](https:\www.nxp.com.cn\about\terms-of-use:TERMSOFUSE)
    - [销售条款](https:\www.nxp.com.cn\company\about-nxp\our-terms-and-conditions-of-commercial-sale:TERMSCONDITIONSSALE)
    - [关于禁止贩卖和奴役人口的声明](https:\www.nxp.com.cn\company\about-nxp\sustainability\social-responsibility\labor-and-human-rights:LABOR-AND-HUMAN-RIGHTS)
    - [辅助功能](https:\www.nxp.com.cn\company\our-company\about-nxp\accessibility:ACCESSIBILITY)
    - [Website Feedback](https:\www.nxp.com\products\website-feedback:WEBSITE-FEEDBACK)
©2006-2026 NXP Semiconductors. All rights reserved.