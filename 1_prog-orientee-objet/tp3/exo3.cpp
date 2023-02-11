
#include<iostream>


using namespace std;


class alea_t {
    int graine;
    int nb_random;
    int increment;
    int repetition; //permet de reset la suite elle est bloquée sur le même nombre

    public:
        // static int nb_random;


        alea_t(int graine) {
            this->graine = graine;
            this->nb_random = 0;
            this->increment = 0;
            this->repetition = 0;
        }


        int rand() {
            //si rand() à générer 2 fois de suite le même nombre, on reset le nombre
            if (repetition) {
                repetition = 0;
                nb_random = 0;

            }

            //ajoute "increment" si le random == 0
            if (!nb_random) {
                nb_random+= increment;
                increment++;
            }

            //génération du nombre aléatoire
            int temp = ((nb_random * 1103515245) + 12345) % (graine+1);

            if (temp == nb_random)
                repetition++;
            
            nb_random = temp;

            //retourne l'absolu de nb_random
            if (nb_random < 0) return -1 * nb_random;
            return nb_random;
        }


};



int main(void) {
    int graine = 56;

    alea_t genA{graine};
    alea_t genB{12};

    int a = genA.rand();
    int b = genB.rand();

    cout<<"a = "<<a<<", b = "<<b<<endl;

    for (int i = 0; i < 100; i++) {
        a = genA.rand();
        b = genB.rand();
        cout<<"a = "<<a<<"\tb = "<<b<<endl;
    }

    return 0;
}

