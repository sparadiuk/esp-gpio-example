/*
 * Copyright 2014-2016 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

# ifndef KAA_REMOTE_CONTROL_ECF_DEFINITIONS_H_
# define KAA_REMOTE_CONTROL_ECF_DEFINITIONS_H_

# include "kaa_common_schema.h"
# include "collections/kaa_list.h"

# ifdef __cplusplus
extern "C" {
# endif



typedef struct {
    int32_t id;
    int8_t status;

    serialize_fn serialize;
    get_size_fn  get_size;
    destroy_fn   destroy;
} kaa_remote_control_ecf_gpio_status_t;

kaa_remote_control_ecf_gpio_status_t *kaa_remote_control_ecf_gpio_status_create(void);
kaa_remote_control_ecf_gpio_status_t *kaa_remote_control_ecf_gpio_status_deserialize(avro_reader_t reader);



typedef struct {

    serialize_fn serialize;
    get_size_fn  get_size;
    destroy_fn   destroy;
} kaa_remote_control_ecf_device_info_request_t;

kaa_remote_control_ecf_device_info_request_t *kaa_remote_control_ecf_device_info_request_create(void);
kaa_remote_control_ecf_device_info_request_t *kaa_remote_control_ecf_device_info_request_deserialize(avro_reader_t reader);



typedef struct {
    kaa_string_t * model;
    kaa_string_t * device_name;
    kaa_list_t * gpio_status;

    serialize_fn serialize;
    get_size_fn  get_size;
    destroy_fn   destroy;
} kaa_remote_control_ecf_device_info_response_t;

kaa_remote_control_ecf_device_info_response_t *kaa_remote_control_ecf_device_info_response_create(void);
kaa_remote_control_ecf_device_info_response_t *kaa_remote_control_ecf_device_info_response_deserialize(avro_reader_t reader);



typedef struct {
    kaa_remote_control_ecf_gpio_status_t * gpio;

    serialize_fn serialize;
    get_size_fn  get_size;
    destroy_fn   destroy;
} kaa_remote_control_ecf_gpio_toggle_request_t;

kaa_remote_control_ecf_gpio_toggle_request_t *kaa_remote_control_ecf_gpio_toggle_request_create(void);
kaa_remote_control_ecf_gpio_toggle_request_t *kaa_remote_control_ecf_gpio_toggle_request_deserialize(avro_reader_t reader);

#ifdef __cplusplus
}      /* extern "C" */
#endif
#endif