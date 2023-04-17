#include<iostream>
#include<vector>

struct Nombre {
	virtual int operator<(Nombre& a) = 0; //pure == incomplete
};
struct Fraction : public Nombre {
	/* definition de Fraction */
	int operator<(Nombre& a) {
		/*...*/
	}
};

struct FonctionNumerique : public Nombre {
	/* definition */
}

struct ExpressionAlgebrique : public Nombre {
	/* définition */
}


void tri(std::vector<Nombre>& a) {
	/*definition*/
}


int main(){

}