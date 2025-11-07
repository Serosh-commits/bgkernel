#include "gdt.h"
#include <cstring>

GDTEntry GDT::entries[3];
GDTPtr   GDT::ptr;

void GDT::set_gate(int n, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    entries[n].low  = (base & 0xFFFF) | ((limit & 0xFFFF) << 16);
    entries[n].high = ((base >> 16) & 0xFF) | (access << 8) |
                      ((limit >> 16) & 0x0F) << 16 |
                      (gran << 24) | ((base >> 24) << 24);
}

void GDT::init() {
    set_gate(0, 0, 0, 0, 0);
    set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    ptr.limit = sizeof(entries) - 1;
    ptr.base  = (uint32_t)&entries;
    asm volatile ("lgdt %0" : : "m"(ptr));
    asm volatile (
        "mov %%esp, %%eax\n"
        "push $0x10\n"
        "push %%eax\n"
        "pushf\n"
        "push $0x08\n"
        "push $1f\n"
        "iret\n"
        "1:\n"
        "mov $0x10, %%ax\n"
        "mov %%ax, %%ds\n"
        "mov %%ax, %%es\n"
        "mov %%ax, %%fs\n"
        "mov %%ax, %%gs\n"
        "mov %%ax, %%ss\n" ::: "eax");
}
