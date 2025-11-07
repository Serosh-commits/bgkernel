#pragma once
#include <cstdint>

class Console {
public:
    static void init();
    static void putchar(char c);
    static void printf(const char* fmt, ...);

private:
    static constexpr uint16_t* const VGA_BUFFER = (uint16_t*)0xB8000;
    static constexpr int WIDTH = 80;
    static constexpr int HEIGHT = 25;
    static int row, col;
    static uint8_t color;
};
