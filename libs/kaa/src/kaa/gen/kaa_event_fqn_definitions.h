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

 
 /*
  * This header contains information about all the Event families and
  * events are supported by current SDK.
  */
  
# ifndef KAA_EVENT_FQN_DEFINITIONS_
# define KAA_EVENT_FQN_DEFINITIONS_

# ifdef __cplusplus
extern "C" {
# endif

typedef struct {
    char       *ecf_name;
    size_t      supported_incoming_fqns_count;
    char      **supported_incoming_fqns;
} event_class_family_t;

static const char * RemoteControlECFFQNS[2] = {
                                                    "org.kaaproject.kaa.examples.gpiocontrol.DeviceInfoRequest",
                                                    "org.kaaproject.kaa.examples.gpiocontrol.GpioToggleRequest"};

# define SUPPORTED_EVENT_CLASS_FAMILIES_SIZE 1

static const event_class_family_t SUPPORTED_EVENT_CLASS_FAMILIES[SUPPORTED_EVENT_CLASS_FAMILIES_SIZE] =
{
    {
        /* .ecf_name = */                       "RemoteControlECF",
        /* .supported_incoming_fqns_count = */  2,
        /* .supported_incoming_fqns = */        (char **)RemoteControlECFFQNS
    }
};

# ifdef __cplusplus
}      /* extern "C" */
# endif

# endif