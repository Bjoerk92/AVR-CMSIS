/**
 * @file Atmega2560.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief Atmega2560 Register struct and definition.
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
/* Register definitions                                                      */
/*****************************************************************************/

#define PINS_BASE_ADDRESS   ((BASE_REGISTER_OFFSET) + 0x03)
#define PINS_NUMBER_OF_REGS (0x09)
#define MAX_PINS            (87U)


/*****************************************************************************/
/* Register structs                                                          */
/*****************************************************************************/

/**
    \brief Pin structs
    \note Address 0x03-0x0B
 */
typedef struct pins_ttag
{
    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b; 
        uint8_t raw;
    }pina;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;  
    }ddra;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;
    }porta;

    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b; 
        uint8_t raw;
    }pinb;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;  
    }ddrb;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;
    }portb;

    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b; 
        uint8_t raw;
    }pinc;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;  
    }ddrc;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;
    }portc;

    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b; 
        uint8_t raw;
    }pind;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;  
    }ddrd;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;
    }portd;

    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b; 
        uint8_t raw;
    }pine;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;  
    }ddre;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;
    }porte;

    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b; 
        uint8_t raw;
    }pinf;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;  
    }ddrf;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t b7 : 1;
        }b;
        uint8_t raw;
    }portf;

    union
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t reserved : 1;
        }b; 
        uint8_t raw;
    }ping;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t reserved : 1;
        }b;
        uint8_t raw;  
    }ddrg;

    union 
    {
        struct
        {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
            uint8_t b5 : 1;
            uint8_t b6 : 1;
            uint8_t reserved : 1;
        }b;
        uint8_t raw;
    }portg;
}pin_u;
