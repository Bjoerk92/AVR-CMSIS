cmake_minimum_required(VERSION 3.14)

set(TARGET_CHIP "Atmega328p" CACHE STRING "AVR chip to build for")

add_library(DRIVER
    Pins.c
)

target_link_libraries(DRIVER PUBLIC
    CMSIS
)