cmake_minimum_required(VERSION 3.20)

if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/toolchain/avr-toolchain.cmake" CACHE FILEPATH "AVR toolchain file")
endif()

set(TARGET "Arduino" CACHE STRING "Driver target to build")

project(CMSIS VERSION 1.0.0.0 LANGUAGES C CXX ASM)

add_subdirectory(Drivers)
add_subdirectory(CMSIS)
