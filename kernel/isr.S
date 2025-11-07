#define ISR(n) \
    .global isr##n; \
    isr##n: \
        push $0; \
        push $##n; \
        jmp common_stub

ISR(0)  ISR(1)  ISR(2)  ISR(3)  ISR(4)  ISR(5)  ISR(6)  ISR(7)
ISR(8)  ISR(9)  ISR(10) ISR(11) ISR(12) ISR(13) ISR(14) ISR(15)
ISR(16) ISR(17) ISR(18) ISR(19) ISR(20) ISR(21) ISR(22) ISR(23)
ISR(24) ISR(25) ISR(26) ISR(27) ISR(28) ISR(29) ISR(30) ISR(31)

#define IRQ(n, i) \
    .global irq##n; \
    irq##n: \
        push $0; \
        push $##i; \
        jmp common_stub

IRQ(0,32) IRQ(1,33) IRQ(2,34) IRQ(3,35) IRQ(4,36) IRQ(5,37) IRQ(6,38) IRQ(7,39)
IRQ(8,40) IRQ(9,41) IRQ(10,42) IRQ(11,43) IRQ(12,44) IRQ(13,45) IRQ(14,46) IRQ(15,47)

.extern interrupt_handler
common_stub:
    pusha
    mov %ds, %eax
    push %eax
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    call interrupt_handler
    pop %eax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    popa
    add $8, %esp
    iret
