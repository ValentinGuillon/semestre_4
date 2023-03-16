
#ifndef CHAINE_H
#define CHAINE_H

#include <iostream>

class chaine_t {
    int size;
    char *tab; //tab[]

    //copie les "size" premiers char de str
    void copy(char* ret, char* const str, int size, int index_start, int print) const;

    public:
        //constructeur de déclaration
        chaine_t (void);
        //constructeur par copie
        chaine_t (chaine_t const &obj);
        //constructeur avec un tableau de char
        chaine_t (char* const str);
        //constructeur qui convertit un entier en tableau d'entier
        chaine_t (int const entier);

        ~chaine_t (void);

        chaine_t & operator= (chaine_t const &obj);
        chaine_t operator+ (chaine_t const &obj) const;
        char & operator[] (int const index) const;

        friend std::ostream &operator<<(std::ostream &out, chaine_t const &obj);


        chaine_t & append (chaine_t const &obj);

};

#endif
