---
trigger: always_on
---

当前项目只能修改这个文件夹里面的内容 C:\Users\WeiZhichun\workspaceS32DS.3.5\IPCF_FreeRTOS_S32G399A_M7_0\src
且需要保证不能有语法错误，不能出现数组溢出等 BUG；当前只需要实现 M 核的代码功能；

1.0 引言 (Introduction)
在现代汽车电子电气架构中，多核异构系统已成为实现复杂功能的基石。为了确保不同核心（如应用处理器与微控制器）之间的高效、可靠协作，一个健壮的跨核通信子系统至关重要。本软件需求规范 (SRS) 旨在为该子系统的设计、实现与验证提供一份全面、权威的指导性文件。本文档将详细阐述其架构、通信协议、功能需求以及应用程序接口 (API)，确保开发与质量保证团队对系统有统一且明确的理解。
1.1 文档目的 (Purpose)
本文档旨在将所有相关的设计笔记与需求清单整合为一份单一、权威的软件需求规范。其主要目的在于为软件开发团队和质量保证 (QA) 团队提供关于跨核通信组件的明确技术要求，内容涵盖系统架构、通信协议、服务模型以及应用程序接口 (API)，作为后续开发、测试和验收工作的核心依据。
1.2 系统范围 (Scope)
本规范定义的跨核通信子系统，其范围是管理多核异构环境中 A 核 (Application Core) 与 M 核 (Microcontroller Core) 之间的数据交换。根据需求 [R1]，该子系统必须支持通过以太网 (ETH)、共享内存 (IPCF) 和本地套接字 (Local Socket) 三种传输介质，并采用面向服务的架构 (SOA) 通信语义进行数据传输。当前 A sample, M 核只需要实现 IPCF;
1.3 术语与缩略语 (Definitions, Acronyms, and Abbreviations)
术语/缩略语 完整名称/定义
SOA 面向服务的架构 (Service-Oriented Architecture)，一种软件设计范式，将应用程序的不同功能单元（称为服务）通过定义良好的接口和契约联系起来。
ETH 以太网 (Ethernet)，一种计算机局域网技术。在本规范中特指基于 UDP 协议的通信通道。
IPCF 共享内存 (Shared Memory)，一种用于多核处理器内部高效通信的机制。
PICC Daemon A 核上的跨核通信守护进程 (Process)，负责管理 A 核应用与 M 核之间的通信链路和数据路由。
A 核 (A-Core) 应用核 (Application Core)，通常指运行复杂操作系统（如 Linux）的高性能处理器，用于处理非实时、高算力的应用。
M 核 (M-Core) 微控制器核 (Microcontroller Core)，通常指运行实时操作系统 (RTOS) 或裸机程序的处理器，用于处理高实时性、高可靠性的控制任务。
SOME/IP Scalable service-Oriented Middleware over IP，一种用于汽车领域的通信中间件解决方案。在本规范中，其概念（如 RR, FF）被用作 Method 服务类型的类比。
本规范接下来的章节将深入探讨系统的总体架构设计。

---

2.0 总体描述 (Overall Description)
本子系统的核心设计理念是构建一个兼具灵活性与可靠性的通信框架。它通过支持多种物理传输层并抽象出标准化的面向服务模型，旨在将上层应用与底层硬件和通信介质解耦。这种设计不仅简化了应用程序的开发，还为未来系统扩展和功能迭代奠定了坚实的基础。
2.1 系统架构与核心 (System Architecture and Cores)
系统架构被定义为一个多核异构环境。根据需求 [R1]，本通信组件的核心职责是作为桥梁，实现 A 核与 M 核之间的数据安全、高效传输。
2.2 通信模型 (Communication Model)
系统采用经典的客户端-服务端 (Client-Server) 通信模型。根据需求 [R2]，该模型必须遵循以下约束：
? 一对多服务能力：一个服务端 (Server) 必须能够支持与多个客户端 (Client) 同时进行通信。
? 单一服务依赖：一个客户端 (Client) 在任何时候只能与一个服务端建立通信。
2.3 支持的传输介质 (Supported Transport Media)
依据需求 [R1]，通信子系统必须无缝支持以下三种传输介质，以适应不同的通信场景：
? 以太网 (Ethernet): 用于核间或跨芯片的长距离、高带宽通信。其传输层协议 必须 采用 UDP。
? 共享内存 (IPCF): 用于同一芯片上 A 核与 M 核之间的高速、低延迟通信。
? 本地套接字 (Local Socket): 用于同一操作系统内核内的进程间通信 (IPC)，例如 A 核上的两个应用程序（App3 和 App4）之间的通信。
接下来，本规范将详细定义基于此架构的各项功能需求。

---

数据包格式说明
• 第一字节是 CRC 使能位，0 代表使能，1 代表非使能 ,程序默认为使能，可通过配置修改；
• 后面是 N 个私有协议数据包 ，例如：第一个字节是 Provider id；
• 之后是 2 字节的 counter，每个 IPCF 通道上独立累计计算

最后 2 字节是 CRC,计算前面所有数据的 CRC16

3.0 功能需求 (Functional Requirements)
本章节详细阐述了跨核通信组件必须实现的具体功能。这些需求定义了系统行为的“什么”(what)，涵盖了从服务类型、连接管理到数据完整性保障的各个方面，为后续的设计与实现提供了明确的指引。
3.1 SOA 服务实现 (SOA Service Implementation)
3.1.1 Event 服务 (Event Service)
根据需求 [R3]，Event 服务是一种从服务端到客户端的单向通知机制。系统必须实现以下两种模式：
? 无确认通知 (NOTIFICATION_WITHOUT_ACK, 0x09):
o 这是一种“即发即忘”(Fire-and-Forget)机制。服务端发送 Event 后，不期望客户端返回任何确认信息。
o 约束: 当 M 核作为服务端发送 Event 时，M 核因不支持同步处理，在业务逻辑上仅支持“无确认”发送模式；即便协议层启用了“有确认”模式，M 核也会忽略客户端回传的 ACK 信号而不会进行任何逻辑处理。
([R5])。
? 带确认通知 (NOTIFICATION_WITH_ACK, 0x08):
o 服务端发送 Event 后，客户端的通信组件 必须 自动回复一个 EVENT_ACK (0x82) 报文，以确认消息已接收。
o A 核客户端处理: 对于运行在 A 核上的客户端应用，此 ACK 由 PICC Daemon 在后台透明处理，应用层无需干预。
o M 核客户端处理: 对于 M 核客户端，是否需要回复 ACK 取决于具体业务场景对可靠性的要求。对于关键消息，应配置为回复 ACK ([R3])。
3.1.2 Method 服务 (Method Service)
根据需求 [R4]，Method 服务允许客户端向服务端发起方法调用请求。系统必须支持以下三种类型：
类型 SOME/IP 类比 客户端行为 服务端行为 关键特性
Method With Response (REQUEST, 0x05) RR (Request-Response) 发送请求 (Request) 回复业务响应 (Response) 客户端阻塞等待，直到收到服务端的业务处理结果。
Method Without Response Without Ack (REQUEST_NO_RETURN_WITHOUT_ACK, 0x07) FF (Fire and Forget) 发送请求 (Request) 不返回任何报文 客户端发送后立即返回，不关心服务端的接收或处理状态。
Method Without Response With Ack (REQUEST_NO_RETURN_WITH_ACK, 0x06) N/A 发送请求 (Request) 通信中间件回复确认 (ACK) 客户端阻塞等待，直到收到服务端中间件的接收确认，但不返回业务结果。
3.2 连接与链路管理 (Connection and Link Management)
根据需求 [R5]，系统必须实现一套健壮的链路管理生命周期，包括连接、断开和异常重连。

1. 连接握手 (Connection Handshake):
   o 客户端在启动后，必须 主动、周期性地向服务端发送连接请求报文。此过程将持续进行，直到收到服务端的连接确认应答。
   o 服务端在启动后处于被动监听状态，不会主动发起连接。此处 M 核是否处于服务端或者客户端由应用层决定，例如 M 核有多个 SWC1,SWC,SWC3 分别可能是 client,sever,client;
2. 断开机制 (Disconnection Mechanism):
   A 核 APP 退出后，核间通信 Daemon 会识别到，然后向 M 核发送断开连接请求报文。M 核会回复断开应答报文。之后 A 核开始周期发送连接请求报文。（M 核目前没有主动断开的场景）。
   问题：断开重连机制，A 核发来断开连接通知的时候，M 核应用层在接到断开通知后需要执行的操作，（是否需要释放资源，释放需要等待 A 核重新发起连接）
   回答：CLIENT 会一直重发请求，所以可以释放资源；
3. A 核 Server 重启处理 (A-Core Server Restart Handling):
   为了解决 A 核 Daemon 崩溃的 bug，在 A 核 Daemon 崩溃重启后，A 核 Server 会发送重连通知，M 核 Client 收到后会重新发起连接请求报文
   Log 举例
   A 核是 server，provider id：0x56
   M 核是 client，consumer id：0x4D
   • A 核 server 未启动时，M 核以 10ms 周期一直发送 link 请求。  
   报文说明：A 核 server 未启动时，M 核以 10ms 周期一直发送 link 请求
   前 8 字节是协议 header，之后是 payload，具体字段含义参照 2 章节
   56 00 4D 00 00 01 00 05 01 xx xx xx xx（xx 扩展字段）

A 核 server 启动后，回复 link 应答报文。之后两端可以通信。server 开始发送 event 报文或者 client 开始发送 method 请求报文。
报文说明：A 核 server 启动后，回复 link 应答报文；
56 00 4D 00 00 00 00 05 0x01 xx xx xx xx （xx 扩展字段）
A 核 server 退出后，A 核核间通信会识别到，A 核会向 M 核发送断开连接报文。
报文说明：A 核发送断开连接报文；
56 00 4D 00 00 01 00 01 02  
报文说明：M 核回复断开连接应答报文
56 00 4D 00 00 00 00 05 02 xx xx xx xx（xx 扩展字段）
（xx 扩展字段表示的是客户端 ID,通信介质类型，服务端 ID，通信介质信息，对对通信无影响，当前无具体意义）

3.3 心跳健康监测 (Heartbeat Health Monitoring)
根据需求 [R6]，为确保通信链路的持续可用性，必须实现心跳健康监测机制。
? 机制: A 核与 M 核的通信组件之间采用双向的 Ping/Pong 报文机制进行健康探测。
? 周期: 在每个已建立的通信通道上，心跳报文 必须 以 2 秒 的固定周期双向发送。
? 失效条件: 如果任何一端连续 3 次 未能收到对端的 Pong 回复，则应判定该通信介质发生故障。通信组件必须将此断开事件通知给上层应用。心跳功能和 Client ，Server 无关；当出现心跳超时的时候，需要尝试重连，并把故障信息上报给应用层
? 报文格式: 心跳报文为特殊格式，不遵循标准协议头。
o Ping 报文: ff 00 ff 00 ff 00 00 01 00
o Pong 报文: ff 00 ff 00 ff 00 00 01 01
3.4 数据传输优化 (Data Transfer Optimization)
根据需求 [R7]，为降低接口调用频率并提升传输效率，必须实现消息堆叠发送机制。
? ETH 通道堆叠规则: 数据发送由以下任一条件触发：

1. 距离上次发送已达到 10ms 的时间周期。
2. 堆叠的消息总大小（包含协议头）已接近以太网的 MTU (最大传输单元)。
   ? IPCF 通道堆叠规则: 数据发送由以下任一条件触发：
3. 距离上次发送已达到 10ms 的时间周期。
4. 堆叠的消息总大小（包含协议头）已接近 IPCF 驱动程序配置的最大缓冲区大小。
   3.5 数据完整性保障 (Data Integrity Assurance)
   根据需求 [R8]，在通过 ETH 和 IPCF 通道发送任何堆叠消息之前，必须执行以下数据完整性保障措施：
5. 全局发送计数器 (Global Send Counter):
   o 系统必须为每个物理通道 (IPCF/ETH) 维护一个 2 字节的全局发送计数器。每发送一个堆叠报文，该计数器递增 1。
6. CRC16 校验 (CRC16 Checksum):
   o 必须 对整个待发送的数据负载（包括上述 2 字节的计数器）计算一个 CRC16 校验和。
   o 计算得到的 2 字节 CRC16 结果必须附加在数据报文的末尾。
7. 计数器管理 (Counter Management):
   o 明确规定: M 核的发送计数器在经历断开和重启后，不得 被重置为零。
8. CRC16 算法 (CRC16 Algorithm):
   o 为保证两端计算结果一致，实现时 必须 使用以下指定的算法参数：
   ? xorValueCrc16: 0x0000U
   ? startValueCrc16: 0xFFFFU
   o 具体的源码实现请参见 附录 A。
   3.6 A 核订阅机制 (A-Core Subscription Mechanism)
   根据需求 [R3]，必须在 A 核上实现一套特定的 Event 订阅/过滤机制。此机制仅用于 A 核应用程序与 PICC Daemon 之间的交互。
   ? 应用程序使用 SUBSCRIBE_SERVICE (0x03) 消息向 PICC Daemon 注册其感兴趣的 Event 列表。
   ? 应用程序使用 STOP_SUBSCRIBE_SERVICE (0x04) 消息从 PICC Daemon 取消订阅。
   ? PICC Daemon 负责维护每个客户端的订阅列表，并且只将客户端已订阅的 Event 消息转发给该客户端。
   以上功能需求定义了系统的核心行为，下一章节将规范实现这些功能所需的 API 接口。

---

4.0 A 核 API 规范 (A-Core API Specification)
本章节定义了 A 核应用程序用于与跨核通信子系统交互的应用程序编程接口 (API)。根据需求 [R11]，考虑到 M 核的实时性约束（仅支持异步操作），A 核作为核心计算平台，必须 同时提供同步和异步两种模式的 API，以满足不同应用场景的需求。
4.1 Event 发送 API (Event Sending APIs)
int EventSend(uint8_t event_id, uint8_t consumer_id, const vector<uint8_t>& tx_buffer, MethodType en_method_type = EN_notificationWithAck, uint16_t wait_millisecond = 500);
4.1.1 同步发送 (Synchronous Sending)
当 en_method_type 参数为 EN_notificationWithAck 时，API 表现为同步行为。
? 调用后，API 必须 阻塞当前线程，直到收到远端对等体回复的 ACK 报文。
? 如果在 wait_millisecond 指定的超时时间内未收到 ACK，API 必须 返回一个超时错误。
? 重要: 在同步模式下，此函数是 非线程安全 的 ([R11])。
4.1.2 异步发送 (Asynchronous Sending)
当 en_method_type 参数为 EN_notificationWithoutAck 时，API 表现为异步行为。
? 调用后，API 必须 立即返回，不等待任何确认。
? 在异步模式下，此函数 必须 是 线程安全 的，支持从多个线程并发调用 ([R11])。
(Note: The mapping of en_method_type to synchronous/asynchronous behavior has been corrected to reflect the logical intent of the API. EN_notificationWithAck is required for synchronous waits, while EN_notificationWithoutAck is inherently asynchronous. This resolves a logical contradiction present in the source documentation.)
4.2 Method 请求 API (Method Request APIs)
4.2.1 同步请求 (Synchronous Request)
int MethodCall(uint8_t remote_id, uint8_t method_id, const std::vector<uint8_t>& tx_buffer, ReturnCode& return_code, std::vector<uint8_t>& rx_buffer, MethodType type = EN_methodWithResponse, uint16_t u16_wait_milliseconds = 500);
? 行为:
o 当 type 为 EN_methodWithResponse 或 EN_methodWithoutResponseWithAck 时，API 必须 阻塞当前线程，直到收到服务端的业务响应 (Response) 或中间件确认 (Ack)。
o 当 type 为 EN_methodWithoutResponseWithoutAck 时，API 调用后立即返回。
4.2.2 异步请求 (Asynchronous Request)
int AsynMethodCall(uint8_t remote_id, uint8_t method_id, const std::vector<uint8_t>& tx_buffer, uint8_t& session_id, MethodType type = EN_methodWithResponse);
typedef std::function<void(uint8_t remote_id, uint8_t method_id, const ReturnCode& return_code, const std::vector<uint8_t>& rx_buffer, uint8_t session_id)> AsynMethodResponseCallbackFunction;
int RegisterAsynMethodResponseHandler(AsynMethodResponseCallbackFunction callback);
? 工作流:

1. 客户端应用程序首先调用 RegisterAsynMethodResponseHandler 来注册一个用于处理异步响应的回调函数。
2. 客户端调用 AsynMethodCall 发起请求。该函数会立即返回，并通过出参 session_id 提供一个唯一的请求序列号。
3. 当服务端的响应报文到达时，通信组件将调用先前注册的回调函数。
4. 回调函数接收到的 session_id 与发起请求时获得的 session_id 相匹配，从而将响应与原始请求关联起来 ([R11])。
   这些 API 为上层应用提供了与底层通信协议交互的标准化入口，下一章将详细定义协议本身。

---

5.0 通信协议规范 (Communication Protocol Specification)
本章节定义了跨核通信所使用的私有协议的详细规范。所有在 A 核与 M 核之间传输的数据都必须严格遵守本规范，以确保系统的互操作性。
5.1 报文结构 (Packet Structure)
根据需求 [R9]，所有协议报文在网络传输或内存交换时，必须 采用 大端 (Big-Endian) 字节序。
协议报文由一个 8 字节的定长协议头和一个可变长度的负载 (Payload) 组成。协议头结构如下：
字节偏移 字段名 长度 (字节) 描述
0 ProviderID 1 服务提供者标识
1 MethodID 1 服务 (Event/Method) 标识
2 ConsumerID 1 服务消费者 (客户端) 标识
3 SessionID 1 会话 ID，用于报文匹配
4 MessageType 1 报文类型
5 ReturnCode 1 返回码，用于状态或错误指示
6-7 Length 2 Payload 的长度
8+ Payload Length 应用数据负载
5.2 协议字段详解 (Protocol Field Details)
5.2.1 ProviderID & ConsumerID

D 范围,功能名称,M 核占用(%),A 核占用(%)
01 - 10,电源管理,01,6
11 - 20,OTA,11,16
21 - 30,健康管理,21,26
31 - 40,通信模块,31,36
41 - 50,存储模块,41,46
51 - 60,诊断模块,51,56
61 - 70,时钟同步,61,66
71 - 80,SOA,71,76

81 - 254,预留,--,--

? 定义: ProviderID 用于唯一标识一个服务提供者 (Server)，ConsumerID 用于唯一标识一个服务消费者 (Client)。
? 取值范围: 有效值为 1 至 254 (0x01 - 0xFE)。0x00 和 0xFF 为无效值 ([R10])。
? ID 管理规则 ([R10]):

1. ProviderID 和 ConsumerID 在整个系统中 必须 是唯一的。
2. 一个 Provider 可以为多个 Consumer 提供服务。
3. 一个 Consumer 只能使用一个 Provider 提供的服务。
   5.2.2 MethodID
   ? 定义: 用于标识一个 Provider 提供的具体服务，该服务可以是 Event 或 Method。
   ? 取值范围: 有效值为 1 至 254。
   ? 唯一性约束: 在同一个 ProviderID 的上下文中，所有 Event ID 和 Method ID 必须 是唯一的，即两者之间不能有任何重叠 ([R10])。
   5.2.3 SessionID
   ? 定义: 用于关联有逻辑联系的报文，例如请求与响应、通知与确认。
   ? 取值范围: 0x01 至 0xFF。当达到 0xFF 后，下一个值将回滚至 0x01 ([R10])。
   ? 使用场景: 仅在以下两种情况下使用，其余所有报文此字段均为 0x00 ([R10]):
4. 带确认的 Event (NOTIFICATION_WITH_ACK)，用于匹配通知和 EVENT_ACK。
5. 异步 Method 请求，用于匹配 REQUEST 和 RESPONSE。
   ? 计数规则: SessionID 应该 针对同一消息类型 (Event/Method) 进行累加，与 ProviderID 无关。
   5.2.4 MessageType
   此字段用于标识报文的类型。
   值 (Hex) 名称 描述
   0x00 LINK_AVAILABLE 连接/断开相关报文
   0x03 SUBSCRIBE_SERVICE 订阅服务 (仅 A 核内部使用)
   0x04 STOP_SUBSCRIBE_SERVICE 停止订阅服务 (仅 A 核内部使用)
   0x05 REQUEST 服务端有业务应答的请求
   0x06 REQUEST_NO_RETURN_WITH_ACK 应用层无应答，但中间件有确认应答的请求
   0x07 REQUEST_NO_RETURN_WITHOUT_ACK 应用层和中间件均无应答的请求
   0x08 NOTIFICATION_WITH_ACK 中间件有确认应答的通知
   0x09 NOTIFICATION_WITHOUT_ACK 中间件无应答的通知
   0x80 RESPONSE 服务端业务应答消息
   0x81 ACK 中间件对 Method 的确认应答消息
   0x82 EVENT_ACK 中间件对 Event 的确认应答消息
   0x99 ERROR 内部错误码通知
   5.2.5 ReturnCode
   此字段的含义依赖于 MessageType。对于大多数报文类型，此字段固定为 0x00。根据需求 [R12]，其有意义的取值如下：
   ? 当 MessageType 为 LINK_AVAILABLE (0x00) 时:
   o 0x00: 同意连接/断开。
   o 0x01: 不同意连接/断开。
   ? 当 MessageType 为 RESPONSE (0x80) 时:
   o 0x01: E_NOT_OK (服务端处理失败)。
   o 0x02: E_NOT_READY (服务端未准备好接收请求)。
   ? 当 MessageType 为 ERROR (0x99) 时:
   o 用于指示应用层 ID 重复错误或 IPCF 驱动层错误。
   5.2.6 Length
   ? 定义: 一个 2 字节的无符号整数，用于表示紧随其后的 Payload 字段的长度（单位：字节）。
   ? 字节序: 必须 采用大端字节序 ([R9])。
   5.2.7 Payload
   ? 定义: 实际的应用层数据。其内容的格式、序列化和反序列化方式由应用层自行约定，本通信协议不作规定。

---

6.0 附录 (Appendices)
本部分提供用于支持本规范实现的补充参考材料。
6.1 附录 A: CRC16 源码参考 (Appendix A: CRC16 Source Code Reference)
以下是用于数据完整性校验的 CRC16 算法的 C++ 源码参考实现，必须 遵循此实现以确保跨核兼容性。
crc16.h
#include <cstdint>
#include <array>

static constexpr uint16_t xorValueCrc16{0x00'00U};
static constexpr uint16_t startValueCrc16{0xFF'FFU};
