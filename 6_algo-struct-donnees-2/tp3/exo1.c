
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tri_a_bulle_corrige.h>


#define SIZE 10000


void fill(int T[], int size);
double time_spent(int (*fonction)(int*, int), int T[], int size);



int main(void) {
	srand(time(0));

	printf("makefile de merde, je sais où t'habite\n");

	int list[SIZE];
	int temp[SIZE];

	fill(list, SIZE);
	memcpy(temp, list, sizeof(list));

	printf("\nTableau de base: (%d éléments)\n", SIZE);
	// affiche_tableau(list, SIZE);
	affiche_extremites_tableau(list, SIZE);

	printf("\nTemps moyen de tri: (sur 10 exécutions)\n");
	printf("Processing...\n");

	printf("Normal: \033[38;2;255;154;0;1m%f\033[0m\n", time_spent(tri_a_bulle, list, SIZE));
	memcpy(list, temp, sizeof(temp));
	printf("Optimisé: \033[38;2;255;154;0;1m%f\033[0m\n", time_spent(tri_a_bulle_optimise, list, SIZE));

	memcpy(list, temp, sizeof(temp));
	printf("Le mien, le meilleur: \033[38;2;255;154;0;1m%f\033[0m\n", time_spent(tri_a_bulle_giga_optimise, list, SIZE));


	printf("\nTableau trié:\n");
	// affiche_tableau(list, SIZE);
	affiche_extremites_tableau(list, SIZE);


	return 0;
}




void fill(int T[], int size) {
	for (int i = 0; i < size; i++) {
		T[i] = rand() % 24;
	}
}


double time_spent(int (*fonction)(int*, int), int T[], int size) {
	clock_t start, end;
	double time;

	start = clock();
	fonction(T, size);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	return time;
}
