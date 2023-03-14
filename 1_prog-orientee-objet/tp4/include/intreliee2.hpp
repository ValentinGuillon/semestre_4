
#ifndef INTRELIEE2_H
#define INTRELIEE2_H

#include <iostream>

class intreliee2_t
{
    int entier;
    static int somme_entier;

    public:
        intreliee2_t (int value);
        ~intreliee2_t (void);
        void set (int a);
        int get (void) const;
        int somme (void) const;

        friend std::ostream &operator<<(std::ostream &out, intreliee2_t &obj);

        intreliee2_t (const intreliee2_t &obj);
        intreliee2_t &operator=(const intreliee2_t &obj);

};




#endif
