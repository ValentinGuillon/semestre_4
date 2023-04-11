/* ARRAY */
#include<array> //tableau taille static

#include<iostream>

int main () {
	//déclaration de tableau en C
	//int t1[10];

	//déclaration de tableau en C++, avec 'array'
	std::array<int, 10> t2;

	int i = 0;

	//boucler sur chaque élément du tableau
	for(int& a: t2) { //& (référence) permet de pouvoir modifier le tableau
		a=i++;
	}

	for(auto a: t2) { //sans &, on ne peut pas modifier les éléments
		std::cout<< a << " "; 
	}

	//'auto' fonctionne pour tous les types
}