/*
 * produit_scalaire_vecto.c
 * 
 * Copyright 2016 Anthony Geourjon <anthony.geourjon@e.ujf-grenoble.fr>
 */

#include <stdlib.h>
#include <stdio.h>

#include <smmintrin.h>

#include "init.h"

void dot_product(vecteurfloat_t vu,vecteurfloat_t vv, vecteurfloat_t vres){
	
	int i;
	
	for(i=0;i<N;i+=4){
		
		float4 u = {vu[i],vu[i+1],vu[i+2],vu[i+3]};
		float4 v = {vv[i],vv[i+1],vv[i+2],vv[i+3]};
		
		float4 dp = {vres[i],vres[i+1],vres[i+2],vres[i+3]};;
		
		__m128 v1, v2, res;
		
		
		v1 = _mm_load_ps(u);
		v2 = _mm_load_ps(v);
		
		res = _mm_dp_ps(v1, v2, 0xFF);
		
		_mm_store_ps(dp, res);
	}
	
}

int main()
{
	
	printf("Produit scalaire de deux vecteurs avec vectorisation.\n");
		
	vecteurfloat_t v1, v2, vres;

    init_vect(v1);
    init_vect(v2);
    	
	dot_product(v1,v2,vres);
	
	return EXIT_SUCCESS;
}

