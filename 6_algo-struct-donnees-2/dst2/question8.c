
//question8
//gcc -Wall -Wextra -g -fsanitize=address question8.c -o question8
#include <stdlib.h>

typedef struct MaStruct
{
    int a;
    char b;
    char c;
    struct MaStruct* d;
}MaStruct;

int main(void) {
    MaStruct *p = malloc(sizeof(p));
    free(p);
    return 0;
}
