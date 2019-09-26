main: main.o ex1.o
	gcc -o main main.o ex1.o
main.o: main.c ex1.h
	gcc -c main.c
ex1.o: ex1.h ex1.c
	gcc -c ex1.c
