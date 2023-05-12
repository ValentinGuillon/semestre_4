
#include<iostream>
using namespace std;

struct A {
    A(A& a){ cout<< "A(A&) ";}
    A() { cout<< "A() ";}
    ~A(){ cout<< "~A() ";}
};
void f(A b){}

int main(void) {
    cout<<"\n1 ";   A a; 
    cout<<"\n2 "; A b=a;
    cout<<"\n3 ";  A* c;
    cout<<"\n4 "; A& d=a;

    cout<<"\n5 ";
    {
        cout<<"\n6 "; A* n=new A{b};
        cout<<"\n7 "; c=&d;
        cout<<"\n8 "; A m;

        cout<<"\n9 "; 
    }
    cout<<"\n10 "; A k;

    cout<<"\n11 ";
    return 0;
}
