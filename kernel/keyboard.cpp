#include "keyboard.h"
#include "console.h"
#include "shell.h"
#include <cstdint>

static uint8_t shift = 0;
static const char scancode_to_ascii[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=','\b','\t',
    'q','w','e','r','t','y','u','i','o','p','[',']','\n',0,'a','s',
    'd','f','g','h','j','k','l',';','\'','`',0,'\\','z','x','c','v',
    'b','n','m',',','.','/',0,'*',0,' ',0,0,0,0,0,0,0,0,0,0,0,0,0,
    '7','8','9','-','4','5','6','+','1','2','3','0','.'
};

void Keyboard::handler(uint8_t sc) {
    if (sc & 0x80) {
        sc &= 0x7F;
        if (sc == 0x2A || sc == 0x36) shift = 0;
    } else {
        if (sc == 0x2A || sc == 0x36) { shift = 1; return; }
        char c = scancode_to_ascii[sc];
        if (c) {
            if (shift) c = (c >= 'a' && c <= 'z') ? c - 32 : c;
            Shell::input_char(c);
        }
    }
}

void Keyboard::init() {
    asm volatile ("sti");
}

char Keyboard::getchar() {
    while (true) asm("hlt");
}
