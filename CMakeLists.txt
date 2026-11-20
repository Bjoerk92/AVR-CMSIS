cmake_minimum_required(VERSION 3.20)

option(BUILD_TARGET_TEST "Build target test firmware" ON)

if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/toolchain/avr-toolchain.cmake" CACHE FILEPATH "AVR toolchain file")
endif()

project(CMSIS VERSION 1.0.0.0 LANGUAGES C CXX ASM)

if(BUILD_TARGET_TEST)
    set(TARGET "Arduino" CACHE STRING "Driver target to build")
endif()


add_subdirectory(Drivers)
add_subdirectory(CMSIS)

if(BUILD_TARGET_TEST)
    add_subdirectory(Test)
endif()
