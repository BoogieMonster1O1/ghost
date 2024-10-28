#include "i386/apic.h"
#include "i386/cpuid.h"
#include "i386/asm.h"

bool check_apic() {
    uint32_t eax, edx;
    cpuid(1, &eax, &edx);
    return edx & CPUID_FEAT_EDX_APIC;
}

void mask_interrupts() {
    outb(PIC1_COMMAND, 0x11);  // Start the initialization sequence
    outb(PIC1_DATA, 0x20);     // Set the offset for PIC1
    outb(PIC1_DATA, 0x04);     // Cascade mode
    outb(PIC1_DATA, 0x01);     // Complete the initialization

    outb(PIC2_COMMAND, 0x11);  // Initialize PIC2
    outb(PIC2_DATA, 0x28);     // Set the offset for PIC2
    outb(PIC2_DATA, 0x02);     // Cascade mode
    outb(PIC2_DATA, 0x01);     // Complete the initialization

    outb(PIC1_DATA, 0xFF);  // Mask all on PIC1
    outb(PIC2_DATA, 0xFF);  // Mask all on PIC2
}

void apic_init() {
    uint32_t *apic_sivr = (uint32_t *)(APIC_BASE + APIC_SPURIOUS_INT_VECTOR_REGISTER);
    *apic_sivr = 0x100 | 0xFF;
}
