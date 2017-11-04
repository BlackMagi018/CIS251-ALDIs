all: operations.h operations.c main.c
	gcc -o aldis main.o operations.o 

operations.o: operations.h operations.c
	gcc -c operations.c

main.o: operations.h main.c
	gcc -c main.c

run:
	./aldis

clean:
	rm -f *.o
