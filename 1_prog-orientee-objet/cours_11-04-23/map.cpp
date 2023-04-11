#include<map> //dictionnaire
#include<string>
#include<iostream>

int main() {
	std::map<std::string, std::string> dico; //on met les types de "clé" et de "valeur" que l'on veut
	//std::map<std::string, std::string> dico2({"voiture":"truc qui roule"});
	/* il est recommendé que la clé est l'opérateur < */
	dico["ballon"]="objet rond et creux";

	/****/

	std::cout << dico["ballon"] << std::endl;
	dico["ballon"]="objet sphérique et rempli de gaz";
	std::cout << dico["ballon"] << std::endl;
	dico["parapluie"]="protège le saligot de la pluie. gg";

	for (auto &[a, b]: dico) {
		std::cout << a << ":" << b << std::endl;
	}

	//std::cout<< "pas at \"caillou\":" << dico["caillou"] << std::endl;
	std::cout<< "at \"caillou\":" << dico.at("caillou") << std::endl;

}