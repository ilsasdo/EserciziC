main: clean build test

clean:
	rm -rf build/*

build: clean
	gcc -c src/linked_list.c -o build/linked_list.o

build_test: build
	mkdir -p build/test
	gcc -c test/assert.c -o build/test/assert.o
	gcc -c test/test.c -o build/test/test.o
	gcc -o build/test/test build/test/*.o build/*.o

test: build_test
	build/test/test