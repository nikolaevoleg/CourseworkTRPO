all: program

program: build/main.o build/game.o build/functions.o 
	gcc -Wall -Werror build/main.o build/game.o build/functions.o -o bin/program

build/main.o: source/main.c 
	gcc -Wall -Werror -c source/main.c -o build/main.o

build/game.o: source/game.c 
	gcc -Wall -Werror -c source/game.c -o build/game.o

build/functions.o: source/functions.c 
	gcc -Wall -Werror -c source/functions.c -o build/functions.o

clean:
	rm -rf bin/program build/*.o

