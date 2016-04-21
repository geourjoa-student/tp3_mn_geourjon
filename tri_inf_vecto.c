/*
 * tri_inf_vecto.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 */

#include <stdlib.h>
#include <stdio.h>

#include <smmintrin.h>

#include "init.h"

typedef float float4 [4] __attribute__ ((aligned(16)));

void tri_inf_vecto(matricefloat_t m, vecteurfloat_t v, vecteurfloat_t res){
    int i,j;
    __m128 _va,_vb,_vecteur_somme,_vres,_vc,_vd, _tmp;
    
    float4 somme_temporaire = {0,0,0,0};
    
    for(i=0;i<N;i+=4){
        
       
        _vecteur_somme = _mm_load_ps(somme_temporaire);
        
        for(j=0;j<i;j+=4){
			
			// On crée des tableaux de 4 float;
			
			float4 a = {m[i][j],m[i][j+1],m[i][j+2],m[i][j+3]};
			float4 b = {res[j],res[j+1],res[j+2], res[j+3]};
			
			//On les vectorise
			
			_va = _mm_load_ps(a);
			_vb = _mm_load_ps(b);
			
			//0xFF Masque constant pour qque tous l'octet soit multiplié
			_tmp = _mm_dp_ps(_va,_vb,0xFF);
			_vecteur_somme = _mm_add_ps(_vecteur_somme, _tmp);
			
			//ici _vecteur_somme = _vecteur_somme + _va * _vb
        }
	
		float4 c = {v[i],v[i+1],v[i+2],v[i+3]};
		float4 d = {m[i][i],m[i+1][i+1],m[i+2][i+2],m[i+3][i+3]};
		_vc = _mm_load_ps(c);
		_vd = _mm_load_ps(d);
		_vres = _mm_div_ps(_mm_sub_ps(_vc,_vecteur_somme),_vd);
		
		// ici _vres = (_vc - _vecteur_somme) / _vd
		
		// TODO Comment enregister le résultat ?
		//_mm_store_ps (b, _vres);
    }    
}


int main(int argc, char **argv)
{
	
	printf("Résolution matrice triangulaire inférieure avec vectorisation.\n");
	
	matricefloat_t m;
	vecteurfloat_t v, res;

    init_vect(v);
    init_mat_tri_inf(m);
   
	tri_inf_vecto(m,v,res); 
	
	return EXIT_SUCCESS;
}

