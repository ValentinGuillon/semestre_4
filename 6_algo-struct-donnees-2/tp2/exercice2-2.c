#include <stdio.h>

/* aucune autre variable ne doit être déclarée */

int main(void) {
	// Déclaration des variables a et b
	int a, b;
	// Demande à l’utilisateur de saisir les entiers a et b
	printf("Donnez un entier:\n>");
	scanf("%d", &a);
	printf("Un autre:\n>");
	scanf("%d", &b);


	// Tri des variables pour que le printf qui suit soit correct
	if (a > b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}



	// Affichage des valeurs dans l’ordre croissant
	printf("Valeurs saisies dans l’ordre croissant: %i, %i \n", a, b);
	// Retour
	return 0;
}
