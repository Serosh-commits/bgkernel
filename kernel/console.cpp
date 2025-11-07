#include "console.h"
#include <cstdarg>

int Console::row = 0;
int Console::col = 0;
uint8_t Console::color = 0x0F;

void Console::init() {
    for (int i = 0; i < WIDTH * HEIGHT; ++i)
        VGA_BUFFER[i] = (color << 8) | ' ';
}

void Console::putchar(char c) {
    if (c == '\n') {
        ++row; col = 0;
    } else if (c == '\r') {
        col = 0;
    } else if (c == '\b') {
        if (col) --col;
    } else {
        VGA_BUFFER[row * WIDTH + col] = (color << 8) | c;
        if (++col == WIDTH) { col = 0; ++row; }
    }
    if (row == HEIGHT) {
        for (int y = 1; y < HEIGHT; ++y)
            for (int x = 0; x < WIDTH; ++x)
                VGA_BUFFER[(y-1)*WIDTH + x] = VGA_BUFFER[y*WIDTH + x];
        for (int x = 0; x < WIDTH; ++x)
            VGA_BUFFER[(HEIGHT-1)*WIDTH + x] = (color << 8) | ' ';
        row = HEIGHT - 1;
    }
}

void Console::printf(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    char buf[256];
    int n = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    for (int i = 0; i < n; ++i) putchar(buf[i]);
}
