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

# include <stdint.h>
# include "kaa_remote_control_ecf.h"

# include "avro_src/avro/io.h"

# include "kaa_common.h"
# include "kaa_event.h"
# include "kaa_error.h"
# include "utilities/kaa_mem.h"

# include "kaa_private.h"

# ifdef kaa_broadcast_event
# undef kaa_broadcast_event
# endif
# define kaa_broadcast_event(context, fqn, fqn_length, event_data, event_data_size) \
    kaa_event_manager_send_event((context), (fqn), (fqn_length), (event_data), (event_data_size), NULL, 0)


typedef struct kaa_remote_control_ecf_ {

    on_kaa_remote_control_ecf_device_info_request device_info_request_listener;
    void * device_info_request_context;
    on_kaa_remote_control_ecf_gpio_toggle_request gpio_toggle_request_listener;
    void * gpio_toggle_request_context;

    unsigned char is_device_info_request_callback_added;
    unsigned char is_gpio_toggle_request_callback_added;

} kaa_remote_control_ecf;

static kaa_remote_control_ecf listeners = {

    NULL, NULL,
    NULL, NULL,

    0
,
    0

};

static void kaa_event_manager_device_info_request_listener(const char * event_fqn, const char *data, size_t size, kaa_endpoint_id_p event_source)
{
    (void)event_fqn;
    if (listeners.device_info_request_listener) {
        avro_reader_t reader = avro_reader_memory(data, size);
        kaa_remote_control_ecf_device_info_request_t * event = kaa_remote_control_ecf_device_info_request_deserialize(reader);
        avro_reader_free(reader);
        listeners.device_info_request_listener(listeners.device_info_request_context, event, event_source);
    }
}

kaa_error_t kaa_event_manager_set_kaa_remote_control_ecf_device_info_request_listener(kaa_event_manager_t *self, on_kaa_remote_control_ecf_device_info_request listener, void *context)
{
    KAA_RETURN_IF_NIL(self, KAA_ERR_BADPARAM);
    listeners.device_info_request_listener = listener;
    listeners.device_info_request_context = context;
    if (!listeners.is_device_info_request_callback_added) {
        listeners.is_device_info_request_callback_added = 1;
        return kaa_event_manager_add_on_event_callback(self, "org.kaaproject.kaa.examples.gpiocontrol.DeviceInfoRequest", kaa_event_manager_device_info_request_listener);
    }
    return KAA_ERR_NONE;
}

static void kaa_event_manager_gpio_toggle_request_listener(const char * event_fqn, const char *data, size_t size, kaa_endpoint_id_p event_source)
{
    (void)event_fqn;
    if (listeners.gpio_toggle_request_listener) {
        avro_reader_t reader = avro_reader_memory(data, size);
        kaa_remote_control_ecf_gpio_toggle_request_t * event = kaa_remote_control_ecf_gpio_toggle_request_deserialize(reader);
        avro_reader_free(reader);
        listeners.gpio_toggle_request_listener(listeners.gpio_toggle_request_context, event, event_source);
    }
}

kaa_error_t kaa_event_manager_set_kaa_remote_control_ecf_gpio_toggle_request_listener(kaa_event_manager_t *self, on_kaa_remote_control_ecf_gpio_toggle_request listener, void *context)
{
    KAA_RETURN_IF_NIL(self, KAA_ERR_BADPARAM);
    listeners.gpio_toggle_request_listener = listener;
    listeners.gpio_toggle_request_context = context;
    if (!listeners.is_gpio_toggle_request_callback_added) {
        listeners.is_gpio_toggle_request_callback_added = 1;
        return kaa_event_manager_add_on_event_callback(self, "org.kaaproject.kaa.examples.gpiocontrol.GpioToggleRequest", kaa_event_manager_gpio_toggle_request_listener);
    }
    return KAA_ERR_NONE;
}


kaa_error_t kaa_event_manager_send_kaa_remote_control_ecf_device_info_response(kaa_event_manager_t *self, kaa_remote_control_ecf_device_info_response_t *event, kaa_endpoint_id_p target)
{
    KAA_RETURN_IF_NIL2(self, event, KAA_ERR_BADPARAM);
    size_t event_size = event->get_size(event);
    char *buffer = (char *)KAA_MALLOC((event_size) * sizeof(char));
    KAA_RETURN_IF_NIL(buffer, KAA_ERR_NOMEM);
    avro_writer_t writer = avro_writer_memory(buffer, event_size);
    if (!writer) {
        KAA_FREE(buffer);
        return KAA_ERR_NOMEM;
    }
    event->serialize(writer, event);
    kaa_error_t result = kaa_event_manager_send_event(self, "org.kaaproject.kaa.examples.gpiocontrol.DeviceInfoResponse", writer->buf, writer->written, target);
    avro_writer_free(writer);
    return result;
}


kaa_error_t kaa_event_manager_add_kaa_remote_control_ecf_device_info_response_event_to_block(kaa_event_manager_t *self, kaa_remote_control_ecf_device_info_response_t *event, kaa_endpoint_id_p target, kaa_event_block_id trx_id)
{
    KAA_RETURN_IF_NIL2(self, event, KAA_ERR_BADPARAM);
    size_t event_size = event->get_size(event);
    char *buffer = (char *)KAA_MALLOC((event_size) * sizeof(char));
    KAA_RETURN_IF_NIL(buffer, KAA_ERR_NOMEM);
    avro_writer_t writer = avro_writer_memory(buffer, event_size);
    if (!writer) {
        KAA_FREE(buffer);
        return KAA_ERR_NOMEM;
    }
    event->serialize(writer, event);
    kaa_error_t result = kaa_event_manager_add_event_to_transaction(self, trx_id, "org.kaaproject.kaa.examples.gpiocontrol.DeviceInfoResponse", writer->buf, writer->written, target);
    avro_writer_free(writer);
    return result;
}

