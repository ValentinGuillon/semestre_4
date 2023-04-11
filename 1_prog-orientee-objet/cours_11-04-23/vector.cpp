/* VECTOR */

#include<vector> //tableau taille souple
#include<iostream>


int main() {
	//déclaration
	std::vector<int> v1;
	std::vector<int> v2(3); //remplis le tableau avec 3 élements par défaut

	//ajout d'éléments
	v1.push_back(45); //'append()' de python
	v1.push_back(32);
	v1.push_back(4);

	//boucler
	for (auto a: v1) {
		std::cout << a << " ";
	}

	std::cout<<std::endl<< v1.size() << std::endl;

	//affectation d'une cellule
	v1[2]=3;
	v1.at(1)=2; //error 'out_of_range' si l'index n'existe pas

	for (auto a: v1) {
		std::cout << a << " ";
	}
}
