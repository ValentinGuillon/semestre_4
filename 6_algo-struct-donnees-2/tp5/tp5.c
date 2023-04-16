/* programme déterminant le chemin le plus rapide entre un noeud donné et tous les autres d'une matrice
 * en utilisant le'algorithme de Dijkstra
 */

#include<dijkstra.h>
#include<stdio.h>
#include<stdlib.h>


#define SIZE 7 //nombre de noeud de la matrice


int main(int argc, char** argv) {
    // arrêt du programme si on ne donne pas d'argument à l'exécution
    if (argc == 1) {
        printf("Argument is missing: must give at least one.\n");
        printf(" 1: metro parisien\n");
        printf(" 2: metro parisien sans ligne 4 dans un sens\n");
        return 0;
    }

    // arrêt du programme si l'argument donné n'est pas correcte
    if (argv[1][0] != '1' && argv[1][0] != '2') {
        printf("Wrong argument.\n");
        printf(" 1: metro parisien\n");
        printf(" 2: metro parisien sans ligne 4 dans un sens\n");
        return 0;
    }



    // réseau de métro parisiens sur 7 gares principales
    int metro_parisien[SIZE][SIZE] = {
        {0,   INF, INF, INF, INF, 12,  5},
        {INF, 0,   2,   INF, INF, INF, 7},
        {INF, 2,   0,   13,  INF, INF, 10},
        {INF, INF, 13,  0,   INF, INF, INF},
        {INF, INF, INF, INF, 0,   INF, 2},
        {12,  INF, INF, INF, INF, 0,   12},
        {5,   7,   10,  INF, 2,   12,  0}
    };
    
    // pareil, mais avec une ligne ne circulant pas dans un sens
    int metro_parisien_sans_4[SIZE][SIZE] = {
        {0,   INF, INF, INF, INF, 12,  5},
        {INF, 0,   2,   INF, INF, INF, 7},
        {INF, 2,   0,   13,  INF, INF, INF},
        {INF, INF, 13,  0,   INF, INF, INF},
        {INF, INF, INF, INF, 0,   INF, 2},
        {12,  INF, INF, INF, INF, 0,   12},
        {5,   7,   10,  INF, 2,   INF, 0}
    };


    int **matrice = NULL; //matrice de taille [size][size]
    
    // allocation mémoire
    matrice = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
        matrice[i] = malloc(SIZE * sizeof(int*));

    // remplissage avec une matrice déjà existante
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            if (argv[1][0] == '1')
                matrice[i][j] = metro_parisien[i][j];
            else if (argv[1][0] == '2')
                matrice[i][j] = metro_parisien_sans_4[i][j];
        }
    }



    // demande du noeud de départ
    int node = 1;
    printf("Quel noeud de départ ? (entre 1 et %d)\n>", SIZE);
    while(1) {
        scanf("%d", &node);
        if (node >= 1 && node <= SIZE)
            break;
        printf("wrong node (entre 1 et %d)\n>", SIZE);
    }


    //trajets le plus rapide entre "node" et tous les autres
    int **paths = NULL; //doit être de taille [size][size+1]
    
    //allocation mémoire
    paths = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE+1; i++)
        paths[i] = malloc(SIZE+1 * sizeof(int*));

    //remplissage
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE+1; j++)
            paths[i][j] = -1;
    }




    //résolution des trajets
    dijkstra(matrice, SIZE, node, paths);

    printf("\nNoeud de départ : %d\n\n", node);
    afficher_trajets(paths, SIZE, node);

    return 0;
}
