cmake_minimum_required(VERSION 3.20)

add_library(CMSIS INTERFACE)

target_include_directories(CMSIS INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}/Core"
    "${CMAKE_CURRENT_LIST_DIR}/Driver"
    "${CMAKE_CURRENT_LIST_DIR}/Driver/Drivers"
)

if(TARGET_CHIP STREQUAL "Atmega328p")
    target_include_directories(CMSIS INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/Devices/Atmega328p"
    )
elseif(TARGET_CHIP STREQUAL "Atmega2560")
    target_include_directories(CMSIS INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/Devices/Atmega2560"
    )
else()
    message(FATAL_ERROR "Unsupported TARGET_CHIP: ${TARGET_CHIP}")
endif()