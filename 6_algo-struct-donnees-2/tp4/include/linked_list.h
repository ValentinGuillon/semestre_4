
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define CONTACT_STRUCT


typedef struct contact_s {
    char name[50+1];
    char phone[10+1];
    struct contact_s * next;
} contact;



char* getfield(char* line, int num);
//intègre toutes les données d'une bdd dans une liste chainée
contact* ajout_db_liste(char *file_name, contact* liste);

//créé un contact et l'ajoute en tête de liste
contact * ajouter_liste(contact *liste, char* nom, char* telephone);

// contact * rechercher_liste(contact *c); //modifiée, pour ne pas demander d'input
//affiche s'il le contact existe ou non
void rechercher_liste(contact *c, char* nom, char* telephone);


void afficher_liste(contact *list);
void free_contact(contact *list);

#endif
