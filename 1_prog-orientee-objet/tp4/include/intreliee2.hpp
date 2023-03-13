
#ifndef INTRELIEE2_H
#define INTRELIEE2_H

class intreliee2_t
{
    int entier;
    static int somme_entier; //???

    public:
        intreliee_t2 (int value);
        ~intreliee_t2 (void);
        void set (int a);
        int get (void) const;
        int somme (void) const;


        intreliee_t2 &operator=(intreliee2_t obj);

};




#endif
