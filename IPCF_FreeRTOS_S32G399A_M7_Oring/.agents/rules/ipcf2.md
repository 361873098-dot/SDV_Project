---
trigger: always_on
---

---
trigger: always_on
---
以下是核间通讯协议第二部分
所有报文都是堆叠报文，也就是说 M 核接收的数据都是堆叠报文，M 核发出去的也是堆叠报文；

当前的通道仅支持 ipfc 通道，也就是代码中所配置的 ipcf_shm_cfg_channels0，表示的是 ipcf 通道，所使用的 instances 为 1，即表示只有 1 个通道，也就是 IPCF 通道，这个 instances 对应于 PICC_ProcessRxData （）中的 instance；这个 ipcf 的通道中有配置两个 ipcf channel，即 ipcf_shm_cfg_channels0 这个数组中的 index =1 和 index=2 分别对应 PICC_ProcessRxData（）中的形参 chan_id；
由于 M 核心的实时性，无法进行同步等待，所以：
1 M 核发送 Request 之后，需要使用异步的方式去获取 A 核返回 RESPONSE 消息中的 seesion id 进行匹配从而对获取信息；
2 M 核发送 EVENT 的时候，只需要发不带 ACK 的 EVENT，如果应用层需要 M 核发带 ACK 的 EVENT，那么 M 核对这个 EVENT 的 ACK 不做处理；

你检查当前整个代码，不要修改 configTOTAL_HEAP_SIZE 这个大小的情况，去修改 SAMPLE_TASK_STACK_SIZE 的大小，payload 大小虽然是两个字节的大小，但是实际情况也不会有两字节这么大的 palyload，所以我希望你能合理配置 SAMPLE_TASK_STACK_SIZE，从而避免出现程序崩溃的问题

Session ID 用于区分同一 Event/Method ID 下的不同报文，范围 0x01~0xFF，当达到 0xFF 时，回到 0x01 重新开始计数。目前只在下面 2 种情况下使用，其余情况为 0x00 。
• 带 Ack 的 Event，因为需要匹配 Event 和对应的 Ack。
• 异步 Method 请求，因为需要匹配 Request 和 Response。
• 用以区分同一类型消息的不同报文，比如，陆续发送 event 为 1 的消息，第一条消息的协议 session id 字段是 1，第二条消息 session id 字段是 2，以此类推
• 问题：M 核作为 CLIENT 发起异步 Method 请求时，这个 Session id 是全局（所有异步 Method 范围内累加还是在单次连接或特定 Provider 范围内累加？M 核要知道如何安全的管理这个计数器以防止冲突，尤其是在连接断开重连以后，M 核是否应重置这个 Session id 的计数器）
• 回答：要保证同一个 EVNET 的消息，要进行累加，所以这个时候于 PROVIDER 无关；所以全局或者局部变量都可以；都能区分同一个类型消息的不同报文；断开重连以后这个 SESSION ID 可以重置或不重置，都可以；

当前程序心跳需要在 CHANNEL 1 和 CHANNEL2 上同时双向发送和接收，心跳报文和 CLIENT Server 无关联，用于检测通道是否可用，心跳报文与应用层无关；也就是说是否连接成功，心跳报文都要发送；

连接/断开功能
• 核间通信中的 Server，Client 在使用 Event，Method 服务前，会进行“握手”交互确认：Client 启动后，会主动向 Server 发起连接请求，Server 收到后回复连接应答,如果未收到连接应答，Client 会周期发送连接请求 。(M 核先启动，A 核后启动)
• 极端情况下,如果 A 核 PICC Daemon 意外挂掉重启，并且 A 核是 Server 的情况下，A 核会向 M 核发送 Server 重启通知，M 核中的 Client 重新发起连接请求。
• Client/Server 退出后,会向对端发送断开 通知。（由于 M 核的特殊性，实际场景中只会出现 A 核向 M 核发送断开通知）。
只要用到了核间通讯的应用都需要有连接请求和断开请求这个功能，例如电源管理使用了核间通讯，那么电源管理就会用到这个连接/断开功能，