#
#    Copyright (c) 2023 Project CHIP Authors
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#
cmake_minimum_required(VERSION 3.13.1)

get_filename_component(CHIP_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/third_party/connectedhomeip REALPATH)
get_filename_component(GEN_DIR ${CHIP_ROOT}/zzz_generated/ REALPATH)
get_filename_component(APP_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/.. REALPATH)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/boards/${BOARD}.overlay")
  set(LOCAL_DTC_OVERLAY_FILE "${CMAKE_CURRENT_SOURCE_DIR}/boards/${BOARD}.overlay")
else()
  unset(LOCAL_DTC_OVERLAY_FILE)
endif()

if(EXISTS "${CHIP_ROOT}/src/platform/telink/${BOARD}.overlay")
  set(GLOBAL_DTC_OVERLAY_FILE "${CHIP_ROOT}/src/platform/telink/${BOARD}.overlay")
else()
  unset(GLOBAL_DTC_OVERLAY_FILE)
endif()

if(EXISTS "${CHIP_ROOT}/src/platform/telink/${FLASH_SIZE}_flash.overlay")
  set(FLASH_DTC_OVERLAY_FILE "${CHIP_ROOT}/src/platform/telink/${FLASH_SIZE}_flash.overlay")
  message(STATUS "Flash memory size is set to: " ${FLASH_SIZE} "b")
else()
  set(FLASH_DTC_OVERLAY_FILE "${CHIP_ROOT}/src/platform/telink/2m_flash.overlay")
  message(STATUS "Flash memory size is set to: 2mb")
endif()

if(DTC_OVERLAY_FILE)
  set(DTC_OVERLAY_FILE
    "${DTC_OVERLAY_FILE} ${GLOBAL_DTC_OVERLAY_FILE} ${FLASH_DTC_OVERLAY_FILE} ${LOCAL_DTC_OVERLAY_FILE}"
    CACHE STRING "" FORCE
  )
else()
  set(DTC_OVERLAY_FILE ${GLOBAL_DTC_OVERLAY_FILE} ${FLASH_DTC_OVERLAY_FILE} ${LOCAL_DTC_OVERLAY_FILE})
endif()

set(CONF_FILE  prj.conf)

# Load NCS/Zephyr build system
list(APPEND ZEPHYR_EXTRA_MODULES ${CHIP_ROOT}/config/telink/chip-module)
find_package(Zephyr HINTS $ENV{ZEPHYR_BASE})

project(chip-telink-shell-example)

include(${CHIP_ROOT}/config/telink/app/enable-gnu-std.cmake)
include(${CHIP_ROOT}/src/app/chip_data_model.cmake)

target_compile_options(app PRIVATE -fpermissive)

target_include_directories(app PRIVATE
                           include
                           ${GEN_DIR}/app-common
                           ${APP_ROOT}/shell_common/include)

add_definitions(
    "-DCHIP_ADDRESS_RESOLVE_IMPL_INCLUDE_HEADER=<lib/address_resolve/AddressResolve_DefaultImpl.h>"
)

target_sources(app PRIVATE
               ${APP_ROOT}/shell_common/globals.cpp
               ${APP_ROOT}/shell_common/cmd_misc.cpp
               ${APP_ROOT}/shell_common/cmd_otcli.cpp
               ${APP_ROOT}/standalone/main.cpp)
