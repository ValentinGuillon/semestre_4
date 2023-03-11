
//définition d'un liste chainée de contact (name, phone)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <linked_list.h>
#include <hachage_table.h>


repertoire* ajout_db_rep(char *file_name, repertoire* rep, long length){
	// lecture du fichier 
	FILE* stream = fopen(file_name, "r");

	// ligne limitée à 1024 caractères 
	char line[1024];

	while (fgets(line, 1024, stream)) {
	    char* tmp = strdup(line);
        // char* nom = getfield(tmp, 1);
        // char* phone = getfield(tmp, 2);

        long index = get_index(getfield(tmp, 1), length);

        contact *list = *rep->tableau[index];

		list = ajouter_liste(list, getfield(tmp, 1), getfield(tmp, 2));
	    free(tmp);
	}

    fclose(stream);
	return rep;
}






long hashage (char *str) {
    long hash = 5381;

    while (*str != '\0') {
        hash = ((hash << 5) + hash) + *str; //hash * 33 + c
        str++;
    }
    
    return hash;
}


long get_index (char *key, int taille_tab) {
    return hashage(key) % taille_tab;
}



repertoire *create_rep(int len) {
    repertoire *repo = malloc(sizeof(repertoire));
    assert(repo);

    // int taille_table;
    // int nb_contact;
    // contact *tableau[];

    repo->taille_table = len;
    repo->nb_contacts = 0;
    *repo->tableau = malloc(sizeof(contact*) * len);

    for (int i = 0; i < len; i++)
        *(repo->tableau)[i] = NULL;

    return repo;
}



repertoire *ajouter_repertoire(repertoire *rep, char* nom, char* telephone) {

    long index = get_index(nom, rep->taille_table);

    *(rep->tableau)[index] = ajouter_liste(*rep->tableau[index], nom, telephone);
    rep->nb_contacts ++;

    return rep;
}


void rechercher_rep(repertoire *rep, int length, char* nom, char* telephone) {
    //génération de l'index du contact

    long index = get_index(nom, length);

    contact *list = *(rep->tableau)[index];

    
    //recherche du contact dans la liste "c"
    int names_equal, phones_equal;

    while (list != NULL) {
        names_equal = strcmp(list->name, nom);
        phones_equal = strcmp(list->phone, telephone);

        if (names_equal == 0 && phones_equal == 0) {
            printf("Contact trouvé dans le répertoire\n");
            return;
        }
        
        list = list->next;
    }

    //contact non trouvé
    printf("Le contact n'est pas dans le répertoire\n");
}



void afficher_rep(repertoire *rep) {
    if (! rep->nb_contacts) {
        printf("Répertoire vide");
        return;
    }

    // contact *list = NULL;



    printf("(début du répertoire)\n");
    for (long i = 0; i < rep->taille_table; i++) {
        if (rep->tableau[i] == NULL)
            continue;

        printf("==== Début index %ld ====\n", i);
        afficher_liste(*(rep->tableau)[i]);
        printf("====  Fin  index %ld ====\n", i);
    }

    printf("(fin du répertoire)\n");
}

void free_rep(repertoire *rep) {
    if (! rep->nb_contacts)
        return;

    for (long i = 0; i < rep->taille_table; i++)
        free_contact(*(rep->tableau)[i]);
}
