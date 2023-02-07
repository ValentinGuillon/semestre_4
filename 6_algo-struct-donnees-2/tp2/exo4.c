
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct s_noeud_t {
	int v;
	struct s_noeud_t* g;
	struct s_noeud_t* d;
} noeud_t;


noeud_t* create_node(int val, noeud_t* gauche, noeud_t* droite);
int is_search_binary_tree(noeud_t* node, int* min, int* max);

void print_tree(noeud_t* tree, int profondeur);
void print_tabulation(int n, int est_gauche);





int main(void) {
	int min, max;
	noeud_t *tree;
	tree = create_node(5, create_node(4, NULL, create_node(5, NULL, NULL)), create_node(6, NULL, NULL));

	min = max = tree->v;

	if (is_search_binary_tree(tree, &min, &max)) {
		printf("L'arbre est un binaire de recherche\n");
	}
	else printf("L'arbre n'est pas un binaire de recherche\n");
	printf("min = %d, max = %d\n", min, max);

	print_tree(tree, 0);
	return 0;
}





noeud_t* create_node(int val, noeud_t* gauche, noeud_t* droite) {
	noeud_t* node = malloc(sizeof(noeud_t));
	assert(node);

	node->v = val;
	node->g = gauche;
	node->d = droite;

	return node;
}



int is_search_binary_tree(noeud_t* node, int* min, int* max) {
	//mise à jour des min/max
	if (*min > node->v) *min = node->v;
	if (*max < node->v) *max = node->v;

	int gauche_est_de_recherche = 0;

	//s'il y'a un arbre gauche, on regarde si la valeur de gauche est plus petite que le noeud actuel, si oui, on regarde si l'arbre gauche est binaire de recherche
	if (node->g != NULL) {
		if (node->v < node->g->v) {
			return 0;
		}
		gauche_est_de_recherche = is_search_binary_tree(node->g, min, max);
	}

	if (!gauche_est_de_recherche) return 0;

	//on fait pareil pour l'arbre droit
	if (node->d != NULL) {
		if (node->v > node->d->v) {
			return 0;
		}
		is_search_binary_tree(node->d, min, max);
	}

	return 1;
}



void print_tree(noeud_t* node, int profondeur) {
	profondeur++;
	printf(" %d", node->v);


	print_tabulation(profondeur, 1);
	if (node->g != NULL) {
		print_tree(node->g, profondeur);
	}

	print_tabulation(profondeur, 0);
	if (node->d != NULL) {
		print_tree(node->d, profondeur);
	}
	printf("\n");
}

void print_tabulation(int n, int est_gauche) {
	printf("\n");
	for (int i = 0; i < n-1; i++) {
		printf("    ");
	}
	if (est_gauche) printf("gau ->");
	else  printf("droi->");
}

