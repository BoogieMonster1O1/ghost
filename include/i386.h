#ifndef ASM_H
#define ASM_H

#include <stdint.h>

#define CPUID_FEAT_EDX_APIC (1 << 9)

void cpuid(uint32_t code, uint32_t *eax, uint32_t *edx)
{
    uint32_t ebx, ecx;
    __asm__ volatile("cpuid"
                     : "=a"(*eax), "=b"(ebx), "=c"(ecx), "=d"(*edx)
                     : "a"(code));
}

static inline void outb(uint16_t port, uint8_t value)
{
    __asm__ volatile("outb %0, %1" : : "a"(value), "Nd"(port));
}

void delay_cycle(int cycles)
{
    for (int i = 0; i < cycles; i++)
    {
        asm volatile("nop");
    }
}

#endif
