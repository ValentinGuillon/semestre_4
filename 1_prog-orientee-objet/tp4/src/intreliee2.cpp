
#include <intreliee2.hpp>
#include <iostream>


int intreliee2_t::somme_entier = 0;



intreliee2_t::intreliee2_t (int value)
{
    this->entier = value;

    this->somme_entier += value;
}



intreliee2_t::intreliee2_t (const intreliee2_t &obj)
{
    this->entier = obj.entier;
    this->somme_entier += this->entier;
}



intreliee2_t::~intreliee2_t ()
{
    this->somme_entier -= this->entier;
}



std::ostream &operator<<(std::ostream &out, intreliee2_t &obj) {
    return out<<"[entier="<<obj.entier<<", somme="<<obj.somme_entier<<"]";
}



intreliee2_t & intreliee2_t::operator=(const intreliee2_t &obj)
{
    //en retire la valeur de this de la somme total
	this->somme_entier -= this->entier;
    this->entier = obj.entier;

    //en change l'entier this par avec celui de obj
    //on ajoute ce nouveau entier à la somme total
    this->somme_entier += this->entier;

	return *this;
}



void intreliee2_t::set (int a)
{
    this->somme_entier -= this->entier;
    this->entier = a;
    this->somme_entier += this->entier;
}


int intreliee2_t::get (void) const
{
    return entier;
}


int intreliee2_t::somme (void) const
{
    return this->somme_entier;
}




