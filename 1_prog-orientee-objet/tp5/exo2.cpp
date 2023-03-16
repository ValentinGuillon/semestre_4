
#include<iostream>
#include<chaine.hpp>

using namespace std;

int main(void) {
    chaine_t a;
    cout<<"chaine_t a;"<<endl;
    cout<<"    //a = "<<a<<endl;

    chaine_t b{"Bonjour"};
    cout<<"chaine_t b{\"Bonjour\"};"<<endl;
    cout<<"    //b = "<<b<<endl;

    chaine_t const c = "Salut";
    cout<<"chaine_t const c = \"Salut\";"<<endl;
    cout<<"    //c = "<<c<<endl;

    chaine_t m("Ave");
    cout<<"chaine_t m(\"Ave\");"<<endl;
    cout<<"    //m = "<<m<<endl;

    chaine_t n(45);
    cout<<"chaine_t n(45);"<<endl;
    cout<<"    //n = "<<n<<endl;

    chaine_t* d = new chaine_t{"Au revoir"};
    cout<<"chaine_t* d = new chaine_t{\"Au revoir\"};"<<endl;
    cout<<"    //*d = "<<*d<<endl;

    a.append(b);
    cout<<"a.append(b);"<<endl;
    cout<<"    //a = "<<a<<endl;
    cout<<"    //b = "<<b<<endl;

    a = b+c;
    cout<<"a = b+c;"<<endl;
    cout<<"    //a = "<<a<<endl;
    cout<<"    //b = "<<b<<endl;
    cout<<"    //c = "<<c<<endl;

    // b[4] = 'u';
    // // c[3] = 'u'; //error, c est const
    // char u = c[3];
    // // c.append(a) //error, c est const
    // //b[55] = 'u' //out of range

    cout<<"Fin du programme"<<endl;
    return 0;
}
