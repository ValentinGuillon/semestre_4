/* héritage */
#include<iostream>

using namespace std;

class A {
	protected: //private, mais copié lors d'un héritage
		int a;

	public:
		A(){cout << "A1 ";}
		A(int a){cout<<<"A2 ";}
		~A(){cout<<"~A ";}
		A(const A& a){cout<<"cA ";}

		void meth() {
			cout << "methA ";
		}

};



struct B : public A { //les membres "private" de A ne sont pas dans B
	B() : A(3), b(0) {cout<<"B1 ";} //comme on a déclaré une constructeur pour A, il faut le faire aussi pour B (parceque le construct par défaut)
    // il n'est pas toujours necessaire de le faire avec le destructeur
    ~B() {cout<<"~B ";}
    //copy
    B(const B& b): A(b) {cout<<"cB ";}
    //operateur d'affectaction
    B& operator=(const B& b) {
    	this->A::operator=(b);
    	/*...*/
    	return *this;
    }

	int b;
	void meth() { //ça n'est pas une surcharge, mais une redéfinition (prend l'acscendant sur A::math())
		cout << "methB ";
	}
	void nm(){
		cout << "nmB ";
	}
	void m2() {
		//this->a = 4;
	}
};





int main() {
/*
	B obj;
	obj.meth();
	obj.A::meth();
	obj.nm();
	//obj.A::nm(); //error: ‘struct A’ has no member named ‘nm’


	//obj.a=3;
	obj.b=5;

	cout << obj.a << " " << obj.b << endl;

	cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(int) << endl;
 */

	B b1;
	A* ptr=&obj1; //conversion implicite de Fille vers MÈRE (! l'inverse est impossible)
	cout<<"mess"<<endl;
	B b2{b1};
	cout<<"fin"<<endl;
}