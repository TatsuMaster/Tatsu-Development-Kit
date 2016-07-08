TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra

.PHONY: clean

all: posix_sdk

clean:
	rm -rf *.o sdk_testapp *~ *.exe

posix_sdk: errno.o

errno.o: errno.c errno.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

