all: ttf

.PHONY: ttf clean

ttf:
	@echo "Building Tatsu Test Framework"; cd ttf; $(MAKE); cd ..
	@echo "Building POSIX SDK"; cd sdk/posix; $(MAKE); cd ../..
	@echo "Building SDK Tests"; cd sdk/tests; $(MAKE); cd ../..

testrun: ttf
	@echo "Running TTF Self Tests"; ./ttf/ttf_testapp;
	@echo "Running SDK Tests"; ./sdk/tests/sdk_testapp;

clean:
	cd ttf; $(MAKE) clean; cd ..
	cd sdk/tests; $(MAKE) clean; cd ../..
