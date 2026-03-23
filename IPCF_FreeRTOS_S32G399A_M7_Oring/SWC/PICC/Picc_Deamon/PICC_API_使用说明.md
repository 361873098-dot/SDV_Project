# PICC API 使用说明

## 📌 v2.0 重要简化更新

从 v2.0 版本开始，所有发送 API 已大幅简化：

**之前（v1.x）**：
```c
// 需要手动传递 7-8 个参数，包括 providerId, consumerId, instanceId, channelId
PICC_SendEvent(0x61, 0x02U, 0x66, data, len, PICC_EVENT_WITHOUT_ACK, 1U);
PICC_MethodRequest(0x16, 0x02U, data, 2U, PICC_METHOD_WITH_RESPONSE, 0, 2U);
PICC_MethodResponse(0x06, 2U, sessionId, 0x00, rspData, 1, 0, 2U);
```

**现在（v2.0）**：
```c
// 只需传递 appIndex，驱动自动从 PICC_Init() 配置中获取 ID 和 channelId
PICC_SendEvent(PICC_APP_TIMESYNC, 0x02U, data, len, PICC_EVENT_WITHOUT_ACK);
PICC_MethodRequest(PICC_APP_OTA, 0x02U, data, 2U, PICC_METHOD_WITH_RESPONSE);
PICC_MethodResponse(PICC_APP_PWR, 2U, sessionId, 0x00, rspData, 1);
```

**优势**：
- 参数数量从 7-8 个减少到 4-5 个
- 不需要应用层维护 ID 常量，只需知道自己的 `PICC_APP_xxx` 枚举
- 消除了传错 channelId 或 instanceId 的可能性
- `PICC_Init()` 配置保持不变，完全向后兼容

---

## 0. 核心通信方向与角色向导 (Directionality & Role Summary)

在深入具体 API 之前，**必须先理清 M核与A核 之间两种通信协议的数据流向**。明确了方向，您就知道什么时候该调用什么接口。

### 1) EVENT 协议 (单向通知 / Fire-and-Forget)
**特性**：发即忘（类似 UDP 广播），发送方无需对方回复处理结果（无需 Response）。
*   【**发送方向**：M核 ➡ A核】 (`M -> A`)
    *   **动作**：M核主动调用 `PICC_SendEvent()`。
*   【**接收方向**：A核 ➡ M核】 (`A -> M`)
    *   **动作**：M核通过初始化时注册的 `.eventHandler` 捕获即时硬中断通知；**或者**在周期任务中主动轮询 `PICC_GetEventData()` 读取。

### 2) METHOD 协议 (双向请求 / Request-Response)
**特性**：一问一答（类似 RPC），Client 提问发起 Request，Server 作答返回 Response。
*   **情形 A：M核是 Client（M核提问，A核作答）**
    *   【**发起请求**：M核 ➡ A核】 (`M -> A`)：M核主动调用 `PICC_MethodRequest()` 发送指令。
    *   【**提取应答**：A核 ➡ M核】 (`A -> M`)：M核在周期任务中轮询 `PICC_GetResponseData()` 收割 A核的处理结果。
*   **情形 B：M核是 Server（A核提问，M核作答）**
    *   【**提取请求**：A核 ➡ M核】 (`A -> M`)：M核通过初始化时注册的 `.methodHandler` 捕获 A核的瞬间请求；**或者**在周期任务中轮询 `PICC_GetMethodData()` 拿到 A核发来的指令数据。
    *   【**反馈应答**：M核 ➡ A核】 (`M -> A`)：M核在处理完业务后，必须主动调用 `PICC_MethodResponse()` 给 A核擦屁股回包以结束会话。

---

## 1. 概述

`picc_api.h` 是 M 核应用层与 PICC 驱动层交互的**唯一公共接口头文件**。  
应用层只需 `#include "picc_api.h"`，通过 8 个公共 API 完成全部核间通信操作。

---

## 2. 公共 API 列表

| # | 函数 | 方向 | 用途 |
|---|------|------|------|
| 1 | `PICC_Init()` | 初始化 | 注册一个应用模块并配置回调 |
| 2 | `PICC_SendEvent()` | M→A | 发送 Event 通知（简化版：自动使用 Init 时的配置） |
| 3 | `PICC_MethodRequest()` | M→A | 发送 Method 请求（简化版：自动使用 Init 时的配置） |
| 4 | `PICC_MethodResponse()` | M→A | 发送 Method 响应（简化版：自动使用 Init 时的配置） |
| 5 | `PICC_GetMethodData()` | A→M | 获取 A 核发来的 Method 请求数据及回调结果 |
| 6 | `PICC_GetResponseData()` | A→M | 获取 A 核返回的 Method 响应数据及回调结果 |
| 7 | `PICC_GetEventData()` | A→M | 获取 A 核发来的 Event 通知数据及回调结果 |
| 8 | `PICC_GetLinkState()` | 查询 | 查询指定通道的链路连接状态 |

**重要改进**：从 v2.0 开始，所有发送 API（SendEvent/MethodRequest/MethodResponse）都已简化，不再需要手动传递 `providerId`、`consumerId`、`instanceId`、`channelId` 等参数。驱动会自动从 `PICC_Init()` 时注册的配置中获取这些信息。

---

## 3. PICC_Init 配置说明

### 3.1 PICC_AppConfig_t 结构体

```c
typedef struct {
    uint8                    localId;           /* 本地 ID */
    uint8                    remoteId;          /* 对端 ID */
    PICC_Role_e              role;              /* Server 或 Client */
    uint8                    channelId;         /* IPCF 通道号 (1 或 2) */
    PICC_LinkStateCallback_t linkStateCallback; /* 链路状态回调（可为 NULL） */
    PICC_MethodCallback_t    methodHandler;     /* Method 请求回调（可为 NULL） */
    PICC_EventCallback_t     eventHandler;      /* Event 通知回调（可为 NULL） */
} PICC_AppConfig_t;
```

### 3.2 三个回调字段说明

三个回调字段均为**可选**。传 `NULL` 表示使用**纯轮询模式**，传函数指针表示使用**即时回调模式**。  
**两种模式可以无缝结合**：邮箱始终存储 A 核原始数据，如果注册了回调，回调产生的结果也会自动存入邮箱。  
**应用层统一通过 `PICC_Get*Data()` 获取全部数据**（既包含 A 核请求/事件原始数据，也包含回调执行后输出的结果 `cbResult`）。

#### linkStateCallback（链路状态回调）

| 传值 | 行为 |
|------|------|
| `NULL` | 通过 `PICC_GetLinkState()` 轮询 |
| 函数指针 | 链路变化时立刻调用 |

```c
typedef void (*PICC_LinkStateCallback_t)(uint8 remoteId, PICC_LinkState_e state);
```

#### methodHandler（Method 请求回调）

| 传值 | 行为 |
|------|------|
| `NULL` | 纯轮询，`PICC_GetMethodData()` 读取 A 核请求数据。 |
| 函数指针 | 请求到达时立刻调用。回调不仅由于构建响应，还可通过 `cbResult` 输出即时结果，该结果可随后通过 `PICC_GetMethodData()` 轮询读取。 |

```c
typedef uint8 (*PICC_MethodCallback_t)(uint8 consumerId, uint8 methodId,
                                       const uint8 *reqData, uint16 reqLen,
                                       uint8 *rspData, uint16 *rspLen,
                                       uint8 *cbResult, uint16 *cbResultLen);
```

#### eventHandler（Event 通知回调）

| 传值 | 行为 |
|------|------|
| `NULL` | 纯轮询，通过 `PICC_GetEventData()` 读取 A 核 Event 数据。 |
| 函数指针 | 事件到达时立刻调用。回调内部通常执行轻量、高时效性操作（如采集时间戳）输出到 `cbResult` 中，并存入邮箱供周期应用轮询读取。 |

```c
typedef void (*PICC_EventCallback_t)(uint8 providerId, uint8 eventId,
                                     const uint8 *data, uint16 len,
                                     uint8 *cbResult, uint16 *cbResultLen);
```

### 3.3 统一轮询读取 API（新增 cbResult 极简设计）

```c
/* 最后两个参数用于输出本次接收带来的"回调产生的结果（cbResult）"。如果应用不需要或者没注册该类事件的回调，传 NULL 即可 */
sint8 PICC_GetMethodData(appIndex, methodId, data, maxLen, &len, cbResult, &cbLen);
sint8 PICC_GetResponseData(appIndex, methodId, &retCode, data, maxLen, &len, cbResult, &cbLen);
sint8 PICC_GetEventData(appIndex, eventId, data, maxLen, &len, cbResult, &cbLen);
```

---

## 4. 使用示例

> **核心概念**：不管应用层底层是否注册了回调函数（执行实时操作），周期主任务始终使用相同的 `PICC_Get*Data()` 进行查询。  
> 这一极简设计意味着应用不再需要自己声明复杂的全局共享变量，也能够轻松得到回调产生的即时计算结果。

### 4.1 场景一：纯轮询（Pwsm 电源管理模型）

回调全部传 `NULL`，直接在周期任务中获取并处理数据。由于不需要回调返回的结果，获取函数中传 `NULL, NULL`。

```c
void Pwsm_Init(void)
{
    static const PICC_AppConfig_t cfg = {
        .localId = 0x01, .remoteId = 0x06,
        .role = PICC_ROLE_SERVER, .channelId = 2U,
        .linkStateCallback = NULL,
        .methodHandler     = NULL,
        .eventHandler      = NULL
    };
    (void)PICC_Init(PICC_APP_PWR, &cfg);
}

void Pwsm_Main(void)  /* 10ms 周期任务 */
{
    uint8 buf[8]; uint16 len;

    if (PICC_GetLinkState(2U) != PICC_LINK_STATE_CONNECTED) return;

    /* 【提取请求：A ➡ M】（METHOD 场景B：M核是 Server 获取请求） */
    /* 没注册回调，不需要 cbResult，后两个参数传 NULL, NULL */
    if (PICC_GetMethodData(PICC_APP_PWR, 2U, buf, sizeof(buf), &len,
                           NULL, NULL) == PICC_E_OK) {
        uint8 ackState = buf[0];
        /* 第1步：处理收到的 Method Request (ID=2) 的业务逻辑... */
        
        /* 【反馈应答：M ➡ A】（METHOD 场景B：M核必须回复 Response 形成 RPC 闭环！） */
        /* ⚠️ 防呆提示：因为您没注册回调函数，所以必须由您手动调用 MethodResponse 发送回包结束本次会话！ */
        uint8 rspPayload[1] = { 0x00 }; /* 假设 0x00 表示处理成功 */
        (void)PICC_MethodResponse(PICC_APP_PWR, 2U, 0U /* 假设sessionId为0 */, 0x00, rspPayload, 1);
    }
}
```

### 4.2 场景二：Event 回调 + 统一读取（时钟同步时间戳模型）

回调中立刻采集硬件定时器戳写入 `cbResult`，随后周期任务无缝通过 `PICC_GetEventData()` 一并拿到 A 核数据和刚才记录的硬件回调结果（本地时间戳）。

```c
static void TimeSync_EventHandler(uint8 providerId, uint8 eventId,
                                   const uint8 *data, uint16 len,
                                   uint8 *cbResult, uint16 *cbResultLen)
{
    if (eventId == 0x01U) {
        /* [即时操作] 在数据到达微秒级瞬间，采集本地机器时间戳 */
        uint32 ts = STM_GetCounter();
        cbResult[0] = (uint8)(ts >> 24U);
        cbResult[1] = (uint8)(ts >> 16U);
        cbResult[2] = (uint8)(ts >>  8U);
        cbResult[3] = (uint8)(ts);
        *cbResultLen = 4U;
    }
}

void TimeSync_Init(void)
{
    static const PICC_AppConfig_t cfg = {
        .localId = 0x61, .remoteId = 0x66,
        .role = PICC_ROLE_CLIENT, .channelId = 1U,
        .linkStateCallback = NULL,
        .methodHandler     = NULL,
        .eventHandler      = TimeSync_EventHandler
    };
    (void)PICC_Init(PICC_APP_TIMESYNC, &cfg);
}

void TimeSync_Main(void)  /* 10ms 周期任务 */
{
    uint8 remoteData[8]; uint16 remoteLen;
    uint8 cbResult[8];   uint16 cbLen;

    /* 【提取通知：A ➡ M】（EVENT 接收通知） */
    /* 只需这 1 个 API（无需查全局变量），就能同时提取远端包裹和刚才顺手记录的本地时间戳！ */
    if (PICC_GetEventData(PICC_APP_TIMESYNC, 0x01U,
                          remoteData, sizeof(remoteData), &remoteLen,
                          cbResult, &cbLen) == PICC_E_OK)
    {
        uint32 localTs = ((uint32)cbResult[0] << 24U) |
                         ((uint32)cbResult[1] << 16U) |
                         ((uint32)cbResult[2] <<  8U) |
                         ((uint32)cbResult[3]);
                         
        /* 有了 A核数据(remoteData) + 回调记录的即时本地时间戳(localTs)，即可开始对齐计算 */
        TimeSync_CalculateOffset(localTs, remoteData, remoteLen);
        
        /* 【主动发送通知：M ➡ A】（EVENT 发送单向通知） */
        /* 同步计算完成后，如果想立刻反向报喜给 A核，因为是 EVENT，发出去就不管了 */
        uint8 syncDoneMsg[1] = { 0x01 };
        (void)PICC_SendEvent(PICC_APP_TIMESYNC, 0x02U, syncDoneMsg, 1, PICC_EVENT_WITHOUT_ACK);
    }
}
```

### 4.3 场景三：Method 回调 + 统一读取（OTA 写闪存模型）

```c
static uint8 OTA_MethodHandler(uint8 consumerId, uint8 methodId,
                                const uint8 *reqData, uint16 reqLen,
                                uint8 *rspData, uint16 *rspLen,
                                uint8 *cbResult, uint16 *cbResultLen)
{
    if (methodId == 0x03U) {
        /* [即刻进行擦写操作] */
        sint8 ret = Flash_Write(reqData, reqLen);
        
        /* 【反馈应答准备：M ➡ A】（METHOD 场景B：自动闭环） */
        /* ⚠️ 高级用法防呆提示：由于您在此注册了 Callback 函数！ */
        /* 驱动底层在拿到下面的 rspData 和 rspLen 赋值后，会【全自动调用 PICC_MethodResponse()】替您擦屁股！ */
        /* 您在下文的 OTA_Main 手动轮询时，就『绝不能』再去调用一次 MethodResponse 重复发包了。 */
        rspData[0] = (ret == 0) ? 0x00U : 0x01U;
        *rspLen = 1U;

        /* 回调结果输出：把本次写入完毕的字节数留给周期应用任务展示用 */
        cbResult[0] = (uint8)(reqLen >> 8U);
        cbResult[1] = (uint8)(reqLen);
        *cbResultLen = 2U;
        return 0x00;
    }
    return 0x01;
}

void OTA_Init(void)
{
    static const PICC_AppConfig_t cfg = {
        .localId = 0x11, .remoteId = 0x16,
        .role = PICC_ROLE_SERVER, .channelId = 2U,
        .linkStateCallback = NULL,
        .methodHandler     = OTA_MethodHandler, /* <--- 在这里注册回调！ */
        .eventHandler      = NULL
    };
    (void)PICC_Init(PICC_APP_OTA, &cfg);
}

void OTA_Main(void)
{
    uint8 data[32]; uint16 len;
    uint8 cbResult[8]; uint16 cbLen;

    /* 【主动请求：M ➡ A】（METHOD 场景A：M核主动扮演 Client) */
    /* 例如如果 M核 OTA 觉得该下一包了，可以随时发起 MethodRequest 要更新数据 */
    // uint8 reqCmd[2] = {0x00, 0x01};
    // (void)PICC_MethodRequest(PICC_APP_OTA, 0x02U, reqCmd, 2U, PICC_METHOD_WITH_RESPONSE);

    /* 【提取请求（已自动回复妥当）：A ➡ M】（METHOD 场景B：获取通知和回调果实） */
    /* 周期任务完全省去写全局变量，在这里直接检查刚才瞬间的回调有没有完成烧写的块 */
    if (PICC_GetMethodData(PICC_APP_OTA, 0x03U, data, sizeof(data), &len,
                           cbResult, &cbLen) == PICC_E_OK) {
        uint16 writtenBytes = ((uint16)cbResult[0] << 8U) | cbResult[1];
        /* 记录 writtenBytes，更新进度条等... */
    }
}
```

---

## 5. 数据流总结

```
A核数据到达 → PICC_StoreToMailbox(payload)  ─── 覆盖存入槽位 slot.data
           → 调用底层回调(产生cbResult)      ─── 覆盖存入槽位 slot.cbResult
           │
           ▼
  应用层周期拉取 PICC_Get*Data(data, cbResult)
           │
           ├─ data     = A核请求/返回/事件原始数据
           └─ cbResult = 回调产生的结果（如果没有执行回调，则 cbResultLen = 0）
```

| 运行时特性 | 注册回调状态 | `PICC_Get*Data()` 操作结果 |
|------|:----:|----------------------|
| **纯轮询模式** | `NULL` | 读取出 `data` 为A核原始数据，`cbResultLen=0` |
| **异步混合模式** | `函数指针` | 读取出 `data` 为A核原始数据，同时 `cbResult` 为即时回调产生的产物 |

---

## 6. 兼容性总结

`PICC_Init()` 配置接口和 `PICC_Get*Data()` 拉取接口设计为**完全且一致地屏蔽了底层差异**。无论业务对延迟的诉求如何，均可保持主干代码风格统一，极大程度避免在应用层大量维护外部共享标志位，提高高复用性核间通信的使用体验。
