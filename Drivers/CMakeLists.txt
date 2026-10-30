cmake_minimum_required(VERSION 3.14)

if("${TARGET}" STREQUAL "Arduino")
    add_subdirectory(Arduino_uno)
else()
    message(FATAL_ERROR "Unsupported TARGET: ${TARGET}")
endif()
