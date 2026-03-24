# PICC API v2.0 简化更新说明

## 📌 更新概述

PICC API v2.0 对所有发送接口进行了大幅简化，将参数数量从 7-8 个减少到 4-5 个，应用层不再需要手动管理和传递 `providerId`、`consumerId`、`instanceId`、`channelId` 等底层参数。

## 🎯 核心改进

### 1. API 参数简化对比

#### PICC_SendEvent()
```c
// v1.x (旧版本) - 7 个参数
PICC_SendEvent(providerId, eventId, consumerId, data, len, withAck, channelId);
// 示例：
PICC_SendEvent(0x61, 0x02U, 0x66, data, len, PICC_EVENT_WITHOUT_ACK, 1U);

// v2.0 (新版本) - 5 个参数
PICC_SendEvent(appIndex, eventId, data, len, withAck);
// 示例：
PICC_SendEvent(PICC_APP_TIMESYNC, 0x02U, data, len, PICC_EVENT_WITHOUT_ACK);
```

#### PICC_MethodRequest()
```c
// v1.x (旧版本) - 7 个参数
PICC_MethodRequest(providerId, methodId, data, len, type, instanceId, channelId);
// 示例：
PICC_MethodRequest(0x16, 0x02U, data, 2U, PICC_METHOD_WITH_RESPONSE, 0, 2U);

// v2.0 (新版本) - 5 个参数
PICC_MethodRequest(appIndex, methodId, data, len, type);
// 示例：
PICC_MethodRequest(PICC_APP_OTA, 0x02U, data, 2U, PICC_METHOD_WITH_RESPONSE);
```

#### PICC_MethodResponse()
```c
// v1.x (旧版本) - 8 个参数
PICC_MethodResponse(consumerId, methodId, sessionId, returnCode, data, len, instanceId, channelId);
// 示例：
PICC_MethodResponse(0x06, 2U, sessionId, 0x00, rspData, 1, 0, 2U);

// v2.0 (新版本) - 6 个参数
PICC_MethodResponse(appIndex, methodId, sessionId, returnCode, data, len);
// 示例：
PICC_MethodResponse(PICC_APP_PWR, 2U, sessionId, 0x00, rspData, 1);
```

### 2. 自动化机制

驱动内部通过 `appIndex` 自动从 `PICC_Init()` 时注册的配置中获取：
- `localId` (ProviderID 或 ConsumerID)
- `remoteId` (对端 ID)
- `channelId` (IPCF 通道号)
- `instanceId` (固定为 IPCF_INSTANCE0)

### 3. 优势总结

✅ **参数减少**：从 7-8 个参数减少到 4-6 个
✅ **消除错误**：不可能传错 channelId 或 instanceId
✅ **代码简洁**：应用层不需要维护 ID 常量
✅ **易于维护**：配置集中在 `PICC_Init()` 中
✅ **向后兼容**：`PICC_Init()` 配置结构体完全不变

## 🔧 技术实现

### 修改的文件列表

1. **picc_mailbox.h/c**
   - 新增 `PICC_MailboxGetAppConfig()` 接口，用于根据 appIndex 查询配置

2. **picc_service.h/c**
   - 将 `PICC_SendEvent()` 改名为 `PICC_ServiceEventSend()`，作为内部接口

3. **picc_api.h**
   - 更新所有发送 API 的声明，简化参数列表

4. **picc_api.c**
   - 实现新的简化版发送 API
   - 内部自动调用 `PICC_MailboxGetAppConfig()` 获取配置
   - 自动进行链路状态检查

5. **pwsm.c**
   - 更新应用层调用示例

6. **PICC_API_使用说明.md**
   - 更新文档和示例代码

### 核心实现逻辑

```c
// 以 PICC_SendEvent 为例
sint8 PICC_SendEvent(PICC_AppIndex_e appIndex, uint8 eventId,
                     const uint8 *data, uint16 len, PICC_EventType_e withAck)
{
    const PICC_AppConfig_t *cfg;
    sint8 ret;

    // 1. 检查基础设施是否初始化
    if (PICC_MailboxIsReady() == FALSE) {
        return PICC_E_NOT_INIT;
    }

    // 2. 根据 appIndex 获取配置
    ret = PICC_MailboxGetAppConfig(appIndex, &cfg);
    if (ret != PICC_E_OK) {
        return PICC_E_PARAM;
    }

    // 3. 检查链路状态
    if (PICC_LinkGetState(cfg->channelId) != PICC_LINK_STATE_CONNECTED) {
        return PICC_E_NOT_CONNECTED;
    }

    // 4. 调用底层服务层接口，自动填充 ID 和 channelId
    return PICC_ServiceEventSend(cfg->localId, eventId, cfg->remoteId,
                                 data, len, withAck, cfg->channelId);
}
```

## 📝 迁移指南

### 应用层代码迁移

只需要修改发送 API 的调用，删除多余的参数：

```c
// 旧代码
PICC_SendEvent(PWR_PROVIDER_ID, PWR_EVENT_STATE_NOTIFY,
               PWR_CONSUMER_ID, payload, 1U,
               PICC_EVENT_WITH_ACK, PWR_CHANNEL_ID);

// 新代码
PICC_SendEvent(PICC_APP_PWR, PWR_EVENT_STATE_NOTIFY,
               payload, 1U, PICC_EVENT_WITH_ACK);
```

### 不需要修改的部分

- `PICC_Init()` 调用保持不变
- `PICC_GetMethodData()` / `PICC_GetResponseData()` / `PICC_GetEventData()` 保持不变
- `PICC_GetLinkState()` 保持不变
- 所有回调函数签名保持不变

## ✅ 验证清单

- [x] picc_mailbox 新增 GetAppConfig 接口
- [x] picc_service 将 SendEvent 改为内部接口
- [x] picc_api.h 更新发送 API 声明
- [x] picc_api.c 实现新的简化版 API
- [x] pwsm.c 更新应用层调用
- [x] PICC_API_使用说明.md 更新文档

## 🚀 后续建议

1. **编译验证**：在实际硬件平台上编译验证
2. **功能测试**：测试 Event/Method 发送和接收功能
3. **其他应用**：如果有其他应用模块（OTA、DIAG 等）使用了 PICC API，也需要相应更新

## 📞 技术支持

如有问题，请参考：
- [PICC_API_使用说明.md](./PICC_API_使用说明.md) - 完整 API 文档
- [picc_api.h](./picc_api.h) - API 头文件
