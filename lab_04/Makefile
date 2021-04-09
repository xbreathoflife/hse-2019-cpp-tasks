CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: lab_04

obj: 
	mkdir obj

obj/main.o: src/main.c | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/mergesort.o: src/mergesort.c | obj
	gcc $(CFLAGS) -c src/mergesort.c -o obj/mergesort.o

lab_04: obj/mergesort.o obj/main.o
	gcc obj/mergesort.o obj/main.o -o lab_04

clean:
	rm -rf obj lab_04

