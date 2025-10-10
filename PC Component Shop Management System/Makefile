all: main

main: main.o pcpart.o
	gcc -o main main.o pcpart.o

main.o: main.c pcpart.h
	gcc -c main.c

pcpart.o: pcpart.c pcpart.h
	gcc -c pcpart.c

clean:
	rm -f main *.o
