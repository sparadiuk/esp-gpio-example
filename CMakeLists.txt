#
#  Copyright 2014-2016 CyberVision, Inc.
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#

cmake_minimum_required(VERSION 2.8.8)

project (C-SDK-sample)
enable_language(C)


# search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# avoid using any additional flags when linking with shared libraries
#without this line, we get an rpath error
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

set(KAA_SDK_ROOT libs/kaa/src/)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Os -Wall -Wextra")

if(NOT DEFINED ESPRESSIF_HOME)
    set(ESPRESSIF_HOME /opt/Espressif)
endif()
    
set(ESP_TOOLCHAIN_DIR ${ESPRESSIF_HOME}/crosstool-NG/builds/xtensa-lx106-elf/bin)

set(ESP_SDK_BASE ${ESPRESSIF_HOME}/esp-rtos-sdk)

set(ESP8266_SRC user/user_main.c driver/uart.c blank.c)

set(ESP8266_LIBS "-lfreertos -lhal -lgcc -lpp -lphy -lnet80211 -lwpa -llwip -lmain")

set(ESP8266_INCDIRS ${ESP_SDK_BASE}/extra_include ${ESP_SDK_BASE}/include ${ESP_SDK_BASE}/include/lwip ${ESP_SDK_BASE}/include/lwip/ipv4 ${ESP_SDK_BASE}/include/lwip/ipv6 ${ESP_SDK_BASE}/include/espressif/ )

set(ESP8266_LINKSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/ld/eagle.app.v6.ld)

set(ESP8266_LIBDIR "-L${CMAKE_CURRENT_SOURCE_DIR}/build -L${ESP_TOOLCHAIN_DIR}/../lib/gcc/xtensa-lx106-elf/4.8.2/ ")
                    
set(ESP8266_LIBDIR "${ESP8266_LIBDIR} -L${ESP_SDK_BASE}/lib -L${CMAKE-CMAKE_CURRENT_SOURCE_DIR} -L${ESP_TOOLCHAIN_DIR}/ld")

set(ESP8266_LDFLAGS "${ESP8266_LIBDIR} -T${ESP8266_LINKSCRIPT} -nostdlib -u call_user_start -static --start-group ${ESP8266_LIBS} -lesp-platform --end-group --gc-sections -Map map")

set(CMAKE_AR ${ESP_TOOLCHAIN_DIR}/xtensa-lx106-elf-ar)

set(CMAKE_RANLIB ${ESP_TOOLCHAIN_DIR}/xtensa-lx106-elf-ranlib)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DESP8266_PLATFORM -Os -Wpointer-arith -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -D__ets__ -DICACHE_FLASH")

#WiFi SSID and PASSWORD
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSSID='\"${SSID}\"' -DPWD='\"${PWD}\"' -DDEMO_ACCESS_TOKEN='\"${DEMO_ACCESS_TOKEN}\"'")

#TODO(APP-88): Merge gpio demos into single one
set(CMAKE_C_LINK_FLAGS "${ESP8266_LDFLAGS}")
set(CMAKE_C_LINKER "${ESP_TOOLCHAIN_DIR}/xtensa-lx106-elf-ld")
set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_C_LINKER} <OBJECTS> <LINK_LIBRARIES> <CMAKE_C_LINK_FLAGS> -o <TARGET>")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src
#					${KAA_SDK_ROOT}/kaa/
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/src/kaa/platform-impl/esp8266/ 
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/src/kaa/ 
                    ${CMAKE_CURRENT_SOURCE_DIR}/build/libs/kaa/ 
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/src/extensions/user/
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/src/extensions/profile/
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/src/extensions/event/
                    ${KAA_SDK_ROOT}
                    ${ESP8266_INCDIRS}
                   )
add_library(esp-platform STATIC ${ESP8266_SRC})
#add_library(${APP_NAME} blank.c)
add_executable(${APP_NAME} src/kaa_demo.c driver/gpio.c)
add_subdirectory(libs/kaa)
target_link_libraries(${APP_NAME} PRIVATE esp-platform kaac)
add_custom_command(TARGET ${APP_NAME}
                   POST_BUILD
                   COMMAND esptool.py elf2image -o ./ ${APP_NAME}
                   & echo "Making firmware image"
                  )
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ESP8266_LDFLAGS} -o ${APP_NAME}")
