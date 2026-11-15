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

#include "avr_compiler.h"

/***
    \brief Base address offset
    \note First 0x1F address are reserved for R1-31
 */
#define BASE_REGISTER_OFFSET    0x20U

/*****************************************************************************/
/* Pin Register define                                                       */
/*****************************************************************************/

/**
 * @brief 
 * 
 */
typedef struct
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

#define PINB_BASE_ADDRESS   (0x23U)
#define PINC_BASE_ADDRESS   (0x26U)
#define PIND_BASE_ADDRESS   (0x29U)

#define PIN_B_SIZE          (8U)
#define PIN_C_SIZE          (7U)
#define PIN_D_SIZE          (8U)

#define MAX_PINS            (PIN_B_SIZE + PIN_C_SIZE + PIN_D_SIZE)
typedef enum PIN_GROUP_ID_Etag
{   
    PIN_B = 0,
    PIN_C,
    PIN_D
}pin_group_id_e;

/*****************************************************************************/
/* Timer Interrupt Define                                                    */
/*****************************************************************************/

typedef struct 
{
    union TIFR0_Ttag
    {
        struct
        {
            uint8_t TOV0 : 1;       // Timer/Counter0 Overflow Flag
            uint8_t OCF0A : 1;      // Timer/Counter0 Output Compare Match A Flag
            uint8_t OCF0B : 1;      // Timer/Counter0 Output Compare Match B Flag
            uint8_t reserved : 5;   // Reserved - unused bits
        }bin;
        uint8_t raw;
    }tifr0_t;                       // Timer/Counter0 Interrupt Flag Register

    union TIFR1_Ttag
    {
        struct
        {
            uint8_t TOV1 : 1;       // Timer/Counter1 Overflow Flag
            uint8_t OCF1A : 1;      // Timer/Counter1 Output Compare Match A Flag
            uint8_t OCF1B : 1;      // Timer/Counter1 Output Compare Match B Flag
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t ICF1 : 1;       // Timer/Counter1 Input Capture Flag
            uint8_t reserved2 : 2;  // Reserved - unused bits
        }bin;
        uint8_t raw;
    }tifr1_t;                       // Timer/Counter1 Interrupt Flag Register

    union TIFR2_Ttag
    {
        struct
        {
            uint8_t TOV2 : 1;       // Timer/Counter2 Overflow Flag
            uint8_t OCF2A : 1;      // Timer/Counter2 Output Compare Match A Flag
            uint8_t OCF2B : 1;      // Timer/Counter2 Output Compare Match B Flag
            uint8_t reserved : 5;   // Reserved - unused bits
        }bin;
        uint8_t raw;
    }tifr2_t;                       // Timer/Counter2 Interrupt Flag Register
} tifr_t;

#define TIFR_BASE_ADDRESS (0x35U)

/*****************************************************************************/
/* Pin Change Interrupt Flag Register                                        */
/*****************************************************************************/

typedef union 
{
    struct
    {
        uint8_t PCIF0 : 1;      // Pin Change Interrupt Flag 0
        uint8_t PCIF1 : 1;      // Pin Change Interrupt Flag 1
        uint8_t PCIF2 : 1;      // Pin Change Interrupt Flag 2
        uint8_t reserved : 5;   // Reserved - unused bits
    }bin;
    uint8_t raw;
}pcifr_t;

#define PCIFR_BASE_ADDRESS (0x3BU)

/*****************************************************************************/
/* External Interrupt Flag Register                                          */
/*****************************************************************************/

typedef struct 
{
    union EIFR_Ttag
    {
        struct
        {
            uint8_t INTF0 : 1;      // External Interrupt Flag 0
            uint8_t INTF1 : 1;      // External Interrupt Flag 1
            uint8_t INTF2 : 1;      // External Interrupt Flag 2
            uint8_t reserved : 5;   // Reserved - unused bits
        }bin;
        uint8_t raw;
    }eifr_t;                       // External Interrupt Flag Register

    union EIMSK_Ttag
    {
        struct
        {
            uint8_t INT0 : 1;       // External Interrupt Request 0 Enable
            uint8_t INT1 : 1;       // External Interrupt Request 1 Enable
            uint8_t INT2 : 1;       // External Interrupt Request 2 Enable
            uint8_t reserved : 5;   // Reserved - unused bits
        }bin;
        uint8_t raw;
    }eimsk_t;                      // External Interrupt Mask Register
}ei_t;

#define EXTERNAL_INTERRUPT_BASE_ADDRESS (0x3CU)

/*****************************************************************************/
/* General purpose registers                                                 */
/*****************************************************************************/

typedef uint8_t GPIOR_t;

#define GPIOR0_BASE_ADDRESS (0x3EU)
#define GPIOR1_BASE_ADDRESS (0x4AU)
#define GPIOR2_BASE_ADDRESS (0x4BU)

/*****************************************************************************/
/* Eeprom registers                                                          */
/*****************************************************************************/

/**
 * @brief Defines the Eeprom registers
 * 
 */
typedef struct 
{
    union EECR_Ttag
    {
        struct
        {
            uint8_t EERE : 1;      // EEPROM Read Enable
            uint8_t EEWE : 1;      // EEPROM Write Enable
            uint8_t EEMWE : 1;     // EEPROM Master Write Enable
            uint8_t EERIE : 1;     // EEPROM Ready Interrupt Enable
            uint8_t reserved : 4;  // Reserved - unused bits
        }bin;
        uint8_t raw;
    }eecr_t;                       // EEPROM Control Register

    union EEDR_Ttag
    {
        struct
        {
            uint8_t EEDR : 8;      // EEPROM Data Register
        }bin;
        uint8_t raw;
    }eedr_t;                       // EEPROM Data Register

    union EEAR_Ttag
    {
        struct
        {
            uint8_t EEARL : 8;     // EEPROM Address Register Low Byte
            uint8_t EEARH : 2;     // EEPROM Address Register High Byte
            uint8_t reserved : 6;  // Reserved - unused bits
        }bin;
        uint16_t raw;
    }eear_t;                       // EEPROM Address Register
}eeprom_t;

#define EEPROM_BASE_ADDRESS (0x3FU)

/*****************************************************************************/
/* General Timer/Counter control registers                                   */
/*****************************************************************************/

/**
 * @brief Defines the General timer/counter control register
 * 
 */
typedef struct 
{
    uint8_t PSRSYNC : 1;    // Prescaler Reset for Synchronous Timer/Counters
    uint8_t PSRASY : 1;     // Prescaler Reset for Asynchronous Timer/Counters
    uint8_t reserved : 5;   // Reserved - unused bits
    uint8_t TSM : 1;        // Timer/Counter Synchronization Mode            
}gtccr_t;   // General Timer/Counter Control Register

#define GTCCR_BASE_ADDRESS (0x43U)

/*****************************************************************************/
/* Timer/Counter 0 and 2 registers                                           */
/*****************************************************************************/

/**
 * @brief Timer/Counter 0 and 2 registers
 * 
 */
typedef struct 
{   
    union 
    {
        struct
        {
            uint8_t WGM_LOW : 2;    // Wave generator low bits (0 and 1)
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t COMnB : 2;      // Compare Output mode for Channel B
            uint8_t COMnA : 2;      // Compare Output Mode for Channel A
        }bin;
        uint8_t raw;
    }tccrA_t;                      // Timer/Counter Control Register A

    union 
    {
        struct
        {
            uint8_t Clk_scale : 3;  // Clock prescaler selection
            uint8_t WGM_HIGH : 1;   // Waveform Generation Mode bit 2
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t FOCnA : 1;      // Force Output Compare for Channel A
            uint8_t FOCnB : 1;      // Force Output Compare for Channel B
        }bin;
        uint8_t raw;
    }tccrB_t;                      // Timer/Counter Control Register B

    uint8_t TCNTn;                 // Timer/Counter Register
    uint8_t OCRnA;                 // Output Compare Register A
    uint8_t OCRnB;                 // Output Compare Register B
}Timer_8bit_t;

/**
 * @brief Timer/Counter 1 registers
 * 
 */
typedef struct 
{   
    union 
    {
        struct
        {
            uint8_t WGM_LOW : 2;    // Wave generator low bit (0 / 1)
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t COMnB : 2;      // Compare Output mode for Channel B
            uint8_t COMnA : 2;      // Compare Output Mode for Channel A
        }bin;
        uint8_t raw;
    }tccrA_t;                      // Timer/Counter Control Register A

    union 
    {
        struct
        {
            uint8_t Clk_scale : 3;  // Clock prescaler selection
            uint8_t WGM_HIGH : 2;   // Wave generator high bit (2 / 3)
            uint8_t reserved : 1;   // Reserved - unused bits
            uint8_t ICE : 2;      // Input Capture option bits
        }bin;
        uint8_t raw;
    }tccrB_t;                      // Timer/Counter Control Register B

    union
    {
        struct 
        {
            uint8_t reserved : 6;   // reserved
            uint8_t FOCnA : 1;      // Force Output Compare for Channel A
            uint8_t FOCnB : 1;      // Force Output Compare for Channel B
        }bin;
        uint8_t raw;
    }tccrC_t;

    uint8_t reserved;               // Reserved for alignment
    uint16_t TCNTn;                 // Timer/Counter Register
    uint16_t OCRnA;                 // Output Compare Register A
    uint16_t OCRnB;                 // Output Compare Register B
}Timer_16bit_t;

/**
 * @brief Enum defining the Timer
 * 
 */
typedef enum Timer_wgm_etag
{
    // 8-bit timer waveform generation modes
    TIMER_8BIT_WGM_NORMAL = 0,                      // Normal mode: counter counts from 0 to 0xFF then wraps
    TIMER_8BIT_WGM_PWM_PHASE_CORRECT = 1,           // Phase-correct PWM: dual-slope output
    TIMER_8BIT_WGM_CTC = 2,                         // Clear Timer on Compare Match (CTC)
    TIMER_8BIT_WGM_FAST_PWM = 3,                    // Fast PWM: single-slope output
    TIMER_8BIT_WGM_PWM_PHASE_CORRECT_OCR = 5,       // Phase-correct PWM using OCRn as TOP
    TIMER_8BIT_WGM_FAST_PWM_OCR = 7,                // Fast PWM using OCRn as TOP

    // 16-bit timer waveform generation modes
    TIMER_16BIT_WGM_NORMAL = 0,                     // Normal mode: counter counts from 0 to 0xFFFF and wraps
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_8BIT = 1,     // Phase-correct PWM, TOP = 0x00FF
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_9BIT = 2,     // Phase-correct PWM, TOP = 0x01FF
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_10BIT = 3,    // Phase-correct PWM, TOP = 0x03FF
    TIMER_16BIT_WGM_CTC_OCRnA = 4,                   // CTC mode, TOP = OCR1A
    TIMER_16BIT_WGM_FAST_PWM_8BIT = 5,               // Fast PWM, TOP = 0x00FF
    TIMER_16BIT_WGM_FAST_PWM_9BIT = 6,               // Fast PWM, TOP = 0x01FF
    TIMER_16BIT_WGM_FAST_PWM_10BIT = 7,              // Fast PWM, TOP = 0x03FF
    TIMER_16BIT_WGM_PWM_PHASE_FREQ_CORRECT_ICRn = 8, // Phase/frequency-correct PWM, TOP = ICR1
    TIMER_16BIT_WGM_PWM_PHASE_FREQ_CORRECT_OCRnA = 9, // Phase/frequency-correct PWM, TOP = OCR1A
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_ICRn = 10,     // Phase-correct PWM, TOP = ICR1
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_OCRnA = 11,    // Phase-correct PWM, TOP = OCR1A
    TIMER_16BIT_WGM_CTC_ICRn = 12,                   // CTC mode, TOP = ICR1
    TIMER_16BIT_WGM_RESERVED1 = 13,                  // Reserved / not used
    TIMER_16BIT_WGM_FAST_PWM_ICRn = 14,               // Fast PWM, TOP = ICR1
    TIMER_16BIT_WGM_FAST_PWM_OCRnA = 15              // Fast PWM, TOP = OCR1A
} Timer_wgm_e;

/**
 * @brief enum defining the clock selection options
 * 
 */
typedef enum Timer_clk_select_etag
{
    No_clock_source = 0,            // No clock source - Timer/counter stopped
    clk_raw,                        // No prescaling - raw clock input. 
    clk_div_8,                      // clock signal / 8
    clk_div_64,                     // clock signal / 64
    clk_div_256,                    // clock signal / 256
    clk_div_1024,                   // clock signal / 1024
    clk_external_T0_falling,        // external clock source on T0, count on falling edge
    clk_external_T0_rising,         // external clock source on T0, count on rising edge
}Timer_clk_select_e;

/**
 * @brief Enum defining the Timers compare options.
 * 
 */
typedef enum Timer_compare_etag
{
    Normal_mode = 0,                // Normal mode 
    Toggle_OC_on_compare_match,     // Toggle OCxA/B on compare match - 
    Clear_OC_on_compare_match,      // Clear OCxA/B on compare match
    Set_OC_on_compare_match         // Set OCxA/B on compare match
}Timer_compare_e;

typedef enum Timer_Input_cap_opt_etag
{
    Falling_edge_No_noise_cancel = 0,
    Rising_edge_no_noise_cancel = 1,
    Falling_edge_with_noise_cancel = 2,
    Rising_edge_with_noise_cancel = 3
}Timer_Input_cap_opt_e;

typedef enum Timer_cmp_channels_etag
{
    Channel_A = 0,
    Channel_B
}Timer_cmp_channels_e;

/**
 * @brief enum defining the timer identity
 * 
 */
typedef enum Timer_id_etag
{
    timer_0 = 0,
    timer_1,
    timer_2,
}Timer_id_e;

typedef Timer_8bit_t    Timer_0_t;  // typedef for timer 0
typedef Timer_16bit_t   Timer_1_t;  // typedef for timer 1
typedef Timer_8bit_t    Timer_2_t;  // typedef for timer 2

#define MAX_TIMERS          (0x03U) // number of Timers
#define TIMER_CMP_CHANNELS  (0x02U) // Number of Timer compare channels

#define TIMER0_BASE_ADDRESS (0x44U) // base address for Timer 0
#define TIMER1_BASE_ADDRESS (0x80U) // base address for Timer 1
#define TIMER2_BASE_ADDRESS (0xB0U) // base address for Timer 2

#define TIMER_BASE_ADDRESS {TIMER0_BASE_ADDRESS, TIMER1_BASE_ADDRESS, TIMER2_BASE_ADDRESS}

/*****************************************************************************/
/* Timer interrupt mask registers                                            */
/*****************************************************************************/

/**
 * @brief Define the 8-bit timer interrupt register
 * 
 */
typedef union timsk_8bit_ttag
{
    struct {
        uint8_t TOIE : 1;       // Timer overflow 
        uint8_t OCIEA : 1;      // Output compare channel A
        uint8_t OCIEB : 1;      // Output compare channel B
        uint8_t reserved : 5;   // reserved
    }b;
    uint8_t raw;
}timsk_8bit_t;

/**
 * @brief Define the 16-bit timer interrupt register
 * 
 */
typedef union timsk_16Bit_ttag
{
    struct {
        uint8_t TOIE : 1;       // Timer overflow
        uint8_t OCIEA : 1;      // Output compare channel A
        uint8_t OCIEB : 1;      // Output compare channel B
        uint8_t reserved : 2;   // reserved
        uint8_t ICIE : 1;       // Input capture 
        uint8_t reserved2: 2;   // reserved
    }b;
    uint8_t raw;
}timsk_16bit_t;

/**
 * @brief Union holding the Timer interrupt mask registers
 * 
 */
typedef union timsk_ttag{
    timsk_8bit_t timer_8_bit;       // IRQ register defines for Timer 0/2
    timsk_16bit_t timer_16_bit;     // IRQ register defines for Timer 1
}timsk_t;

#define TIMSK_0_BASE_ADDRESS (0x6EU)        // Timer/counter 0 interrupt register base address
#define TIMSK_1_BASE_ADDRESS (0x6FU)        // Timer/counter 1 interrupt register base address
#define TIMSK_2_BASE_ADDRESS (0x70U)        // Timer/counter 2 interrupt register base address

#define TIMSK_BASE_ADDRESS {TIMSK_0_BASE_ADDRESS, TIMSK_1_BASE_ADDRESS, TIMSK_2_BASE_ADDRESS}


/*****************************************************************************/
/* SPI registers                                                             */
/*****************************************************************************/

/**
 * @brief Defines the SPI registers
 * 
 */
typedef struct 
{
    union SPCR_Ttag
    {
        struct
        {
            uint8_t SPR0 : 1;       // SPI Clock Rate Select bit 0
            uint8_t SPR1 : 1;       // SPI Clock Rate Select bit 1
            uint8_t CPHA : 1;       // Clock Phase
            uint8_t CPOL : 1;       // Clock Polarity
            uint8_t MSTR : 1;       // Master/Slave Select
            uint8_t DORD : 1;       // Data Order
            uint8_t SPE : 1;        // SPI Enable
            uint8_t SPIE : 1;       // SPI Interrupt Enable
        }bin;
        uint8_t raw;
    }spcr_t;                        // SPI Control Register

    union SPSR_Ttag
    {
        struct
        {
            uint8_t SPI2X : 1;      // Double SPI Speed Bit
            uint8_t reserved : 5;   // Reserved - unused bits
            uint8_t WCOL : 1;       // Write Collision Flag
            uint8_t SPIF : 1;       // SPI Interrupt Flag
        }bin;
        uint8_t raw;
    }spsr_t;                        // SPI Status Register

    uint8_t SPDR;                       // SPI Data Register

}SPI_t;

#define SPI_BASE_ADDRESS (0x4CU)    // base address for the SPI

/*****************************************************************************/
/* Analog Comparator                                                         */
/*****************************************************************************/

/**
 * @brief Defines the analog comparator control and status register
 * 
 */
typedef union ACRC_ttag
{
    struct ACRC_BYTES_Ttag
    {
        uint8_t ACIS : 2;   // Analog comparator Interrupt mode select
        uint8_t ACIC : 1;   // Analog Comparator input capture Enable
        uint8_t ACIE : 1;   // Analog comparator interrupt enable
        uint8_t ACI  : 1;   // Analog comparator interrupt flag
        uint8_t ACO  : 1;   // Analog comparator output
        uint8_t ACBG : 1;   // Analog comparator bandgap select
        uint8_t ACD  : 1;   // Analog comparator disable
    }b;
    uint8_t raw;
}ACRC_t;

#define ACRC_BASE_ADDRESS (0x50U)   // Base address for ACRC register

/*****************************************************************************/
/* Sleep mode Control register                                               */
/*****************************************************************************/

/**
 * @brief Defines the Sleep mode control register
 * 
 */
union SMCR_Utag
{
    struct 
    {
        uint8_t SE : 1;         // Sleep enable
        uint8_t SM : 3;         // Sleep mode
        uint8_t reserved : 4;   // Reserved
    }b;
    uint8_t raw;
}SMCR_t;            // sleep mode control registers

#define SMCR_BASE_ADDRESS (0x53U)   // sleep mode register base address

/**
 * @brief Enumeration for sleep mode
 * 
 */
typedef enum SLEEP_MODE_Etag
{
    SM_IDLE = 0,
    SM_ADC_NOISE_REDUCTION,
    SM_POWER_DOWN,
    SM_POWER_SAVE,
    SM_STANDBY = 6, 
    SM_EXTERNAL_STANDBY = 7
}sleep_mode_e;

/*****************************************************************************/
/* MCU Registers                                                             */
/*****************************************************************************/

/**
 * @brief Defines the Atmega328P MCU registers
 * 
 */
struct MCUxR_Ttag
{
    union MCUSR_Utag
    {
        struct
        {
            uint8_t PORF : 1;       // Power-on Reset Flag
            uint8_t EXTRF : 1;      // External Reset Flag
            uint8_t BORF : 1;       // Brown-out Reset Flag
            uint8_t WDRF : 1;       // Watchdog System Reset Flag
            uint8_t reserved : 4;   // reserved
        }b;
        uint8_t raw;
    }MCUSR_t;   // MCU Status Registers

    union MCUCR_Utag
    {
        struct
        {
            uint8_t IVCE : 1;       // Interrupt Vector Change Enable
            uint8_t IVSEL : 1;      // Interrupt Vector Select
            uint8_t reserved : 2;   // reserved
            uint8_t PUD : 1;        // Pull-up disabled
            uint8_t BODSE : 1;      // BOD Sleep 
            uint8_t BODS : 1;       // BOD Sleep Enable
        }b; 
        uint8_t raw;
    }MCURCc_t;   // MCU Control Registers
}MCUxR_t; 

#define MCUxR_BASE_ADDRESS (0x54U)  // Base address for the MCU Registers


/*****************************************************************************/
/* Store program memory                                                      */
/*****************************************************************************/

/**
 * @brief Define the store program memory control register
 * 
 */
union SPMCSR_Utag
{
    struct
    {
        uint8_t SPMEN : 1;      // Store Program memory
        uint8_t PGERS : 1;      // Page Erase
        uint8_t PGWRT : 1;      // Page write
        uint8_t BLBSET : 1;     // Boot lock bit set
        uint8_t RWWSRE : 1;     // Read-While-Write Section Read Enable
        uint8_t SIGRD : 1;      // Signature Row Read
        uint8_t RWWSB : 1;      // Read-While-Write Section Busy
        uint8_t SPMIE : 1;      // SPM Interrupt Enable
    }b;
    uint8_t raw;
}SPMCSR_t;  // Store Program Memory Control and Status Register

#define SPMCSR_BASE_ADDRESS (0x57U)     // Base address for SPMCSR


/*****************************************************************************/
/* Watchdog controller                                                       */
/*****************************************************************************/

/**
 * @brief Defines the watchdog registers.
 * 
 */
typedef union WDTCSR_Utag
{
    struct {
        uint8_t WPDx : 3;   // Watchdog prescaler selector
        uint8_t WDE : 1;    // Watchdog System Reset enable
        uint8_t WDCE : 1;   // Watchdog Change enable
        uint8_t WDPh : 1;   // Watchdog enable 512/1024 prescaler
        uint8_t WDIE : 1;   // Watchdog Interrupt enable
        uint8_t WDIF : 1;   // Watchdog Interrupt flag
    }b;
    uint8_t raw;
}WDTCSR_t;

#define WDTCSR_BASE_ADDRESS (0x60U)     // base address for watchdog

/*****************************************************************************/
/* Clock Prescale Register                                                   */
/*****************************************************************************/

/**
 * @brief Defining clock prescale register
 * 
 */
typedef union CLKPR_Utag
{
    struct {
        uint8_t CLKPSx : 4;     // Clock prescaler devision factor selector
        uint8_t reserved : 3;   // reserved
        uint8_t CLKPC : 1;      // Clock prescaler change enable
    }b;
    uint8_t raw;
}CLKPR_t;

#define CLKPR_BASE_ADDRESS (0x61U)  // CLKPR base address

typedef enum CLK_Prescaler_etag
{
    CLK_DIV_FACTOR_1 = 0,
    CLK_DIV_FACTOR_2,
    CLK_DIV_FACTOR_4,
    CLK_DIV_FACTOR_8,
    CLK_DIV_FACTOR_16,
    CLK_DIV_FACTOR_32,
    CLK_DIV_FACTOR_64,
    CLK_DIV_FACTOR_128,
    CLK_DIV_FACTOR_256
}CLK_Prescaler_e;

/*****************************************************************************/
/* Power Reduction Register                                                  */
/*****************************************************************************/

/**
 * @brief Defines Power Reduction Register
 * 
 */
typedef union PPR_ttag 
{
    struct {
        uint8_t PRADC : 1;          // Power Reduction ADC
        uint8_t PRUSART0 : 1;       // Power Reduction USART0 
        uint8_t PRSPI : 1;          // Power Redunction SPI
        uint8_t PRTIM1 : 1;         // Power Reduction Timer 1
        uint8_t reserved : 1;       // Reserved
        uint8_t PRTIM0 : 1;         // Power Reduction Timer 0 
        uint8_t PTRIM2 : 1;         // Power Reduction Timer 2
        uint8_t PRTWI : 1;          // Power Reduction I2C 
    }b;
    uint8_t raw;
}PPR_t;

#define PPR_BASE_ADDRESS (0x64U)

/*****************************************************************************/
/* Oscillator Calibration Register                                           */
/*****************************************************************************/

/**
 * @brief Define the OSCCAL register
 * 
 */
typedef uint8_t OSCCAL_t;

#define OSCCAL_BASE_ADDRESS (0x66U)