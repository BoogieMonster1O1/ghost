# ghost

Stands for Ghost Has Operating System Technology. A simple operating system for learning purposes. A derivative of the [osdev.org Bare Bones](https://wiki.osdev.org/Bare_Bones) tutorial.

I have no idea what I'm doing. I'm not even sure if I'm doing anything at all. The wiki was right - there is zero instant gratification in this. But it's fun.

This is entirely driven by curiosity. I'm not sure if I'll ever get to a point where I can say "I've built an operating system". Clearly I'm way too confident in my abilities.

## Building

You need a cross-compiler. I built mine using the [osdev.org tutorial](https://wiki.osdev.org/GCC_Cross-Compiler). Add it to your path and test it by running `i686-elf-gcc --version`.

You can then build the OS by running `make all`.

### Running

I didn't try this on real hardware yet. I'm just using QEMU. You can run the OS by running `make run`.
