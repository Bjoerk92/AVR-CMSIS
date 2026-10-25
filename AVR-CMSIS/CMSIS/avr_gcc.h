/**
 * @file avr-gcc.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-02
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#pragma GCC system_header    // treat file as system include file

/* Fallback for __has_builtin */
#ifndef __has_builtin
    #define __has_builtin(x) (0)
#endif

/* CMSIS compiler specific defines */
#ifndef __ASM
    #define __ASM                           __asm
#endif
#ifndef __INLINE
    #define __INLINE                        inline
#endif
#ifndef __STATIC_INLINE
    #define __STATIC_INLINE                 static inline
#endif
#ifndef __STATIC_FORCEINLINE
    #define __STATIC_FORCEINLINE            __attribute__((always_inline)) static inline
#endif
#ifndef __NO_RETURN
    #define __NO_RETURN                     __attribute__((__noreturn__))
#endif
#ifndef CMSIS_DEPRECATED
    #define CMSIS_DEPRECATED                __attribute__((deprecated))
#endif
#ifndef __USED
    #define __USED                          __attribute__((used))
#endif
#ifndef __WEAK
    #define __WEAK                          __attribute__((weak))
#endif
#ifndef __PACKED
    #define __PACKED                        __attribute__((packed, aligned(1)))
#endif
#ifndef __PACKED_STRUCT
    #define __PACKED_STRUCT                 struct __attribute__((packed, aligned(1)))
#endif
#ifndef __PACKED_UNION
    #define __PACKED_UNION                  union __attribute__((packed, aligned(1)))
#endif
#ifndef   __UNALIGNED_UINT16_WRITE
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT16_WRITE { uint16_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT16_WRITE(addr, val)    (void)((((struct T_UINT16_WRITE *)(void *)(addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT16_READ
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT16_READ { uint16_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT16_READ(addr)          (((const struct T_UINT16_READ *)(const void *)(addr))->v)
#endif
#ifndef   __UNALIGNED_UINT32_WRITE
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT32_WRITE { uint32_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT32_WRITE(addr, val)    (void)((((struct T_UINT32_WRITE *)(void *)(addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT32_READ
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT32_READ { uint32_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT32_READ(addr)          (((const struct T_UINT32_READ *)(const void *)(addr))->v)
#endif
#ifndef   __ALIGNED
  #define __ALIGNED(x)                           __attribute__((aligned(x)))
#endif
#ifndef   __RESTRICT
  #define __RESTRICT                             __restrict
#endif
#ifndef   __COMPILER_BARRIER
  #define __COMPILER_BARRIER()                   __ASM volatile("":::"memory")
#endif
#ifndef __NO_INIT
  #define __NO_INIT                              __attribute__ ((section (".noinit")))
#endif
#ifndef __ALIAS
  #define __ALIAS(x)                             __attribute__ ((alias(x)))
#endif

/* ##########################  Core Instruction Access  ######################### */
/** \defgroup CMSIS_Core_InstructionInterface CMSIS Core Instruction Interface
  Access to dedicated instructions
  @{
*/

/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP()         __ASM volatile ("nop")

/**
  \brief    Sleep operation
  \details  Sleep operation Will
 */
#define __SLEEP()        __ASM volatile ("sleep")

/**
  \brief Enable Sleep
  \details Enable sleep operation.
 */
#define __ENABLE_SLEEP      __ASM volatile ("ldi (1 << SE);"\
                                            "out MCUCR, r16")

/**
  \brief Break point
  \details Break point is used in the on-chip debug system. 
           When executed the cpu will be set into a stopped state.
 */
#define __BKPT() __ASM volatile ("BREAK")

/**
  \brief Reverse byte order (32bit)
  \details Reverse the byte order in unsigned integer value example 0x12345678 becomes 0x78563412
  \param [in]   value   Value to reverse
  \return               Reversed value
 */
__STATIC_FORCEINLINE uint32_t __REV(uint32_t value)
{
  return ((value & 0x000000FFUL) << 24) |
       ((value & 0x0000FF00UL) << 8)  |
       ((value & 0x00FF0000UL) >> 8)  |
       ((value & 0xFF000000UL) >> 24);
}

/**
  \brief Reverse byte order (16bit)
  \details Reverse the byte order within each halfword of a word. example 0x12345678 becomes 0x34127856
  \param [in]   value   Value to reverse
  \return               Reversed value
 */
__STATIC_FORCEINLINE uint32_t __REV16(uint32_t value)
{
    return  ((value & 0x000000FF) << 8) |
            ((value & 0x0000FF00) >> 8) |
            ((value & 0x00FF0000) << 8) |
            ((value & 0xFF000000) >> 8);
}

/**
  \brief Reverse byte order (16bit)
  \details Reverse the byte order within a 16-bit value and returns the signed result. example 0x0080 becomes 0x8000.
  \param [in]   value   Value to reverse
  \return               Revered value
 */
__STATIC_FORCEINLINE int16_t __RESSH(int16_t value)
{
    return  ((value & 0xFF00) >> 8) |
            ((value & 0x00FF) << 8);
}

__STATIC_FORCEINLINE uint32_t __ROR(uint32_t op1, uint32_t op2)
{
    op2 %= 32;
    if (op2 == 0U)
    {
        return op1;
    }
    return (op1 >> op2) | (op1 << (32U -op2));
}

/**
  \brief Reverse bit order of value
  \details Reverse the bit order of a given value
  \param [in]   value   Value to reverse
  \return               Reverse value
 */
__STATIC_FORCEINLINE uint32_t __RBIT(uint32_t value)
{
    uint32_t result = value;
    uint32_t s = (4U * 8U) - 1U;

    for (value >>= 1U; value != 0; value >>= 1U)
    {
        result <<= 1U;
        result |= value & 1U;
        s--;
    }
    result <<=s;
    return (result);
}

/**
  \brief Count leading zeros
  \details Counts the number of leading zeros of a data value
  \param [in]   value   Value to count the leading zero's
  \return               number of leading zero's in value
 */
__STATIC_FORCEINLINE uint8_t __CLZ(uint32_t value)
{
    if (value == 0U)
    {
        return 32U;
    }
    uint8_t count = 0U;
    while ((value & 0x80000000UL) == 0U)
    {
      count++;
      value <<= 1U;
    }
    return count;
}

/**
  \brief   Signed Saturate
  \details Saturates a signed value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (1..32)
  \return             Saturated value
 */
__STATIC_FORCEINLINE int32_t __SSAT(int32_t val, uint32_t sat)
{
    if ((sat >= 1U) && (sat <= 32U))
    {
        const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
        const int32_t min = -1 - max ;
        if (val > max)
        {
            return (max);
        }
        else if (val < min)
        {
            return (min);
        }
    }
    return (val);
}

/**
  \brief Unsigned Saturate
  \details Saturates an unsigned value.
  \param [in]   value   Value to be saturated
  \param [in]   sat     Bit position to saturate to (0..31)
  \return               Saturated value
 */
__STATIC_FORCEINLINE uint32_t __USAT(int32_t val, uint32_t sat)
{
    if (sat <= 31U)
    {
        const uint32_t max = ((1U << sat) - 1U);
        if (val > (int32_t)max)
        {
            return (max);
        }
        else if (val < 0)
        {
            return (0U);
        }
    }
    return ((uint32_t)val);
}

/**
  \brief Enable IRQ
  \details Enable the IRQ by setting the global IRQ
 */
__STATIC_FORCEINLINE void __enable_IRQ(void)
{
    __ASM volatile ("sei");
}

/**
  \brief Disable IRQ
  \details Disable the IRQ by clearing the global IRQ
 */
__STATIC_FORCEINLINE void __disable_IRQ(void)
{
    __ASM volatile ("cli");
}

