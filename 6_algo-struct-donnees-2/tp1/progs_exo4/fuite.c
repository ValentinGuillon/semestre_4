#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fuite() {
    static int* pIntNull;
    static int* pInt;

    pIntNull = malloc(sizeof(int));
    pIntNull = NULL; 
    
    pInt = malloc(sizeof(int));
    return 0;
}

int main()
{
    return 0;
}
