all: ttf

.PHONY: ttf clean

ttf:
	@echo "Building Tatsu Test Framework"; cd ttf; make; cd ..

clean:
	cd ttf; make clean; cd ..
