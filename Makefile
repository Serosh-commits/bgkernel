CXX = i686-elf-g++
AS  = i686-elf-as
LD  = i686-elf-ld

CXXFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -Ikernel
ASFLAGS  = 
LDFLAGS  = -T linker.ld -nostdlib

OBJS = boot/boot.o \
       kernel/kernel.o kernel/console.o kernel/gdt.o kernel/idt.o \
       kernel/isr.o kernel/keyboard.o kernel/memory.o kernel/shell.o \
       kernel/interrupt.o

all: myos.iso

myos.iso: kernel.bin grub.cfg
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/
	cp grub.cfg iso/boot/grub/
	grub-mkrescue -o myos.iso iso

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.S
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -rf *.o boot/*.o kernel/*.o kernel.bin iso myos.iso
