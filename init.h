#ifndef _INIT_H_
#define _INIT_H_

	#define N 128
	
	typedef float matricefloat_t [N][N] ; // définition d'un type matrice
	typedef float vecteurfloat_t [N] ;   // définition d'un type vecteur

	//initialisation d'un vecteur v 
	void init_vect (vecteurfloat_t v);
	
	// initialisation de la matrice m diagonale 
	void init_mat_diag (matricefloat_t m);
	
	// initialisation de la matrice M triangulaire inférieure 
	void init_mat_tri_inf (matricefloat_t m);

	// initialisation de la matrice M triangulaire supérieur 
	void init_mat_tri_sup (matricefloat_t m);


#endif /* #ifndef _INIT_H_ */
