.PHONY: build
build:
	mkdir -p ./build
	CC=clang CXX=clang++ cmake -B ./build -G Ninja -S .
	ninja -C ./build

run: build
	./build/test

clean:
	rm -rf ./build
