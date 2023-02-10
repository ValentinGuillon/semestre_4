#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int permute(int* a, int* b);
void affiche_tableau(int T[], int n);
void affiche_extremites_tableau(int T[], int n);
int tri_a_bulle(int T[], int n);
int tri_a_bulle_optimise(int T[], int n);
int tri_a_bulle_giga_optimise(int T[], int n);



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

    printf("{");

    for (int i = 0; i < n; i++) {
        printf("%d", T[i]);
        if (i+1 == n) continue; //pour ne pas mettre de virgule après le dernier élément
        printf(", ");
    }

    printf("}\n~~~ fin du tableau ~~~\n");
}


//affiche uniquement les 4 permiers/derniers élément du tableau
void affiche_extremites_tableau(int T[], int n){
    int dots_printed = 0;

    printf("{");

    for (int i = 0; i < n; i++) {
        if (i < 4 || i >= n-4) {
            printf("%d", T[i]);
            if (i+1 == n) continue; //pour ne pas mettre de virgule après le dernier élément
            printf(", ");
            continue;
        }

        if (! dots_printed) {
            printf( "..., ");
            dots_printed = 1;
        }

    }

    printf("}\n");
}

/* Fonctions de tri à bulle */

int tri_a_bulle(int T[], int n) {
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
    int trie;

    for (int i=n ; i > 0 ; i--){
	    trie=1;

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


//incrémente une var quand il n'y a pas de changement, si oui, la remet à zéro
//à la fin du parcours, on soustrait var pour le prochain parcours
//ex: si on fait un parcours sur dix éléments, mais que les 4 derniers n'ont pas eu à changer, donc var=4, le précédent parcours sera donc réduit de 4 (en plus du i réduit de base par 1)

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
