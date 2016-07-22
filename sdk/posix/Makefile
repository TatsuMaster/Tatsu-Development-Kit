TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra -fno-builtin
TDK_ASM    = nasm

.PHONY: clean

all: posix_sdk

clean:
	rm -rf *.o sdk_testapp *~ *.exe

posix_sdk: ctype.o errno.o string.o string_asm.o

ctype.o: ctype.c ctype.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

errno.o: errno.c errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

string.o: string.c string.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

string_asm.o: string.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 -g $< -o $@
