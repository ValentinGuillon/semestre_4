/* MAP */
#include<map> //dictionnaire de python
#include<string>
#include<iostream>

int main() {
	//déclaration (on met les types de "clé" et de "valeur" que l'on veut)
	std::map<std::string, std::string> dico; 
	//std::map<std::string, std::string> dico2({"voiture":"truc qui roule"});
	/* il est recommandé que la clé ai l'opérateur < */

	//création d'une entrée (ou remplacement d'un existante)
	dico["ballon"]="objet rond et creux";
	std::cout << dico["ballon"] << std::endl;
	dico["ballon"]="objet sphérique et rempli de gaz";
	std::cout << dico["ballon"] << std::endl;

	dico["parapluie"]="protège le saligot de la pluie. gg";
	dico["cahier"];


	//boucler
	for (auto &[a, b]: dico) {
		std::cout << a << " : " << b << std::endl;
	}

	std::cout << dico.at("caillou") << std::endl; //si la clé n'existe pas, throwing 'out_of_range'

}