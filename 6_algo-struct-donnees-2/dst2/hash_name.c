
// question9
// gcc -Wall -Wextra -g -fsanitize=address    -c -o hash.o hash.c
// gcc -Wall -Wextra -g -fsanitize=address  hash.o hash_name.c -o hash_name

#include "hash.h"
#include<stdio.h>

int main(void) {
    char my_name[] = "valentin";
    int nb_nodes = 5;
    int long index;

    index = get_index(my_name, nb_nodes);

    printf("index de \"%s\" avec %d noeud = %ld\n", my_name, nb_nodes, index);
    return 0;
}
