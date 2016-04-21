/*
 * tri_inf.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#include "init.h"

//résolution du système avec matrice inférieure
void tri_inf(matricefloat_t m, vecteurfloat_t v, vecteurfloat_t res){
 
    int i,j,s;
    for(i=0;i<N;i++){
        s=0;
        for(j=0;j<i;j++){
            s = s+m[i][j]*res[j];
        }
        res[i]=(v[i]-s)/m[i][i];
    }
}

int main()
{
	matricefloat_t m;
    vecteurfloat_t v,res; 
    
	init_vect(v);
	init_mat_diag(m);
	
	printf("Résolution de système matrice inférieur.\n");
	
	tri_inf(m,v,res);
    
	return EXIT_SUCCESS;
}

