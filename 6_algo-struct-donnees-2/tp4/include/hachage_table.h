

#ifndef CONTACT_STRUCT
#define CONTACT_STRUCT

typedef struct contact_s {
    char name[50];
    char phone[10];
    struct contact_s * next;
} contact;

#endif


#ifndef HACHAGE_TABLE_H
#define HACHAGE_TABLE_H


typedef struct repertoire_s {
    int taille_table;
    int nb_contacts;
    contact **tableau[]; //pointeur vers un tableau de pointeurs de contact
} repertoire;



//intègre toutes les données d'une bdd dans une liste chainée
repertoire* ajout_db_rep(char *file_name, repertoire* rep, long length);



//retourne un nombre obtenu en hachant un str
long hashage (char *str);
//retourne le hash de "key"
long get_index (char *key, int taille_tab);

//créé un objet "repertoire", et retourne sont adresse
repertoire *create_rep(int len);
//ajoute un contact dans un repertoire
repertoire *ajouter_repertoire(repertoire *rep, char* nom, char* telephone);

//affiche si le contact existe dans le repo
void rechercher_rep(repertoire *rep, int length, char* nom, char* telephone);


//affiche le répertoitr (uniquement aux index où les ll ont au moins un élément)
void afficher_rep(repertoire *rep);

//libère la mémoire du répertoire
void free_rep(repertoire *rep);


#endif
