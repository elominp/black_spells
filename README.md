# black_spells
some black spells to test and learn various things with fun :)

To play with the x86_stack program use these compilers settings :

- Need to be compiled in C, not C++. The program could compile in C++ but the stack layout is different, so the program won't work.
- Need to be compiled at least in C99 (--std=c99 on gcc)
- Need to be compiled in 32 bits (with cross-compilation or 32 bits compiler).
- Don't use assembly with intel syntax (like MASM on Visual Studio)
- Any 32 bits gcc compiler should work
