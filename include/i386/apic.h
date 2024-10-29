#ifndef APIC_H
#define APIC_H

#include <stdint.h>
#include <stdbool.h>

#define APIC_BASE 0xFEE00000
#define APIC_SPURIOUS_INT_VECTOR_REGISTER 0xF0
#define APIC_ENABLE 0x100

#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1

#define IOAPIC_BASE 0xFEC00000
#define IOAPIC_TIMER_VECTOR 0x20
#define IOAPIC_KEYBOARD_VECTOR 0x21

#define PIT_FREQUENCY 1193182

static inline void apic_write(uint32_t offset, uint32_t value) {
    volatile uint32_t *apic_reg = (uint32_t *)(APIC_BASE + offset);
    *apic_reg = value;
}

static inline uint32_t apic_read(uint32_t offset) {
    volatile uint32_t *apic_reg = (uint32_t *)(APIC_BASE + offset);
    return *apic_reg;
}

void apic_init();

bool check_apic();

void mask_interrupts();

void initialize_timer();

#endif
