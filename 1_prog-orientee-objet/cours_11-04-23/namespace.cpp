/* namespace */
#include<iostream>


int var=1;

//ouverture d'un espace de nom
namespace monEDN {
	int var=2;
	void mafonction(){};
	struct MonType{};

	namespace MSED { //Inception
		int var=3;
	}
}

//ajouter du nouveau contenu dans un espace de nom déjà existant
namespace monEDN{ 
	int var2=4;
}

/*
//accès à une variable d'un namespace
int main() {
	std::cout<< "boujour" << " ";
	std::cout<< var << " "; //var = 1
	std::cout<< monEDN::var << " "; //var = 2
	std::cout<< monEDN::MSED::var << " ";  //var = 3

}*/


/*
//prioriser l'utilisation d'une variable d'un namespace spécifique
int main() {
	using monEDN::MSED::var; //"var" fera désormais référence à "var=3"
	std::cout<< var << " ";
}*/



int main() {
	using namespace monEDN;
	std::cout<< MSED::var << " ";

}