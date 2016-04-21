/*
 * tri_inf_vecto.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 */

#include <stdlib.h>
#include <stdio.h>

#include <smmintrin.h>

#include "init.h"

void tri_inf_vecto(matricefloat_t m, vecteurfloat_t v, vecteurfloat_t res){
    int i,j;
    __m128 _va,_vb,_vecteur_somme,_vres,_vc,_vd;
    
    float4 somme_temporaire = {0,0,0,0};
    
    for(i=0;i<N;i+=4){
		
		float4 resultat = {res[i],res[i+1],res[i+2],res[i+3]};
        
       
        _vecteur_somme = _mm_load_ps(somme_temporaire);
        
        for(j=0;j<i;j+=4){
			
			// On crée des tableaux de 4 float;
			
			float4 a = {m[i][j],m[i][j+1],m[i][j+2],m[i][j+3]};
			float4 b = {res[j],res[j+1],res[j+2], res[j+3]};
			
			//On les vectorise
			
			_va = _mm_load_ps(a);
			_vb = _mm_load_ps(b);
			
			//0xFF Masque constant pour qque tous l'octet soit multiplié
			_vecteur_somme = _mm_add_ps(_vecteur_somme, _mm_mul_ps(_va,_vb));
			
			//ici _vecteur_somme = _vecteur_somme + _va * _vb
        }
	
		float4 c = {v[i],v[i+1],v[i+2],v[i+3]};
		float4 d = {m[i][i],m[i+1][i+1],m[i+2][i+2],m[i+3][i+3]};
		_vc = _mm_load_ps(c);
		_vd = _mm_load_ps(d);
		_vres = _mm_div_ps(_mm_sub_ps(_vc,_vecteur_somme),_vd);
		
		// ici _vres = (_vc - _vecteur_somme) / _vd
		
		// TODO Comment enregister le résultat ?
		_mm_store_ps (resultat, _vres);
    }    
}


int main()
{
	
	printf("Résolution matrice triangulaire inférieure avec vectorisation.\n");
	
	matricefloat_t m;
	vecteurfloat_t v, res;

	init_vect(v);
	init_mat_tri_inf(m);
   
	tri_inf_vecto(m,v,res); 
	
	return EXIT_SUCCESS;
}

