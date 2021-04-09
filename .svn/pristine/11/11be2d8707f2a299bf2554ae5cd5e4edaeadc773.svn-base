CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: hw_01

obj: 
	mkdir obj

obj/main.o: src/main.c | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/bmp.o: src/bmp.c | obj
	gcc $(CFLAGS) -c src/bmp.c -o obj/bmp.o

hw_01: obj/bmp.o obj/main.o
	gcc obj/bmp.o obj/main.o -o hw_01

clean:
	rm -rf obj hw_01

