#pragma once
class Shell {
public:
    static void run();
    static void input_char(char c);
private:
    static char line[256];
    static int pos;
    static void execute(const char* cmd);
};
