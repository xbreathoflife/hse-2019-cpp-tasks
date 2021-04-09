CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: lab1

bin: 
	mkdir bin

bin/main.o: src/main.c | bin
	gcc $(CFLAGS) -c src/main.c -o bin/main.o

bin/algorithm.o: src/algorithm.c | bin
	gcc $(CFLAGS) -c src/algorithm.c -o bin/algorithm.o

bin/io.o: src/io.c | bin
	gcc $(CFLAGS) -c src/io.c -o bin/io.o

bin/util.o: src/util.c | bin
	gcc $(CFLAGS) -c src/util.c -o bin/util.o

lab1: bin/main.o bin/algorithm.o bin/io.o bin/util.o
	gcc bin/main.o bin/algorithm.o bin/io.o bin/util.o -o lab1

clean:
	rm -rf bin lab1
 
