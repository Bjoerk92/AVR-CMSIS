/**
 * @file Pins.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "Driver.h"
#include "stdbool.h"

/******************************************************************************/
/*                  ENUM                                                      */
/******************************************************************************/

/**
 * @brief Enum defining the Pin direction options
 * 
 */
typedef enum PIN_DIR_Etag
{
    PIN_DIR_OUTPUT = 0,
    PIN_DIR_INPUT,
}pin_dir_e;

/**
 * @brief Enum defining the Pin output options.
 * 
 */
typedef enum PIN_OUTPUT_Etag
{
    PIN_LOW = 0,
    PIN_HIGH,
}PIN_OUTPUT_E;

/******************************************************************************/
/*                  PUBLIC FUNCTION                                           */
/******************************************************************************/

/**
 * @brief Function to set a single pins direction
 * 
 * @param pin_number Pin number to set direction
 * @param dir Direction to set
 * @return DRV_STATUS_E 
 */
DRV_STATUS_E Pin_set_direction(uint8_t pin_number, pin_dir_e dir);

/**
 * @brief Function to read a single pin value
 * 
 * @param pin_number    pin to read
 * @param dst           pointer to store the value
 * @return DRV_STATUS_E 
 */
DRV_STATUS_E Pin_read(uint8_t pin_number, bool* dst);

/**
 * @brief Function to write a single pin value
 * 
 * @param pin_number    pin to write
 * @param value         value to write
 * @return DRV_STATUS_E 
 */
DRV_STATUS_E Pin_write(uint8_t pin_number, PIN_OUTPUT_E value);
