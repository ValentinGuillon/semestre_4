//switch deux valeurs, SANS passage par référence (call func(&a, &b))

#include <iostream>

using namespace std;


void echange(int &a, int &b);


int main(void) {
    int a = 2;
    int b = 3;

    cout<<"Value: a="<<a<<", b="<<b<<endl;

    cout<<"echange(a, b); //SANS passage par référence"<<endl;
    echange(a, b);

    cout<<"Value: a="<<a<<", b="<<b<<endl;

    return 0;
}




void echange(int &a, int &b) {
    int temp = a;

    a = b;
    b = temp;
}