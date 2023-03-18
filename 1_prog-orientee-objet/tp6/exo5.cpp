
//fonction qui fait la puissance de n'importe quel type (positif)

#include<iostream>
#include<cassert>


//retourne la puissance de "a" par "power"
template <typename T> T expon(T a, int power);


int main(void)
{
    int a = 2;
    float b = 3.1;

    int a_pow_8 = expon(a, 8);
    float b_pow_7 = expon(b, 7);

    assert(a_pow_8 == 256);

    std::cout<<"b_pow_7 = "<<b_pow_7<<std::endl;
    std::cout<<(float)(3.1*3.1*3.1)*(3.1*3.1*3.1)<<std::endl;
    // assert(b_pow_7 == (float)((3.1*3.1*3.1)*(3.1*3.1*3.1)));
    

    std::cout<<"Tests réussis."<<std::endl;
    return 0;
}



template <typename T> T expon(T a, int power)
{
    if (a <= 0)
        return 0;

    T res = a;

    //en utilisant l'exponentiation rapide (si power pair, res = (a**(power/2))**2. sinon, res = (a**(power-1/2))**2)
    for (int i = 1; i < (power - (power%2)) / 2; i++)
        res = res * a;
    
    return res * res;
}

