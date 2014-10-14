global isr_wrapper
extern interrupt_handler
align 4
 
isr_wrapper:
    pushad
    call interrupt_handler
    popad
    iret
