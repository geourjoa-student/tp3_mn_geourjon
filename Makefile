CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=diag tri_inf tri_sup

all: $(EXEC)

diag: init.o diag.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
tri_inf: init.o tri_inf.o
	$(CC) -o $@ $^ $(LDFLAGS)	
	
tri_sup: init.o tri_sup.o
	$(CC) -o $@ $^ $(LDFLAGS)	

diag.o: init.h

tri_inf.o: init.h

tri_sup.o: init.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf *.o
	
mrproper :
		rm $(EXEC)
