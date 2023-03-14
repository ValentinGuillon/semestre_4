
#ifndef ACCES_H
#define ACCES_H


class acces_t
{
    int value;
    int nb_acces_since_last_modif;

    public:
        acces_t (int const a);
        acces_t & set (int const new_val);
        int get (void);
        int nbGet (void) const;
};


#endif
