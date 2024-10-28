#include "i386/cpuid.h"

void cpuid(uint32_t code, uint32_t *eax, uint32_t *edx) {
    uint32_t ebx, ecx;
    __asm__ volatile("cpuid"
                     : "=a"(*eax), "=b"(ebx), "=c"(ecx), "=d"(*edx)
                     : "a"(code));
}

uint32_t cpuid_edx() {
    uint32_t eax, edx;
    cpuid(1, &eax, &edx);
    return edx;
}
