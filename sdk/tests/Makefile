TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra -fno-builtin -fPIC
TDK_ASM    = nasm

all: sdk_testapp

.PHONY: clean
clean:
	rm -rf *.o sdk_testapp *~ *.exe

sdk_testapp: sdk_testapp.o ttf.o posix_tests.o crt_tests.o crt_limits_tests.o posix_netdb_tests.o posix_fenv_tests.o posix_errno_tests.o posix_arpa_inet_tests.o posix_signal_tests.o posix_ctype_tests.o ttf_unix.o stdlib.o stdlib_asm.o posix_stdlib_tests.o string.o posix_string_tests.o errno.o ctype.o string_asm.o fenv.o math.o math_asm.o posix_math_tests.o
	@echo "  [LD ] Linking $@"; $(TDK_CC) sdk_testapp.o ttf.o posix_tests.o crt_tests.o crt_limits_tests.o posix_netdb_tests.o posix_fenv_tests.o posix_errno_tests.o posix_arpa_inet_tests.o posix_signal_tests.o ttf_unix.o stdlib.o stdlib_asm.o posix_stdlib_tests.o string.o errno.o ctype.o posix_string_tests.o posix_ctype_tests.o string_asm.o math_asm.o fenv.o math.o posix_math_tests.o -o sdk_testapp

crt_tests.o: crt_tests.c crt_tests.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

crt_limits_tests.o: crt_limits_tests.c crt_limits_tests.h ../crt/limits.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

ttf.o: ../../ttf/ttf.c ../../ttf/ttf.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
    
ttf_unix.o: ../../ttf/ttf_unix.c ../../ttf/ttf_unix.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_ctype_tests.o: posix_ctype_tests.c posix_ctype_tests.h ../posix/ctype.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_arpa_inet_tests.o: posix_arpa_inet_tests.c posix_arpa_inet_tests.h ../posix/arpa/inet.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_errno_tests.o: posix_errno_tests.c posix_errno_tests.h ../posix/errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_fenv_tests.o: posix_fenv_tests.c posix_fenv_tests.h ../posix/fenv.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_math_tests.o: posix_math_tests.c posix_math_tests.h ../posix/math.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_netdb_tests.o: posix_netdb_tests.c posix_netdb_tests.h ../posix/netdb.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_signal_tests.o: posix_signal_tests.c posix_signal_tests.h ../posix/signal.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_stdlib_tests.o: posix_stdlib_tests.c posix_stdlib_tests.h ../posix/stdlib.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
    
posix_string_tests.o: posix_string_tests.c posix_string_tests.h ../posix/string.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

errno.o: ../posix/errno.c ../posix/errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

ctype.o: ../posix/ctype.c ../posix/ctype.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

math.o: ../posix/math.c ../posix/math.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -g -o $@ -c $<

math_asm.o: ../posix/math.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 -g $< -o $@

stdlib.o: ../posix/stdlib.c ../posix/stdlib.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

stdlib_asm.o: ../posix/stdlib.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 $< -o $@
    
string.o: ../posix/string.c ../posix/string.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

string_asm.o: ../posix/string.asm
	@echo "  [ASM] Assembling $<"; $(TDK_ASM) -f elf64 $< -o $@

fenv.o: ../posix/fenv.c ../posix/fenv.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -DFRAMEWORK_TEST -o $@ -c $<

posix_tests.o: posix_tests.c $(wildcard posix_*.h) 
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

sdk_testapp.o: sdk_testapp.c posix_tests.h ../../common/tdk_version.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
