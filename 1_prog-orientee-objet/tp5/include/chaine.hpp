
#ifndef CHAINE_H
#define CHAINE_H

#include <iostream>

class chaine_t {
    int max_size;
    int actual_size;
    char tab[100];

    public:
        chaine_t (chaine_t &obj);
        chaine_t (void);
        chaine_t (char const* str);
        chaine_t (int entier);

        ~chaine_t (void);

        chaine_t operator= (chaine_t const &obj);
        chaine_t operator+ (chaine_t const &obj) const;
        char & operator[] (int const index);

        friend std::ostream &operator<<(std::ostream &out, chaine_t const &obj);
        void print_chaine (void);


        chaine_t append (chaine_t const &obj);

};

#endif
