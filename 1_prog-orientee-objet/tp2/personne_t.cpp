#include<iostream>
#include "personne_t.hpp"

using namespace std;


class personne_t {
    string nom;
    string prenom;
    int age;
    string profession;

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
            cout<<"getProfession() not defined"<<endl;
        }
        void setProfession(string newProfessions) {
            cout<<"setProfession() not defined"<<endl;
        }
        
        string affiche(void) {
			return prenom;
            //return nom + " " + prenom + ", " + to_string( age) + " ans, " + profession + "de naissance.";
        }
};


