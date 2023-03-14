
//tests sur la class tableau20_t

#include <iostream>
#include <cassert>

#include <tableau20.hpp>


using namespace std;


int main(void) {
    tableau20_t tab1;
    for (int i = 0; i < TAILLE; i++)
    {
        assert(tab1[i] == 0);
    }

    tab1[2] = 8;
    assert(tab1[2] == 8);

    int var1 = tab1.nbNul();
    assert(var1 == TAILLE-1); //== 4

    int var2 = tab1[4];
    assert(var2 == 0);


    tableau20_t tab2;
    for (int i = 0; i < TAILLE; i++)
    {
        assert(tab2[i] == 0);
    }

    tab2 = tab1;

    for (int i = 0; i < TAILLE; i++)
    {
        assert(tab1[i] == tab2[i]);
    }


    tab1 = tab2 + tab1;
    assert(tab1[2] == 16);

    cout<<"Tous les tests ont réussis"<<endl;
    return 0;
}
