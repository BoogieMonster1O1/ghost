#ifndef TTY_H
#define TTY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "vga.h"

size_t strlen(const char* str);

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;
extern uint8_t terminal_bg_color;
extern uint16_t* terminal_buffer;

void terminal_initialize(void);

void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

void terminal_putchar(char c);

void terminal_write(const char* data, size_t size);

void terminal_writestring(const char* data);

void terminal_writenum(uint32_t num, uint8_t base);

#endif
