#include<iostream>
#include "point2.hpp"


using namespace std;


point2_t::point2_t(float px,float py) {
    x=px;
    y=py;
    cout << "Le point [" << this << "] est construit" << endl;
}
        
point2_t::~point2_t(void) {
    cout << "Le point [" << this << "] est détruit" << endl;
}

void point2_t::affichePoint() {
    cout << "(" << x << "," << y << ")" << endl;
}

void point2_t::rotate() { // effectue une rotation de +90 d. ayant pour centre le point (0,0)
    float tmp=x;
    x=-y;
    y=tmp;
}



