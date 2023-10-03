BINS=build/circular build/circular_pow2 build/stacks build/stacks_nocpy build/stl

all : $(BINS)

bench : $(BINS)
	for bin in $^; do hyperfine -N --warmup=1 $$bin; done

build/% : %.c skel.h
	mkdir -p build
	gcc -O3 -o $@ -D_$(DEBUG) $<

build/% : %.cpp
	mkdir -p build
	g++ -O3 -o $@ -D_$(DEBUG) $<
