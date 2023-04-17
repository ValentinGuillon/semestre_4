
//g++ -Wall -Wextra -g -std=c++17 notes4.cpp -o test


#include<iostream>
#include<vector>
/* throw, catch, try */


/*
int f() {
	throw 1; //la suite du programme sera ignorée, jusqu'au un catch correspondant
	std::cerr << "message2\n";
}

int dev(int a, int b) {
	if (b == 0)
		throw 1;
	return a/b;
}



int main() {
	std::vector<int> v(6);
	//v.at(9);



	std::cerr << "boujour\n";
	int c;
	try {
		throw c;
		f();
		std::cerr << "message\n";
	}
	catch(std::out_of_range& a)
	{
		std::cerr << "Une exception de type out_of_range a été lancée" << std::endl;
	}
	catch(long a) {
		std::cerr << "Une exception de type long a été lancée: " << a << std::endl;
	}
	catch(int a) {
		std::cerr << "Une exception de type int a été lancée: " << a << std::endl;
	}
	catch(...) // n'importe quel type
	{
		std::cerr << "Une exception de type inconnu a été lancée" << std::endl;
	}

	std::cerr << "au revoir\n";
}

*/


/*
struct A{};
struct B public A {};

int main() {
	try {
		throw B();
	}
	catch(A& a) {
	//catch(B& a) {
		std::cerr << "Une exception a été lancée" << std::endl;
	}
}
*/





/*
struct monExcep : public std::exception
{

};

voi maFonction(int a, int b) {
	if (a == b)
		throw monExcep();
	std::cerr << "appel de maFonction" << std::endl;
}


int main() {


	try {
		maFonction(5, 5);
	}
	catch(monExcep& a) {
		std::cerr << "erreur:" << std::endl;
	}


}*/




struct A {
	virtual void f() {};
};

struct B : public A {

}



int main() {
	B b1;
	std::cout<< &b1 << std::endl;
	A* pa=&b1;
	N* pb=dynamic_cast<B*>(pa);
	std::cout << pb << std::endl;

	A a1;
	std::cout << &a2 << std::endl;
	pa=&a1;
	pb=dynamic_cast<B*>(pa);
	std::cout<<pb<<std::endl;
}
