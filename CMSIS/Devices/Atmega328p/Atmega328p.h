/**
 * @file Atmega328p.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief Atmega328p Register struct and definition.
 * @version 0.1
 * @date 2026-10-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "avr_compilor.h"

/***
    \brief Base address offset
    \note First 0x1F address are reserved for R1-31
 */
#define BASE_REGISTER_OFFSET    0x20U

/*****************************************************************************/
/* Pin Register define                                                       */
/*****************************************************************************/

typedef struct Pin_ttag
{
    union INPUT_Ttag {
        struct
        {
            uint8_t num_1 : 1;
            uint8_t num_2 : 1;
            uint8_t num_3 : 1;
            uint8_t num_4 : 1;
            uint8_t num_5 : 1;
            uint8_t num_6 : 1;
            uint8_t num_7 : 1;
        }bin;
        uint8_t raw;
    } Input;

    union DIRECTION_Ttag {
        struct
        {
            uint8_t num_1 : 1;
            uint8_t num_2 : 1;
            uint8_t num_3 : 1;
            uint8_t num_4 : 1;
            uint8_t num_5 : 1;
            uint8_t num_6 : 1;
            uint8_t num_7 : 1;
        }bin;
        uint8_t raw;
    } Direction;

    union DATA_Ttag {
        struct
        {
            uint8_t num_1 : 1;
            uint8_t num_2 : 1;
            uint8_t num_3 : 1;
            uint8_t num_4 : 1;
            uint8_t num_5 : 1;
            uint8_t num_6 : 1;
            uint8_t num_7 : 1;
        }bin;
        uint8_t raw;
    } Data;
}pin_t;

#define PINB_BASE_ADDRESS   ((BASE_REGISTER_OFFSET) + 0x03U)
#define PINC_BASE_ADDRESS   ((BASE_REGISTER_OFFSET) + 0x06U)
#define PIND_BASE_ADDRESS   ((BASE_REGISTER_OFFSET) + 0x09U)
#define MAX_PINS            (23U)
#define PIN_B_SIZE          (8U)
#define PIN_C_SIZE          (7U)
#define PIN_D_SIZE          (8U)

typedef enum PIN_GROUP_ID_Etag
{   
    PIN_B = 0,
    PIN_C,
    PIN_D
}pin_group_id_e;

