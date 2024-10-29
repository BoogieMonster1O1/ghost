#include "i386/i386.h"
#include "tty.h"

static uint16_t timer_ticks = 0;

void handle_timer_interrupt(void) {  // Timer interrupt
    terminal_writestring("Timer interrupt\n");
    apic_write(0x380, 0);
    apic_write(0x320, 0);
    terminal_writestring("Timer interrupt lol\n");
}

void handle_interrupt_33(void) {  // Keyboard interrupt
    terminal_putchar('e');
}
