#include "i386/i386.h"
#include "tty.h"

void handle_timer_interrupt(void) { // Timer interrupt
    terminal_putchar('e');
}

void handle_interrupt_33(void) { // Keyboard interrupt
    terminal_putchar('e');
}
