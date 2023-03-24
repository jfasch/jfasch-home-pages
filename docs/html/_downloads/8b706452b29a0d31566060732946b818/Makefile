.PHONY: all
all: hello-first hello-second

hello.o: hello.c
	gcc -fPIC -c -o hello.o hello.c

hello-flexible.o: hello-flexible.c
	gcc -fPIC  -c -o hello-flexible.o hello-flexible.c

libgreet.so: hello.o hello-flexible.o
	gcc -shared -o libgreet.so hello.o hello-flexible.o 

hello-first.o: hello-first.c
	gcc -c -o hello-first.o hello-first.c

hello-second.o: hello-second.c
	gcc -c -o hello-second.o hello-second.c 

hello-first: hello-first.o libgreet.so
	gcc -o hello-first hello-first.o libgreet.so

hello-second: hello-second.o libgreet.so
	gcc -o hello-second hello-second.o libgreet.so
