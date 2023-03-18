
//fonction qui fait la somme d'un tableau de n'importe quelle type sommable

#include <iostream>
#include <cassert>

template <typename T> T somme(int size, T* tab);


int main(void)
{
    int a[] = {2, 5, 7, -4, 8};
    float b[] = {1.2, 5.1, -1.2, 0.2, 4.1};

    int somme_a = somme(5, a);
    float somme_b = somme(5, b);

    assert(somme_a == 18);
    assert(somme_b == (float)(9.4)); //si on ne met pas float ici, ça n'est pas égale


    std::cout<<"Tests réussis."<<std::endl;
    return 0;
}



template <typename T> T somme(int size, T* tab)
{
    if (size == 0)
        return T{0};

    T res = tab[0];

    for (int i = 1; i < size; i++)
        res = res + tab[i];
    
    return res;
}
