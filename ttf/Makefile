TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra

all: ttf_testapp

.PHONY: clean
clean:
	rm -rf *.o ttf_testapp *~

ttf_testapp: ttf_testapp.o
	@echo "  [LD ] Linking $@"; $(TDK_CC) $< -o $@ -lncurses

ttf_testapp.o: ttf_testapp.c $(wildcard *.h) ../common/tdk_version.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
