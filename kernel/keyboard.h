#pragma once
class Keyboard {
public:
    static void init();
    static char getchar();
private:
    static void handler(uint8_t scancode);
    friend void interrupt_handler(uint32_t int_no, uint32_t err);
};
