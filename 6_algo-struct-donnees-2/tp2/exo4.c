
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct s_noeud_t {
	int v;
	struct noeud_t* g;
	struct noeud_t* d;
} noeud_t;


noeud_t* add_node(int val);
void insert(noeud_t* tree, int n);
int hauteur(noeud_t* tree);
int max(int a, int b);
void print_tree(noeud_t* tree);





int main(void) {
	noeud_t *tree = add_node(5);
	insert(tree, 4);
	insert(tree, 5);
	insert(tree, 7);
	insert(tree, 2);
	insert(tree, 9);

	print_tree(tree);


	return 0;
}





noeud_t* add_node(int val) {
	noeud_t* tree = malloc(sizeof(noeud_t));
	assert(tree);

	tree->v = val;
	tree->g = NULL;
	tree->d = NULL;

	return tree;
}





void insert(noeud_t* tree, int n) {
	if (tree->g == NULL) {
		tree->g = add_node(n);
		return;
	}
	else if (tree->d == NULL) {
		tree->g = add_node(n);
		return;
	}



	if (hauteur(tree->g) > hauteur(tree->d)) {
		insert(tree->d, n);
	}
	else {
		insert(tree->g, n);
	}
}






int max(int a, int b){
	if (b > a) return b;
	return a;
}



int hauteur(noeud_t* tree) {
	if (tree == NULL) {
		return 1;
	}

	return 1 + max(hauteur(tree->g), hauteur(tree->d));
}



void print_tree(noeud_t* tree) {
	printf("%d ->", tree->v);

	if (tree->g != NULL) print_tree(tree->g);
	if (tree->d != NULL) print_tree(tree->d);

}



