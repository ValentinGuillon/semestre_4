#include <stdio.h>
#include "liste.h"


int main(void) {
    Liste *a = initialisation();

    for (int i = 0; i < 5; i++) {
        insertion(a, i+1);
    }

    afficherListe(a);

    return 0;
}
