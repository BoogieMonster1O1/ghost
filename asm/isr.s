.section .text
.global isr_divide_error_0, isr_debug_1, isr_nmi_2, isr_breakpoint_3, isr_overflow_4
.global isr_bound_range_exceeded_5, isr_invalid_opcode_6, isr_device_not_available_7
.global isr_err_double_fault_8, isr_coprocessor_segment_overrun_9, isr_err_invalid_tss_10
.global isr_err_segment_not_present_11, isr_err_stack_segment_fault_12, isr_err_general_protection_fault_13
.global isr_err_page_fault_14, isr_reserved_15, isr_x87_floating_point_16
.global isr_err_alignment_check_17, isr_machine_check_18, isr_simd_floating_point_19
.global isr_virtualization_20, isr_control_protection_exception_21, isr_reserved_22
.global isr_reserved_23, isr_reserved_24, isr_reserved_25, isr_reserved_26
.global isr_reserved_27, isr_reserved_28, isr_reserved_29, isr_err_security_exception_30
.global isr_reserved_31

.extern handle_divide_error
.extern handle_debug
.extern handle_nmi
.extern handle_breakpoint
.extern handle_overflow
.extern handle_bound_range_exceeded
.extern handle_invalid_opcode
.extern handle_device_not_available
.extern handle_double_fault
.extern handle_coprocessor_segment_overrun
.extern handle_invalid_tss
.extern handle_segment_not_present
.extern handle_stack_segment_fault
.extern handle_general_protection_fault
.extern handle_page_fault
.extern handle_x87_floating_point
.extern handle_alignment_check
.extern handle_machine_check
.extern handle_simd_floating_point
.extern handle_virtualization
.extern handle_control_protection_exception
.extern handle_security_exception

isr_divide_error_0:
    call handle_divide_error
    iret

isr_debug_1:
    call handle_debug
    iret

isr_nmi_2:
    call handle_nmi
    iret

isr_breakpoint_3:
    call handle_breakpoint
    iret

isr_overflow_4:
    call handle_overflow
    iret

isr_bound_range_exceeded_5:
    call handle_bound_range_exceeded
    iret

isr_invalid_opcode_6:
    call handle_invalid_opcode
    iret

isr_device_not_available_7:
    call handle_device_not_available
    iret

isr_err_double_fault_8:
    call handle_double_fault
    iret

isr_coprocessor_segment_overrun_9:
    call handle_coprocessor_segment_overrun
    iret

isr_err_invalid_tss_10:
    call handle_invalid_tss
    iret

isr_err_segment_not_present_11:
    call handle_segment_not_present
    iret

isr_err_stack_segment_fault_12:
    call handle_stack_segment_fault
    iret

isr_err_general_protection_fault_13:
    call handle_general_protection_fault
    iret

isr_err_page_fault_14:
    call handle_page_fault
    iret

isr_reserved_15:
    call handle_reserved
    iret

isr_x87_floating_point_16:
    call handle_x87_floating_point
    iret

isr_err_alignment_check_17:
    call handle_alignment_check
    iret

isr_machine_check_18:
    call handle_machine_check
    iret

isr_simd_floating_point_19:
    call handle_simd_floating_point
    iret

isr_virtualization_20:
    call handle_virtualization
    iret

isr_control_protection_exception_21:
    call handle_control_protection_exception
    iret

isr_err_security_exception_30:
    call handle_security_exception
    iret

isr_reserved:
    call handle_reserved
    iret

.global isr_timer_32, isr_keyboard_33

isr_interrupt_32:
    call handle_timer_interrupt
    iret

isr_interrupt_33:
    call handle_interrupt_33
    iret

.global isr_table
isr_table:
    .long isr_divide_error_0
    .long isr_debug_1
    .long isr_nmi_2
    .long isr_breakpoint_3
    .long isr_overflow_4
    .long isr_bound_range_exceeded_5
    .long isr_invalid_opcode_6
    .long isr_device_not_available_7
    .long isr_err_double_fault_8
    .long isr_coprocessor_segment_overrun_9
    .long isr_err_invalid_tss_10
    .long isr_err_segment_not_present_11
    .long isr_err_stack_segment_fault_12
    .long isr_err_general_protection_fault_13
    .long isr_err_page_fault_14
    .long isr_reserved
    .long isr_x87_floating_point_16
    .long isr_err_alignment_check_17
    .long isr_machine_check_18
    .long isr_simd_floating_point_19
    .long isr_virtualization_20
    .long isr_control_protection_exception_21
    .long isr_reserved
    .long isr_reserved
    .long isr_reserved
    .long isr_reserved
    .long isr_reserved
    .long isr_reserved
    .long isr_reserved
    .long isr_reserved
    .long isr_err_security_exception_30
    .long isr_reserved
    .long isr_interrupt_32
    .long isr_interrupt_33
