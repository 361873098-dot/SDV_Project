# PICC API 使用说明

## 1. 概述

`picc_api.h` 是 M 核应用层与 PICC 驱动层交互的**唯一公共接口头文件**。  
应用层只需 `#include "picc_api.h"`，通过 8 个公共 API 完成全部核间通信操作。

---

## 2. 公共 API 列表

| # | 函数 | 方向 | 用途 |
|---|------|------|------|
| 1 | `PICC_Init()` | 初始化 | 注册一个应用模块并配置回调 |
| 2 | `PICC_SendEvent()` | M→A | 发送 Event 通知 |
| 3 | `PICC_MethodRequest()` | M→A | 发送 Method 请求（Client 角色） |
| 4 | `PICC_MethodResponse()` | M→A | 发送 Method 响应（Server 角色） |
| 5 | `PICC_GetMethodData()` | A→M | 获取 A 核发来的 Method 请求数据及回调结果 |
| 6 | `PICC_GetResponseData()` | A→M | 获取 A 核返回的 Method 响应数据及回调结果 |
| 7 | `PICC_GetEventData()` | A→M | 获取 A 核发来的 Event 通知数据及回调结果 |
| 8 | `PICC_GetLinkState()` | 查询 | 查询指定通道的链路连接状态 |

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

    /* 没注册回调，不需要 cbResult，后两个参数传 NULL, NULL */
    if (PICC_GetMethodData(PICC_APP_PWR, 2U, buf, sizeof(buf), &len,
                           NULL, NULL) == PICC_E_OK) {
        uint8 ackState = buf[0];
        /* 处理收到的 Method Request (ID=2)... */
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

    /* 一次 API 调用！邮箱会把刚才记录的回调时间戳一并返回 */
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
        /* 即刻进行擦写操作 */
        sint8 ret = Flash_Write(reqData, reqLen);
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

void OTA_Main(void)
{
    uint8 data[32]; uint16 len;
    uint8 cbResult[8]; uint16 cbLen;

    /* 周期任务完全省去写全局变量，在这里检查是否有完成烧写的块 */
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
