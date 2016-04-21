#ifndef _INIT_H_
#define _INIT_H_

	#define N 128
	
	//Vesrion classique des programmes
	
	//Matrice
	typedef float matricefloat_t [N][N] ; 
	
	// Vecteur
	typedef float vecteurfloat_t [N] ;   

	//initialisation d'un vecteur v 
	void init_vect (vecteurfloat_t v);
	
	// initialisation de la matrice m diagonale 
	void init_mat_diag (matricefloat_t m);
	
	// initialisation de la matrice M triangulaire inférieure 
	void init_mat_tri_inf (matricefloat_t m);

	// initialisation de la matrice M triangulaire supérieur 
	void init_mat_tri_sup (matricefloat_t m);

	
	//Vesrion optimisée des programmes
	
	//Matrice
	/*typedef vecteurfloat_t matriceOptimiseefloat_t [N]; 
	
	void init_vect (vecteurfloat_t v);
	
	void init_mat_optimisee_tri_inf(matriceOptimiseefloat_t m);
	
	void init_mat_optimisee_tri_sup(matriceOptimiseefloat_t m);
	*/
	
	//Définition de type pour la vectorisation
	typedef float float4 [4] __attribute__ ((aligned(16)));
	

#endif /* #ifndef _INIT_H_ */
