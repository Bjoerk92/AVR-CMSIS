/**
 * @file pins.c
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief Arduino_uno Pin drivers
 * @version 0.1
 * @date 2026-10-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "Pins.h"

/******************************************************************************/
/*                  STRUCTS                                                   */
/******************************************************************************/

typedef struct PIN_MAPPING_Ttag
{
    pin_group_id_e group;   // group id
    uint8_t bit;            // bit number
}pin_mapping_t;

/******************************************************************************/
/*                  CONST VARIABLE                                            */
/******************************************************************************/

/**
 * @brief Pin mapping table.
 * @details Each index is a physical Pins.
 * 
 */
static const pin_mapping_t pin_map[] = 
{
    {.group = PIN_D, .bit = 0}, // Pin number 0
    {.group = PIN_D, .bit = 1}, // Pin number 1
    {.group = PIN_D, .bit = 2}, // Pin number 2
    {.group = PIN_D, .bit = 3}, // Pin number 3
    {.group = PIN_D, .bit = 4}, // Pin number 4
    {.group = PIN_D, .bit = 5}, // Pin number 5
    {.group = PIN_D, .bit = 6}, // Pin number 6
    {.group = PIN_D, .bit = 7}, // Pin number 7
    {.group = PIN_B, .bit = 0}, // Pin number 8
    {.group = PIN_B, .bit = 1}, // Pin number 9
    {.group = PIN_B, .bit = 2}, // Pin number 10
    {.group = PIN_B, .bit = 3}, // Pin number 11
    {.group = PIN_B, .bit = 4}, // Pin number 12
    {.group = PIN_B, .bit = 5}, // Pin number 13
    {.group = PIN_C, .bit = 0}, // Pin number 14
    {.group = PIN_C, .bit = 1}, // Pin number 15
    {.group = PIN_C, .bit = 2}, // Pin number 16
    {.group = PIN_C, .bit = 3}, // Pin number 17
    {.group = PIN_C, .bit = 4}, // Pin number 18
    {.group = PIN_C, .bit = 5}, // Pin number 19
};

/**
 * @brief Max number of pins
 * 
 */
static const uint8_t max_pin = sizeof(pin_map)/(sizeof(pin_map[0]));

/**
 * @brief pointer to the pinb hw block
 * 
 */
static volatile pin_t* pin_b = (volatile pin_t*)PINB_BASE_ADDRESS;

/**
 * @brief pointer to the pinc hw block
 * 
 */
static volatile pin_t* pin_c = (volatile pin_t*)PINC_BASE_ADDRESS;

/**
 * @brief pointer to the pind hw block
 * 
 */
static volatile pin_t* pin_d = (volatile pin_t*)PIND_BASE_ADDRESS;



/******************************************************************************/
/*                  STATIC FUNCTIONS                                          */
/******************************************************************************/

/**
 * @brief Set the Dir B object
 * 
 * @param pin pin to set
 * @param dir direction 
 * @return __STATIC_INLINE 
 */
__STATIC_INLINE void SetDirB(uint8_t pin, pin_dir_e dir)
{
    if (dir == PIN_DIR_OUTPUT)
    {
        pin_b->Direction.raw |= (1 << pin);
    }
    else
    {
        pin_b->Direction.raw &= ~(1 << pin);
    }
}

/**
 * @brief Set the Dir C object
 * 
 * @param pin pin to set
 * @param dir direction 
 * @return __STATIC_INLINE 
 */
__STATIC_INLINE void SetDirC(uint8_t pin, pin_dir_e dir)
{
    if (dir == PIN_DIR_OUTPUT)
    {
        pin_c->Direction.raw |= (1 << pin);
    }
    else
    {
        pin_c->Direction.raw &= ~(1 << pin);
    }
}

/**
 * @brief Set the Dir D object
 * 
 * @param pin pin to set
 * @param dir direction 
 * @return __STATIC_INLINE 
 */
__STATIC_INLINE void SetDirD(uint8_t pin, pin_dir_e dir)
{
    if (dir == PIN_DIR_OUTPUT)
    {
        pin_d->Direction.raw |= (1 << pin);
    }
    else
    {
        pin_d->Direction.raw &= ~(1 << pin);
    }
}


/******************************************************************************/
/*                  PUBLIC FUNCTIONS                                          */
/******************************************************************************/

/**
 * @ref Pin_set_direction
 */
drv_status_e Pin_set_direction(uint8_t pin_number, pin_dir_e dir)
{
    drv_status_e status = DRV_OK;
    if (pin_number >= max_pin)
    {
        status = DRV_ERROR_PARAM;
    }
    else
    {
        switch (pin_map[pin_number].group)
        {
            case PIN_B:
                SetDirB(pin_map[pin_number].bit, dir);
                break;
            case PIN_C:
                SetDirC(pin_map[pin_number].bit, dir);
                break; 
            case PIN_D:
                SetDirD(pin_map[pin_number].bit, dir);
                break;
            
            default:
                status = DRV_ERROR;
                break;
        }
    }
    return status;
}

/**
 * @ref Pin_read
 */
drv_status_e Pin_read(uint8_t pin_number, bool* dst)
{
    drv_status_e status = DRV_OK;
    if (pin_number >= max_pin)
    {
        status = DRV_ERROR_PARAM;
    }
    else
    {
        switch (pin_map[pin_number].group)
        {
            case PIN_B:
                *dst = (pin_b->Input.raw & (1 << pin_map[pin_number].bit)) != 0;
                break;
            case PIN_C:
                *dst = (pin_c->Input.raw & (1 << pin_map[pin_number].bit)) != 0;
                break; 
            case PIN_D:
                *dst = (pin_d->Input.raw & (1 << pin_map[pin_number].bit)) != 0;
                break;
            
            default:
                status = DRV_ERROR;
                break;
        }
    }
    return status;
}

/**
 * @ref Pin_write
 */
drv_status_e Pin_write(uint8_t pin_number, PIN_OUTPUT_E value)
{
    drv_status_e status = DRV_OK;
    if (pin_number >= max_pin)
    {
        status = DRV_ERROR_PARAM;
    }
    else
    {
        switch (pin_map[pin_number].group)
        {
            case PIN_B:
                if (value == PIN_HIGH)
                {
                    pin_b->Data.raw |= (1 << pin_map[pin_number].bit);
                }
                else
                {
                    pin_b->Data.raw &= ~(1 << pin_map[pin_number].bit);
                }
                break;
            case PIN_C:
                if (value == PIN_HIGH)
                {
                    pin_c->Data.raw |= (1 << pin_map[pin_number].bit);
                }
                else
                {
                    pin_c->Data.raw &= ~(1 << pin_map[pin_number].bit);
                }
                break; 
            case PIN_D:
                if (value == PIN_HIGH)
                {
                    pin_d->Data.raw |= (1 << pin_map[pin_number].bit);
                }
                else
                {
                    pin_d->Data.raw &= ~(1 << pin_map[pin_number].bit);
                }
                break;
            
            default:
                status = DRV_ERROR;
                break;
        }
    }
    return status;
}

/**
 * @ref Pins.h
 */
drv_status_e Pin_Toggle(uint8_t pin_number)
{
    drv_status_e status = DRV_OK;
    if (pin_number >= max_pin)
    {
        status = DRV_ERROR_PARAM;
    }
    else
    {
        switch (pin_map[pin_number].group)
        {
            case PIN_B:
                pin_b->Data.raw ^= (1 << pin_map[pin_number].bit);
                break;
            case PIN_C:
                pin_c->Data.raw ^= (1 << pin_map[pin_number].bit);
                break; 
            case PIN_D:
                pin_d->Data.raw ^= (1 << pin_map[pin_number].bit);
                break;
            
            default:
                status = DRV_ERROR;
                break;
        }
    }
    return status;
}