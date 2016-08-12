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

# include <inttypes.h>
# include <string.h>
# include "platform/stdio.h"
# include "kaa_remote_control_ecf_definitions.h"
# include "avro_src/avro/io.h"
# include "avro_src/encoding.h"
# include "utilities/kaa_mem.h"

/*
 * AUTO-GENERATED CODE
 */




static void kaa_remote_control_ecf_gpio_status_serialize(avro_writer_t writer, void *data)
{
    if (data) {
        kaa_remote_control_ecf_gpio_status_t *record = (kaa_remote_control_ecf_gpio_status_t *)data;

        kaa_int_serialize(writer, &record->id);
        kaa_boolean_serialize(writer, &record->status);
    }
}

static size_t kaa_remote_control_ecf_gpio_status_get_size(void *data)
{
    if (data) {
        size_t record_size = 0;
        kaa_remote_control_ecf_gpio_status_t *record = (kaa_remote_control_ecf_gpio_status_t *)data;

        record_size += kaa_int_get_size(&record->id);
        record_size += kaa_boolean_get_size(&record->status);

        return record_size;
    }

    return 0;
}

kaa_remote_control_ecf_gpio_status_t *kaa_remote_control_ecf_gpio_status_create(void)
{
    kaa_remote_control_ecf_gpio_status_t *record = 
            (kaa_remote_control_ecf_gpio_status_t *)KAA_CALLOC(1, sizeof(kaa_remote_control_ecf_gpio_status_t));

    if (record) {
        record->serialize = kaa_remote_control_ecf_gpio_status_serialize;
        record->get_size = kaa_remote_control_ecf_gpio_status_get_size;
        record->destroy = kaa_data_destroy;
    }

    return record;
}

kaa_remote_control_ecf_gpio_status_t *kaa_remote_control_ecf_gpio_status_deserialize(avro_reader_t reader)
{
    kaa_remote_control_ecf_gpio_status_t *record = 
            (kaa_remote_control_ecf_gpio_status_t *)KAA_MALLOC(sizeof(kaa_remote_control_ecf_gpio_status_t));

    if (record) {
        record->serialize = kaa_remote_control_ecf_gpio_status_serialize;
        record->get_size = kaa_remote_control_ecf_gpio_status_get_size;
        record->destroy = kaa_data_destroy;

        avro_binary_encoding.read_int(reader, &record->id);
        avro_binary_encoding.read_boolean(reader, &record->status);
    }

    return record;
}





kaa_remote_control_ecf_device_info_request_t *kaa_remote_control_ecf_device_info_request_create(void)
{
    kaa_remote_control_ecf_device_info_request_t *record = 
            (kaa_remote_control_ecf_device_info_request_t *)KAA_CALLOC(1, sizeof(kaa_remote_control_ecf_device_info_request_t));

    if (record) {
        record->serialize = kaa_null_serialize;
        record->get_size = kaa_null_get_size;
        record->destroy = kaa_data_destroy;
    }

    return record;
}

kaa_remote_control_ecf_device_info_request_t *kaa_remote_control_ecf_device_info_request_deserialize(avro_reader_t reader)
{
    kaa_remote_control_ecf_device_info_request_t *record = 
            (kaa_remote_control_ecf_device_info_request_t *)KAA_MALLOC(sizeof(kaa_remote_control_ecf_device_info_request_t));

    if (record) {
        record->serialize = kaa_null_serialize;
        record->get_size = kaa_null_get_size;
        record->destroy = kaa_data_destroy;

    }

    return record;
}



static void kaa_remote_control_ecf_device_info_response_destroy(void *data)
{
    if (data) {
        kaa_remote_control_ecf_device_info_response_t *record = (kaa_remote_control_ecf_device_info_response_t *)data;

        kaa_string_destroy(record->model);
        kaa_string_destroy(record->device_name);
                    kaa_list_destroy(record->gpio_status, kaa_data_destroy);
                kaa_data_destroy(record);
    }
}

static void kaa_remote_control_ecf_device_info_response_serialize(avro_writer_t writer, void *data)
{
    if (data) {
        kaa_remote_control_ecf_device_info_response_t *record = (kaa_remote_control_ecf_device_info_response_t *)data;

        kaa_string_serialize(writer, record->model);
        kaa_string_serialize(writer, record->device_name);
                    kaa_array_serialize(writer, record->gpio_status, kaa_remote_control_ecf_gpio_status_serialize);
                }
}

static size_t kaa_remote_control_ecf_device_info_response_get_size(void *data)
{
    if (data) {
        size_t record_size = 0;
        kaa_remote_control_ecf_device_info_response_t *record = (kaa_remote_control_ecf_device_info_response_t *)data;

        record_size += kaa_string_get_size(record->model);
        record_size += kaa_string_get_size(record->device_name);
                    record_size += kaa_array_get_size(record->gpio_status, kaa_remote_control_ecf_gpio_status_get_size);
            
        return record_size;
    }

    return 0;
}

kaa_remote_control_ecf_device_info_response_t *kaa_remote_control_ecf_device_info_response_create(void)
{
    kaa_remote_control_ecf_device_info_response_t *record;// = 
            //(kaa_remote_control_ecf_device_info_response_t *)KAA_CALLOC(1, sizeof(kaa_remote_control_ecf_device_info_response_t));

    if (record) {
        record->serialize = kaa_remote_control_ecf_device_info_response_serialize;
        record->get_size = kaa_remote_control_ecf_device_info_response_get_size;
        record->destroy = kaa_remote_control_ecf_device_info_response_destroy;
    }

    return record;
}

kaa_remote_control_ecf_device_info_response_t *kaa_remote_control_ecf_device_info_response_deserialize(avro_reader_t reader)
{
    kaa_remote_control_ecf_device_info_response_t *record = 
            (kaa_remote_control_ecf_device_info_response_t *)KAA_MALLOC(sizeof(kaa_remote_control_ecf_device_info_response_t));

    if (record) {
        record->serialize = kaa_remote_control_ecf_device_info_response_serialize;
        record->get_size = kaa_remote_control_ecf_device_info_response_get_size;
        record->destroy = kaa_remote_control_ecf_device_info_response_destroy;

        record->model = kaa_string_deserialize(reader);
        record->device_name = kaa_string_deserialize(reader);
            record->gpio_status = kaa_array_deserialize_wo_ctx(reader, (deserialize_wo_ctx_fn)kaa_remote_control_ecf_gpio_status_deserialize);
        }

    return record;
}



static void kaa_remote_control_ecf_gpio_toggle_request_destroy(void *data)
{
    if (data) {
        kaa_remote_control_ecf_gpio_toggle_request_t *record = (kaa_remote_control_ecf_gpio_toggle_request_t *)data;

        if (record->gpio && record->gpio->destroy) {
            record->gpio->destroy(record->gpio);
        }
        kaa_data_destroy(record);
    }
}

static void kaa_remote_control_ecf_gpio_toggle_request_serialize(avro_writer_t writer, void *data)
{
    if (data) {
        kaa_remote_control_ecf_gpio_toggle_request_t *record = (kaa_remote_control_ecf_gpio_toggle_request_t *)data;

        record->gpio->serialize(writer, record->gpio);
    }
}

static size_t kaa_remote_control_ecf_gpio_toggle_request_get_size(void *data)
{
    if (data) {
        size_t record_size = 0;
        kaa_remote_control_ecf_gpio_toggle_request_t *record = (kaa_remote_control_ecf_gpio_toggle_request_t *)data;

        record_size += record->gpio->get_size(record->gpio);

        return record_size;
    }

    return 0;
}

kaa_remote_control_ecf_gpio_toggle_request_t *kaa_remote_control_ecf_gpio_toggle_request_create(void)
{
    kaa_remote_control_ecf_gpio_toggle_request_t *record = 
            (kaa_remote_control_ecf_gpio_toggle_request_t *)KAA_CALLOC(1, sizeof(kaa_remote_control_ecf_gpio_toggle_request_t));

    if (record) {
        record->serialize = kaa_remote_control_ecf_gpio_toggle_request_serialize;
        record->get_size = kaa_remote_control_ecf_gpio_toggle_request_get_size;
        record->destroy = kaa_remote_control_ecf_gpio_toggle_request_destroy;
    }

    return record;
}

kaa_remote_control_ecf_gpio_toggle_request_t *kaa_remote_control_ecf_gpio_toggle_request_deserialize(avro_reader_t reader)
{
    kaa_remote_control_ecf_gpio_toggle_request_t *record = 
            (kaa_remote_control_ecf_gpio_toggle_request_t *)KAA_MALLOC(sizeof(kaa_remote_control_ecf_gpio_toggle_request_t));

    if (record) {
        record->serialize = kaa_remote_control_ecf_gpio_toggle_request_serialize;
        record->get_size = kaa_remote_control_ecf_gpio_toggle_request_get_size;
        record->destroy = kaa_remote_control_ecf_gpio_toggle_request_destroy;

        record->gpio = kaa_remote_control_ecf_gpio_status_deserialize(reader);
    }

    return record;
}

