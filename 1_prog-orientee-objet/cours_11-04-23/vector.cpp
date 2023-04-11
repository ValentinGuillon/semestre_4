#include<vector> //tableau taille souple
#include<iostream>


int main() {
	std::vector<int> v1(3);
	v1.push_back(45); //append de python
	v1.push_back(32);
	v1.push_back(4);

	for (auto a: v1) {
		std::cout << a << " ";
	}

	//std::vector<int> v2(3):
	std::cout<< v1.size();
	v1[2]=3;
	v1.at(1)=2;
	for (auto a: v1) {
		std::cout << a << " ";
	}



}

