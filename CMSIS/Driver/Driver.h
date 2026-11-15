/**
 * @file Driver.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief AVR-CMSIS Hardware abstraction layer to the drivers.
 * @version 0.1
 * @date 2026-10-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "avr_compiler.h"
#if 1
    #define ATMEGA328P 1
#endif


#ifdef ATMEGA328P
    #include "Atmega328p.h"
#endif
#ifdef ATMEGA2560
    #include "Atmega2560.h"
#endif

typedef enum drv_status_etag {
    DRV_OK = 0,
    DRV_ERROR,
    DRV_ERROR_PARAM,
}drv_status_e;

