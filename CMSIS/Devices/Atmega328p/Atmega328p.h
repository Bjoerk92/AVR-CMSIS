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
            uint8_t WGMn0 : 1;      // Waveform Generation Mode bit 0
            uint8_t WGMn1 : 1;      // Waveform Generation Mode bit 1
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t COMnB1 : 1;     // Compare Output Mode for Channel B bit 1
            uint8_t COMnB0 : 1;     // Compare Output Mode for Channel B bit 0
            uint8_t COMnA1 : 1;     // Compare Output Mode for Channel A bit 1
            uint8_t COMnA0 : 1;     // Compare Output Mode for Channel A bit 0
        }bin;
        uint8_t raw;
    }tccrnA_t;                      // Timer/Counter Control Register A

    union 
    {
        struct
        {
            uint8_t CSn0 : 1;       // Clock Select bit 0
            uint8_t CSn1 : 1;       // Clock Select bit 1
            uint8_t CSn2 : 1;       // Clock Select bit 2
            uint8_t WGMn2 : 1;      // Waveform Generation Mode bit 2
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t FOCnA : 1;      // Force Output Compare for Channel A
            uint8_t FOCnB : 1;      // Force Output Compare for Channel B
        }bin;
        uint8_t raw;
    }tccrnB_t;                      // Timer/Counter Control Register B

    uint8_t TCNTn;                 // Timer/Counter Register
    uint8_t OCRnA;                 // Output Compare Register A
    uint8_t OCRnB;                 // Output Compare Register B
}Timer_8bit_t;

/**
 * @brief enum defining the different waveform generation modes for 8-bit timers
 * 
 */
typedef enum Timer_8bit_WGM_Etag
{
    TIMER_8BIT_WGM_NORMAL = 0,
    TIMER_8BIT_WGM_PWM_PHASE_CORRECT = 1,
    TIMER_8BIT_WGM_CTC = 2,
    TIMER_8BIT_WGM_FAST_PWM = 3,
    TIMER_8BIT_WGM_PWM_PHASE_CORRECT_OCR = 5,
    TIMER_8BIT_WGM_FAST_PWM_OCR = 7
} Timer_8bit_WGM_e;

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
            uint8_t WGMn0 : 1;      // Waveform Generation Mode bit 0
            uint8_t WGMn1 : 1;      // Waveform Generation Mode bit 1
            uint8_t reserved : 2;   // Reserved - unused bits
            uint8_t COMnB1 : 1;     // Compare Output Mode for Channel B bit 1
            uint8_t COMnB0 : 1;     // Compare Output Mode for Channel B bit 0
            uint8_t COMnA1 : 1;     // Compare Output Mode for Channel A bit 1
            uint8_t COMnA0 : 1;     // Compare Output Mode for Channel A bit 0
        }bin;
        uint8_t raw;
    }tccrnA_t;                      // Timer/Counter Control Register A

    union 
    {
        struct
        {
            uint8_t CSn0 : 1;       // Clock Select bit 0
            uint8_t CSn1 : 1;       // Clock Select bit 1
            uint8_t CSn2 : 1;       // Clock Select bit 2
            uint8_t WGMn2 : 1;      // Waveform Generation Mode bit 2
            uint8_t WGMn3 : 1;      // Waveform Generation Mode bit 2
            uint8_t reserved : 1;   // Reserved - unused bits
            uint8_t FOCnA : 1;      // Force Output Compare for Channel A
            uint8_t FOCnB : 1;      // Force Output Compare for Channel B
        }bin;
        uint8_t raw;
    }tccrnB_t;                      // Timer/Counter Control Register B

    uint8_t reserved;               // Reserved for alignment
    uint16_t TCNTn;                 // Timer/Counter Register
    uint16_t OCRnA;                 // Output Compare Register A
    uint16_t OCRnB;                 // Output Compare Register B
}Timer_16bit_t;

/**
 * @brief Enum defing the Wave generator for 16bit timer
 * 
 */
typedef enum Timer_16bit_WGM_Etag
{
    TIMER_16BIT_WGM_NORMAL = 0,
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_8BIT = 1,
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_9BIT = 2,
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_10BIT = 3,
    TIMER_16BIT_WGM_CTC_OCRnA = 4,
    TIMER_16BIT_WGM_FAST_PWM_8BIT = 5,
    TIMER_16BIT_WGM_FAST_PWM_9BIT = 6,
    TIMER_16BIT_WGM_FAST_PWM_10BIT = 7,
    TIMER_16BIT_WGM_PWM_PHASE_FREQ_CORRECT_ICRn = 8,
    TIMER_16BIT_WGM_PWM_PHASE_FREQ_CORRECT_OCRnA = 9,
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_ICRn = 10,
    TIMER_16BIT_WGM_PWM_PHASE_CORRECT_OCRnA = 11,
    TIMER_16BIT_WGM_CTC_ICRn = 12,
    TIMER_16BIT_WGM_RESERVED1 = 13,
    TIMER_16BIT_WGM_FAST_PWM_ICRn = 14,
    TIMER_16BIT_WGM_FAST_PWM_OCRnA = 15
} Timer_16bit_WGM_e;


typedef Timer_8bit_t    Timer_0_t;      // typedef for timer 0
typedef Timer_16bit_t   Timer_1_t;      // typedef for timer 1
typedef Timer_8bit_t    Timer_2_t;      // typedef for timer 2

/**
 * @brief Enum defing the timer id's 
 * 
 */
typedef enum
{
    Timer_0 = 0,
    Timer_1 = 1,
    Timer_2 = 2
} timer_id_e;

#define TIMER0_BASE_ADDRESS (0x44U) // base address for Timer 0
#define TIMER1_BASE_ADDRESS (0x80U) // base address for Timer 1
#define TIMER2_BASE_ADDRESS (0xB0U) // base address for Timer 2

/**
 * @brief Define the 8-bit timer interrupt register
 * 
 */
typedef union TISMK_8Bit_Ttag
{
    struct {
        uint8_t TOIE : 1;
        uint8_t OCIEA : 1;
        uint8_t OCIEB : 1;
        uint8_t reserved : 5;
    }b;
    uint8_t raw;
}TISMK_8Bit_t;

/**
 * @brief Define the 16-bit timer interrupt register
 * 
 */
typedef union TISMK_16Bit_Ttag
{
    struct {
        uint8_t TOIE : 1;
        uint8_t OCIEA : 1;
        uint8_t OCIEB : 1;
        uint8_t reserved : 2;
        uint8_t ICIE : 1;
        uint8_t reserved2: 2;
    }b;
    uint8_t raw;
}TISMK_16Bit_t;

typedef TISMK_8Bit_t    Timer_irq_0_t;      // typedef for timer interrupt register 0
typedef TISMK_16Bit_t   Timer_irq_1_t;      // typedef for timer interrupt register 1
typedef TISMK_8Bit_t    Timer_irq_2_t;      // typedef for timer interrupt register 2

#define TIMSK_0_BASE_ADDRESS (0x6EU)        // Timer/counter 0 interrupt register base address
#define TIMSK_1_BASE_ADDRESS (0x6FU)        // Timer/counter 1 interrupt register base address
#define TIMSK_2_BASE_ADDRESS (0x70U)        // Timer/counter 2 interrupt register base address

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