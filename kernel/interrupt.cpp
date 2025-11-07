#include "console.h"
#include "keyboard.h"
#include <cstdint>

static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

extern "C" void interrupt_handler(uint32_t int_no, uint32_t err) {
    if (int_no == 33) {
        uint8_t sc = inb(0x60);
        Keyboard::handler(sc);
        outb(0x20, 0x20);
    } else if (int_no < 32) {
        Console::printf("Exception %d\n", int_no);
        asm("cli; hlt");
    }
}
