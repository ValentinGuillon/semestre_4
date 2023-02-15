
#include <stdio.h>
#include <arbre_binaire_abr.h>

// \033[38;2;255;154;0;1m



//affiche un arbre, vérifie s'il est de recherche, détermine le min/max
void test_si_abr(noeud_t* tree, int id);

//affiche un arbre, supprime une valeur, réaffiche
void test_suppr_val(noeud_t* tree, int val, int id);





int main(void) {
	noeud_t *tree = NULL;

	//================================
	//  Test d'arbres de recherche
	//================================

	printf("\033[38;2;255;154;0;1m============================\n    TEST ABRité D'ARBRES\n============================\033[0m\n\n");
	printf("Les arbres sont indiqués en préfixe\n");

	//premier arbre
	printf("\nArbre 1: devrait être de recherche\n");
	test_si_abr(tree, 1);
	cut_tree(tree);

	//deuxième arbre
	tree = add_t(18, add_t(4, add_t(2, NULL, add_t(5, NULL, NULL)), add_t(17, NULL, NULL)), add_t(19, NULL, NULL));
	printf("\nArbre 2: ne devrait pas être de recherche (à cause du 5)\n");
	test_si_abr(tree, 2);
	cut_tree(tree);

	//troisième arbre
	tree = add_t(3, add_t(4, NULL, NULL), add_t(6, add_t(2, NULL, NULL), NULL));
	printf("\nArbre 3: ne devrait pas être de recherche (à cause du 2)\n");
	test_si_abr(tree, 3);
	cut_tree(tree);

	//quatrième arbre
	tree = add_t(3, add_t(1, NULL, add_t(3, NULL, NULL)), add_t(6, NULL, NULL));
	printf("\nArbre 4: ne devrait pas être de recherche (à cause de 3)\n");
	test_si_abr(tree, 4);
	cut_tree(tree);

	//cinquième arbre
	tree = add_t(3, add_t(1, NULL, add_t(2, NULL, NULL)), add_t(6, NULL, NULL));
	printf("\nArbre 5: devrait être de recherche\n");
	test_si_abr(tree, 5);
	cut_tree(tree);



	//==========================================
	//  Test de suppression de val dans un ABR
	//==========================================

	printf("\n\n\033[38;2;255;154;0;1m=======================\n    TEST REMOVE VAL\n=======================\033[0m\n\n");
	printf("Les arbres sont indiqués en préfixe\n");


	tree = add_t(5, add_t(2, add_t(1, NULL, NULL), add_t(3, NULL, NULL)), add_t(10, add_t(8, add_t(6, NULL, NULL), add_t(9, NULL, NULL)), add_t(15, add_t(12, NULL, NULL), NULL)));

	printf("\nArbre 1: ");
	test_suppr_val(tree, 5, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 3, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 2, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 1, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 4, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 6, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 15, 1);
	printf("\nArbre 1: ");
	test_suppr_val(tree, 8, 1);
	cut_tree(tree);



}






//affiche un arbre, vérifie s'il est de recherche, détermine le min/max
void test_si_abr(noeud_t* tree, int id) {
	int min, max; //si l'arbre n'est pas de recherche, ces valeurs seront inexactes
	int arbre_est_binaire;

    if (tree == NULL)
	    min = max = 0;
    else 
	    min = max = tree->v;

	arbre_est_binaire = is_search_binary_tree(tree, &min, &max);
	print_tree(tree, 0);
	print_t(tree);

	if (arbre_est_binaire) {
		printf("\033[38;2;255;154;0;1mL'arbre %d est un binaire de recherche\n", id);
		printf("min = %d, max = %d\033[0m\n", min, max);
	}
	else printf("\033[38;2;255;154;0;1mL'arbre %d N'EST PAS un binaire de recherche\033[0m\n", id);
}





void test_suppr_val(noeud_t* tree, int val, int id) {
	if (tree == NULL) {
		printf("Arbre %d est NULL\n", id);
		return;
	}

	printf("avant suppression de %d\n", val);

	int min, max;
	min = max = tree->v;

	// print_tree(tree, 0);
	print_t(tree);


	if (!is_search_binary_tree(tree, &min, &max)) {
		printf("Arbre %d n'est pas un ABR\n", id);
		return;
	}


	tree = remove_val(tree, val);

	printf("Arbre %d: \033[38;2;255;154;0;1maprès suppression de %d\033[0m\n", id, val);
	print_t(tree);
}
