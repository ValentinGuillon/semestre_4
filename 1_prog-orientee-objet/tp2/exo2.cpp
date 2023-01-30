#include<iostream>
#include<string>
#include "personne_t.hpp"

using namespace std;


int main(void) {
	personne_t lui{"PIERRE", "Ninet", 45};
	cout<<lui.affiche()<<endl;
	cout<<"Profession: "<<lui.getProfession()<<endl;
	cout<<"10 ans plus tard..."<<endl;
	lui.setAge(lui.getAge()+3);
	lui.setProfession("Déménageur");
	lui.setAge(lui.getAge()+7);
	cout<<lui.affiche()<<endl;


}

