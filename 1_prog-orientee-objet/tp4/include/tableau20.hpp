
#ifndef TABLEAU20_H
#define TABLEAU20_H
#define TAILLE 5

#include <iostream>
using namespace std;


class tableau20_t {
    int tab[TAILLE];


    public:
        tableau20_t (void);
        /*tableau20_t (void);*/

        friend ostream &operator<<(ostream &out, tableau20_t &tabl) {
            out<<"[";

            for (int i = 0; i < TAILLE -1; i++)
                out<<tabl[i]<<", ";

            return out<<tabl[TAILLE]<<"]";
        }

        //retourne le nombre de case vide (== 0)
        int nbNul(void) const;

        //définition de l'opérateur [] (call ex: tab[5])
        int & operator[] (int index);

        /*tableau20_t & operator= (const tableau20_t &other_tab);*/

        //somme des var des deux tableaux
        tableau20_t operator+ (const tableau20_t &other_tab) const;
};


#endif
