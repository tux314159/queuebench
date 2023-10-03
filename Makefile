BINS=build/circular build/circular_pow2 build/circular_if build/stacks build/stacks_nocpy build/stl

all : $(BINS)

bench : $(BINS)
	hyperfine -N --warmup=1 $(BINS)

build/% : %.c skel.h
	mkdir -p build
	gcc -O3 -o $@ -D_$(DEBUG) $<

build/% : %.cpp
	mkdir -p build
	g++ -O3 -o $@ -D_$(DEBUG) $<
