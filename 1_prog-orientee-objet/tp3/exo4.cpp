

#include <iostream>

using namespace std;



class intreliee_t
{
    int entier;
    static int somme_entier; //???

    public:
        intreliee_t (int value);
        ~intreliee_t (void);
        void set (int a);
        int get (void) const;
        int somme (void) const;
    
};

int intreliee_t::somme_entier = 0;



int main (void)
{
    intreliee_t a{2}, b{5};

    cout<<"a = "<<a.get()<<endl;
    cout<<"b = "<<b.get()<<endl;
    { cout<<"{"<<endl;

    intreliee_t c{3};

    cout<<"    c = "<<c.get()<<endl;
    cout<<"    somme (from a) = "<<a.somme()<<endl;
    cout<<"    somme (from b) = "<<b.somme()<<endl;
    cout<<"    somme (from c) = "<<c.somme()<<endl;



    cout<<"    set() de tous les \"intreliee\":"<<endl;
    a.set(-4);
    b.set(1);
    c.set(-4);


    } cout<<"}"<<endl;

    cout<<"a = "<<a.get()<<endl;
    cout<<"b = "<<b.get()<<endl;
    //cout<<"c = "<<c.get()<<endl;
    cout<<"somme (from a) = "<<a.somme()<<endl;
    cout<<"somme (from b) = "<<b.somme()<<endl;
    //cout<<"somme (from c) = "<<c.somme()<<endl;

    return 0;
}





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

