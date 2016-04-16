all: diag

diag : init.o diag.o
	gcc -o diag init.o diag.o

init.o: init.c 
	gcc -o init.o -c init.c

diag.o: diag.c init.h
	gcc -o diag.o -c diag.c

clean:
	rm -rf *.o
