#pragma once
#include <cstdint>

struct IDTEntry {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t  zero;
    uint8_t  type_attr;
    uint16_t offset_high;
} __attribute__((packed));

struct IDTPtr { uint16_t limit; uint32_t base; } __attribute__((packed));

class IDT {
public:
    static void init();
    static void set_gate(uint8_t n, uint32_t handler);
private:
    static IDTEntry entries[256];
    static IDTPtr   ptr;
};
