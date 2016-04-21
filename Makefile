CC=gcc
CFLAGS=-W -Wall -O2
LDFLAGS=
EXEC=diag tri_inf tri_sup tri_inf_vecto tri_sup_vecto produit_scalaire_vecto produit_matricielle_vecto clean

all: $(EXEC)

diag: init.o diag.o
	$(CC) -o $@ $^ 
	
tri_inf: init.o tri_inf.o
	$(CC) -o $@ $^ 	
	
tri_sup: init.o tri_sup.o
	$(CC) -o $@ $^ 	

tri_inf_vecto: init.o tri_inf_vecto.o
	$(CC) -O2 -o $@ $^ 
	
tri_sup_vecto: init.o tri_sup_vecto.o
	$(CC) -O2 -o $@ $^ 	
	
produit_scalaire_vecto: init.o produit_scalaire_vecto.c
	$(CC) -msse4.1 -O2 -o $@ $^
	
produit_matricielle_vecto: init.o produit_matricielle_vecto.c
	$(CC) -msse4.1 -O2 -o $@ $^
	
diag.o: init.h

tri_inf.o: init.h

tri_sup.o: init.h

tri_inf_vecto.o : init.h

tri_sup_vecto.o : init.h

produit_scalaire_vecto.o : init.h

produit_matricielle_vecto.o : init.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf *.o
	
mrproper :
		rm $(EXEC)
