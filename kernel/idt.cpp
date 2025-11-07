#include "idt.h"
#include <cstring>

IDTEntry IDT::entries[256];
IDTPtr   IDT::ptr;

void IDT::set_gate(uint8_t n, uint32_t handler) {
    entries[n].offset_low  = handler & 0xFFFF;
    entries[n].selector    = 0x08;
    entries[n].zero        = 0;
    entries[n].type_attr   = 0x8E;
    entries[n].offset_high = (handler >> 16) & 0xFFFF;
}

extern "C" void isr0(); extern "C" void isr1(); extern "C" void isr2(); extern "C" void isr3();
extern "C" void isr4(); extern "C" void isr5(); extern "C" void isr6(); extern "C" void isr7();
extern "C" void isr8(); extern "C" void isr9(); extern "C" void isr10(); extern "C" void isr11();
extern "C" void isr12(); extern "C" void isr13(); extern "C" void isr14(); extern "C" void isr15();
extern "C" void isr16(); extern "C" void isr17(); extern "C" void isr18(); extern "C" void isr19();
extern "C" void isr20(); extern "C" void isr21(); extern "C" void isr22(); extern "C" void isr23();
extern "C" void isr24(); extern "C" void isr25(); extern "C" void isr26(); extern "C" void isr27();
extern "C" void isr28(); extern "C" void isr29(); extern "C" void isr30(); extern "C" void isr31();

extern "C" void irq0(); extern "C" void irq1(); extern "C" void irq2(); extern "C" void irq3();
extern "C" void irq4(); extern "C" void irq5(); extern "C" void irq6(); extern "C" void irq7();
extern "C" void irq8(); extern "C" void irq9(); extern "C" void irq10(); extern "C" void irq11();
extern "C" void irq12(); extern "C" void irq13(); extern "C" void irq14(); extern "C" void irq15();

void IDT::init() {
    ptr.limit = sizeof(entries) - 1;
    ptr.base  = (uint32_t)&entries;
    memset(&entries, 0, sizeof(entries));

    set_gate(0,  (uint32_t)isr0);  set_gate(1,  (uint32_t)isr1);
    set_gate(2,  (uint32_t)isr2);  set_gate(3,  (uint32_t)isr3);
    set_gate(4,  (uint32_t)isr4);  set_gate(5,  (uint32_t)isr5);
    set_gate(6,  (uint32_t)isr6);  set_gate(7,  (uint32_t)isr7);
    set_gate(8,  (uint32_t)isr8);  set_gate(9,  (uint32_t)isr9);
    set_gate(10, (uint32_t)isr10); set_gate(11, (uint32_t)isr11);
    set_gate(12, (uint32_t)isr12); set_gate(13, (uint32_t)isr13);
    set_gate(14, (uint32_t)isr14); set_gate(15, (uint32_t)isr15);
    set_gate(16, (uint32_t)isr16); set_gate(17, (uint32_t)isr17);
    set_gate(18, (uint32_t)isr18); set_gate(19, (uint32_t)isr19);
    set_gate(20, (uint32_t)isr20); set_gate(21, (uint32_t)isr21);
    set_gate(22, (uint32_t)isr22); set_gate(23, (uint32_t)isr23);
    set_gate(24, (uint32_t)isr24); set_gate(25, (uint32_t)isr25);
    set_gate(26, (uint32_t)isr26); set_gate(27, (uint32_t)isr27);
    set_gate(28, (uint32_t)isr28); set_gate(29, (uint32_t)isr29);
    set_gate(30, (uint32_t)isr30); set_gate(31, (uint32_t)isr31);

    set_gate(32, (uint32_t)irq0);  set_gate(33, (uint32_t)irq1);
    set_gate(34, (uint32_t)irq2);  set_gate(35, (uint32_t)irq3);
    set_gate(36, (uint32_t)irq4);  set_gate(37, (uint32_t)irq5);
    set_gate(38, (uint32_t)irq6);  set_gate(39, (uint32_t)irq7);
    set_gate(40, (uint32_t)irq8);  set_gate(41, (uint32_t)irq9);
    set_gate(42, (uint32_t)irq10); set_gate(43, (uint32_t)irq11);
    set_gate(44, (uint32_t)irq12); set_gate(45, (uint32_t)irq13);
    set_gate(46, (uint32_t)irq14); set_gate(47, (uint32_t)irq15);

    asm volatile ("lidt %0" : : "m"(ptr));
}
