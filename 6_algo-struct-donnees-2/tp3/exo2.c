
#include <stdio.h>
#include <arbre_binaire_abr.h>

// \033[38;2;255;154;0;1m




void analyse_tree(noeud_t* tree, int id);



int main(void) {
	noeud_t *tree = NULL;

	printf("Les arbres sont parcourus en préfixe\n");

	//premier arbre
	printf("\nArbre 1: devrait être de recherche\n");
	analyse_tree(tree, 1);
	cut_tree(tree);

	//deuxième arbre
	tree = add_n(18, add_n(4, add_n(2, NULL, add_n(5, NULL, NULL)), add_n(24, NULL, NULL)), add_n(19, NULL, NULL));
	printf("\nArbre 2: ne devrait pas être de recherche (à cause du 5)\n");
	analyse_tree(tree, 2);
	cut_tree(tree);

	//troisième arbre
	tree = add_n(3, add_n(4, NULL, NULL), add_n(6, add_n(2, NULL, NULL), NULL));
	printf("\nArbre 3: ne devrait pas être de recherche (à cause du 2)\n");
	analyse_tree(tree, 3);
	cut_tree(tree);

	//quatrième arbre
	tree = add_n(3, add_n(1, NULL, add_n(3, NULL, NULL)), add_n(6, NULL, NULL));
	printf("\nArbre 4: ne devrait pas être de recherche (à cause de 3)\n");
	analyse_tree(tree, 4);
	cut_tree(tree);

	//cinquième arbre
	tree = add_n(3, add_n(1, NULL, add_n(2, NULL, NULL)), add_n(6, NULL, NULL));
	printf("\nArbre 5: devrait être de recherche\n");
	analyse_tree(tree, 5);
	cut_tree(tree);
}






void analyse_tree(noeud_t* tree, int id) {
	int min, max; //si l'arbre n'est pas de recherche, ces valeurs seront inexactes
	int arbre_est_binaire;

    if (tree == NULL)
	    min = max = 0;
    else 
	    min = max = tree->v;

	arbre_est_binaire = is_search_binary_tree(tree, &min, &max);
	print_tree(tree, 0);

	if (arbre_est_binaire) {
		printf("\033[38;2;255;154;0;1mL'arbre %d est un binaire de recherche\n", id);
		printf("min = %d, max = %d\033[0m\n", min, max);
	}
	else printf("\033[38;2;255;154;0;1mL'arbre %d N'EST PAS un binaire de recherche\033[0m\n", id);
}

