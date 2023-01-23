#include<iostream>

using namespace std;

struct Point {
    private :
        float x;
        float y;
    public:
        Point(float px,float py) {
            x=px;
            y=py;
        }

        void affichePoint() {
            cout << "(" << x << "," << y << ")" << endl;
        }

        void rotate() { // effectue une rotation de +90 d. ayant pour centre le point (0,0)
            float tmp=x;
            x=-y;
            y=tmp;
        }

        void translate(Point a) {
            x += a.x;
            y += a.y;
        }
};

int main() {
    Point p(4,5);
    Point c(-4,1);
    c.affichePoint();
    c.rotate();
    c.affichePoint();
    c.translate(p);
    c.affichePoint();
}

