all: program

program: build/main.o build/functions.o bin
	gcc -Wall -Werror build/main.o build/functions.o -o bin/program

build/main.o: source/main.c build
	gcc -Wall -Werror -c source/main.c -o build/main.o

build/functions.o: source/functions.c build
	gcc -Wall -Werror -c source/functions.c -o build/functions.o

build:
	mkdir build

bin:
	mkdir bin

.PHONY: clean

clean:
	rm -rf bin/program build/*.o bin/test

