.PHONY: build
build:
	mkdir -p ./build
	CC=clang CXX=clang++ cmake -B ./build -G Ninja -S .
	ninja -C ./build

clean:
	rm -rf ./build
