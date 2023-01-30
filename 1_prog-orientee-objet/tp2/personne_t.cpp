#include<iostream>
#include "personne_t.hpp"

using namespace std;



personne_t::personne_t(string nom, string prenom, int age) {
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->profession = "Sans emploi";
}
        
void personne_t::setAge(int age) {
    this->age = age;
}
        
int personne_t::getAge(void) {
    return this->age;
}
        
string personne_t::getProfession(void) {
    return profession;
}
void personne_t::setProfession(string newProfessions) {
    profession = newProfessions;
}

string personne_t::affiche(void) {
    return nom + " " + prenom + ", " + to_string(age) + " ans, " + profession + " de naissance.";
}

