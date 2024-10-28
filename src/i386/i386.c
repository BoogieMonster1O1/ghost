#include <i386/i386.h>

void delay_cycle(int cycles) {
    for (int i = 0; i < cycles; i++) {
        asm volatile("nop");
    }
}
