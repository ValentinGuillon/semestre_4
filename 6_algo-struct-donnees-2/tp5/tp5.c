
#include<dijkstra.h>
#include<stdio.h>
#include<stdlib.h>


#define SIZE 7 //nombre de noeud de la matrice


int main(void) {
    //réseau de métro parisiens sur 7 gares principales
    int matrice[SIZE][SIZE] = {{0,   INF, INF, INF, INF, 12,  5},
                               {INF, 0,   2,   INF, INF, INF, 7},
                               {INF, 2,   0,   13,  INF, INF, 10},
                               {INF, INF, 13,  0,   INF, INF, INF},
                               {INF, INF, INF, INF, 0,   INF, 2},
                               {12,  INF, INF, INF, INF, 0,   12},
                               {5,   7,   10,  INF, 2,   12,  0}};


    /*
    //pareil, mais avec une ligne ne circulant pas dans un sens
    int matrice[SIZE][SIZE] = {{0,   INF, INF, INF, INF, 12,  5},
                               {INF, 0,   2,   INF, INF, INF, 7},
                               {INF, 2,   0,   13,  INF, INF, INF},
                               {INF, INF, 13,  0,   INF, INF, INF},
                               {INF, INF, INF, INF, 0,   INF, 2},
                               {12,  INF, INF, INF, INF, 0,   12},
                               {5,   7,   10,  INF, 2,   INF, 0}};
    */

    int **mat = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
        mat[i] = malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
            mat[i][j] = matrice[i][j];
    }

    // for (int i = 0; i < SIZE; i++){
    //     for (int j = 0; j < SIZE; j++) {
    //         printf("matrice[%d][%d] = %d\n", i, j, matrice[i][j]);
    //         printf("mat    [%d][%d] = %d\n", i, j, mat[i][j]);
    //     }
    // }




    /* demander le noeud de départ */
    int node = 1;
    printf("Quel noeud de départ ? (entre 1 et 7)\n>");
    scanf("%d", &node);

    /* afficher la distance minimal, puis le chemin à parcourir
     * entre le départ et chacun des autres noeud
     */

    //trajets le plus rapide entre "node" et tous les autres
    int paths[SIZE][SIZE+1]; //+1 pour laisser la place à la distance du trajet

    int **fp = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE+1; i++)
        fp[i] = malloc(SIZE+1 * sizeof(int*));

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE+1; j++)
            fp[i][j] = -1;
    }

    dijkstra(mat, SIZE, node-1, fp);


    for (int i = 0; i < SIZE; i++) {
        printf("fp[%d] = ", i);
        print_tab(fp[i], SIZE+1);
    }

    return 0;
}


