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
void tri_inf(matriceOptimiseefloat_t m, vecteurfloat_t v, vecteurfloat_t res){
 
    	int i,j;
	float s=0;

	for(i= 0 ; i < N ; i++){
		for(j=0; j <i ; j++){
			s= (v[i]-m[i][j]*v[j])/m[i][i];
		}
		res[i]=s;
	}
}

int main()
{
	matriceOptimiseefloat_t m;
    	vecteurfloat_t v,res; 
    
	init_vect(v);
	init_mat_optimisee(m);
	
	printf("Résolution de système matrice inférieur.\n");
	
	tri_inf(m,v,res);
    
	return EXIT_SUCCESS;
}

