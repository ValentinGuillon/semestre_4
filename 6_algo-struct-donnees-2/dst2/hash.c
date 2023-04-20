#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int i = 0;
    char c = str[i];
    while (c != '\0') {
        hash = hash * 33 + c;
        i++;
        c = str[i];
    }
    return hash;
}

unsigned long get_index(char* str, int nb_noeuds) {
	// calcule le hash de la chaîne str 
	// modulo le nombre de noeuds.	
    return hash(str) % nb_noeuds;
}


