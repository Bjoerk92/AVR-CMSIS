/**
 * @file Blinky.c
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief Test code for blinking the onboard led on the arduino uno
 * @version 0.1
 * @date 2026-11-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "Pins.h"
#include "Timers.h"

/**
 * @brief Pin number for the build in LED
 */
#define LED_BUILDIN     ((uint8_t)13)

static uint8_t counter = 0;

static void setupTimer()
{
    Timer_cfg_t timer_cfg = {
        .timer_id               = timer_0,
        .Wave                   = TIMER_8BIT_WGM_NORMAL,
        .prescaler              = clk_div_8,
        .cmp_mode[Channel_A]    = Normal_mode,
        .cmp_mode[Channel_B]    = Normal_mode,
        .cmp_value[Channel_A]   = 0,
        .cmp_value[Channel_B]   = 0,
        .IRQ_bit_en.timer_8_bit.b.TOIE = true,
    };

    Timer_Init(&timer_cfg);
}


int main(void)
{
    Pin_set_direction(LED_BUILDIN, PIN_DIR_OUTPUT);

    setupTimer();



    Pin_write(LED_BUILDIN, PIN_HIGH);
    while(1)
    {
    }
}

__IRQ void Timer0_IRQ_Overflow(void)
{
    counter++;
}