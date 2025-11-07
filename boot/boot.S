#define ASM_FILE 1
#include "multiboot.h"

    .section .multiboot
    .align 4
    .long MULTIBOOT_HEADER_MAGIC
    .long MULTIBOOT_HEADER_FLAGS
    .long -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

    .section .bss
    .align 16
stack_bottom:
    .skip 16384
stack_top:

    .section .text
    .global _start
    .type _start, @function
_start:
    mov $stack_top, %esp
    call kmain
    cli
1:  hlt
    jmp 1b
