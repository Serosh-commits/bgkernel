# wired — A Minimal x86 Kernel in C++

![MyOS Boot](https://img.shields.io/badge/MyOS-v0.1-brightgreen) ![C++](https://img.shields.io/badge/C++-17-blue) ![x86](https://img.shields.io/badge/Arch-x86-orange) ![Bootable](https://img.shields.io/badge/Bootable-ISO-success)

> **A fully working, bootable, 32-bit x86 operating system kernel written in modern C++ — with a shell, keyboard input, VGA console, and memory management.**

---

## Features

- **Multiboot-compliant** (boots with GRUB)
- **Protected mode** with GDT & IDT
- **VGA text console** (80×25, scrolling, `printf`)
- **PS/2 keyboard driver** (full ASCII, shift support)
- **Interactive shell** with commands:
  - `help` — list commands
  - `echo <msg>` — print message
  - `clear` — clear screen
  - `reboot` — triple fault reboot
- **Simple bitmap memory allocator**
- **No external dependencies** — pure freestanding C++

---

## Demo

```text
Welcome to MyOS v0.1
> echo Hello, World!
Hello, World!
> help
help, clear, echo <msg>, reboot
> reboot
[system reboots]
