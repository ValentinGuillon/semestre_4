
//tests sur la class tableau20_t

#include <iostream>

#include <tableau20.hpp>


using namespace std;


int main(void) {
    tableau20_t tab1;
    cout<<"tableau20_t tab1;\n  //tab1 = "<<tab1<<endl;

    tab1[2] = 2;
    cout<<"tab1[2] = 2;\n  //tab1 = "<<tab1<<endl;

    int var1 = tab1.nbNul();
    cout<<"int var1 = tab1.nbNul();\n  //var1 = "<<var1<<endl;

    int var2 = tab1[4];
    cout<<"int var2 = tab1[4];\n  //var2 = "<<var2<<endl;


    tableau20_t tab2;
    cout<<"tableau20_t tab2;\n  //tab2 = "<<tab2<<endl;

    tab2 = tab1;
    cout<<"tab2 = tab1;\n  //tab2 = "<<tab2<<endl;

    tab1 = tab2 + tab1;
    cout<<"tab1 = tab2 + tab1;\n  //tab1 = "<<tab1<<endl;

    return 0;
}
