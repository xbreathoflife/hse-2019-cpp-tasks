CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: lab_05

obj: 
	mkdir obj

obj/main.o: src/main.c | obj
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/clist.o: src/clist.c | obj
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

obj/point_list.o: src/point_list.c | obj
	gcc $(CFLAGS) -c src/point_list.c -o obj/point_list.o

lab_05: obj/clist.o obj/main.o obj/point_list.o
	gcc obj/clist.o obj/main.o obj/point_list.o -o lab_05

clean:
	rm -rf obj lab_05

