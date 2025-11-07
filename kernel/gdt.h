#pragma once
struct GDTEntry { uint32_t low, high; };
struct GDTPtr { uint16_t limit; uint32_t base; } __attribute__((packed));

class GDT {
public:
    static void init();
private:
    static GDTEntry entries[3];
    static GDTPtr ptr;
    static void set_gate(int n, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);
};
