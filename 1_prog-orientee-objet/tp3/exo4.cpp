

#include <iostream>

using namespace std;



class intreliee_t
{
    int entier;
    int somme_entier; //???

    public:
        intreliee_t (int value);
        void set (int a);
        int get (void) const;
        int somme (void) const;
    
};




int main (void)
{
    intreliee_t a{2}, b{5}, c{3};

    cout<<"a = "<<a.get()<<endl;
    cout<<"b = "<<b.get()<<endl;
    cout<<"c = "<<c.get()<<endl;
    cout<<"somme (from a) = "<<a.somme()<<endl;
    cout<<"somme (from b) = "<<b.somme()<<endl;
    cout<<"somme (from c) = "<<c.somme()<<endl;


    cout<<"set() de tous les \"intreliee\":"<<endl;
    a.set(8);
    b.set(2);
    c.set(-4);

    cout<<"a = "<<a.get()<<endl;
    cout<<"b = "<<b.get()<<endl;
    cout<<"c = "<<c.get()<<endl;
    cout<<"somme (from a) = "<<a.somme()<<endl;
    cout<<"somme (from b) = "<<b.somme()<<endl;
    cout<<"somme (from c) = "<<c.somme()<<endl;


    return 0;
}





intreliee_t::intreliee_t (int value)
{
    this->entier = value;

    static int a = 0;
    a += value;
    this->somme_entier = a;
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

