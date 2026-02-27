/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiofh.h
 *
 * @brief   This module defines SAI Optimized Forwarding Header
 */

#if !defined (__SAIOFH_H_)
#define __SAIOFH_H_

#include <saitypes.h>

/**
 * @defgroup SAIOFH SAI - OFH specific API definitions
 *
 * @{
 */

/**
 * @brief OFH types
 */
typedef enum _sai_ofh_type_t
{
    /**
     * @brief AFH Type 1
     */
    SAI_OFH_TYPE_AFH_TYPE_1,

    /**
     * @brief AFH Type 2
     */
    SAI_OFH_TYPE_AFH_TYPE_2,

    /**
     * @brief UFH Type 1
     */
    SAI_OFH_TYPE_UFH_TYPE_1,

    /**
     * @brief UFH Type 2
     */
    SAI_OFH_TYPE_UFH_TYPE_2,
} sai_ofh_type_t;

/**
 * @brief Attribute Id for SAI OFH object
 */
typedef enum _sai_ofh_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OFH_ATTR_START,

    /**
     * @brief Type of OFH header
     *
     * @type sai_ofh_type_t
     * @flags CREATE_ONLY
     * @default SAI_OFH_TYPE_AFH_TYPE_1
     */
    SAI_OFH_ATTR_TYPE = SAI_OFH_ATTR_START,

    /**
     * @brief OFH ether type identifier
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_ETHERTYPE,

    /**
     * @brief OFH AR Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_AR_OFFSET,

    /**
     * @brief OFH AR Field Width in Bits
     * Number of bits are 1. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_AR_WIDTH,

    /**
     * @brief OFH Flow Label Present Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_F_OFFSET,

    /**
     * @brief OFH Flow Label Present Field width in Bits
     * Number of bits are 1. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_F_WIDTH,

    /**
     * @brief OFH Congestion Notification Message Eligible Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_C_OFFSET,

    /**
     * @brief OFH Congestion Notification Message Eligible Field Width in Bits
     * Number of bits are 1. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_C_WIDTH,

    /**
     * @brief OFH Congestion Notification Message Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_CNM_OFFSET,

    /**
     * @brief OFH Congestion Notification Message Field Width in bits
     * Number of bits are 1. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_CNM_WIDTH,

    /**
     * @brief OFH ECN Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_ECN_OFFSET,

    /**
     * @brief OFH ECN Field Width in Bits
     * Number of bits are 2. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_ECN_WIDTH,

    /**
     * @brief OFH DSCP Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_DSCP_OFFSET,

    /**
     * @brief OFH DSCP Field Width in Bits
     * Number of bits are 6. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 6
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_DSCP_WIDTH,

    /**
     * @brief OFH TTL Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_TTL_OFFSET,

    /**
     * @brief OFH TTL Field Width in Bits
     * Number of bits are 4. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_TTL_WIDTH,

    /**
     * @brief OFH Flow Label Field Bit Offset
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_FLOW_LABEL_OFFSET,

    /**
     * @brief OFH Flow Label Field Width in Bits
     * Number of bits are 8. Value of 0 bits means that field is not configured
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     * @validonly SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_1 or SAI_OFH_ATTR_TYPE == SAI_OFH_TYPE_AFH_TYPE_2
     */
    SAI_OFH_ATTR_FLOW_LABEL_WIDTH,

    /**
     * @brief OFH header size
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_OFH_ATTR_HDR_SIZE,

    /**
     * @brief End of attributes
     */
    SAI_OFH_ATTR_END,

    /** Custom range base value */
    SAI_OFH_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OFH_ATTR_CUSTOM_RANGE_END

} sai_ofh_attr_t;

/**
 * @brief Create and return a OFH object
 *
 * @param[out] ofh_id OFH object
 * @param[in] switch_id Switch object id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_ofh_fn)(
        _Out_ sai_object_id_t *ofh_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Deletes a specified OFH object.
 *
 * @param[in] ofh_id OFH object to be removed.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_ofh_fn)(
        _In_ sai_object_id_t ofh_id);

/**
 * @brief Set OFH attribute value(s).
 *
 * @param[in] ofh_id TAM id
 * @param[in] attr Attribute to set
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_ofh_attribute_fn)(
        _In_ sai_object_id_t ofh_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get values for specified OFH attributes.
 *
 * @param[in] ofh_id OFH object id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ofh_attribute_fn)(
        _In_ sai_object_id_t ofh_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief OFH methods table retrieved with sai_api_query()
 */
typedef struct _sai_ofh_api_t
{
    /**
     * @brief SAI OFH API set
     */
    sai_create_ofh_fn                   create_ofh;
    sai_remove_ofh_fn                   remove_ofh;
    sai_set_ofh_attribute_fn            set_ofh_attribute;
    sai_get_ofh_attribute_fn            get_ofh_attribute;
} sai_ofh_api_t;

/**
 * @}
 */
#endif /** __SAIOFH_H_ */
