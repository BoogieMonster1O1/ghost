#ifndef I386_H
#define I386_H

#include <stdbool.h>
#include <stdint.h>

#include "apic.h"
#include "cpuid.h"

void delay_cycle(int cycles);

#endif
