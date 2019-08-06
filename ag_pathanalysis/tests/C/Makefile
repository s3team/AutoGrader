CSRC=$(wildcard *.c)
CEXECS_SRC = $(CSRC:%.c=%)
CEXECS=$(CEXECS_SRC) recover-hard-opt
CEXECS_64 = $(CEXECS_SRC:%=%_64)

CFLAGS = -fno-stack-protector

all: $(CEXECS)

recover-hard-opt: recover-hard.c
	$(CC) -m32 $< -o $@ $(CFLAGS) -O3

$(CEXECS_SRC): $(CSRC)
	gcc -m32 $@.c -o $@ $(CFLAGS)
ifeq (false, true)
	gcc $@.c -o $@_64 $(CFLAGS)
endif


clean:
	rm -f $(CEXECS)
ifeq (false, true)
	rm -f $(CEXECS_64)
endif
