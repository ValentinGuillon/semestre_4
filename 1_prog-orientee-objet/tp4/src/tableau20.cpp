
//définition de la class tableau20_t

#include <iostream>

#include <tableau20.hpp>



tableau20_t::tableau20_t (void) {
    for (int i = 0; i < TAILLE; i++)
        tab[i] = 0;
}


std::ostream &operator<<(std::ostream &out, const tableau20_t &obj) {
    out<<"[";

    for (int i = 0; i < TAILLE -1; i++)
        out<<obj.tab[i]<<", ";

    return out<<obj.tab[TAILLE]<<"]";
}


//retourne le nombre de case vide (== 0)
int tableau20_t::nbNul(void) const {
    int empty_cases = 0;
    for (int i = 0; i < TAILLE; i++) {
        if (this->tab[i] == 0)
            empty_cases ++;
    }

    return empty_cases;
}


//définition de l'opérateur [] (call ex: tab[5])
int & tableau20_t::operator[] (int index) {
    if (index < -TAILLE or index > TAILLE) {
        std::cout<<"ERROR: index out of range"<<std::endl;
        // throw 1;
        exit(1);
    }

    if (index < 0)
        index += TAILLE;

    return this->tab[index];
}

/*
tableau20_t & tableau20_t::operator= (const tableau20_t &other_tab) {
    for (int i = 0; i < TAILLE; i++)
        this->tab[i] = other_tab.tab[i];

    return *this;
}*/


//somme des var des deux tableaux
tableau20_t tableau20_t::operator+ (const tableau20_t &other_tab) const {
    tableau20_t somme;

    for (int i = 0; i < TAILLE; i++)
        somme[i] = other_tab.tab[i] + this->tab[i];

    return somme;
}


