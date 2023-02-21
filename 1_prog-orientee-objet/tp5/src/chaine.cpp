
#include<iostream>
#include<cstdlib>
#include<chaine.hpp>


using namespace std;

chaine_t::chaine_t (const char* given_str) {
    this->size = sizeof(given_str) / sizeof(char);

    this->tab = (char*)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        this->tab[i] = given_str[i];
}


chaine_t::~chaine_t (void) {
    free(this->tab);
}


void chaine_t::print_chaine (void) {
    cout<<this->size<<endl<<"[";

    for (int i = 0; i < this->size; i++) {
        cout<<this->tab[i]<<", ";
    }
    cout<<"]";

    // for (int i = 0; i < this->size; i++) {
    //     cout<<i<<":"<<this->tab[i]<<endl;
    // }
}



