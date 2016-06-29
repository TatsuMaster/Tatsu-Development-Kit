all: ttf

.PHONY: ttf clean

ttf:
	@echo "Building Tatsu Test Framework"; cd ttf; make; cd ..
	@echo "Building SDK Tests"; cd sdk/tests; make; cd ../..

clean:
	cd ttf; make clean; cd ..
	cd sdk/tests; make clean; cd ../..
