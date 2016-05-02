/*
 * tri_inf.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#include "init.h"

//résolution du système avec matrice supérieur
void tri_sup(matriceOptimiseefloat_t m, vecteurfloat_t v){
 
    int i,j;
    
    v[N-1]=v[N-1]/m[N-1][N-1];

	
    for(i=N-2;i>-1;i--){
        for(j=i+1;j<N;j++){
            v[i]=v[i]-m[i][j]*v[j];
        }
        v[i]=v[i]/m[i][i];
    }
}

int main()
{
	matriceOptimiseefloat_t m;
	vecteurfloat_t v; 

	init_vect(v);
	init_mat_optimisee(m);

	printf("Résolution de système matrice inférieur.\n");

	tri_sup(m,v);
    
	return 0;
}


