CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all: lab_02

obj: 
	mkdir obj

obj/test.o: src/test.c | obj
	gcc $(CFLAGS) -c src/test.c -o obj/test.o

obj/str.o: src/str.c | obj
	gcc $(CFLAGS) -c src/str.c -o obj/str.o

obj/test_str.o: src/test_str.c | obj
	gcc $(CFLAGS) -c src/test_str.c -o obj/test_str.o

lab_02: obj/test.o obj/test_str.o obj/str.o
	gcc obj/test.o obj/test_str.o obj/str.o -o lab_02

clean:
	rm -rf obj lab_02

