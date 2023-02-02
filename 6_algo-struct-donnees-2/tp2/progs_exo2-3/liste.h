#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
typedef struct Element Element;
typedef struct Liste Liste;

Liste *initialisation();

void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);



#endif // LISTE_H_INCLUDED
