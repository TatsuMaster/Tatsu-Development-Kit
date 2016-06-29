TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra

all: sdk_testapp

.PHONY: clean
clean:
	rm -rf *.o sdk_testapp *~ *.exe

sdk_testapp: sdk_testapp.o ttf.o posix_tests.o posix_errno_tests.o
	@echo "  [LD ] Linking $@"; $(TDK_CC) sdk_testapp.o ttf.o posix_tests.o posix_errno_tests.o -o sdk_testapp

ttf.o: ../../ttf/ttf.c ../../ttf/ttf.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_errno_tests.o: posix_errno_tests.c posix_errno_tests.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

posix_tests.o: posix_tests.c $(wildcard posix_*.h) 
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

sdk_testapp.o: sdk_testapp.c posix_tests.h ../../common/tdk_version.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
