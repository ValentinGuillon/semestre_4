
#include <intreliee2_t.hpp>

#include <iostream>

using namespace std;



int intreliee_t::somme_entier = 0;



intreliee2_t intreliee_t::operator=(const intreliee2_t & obj)
{
	obj

	return obj;
}

ostream & oper

intreliee2_t a = b;

a = b;


intreliee_t::intreliee_t (int value)
{
    this->entier = value;

    this->somme_entier += value;
}


intreliee_t::~intreliee_t ()
{
    this->somme_entier -= this->entier;
}


void intreliee_t::set (int a)
{
    this->somme_entier -= this->entier;
    this->entier = a;
    this->somme_entier += this->entier;
}


int intreliee_t::get (void) const
{
    return entier;
}


int intreliee_t::somme (void) const
{
    return this->somme_entier;
}




