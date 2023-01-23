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

        void affichePoint(void) {
            cout << "(" << x << "," << y << ")" << endl;
        }

        void rotate(void) { // effectue une rotation de +90 d. ayant pour centre le point (0,0)
            float tmp=x;
            x=-y;
            y=tmp;
        }

        void setX(int newX) {
            x = (float)newX;
        }

        void setY(int newY) {
            y = (float)newY;
        }
   };

int main(void) {
    Point p(4,5);
    Point c(-4,1);
    c.affichePoint();
    c.rotate();
    c.affichePoint();
    c.setX(8);
    c.affichePoint();
    c.setY(15);
    c.affichePoint();
}

