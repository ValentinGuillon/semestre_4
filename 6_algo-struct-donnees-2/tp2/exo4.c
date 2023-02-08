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


typedef struct s_noeud_t {
	int v;
	struct s_noeud_t* g;
	struct s_noeud_t* d;
} noeud_t;

//retourne l'adresse d'un noeud, en lui donnant une valeur et deux sous arbres
noeud_t* add_n(int val, noeud_t* gauche, noeud_t* droite);

//libère la mémoire de chaque noeud de l'arbre
void cut_tree(noeud_t* node);

//retourne 1 si l'arbre binaire est de recherche, en mettant min et max à jour à chaque appel (récursif)
int is_search_binary_tree(noeud_t* node, int* min, int* max);

//retourne la plus petite valeur de l'arbre
int min_of_tree(noeud_t* node);
//retourne la plus grande valeur de l'arbre
int max_of_tree(noeud_t* node);



void analyse_tree(noeud_t* tree);

//affiche tout le sous-arbre gauche, puis le droit, en parcours préfixe
void print_tree(noeud_t* tree, int profondeur);
//affiche différent type de parenthèse en fonction de n
void print_parenthèse(int n, int ouvrant);













int main(void) {
	noeud_t *tree;

	printf("Les arbres sont parcourus en préfixe\n");

	//premier arbre
	tree = add_n(18, add_n(4, add_n(2, NULL, add_n(5, NULL, NULL)), add_n(24, NULL, NULL)), add_n(19, NULL, NULL));
	printf("\nArbre 1: ne devrait pas être de recherche\n");
	analyse_tree(tree);

	//deuxième arbre
	tree = add_n(3, add_n(4, NULL, add_n(5, NULL, NULL)), add_n(6, NULL, NULL));
	printf("\nArbre 2: ne devrait pas être de recherche\n");
	analyse_tree(tree);

	//troisième arbre
	tree = add_n(3, add_n(1, NULL, add_n(3, NULL, NULL)), add_n(6, NULL, NULL));
	printf("\nArbre 3: ne devrait pas être de recherche\n");
	analyse_tree(tree);

	//troisième arbre
	tree = add_n(3, add_n(1, NULL, add_n(2, NULL, NULL)), add_n(6, NULL, NULL));
	printf("\nArbre 4: devrait être de recherche\n");
	analyse_tree(tree);
}



void analyse_tree(noeud_t* tree) {
	int min, max; //si l'arbre n'est pas de recherche, ces valeurs seront inexactes
	int arbre_est_binaire;

	min = max = tree->v;

	arbre_est_binaire = is_search_binary_tree(tree, &min, &max);
	print_tree(tree, 0);

	if (arbre_est_binaire) {
		printf("L'arbre EST un binaire de recherche\n");
		printf("min = %d, max = %d\n", min, max);
	}
	else printf("L'arbre N'EST PAS un binaire de recherche\n");

	cut_tree(tree);
}

















//retourne l'adresse d'un noeud, en lui donnant une valeur et deux sous arbres
noeud_t* add_n(int val, noeud_t* gauche, noeud_t* droite) {
	noeud_t* node = malloc(sizeof(noeud_t));
	assert(node);

	node->v = val;
	node->g = gauche;
	node->d = droite;

	return node;
}


void cut_tree(noeud_t* node) {
	if (node->g != NULL) cut_tree(node->g);
	if (node->d != NULL) cut_tree(node->d);

	free(node);
	return;
}



//retourne 1 si l'arbre binaire est de recherche, en mettant min et max à jour à chaque appel (récursif)
int is_search_binary_tree(noeud_t* node, int* min, int* max) {

	int sous_arbre_est_de_recherche = 1;

	//on regarde l'arbre gauche, puis le droit

	//s'il y'a un arbre gauche, on regarde si la valeur de gauche est plus petite que le noeud actuel, si oui, on regarde si l'arbre gauche est binaire de recherche
	if (node->g != NULL) {
		//si le plus grand élément de gauche est plus grand que le noeud actuel, l'arbre n'est pas de recherche
		if (max_of_tree(node->g) >= node->v)
			return 0;

		if (node->v < node->g->v)
			return 0;

		sous_arbre_est_de_recherche = is_search_binary_tree(node->g, min, max);
	}

	if (!sous_arbre_est_de_recherche) return 0;

	//on fait pareil pour l'arbre droit
	if (node->d != NULL) {
		//si le plus petit élément de droite est plus petit que le noeud actuel, l'arbre n'est pas de recherche
		if (min_of_tree(node->d) <= node->v)
			return 0;

		if (node->v > node->d->v)
			return 0;

		sous_arbre_est_de_recherche = is_search_binary_tree(node->d, min, max);
	}

	//mise à jour des min/max
	if (*min > node->v) *min = node->v;
	if (*max < node->v) *max = node->v;

	return sous_arbre_est_de_recherche;
}





//retourne la plus petite valeur de l'arbre
int min_of_tree(noeud_t* node) {
	int val = node->v;
	int val_temp;

	//prend la valeur la plus petite entre val et la plus petite de sous-arbre gauche
	if (node->g != NULL) {
		val_temp = min_of_tree(node->g);

		if (val > val_temp)
			val = val_temp;
	}

	//prend la valeur la plus petite entre val et la plus petite de sous-arbre droit
	if (node->d != NULL) {
		val_temp = min_of_tree(node->d);

		if (val > val_temp)
			val = val_temp;
	}

	return val;
}




//retourne la plus grande valeur de l'arbre
int max_of_tree(noeud_t* node) {
	int val = node->v;
	int val_temp;

	//prend la valeur la plus grande entre val et la plus grande de sous-arbre gauche
	if (node->g != NULL) {
		val_temp = max_of_tree(node->g);

		if (val < val_temp)
			val = val_temp;
	}

	//prend la valeur la plus grande entre val et la plus grande de sous-arbre droit
	if (node->d != NULL) {
		val_temp = max_of_tree(node->d);

		if (val < val_temp)
			val = val_temp;
	}

	return val;
}












//affiche tout le sous-arbre gauche, puis le droit
//parcours préfixe
void print_tree(noeud_t* node, int profondeur) {
	profondeur++;

	print_parenthèse(profondeur, 1);
	printf("%d, ", node->v);

	if (node->g == NULL) printf("_");
	else print_tree(node->g, profondeur);

	printf(", ");

	if (node->d == NULL) printf("_");
	else print_tree(node->d, profondeur);

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

