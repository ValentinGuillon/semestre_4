
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INF 9999 //désigne la distance entre 2 noeuds non directements connectés


//c'est pour les prédecesseurs, parceque ça me saoulait mdr
typedef struct tuple_t {
    int node, dist;
} tuple;


//determine la distance minimal et le trajet entre "node" et chacun des autres 
void dijkstra(int **mat, int size, int node, int **paths);

//détermine le chemin le plus court entre "node_a" et "node_b"
void fastest_path(int **mat, int size, int node_a, int node_b, int *path);


void afficher_trajets(int **trajets, int size, int start_node); //"trajets" est une matrice [size][size+1], avec [x][0] la distance, et [x][i>0], les noeuds du trajet



//return the index containing the smallest no-null value bewteen no-visited nodes
int index_of_the_smallest_no_visited(int *tab, int *visited, int size);

// //return the smallest no-null value
// int smallest(int *tab, int size);

//retourne 1 si "tab" est rempli de 1
int all_visited(int *tab, int size);

//rempli un tableau avec une valeur donnée
void fill_with(int *tab, int size, int value);

// void print_tab(int *tab, int size);

// int distance_from_start(int **mat, tuple *predecesseurs, int to);


#endif