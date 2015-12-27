run: build
	bin/esercizio1

build: esercizio1

test: libs
	gcc -c src/test.c -o tmp/test.o
	gcc -o bin/test tmp/*.o
	bin/test

esercizio1: libs
	gcc -c src/main.c -o tmp/main.o
	gcc -o bin/esercizio1 tmp/*.o

libs: clean
	gcc -c src/esercizio1.c -o tmp/esercizio1.o
#	gcc -c src/list.c -o tmp/list.o
#	gcc -c src/element.c -o tmp/element.o

clean:
	rm -f bin/*
	rm -f tmp/*
