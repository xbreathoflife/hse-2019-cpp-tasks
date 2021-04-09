CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: lab_03

obj: 
	mkdir obj

obj/main.o: src/main.c | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/clist.o: src/clist.c | obj
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

lab_03: obj/clist.o obj/main.o
	gcc obj/clist.o obj/main.o -o lab_03

clean:
	rm -rf obj lab_03

