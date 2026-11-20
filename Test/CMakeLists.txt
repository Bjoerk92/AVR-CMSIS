set(TARGET "Arduino" CACHE STRING "Driver target to build")

add_executable(target_test_blinky
    Blinky.c
)

target_link_libraries(target_test_blinky PRIVATE

    DRIVER
)

set_target_properties(target_test_blinky PROPERTIES
    SUFFIX ".elf"
)

add_custom_target(strip ALL
    COMMAND "${CMAKE_STRIP}" "$<TARGET_FILE:target_test_blinky>"
    DEPENDS target_test_blinky
    VERBATIM
)

add_custom_target(hex ALL
    COMMAND "${CMAKE_OBJCOPY}" -R .eeprom -O ihex
        "$<TARGET_FILE:target_test_blinky>"
        "${CMAKE_CURRENT_BINARY_DIR}/target_test_blinky.hex"
    DEPENDS strip
    BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/target_test_blinky.hex"
    VERBATIM
)

add_custom_target(eeprom
    COMMAND "${CMAKE_OBJCOPY}" -j .eeprom --change-section-lma .eeprom=0 -O ihex
        "$<TARGET_FILE:target_test_blinky>"
        "${CMAKE_CURRENT_BINARY_DIR}/target_test_blinky.eeprom"
    DEPENDS strip
    BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/target_test_blinky.eeprom"
    VERBATIM
)
