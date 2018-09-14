mycp: mycp.o
  gcc -o mycp mycp.o

mycp.o: mycp.c mycp.h
	gcc -Wall -c mycp.c

clean:
	rm *o mycp
