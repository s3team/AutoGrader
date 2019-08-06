.PHONY: default tags
default: all

%:
ifeq ("false","true")
	(make -f Makefile.pin PIN_ROOT=/home/bambool/loop/pin TARGET=intel64 ARCH_X64="false" $@)
endif
	(make -f Makefile.pin PIN_ROOT=/home/bambool/loop/pin TARGET=ia32 ARCH_X64="false" $@)

tags:
