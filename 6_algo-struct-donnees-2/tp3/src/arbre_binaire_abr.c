/* Prog qui permet la création d'un arbre binaire
 * et determine si l'arbre donné est de recherche

 * Rappel :
 * un arbre binaire est de recherche si, par rapport au noeud observé:
 * 	- TOUS les noeuds du sous-arbre GAUCHE sont SCTRICTEMENT plus PETIT
 * 	- TOUS les noeuds du sous-arbre DROIT sont SCTRICTEMENT plus GRAND
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct s_noeud_t noeud_t;

struct s_noeud_t {
	int v;
	noeud_t* g;
	noeud_t* d;
};



//retourne l'adresse d'un noeud, en lui donnant une valeur et deux sous arbres
noeud_t* add_n(int val, noeud_t* gauche, noeud_t* droite);

//libère la mémoire de chaque noeud de l'arbre
void cut_tree(noeud_t* tree);

//retourne 1 si l'arbre binaire est de recherche, en mettant min et max à jour à chaque appel (récursif)
int is_search_binary_tree(noeud_t* tree, int* min, int* max);

//retire une valeur de l'arbre, tout en conservant l'intégrité de l'ABR
noeud_t* remove_val(noeud_t* tree, int val);


//retourne la plus petite valeur de l'arbre
int min_of_tree(noeud_t* tree);
//retourne la plus grande valeur de l'arbre
int max_of_tree(noeud_t* tree);



//affiche tout le sous-arbre gauche, puis le droit, en parcours préfixe
void print_tree(noeud_t* tree, int profondeur);
//affiche différent type de parenthèse en fonction de n
void print_parenthèse(int n, int ouvrant);




























//retourne l'adresse d'un noeud, en lui donnant une valeur et deux sous arbres
noeud_t* add_n(int val, noeud_t* gauche, noeud_t* droite) {
	noeud_t* tree = malloc(sizeof(noeud_t));
	assert(tree);

	tree->v = val;
	tree->g = gauche;
	tree->d = droite;

	return tree;
}


void cut_tree(noeud_t* tree) {
    if (tree == NULL)
        return;

	cut_tree(tree->g);
	cut_tree(tree->d);

	free(tree);
	return;
}



//retourne 1 si l'arbre binaire est de recherche, en mettant min et max à jour à chaque appel (récursif)
int is_search_binary_tree(noeud_t* tree, int* min, int* max) {
    if (tree == NULL) {
        return 1;
    }

	int sous_arbre_est_de_recherche = 1;

	//on regarde l'arbre gauche, puis le droit

	//s'il y'a un arbre gauche, on regarde si la valeur de gauche est plus petite que le noeud actuel, si oui, on regarde si l'arbre gauche est binaire de recherche
	if (tree->g != NULL) {
		//si le plus grand élément de gauche est plus grand que le noeud actuel, l'arbre n'est pas de recherche
		if (max_of_tree(tree->g) >= tree->v)
			return 0;

		if (tree->v < tree->g->v)
			return 0;

		sous_arbre_est_de_recherche = is_search_binary_tree(tree->g, min, max);
	}

	if (!sous_arbre_est_de_recherche) return 0;

	//on fait pareil pour l'arbre droit
	if (tree->d != NULL) {
		//si le plus petit élément de droite est plus petit que le noeud actuel, l'arbre n'est pas de recherche
		if (min_of_tree(tree->d) <= tree->v)
			return 0;

		if (tree->v > tree->d->v)
			return 0;

		sous_arbre_est_de_recherche = is_search_binary_tree(tree->d, min, max);
	}

	//mise à jour des min/max
	if (*min > tree->v) *min = tree->v;
	if (*max < tree->v) *max = tree->v;

	return sous_arbre_est_de_recherche;
}




//retire une valeur de l'arbre, tout en conservant l'intégrité de l'ABR
noeud_t* remove_val(noeud_t* tree, int val) {
    return NULL;
}






//retourne la plus petite valeur de l'arbre
int min_of_tree(noeud_t* tree) {
	int val = tree->v;
	int val_temp;

	//prend la valeur la plus petite entre val et la plus petite de sous-arbre gauche
	if (tree->g != NULL) {
		val_temp = min_of_tree(tree->g);

		if (val > val_temp)
			val = val_temp;
	}

	//prend la valeur la plus petite entre val et la plus petite de sous-arbre droit
	if (tree->d != NULL) {
		val_temp = min_of_tree(tree->d);

		if (val > val_temp)
			val = val_temp;
	}

	return val;
}




//retourne la plus grande valeur de l'arbre
int max_of_tree(noeud_t* tree) {
	int val = tree->v;
	int val_temp;

	//prend la valeur la plus grande entre val et la plus grande de sous-arbre gauche
	if (tree->g != NULL) {
		val_temp = max_of_tree(tree->g);

		if (val < val_temp)
			val = val_temp;
	}

	//prend la valeur la plus grande entre val et la plus grande de sous-arbre droit
	if (tree->d != NULL) {
		val_temp = max_of_tree(tree->d);

		if (val < val_temp)
			val = val_temp;
	}

	return val;
}












//affiche tout le sous-arbre gauche, puis le droit
//parcours préfixe
void print_tree(noeud_t* tree, int profondeur) {
    if (tree == NULL){
        printf("{}\n");
        return;
    }

	profondeur++;

	print_parenthèse(profondeur, 1);
	printf("%d, ", tree->v);

	if (tree->g == NULL) printf("_");
	else print_tree(tree->g, profondeur);

	printf(", ");

	if (tree->d == NULL) printf("_");
	else print_tree(tree->d, profondeur);

	print_parenthèse(profondeur, 0);

	if (profondeur == 1) printf("\n");

	

}


void print_parenthèse(int n, int ouvrant) {
	switch (n % 3) {
	case 0:
		if (ouvrant) printf("[");
		else printf("]");
		break;
	case 1:
		if (ouvrant) printf("(");
		else printf(")");
		break;
	case 2:
		if (ouvrant) printf("{");
		else printf("}");
		break;
	
	default:
		if (ouvrant) printf("(");
		else printf(")");
		break;
	}
}

