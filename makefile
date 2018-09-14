mycp: mycopy

mycopy: mycopy.o
	gcc -o mycp mycopy.o

mycopy.o: mycopy.c mycopy.h
	gcc -Wall -c mycopy.c

clean:
	rm *o mycp
