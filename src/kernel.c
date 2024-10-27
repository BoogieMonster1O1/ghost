#include "tty.h"
#include "idt.h"
#include "i386.h"

#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1

bool check_apic() {
   uint32_t eax, edx;
   cpuid(1, &eax, &edx);
   return edx & CPUID_FEAT_EDX_APIC;
}

void mask_interrupts() {
    outb(PIC1_COMMAND, 0x11); // Start the initialization sequence
    outb(PIC1_DATA, 0x20);    // Set the offset for PIC1
    outb(PIC1_DATA, 0x04);    // Cascade mode
    outb(PIC1_DATA, 0x01);    // Complete the initialization

    outb(PIC2_COMMAND, 0x11); // Initialize PIC2
    outb(PIC2_DATA, 0x28);    // Set the offset for PIC2
    outb(PIC2_DATA, 0x02);     // Cascade mode
    outb(PIC2_DATA, 0x01);     // Complete the initialization

    outb(PIC1_DATA, 0xFF);     // Mask all on PIC1
    outb(PIC2_DATA, 0xFF);     // Mask all on PIC2
}

void kernel_main(void) {
	idt_init();
	mask_interrupts();
	terminal_initialize();

	terminal_writestring("Welcome to gjost\n");

	if (check_apic()) {
		terminal_writestring("APIC detected.\n");
	} else {
		terminal_writestring("APIC not detected.\n");
		terminal_writestring("This kernel requires APIC support.\n");
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
