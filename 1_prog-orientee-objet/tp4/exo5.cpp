
#include <acces.hpp>

#include <iostream>
#include <cassert>


int main (void)
{
    acces_t n{4};
    assert(n.nbGet() == 0);
    assert(n.get() == 4);
    assert(n.nbGet() == 1);
    assert(n.nbGet() == 1);
    assert(n.get() == 4);
    assert(n.nbGet() == 2);
    n.set(2);
    assert(n.nbGet() == 0);
    assert(n.get() == 2);
    assert(n.nbGet() == 1);

    acces_t const c{5};
    assert(c.nbGet() == 0);
    // assert(c.get() == 5);
    // assert(c.nbGet() == 1);
    // assert(c.nbGet() == 1);
    // assert(c.get() == 5);
    // assert(c.get() == 5);
    // assert(c.nbGet() == 3);
    // c.set(4);

    std::cout<<"Tous les tests ont réussis"<<std::endl;
    return 0;

}

