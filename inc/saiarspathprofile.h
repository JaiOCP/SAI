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
 * @file    saiarspathprofile.h
 *
 * @brief   This module defines SAI interface for adaptive routing and switching
 */

#if !defined (__SAIARSPATHPROFILE_H_)
#define __SAIARSPATHPROFILE_H_

#include <saitypes.h>

/**
 * @defgroup SAIARSPATHPROFILE SAI - Adaptive Routing and Switching path quality profile specific API definitions
 *
 * @{
 */

/**
 * @brief Adaptive routing and switching path profile type
 */
typedef enum _sai_ars_path_profile_type_t
{
    /** Publisher of ARS messages */
    SAI_ARS_PATH_PROFILE_TYPE_PUBLISHER,

    /** Subscriber of ARS messages */
    SAI_ARS_PATH_PROFILE_TYPE_SUBSCRIBER,

    /** Publisher and Subscriber of ARS messages */
    SAI_ARS_PATH_PROFILE_TYPE_BOTH,

    /** No action of ARS messages */
    SAI_ARS_PATH_PROFILE_TYPE_NONE,

} sai_ars_path_profile_type_t;

/**
 * @brief Attribute id for ARS path profile
 */
typedef enum _sai_ars_path_profile_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ARS_PATH_PROFILE_ATTR_START,

    /**
     * @brief ARS profile type
     *
     * @type sai_ars_path_profile_type_t
     * @flags CREATE_AND_SET
     * @default SAI_ARS_PATH_PROFILE_TYPE_NONE
     */
    SAI_ARS_PATH_PROFILE_ATTR_TYPE = SAI_ARS_PATH_PROFILE_ATTR_START,

    /**
     * @brief Monitoring ports for publisher
     *
     * @type sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT
     * @default empty
     * @validonly SAI_ARS_PATH_PROFILE_ATTR_TYPE == SAI_ARS_PATH_PROFILE_TYPE_PUBLISHER or SAI_ARS_PATH_PROFILE_ATTR_TYPE == SAI_ARS_PATH_PROFILE_TYPE_BOTH
     */
    SAI_ARS_PATH_PROFILE_ATTR_MON_PORT_LIST,

    /**
     * @brief Publish set of ports
     *
     * @type sai_object_list_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_PORT
     * @default empty
     * @validonly SAI_ARS_PATH_PROFILE_ATTR_TYPE == SAI_ARS_PATH_PROFILE_TYPE_PUBLISHER or SAI_ARS_PATH_PROFILE_ATTR_TYPE == SAI_ARS_PATH_PROFILE_TYPE_BOTH
     */
    SAI_ARS_PATH_PROFILE_ATTR_PUB_PORT_LIST,

    /**
     * @brief Remote switch identifier list
     *
     * @type sai_u32_list_t
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_ARS_PATH_PROFILE_ATTR_REMOTE_PATH_ID_LIST,

    /**
     * @brief End of attributes
     */
    SAI_ARS_PATH_PROFILE_ATTR_END,

    /** Custom range base value */
    SAI_ARS_PATH_PROFILE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_ARS_PATH_PROFILE_ATTR_CUSTOM_RANGE_END

} sai_ars_path_profile_attr_t;

/**
 * @brief Create ARS path profile object
 *
 * @param[out] ars_path_profile_id ARS path profile id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_ars_path_profile_fn)(
        _Out_ sai_object_id_t *ars_path_profile_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove ARS path profile object
 *
 * @param[in] ars_path_profile_id ARS path profile id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_ars_path_profile_fn)(
        _In_ sai_object_id_t ars_path_profile_id);

/**
 * @brief Set ARS path profile attribute
 *
 * @param[in] ars_path_profile_id ARS path profile id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_ars_path_profile_attribute_fn)(
        _In_ sai_object_id_t ars_path_profile_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ARS path profile attribute
 *
 * @param[in] ars_path_profile_id ARS path profile id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ars_path_profile_attribute_fn)(
        _In_ sai_object_id_t ars_path_profile_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief ARS path profile methods table retrieved with sai_api_query()
 */
typedef struct _sai_ars_path_profile_api_t
{
    sai_create_ars_path_profile_fn               create_ars_path_profile;
    sai_remove_ars_path_profile_fn               remove_ars_path_profile;
    sai_set_ars_path_profile_attribute_fn        set_ars_path_profile_attribute;
    sai_get_ars_path_profile_attribute_fn        get_ars_path_profile_attribute;
} sai_ars_path_profile_api_t;

/**
 * @}
 */
#endif /** __SAIARSPATHPROFILE_H_ */
