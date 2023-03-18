
//fonction qui tri un tableau d'objet comparable

#include <iostream>
#include <cassert>

using namespace std;

//tri à bulle (non optimisé)
template <typename T> void triGeneral(int size, T* tab);

//échange deux valeur
template <typename T> void swap(T* a, T* b);

//compare un à un les éléments de deux tableaux de type comparable. Return 0 si les valeurs au même indice ne sont pas égaux. Sinon 1
template <typename T> int areSame(int size, T* tab_a, T* tab_b);



// template <typename T> void afficher(int size, T* tab);






int main (void)
{
    int a[] = {2, 4, 6, 8, 2};
    int a_sorted[] = {2, 2, 4, 6, 8};
    float b[] = {7.2, 1.2, 8.1, 4.8, 3.6};
    float b_sorted[] = {1.2, 3.6, 4.8, 7.2, 8.1};

    assert(!areSame(5, a, a_sorted));
    assert(!areSame(5, b, b_sorted));

    // cout<<"a = "; afficher(5, a);
    // cout<<"a = "; afficher(5, a_sorted);
    // cout<<"b = "; afficher(5, b);
    // cout<<"b = "; afficher(5, b_sorted);

    triGeneral(5, a);
    triGeneral(5, b);

    // cout<<"a = "; afficher(5, a);
    // cout<<"a = "; afficher(5, a_sorted);
    // cout<<"b = "; afficher(5, b);
    // cout<<"b = "; afficher(5, b_sorted);

    assert(areSame(5, a, a_sorted));
    assert(areSame(5, b, b_sorted));


    cout<<"Tests réussis."<<endl;
    return 0;
}



template <typename T> void triGeneral(int size, T* tab)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (tab[j] > tab[j+1])
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



template <typename T> int areSame(int size, T* tab_a, T* tab_b)
{
    for (int i = 0; i < size; i++)
    {
        if (tab_a[i] != tab_b[i])
            return 0;
    }

    return 1;
}



// template <typename T> void afficher(int size, T* tab)
// {
//     cout<<"[";
//     for (int i = 0; i < size-1; i++)
//         cout<<tab[i]<<", ";
//     cout<<tab[size-1]<<"]"<<endl;
// }
