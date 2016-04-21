CC=gcc
CFLAGS=-W -Wall -O2
LDFLAGS=
EXEC=diag tri_inf tri_sup tri_inf_vecto

all: $(EXEC)

diag: init.o diag.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
tri_inf: init.o tri_inf.o
	$(CC) -o $@ $^ $(LDFLAGS)	
	
tri_sup: init.o tri_sup.o
	$(CC) -o $@ $^ $(LDFLAGS)	

tri_inf_vecto: init.o tri_inf_vecto.o
	$(CC) -msse4.1 -o $@ $^ $(LDFLAGS)	

diag.o: init.h

tri_inf.o: init.h

tri_sup.o: init.h

tri_inf_vecto.o : init.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf *.o
	
mrproper :
		rm $(EXEC)
