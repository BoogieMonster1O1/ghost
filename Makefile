ASM_FILES = asm/boot.s
C_FILES = src/kernel.c src/tty.c

AS = i686-elf-as
CC = i686-elf-gcc

CFLAGS = -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I include

LDFLAGS = -T linker.ld -o ghost.bin -ffreestanding -O2 -nostdlib -lgcc

OBJ_FILES = $(ASM_FILES:.s=.o) $(C_FILES:.c=.o)

TARGET = ghost.bin

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES)

%.o: asm/%.s
	$(AS) $< -o $@

%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
