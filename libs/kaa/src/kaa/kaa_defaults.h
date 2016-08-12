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

# ifndef KAA_DEFAULTS_H_
# define KAA_DEFAULTS_H_

/**
 *
 * DO NOT EDIT THIS FILE. IT IS AUTO-GENERATED.
 *
 */

# include "kaa_common.h"

# ifdef __cplusplus
extern "C" {
# endif

# define KAA_BUILD_VERSION             "0.10.0-SNAPSHOT"
# define KAA_BUILD_COMMIT_HASH         ""

# define KAA_SDK_TOKEN                 "IIAmNNkv17RV0N6xVbmeeNtWZKg"

# define KAA_PROFILE_SCHEMA_VERSION    0

# define DEFAULT_USER_VERIFIER_TOKEN    "20241566954312106880"

# define KAA_SYNC_TIMEOUT               60000L


/**
 * @brief Uses to represent transport-specific connection data to establish
 * connection to Bootstrap servers.
 *
 * @see kaa_transport_protocol_id_t
 * @see kaa_access_point_t
 */
typedef struct {
    kaa_transport_protocol_id_t    protocol_id;
    kaa_access_point_t             access_point;
} kaa_bootstrap_server_connection_data_t;

# define KAA_BOOTSTRAP_ACCESS_POINT_COUNT    2

static const kaa_bootstrap_server_connection_data_t KAA_BOOTSTRAP_ACCESS_POINTS[KAA_BOOTSTRAP_ACCESS_POINT_COUNT] =
{
    {
        { 0xfb9a3cf0, 1 },
        {
            0x929a2016,
            315,
            (char []) {
            0 , 0 , 1 , 38 , 48 , -126 , 1 , 34 , 48 , 13 , 6 , 9 , 42 , -122 , 72 , -122 , -9 , 13 , 1 , 1 , 1 , 5 , 0 , 3 , -126 , 1 , 15 , 0 , 48 , -126 , 1 , 10 , 2 , -126 , 1 , 1 , 0 , -86 , 123 , 93 , 102 , 46 , 22 , 102 , 115 , 71 , 80 , 88 , -61 , 115 , -12 , 29 , 98 , 115 , -59 , 15 , -55 , 22 , -63 , 92 , 49 , -89 , -108 , -87 , 71 , -23 , 124 , 87 , -84 , 58 , 73 , -82 , -91 , -124 , 2 , -47 , -68 , -35 , 101 , -98 , 25 , 56 , 97 , -116 , 30 , 67 , -50 , -25 , 16 , 91 , 127 , -116 , 99 , -125 , 7 , 78 , 47 , -28 , 120 , 9 , -127 , -100 , -19 , 111 , -56 , 108 , 85 , -5 , -101 , 85 , -81 , 107 , -10 , -103 , -77 , 127 , -28 , -126 , -62 , 49 , 41 , 95 , 30 , -47 , -121 , 89 , 98 , -104 , 127 , -21 , -38 , 39 , 52 , 78 , -8 , 110 , 75 , 9 , 78 , 59 , -67 , 53 , -68 , -47 , 5 , 110 , -31 , -116 , 95 , -82 , -34 , 32 , -47 , 98 , 116 , 9 , -35 , -65 , 104 , 106 , 5 , 62 , -11 , 40 , -25 , -101 , 39 , -64 , -75 , 74 , -49 , -27 , 63 , -58 , 61 , 74 , -62 , 17 , 84 , 62 , 37 , -35 , 125 , -69 , -58 , 65 , -83 , 110 , 83 , -116 , 26 , 123 , 15 , 97 , 69 , -89 , 39 , 36 , -104 , 9 , 39 , -76 , -91 , -124 , -74 , -19 , 73 , 115 , 21 , 111 , -122 , -21 , -2 , 85 , -89 , 80 , 111 , -24 , -52 , 91 , 55 , -34 , 16 , 46 , 24 , 77 , 51 , 5 , -33 , -120 , -111 , -7 , 3 , -64 , -7 , 27 , -97 , 86 , -57 , -73 , -22 , 58 , 95 , 85 , -69 , -65 , 117 , -102 , 120 , 64 , 24 , 122 , -112 , -99 , 118 , -89 , 7 , 37 , 114 , 102 , 27 , -93 , -16 , 16 , 41 , 119 , -110 , 44 , -103 , -94 , -12 , -100 , -51 , -89 , 62 , 80 , -84 , -31 , 117 , -89 , -89 , -42 , 8 , 58 , -94 , -62 , 64 , -29 , -11 , 10 , 114 , 121 , 55 , 2 , 3 , 1 , 0 , 1 , 0 , 0 , 0 , 9 , 49 , 48 , 46 , 50 , 46 , 50 , 46 , 56 , 54 , 0 , 0 , 38 , -95             }
        }
    },
    {
        { 0x56c8ff92, 1 },
        {
            0x929a2016,
            315,
            (char []) {
            0 , 0 , 1 , 38 , 48 , -126 , 1 , 34 , 48 , 13 , 6 , 9 , 42 , -122 , 72 , -122 , -9 , 13 , 1 , 1 , 1 , 5 , 0 , 3 , -126 , 1 , 15 , 0 , 48 , -126 , 1 , 10 , 2 , -126 , 1 , 1 , 0 , -86 , 123 , 93 , 102 , 46 , 22 , 102 , 115 , 71 , 80 , 88 , -61 , 115 , -12 , 29 , 98 , 115 , -59 , 15 , -55 , 22 , -63 , 92 , 49 , -89 , -108 , -87 , 71 , -23 , 124 , 87 , -84 , 58 , 73 , -82 , -91 , -124 , 2 , -47 , -68 , -35 , 101 , -98 , 25 , 56 , 97 , -116 , 30 , 67 , -50 , -25 , 16 , 91 , 127 , -116 , 99 , -125 , 7 , 78 , 47 , -28 , 120 , 9 , -127 , -100 , -19 , 111 , -56 , 108 , 85 , -5 , -101 , 85 , -81 , 107 , -10 , -103 , -77 , 127 , -28 , -126 , -62 , 49 , 41 , 95 , 30 , -47 , -121 , 89 , 98 , -104 , 127 , -21 , -38 , 39 , 52 , 78 , -8 , 110 , 75 , 9 , 78 , 59 , -67 , 53 , -68 , -47 , 5 , 110 , -31 , -116 , 95 , -82 , -34 , 32 , -47 , 98 , 116 , 9 , -35 , -65 , 104 , 106 , 5 , 62 , -11 , 40 , -25 , -101 , 39 , -64 , -75 , 74 , -49 , -27 , 63 , -58 , 61 , 74 , -62 , 17 , 84 , 62 , 37 , -35 , 125 , -69 , -58 , 65 , -83 , 110 , 83 , -116 , 26 , 123 , 15 , 97 , 69 , -89 , 39 , 36 , -104 , 9 , 39 , -76 , -91 , -124 , -74 , -19 , 73 , 115 , 21 , 111 , -122 , -21 , -2 , 85 , -89 , 80 , 111 , -24 , -52 , 91 , 55 , -34 , 16 , 46 , 24 , 77 , 51 , 5 , -33 , -120 , -111 , -7 , 3 , -64 , -7 , 27 , -97 , 86 , -57 , -73 , -22 , 58 , 95 , 85 , -69 , -65 , 117 , -102 , 120 , 64 , 24 , 122 , -112 , -99 , 118 , -89 , 7 , 37 , 114 , 102 , 27 , -93 , -16 , 16 , 41 , 119 , -110 , 44 , -103 , -94 , -12 , -100 , -51 , -89 , 62 , 80 , -84 , -31 , 117 , -89 , -89 , -42 , 8 , 58 , -94 , -62 , 64 , -29 , -11 , 10 , 114 , 121 , 55 , 2 , 3 , 1 , 0 , 1 , 0 , 0 , 0 , 9 , 49 , 48 , 46 , 50 , 46 , 50 , 46 , 56 , 54 , 0 , 0 , 38 , -96             }
        }
    }};



# define KAA_CONFIGURATION_DATA_LENGTH    17

static const char KAA_CONFIGURATION_DATA[KAA_CONFIGURATION_DATA_LENGTH] =
{
0 , -1 , -112 , 16 , -76 , -57 , -45 , 66 , -33 , -125 , -68 , 43 , 105 , 18 , -32 , -121 , 99 };

# ifdef __cplusplus
} // extern "C"
# endif

# endif /* KAA_DEFAULTS_H_ */
