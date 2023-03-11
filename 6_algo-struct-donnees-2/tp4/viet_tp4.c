

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/////////// 2.1 Structure contact 

struct contact_s{
    char nom[100];
    char telephone[10];
    struct contact_s * suivant;
};

typedef struct contact_s contact;


/////////// 2.2 Interaction avec la liste
//// Question 1:
contact * ajouter_liste(contact * liste, char * nom, char * telephone){
    contact * nouveau = malloc(sizeof(contact));
    strcpy(nouveau -> nom, nom);
    strcpy(nouveau -> telephone, telephone);
    nouveau -> suivant = liste;
    return nouveau;
};

char* getfield(char* line, int num){
	/* parse la ligne `line` selon le 
	   séparateur ';' et renvoie le champ
	   `num` */
    char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
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
	while (fgets(line, 1024, stream))
	{
	    char* tmp = strdup(line);
		liste = ajouter_liste(liste, getfield(tmp, 1), getfield(tmp, 2));
	    free(tmp);
	}
	return liste;
}

//// Question 2:
void rechercher_liste(contact * c){
    char nom[100];
    printf("Veuillez entrer le nom (et prénom) du contact a rechercher : ");
    scanf("%99[^\n]", nom); //// en spécifiant limit de 99 caractères.
    while (c != NULL){
        if (strcmp(c->nom, nom) == 0){
            printf("Contact trouvé:\nNom: %s, téléphone: %s\n", c->nom, c->telephone);
            return;
        }
        c = c->suivant;
    }
    printf("Le contact n'est pas dans la liste.\n");    
};


/////////// 2.2 Temps de recherche
//// Question 1: déjà ajouter dans main()
//// Question 2: déjà ajouter dans main()



/////////// 3.1 Structure repertoire
//// Question 1: 
typedef struct repertoire_s{
    int taille_tab;
    contact ** tableau;
} repertoire;

//// Question 2:
unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    
    return hash;
}

//// Question 3:
int get_index(char * key, int tab_size){
    return (hash(key) % tab_size);
}



/////////// 3.2 Intéraction avec le répertoire
//// Question 1:
repertoire * create_rep (int len){
    repertoire *rep = malloc(sizeof(repertoire));
    rep->tableau = malloc(sizeof(contact*) * len);
    rep->taille_tab = len;
    for(int i = 0; i < len; i++){
        rep->tableau[i] = NULL;
    }
    return rep;
};

//// Question 2:
repertoire * ajouter_repertoire ( repertoire *rep , char* nom , char* telephone ){
    int index = get_index(nom, rep->taille_tab);
    rep->tableau[index] = ajouter_liste(rep->tableau[index], nom, telephone);
    return rep;
};

//// Question 3:
void rechercher_rep ( repertoire * rep , int length ){
    char nom[100];
    printf("Veuillez entrer le nom (et prénom) du contact a rechercher : ");
    scanf("%99[^\n]", nom);
    int index = get_index(nom, length);
    contact * ptr_contact = rep->tableau[index];
    while(ptr_contact != NULL) {
        if(strcmp(ptr_contact->nom, nom) == 0){
            printf("Contact trouvé:\nNom: %s, téléphone: %s\n", ptr_contact->nom, ptr_contact->telephone);
            return;
        }
        ptr_contact = ptr_contact->suivant;
    }
    printf("Le contact n'est pas dans la liste.\n");
};

//// Question 4:
repertoire * ajout_db_rep (char *file_name , repertoire * rep){
    FILE* stream = fopen(file_name, "r");
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        rep = ajouter_repertoire(rep, getfield(tmp, 1), getfield(tmp, 2));
        free(tmp);
    }
    fclose(stream);
    return rep;
};

void afficher_tableau(repertoire *rep){
    for(int i=0; i<rep->taille_tab; i++){
        printf("Index %d:\n", i);
        contact * curr = rep->tableau[i];
        while(curr){
            printf("Nom: %s, Téléphone: %s\n", curr->nom, curr->telephone);
            curr = curr->suivant;
        }
    }
};


/////////// 3.3 Temps de recherche
//// Question 1:
/*
Le temps de calcul de recherche dans la table de hachage dépendra 
de plusieurs facteurs tels que la taille de la table, 
le facteur de remplissage et la fonction de hachage. 
Si la table est bien dimensionnée, le temps de recherche dans la table de hachage 
peut être beaucoup plus rapide que dans une liste chaînée. 
Dans mon cas, pour les base de données, 
le temps de recherche dans la table de hachage est 
d'environ 0,000007 secondes (7 microseconds). 
Cela est nettement plus rapide que le temps de recherche dans une liste chaînée, 
surtout pour les bases de données plus grandes.
*/
//// Question 2: déjà ajouter dans main()



/////////// 3.4 Table de taille dynamique
//// Question 1:
typedef struct repertoire_dyn_s {
    contact ** tableau;
    int taille_tab;
    int nb_contacts;
} repertoire_dyn;

//// Question 2:
void check_resize(repertoire_dyn *rep)
{
    double load_factor = (double)rep->nb_contacts / (double)rep->taille_tab;
    if (load_factor > 0.8)
    {
        int new_taille_tab = 2 * rep->taille_tab;
        contact **new_tableau = calloc(new_taille_tab, sizeof(contact *));
        for (int i = 0; i < rep->taille_tab; i++)
        {
            contact *c = rep->tableau[i];
            while (c != NULL)
            {
                contact *next = c->suivant;
                int index = get_index(c->nom, new_taille_tab);
                c->suivant = new_tableau[index];
                new_tableau[index] = c;
                c = next;
            }
        }
        free(rep->tableau);
        rep->tableau = new_tableau;
        rep->taille_tab = new_taille_tab;
    }
}



int main(int argc, char *argv[]){
    // //////// Structure contact :
    // contact * ma_liste = NULL; 
    // //// Importer la base de données
    // ma_liste = ajout_db_liste(argv[1], ma_liste);
    // //// Ajouter mon contact à la liste
    // ma_liste = ajouter_liste(ma_liste, "Viet Nguyen", "0766740545");
    // // printf("%s", ma_liste->nom);
    // clock_t temp_rec = clock();
    // rechercher_liste(ma_liste);
    // double temp_passe = ((double)(clock() - temp_rec)) / CLOCKS_PER_SEC;
    // printf("Le contact a été trouvé en %.2f seconds.\n", temp_passe);
    

    //////// Structure répertoire :
    repertoire * mon_repertoire = create_rep(10); // initialisation du répertoire avec une table de hachage de taille 1000
    //// Importer la base de données
    mon_repertoire = ajout_db_rep(argv[1], mon_repertoire);
    //// Ajouter mon contact au répertoire
    mon_repertoire = ajouter_repertoire(mon_repertoire, "Victor Hugo", "0771241243");
    // printf("%s", ma_liste->nom);
    clock_t temp_rep = clock();
    rechercher_rep(mon_repertoire, mon_repertoire->taille_tab);
    double temp_passe_rep = ((double)(clock() - temp_rep)) / CLOCKS_PER_SEC;
    printf("Le contact a été trouvé en %.2f seconds.\n", temp_passe_rep);
    // Afficher le contenu de la table de hachage
    // afficher_tableau(mon_repertoire);

    // Tester différentes tailles de répertoire
    for (int i = 1; i <= 10; i++){
        mon_repertoire = create_rep(i);
        mon_repertoire = ajout_db_rep(argv[1], mon_repertoire);
        clock_t temp_test = clock();
        rechercher_rep(mon_repertoire, mon_repertoire->taille_tab);
        double temp_passe_test = ((double)(clock() - temp_test)) / CLOCKS_PER_SEC;
        printf("Pour un répertoire de taille %d, le temps de recherche est de %lf secondes.\n", i, temp_passe_test);
    }
    

    // //////// Structure répertoire dynamique :
    // repertoire_dyn * mon_repertoire_dyn = create_rep_dyn(10);
    // mon_repertoire_dyn = ajout_db_rep_dyn(argv[1], mon_repertoire_dyn);
    // mon_repertoire_dyn = ajouter_repertoire_dyn(mon_repertoire_dyn, "Viet Nguyen", "0766740545");
    // temp_rec = clock();
    // rechercher_rep_dyn(mon_repertoire_dyn, mon_repertoire_dyn->taille_tab);
    // temp_passe = ((double)(clock() - temp_rec)) / CLOCKS_PER_SEC;
    // printf("Le temps de recherche dans la table de hachage dynamique est de %lf secondes.\n", temp_passe);
    
    // // Importer la base de données à une table de taille dynamique
    // mon_repertoire_dyn = create_rep_dyn(10);
    // mon_repertoire_dyn = ajout_db_rep_dyn_dyn(argv[1], mon_repertoire_dyn);
    // printf("La taille de la structure après import de la base de données est de %d.\n", mon_repertoire_dyn->taille_tab);
    
    // // Test de taille de table dynamique
    // for (int i = 1; i <= 10; i++){
    //     mon_repertoire_dyn = create_rep_dyn(i);
    //     mon_repertoire_dyn = ajout_db_rep_dyn(argv[1], mon_repertoire_dyn);
    //     temp_rec = clock();
    //     rechercher_rep_dyn(mon_repertoire_dyn, mon_repertoire_dyn->taille_tab);
    //     temp_passe = ((double)(clock() - temp_rec)) / CLOCKS_PER_SEC;
    //     printf("Pour un répertoire dynamique de taille %d, le temps de recherche est de %lf secondes.\n", i, temp_passe);
    // }
    
    return 0;
}




