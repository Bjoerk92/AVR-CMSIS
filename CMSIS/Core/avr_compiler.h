/**
 * @file avr_compilor.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "stdint.h"
#include "stdbool.h"

#if defined(__GNUC__)
    #include "avr_gcc.h"
#endif






/*****************************************************************************/
/* Stack pointer                                                             */
/*****************************************************************************/

#define SP_BASE_ADDRESS (0x5DU)
typedef union SP_Utag
{
    uint8_t SP_low;
    uint8_t SP_high;
}SP_t;  // Stack pointer


/*****************************************************************************/
/* AVR - Status Register                                                     */
/*****************************************************************************/

#define SREG_BASE_ADDRESS (0x5FU)

typedef union SREG_Utag
{
    struct 
    {
        uint8_t C : 1;  // Carry flag
        uint8_t Z : 1;  // Zero flag
        uint8_t N : 1;  // Negative flag
        uint8_t V : 1;  // Two Complement overflow flag
        uint8_t S : 1;  // Sign bit
        uint8_t H : 1;  // Half Carry flag
        uint8_t T : 1;  // Bit Copy storage
        uint8_t I : 1;  // Global Interrupt enable
    }b;
    uint8_t raw;
}SREG_t;    // Status register
