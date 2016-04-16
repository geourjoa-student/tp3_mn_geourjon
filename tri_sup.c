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
void tri_sup(matricefloat_t m, vecteurfloat_t v, vecteurfloat_t res){
 
    int i,j;
    v[N-1]=v[N-1]/m[N-1][N-1];
    for(i=N-1;i>-1;i--){
        for(j=i+1;j<N;j++){
            v[i]=v[i]-m[i][j]*v[j];
        }
        v[i]=v[i]/m[i][i];
    }
}

int main(int argc, char **argv)
{
	matricefloat_t m;
    vecteurfloat_t v,res; 
    
    init_vect(v);
    init_mat_diag(m);
    tri_sup(m,v,res);
    
	return 0;
}


