all: main.o hello.o
	gcc -o hello main.o hello.o
main.o: main.c hello.h
	gcc -c main.c
hello.o: hello.c hello.h
	gcc -c hello.c
clean:
	rm -f *.o hello
