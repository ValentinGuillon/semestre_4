#include<array> //tableau taille static
#include<iostream>

int main () {
	//int t1[10]; //déclaration de tableau en C

	std::array<int, 10> t2; //déclaration de tableau en C++

	int i = 0;

	for(int& a: t2) { //& permet de pouvoir modifier la tableau
		a=i++;
	}

	for(auto& a: t2) {
		std::cout<< a << " "; //sans &, on ne peut pas modifier les éléments
	}


}