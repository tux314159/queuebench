BINS=build/circular build/stacks build/circular_pow2 build/stl

bench : $(BINS)
	for bin in $^; do hyperfine -N --warmup=1 $$bin; done

build/% : %.c skel.h
	mkdir -p build
	gcc -O3 -o $@ -D_$(DEBUG) $^

build/% : %.cpp
	mkdir -p build
	g++ -O3 -o $@ -D_$(DEBUG) $^
