TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra -fno-builtin -fPIC
TDK_ASM    = nasm

.PHONY: clean

all: posix_sdk

clean:
	rm -rf *.o sdk_testapp *~ *.exe

posix_sdk: ctype.o errno.o math.o math_asm.o netdb.o stdlib.o stdlib_asm.o string.o string_asm.o fenv.o unistd.o strings.o libgen.o

ctype.o: ctype.c ctype.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

errno.o: errno.c errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

math.o: math.c math.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

netdb.o: netdb.c netdb.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
    
math_asm.o: math.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 $< -o $@

stdlib.o: stdlib.c stdlib.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

stdlib_asm.o: stdlib.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 $< -o $@

string.o: string.c string.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

string_asm.o: string.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 $< -o $@

strings.o: strings.c strings.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

fenv.o: fenv.c fenv.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

unistd.o: unistd.c unistd.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

libgen.o: libgen.c libgen.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
