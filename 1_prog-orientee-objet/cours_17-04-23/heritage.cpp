
#include<iostream>
/*
struct A
{
	void f(){
		std::cout << "f1 ";
	}
	void f(int a){
		std::cout << "f2 ";
	}
};


struct B: public A
{
	//créer un alias
	typedef A monParent;
	//using monParent = A;

	using A::f; //réimporte toutes les fonction f de A
	void f(){ //redéclaration de f "écrase" TOUS ceux de A (si on utilise pas using A::f)
		std::cout << "f1.5 ";
	}
	void g(){
		std::cout << "g1 ";
	}
};


int main()
{
	using AutreB = B;
	B b1;
	b1.B::monParent::f();
	AutreB b;
	b.f();
	b.g();
}
*/
