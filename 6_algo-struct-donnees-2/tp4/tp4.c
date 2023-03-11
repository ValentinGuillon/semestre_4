
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <linked_list.h>
#include <hachage_table.h>

#define TAILLE_REP 10000


double time_spent(void (*fonction)(char*, char*, char*), char *filename, char *nom, char *phone);


//temps ajout de contact PUIS import de bdd
void test_ll_1(char *filename, char *nom, char *phone);
//temps ajout de contact PUIS import de bdd
void test_ll_2(char *filename, char *nom, char *phone);




int main(int argc, char *argv[]) {
    //récupération du nom de la bdd csv (donné arg d'exécution)
    if (argc < 2) {
        printf("ERROR: Il manque un argument\nCompiler comme suit :\n\033[38;2;255;171;0m$~ ./tp4 <filename>.csv\033[0m\n");
        return 0;
    }
    
    char filename[30];
    strcpy(filename, argv[1]);





    //tests de vitesse
    double t1, t2;
    printf("==== TEST LINKED LIST 1 ====\n(recherche contact situé en queue de liste)\n");
    t1 = time_spent(test_ll_1, filename, "Valentin Guillon", "0123456789");

    printf("\n==== TEST LINKED LIST 2 ====\n(recherche contact situé en tête de liste)\n");
    t2 = time_spent(test_ll_2, filename, "Valentin Guillon", "0123456789");


    printf("\n\nTest ll 1 duration = %f\n", t1);
    printf("Test ll 2 duration = %f\n", t2);


    // repertoire *rep = create_rep(TAILLE_REP);

    // rep = ajouter_repertoire(rep, "Valentin Guillon", "0123456789");

    // afficher_rep(rep);

    return 0;
}





void test_ll_1(char *filename, char *nom, char *phone) {
    contact *contacts = NULL;

    contacts = ajouter_liste(contacts, nom, phone);
    contacts = ajout_db_liste(filename, contacts);

    // afficher_liste(contacts);

    rechercher_liste(contacts, nom, phone);

    free_contact(contacts);
    printf("free successed\n");
}


void test_ll_2(char *filename, char *nom, char *phone) {
    contact *contacts = NULL;

    contacts = ajout_db_liste(filename, contacts);
    contacts = ajouter_liste(contacts, nom, phone);

    // afficher_liste(contacts);

    rechercher_liste(contacts, nom, phone);

    free_contact(contacts);
}




double time_spent(void (*fonction)(char*, char*, char*), char *filename, char *nom, char *phone) {
	clock_t start, end;
	double time;

	start = clock();
	fonction(filename, nom, phone);
	end = clock();

	time = (double)(end - start) / CLOCKS_PER_SEC;
	return time;
}



