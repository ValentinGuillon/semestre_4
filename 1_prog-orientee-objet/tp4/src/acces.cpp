
#include <acces.hpp>


acces_t::acces_t (int const a)
{
    this->value = a;
    this->nb_acces_since_last_modif = 0;
}



acces_t & acces_t::set (int const new_val)
{
    this->value = new_val;
    this->nb_acces_since_last_modif = 0;

    return *this;
}



int acces_t::get (void)
{
    this->nb_acces_since_last_modif += 1;
    return this->value;
}



int acces_t::nbGet (void) const
{
    return this->nb_acces_since_last_modif;
}


