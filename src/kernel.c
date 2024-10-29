#include <stdint.h>

#include "i386/i386.h"
#include "idt.h"
#include "tty.h"
#include "i386/asm.h"

#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA 0xCFC

uint32_t pci_config_read(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset) {
    uint32_t address = (1 << 31) | (bus << 16) | (device << 11) | (function << 8) | (offset & 0xFC);
    outl(PCI_CONFIG_ADDRESS, address);
    return inl(PCI_CONFIG_DATA);
}

void enumerate_pci_devices() {
    for (uint8_t bus = 0; bus < 128; bus++) {
        for (uint8_t device = 0; device < 32; device++) {
            for (uint8_t function = 0; function < 8; function++) {
                uint16_t vendor_id = pci_config_read(bus, device, function, 0x00) & 0xFFFF;
                if (vendor_id != 0xFFFF) {
                    uint16_t device_id = (pci_config_read(bus, device, function, 0x00) >> 16) & 0xFFFF;
                    terminal_writestring("PCI: Bus ");
                    terminal_writenum(bus, 10);
                    terminal_writestring(", Device ");
                    terminal_writenum(device, 10);
                    terminal_writestring(", Function ");
                    terminal_writenum(function, 10);
                    terminal_writestring(", Vendor ID: 0x");
                    terminal_writenum(vendor_id, 16);
                    terminal_writestring(", Device ID: 0x");
                    terminal_writenum(device_id, 16);
                    terminal_putchar('\n');
                }
            }
        }
    }
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
    terminal_writestring("Test complete.\n");

    enumerate_pci_devices();
}
