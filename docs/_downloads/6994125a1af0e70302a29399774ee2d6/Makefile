.PHONY: all
all: hello-first hello-second

hello.o: hello.c
	gcc -c -o hello.o hello.c

hello-flexible.o: hello-flexible.c
	gcc -c -o hello-flexible.o hello-flexible.c

libgreet.a: hello.o hello-flexible.o
	ar cq libgreet.a hello.o hello-flexible.o

hello-first.o: hello-first.c
	gcc -c -o hello-first.o hello-first.c

hello-second.o: hello-second.c
	gcc -c -o hello-second.o hello-second.c 

hello-first: hello-first.o libgreet.a
	gcc -o hello-first hello-first.o libgreet.a

hello-second: hello-second.o libgreet.a
	gcc -o hello-second hello-second.o libgreet.a
