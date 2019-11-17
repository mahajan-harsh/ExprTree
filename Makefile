CFLAGS=-Wall -ansi -g
main: main.o expr.o
clean:
	rm *~ *.o main
