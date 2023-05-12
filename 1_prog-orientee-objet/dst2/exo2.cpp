#include<iostream>
using namespace std;

class my_quad_t {
    const int a;
    const int b;
    const int c;
    const int d;

    public:

    my_quad_t(const int w, const int x, const int y, const int z) 
        : a(w), b(x), c(y), d(z) {}

    my_quad_t(const my_quad_t &obj) 
        : a(obj.a), b(obj.b), c(obj.c), d(obj.d) {}

    my_quad_t operator<<(const int nb_decal) const {
        int w = this->a;
        int x = this->b;
        int y = this->c;
        int z = this->d;

        for (int i = 0; i < nb_decal; i++) {
            int temp = w;
            w = x; x = y; y = z; z = temp;
        }

        return {w, x, y, z};
    }

    void print(const char *var_name, const int size) const {
        for (int i = 0; i < size; i++) {
            cout<< var_name[i];
        }

        cout<< " : {"<<this->a<<","<<this->b<<","<<this->c<<","<<this->d<<"}";
    }


};


int main(void) {
    const my_quad_t a{1, 2, 3, 4};
    a.print("a", 1); cout<<endl;
    const my_quad_t b = a<<1;
    b.print("b", 1); cout<<endl;
    const my_quad_t c = a<<2;
    c.print("c", 1); cout<<endl;
    const my_quad_t d = a<<4;
    d.print("d", 1); cout<<endl;
}
