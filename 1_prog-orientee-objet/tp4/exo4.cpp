

#include <intreliee2_t.hpp>
#include <iostream>


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


