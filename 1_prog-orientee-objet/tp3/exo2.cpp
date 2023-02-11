
#include<iostream>


using namespace std;


class CompteInstance {
    public:
        static int nb_instance;

        CompteInstance(void) {
            nb_instance++;
        }

        ~CompteInstance() {
            nb_instance--;
        }


        static int compter(void) {
            // cout<<nb_instance;

            return nb_instance;
        }
};




int CompteInstance::nb_instance = 0;


int main(void) {

    CompteInstance a;
    {
        CompteInstance b;
        CompteInstance c;
        CompteInstance d;
        cout<<CompteInstance::compter()<<endl;
    }
    cout<<CompteInstance::compter()<<endl;

    return 0;
}

// exemple fonctionnel d'internet
// #include <iostream>
// using namespace std;

// class Voiture  {
//     private:
//         int Id;
//         double Vitesse;

//     public:
//         static int nbVoitures;
//         Voiture();
//         static int getNombreObjets();
// };

// int Voiture::nbVoitures = 0;
// int Voiture::getNombreObjets() {
//     return nbVoitures;
// }

// Voiture::Voiture() {
//     Id = 1;
//     Vitesse = 240;
//     nbVoitures += 1;
// }

// int main() {
//     Voiture v1, v2, v3, v4;
//     cout << "Nombre d'objets : " << Voiture::getNombreObjets() << endl;
//     return 0;
// }