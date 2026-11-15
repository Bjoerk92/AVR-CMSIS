/**
 * @file Timers.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief CMSIS Timer driver header file
 * @version 0.1
 * @date 2026-11-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "Driver.h"


/**
 * @brief Timer size found in AVR Atmega chips
 * 
 */
typedef enum Timer_size_etag
{
    Timer_8Bit = 0, // timer 8 bit size
    Timer_16Bit,    // timer 16 bit size
}Timer_size_e;

/**
 * @brief struct defining the 
 * 
 */
typedef struct Timer_cfg_ttag
{
    // timer ID
    Timer_id_e              timer_id;
    // Wave generator selection
    Timer_wgm_e             Wave;
    // Timer Prescaler
    Timer_clk_select_e      prescaler;
    // Timer Compare mode for each channel
    Timer_compare_e         cmp_mode[TIMER_CMP_CHANNELS];
    // Timer Compare value for each channel
    uint16_t                cmp_value[TIMER_CMP_CHANNELS];
    // Timer input Capture option !Not available for all timers!
    Timer_Input_cap_opt_e   input_cap_opt;
    // IRQ enable mask(s)
    timsk_t                 IRQ_bit_en;


}Timer_cfg_t, *ptr_Timer_cfg_t;


/**
 * @brief Timer function to setup a timer.
 * @note Timer will start right after initialization!
 * 
 * @param config            pointer to configuration.
 * @return drv_status_e     driver status
 */
drv_status_e Timer_Init(ptr_Timer_cfg_t config);

/**
 * @brief Timer function to stop a timers counter.
 * 
 * @param timer_id      timer id
 * @return drv_status_e driver status
 */
drv_status_e Timer_stop(Timer_id_e timer_id);

/**
 * @brief Timer function to restart a timers counter
 * 
 * @param timer_id timer id
 * @return drv_status_e driver status
 */
drv_status_e Timer_Restart(Timer_id_e timer_id);

/**
 * @brief Timer function to clear a timers counter.
 * 
 * @param timer_id timer id
 * @return drv_status_e driver status
 */
drv_status_e Timer_clear_cnt(Timer_id_e timer_id);

/**
 * @brief Timer function to read a timers counter.
 *  
 * @param timer_id Timer id 
 * @param dst pointer to destination of the counter value
 * @return drv_status_e driver status
 */
drv_status_e Timer_get_cnt(Timer_id_e timer_id, uint16_t* dst);

/**
 * @brief Timer function to force a compare 
 * 
 * @param timer_id 
 * @param channel 
 * @return drv_status_e 
 */
drv_status_e Timer_force_cmp(Timer_id_e timer_id, Timer_cmp_channels_e channel);

