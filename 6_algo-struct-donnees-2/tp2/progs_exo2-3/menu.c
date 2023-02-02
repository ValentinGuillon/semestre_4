#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short menu_bug()
{
    char saisie[100];
    unsigned short choix;
    while(1) {
        printf("\t****************** Bienvenue Au Grand Bazar ******************\n\n\n");
        printf("0 : Quitter\n");
        printf("\nVotre choix : ");
        fflush(stdout);

        fgets(saisie,100,stdin);
        if (sscanf(saisie, "%hu", &choix) == 1 && choix == 0) break;
        printf("Choix incorrect - Recommencez !!!\n");
    }
    return choix;
}

int run_menu()
{
    //Mise en place d'un systeme de mot de passe
    int motpasse =77;
    int code;

    do
    {
        printf("veuillez saisir le code : ");
        scanf("%d",&code);

        if(code==motpasse)
        {
            menu();
        }
        else
        {
            printf("Erreur de code !!!");
        }
    }
    while(code != motpasse);

    return 0;
}

int main()
{
    return 0;
}
