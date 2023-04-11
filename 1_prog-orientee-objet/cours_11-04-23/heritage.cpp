/* héritage */
#include<iostream>

using namespace std;

//mère
class A {
	protected: //comme private, mais copié lors d'un héritage
		int a;

	public:
		//constructeur d'initialisation (ex: A obj;)
		A(){cout << "A1 ";}
		//constructeur (ex: A obj{5};)
		A(int a){cout<<"A2 ";}
		//destructeur
		~A(){cout<<"~A ";}
		//constructeur par copie (ex: A new_obj = obj;)
		A(const A& a){cout<<"copieA ";}
		//opérateur d'affectation
		A& operator=(const A& a) {
    	/*...*/
    	return *this;
    }

		void meth() {cout << "methA ";}
};


//fille
struct B : public A { //les membres 'private' de A ne sont pas dans B, mais les 'protected', si
	//constructeur (si A n'a plus de constructeur par défaut)
	B() : A(3), b(0) {cout<<"B1 ";} //comme on a déclaré une constructeur pour A, il faut le faire aussi pour B (parceque le construct par défaut)
	//destructeur
    ~B() {cout<<"~B ";}
    //constructeur par copie
    B(const B& b): A(b) {cout<<"cB ";} //ici 'b' est de type 'B', pourtant on le met dans 'A()', qui attend un objet 'A'. Mais 'B' étant enfant de 'A', il y'a une conversion implicite de 'B' vers 'A'
    //operateur d'affectaction
    B& operator=(const B& b) {
    	this->A::operator=(b); //appel de l'opérateur d'affectation de 'A'
    	/*...*/
    	return *this;
    }

	int b;
	void meth() { //ça n'est pas une surcharge, mais une redéfinition (prend l'ascendant sur A::meth())
		cout << "methB ";
	}
	void nm(){
		cout << "nmB ";
	}
	void m2() {
		//this->a = 4;
	}
};




/*
int main() {
	B obj;
	obj.meth();
	obj.A::meth();
	obj.nm();
	//obj.A::nm(); //error: ‘struct A’ has no member named ‘nm’

	//obj.a=8; //error: ‘int A::a’ is protected within this context
	obj.b=5;
	cout << obj.b << endl;

	cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(int) << endl;
}*/


int main() {
	B b1;
	A* ptr=&b1; //conversion implicite de Fille vers MÈRE (! l'inverse est impossible)
	cout<<"mess"<<endl;
	B b2{b1};
	cout<<"fin"<<endl;
}
