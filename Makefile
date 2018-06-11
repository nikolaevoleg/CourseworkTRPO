all: program

program: build/main.o bin
	gcc -Wall -Werror build/main.o -o bin/program

build/main.o: source/main.c build
	gcc -Wall -Werror -c source/main.c -o build/main.o

build:
	mkdir build

bin:
	mkdir bin

.PHONY: clean

clean:
	rm -rf bin/program build/*.o bin/test

