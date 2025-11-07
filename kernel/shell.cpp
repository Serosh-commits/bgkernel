#include "shell.h"
#include "console.h"
#include <cstring>

char Shell::line[256];
int  Shell::pos = 0;

void Shell::run() {
    Console::printf("> ");
    while (true) { asm("hlt"); }
}

void Shell::input_char(char c) {
    if (c == '\n' || c == '\r') {
        Console::putchar('\n');
        line[pos] = 0;
        execute(line);
        pos = 0;
        Console::printf("> ");
    } else if (c == '\b') {
        if (pos) { --pos; Console::putchar('\b'); Console::putchar(' '); Console::putchar('\b'); }
    } else if (pos < sizeof(line)-1) {
        line[pos++] = c;
        Console::putchar(c);
    }
}

void Shell::execute(const char* cmd) {
    if (!strcmp(cmd, "help")) {
        Console::printf("help, clear, echo <msg>, reboot\n");
    } else if (!strcmp(cmd, "clear")) {
        Console::init();
    } else if (!strncmp(cmd, "echo ", 5)) {
        Console::printf("%s\n", cmd+5);
    } else if (!strcmp(cmd, "reboot")) {
        asm volatile ("cli; lidt 0; int $0");
    } else if (cmd[0]) {
        Console::printf("Unknown command: %s\n", cmd);
    }
}
