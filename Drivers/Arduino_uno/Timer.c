/**
 * @file Timer.c
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief Arduino_uno Timer drivers
 * @version 0.1
 * @date 2026-11-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "Timers.h"

/**
 * @brief Array of timer base address
 * 
 */
static const void* timer_addresses[MAX_TIMERS] = TIMER_BASE_ADDRESS;

/**
 * @brief Array of timer interrupt mask registers
 * 
 */
static const void* timsk_addresses[MAX_TIMERS] = TIMSK_BASE_ADDRESS;

/**
 * @brief Stored clock prescaler, used to start and stop the timer counter.
 * 
 */
static Timer_clk_select_e saved_clk[MAX_TIMERS] = {};

/*****************************************************************************/
/* Static function                                                           */
/*****************************************************************************/

/**
 * @brief Initializes a 8-bit timer
 * 
 * @param timer     pointer to a 8-bit timer
 * @param config    pointer to its configuration
 * @return drv_status_e driver status
 */
static drv_status_e init_8bit_timer(Timer_8bit_t* timer, ptr_Timer_cfg_t config)
{
    drv_status_e status = DRV_OK;

    timer->tccrA_t.bin.WGM_LOW = (config->Wave & 0x02);
    timer->tccrB_t.bin.WGM_HIGH = ((config->Wave & 0x04) >> 2);
    
    timer->tccrA_t.bin.COMnA = config->cmp_mode[Channel_A];
    timer->tccrA_t.bin.COMnB = config->cmp_mode[Channel_B];

    timer->OCRnA = (config->cmp_value[Channel_A] & UINT8_MAX);
    timer->OCRnB = (config->cmp_value[Channel_B] & UINT8_MAX);

    timer->tccrB_t.bin.Clk_scale = config->prescaler;

    return status;
}

/**
 * @brief Initializes a 16-bit timer
 * 
 * @param timer     pointer to a 16-bit timer
 * @param config    pointer to its configuration
 * @return drv_status_e driver status
 */
static drv_status_e init_16bit_timer(Timer_8bit_t* timer, ptr_Timer_cfg_t config)
{
    drv_status_e status = DRV_OK;

    timer->tccrA_t.bin.WGM_LOW = (config->Wave & 0x02);
    timer->tccrB_t.bin.WGM_HIGH = ((config->Wave & 0x0C) >> 2);
    
    timer->tccrA_t.bin.COMnA = config->cmp_mode[Channel_A];
    timer->tccrA_t.bin.COMnB = config->cmp_mode[Channel_B];

    timer->OCRnA = config->cmp_value[Channel_A];
    timer->OCRnB = config->cmp_value[Channel_B];

    timer->tccrB_t.bin.Clk_scale = config->prescaler;

    return status;
}


/*****************************************************************************/
/* Public function                                                           */
/*****************************************************************************/

/**
 * @ref Timer.h
 */
drv_status_e Timer_Init(ptr_Timer_cfg_t config)
{
    drv_status_e status = DRV_OK;
    if (config == NULL)
    {
        status = DRV_ERROR_PARAM;
    }
    else
    {   
        switch(config->timer_id)
        {
            // 8-bit timers.
            case timer_0:   // allow fall thought. 
            case timer_2:
            {
                Timer_8bit_t* timer = (Timer_8bit_t*)&timer_addresses[config->timer_id];
                timsk_8bit_t* timsk = (timsk_8bit_t*)&timsk_addresses[config->timer_id];
                // enable the IRQ before stating the timers
                if (config->IRQ_bit_en.timer_8_bit.raw != 0)
                {   
                    timsk->raw = config->IRQ_bit_en.timer_8_bit.raw;
                }
                status = init_8bit_timer(timer, config);
                break;
            }

            // 16-bit timers.
            case timer_1:
            {
                Timer_16bit_t* timer = (Timer_16bit_t*)&timer_addresses[config->timer_id];
                timsk_16bit_t* timsk = (timsk_16bit_t*)&timsk_addresses[config->timer_id];
                
                // enable the IRQ before stating the timers
                if (config->IRQ_bit_en.timer_16_bit.raw != 0)
                {   
                    timsk->raw = config->IRQ_bit_en.timer_16_bit.raw;
                }
                status = init_16bit_timer(timer, config); 
                break;
            }
            
            default:
            {
                status = DRV_ERROR;
                break;
            }
        }
    }
    return status;
}

/**
 * @ref Timer.h
 */
drv_status_e Timer_stop(Timer_id_e timer_id)
{
    drv_status_e status = DRV_OK;
    switch(timer_id)
    {
        // 8-bit timers.
        case timer_0:   // allow fall thought. 
        case timer_2:
        {
            Timer_8bit_t* timer = (Timer_8bit_t*)&timer_addresses[timer_id];
            saved_clk[timer_id] = timer->tccrB_t.bin.Clk_scale;
            timer->tccrB_t.bin.Clk_scale = No_clock_source; // no clock source -> Timer stopped.
            break;
        }

        // 16-bit timers.
        case timer_1:
        {
            Timer_16bit_t* timer = (Timer_16bit_t*)&timer_addresses[timer_id];
            saved_clk[timer_id] = timer->tccrB_t.bin.Clk_scale;
            timer->tccrB_t.bin.Clk_scale = No_clock_source; // no clock source -> Timer stopped.
            break;
        }
        
        default:
        {
            status = DRV_ERROR;
            break;
        }
    }
    return status;
}

/**
 * @ref Timer.h
 */
drv_status_e Timer_Restart(Timer_id_e timer_id)
{
    drv_status_e status = DRV_OK;
    switch(timer_id)
    {
        // 8-bit timers.
        case timer_0:   // allow fall thought. 
        case timer_2:
        {
            Timer_8bit_t* timer = (Timer_8bit_t*)&timer_addresses[timer_id];
            timer->tccrB_t.bin.Clk_scale = saved_clk[timer_id];
            break;
        }

        // 16-bit timers.
        case timer_1:
        {
            Timer_16bit_t* timer = (Timer_16bit_t*)&timer_addresses[timer_id];
            timer->tccrB_t.bin.Clk_scale = saved_clk[timer_id];
            break;
        }
        
        default:
        {
            status = DRV_ERROR;
            break;
        }
    }
    return status;
}

/**
 * @ref Timer.h
 */
drv_status_e Timer_clear_cnt(Timer_id_e timer_id)
{
    drv_status_e status = DRV_OK;
    switch(timer_id)
    {
        // 8-bit timers.
        case timer_0:   // allow fall thought. 
        case timer_2:
        {
            Timer_8bit_t* timer = (Timer_8bit_t*)&timer_addresses[timer_id];
            timer->TCNTn = 0;
            break;
        }

        // 16-bit timers.
        case timer_1:
        {
            Timer_16bit_t* timer = (Timer_16bit_t*)&timer_addresses[timer_id];
            timer->TCNTn = 0;
            break;
        }
        
        default:
        {
            status = DRV_ERROR;
            break;
        }
    }
    return status; 
}

/**
 * @ref Timer.h
 */
drv_status_e Timer_get_cnt(Timer_id_e timer_id, uint16_t* dst)
{
    drv_status_e status = DRV_OK;
    switch(timer_id)
    {
        // 8-bit timers.
        case timer_0:   // allow fall thought. 
        case timer_2:
        {
            Timer_8bit_t* timer = (Timer_8bit_t*)&timer_addresses[timer_id];
            *dst = timer->TCNTn;
            break;
        }

        // 16-bit timers.
        case timer_1:
        {
            Timer_16bit_t* timer = (Timer_16bit_t*)&timer_addresses[timer_id];
            *dst = timer->TCNTn;
            break;
        }
        
        default:
        {
            status = DRV_ERROR;
            break;
        }
    }
    return status;
}

/**
 * @ref Timer.h
 */
drv_status_e Timer_force_cmp(Timer_id_e timer_id, Timer_cmp_channels_e channel)
{
    drv_status_e status = DRV_OK;
    switch(timer_id)
    {
        // 8-bit timers.
        case timer_0:   // allow fall thought. 
        case timer_2:
        {
            Timer_8bit_t* timer = (Timer_8bit_t*)&timer_addresses[timer_id];
            if (channel == Channel_A)
            {
                timer->tccrB_t.bin.FOCnA = 0x01U;
            }
            else
            {
                timer->tccrB_t.bin.FOCnB = 0x01U;
            }
            break;
        }

        // 16-bit timers.
        case timer_1:
        {
            Timer_16bit_t* timer = (Timer_16bit_t*)&timer_addresses[timer_id];
            if (channel == Channel_A)
            {
                timer->tccrC_t.bin.FOCnA = 0x01U;
            }
            else
            {
                timer->tccrC_t.bin.FOCnB = 0x01U;
            }
            break;
        }
        
        default:
        {
            status = DRV_ERROR;
            break;
        }
    }
    return status;
}

/*****************************************************************************/
/* Timer IRQ functions                                                       */
/*****************************************************************************/

__WEAK_IRQ Timer0_IRQ_Overflow(void) {}

__WEAK_IRQ Timer0_IRQ_CmpA(void) {}

__WEAK_IRQ Timer0_IRQ_CmpB(void) {}

__WEAK_IRQ Timer1_IRQ_Overflow(void) {}

__WEAK_IRQ Timer1_IRQ_CmpA(void) {}

__WEAK_IRQ Timer1_IRQ_CmpB(void) {}

__WEAK_IRQ Timer1_IRQ_Input_capture(void) {}

__WEAK_IRQ Timer2_IRQ_Overflow(void) {}

__WEAK_IRQ Timer2_IRQ_CmpA(void) {}

__WEAK_IRQ Timer2_IRQ_CmpB(void) {}