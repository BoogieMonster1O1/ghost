# ghost

stands for ghost has operating system sechnology. a simple operating system for learning purposes. a derivative of the [osdev.org bare bones](https://wiki.osdev.org/Bare_Bones) tutorial.

i have no idea what i'm doing. i'm not even sure if i'm doing anything at all. the wiki was right - there is zero instant gratification in this. but it's fun.

this is entirely driven by curiosity. i'm not sure if i'll ever get to a point where i can say "i've built an operating system". clearly i'm way too confident in my abilities.

## building

you need a cross-compiler. i built mine using the [osdev.org tutorial](https://wiki.osdev.org/GCC_Cross-Compiler). test it by running `i686-elf-gcc --version`.

you can then build the os by running `make all`.

### running

i didn't try this on real hardware yet. i'm just using qemu. you can run the os by running `make run`.
