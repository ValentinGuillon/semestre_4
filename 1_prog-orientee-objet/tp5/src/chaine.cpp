
#include <chaine.hpp>
#include <iostream>
#include <stdlib.h>



//copie les "size" premiers char de str
void chaine_t::copy(char* ret, char* const str, int size, int index_start = 0, int print = 0) const
{
    //on verifie si la taille de "str" est plus petit que "size"
    int str_size = 0;
    for (int i = 0; str[i] != '\0'; i++)
        str_size++;

    if (str_size < size)
        size = str_size;

    //on copie "str" dans "ret"
    // char* ret = (char*) malloc(sizeof(char) * size);

    for (int i = index_start; i < size; i++) {
        ret[i] = str[i - index_start];
        if (print)
            std::cout<<"ret["<<i<<"] = "<<ret[i]<<std::endl;
    }
}




//constructeur de déclaration
chaine_t::chaine_t (void)
{
    this->size = 0;
    this->tab = NULL;
}



//constructeur par copie
chaine_t::chaine_t (chaine_t const &obj)
{
    this->size = obj.size;
    this->tab = (char*)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        this->tab[i] = obj.tab[i];
}



//constructeur avec un tableau de char
chaine_t::chaine_t (char* const str)
{
    //calcule de la taille du tableau donné
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
        size++;

    this->size = size;

    this->tab = (char*)malloc(sizeof(char) * size);

    copy(this->tab, str, this->size);
}



//constructeur qui convertit un entier en tableau d'entier
chaine_t::chaine_t (int const entier)
{
    int nb_digits = 0;
    int entier_copy = entier;

    //on compte le nombre de chiffres dans le nombre
    while (entier_copy > 10)
    {
        nb_digits++;
        entier_copy = (int)(entier_copy/10);
    }
    nb_digits++;

    //on alloue de la mémoire pour le tableau
    this->size = nb_digits;
    this->tab = (char*) malloc(sizeof(char) * this->size);

    entier_copy = entier;

    //on remplit le tableau en partant de la fin
    for (int i = nb_digits-1; i >= 0; i--)
    {
        int digit = entier_copy % 10;
        this->tab[i] = (char)(digit + 48);
        entier_copy = (int)(entier_copy/10);
    }
}



chaine_t::~chaine_t (void)
{
    free(this->tab);
}



chaine_t & chaine_t::operator= (chaine_t const &obj)
{
    //on vide this->tab
    free(this->tab);

    //mis à jour des membres de this
    this->size = obj.size;
    this->tab = (char*) realloc(this->tab, sizeof(char) * this->size);

    //remplissage de this->tab avec obj.tab
    copy(this->tab, obj.tab, this->size);

    return *this;
}



chaine_t chaine_t::operator+ (chaine_t const &obj) const
{
    chaine_t result;

    result.size = this->size + obj.size;
    result.tab = (char*) malloc(sizeof(char) * result.size);

    //on met la chaine de this dans result
    copy(result.tab, this->tab, result.size, 0, 1);
    
    //on met la chaine de obj dans result (à la suite de celle de this)
    copy(result.tab, obj.tab, result.size, this->size, 1);

    return result;
}



char & chaine_t::operator[] (int const index) const
{
    //out of range
    if (index >= this->size || index < 0)
        throw 1;

    return this->tab[index];
}



std::ostream &operator<< (std::ostream &out, chaine_t const &obj)
{
    for (int i = 0; i < obj.size; i++)
        out<<obj.tab[i];
    return out;
}



chaine_t & chaine_t::append (chaine_t const &obj)
{
    int previous_size = this->size;

    this->size += obj.size;
    this->tab = (char*) realloc(this->tab, sizeof(char) * this->size);

    copy(this->tab, obj.tab, this->size, previous_size);
    
    return *this;
}
