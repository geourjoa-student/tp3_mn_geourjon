/*
 * tri_sup_vecto.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 */

#include <stdlib.h>
#include <stdio.h>

#include <smmintrin.h>

#include "init.h"

void tri_sup_vecto(matricefloat_t m, vecteurfloat_t v, vecteurfloat_t v_res){
       
    int i,j;
    
    __m128 _v_mii,_v_vj ,_v_vi;
       
    v[N-1]=v[N-1]/m[N-1][N-1];
    
    for(i=N-1;i>-1;i-=4){
		float4 a = {v[i],v[i+1],v[i+2],v[i+3]};	
		_v_vi = _mm_load_ps(a);
		
		float4 resultat = {v_res[i],v_res[i+1],v_res[i+2],v_res[i+3]};	
		
		for(j=i+1;j<N;j+=4){
			
			//On crée nos vecteur de 4 float 
			
			float4 b = {m[i][i],m[i+1][i+1],m[i+2][i+2],m[i+3][i+3]};
			float4 c = {v[j],v[j+1],v[j+2],v[j+3]};
			
			//on les charge en mémoire

			_v_mii = _mm_load_ps(b);
			_v_vj = _mm_load_ps(c);

			//comme sur tri_inf_vecto cette ligne ne compile pas
			_v_vi = _mm_sub_ps(_v_vi,_mm_mul_ps(_v_mii,_v_vj));
			
			//ici _v_vi contient v[i]-m[i][j]*v[j]
		}
		
		float4 d = {m[i][i],m[i+1][i+1],m[i+2][i+2],m[i+3][i+3]};
		_v_mii = _mm_load_ps(d);
		_v_vi = _mm_div_ps(_v_vi,_v_mii); 
		
		//ici _v_vi contient v[i]/m[i][j]
		
		// TODO Comment enregister le résultat ?
		_mm_store_ps (resultat, _v_vi);
    }  
}

int main()
{
	
	printf("Résolution matrice triangulaire supérieur avec vectorisation.\n");
	
	matricefloat_t m;
	vecteurfloat_t v, res;

   	init_vect(v);
    init_mat_tri_inf(m);
   	
   	tri_sup_vecto(m,v,res); 
	
	return EXIT_SUCCESS;
}


