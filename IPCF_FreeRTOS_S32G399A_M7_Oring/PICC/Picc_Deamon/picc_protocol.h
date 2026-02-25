/**
 * @file picc_protocol.h
 * @brief M-Core Inter-Core Communication Protocol Layer - Data Structures and Interface Definition
 *
 * Defines data structures, message types, return codes for inter-core communication private protocol.
 * Protocol messages use big-endian transmission, 8-byte protocol header + Payload.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_PROTOCOL_H
#define PICC_PROTOCOL_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "ipc-types.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Protocol header length (bytes) */
#define PICC_HEADER_SIZE            (8U)

/** Maximum Payload length (supports up to 4096 bytes as per customer requirement) */
#define PICC_MAX_PAYLOAD_SIZE       (4096U)

/** Invalid ID value */
#define PICC_INVALID_ID             (0xFFU)

/** Session ID range */
#define PICC_SESSION_ID_MIN         (0x01U)
#define PICC_SESSION_ID_MAX         (0xFFU)

/** Link message fixed Method ID */
#define PICC_LINK_METHOD_ID         (0x00U)

/** Broadcast Provider ID (for Server restart notification) */
#define PICC_BROADCAST_PROVIDER_ID  (0xFFU)

/*==================================================================================================
 *                                         Enum Types
 *==================================================================================================*/

/**
 * @brief Message type enumeration
 * 
 * Corresponds to MessageType field in protocol
 */
typedef enum {
    PICC_MSG_LINK_AVAILABLE                 = 0x00U,  /**< Connect/Disconnect */
    PICC_MSG_SUBSCRIBE_SERVICE              = 0x03U,  /**< Subscribe service (A-Core only) */
    PICC_MSG_STOP_SUBSCRIBE_SERVICE         = 0x04U,  /**< Stop subscribe (A-Core only) */
    PICC_MSG_REQUEST                        = 0x05U,  /**< Method request (with Response) */
    PICC_MSG_REQUEST_NO_RETURN_WITH_ACK     = 0x06U,  /**< Method request (no Response, with ACK) */
    PICC_MSG_REQUEST_NO_RETURN_WITHOUT_ACK  = 0x07U,  /**< Method request (no Response, no ACK) */
    PICC_MSG_NOTIFICATION_WITH_ACK          = 0x08U,  /**< Event notification (with ACK) */
    PICC_MSG_NOTIFICATION_WITHOUT_ACK       = 0x09U,  /**< Event notification (no ACK) */
    PICC_MSG_RESPONSE                       = 0x80U,  /**< Method response */
    PICC_MSG_ACK                            = 0x81U,  /**< Method ACK */
    PICC_MSG_EVENT_ACK                      = 0x82U,  /**< Event ACK */
    PICC_MSG_ERROR                          = 0x99U   /**< Error message */
} PICC_MsgType_e;

/**
 * @brief Return code enumeration
 * 
 * Corresponds to ReturnCode field in protocol
 */
typedef enum {
    PICC_RET_OK             = 0x00U,  /**< Success/Agree */
    PICC_RET_NOT_OK         = 0x01U,  /**< Failure/Disagree */
    PICC_RET_NOT_READY      = 0x02U   /**< Service not ready */
} PICC_ReturnCode_e;

/**
 * @brief Link message subtype
 * 
 * Corresponds to first byte of LINK_AVAILABLE message Payload
 */
typedef enum {
    PICC_LINK_CONNECT       = 0x01U,  /**< Connect request */
    PICC_LINK_DISCONNECT    = 0x02U,  /**< Disconnect notification */
    PICC_LINK_RECONNECT     = 0x03U   /**< Reconnect notification (Server restart) */
} PICC_LinkSubType_e;

/**
 * @brief Communication media type
 */
typedef enum {
    PICC_MEDIA_IPCF         = 0x00U,  /**< IPCF shared memory */
    PICC_MEDIA_LOCAL        = 0x01U,  /**< Local socket */
    PICC_MEDIA_ETH          = 0x02U   /**< Ethernet */
} PICC_MediaType_e;

/**
 * @brief Heartbeat message type
 */
typedef enum {
    PICC_HEARTBEAT_PING     = 0x01U,  /**< Ping */
    PICC_HEARTBEAT_PONG     = 0x02U   /**< Pong */
} PICC_HeartbeatType_e;

/**
 * @brief Role type (Client/Server)
 */
typedef enum {
    PICC_ROLE_CLIENT = 0U,  /**< Client role */
    PICC_ROLE_SERVER        /**< Server role */
} PICC_Role_e;

/*==================================================================================================
 *                                         Structure Definitions
 *==================================================================================================*/

/**
 * @brief Protocol message header structure (8 bytes, big-endian)
 * 
 * Byte order:
 * [0] ProviderID  [1] MethodID  [2] ConsumerID  [3] SessionID
 * [4] MessageType [5] ReturnCode [6-7] Length (big-endian)
 */
#if defined(__GNUC__) || defined(__ghs__)
typedef struct __attribute__((packed)) {
#else
#pragma pack(push, 1)
typedef struct {
#endif
    uint8  providerId;      /**< Service provider ID (0x01-0xFE valid) */
    uint8  methodId;        /**< Service/Method ID (0x01-0xFE valid) */
    uint8  consumerId;      /**< Client ID (0x01-0xFE valid) */
    uint8  sessionId;       /**< Session ID (0x01-0xFF) */
    uint8  msgType;         /**< Message type @see PICC_MsgType_e */
    uint8  returnCode;      /**< Return code @see PICC_ReturnCode_e */
    uint16 length;          /**< Payload length (big-endian byte order) */
#if defined(__GNUC__) || defined(__ghs__)
} PICC_MsgHeader_t;
#else
} PICC_MsgHeader_t;
#pragma pack(pop)
#endif

/**
 * @brief Complete message structure
 */
typedef struct {
    PICC_MsgHeader_t header;                        /**< Protocol header */
    uint8            payload[PICC_MAX_PAYLOAD_SIZE]; /**< Data payload */
} PICC_Message_t;

/**
 * @brief Link request/response Payload structure
 */
typedef struct {
    uint8 subType;          /**< Link subtype @see PICC_LinkSubType_e */
    uint8 clientId;         /**< Client ID */
    uint8 mediaType;        /**< Communication media @see PICC_MediaType_e */
    uint8 serverId;         /**< Server ID */
} PICC_LinkPayload_t;

/*==================================================================================================
 *                                         CRC16 Related
 *==================================================================================================*/

/** CRC16 XOR value */
#define PICC_CRC16_XOR_VALUE     (0x0000U)

/** CRC16 start value */
#define PICC_CRC16_START_VALUE   (0xFFFFU)

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Calculate CRC16 checksum
 * 
 * @param[in] data       Data buffer
 * @param[in] len        Data length
 * @param[in] isFirst    Whether first call
 * @param[in] startValue Start value (used for non-first call)
 * @return CRC16 checksum value
 */
uint16 PICC_CalculateCRC16(const uint8 *data, uint32 len, boolean isFirst, uint16 startValue);

/**
 * @brief Calculate CRC16 checksum (simplified interface)
 * 
 * @param[in] data Data buffer
 * @param[in] len  Data length
 * @return CRC16 checksum value
 */
uint16 PICC_CRC16(const uint8 *data, uint32 len);

/**
 * @brief Pack protocol message
 * 
 * @param[out] outBuf       Output buffer
 * @param[in]  outBufSize   Output buffer size
 * @param[in]  header       Protocol header
 * @param[in]  payload      Payload data (can be NULL)
 * @param[in]  payloadLen   Payload length
 * @return Total length after packing, returns 0 on failure
 */
uint32 PICC_PackMessage(uint8 *outBuf, uint32 outBufSize,
                        const PICC_MsgHeader_t *header,
                        const uint8 *payload, uint16 payloadLen);

/**
 * @brief Unpack protocol message
 * 
 * @param[in]  inBuf        Input buffer
 * @param[in]  inLen        Input length
 * @param[out] header       Parsed protocol header
 * @param[out] payload      Payload data pointer (points to position in inBuf)
 * @param[out] payloadLen   Payload length
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_UnpackMessage(const uint8 *inBuf, uint32 inLen,
                         PICC_MsgHeader_t *header,
                         const uint8 **payload, uint16 *payloadLen);

/**
 * @brief Convert 16-bit big-endian to local byte order
 */
uint16 PICC_BeToCpu16(uint16 value);

/**
 * @brief Convert 16-bit local to big-endian byte order
 */
uint16 PICC_CpuToBe16(uint16 value);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_PROTOCOL_H */
