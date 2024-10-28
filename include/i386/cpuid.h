#ifndef _CPUID_H
#define _CPUID_H

#include <stdint.h>

#define CPUID_FEAT_EDX_FPU (1 << 0)     // Floating Point Unit
#define CPUID_FEAT_EDX_VME (1 << 1)     // Virtual Mode Extensions
#define CPUID_FEAT_EDX_DE (1 << 2)      // Debugging Extensions
#define CPUID_FEAT_EDX_PSE (1 << 3)     // Page Size Extension
#define CPUID_FEAT_EDX_TSC (1 << 4)     // Time Stamp Counter
#define CPUID_FEAT_EDX_MSR (1 << 5)     // Model-Specific Registers
#define CPUID_FEAT_EDX_PAE (1 << 6)     // Physical Address Extension
#define CPUID_FEAT_EDX_MCE (1 << 7)     // Machine Check Exception
#define CPUID_FEAT_EDX_CX8 (1 << 8)     // CMPXCHG8B Instruction
#define CPUID_FEAT_EDX_APIC (1 << 9)    // APIC On-Chip
#define CPUID_FEAT_EDX_SEP (1 << 11)    // SYSENTER/SYSEXIT
#define CPUID_FEAT_EDX_MTRR (1 << 12)   // Memory Type Range Registers
#define CPUID_FEAT_EDX_PGE (1 << 13)    // Page Global Enable
#define CPUID_FEAT_EDX_MCA (1 << 14)    // Machine Check Architecture
#define CPUID_FEAT_EDX_CMOV (1 << 15)   // CMOV Instruction
#define CPUID_FEAT_EDX_PAT (1 << 16)    // Page Attribute Table
#define CPUID_FEAT_EDX_PSE36 (1 << 17)  // 36-bit Page Size Extension
#define CPUID_FEAT_EDX_PSN (1 << 18)    // Processor Serial Number
#define CPUID_FEAT_EDX_CLFSH (1 << 19)  // CLFLUSH Instruction
#define CPUID_FEAT_EDX_DS (1 << 21)     // Debug Store
#define CPUID_FEAT_EDX_ACPI (1 << 22)   // Thermal Monitor and Software Clock Facilities
#define CPUID_FEAT_EDX_MMX (1 << 23)    // MMX
#define CPUID_FEAT_EDX_FXSR (1 << 24)   // FXSAVE and FXRSTOR Instructions
#define CPUID_FEAT_EDX_SSE (1 << 25)    // SSE
#define CPUID_FEAT_EDX_SSE2 (1 << 26)   // SSE2
#define CPUID_FEAT_EDX_SS (1 << 27)     // Self Snoop
#define CPUID_FEAT_EDX_HTT (1 << 28)    // Hyper-Threading Technology
#define CPUID_FEAT_EDX_TM1 (1 << 29)    // Thermal Monitor 1
#define CPUID_FEAT_EDX_IA64 (1 << 30)   // IA64 (Itanium) Processor
#define CPUID_FEAT_EDX_PBE (1 << 31)    // Pending Break Enable

#define CPUID_FEAT_ECX_SSE3 (1 << 0)           // SSE3
#define CPUID_FEAT_ECX_PCLMULQDQ (1 << 1)      // PCLMULQDQ Instruction
#define CPUID_FEAT_ECX_DTES64 (1 << 2)         // 64-bit Debug Store
#define CPUID_FEAT_ECX_MONITOR (1 << 3)        // MONITOR and MWAIT Instructions
#define CPUID_FEAT_ECX_DS_CPL (1 << 4)         // CPL Qualified Debug Store
#define CPUID_FEAT_ECX_VMX (1 << 5)            // Virtual Machine Extensions
#define CPUID_FEAT_ECX_SMX (1 << 6)            // Safer Mode Extensions
#define CPUID_FEAT_ECX_EST (1 << 7)            // Enhanced SpeedStep
#define CPUID_FEAT_ECX_TM2 (1 << 8)            // Thermal Monitor 2
#define CPUID_FEAT_ECX_SSSE3 (1 << 9)          // SSSE3
#define CPUID_FEAT_ECX_CID (1 << 10)           // Context ID
#define CPUID_FEAT_ECX_FMA (1 << 12)           // Fused Multiply-Add
#define CPUID_FEAT_ECX_CX16 (1 << 13)          // CMPXCHG16B
#define CPUID_FEAT_ECX_ETPRD (1 << 14)         // Extended xAPIC ID
#define CPUID_FEAT_ECX_PDCM (1 << 15)          // Performance Capabilities
#define CPUID_FEAT_ECX_PCID (1 << 17)          // Process-Context Identifiers
#define CPUID_FEAT_ECX_DCA (1 << 18)           // Direct Cache Access
#define CPUID_FEAT_ECX_SSE4_1 (1 << 19)        // SSE4.1
#define CPUID_FEAT_ECX_SSE4_2 (1 << 20)        // SSE4.2
#define CPUID_FEAT_ECX_X2APIC (1 << 21)        // x2APIC
#define CPUID_FEAT_ECX_MOVBE (1 << 22)         // MOVBE Instruction
#define CPUID_FEAT_ECX_POPCNT (1 << 23)        // POPCNT Instruction
#define CPUID_FEAT_ECX_TSC_DEADLINE (1 << 24)  // TSC-Deadline
#define CPUID_FEAT_ECX_AES (1 << 25)           // AES Instructions
#define CPUID_FEAT_ECX_XSAVE (1 << 26)         // XSAVE/XRSTOR
#define CPUID_FEAT_ECX_OSXSAVE (1 << 27)       // OS-Enabled Extended State Management
#define CPUID_FEAT_ECX_AVX (1 << 28)           // AVX
#define CPUID_FEAT_ECX_F16C (1 << 29)          // 16-Bit Floating Point Instructions
#define CPUID_FEAT_ECX_RDRAND (1 << 30)        // RDRAND
#define CPUID_FEAT_ECX_HYPERVISOR (1 << 31)    // Running on a Hypervisor

void cpuid(uint32_t code, uint32_t *eax, uint32_t *edx);

uint32_t cpuid_edx();

#endif
