- [**论坛**](https:\community.nxp.com\t5\NXP-Forums\ct-p\NXP-Forums)

- [**知识库**](https:\community.nxp.com\t5\Knowledge-Bases\ct-p\NXP-Knowledge-Base)

- [**观点**](https:\community.nxp.com\t5\Ideas\idb-p\Ideas)

- [**博文**](https:\community.nxp.com\t5\Blogs\bg-p\blog)

- [**NXP.COM**](https:\www.nxp.com)

[**登录**](https:\community.nxp.com\plugins\common\feature\saml\doauth\post?referer=https%3A%2F%2Fcommunity.nxp.com%2Ft5%2FS32G%2FS32g3-ipcf-debugging%2Fm-p%2F1612326) [**帮助**](https:\community.nxp.com\t5\help\faqpage)

语言

- [Home](https:\community.nxp.com)

- [产品论坛](https:\community.nxp.com\t5\Product-Forums\ct-p\Products)

- [S32G](https:\community.nxp.com\t5\S32G\bd-p\S32G)

- S32g3 ipcf debugging

**S32g3 ipcf debugging**

窗体顶端

窗体底端

已解决

[跳至解决方案](https:\community.nxp.com\t5\S32G\S32g3-ipcf-debugging\m-p\1613268)

‎03-09-2023 02:42 AM

5,676 次查看

<!-- image -->

[**Quentin2022**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\203209)

Contributor III

Hi，nxp:

I'm having trouble debugging ipcf. The version compiled using the S32DS can communicate with the A core.

But when I use gcc cgwing build M core sample can't communicate with A core.I have check the code is same with S32DS exsample.also I sure the config for ipcf is no problem.M core init is success but can't get the remote pool data.

I have make test.In M core sample,I write a fixed value at an address in shared memory,the read this address in A core，but I can't get the value write in M core,and vice versa.so i want to ask is there any other configure ?

root@s32g399ardb3:~# echo 10 &gt;/sys/kernel/ipc-shm-sample/ping
root@s32g399ardb3:~# [ 1830.701340] ipc-shm-sample: starting demo...
[ 1830.701351] ipc-shm-sample: ch 0 &gt;&gt; 20 bytes: SENDING MESSAGES: 10

[ 1830.701368] ipc-shm-dev: ipc\_shm\_acquire\_buf(): No free buffer found in channel 1
[ 1830.701372] ipc-shm-sample: send\_data\_msg(): failed to get buffer for channel ID 1 and size 32

The pop ring write read is 0,but in M core sample read is 5, after ipcf\_init().

Thanks.

已解决！ [转到解答。](https:\community.nxp.com\t5\S32G\S32g3-ipcf-debugging\m-p\1613268)

**1 解答**

‎03-10-2023 10:24 AM

5,639 次查看

<!-- image -->

<!-- image -->

[**Daniel-Aguirre**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\205137)

NXP TechSupport

Hi,

Maybe we don't fully understand the scope of your application. We are looking into the Linker file that is provided on the IPCF (non-multi) examples, and we see that the 0x34600000 is being taken by the int\_sram\_c3 declaration, for which might be the problem you are seeing.

Again, might be that we are not understanding the general implementation.

If you modified the linker file as needed, did you change the structures/address on the IPCF application running on the A/M7 core? Given that the sample that is provided assumes no modifications are done to the linker itself, the A/M7 core uses a predefined address on the peripheral itself. Below will be the configuration for the M7 core on the S32G2 implementation:

<!-- image -->

Is this also being modified?

Please, let us know.

[在原帖中查看解决方案](https:\community.nxp.com\t5\S32G\S32g3-ipcf-debugging\m-p\1613268)

- [所有论坛主题](https:\community.nxp.com\t5\S32G\bd-p\S32G\page\63)
- [前一个主题](https:\community.nxp.com\t5\S32G\Clock-drift-among-STM-and-FTM-timers\td-p\1653662)
- [下一个主题](https:\community.nxp.com\t5\S32G\ATF-Build-Parameters-FIP-QSPI-OFFSET\td-p\1653185)

**9 回复数**

‎03-09-2023 11:05 AM

5,663 次查看

<!-- image -->

<!-- image -->

[**Daniel-Aguirre**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\205137)

NXP TechSupport

Hi,

At this moment S32G3 is still under control of distribution, hence we cannot provide much information on the public community. Please, help us either with creating a ticket or sending this inquiry to your local NXP representative/FAE for them to use the appropiate channel.

As for general information for the IPCF, given that the S32DS application is working, we can only recommend to verify the flags that S32DS is using on the compilation and linking steps.

Have you verified with a simpler application? to confirm that using your setup does indeed have the expected outcome.

Please, let us know.

‎03-09-2023 06:41 PM

5,656 次查看

<!-- image -->

[**Quentin2022**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\203209)

Contributor III

Hi Nxp:

My question is why the content written in M core in my shared memory cannot be read by A core, and the content written in A core cannot be read by M core.It looks like you're operating on two separate pieces of memory.The test code looks like this:

In M core after ipcf\_init(), before remote\_is\_ready:

*((uint32 *)0x34100008) = 0xA5A5A5A5

In A core:

before ipcf\_init():

addr = (uint32\_t *)ioremap(0x34100008, 4);

shm\_err("0x341000008:%x\n", *addr); //printk 0

So, for shared memory operations, do we need any configuration on the M core? Want to be shareable or cacheable\_not?

‎03-10-2023 03:21 AM

5,643 次查看

<!-- image -->

[**Quentin2022**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\203209)

Contributor III

Hi

I found that the partitioning of the SharedRAM in the link file caused, once I split the SharedRAM, then the A-core and M-core operations in this segment of memory looked as if they were independent.

I did A test, first use the default link file, partition SharedRAM address is 0x34000000, size 2M, then M core to write 0x34600000 address, in A core read the address out the correct value. Then I changed the partition of SharedRAM in the link file to 0x34600000, the size of 2M, and then read the content of 0x36000000. The A core could not read the value written by the M core.

SharedRAM (RW) : ORIGIN = 0x34000000, LENGTH = 0x00200000 /* 2MB */

So why?Do you have any suggestions

- 标记:
- [ii](https:\community.nxp.com\t5\tag\ii\tg-p\board-id\S32G)

‎03-10-2023 10:24 AM

5,640 次查看

<!-- image -->

<!-- image -->

[**Daniel-Aguirre**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\205137)

NXP TechSupport

Hi,

Maybe we don't fully understand the scope of your application. We are looking into the Linker file that is provided on the IPCF (non-multi) examples, and we see that the 0x34600000 is being taken by the int\_sram\_c3 declaration, for which might be the problem you are seeing.

Again, might be that we are not understanding the general implementation.

If you modified the linker file as needed, did you change the structures/address on the IPCF application running on the A/M7 core? Given that the sample that is provided assumes no modifications are done to the linker itself, the A/M7 core uses a predefined address on the peripheral itself. Below will be the configuration for the M7 core on the S32G2 implementation:

<!-- image -->

Is this also being modified?

Please, let us know.

‎05-16-2023 11:18 PM

5,179 次查看

<!-- image -->

[**fengxianeric**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\217279)

Contributor IV

Could you please paste menu path for the ipcf\_shm\_cfg window for me ? thanks.

‎03-13-2023 03:08 AM

5,601 次查看

<!-- image -->

[**Quentin2022**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\203209)

Contributor III

Hi,

I solved it.

very thanks.

‎03-17-2023 02:51 AM

5,504 次查看

<!-- image -->

[**Vineesha**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\207718)

Contributor I

Hi,

I have trouble in IPCF communication between A53 and M7. I am using s32g hardware.

From this link, i have built the modules manually- git clone [https://source.codeaurora.org/external/autobsps32/ipcf/ipc-shm/](https:\source.codeaurora.org\external\autobsps32\ipcf\ipc-shm)

Copied these ipc-shm-dev.ko, ipc-shm-sample.ko and ipc-shm-uio.ko files to board.

In uboot level, i have executed the below commands, [IPCF\_Example\_S32G274\_M7\_0.bin downloaded from NXP]

=&gt; dcache off
=&gt; mw.q 0x34000000 0x0 0x100000
=&gt; fatload mmc 0:1 0x80000000 IPCF\_Example\_S32G274\_M7\_0.bin
=&gt; cp.q 0x80000000 0x34300000 0x60000
=&gt; startm7 0x34401000
Starting CM7\_0 core at SRAM address 0x34401000 ... done.
=&gt;boot

Board is booted and able to load the modules as shown below:

root@ubuntu-s32g274ateraaceubuntu:/home/bluebox# insmod ipc-shm-dev.ko
root@ubuntu-s32g274ateraaceubuntu:/home/bluebox# insmod  ipc-shm-sample.ko
root@ubuntu-s32g274ateraaceubuntu:/home/bluebox#

While sending the message it is failed:
root@ubuntu-s32g274ateraaceubuntu:/# dmesg -c &gt; /dev/null
root@ubuntu-s32g274ateraaceubuntu:/# echo 10 &gt; /sys/kernel/ipc-shm-sample/ping
root@ubuntu-s32g274ateraaceubuntu:/# [ 2392.119337] ipc-shm-sample: send\_data\_msg(): failed to get buffer for channel ID 1 and size 16 root@ubuntu-s32g274ateraaceubuntu:/# dmesg -c
[ 2392.119301] ipc-shm-sample: starting demo...
[ 2392.119326] ipc-shm-sample: ch 0 &gt;&gt; 20 bytes: SENDING MESSAGES: 10
[ 2392.119337] ipc-shm-sample: send\_data\_msg(): failed to get buffer for channel ID 1 and size 16
root@ubuntu-s32g274ateraaceubuntu:/#

Can you please help me. Thanks in advance.

‎05-16-2023 11:44 PM

5,172 次查看

<!-- image -->

[**fengxianeric**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\217279)

Contributor IV

me too

‎05-22-2023 12:31 AM

5,122 次查看

<!-- image -->

[**fengxianeric**](https:\community.nxp.com\t5\user\viewprofilepage\user-id\217279)

Contributor IV

- Disable Data Cache from uboot::

dcache off

- Zero-set SRAM shared memory used by both sample apps::

mw.q 0x34000000 0x0 0x100000

- Load binaries in DDRAM and after is SRAM::

fatload mmc 0:1 0x80000000 IPCF\_Example\_multi\_instance\_S32G399\_M7\_0.bin

cp.q 0x80000000 0x34100000 0x30000
fatload mmc 0:1 0x80000000 IPCF\_Example\_multi\_instance\_S32G399\_M7\_1.bin

cp.q 0x80000000 0x34200000 0x30000

- Start M7 core (the argument is the address of the Interrupt Vector)::

startm7 0x34181000

- Boot Linux :

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