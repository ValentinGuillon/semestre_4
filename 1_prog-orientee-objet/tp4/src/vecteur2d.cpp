
//définition d'une classe décrivant un vecteur2D
//définition des opérateurs: +, *, || 

#include<vecteur2d.hpp>
#include<iostream>

using namespace std;


vecteur2d_t::vecteur2d_t (void) {
    this->x = 0;
    this->y = 0;
}

vecteur2d_t::vecteur2d_t (float a, float b) {
    this->x = a;
    this->y = b;
}






vecteur2d_t vecteur2d_t::operator+ (vecteur2d_t vec) {
    // float new_x, new_y;

    // new_x = this->x + vec.x;
    // new_y = this->y + vec.y;

    // vecteur2d_t somme{new_x, new_y};

    vecteur2d_t somme {this->x + vec.x, this->y + vec.y};
    return somme;
}


vecteur2d_t vecteur2d_t::operator* (float multiplier) {
    // float new_x, new_y;

    // new_x = this->x * multiplier;
    // new_y = this->y * multiplier;

    // vecteur2d_t produit{new_x, new_y};

    vecteur2d_t produit{this->x * multiplier, this->y * multiplier};
    return produit;
}

//produit scalaire de deux vecteur2d
float vecteur2d_t::operator|| (vecteur2d_t vec) {
    // float prod_x, prod_y;
    // float scalaire;

    // prod_x = this->x * vec.x;
    // prod_y = this->y * vec.y;
    // scalaire = prod_x + prod_y;

    float scalaire = (this->x * vec.x) + (this->y * vec.y);

    return scalaire;
}

