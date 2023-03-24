.PHONY: all
all: hello-first hello-second

hello.o: hello.c
	gcc -c -o hello.o hello.c

hello-first.o: hello-first.c
	gcc -c -o hello-first.o hello-first.c

hello-second.o: hello-second.c
	gcc -c -o hello-second.o hello-second.c 

hello-first: hello-first.o hello.o
	gcc -o hello-first hello-first.o hello.o

hello-second: hello-second.o hello.o
	gcc -o hello-second hello-second.o hello.o
