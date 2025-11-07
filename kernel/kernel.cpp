extern "C" void kmain(void) {
    Console::init();
    GDT::init();
    IDT::init();
    Keyboard::init();
    Memory::init();

    Console::printf("Welcome to MyOS v0.1\n");
    Shell::run();
}
