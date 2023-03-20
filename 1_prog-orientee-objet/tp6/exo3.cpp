
//définition d'une class qui prends deux variables de type SIMPLE différent

#include <iostream>
#include <cassert>

using namespace std;


//fonctions des exos 1 et 2
template <typename T> T somme(int size, T* tab);
template <typename T> void triGeneral(int size, T* tab);
template <typename T> void swap(T* a, T* b);

//classe de deux type sommable (T+T et H+H) et comparable (T<T et H<H)
template <class T, class H>
class couple_t
{
    T t_type;
    H h_type;

    public:
        //constructeur en donnant les deux types
        couple_t(T a, H b)
        {
            this->t_type = a;
            this->h_type = b;
        }

        //constructeur par copie
        couple_t(couple_t const& cpl_b)
        {
            this->t_type = cpl_b.t_type;
            this->h_type = cpl_b.h_type;
        }


        friend ostream &operator<<(ostream &out, couple_t cpl)
        {
            out<<"{"<<cpl.t_type<<", "<<cpl.h_type<<"}";
            return out;
        }




        //retourne la variable de type T
        T get_first(void) const
        {
            return this->t_type;
        }

        //retourne la variable de type H
        H get_second (void) const
        {
            return this->h_type;
        }


        //opérateur d'affectation
        couple_t &operator=(couple_t const& cpl_b)
        {
            this->t_type = cpl_b.t_type;
            this->h_type = cpl_b.h_type;
            return *this;
        }


        //retourne un nouvel objet, dont chaque vars est la somme des var respective de "this" et "couple_b" (ex: (a, b) + (c, d) = (a+c, b+d))
        couple_t operator+(couple_t const& cpl_b) const
        {
            couple_t<T, H> res{0, 0};
            res.t_type = this->t_type + cpl_b.t_type;
            res.h_type = this->h_type + cpl_b.h_type;
            return res;
        }

        //retourne 1 si, pour (a, b) < (c, d), soit a < c, soit a = c et b < d. Sinon 0
        int operator<(couple_t const& cpl_b)
        {
            //a < c
            if (this->t_type < cpl_b.t_type)
                return 1;

            //! a = c
            if (cpl_b.t_type < this->t_type)
                return 0;

            //a = c et b < d
            if (this->h_type < cpl_b.h_type)
                return 1;

            return 0;
        }
};







int main(void)
{
    //==================
    //tests DÉCLARATION
    //==================

    couple_t<int, float> i_f_A{2, 5.5};
    
    assert(i_f_A.get_first() == 2);
    assert(i_f_A.get_second() == (float)5.5);



    //===============
    //tests ADDITION
    //===============

    couple_t<int, float> i_f_B{4, 1.2};
    couple_t<int, float> i_f_C = i_f_A + i_f_B;

    assert(i_f_C.get_first() == 6);
    assert(i_f_C.get_second() == (float)6.7);



    //======================
    //tests COMPARAISON (<)
    //======================

    couple_t<int, float> i_f_D{4, 1.3};
    couple_t<int, float> i_f_E{4, 1.1};

    assert((i_f_A < i_f_B) == 1);
    assert((i_f_B < i_f_D) == 1);
    assert((i_f_B < i_f_E) == 0);



    //============
    //tests SOMME
    //============

    couple_t<int, float> tab[] = {i_f_A, i_f_B, i_f_C, i_f_D, i_f_E};
    couple_t<int, float> i_f_somme = somme(5, tab);

    assert(i_f_somme.get_first() == 20);
    assert(i_f_somme.get_second() == (float)15.8);



    //=========
    //test TRI
    //=========

    /*(2, 5.5)*/ assert((tab[0].get_first() == 2) && (tab[0].get_second() == (float)5.5));
    /*(4, 1.2)*/ assert((tab[1].get_first() == 4) && (tab[1].get_second() == (float)1.2));
    /*(6, 6.7)*/ assert((tab[2].get_first() == 6) && (tab[2].get_second() == (float)6.7));
    /*(4, 1.3)*/ assert((tab[3].get_first() == 4) && (tab[3].get_second() == (float)1.3));
    /*(4, 1.1)*/ assert((tab[4].get_first() == 4) && (tab[4].get_second() == (float)1.1));

    triGeneral(5, tab);

    /*(2, 5.5)*/ assert((tab[0].get_first() == 2) && (tab[0].get_second() == (float)5.5));
    /*(4, 1.1)*/ assert((tab[1].get_first() == 4) && (tab[1].get_second() == (float)1.1));
    /*(4, 1.2)*/ assert((tab[2].get_first() == 4) && (tab[2].get_second() == (float)1.2));
    /*(4, 1.3)*/ assert((tab[3].get_first() == 4) && (tab[3].get_second() == (float)1.3));
    /*(6, 6.7)*/ assert((tab[4].get_first() == 6) && (tab[4].get_second() == (float)6.7));


    cout<<"Tests réussis."<<endl;
    return 0;
}










//fonctions des exos 1 et 2
template <typename T> T somme(int size, T* tab)
{
    // if (size == 0)
    //     return T{0};

    T res = tab[0];

    for (int i = 1; i < size; i++)
        res = res + tab[i];
    
    return res;
}

template <typename T> void triGeneral(int size, T* tab)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (tab[j+1] < tab[j])
                swap(&tab[j], &tab[j+1]);
        }
    }
}

template <typename T> void swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}


//JE NE SAIS PAS COMMENT FAIRE LA DÉCLARATION/DÉFINITION d'une template class avec plusieurs arguments

// //constructeur en donnant les deux types
// template <class T, class H>
// couple_t<T, H>::couple_t(T a, H b)
// {
//     this->t_type = a;
//     this->h_type = b;
// }

// //constructeur par copie
// couple_t(couple_t const& cpl_b)
// {
//     this->t_type = cpl_b.t_type;
//     this->h_type = cpl_b.h_type;
// }


// //retourne la variable de type T
// T get_first(void) const
// {
//     return this->t_type;
// }

// //retourne la variable de type H
// H get_second (void) const
// {
//     return this->h_type;
// }

// //opérateur d'affectation
// couple_t &operator=(couple_t const& cpl_b);

// //retourne un nouvel objet, dont chaque vars est la somme des var respective de "this" et "couple_b" (ex: (a, b) + (c, d) = (a+c, b+d))
// couple_t operator+(couple_t const& cpl_b) const
// {
//     couple_t res;
//     res.t_type = this->t_type + cpl_b.t_type;
//     res.h_type = this->h_type + cpl_b.h_type;
//     return res;
// }

// //retourne 1 si, pour (a, b) < (c, d), soit a < c, soit a = c et b < d. Sinon 0
// int operator<(couple_t const& cpl_b)
// {
//     //a < c
//     if (this->t_type < cpl_b.t_type)
//         return 1;

//     //! a = c
//     if (cpl_b.t_type < this->t_type)
//         return 0;

//     //a = c et b < d
//     if (this->h_type < cpl_b.h_type)
//         return 1;

//     return 0;
// }