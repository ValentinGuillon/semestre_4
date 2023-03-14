

#include <intreliee2.hpp>

#include <iostream>
#include <cassert>

using namespace std;



int main (void)
{
    intreliee2_t a{2};      //a=2
    assert(a.get() == 2);
    assert(a.somme() == 2);

    intreliee2_t b{5};      //a=2, b=5
    assert(b.get() == 5);
    assert(b.somme() == 7);

    intreliee2_t c = a;     //a=2, b=5, c=2
    assert(c.get() == 2);
    assert(c.somme() == 9);


    assert(a.somme() == b.somme());
    assert(b.somme() == c.somme());


    { // cout<<"{"<<endl;

        intreliee2_t d{-3};  //a=2, b=5, c=2, d=-3
        c = b;               //a=2, b=5, c=5, d=-3

        assert(c.get() == 5);
        assert(c.somme() == 9);

        assert(a.somme() == b.somme());
        assert(b.somme() == c.somme());
        assert(c.somme() == d.somme());

        a.set(-4); //a=-4, b=5, c=5, d=-3
        b.set(1);  //a=-4, b=1, c=5, d=-3
        c.set(-4); //a=-4, b=1, c=-4, d=-3

        assert(a.somme() == -10);

    } // cout<<"}"<<endl;

    //a=-4, b=1, c=-4

    assert(a.somme() == -7);


    cout<<"Tous les tests ont réussis"<<endl;
    return 0;
}
