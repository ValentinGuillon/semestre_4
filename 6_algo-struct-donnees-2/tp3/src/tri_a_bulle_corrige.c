#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DÉFINIR UNE TAILLE DE VOTRE CHOIX
// #define TAB_SIZE ??

/* UTILS */ 
int permute(int* a, int* b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return 0;
}

void affiche_tableau(int T[], int n){
    /* cette fonction doit afficher un tableau */
	// À COMPLÉTER
    int dot_printed = 0;

    printf("{");
    for (int i = 0; i < n; i++) {
        if (i < 4 || i > n-4) {
            printf("%d", T[i]);
            if (i+1 < n) printf(", ");
            continue;
        }

        if (! dot_printed) {
            printf( "...,");
            dot_printed = 1;
        }

    }
    printf("}\n~~~ fin du tableau ~~~\n");
}

/* Fonctions de tri à bulle */

int tri_a_bulle(int T[], int n)
{
    int temp;
    for (int i=n ; i > 0 ; i--){
        for(int j = 0 ; j < i-1 ; j++) {
            if(T[j] > T[j+1]){
                permute(&T[j],&T[j+1]);
            }
        }
    }
    return 0;
}

int tri_a_bulle_optimise(int T[], int n) {
    int temp;
    for (int i=n ; i > 0 ; i--){
	    int trie=1;
        for(int j = 0 ; j < i-1 ; j++) {
            if(T[j] > T[j+1]){
                permute(&T[j],&T[j+1]);
                trie = 0;
            }
        }
        if (trie == 1){
        	printf("trié avec i=%d\n",i);
			return 0;
		}
    }
    return 0;
}


int tri_a_bulle_giga_optimise(int T[], int n) {
    int none_swapped = 0;
    for (int i = n-1; i > 0; i--) {
        none_swapped = 0;
        for (int j = 0; j < i; j++) {
            if (T[j] > T[j+1]) {
                permute(&T[j], &T[j+1]);
                none_swapped = 0;
            }
            else none_swapped++;
        }
        i -= none_swapped;
    }
    return 0;
}



/*
int main()
{

	// DÉCLARATION TABLEAU(X) DE LA TAILLE TAB_SIZE
    
    // Tri à bulle 
    
    double time_spent=0; 
    // À COMPLETER
    
    printf("Temps d'exécution tri bulle : %f\n\n", time_spent);
    
    // Tri à bulle otpimisé //
    // À COMPLETER
    
    printf("Temps d'exécution tri bulle optimisé : %f\n\n", time_spent);
    
    return 0;
    
    
}
*/