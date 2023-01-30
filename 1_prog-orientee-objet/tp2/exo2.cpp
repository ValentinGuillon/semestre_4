#
#include<string>

using namespace std;


class personne_t {
    string nom;
    string prenom;
    int age;

    public:
        personne_t(string nom, string prenom, int age) {
            this->nom = nom;
            this->prenom = prenom;
            this->age = age;
            
        }
        
        void setAge(int age) {
            this->age = age;
        }
        
        int getAge(void) {
            return this->age;
        }
        
        string getProfession(void) {
            
        }


}



