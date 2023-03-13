
//déclaration d'une classe décrivant un vecteur2D

#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <iostream>

using namespace std;

class vecteur2d_t {
    float x, y;

    public:
        vecteur2d_t (void);
        vecteur2d_t (float a, float b);

        friend ostream &operator<<(ostream &out, vecteur2d_t &vec);

        vecteur2d_t operator+ (vecteur2d_t vec);
        vecteur2d_t operator* (float multiplier);
        float operator|| (vecteur2d_t vec);
};


#endif

