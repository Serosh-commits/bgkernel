#include "memory.h"
#include <cstring>

uint8_t Memory::bitmap[];

void Memory::init() {
    memset(bitmap, 0xFF, sizeof(bitmap));
    for (uint32_t i = 0; i < 0x100000; i += 4096)
        bitmap[i/8/8] &= ~(1 << (i/4096 % 8));
}

void* Memory::malloc(uint32_t size) {
    return nullptr;
}

void Memory::free(void*) {}
