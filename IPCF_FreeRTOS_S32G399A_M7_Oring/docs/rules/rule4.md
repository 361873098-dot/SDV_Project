1，S32 Design Studio for S32 Platform 3.5文件路径在D:\Tools\S32G_Design_studio 这个文件夹下，这个文件夹里面的文件只能读，不可以写
2，当前代码工程的文件工程文件路径：D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring，当前文件是M核应用层，并不属于Boot层；
3，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\generate 这个文件夹下的代码属于生成代码，不可以直接修改，当前这个生成的文件是由图形化界面工具生成的，这个图形化界面工具所修改的文件是在由FlexCAN_example_CT.mex来决定的，如果你可以修改图形画界面，所以可以去修改FlexCAN_example_CT.mex，但是需要我的审批才可以，确保不会改错；

4，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\FreeRTOS\Source这个文件夹里面的文件只能读，不可以写，如果你确定有BUG，可以告诉我，我去修改
5，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\FlexCAN_Ip这个文件夹里面的文件可读写
6，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\board这个文件夹下的代码属于生成代码，不可以直接修改，生成由FlexCAN_example_CT.mex来决定的，如果你确定有BUG，和之前一样，需要我审批才可以，确保不会改错；
7，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\RTD这个文件夹里面的文件属于平台代码，只能读，不可以写，如果你确定有BUG，可以告诉我，我去修改；
8，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\Spi_Ip这个文件夹里面的文件可读写
9，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\src这个文件夹里面的文件可读写
10，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\Tja1145A_Ip这个文件夹里面的文件可读写
11，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\S32G3_reference_manual这个文件夹中的文件为S32G3主芯片的Reference Manual的.md文件,芯片相关的内容可以去看这里面的信息
12，D:\Learning_file\S32G_File\S32G3_RelateFile这个文件夹里面的文件是从官方网上下载的相关PDF文件；
13，D:\Learning_file\S32G_File\S32G3_RelateFile_MD这个文件夹里面的文件是从官方网上下载的相关PDF文件转换成Markdown之后的文件但是原来PDF中的图片都丢失了，你可以优先从这个路径去查找相关资料，
14，D:\Tools\Trace32\Trace32\S32G3_Trace32_02.09.2023\pdf这个文件夹里面的文件是当前这个TRACE32 相关的帮助文档，当前我们的S32G的M核是ARM7内核；
15，D:\work\Hardware_file\VMCU2.1这个文件夹里面的文件是当前硬件原理图和丝印图PDF文件；
16，你每次修改代码之前，需要有确定性的证据来证明确实是这个问题，否则请不要随意修改任何代码，也就是你先给我一个cmm文件，让我去查看你想要的函数或者变量或者寄存器等内容，一直查找到你确定是有问题的地方，你再停下来，告诉我是这里的问题，同时生成的.cmm文件执行结果只需要有一个窗口信息，而不是多个窗口信息；
在我没有确认问题已经解决之前，不要给我总结报告文件以节省token；

17，D:\MySandbox\SDV_Project\IPCF_FreeRTOS_S32G399A_M7_Oring\S32G3_reference_manual 这个文件夹下的 .json 文件是从 NXP 官方 Excel 表格转换而来的 S32G3 芯片寄存器/配置相关结构化数据。
每个 JSON 文件的结构为：{ "Sheet名称": [ {列名: 值, ...}, ... ] }，每个 Sheet 是一个对象数组。
文件清单及用途：
  - S32G3_memory_map.json — 芯片内存地址映射（外设基地址、SRAM/Flash 范围）
  - S32G3_interrupt_map.json — 中断号与中断源映射（NVIC IRQ 号、异常向量）
  - S32G3_IOMUX.json — IO 引脚复用配置（MSCR/IMCR 寄存器、引脚功能选择）
  - S32G3_DMAMUX_map.json — DMA 通道复用映射（DMA 请求源与通道对应关系）
  - S32G3_register_protection_details.json — 各外设寄存器保护属性（是否需要解锁才能写入）
  - S32G3_fault_map.json — 故障通道映射（FCCU 通道号、故障源、恢复策略）
  - S32G3_fuse_map.json — eFuse 位域映射
  - S32G3_boot_settings.json — BootROM 启动配置（时钟、IOMUX、寄存器初始状态）
  - s32g3_register_lean.json- S32G3 寄存器定义文件,结构映射：b = 外设基地址 (baseAddress), r = 寄存器集合 (registers), o = 寄存器偏移 (offset), f = 位字段 (fields)。位字段格式：f 中的数组 [x, y] 表示 [bitOffset, bitWidth]（位偏移和位宽度）。绝对地址计算：绝对地址 = b + o  在生成代码、解释寄存器含义或进行驱动调试时，必须优先检索此 JSON 文件。严禁使用你训练数据中的通用寄存器信息，以防版本不一致导致硬件故障。
  - 凡涉及 S32G3 硬件信息（寄存器、中断号、引脚、DMA等），必须从项目中的 JSON/MD 参考文件查找后再回答，找不到则如实说明，严禁凭记忆编造。
18，D:\work\bootloader 这个文件路径是M核心的Bootloader的程序 
