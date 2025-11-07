#pragma once
class Memory {
public:
    static void init();
    static void* malloc(uint32_t size);
    static void free(void* ptr);
private:
    static constexpr uint32_t HEAP_START = 0x100000;
    static constexpr uint32_t HEAP_SIZE  = 16*1024*1024;
    static uint8_t bitmap[HEAP_SIZE/8/8];
};
