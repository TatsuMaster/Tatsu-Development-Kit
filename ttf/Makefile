TDK_CC     = clang
TDK_CFLAGS = -Wall -Wextra

all: ttf_testapp

.PHONY: clean
clean:
	rm -rf *.o ttf_testapp *~ *.exe

ttf_testapp: ttf_testapp.o ttf.o
	@echo "  [LD ] Linking $@"; $(TDK_CC) ttf_testapp.o ttf.o -o ttf_testapp

ttf.o: ttf.c ttf.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<

ttf_testapp.o: ttf_testapp.c $(wildcard *.h) ../common/tdk_version.h
	@echo "  [CC ] Compiling $@"; $(TDK_CC) $(TDK_CFLAGS) -o $@ -c $<
