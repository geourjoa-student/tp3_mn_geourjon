/*
 * diag.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "init.h"

void diag(matricefloat_t A, vecteurfloat_t x, vecteurfloat_t b){
    int i;
    for(i=0;i<N;i++){
        x[i]=b[i]/A[i][i];
    }
}

int main()
{	
	matricefloat_t m;
    vecteurfloat_t v,res; 
    
    init_vect(v);
    init_mat_diag(m);
    
    printf("Résolution d'une matrice diagonale.\n");
    
    diag(m,v,res);
	
	return 0;
}

