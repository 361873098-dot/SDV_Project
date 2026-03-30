---
trigger: always_on
---

---
trigger: always_on
---
以下是核间通讯第三部分
constexpr std::array<uint16_t, 256> lookupTableCrc16{
    0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50a5U, 0x60c6U, 0x70e7U, 0x8108U, 0x9129U, 0xa14aU, 0xb16bU, 0xc18cU,
    0xd1adU, 0xe1ceU, 0xf1efU, 0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52b5U, 0x4294U, 0x72f7U, 0x62d6U, 0x9339U, 0x8318U,
    0xb37bU, 0xa35aU, 0xd3bdU, 0xc39cU, 0xf3ffU, 0xe3deU, 0x2462U, 0x3443U, 0x0420U, 0x1401U, 0x64e6U, 0x74c7U, 0x44a4U,
    0x5485U, 0xa56aU, 0xb54bU, 0x8528U, 0x9509U, 0xe5eeU, 0xf5cfU, 0xc5acU, 0xd58dU, 0x3653U, 0x2672U, 0x1611U, 0x0630U,
    0x76d7U, 0x66f6U, 0x5695U, 0x46b4U, 0xb75bU, 0xa77aU, 0x9719U, 0x8738U, 0xf7dfU, 0xe7feU, 0xd79dU, 0xc7bcU, 0x48c4U,
    0x58e5U, 0x6886U, 0x78a7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U, 0xc9ccU, 0xd9edU, 0xe98eU, 0xf9afU, 0x8948U, 0x9969U,
    0xa90aU, 0xb92bU, 0x5af5U, 0x4ad4U, 0x7ab7U, 0x6a96U, 0x1a71U, 0x0a50U, 0x3a33U, 0x2a12U, 0xdbfdU, 0xcbdcU, 0xfbbfU,
    0xeb9eU, 0x9b79U, 0x8b58U, 0xbb3bU, 0xab1aU, 0x6ca6U, 0x7c87U, 0x4ce4U, 0x5cc5U, 0x2c22U, 0x3c03U, 0x0c60U, 0x1c41U,
    0xedaeU, 0xfd8fU, 0xcdecU, 0xddcdU, 0xad2aU, 0xbd0bU, 0x8d68U, 0x9d49U, 0x7e97U, 0x6eb6U, 0x5ed5U, 0x4ef4U, 0x3e13U,
    0x2e32U, 0x1e51U, 0x0e70U, 0xff9fU, 0xefbeU, 0xdfddU, 0xcffcU, 0xbf1bU, 0xaf3aU, 0x9f59U, 0x8f78U, 0x9188U, 0x81a9U,
    0xb1caU, 0xa1ebU, 0xd10cU, 0xc12dU, 0xf14eU, 0xe16fU, 0x1080U, 0x00a1U, 0x30c2U, 0x20e3U, 0x5004U, 0x4025U, 0x7046U,
    0x6067U, 0x83b9U, 0x9398U, 0xa3fbU, 0xb3daU, 0xc33dU, 0xd31cU, 0xe37fU, 0xf35eU, 0x02b1U, 0x1290U, 0x22f3U, 0x32d2U,
    0x4235U, 0x5214U, 0x6277U, 0x7256U, 0xb5eaU, 0xa5cbU, 0x95a8U, 0x8589U, 0xf56eU, 0xe54fU, 0xd52cU, 0xc50dU, 0x34e2U,
    0x24c3U, 0x14a0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U, 0xa7dbU, 0xb7faU, 0x8799U, 0x97b8U, 0xe75fU, 0xf77eU,
    0xc71dU, 0xd73cU, 0x26d3U, 0x36f2U, 0x0691U, 0x16b0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U, 0xd94cU, 0xc96dU, 0xf90eU,
    0xe92fU, 0x99c8U, 0x89e9U, 0xb98aU, 0xa9abU, 0x5844U, 0x4865U, 0x7806U, 0x6827U, 0x18c0U, 0x08e1U, 0x3882U, 0x28a3U,
    0xcb7dU, 0xdb5cU, 0xeb3fU, 0xfb1eU, 0x8bf9U, 0x9bd8U, 0xabbbU, 0xbb9aU, 0x4a75U, 0x5a54U, 0x6a37U, 0x7a16U, 0x0af1U,
    0x1ad0U, 0x2ab3U, 0x3a92U, 0xfd2eU, 0xed0fU, 0xdd6cU, 0xcd4dU, 0xbdaaU, 0xad8bU, 0x9de8U, 0x8dc9U, 0x7c26U, 0x6c07U,
    0x5c64U, 0x4c45U, 0x3ca2U, 0x2c83U, 0x1ce0U, 0x0cc1U, 0xef1fU, 0xff3eU, 0xcf5dU, 0xdf7cU, 0xaf9bU, 0xbfbaU, 0x8fd9U,
    0x9ff8U, 0x6e17U, 0x7e36U, 0x4e55U, 0x5e74U, 0x2e93U, 0x3eb2U, 0x0ed1U, 0x1ef0U
};

uint16_t CalculateCRC16(uint8_t* bufferView, int len, bool isFirstCall, uint16_t startValue) noexcept;
uint16_t CRC16(uint8_t* bufferView, int len) noexcept;
crc16.cpp
#include "crc16.h"

using namespace std;

uint16_t CalculateCRC16(uint8_t* bufferView, int len, bool isFirstCall, uint16_t startValue) noexcept
{
    uint16_t crc;
    if (isFirstCall) {
        crc = startValueCrc16;
    } else {
        crc = startValue ^ xorValueCrc16;
    }
    
    for(int ienum = 0; ienum < len; ienum++)
    {
        uint8_t arrIdx{static_cast<uint8_t>(bufferView[ienum] ^ static_cast<uint8_t>(crc >> 8U))};
        crc = static_cast<uint16_t>(crc << 8U) ^ lookupTableCrc16[arrIdx];
    }
    
    crc ^= xorValueCrc16;
    return crc;
}

uint16_t CRC16(uint8_t* bufferView, int len) noexcept
{
    return CalculateCRC16(bufferView, len, true, 0x00);
}
6.2 附录 B: 报文时序与示例 (Appendix B: Message Sequence and Examples)
6.2.1 Link/Disconnect Sequence
?	Client 发送连接请求: 0xcd 00 c9 00 00 01 00 05 01 ...
字段	值	描述
ProviderID	0xcd	服务端 ID
MethodID	0x00	固定值
ConsumerID	0xc9	客户端 ID
SessionID	0x00	固定值
MessageType	0x00	LINK_AVAILABLE
ReturnCode	0x01	不同意 (初始请求值)
Length	0x0005	Payload 长度为 5 字节
Payload[0]	0x01	代表连接请求
(Note: The hex value for MessageType has been corrected to 0x00 to align with the protocol specification in Section 5.2.4, resolving an inconsistency in the source material's log.)
?	Server 回复连接确认: 0xcd 00 c9 00 00 00 00 05 01 ...
字段	值	描述
ReturnCode	0x00	同意连接
...	...	(其余字段同上)
?	Server 发送断开通知: 0xcd 00 c9 00 00 01 00 05 02 ...
字段	值	描述
MessageType	0x00	LINK_AVAILABLE
ReturnCode	0x01	不同意 (初始通知值)
Payload[0]	0x02	代表断开通知
...	...	(其余字段同上)
?	Client 回复断开确认: 0xcd 00 c9 00 00 00 00 05 02 ...
字段	值	描述
ReturnCode	0x00	同意断开
Payload[0]	0x02	代表断开报文
...	...	(其余字段同上)
6.2.2 Method Call Sequence
?	Client 发送 REQUEST 请求 (Method With Response): ce 03 d2 00 05 00 00 02 xx xx
字段	值	描述
ProviderID	0xce	服务端 ID
MethodID	0x03	Method ID
ConsumerID	0xd2	客户端 ID
SessionID	0x00	同步调用，固定为 0
MessageType	0x05	REQUEST
ReturnCode	0x00	固定值
Length	0x0002	Payload 长度为 2 字节
Payload	xx xx	客户端请求数据
(Note: The MessageType description in this table has been corrected from RESPONSE to REQUEST to align with the hex value 0x05 and the protocol specification.)
?	Server 回复 RESPONSE 响应: ce 03 d2 00 80 00 00 02 yy yy
字段	值	描述
MessageType	0x80	RESPONSE
ReturnCode	0x00	服务处理成功
Length	0x0002	Payload 长度为 2 字节
Payload	yy yy	服务端响应数据
...	...	(其余字段与请求保持一致)
(Note: The MessageType description in this table has been corrected from REQUEST to RESPONSE to align with the hex value 0x80 and the protocol specification.)

 组包格式说明

第一字节是CRC使能位，0代表使能，1代表非使能
• 后面是N个私有协议数据包
• 2字节的counter，每个通道上独立累计计算
最后2字节是CRC,计算前面所有数据的CRC16
1Byte	NByte	NByte	NByte	2Byte	2Byte
CRC使能位	私有协议包1	私有协议包2	...	Counter	CRC



以下为电源管理的时序：
Method/Event ID： 1  M-->A   01 01 06 01 08 00 00 01 04
Method/Event ID： 2  A-->M   01 02 06 00 07 00 00 02 03 04
Method/Event ID： 8  A-->M   01 08 06 00 07 00 00 01 03
Method/Event ID： 4  M-->A   01 04 06 02 08 00 00 02 03 03
Method/Event ID： 11 A-->M   01 0B 06 00 07 00 00 02 03 00

IPCF通道：例如：10ms周期发送或者消息堆叠达到IPCF驱动配置的最大buffer大小左右（包含协议头）发送。核间通信的应用在通信时需要确认ProviderID和ConsumerID，ProviderID和ConsumerID公用1-254这个范围。在同一个应用中可以存在多个Provider和Consumer，但需要注意这些角色的ID不允许重复。一个Provider角色可以为多个Consumer角色服务，但一个Consumer角色只允许使用一个Provider提供的服务，即Provider1可以对应Consumer2，Consumer3，但Consumer3不能再对应Provider2。每个Provider角色可以提供多种服务，如Event，Method服务，这些Event或者Method也需要分配MethodID，每个Provider下的MethodID取值范围为1-254，不同的Provider可以有相同MethodID的服务。ProviderID和ConsumerID均在构造函数中传入，具体可参考API文档说明。

 Event：一个单向的数据传输，用于Server主动向Client发布信息。协议层根据该客户端是否订阅(M核不支持订阅)，确定消息是否转发给Client。Method：服务端提供Method服务。Method服务分为Request和Response消息，Request用于Client端向Server端发送调用进程/函数/子程序的请求，而Response则是Method执行端完成动作后向调用方回复的调用结果。Method当前支持REQUEST，REQUEST_NO_RETURN_WITH_ACK，REQUEST_NO_RETURN_WITHOUT_ACK类型（ACK由协议层完成，应用层无需关注）以上为新的需求，
 
	不带ACK 的event 方式发送 resquest 的Response ，可以不用等待这个Session ID；可以异步处理这个Session id ,

	由于M核心的实时性，无法进行同步等待，所以：
1	M核发送Request 之后，需要使用异步的方式去获取A核返回RESPONSE消息中的seesion id进行匹配从而对获取信息；
2	M核发送EVENT 的时候，只需要发不带ACK的EVENT，如果应用层需要M核发带ACK的EVENT，那么M核对这个EVENT 的ACK不做处理；