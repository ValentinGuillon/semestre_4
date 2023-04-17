/* HERITAGE */ //g++ -Wall -Wextra -g -std=c++17 heritage.cpp -o test

#include<iostream>

/*
 * dans une struct/class fille, la redéclaration d'un fonction 
 */


struct A
{
	void f(){
		std::cout << "f1\n";
	}
	void f(int a){
		std::cout << "f2\n";
	}
};


struct B: public A
{
	//créer un alias
	typedef A monParent;
	//using monParent = A;

	using A::f; //réimporte toutes les fonction f de A
	void f(){ //redéclaration de f "écrase" TOUS ceux de A (si on utilise pas using A::f)
		std::cout << "f1.5\n";
	}
	void g(){
		std::cout << "g1\n";
	}
};


int main()
{
	using AutreB = B;
	B b1;
	b1.B::monParent::f(); //ou b1.A::f();
	AutreB b;
	b.f();
	b.g();
}

