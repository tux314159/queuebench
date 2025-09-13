CC ?= gcc
CFLAGS ?= -O3

BINS = build/circular build/stacks build/stacks_nocpy

all : $(BINS)

bench : $(BINS)
	hyperfine -N --warmup=8 $(BINS)

build/% : %.c skel.h
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ -D_$(DEBUG) $<
