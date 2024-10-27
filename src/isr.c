#include "tty.h"

void exception_handler() {
    terminal_writestring("System Halted.\n");
    __asm__ volatile ("cli; hlt");
}

void handle_divide_error() {
    terminal_writestring("Divide Error Exception\n");
    exception_handler();  // Divide Error Exception
}

void handle_debug() {
    terminal_writestring("Debug Exception\n");
    exception_handler();  // Debug Exception
}

void handle_nmi() {
    terminal_writestring("Non-Maskable Interrupt\n");
    exception_handler();  // Non-Maskable Interrupt
}

void handle_breakpoint() {
    terminal_writestring("Breakpoint Exception\n");
    exception_handler();  // Breakpoint Exception
}

void handle_overflow() {
    terminal_writestring("Overflow Exception\n");
    exception_handler();  // Overflow Exception
}

void handle_bound_range_exceeded() {
    terminal_writestring("Bound Range Exceeded Exception\n");
    exception_handler();  // Bound Range Exceeded Exception
}

void handle_invalid_opcode() {
    terminal_writestring("Invalid Opcode Exception\n");
    exception_handler();  // Invalid Opcode Exception
}

void handle_device_not_available() {
    terminal_writestring("Device Not Available Exception\n");
    exception_handler();  // Device Not Available Exception
}

void handle_double_fault() {
    terminal_writestring("Double Fault Exception\n");
    exception_handler();  // Double Fault Exception
}

void handle_coprocessor_segment_overrun() {
    terminal_writestring("Coprocessor Segment Overrun Exception\n");
    exception_handler();  // Coprocessor Segment Overrun Exception
}

void handle_invalid_tss() {
    terminal_writestring("Invalid TSS Exception\n");
    exception_handler();  // Invalid TSS Exception
}

void handle_segment_not_present() {
    terminal_writestring("Segment Not Present Exception\n");
    exception_handler();  // Segment Not Present Exception
}

void handle_stack_segment_fault() {
    terminal_writestring("Stack Segment Fault Exception\n");
    exception_handler();  // Stack Segment Fault Exception
}

void handle_general_protection_fault() {
    terminal_writestring("General Protection Fault Exception\n");
    exception_handler();  // General Protection Fault Exception
}

void handle_page_fault() {
    terminal_writestring("Page Fault Exception\n");
    exception_handler();  // Page Fault Exception
}

void handle_reserved() {
    terminal_writestring("Reserved Exception\n");
    exception_handler();  // Reserved Exception
}

void handle_x87_floating_point() {
    terminal_writestring("x87 Floating Point Exception\n");
    exception_handler();  // x87 Floating Point Exception
}

void handle_alignment_check() {
    terminal_writestring("Alignment Check Exception\n");
    exception_handler();  // Alignment Check Exception
}

void handle_machine_check() {
    terminal_writestring("Machine Check Exception\n");
    exception_handler();  // Machine Check Exception
}

void handle_simd_floating_point() {
    terminal_writestring("SIMD Floating Point Exception\n");
    exception_handler();  // SIMD Floating Point Exception
}

void handle_virtualization() {
    terminal_writestring("Virtualization Exception\n");
    exception_handler();  // Virtualization Exception
}

void handle_control_protection_exception() {
    terminal_writestring("Control Protection Exception\n");
    exception_handler();  // Control Protection Exception
}

void handle_security_exception() {
    terminal_writestring("Security Exception\n");
    exception_handler();  // Security Exception
}
