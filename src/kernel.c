#include <stdint.h>
#include "i386/i386.h"
#include "idt.h"
#include "tty.h"

static inline uint32_t read_apic_register(uint32_t *reg) {
    return *reg;
}

#define APIC_VERSION_REGISTER (APIC_BASE + 0x30)

// Function to check if the Local APIC is initialized
int is_apic_initialized() {
    uint32_t *apic_version_reg = (uint32_t *)APIC_VERSION_REGISTER;
    uint32_t version = read_apic_register(apic_version_reg);

    // Check if the version is valid (should not be zero)
    return (version);
}

void kernel_main(void) {
    idt_init();
    mask_interrupts();
    terminal_initialize();

    terminal_writestring("Welcome to ghost\n");

    uint32_t cpuid = cpuid_edx();

    if (cpuid & CPUID_FEAT_EDX_APIC) {
        terminal_writestring("APIC is supported\n");
    } else {
        terminal_writestring("APIC is not supported\n");
        return;
    }

    apic_init();

    if (cpuid & CPUID_FEAT_EDX_FPU) {
        terminal_writestring("FPU is supported\n");
    } else {
        terminal_writestring("FPU is not supported\n");
        return;
    }

    terminal_writestring("This is a test of the terminal.\n");
    for (int i = 0; i < 26; i++) {
        terminal_setcolor(vga_entry_color(i % 16, (i + 8) % 16));
        terminal_putchar('A' + i);
        delay_cycle(20000000);
    }
                  terminal_setcolor(VGA_COLOR_WHITE);
    terminal_putchar('\n');
    terminal_writestring("This is white text.\n");
    terminal_setcolor(VGA_COLOR_LIGHT_GREY);
    terminal_writestring("Test complete.\n");
}
