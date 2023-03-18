
//fonction qui renvoie le minimum entre deux références de type comparable

#include<iostream>
#include<cassert>


template <typename T> T min(T const& a, T const& b);



int main(void)
{
    int i_a = 4, i_b = 8;
    float f_a = 2.2, f_b = 2.1;

    int i_min = min(i_a, i_b);
    float f_min = min(f_a, f_b);

    assert(i_min == 4);
    assert(f_min == (float)2.1);


    std::cout<<"Tests réussis."<<std::endl;
    std::cout<<"(J'ai pas compris l'intéret de cet exo, sachant que l'exo1 était plus compliqué)"<<std::endl;
    return 0;
}


template <typename T> T min(T const& a, T const& b)
{
    if (a < b)
        return a;
    
    return b;
}



