TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra -fno-builtin

all: sdk_testapp

.PHONY: clean
clean:
	rm -rf *.o sdk_testapp *~ *.exe

sdk_testapp: sdk_testapp.o ttf.o posix_tests.o posix_errno_tests.o ttf_unix.o string.o posix_string_tests.o errno.o
	@echo "  [LD ] Linking $@"; $(TDK_CC) sdk_testapp.o ttf.o posix_tests.o posix_errno_tests.o ttf_unix.o string.o errno.o posix_string_tests.o -o sdk_testapp

ttf.o: ../../ttf/ttf.c ../../ttf/ttf.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
    
ttf_unix.o: ../../ttf/ttf_unix.c ../../ttf/ttf_unix.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_errno_tests.o: posix_errno_tests.c posix_errno_tests.h ../posix/errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_string_tests.o: posix_string_tests.c posix_string_tests.h ../posix/string.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

string.o: ../posix/string.c ../posix/string.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

errno.o: ../posix/errno.c ../posix/errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_tests.o: posix_tests.c $(wildcard posix_*.h) 
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

sdk_testapp.o: sdk_testapp.c posix_tests.h ../../common/tdk_version.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
