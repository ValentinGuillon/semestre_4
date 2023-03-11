
//définition d'un liste chainée de contact (name, phone)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <linked_list.h>



char* getfield(char* line, int num){
	/* parse la ligne `line` selon le séparateur ';' et renvoie le champ `num` */

    char* tok;
    for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
        if (!--num)
            return tok;
    }

    return NULL;
}



contact* ajout_db_liste(char *file_name, contact* liste){
	// lecture du fichier 
	FILE* stream = fopen(file_name, "r");

	// ligne limitée à 1024 caractères 
	char line[1024];

	while (fgets(line, 1024, stream)) {
	    char* tmp = strdup(line);
		liste = ajouter_liste(liste, getfield(tmp, 1), getfield(tmp, 2));
	    free(tmp);
	}

    fclose(stream);
	return liste;
}



contact * ajouter_liste(contact* liste, char* nom, char* telephone) {
    //création du contact
    contact * new_c = malloc(sizeof(contact));

    assert(new_c);

    strcpy(new_c->name, nom);
    strcpy(new_c->phone, telephone);
    new_c->next = NULL;


    //placement en tête de liste
    if (liste == NULL)
        liste = new_c;

    else {
        new_c->next = liste;
        liste = new_c;
    }

    return liste;
}



//affiche si le contact donnée est dans la liste "c"
void rechercher_liste(contact* c, char* nom, char* telephone) {
    //recherche du contact dans la liste "c"
    int names_equal, phones_equal;

    while (c != NULL) {
        names_equal = strcmp(c->name, nom);
        phones_equal = strcmp(c->phone, telephone);

        if (names_equal == 0 && phones_equal == 0) {
            printf("Contact trouvé dans la liste\n");
            return;
        }
        
        c = c->next;
    }

    //contact non trouvé
    printf("Le contact n'est pas dans la liste\n");
}



// //retourne l'adresse du contact (s'il existe), sinon NULL
// //en fait non mdr, pas cette version
// void rechercher_liste(contact* c, char* nom, char* telephone) {


//     printf("NOM:%s, PHONE:%s\n\n\n", nom, telephone);

//     char name_to_find[50];
//     char phone_to_find[10];


//     // //demander à l'user infos du contact
//     // printf("====== Recherche de contact ======\n");
//     // printf("Prénom et Nom: (ex: Valentin Guillon) (max 50 charactères)\n>");
//     // scanf("%s", name_to_find);
//     // printf("N° Téléphone: (ex: 01.23.45.67.89)\n>");
//     // scanf("%s.%s.%s.%s.%s", &phone_to_find[0], &phone_to_find[2], &phone_to_find[4], &phone_to_find[6], &phone_to_find[8]);

//     // //verifier validité de données 
//     // //...

//     strcpy(name_to_find, nom);
//     strcpy(phone_to_find, telephone);


//     printf("NOM:%s, PHONE:%s\n\n\n", name_to_find, phone_to_find);

//     // printf("NOM:%s, PHONE:%s\n\n\n", c->name, c->phone);


//     //recherche du contact dans la liste "c"
//     int names_equal, phones_equal;

//     while (c != NULL) {
//         names_equal = strcmp(c->name, name_to_find);
//         phones_equal = strcmp(c->phone, phone_to_find);

//         printf("nom:%s, phone:%s\n  nom recherché:%s\n  phone recherché:%s\n\n", c->name, c->phone, name_to_find, phone_to_find);

//         if (names_equal == 0 && phones_equal == 0) {
//             printf("\nLe contact trouvé\n");
//             return;
//         }
        
//         c = c->next;
//     }

//     //contact non trouvé
//     printf("\nLe contact n'est pas dans la liste\n");
//     // return NULL;
// }


void afficher_liste(contact *list) {
    printf("(début de la liste)\n");

    while(list != NULL) {
        printf("Nom: %s\n N°: %s\n\n", list->name, list->phone);
        list = list->next;
    }
    
    printf("(fin de la liste)\n");
}


void free_contact(contact *list) {
    if (list == NULL)
        return;

    free_contact(list->next);
    free(list);
}

