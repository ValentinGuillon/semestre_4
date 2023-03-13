
//tests sur la class vecteur20_t

#include<vecteur2d.hpp>
#include<iostream>

using namespace std;



int main(void) {
    cout<<"==== TEST DE class vecteur2d_t ====\n"<<endl;
    //initialisation
    vecteur2d_t a{-1.2, 2.1};
    vecteur2d_t b{1.1, 4.8};
    float x = 2;

    //calculs
    vecteur2d_t somme_ab = a+b;
    vecteur2d_t produit_ax = a*x;
    float scalaire_ab = a||b;


    //affichage
    cout<<"a = "<<endl<<"    "<<a<<endl;
    cout<<"b = "<<endl<<"    "<<b<<endl;
    cout<<"x = "<<endl<<"    "<<x<<endl<<endl;

    cout<<"a+b ="<<endl<<"    "<<somme_ab<<endl;
    cout<<"a*x ="<<endl<<"    "<<produit_ax<<endl;
    cout<<"a||x ="<<endl<<"    "<<scalaire_ab<<endl;

    return 0;
}

