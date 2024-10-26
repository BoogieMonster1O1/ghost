#include "tty.h"

void delay_cycle(int cycles) {
	for (int i = 0; i < cycles; i++) {
		asm volatile("nop");
	}
}

void kernel_main(void) {
	terminal_initialize();

	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("This is a test of the terminal.\n");
	for (int i = 0; i < 26; i++) {
		terminal_setcolor(vga_entry_color(i % 16, (i + 8) % 16));
		terminal_putchar('A' + i);
		delay_cycle(30000000);
	}
	terminal_setcolor(VGA_COLOR_WHITE);
	terminal_putchar('\n');
	terminal_writestring("This is white text.\n");
	terminal_setcolor(VGA_COLOR_LIGHT_GREY);
	terminal_writestring("Test complete.\n");
}
