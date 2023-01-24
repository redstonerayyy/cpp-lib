.PHONY: build
build:
	mkdir -p ./build
	CC=clang CXX=clang++ cmake -B ./build -G Ninja -S .
	ninja -C ./build

clean:
	rm -rf ./build
	rm -rf ./runtests

test: build
	mkdir -p runtests
	cp -r ./test/data/* ./runtests
	cp ./build/testlib ./runtests/testlib
	./runtests/testlib
