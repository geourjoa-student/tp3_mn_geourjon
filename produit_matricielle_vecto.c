/*
 * produit_matriciel_vecto.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 */

#include <stdio.h>
#include <stdlib.h>

#include <smmintrin.h>

#include "init.h"

//Version 3 boucles du cours avec s
void produit_matriciel_vecto(matricefloat_t m1, matricefloat_t m2, matricefloat_t m3){
    
    register unsigned int i,j,k ;
    
    register float p = 0.0 ;
       
    __m128 _v_somme_courante,_vm1,_vm2;
    
    
    float4 somme_courante = {0,0,0,0};
    
    #pragma omp parallel for private(i,j,k)	
    for (i = 0; i < N; i++)
    {
        for(j = 0; j<N; j+=4)
        {
			float4 res =	{m1[i][j],m1[i][j+1],m1[i][j+2],m1[i][j+3]};
					
            _v_somme_courante = _mm_load_ps(somme_courante);
            for(k = 0; k<N; k+=4)
            {
				float4 b = {m1[i][k],m1[i][k+1],m1[i][k+2],m1[i][k+3]};
				float4 c = {m2[k][j],m2[k][j+1],m2[k][j+2],m2[k][j+3]};
				
				_vm1 = _mm_load_ps(b);
				_vm2 = _mm_load_ps(c);
					
				_v_somme_courante = _mm_add_ps(_v_somme_courante,_mm_mul_ps(_vm1,_vm2)); 
				
				// _v_somme_courante = _v_somme_courante + _vm1 * _vm2
            }
            
            _mm_store_ps(res, _v_somme_courante);
        }
	    
    }
}

int main(){
	
	printf("Produit matricielle de deux matrices inférieurs (ou supérieurs) avec vectorisation et parralélisation.\n");

	matricefloat_t m1, m2, m3;
	
	init_mat_tri_inf(m1);
	init_mat_tri_inf(m2);
	init_mat_tri_inf(m3);
	
	produit_matriciel_vecto(m1,m2,m3);
	
	return 0;
}
