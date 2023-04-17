/* programme déterminant le chemin le plus rapide entre un noeud donné et tous les autres d'une matrice
 * en utilisant le'algorithme de Dijkstra
 */

#include<dijkstra.h>
#include<stdio.h>
#include<stdlib.h>


//#define size 7 //nombre de noeud de la matrice


// alloue de la mémoire pour une matrice [x][y]
int** allocate_matrice(int **mat, int x, int y);

// libère la mémoire d'une matrice [x][]
int** free_matrice(int **mat, int x);



int main(int argc, char** argv) {
    // arrêt du programme si on ne donne pas d'argument à l'exécution
    if (argc == 1) {
        printf("Argument is missing: must give at least one.\n");
        printf(" 1: metro parisien\n");
        printf(" 2: metro parisien sans ligne 4 dans un sens\n");
        printf(" 3: metro parisien sans ligne 4 dans un sens (mais avec plus de noeud\n");
        return 0;
    }

    // arrêt du programme si l'argument donné n'est pas correcte

    int size;

    switch (argv[1][0]) {
        case '1':
            size = 7;
            break;
        case '2':
            size = 7;
            break;
        case '3':
            size = 9;
            break;
        default:
            printf("Wrong argument.\n");
            printf(" 1: metro parisien\n");
            printf(" 2: metro parisien sans ligne 4 dans un sens\n");
            printf(" 3: metro parisien sans ligne 4 dans un sens (mais avec plus de noeud\n");
            return 0;
    }



    // réseau de métro parisiens sur 7 gares principales
    int metro_parisien[7][7] = {
        {0,   INF, INF, INF, INF, 12,  5},
        {INF, 0,   2,   INF, INF, INF, 7},
        {INF, 2,   0,   13,  INF, INF, 10},
        {INF, INF, 13,  0,   INF, INF, INF},
        {INF, INF, INF, INF, 0,   INF, 2},
        {12,  INF, INF, INF, INF, 0,   12},
        {5,   7,   10,  INF, 2,   12,  0}
    };
    
    // pareil, mais avec une ligne ne circulant pas dans un sens
    int metro_parisien_sans_4[7][7] = {
        {0,   INF, INF, INF, INF, 12,  5},
        {INF, 0,   2,   INF, INF, INF, 7},
        {INF, 2,   0,   13,  INF, INF, INF},
        {INF, INF, 13,  0,   INF, INF, INF},
        {INF, INF, INF, INF, 0,   INF, 2},
        {12,  INF, INF, INF, INF, 0,   12},
        {5,   7,   10,  INF, 2,   INF, 0}
    };

    // pareil, mais avec une ligne ne circulant pas dans un sens
    int metro_parisien_sans_4_mais_plus_grand[9][9] = {
        {0,   INF, INF, INF, INF, 12,  5,   6,   INF},
        {INF, 0,   2,   INF, INF, INF, 7,   INF, INF},
        {INF, 2,   0,   13,  INF, INF, INF, INF, INF},
        {INF, INF, 13,  0,   INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 0,   INF, 2,   INF, INF},
        {12,  INF, INF, INF, INF, 0,   12,  INF, 4  },
        {5,   7,   10,  INF, 2,   INF, 0,   INF, 6  },
        {6,   INF, INF, INF, INF, INF, INF, 0,   INF},
        {INF, INF, INF, INF, INF, 4,   6,   INF, 0  },
    };

    int **matrice = NULL; //matrice de taille [size][size]
    
    // allocation mémoire
    matrice = allocate_matrice(matrice, size, size);

    // remplissage avec une matrice déjà existante
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (argv[1][0] == '1')
                matrice[i][j] = metro_parisien[i][j];
            else if (argv[1][0] == '2')
                matrice[i][j] = metro_parisien_sans_4[i][j];
            else if (argv[1][0] == '3')
                matrice[i][j] = metro_parisien_sans_4_mais_plus_grand[i][j];
        }
    }



    // demande du noeud de départ
    int node = 1;
    printf("Quel noeud de départ ? (entre 1 et %d)\n>", size);
    while(1) {
        scanf("%d", &node);
        if (node >= 1 && node <= size)
            break;
        printf("wrong node (entre 1 et %d)\n>", size);
    }


    //trajets le plus rapide entre "node" et tous les autres
    int **paths = NULL; //doit être de taille [size][size+1]
    
    //allocation mémoire
    paths = allocate_matrice(paths, size, size+1);

    //remplissage
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size+1; j++)
            paths[i][j] = -1;
    }




    //résolution des trajets
    dijkstra(matrice, size, node, paths);

    printf("\nNoeud de départ : %d\n\n", node);
    afficher_trajets(paths, size, node);

    free_matrice(matrice, size);
    free_matrice(paths, size);
    return 0;
}





// alloue de la mémoire pour une matrice [x][y]
int** allocate_matrice(int **mat, int x, int y) {
    mat = malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
        mat[i] = malloc(y * sizeof(int*));
    
    return mat;
}


// libère la mémoire d'une matrice [x][]
int** free_matrice(int **mat, int x) {
    for (int i = 0; i < x; i++)
        free(mat[i]);
    free(mat);

    return mat;
}
