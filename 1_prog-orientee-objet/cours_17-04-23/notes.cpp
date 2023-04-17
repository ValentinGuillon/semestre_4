//g++ -Wall -Wextra -g -std=c++17 notes.cpp -o test
//-fsanitize=address

#include<iostream>

struct A
{
	A() {std::cout << "construction de  A " << this << std::endl;}

	//à noter, pour toutes fonctions allouant de la mémoire, il est recommandé de les déclarer "virtual"

	//void f(){
	virtual void f(){ //le choix de la méthode se fait à l'execution (et non à la compilation)
		std::cout << "f1 sur " << this << std::endl;
	}
};


struct B: public A
{
	int b;
	B() {std::cout << "construction de  B " << this << std::endl;}
	void f(){ //est virtual, car celle du parent est virtual
	//int f(){ //on ne peut changer le type de retour, car A::f() est virtual
		std::cout << "f1.5 sur " << this << std::endl;
	}

	void g(){
		std::cout << "g1 ";
	}
};






/*
int main()
{
	B b1;
	A a1;
	A* pa=&b1;
	b1.f();
	pa->f();
	pa=&a1;
	pa->f();
}
*/


int main() {
	B b1;
	A& ra = b1;
	ra.f();

}