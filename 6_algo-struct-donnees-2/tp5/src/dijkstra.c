
#include<dijkstra.h>
#include<stdio.h>



void dijkstra(int **mat, int size, int node, int **paths) {
    for (int i = 0; i < size; i++) {
        if (i == node)
            paths[i][0] = 0;
        fastest_path(mat, size, node, i, paths[i]);
    }
}






//détermine le chemin le plus court entre "node_a" et "node_b"
void fastest_path(int **mat, int size, int node_a, int node_b, int *path){
    int distances[size]; //distance minimal entre "node_a" et les autres
    int visited[size]; //état visité(1) ou non(0) de chaque noeud de la matrice (ex: noeud 4 <=> index 3)
    tuple predecesseurs[size]; //a:predecesseurs, b:distance from a. Noeud précédent l'observation de chaque noeud
    int distance_from_a = 0; //distance entre le noeud de départ, et le noeud observé

    int current_node = node_a; //noeud observé
    //initialiser les tableaux
    fill_with(visited, size, 0); visited[node_a] = 1;
    fill_with(distances, size, INF); distances[node_a] = 0;
    // fill_with(predecesseurs, size, -1); predecesseurs[node_a] = INF;
    for (int i = 0; i < size; i++) {
        predecesseurs[i].a = -1;
        predecesseurs[i].b = INF;
    }


    int input;
    int loop_without_operation = 0;
    while (!all_visited(visited, size)) {
        if (loop_without_operation > 10000)
            break;
        printf("------------loop %d\n", loop_without_operation);
        printf("current node:    %d\n", current_node+1);
        printf("distance_from_a: %d\n", distance_from_a);
        printf("distances:       "); print_tab(distances, size);
        printf("visited:         "); print_tab(visited, size);
        printf("predecesseurs:   "); //print_tab(predecesseurs, size);
        for (int i = 0; i < size-1; i++)
            printf("%d(%d,%d), ", i, predecesseurs[i].a, predecesseurs[i].b);
        printf("%d(%d,%d)\n", size-1, predecesseurs[size-1].a, predecesseurs[size-1].b);

        // scanf("%d", &input);

        // if (loop_without_operation <= size)
        //     break;


        for (int i = 0; i < size; i++) {
            //ignore visited node
            if (visited[i])
                continue;
            //ignore le noeud observé
            if (i == current_node)
                continue;

            //pas de lien direct entre les deux noeuds observés
            if (mat[current_node][i] == INF)
                continue;
            //les deux noeuds observés sont un seul et même noeud
            if (mat[current_node][i] == 0)
                continue;


            if (distances[i] > mat[current_node][i] + distance_from_a) {
                distances[i] = mat[current_node][i] + distance_from_a;
                predecesseurs[i].a = current_node;
                predecesseurs[i].b = distances[i];
            }
        }


        int temp = index_of_the_smallest_no_visited(distances, visited, size);

        // distance_from_a = distance_from_start(mat, predecesseurs, temp);
        distance_from_a = predecesseurs[temp].b;
        current_node = temp;
        
        visited[current_node] = 1;


        loop_without_operation++;
    }


    path[0] = distances[node_b];
    // for (int i = 1; i < size + 1; i++)
    //     path[i] = i*2;

    // enregistrement de la distance minimal, et du chemin
    path[0] = distances[node_b];

    int to = node_b, from = predecesseurs[to].a;
    for (int i = 1; to != node_a && to != -1; i++) {
        path[i] = to;
        printf("%d\n", path[i]);
        to = predecesseurs[from].a;
        from = predecesseurs[to].a;
    }

}














//rempli un tableau avec une valeur donnée
void fill_with(int *tab, int size, int value) {
    for (int i = 0; i < size; i++)
        tab[i] = value;
}

//retourne 1 si "tab" est rempli de 1
int all_visited(int *tab, int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == 0)
            return 0;
    }
    return 1;
}

//return the smallest no-null value
int smallest(int *tab, int size) {
    int minimal = INF;

    for (int i = 0; i < size; i++) {
        //ignore nul value
        if (tab[i] == 0)
            continue;
        if (tab[i] < minimal)
            minimal = tab[i];
    }
    return minimal;
}

//return the index containing the smallest no-null value
int index_of_the_smallest_no_visited(int *tab, int *visited, int size) {
    int index = size;
    int smallest = INF;

    for (int i = 0; i < size; i++) {
        //ignore null value
        if (tab[i] == 0)
            continue;
        //ignore infinite value
        if (tab[i] == INF)
            continue;
        //ignore visited
        if (visited[i])
            continue;

        if (smallest > tab[i]) {
            index = i;
            smallest = tab[i];
        }
    }
    if (smallest == INF) {
        printf("ERROR: in index_of_the_smallest_no_visited: INF returned\n");
        return 0;
    }

    return index;
}


void print_tab(int *tab, int size) {
    for (int i = 0; i < size-1; i++)
        printf("%d, ", tab[i]);
    printf("%d\n", tab[size-1]);
}



int distance_from_start(int **mat, tuple *predecesseurs, int to) {
    int distance = 0;

    int from = predecesseurs[to].a;
    while(to != 2 || to != -1) {
        printf("from=%d, to=%d\n", from, to);
        distance += mat[from][to];
        to = predecesseurs[from].a;
        from = predecesseurs[to].a;
    }

    return distance;
}


