
// #include<cstdio>
#include<iostream>
#include<assert.h> //je sais pas si ça va compiler mdr



using namespace std;

class Interv;

int min(double a, double b);
int max(double a, double b);


class Interv {
	double borne_min;
	double borne_max;
	int interv_est_vide = 0; //bool


	public:
		Interv(double a, double b) {
			if (b < a) {
				this->borne_min = b;
				this->borne_max = a;
			}
			else {
				this->borne_min = a;
				this->borne_max = b;
			}
		}

		Interv(void) {
			//ptdr je ne sais pas comment décrire un intervalle
			this->interv_est_vide = 1;
			return;
		}

		Interv(double a) {
			this->borne_min = a;
			this->borne_max = a;
		}

		void afficher(void) {
			if (this->estVide()) {
				cout<<"[-O-]";
				return;
			}
			cout<<"["<<borne_min<<"; "<<borne_max<<"]";
		}


		//retourne 1 si un double est dans l'intervalle
		int appartient(double e) {
			//un des deux Interv est vide
			if (this->estVide()) {
				return 0;
			}
			//si n'appartient pas
			if (e < borne_min || e > borne_max) {
				return 0;
			}

			return 1;
		}

		//retourne l'Interv de deux intervalle
		Interv intersec(Interv b) {
			//un des deux Interv est vide
			if (this->estVide() || b.estVide()) {
				return Interv();
			}

			//cas où il n'y a pas d'intersection
			if (this->borne_max < b.borne_min && this->borne_min < b.borne_min) {
				//this est plus faible
				return Interv();
			}
			else if (b.borne_max < this->borne_min && b.borne_min < this->borne_min) {
				//b est plus faible
				return Interv();
			}


			//ici il y'a a obligatoirement un intervalle
			//regardons si a est plus faible
			if (this->borne_min <= b.borne_min) {
				return Interv(b.borne_min, this->borne_max);
			}
			else {
				return Interv(b.borne_min, this->borne_max);
			}
		}

		//retourne l'union de deux intervalle
		Interv uni(Interv b) {
			//si l'inter des deux est vide
			if (this->intersec(b).estVide()) {
				cout<<"Impossible d'unir ";
				this->afficher();
				cout<<" et ";
				b.afficher();
				cout<<" avec la classe actuel"<<endl;

				return Interv();
				// throw 1;
			}

			return Interv(min(this->borne_min, b.borne_min), max(this->borne_max, b.borne_max));
		}


		int estVide(void) {
			return interv_est_vide;
		}
};





int main(void) {
	Interv a = Interv(4, 8);
	Interv b = Interv();
	Interv c = Interv(5);
	Interv d = Interv(15, 6);
	Interv e = Interv(-2, 3);

	cout<<"Intervalle A = "; a.afficher(); cout<<endl;
	cout<<"Intervalle B = "; b.afficher(); cout<<endl;
	cout<<"Intervalle C = "; c.afficher(); cout<<endl;
	cout<<"Intervalle D = "; d.afficher(); cout<<endl;
	cout<<"Intervalle E = "; e.afficher(); cout<<endl;


	//appartient
	for (int i = 0; i < 3; i++) {
		if (a.appartient(i+3))
			cout<< i+3 <<" appartient à A"<<endl;
		else
			cout<< i+3 <<" n'appartient pas à A"<<endl;
	}

	//intersection
	cout<<"Intersection de A et D = "; a.intersec(b).afficher(); cout<<endl;
	cout<<"Intersection de D et E = "; d.intersec(e).afficher(); cout<<endl;

	//union
	cout<<"Union de A et D = "; a.uni(d).afficher(); cout<<endl;
	cout<<"Union de B et E = "; b.uni(e).afficher(); cout<<endl;
	cout<<"Union de A et E = "; a.uni(e).afficher(); cout<<endl;


	return 0;
}









int min(double a, double b) {
	if (a < b) return b;
	return a;
}

int max(double a, double b) {
	if (a > b) return b;
	return a;
}




