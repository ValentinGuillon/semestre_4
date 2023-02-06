
#include<cstdio>
#include<assert.h> //je sais pas si ça va compiler mdr



using namespace std;


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

		int appartient(double e) {
			//un des deux Interv est vide
			if (this.estVide()) {
				return 0;
			}
			//si n'appartient pas
			if (e < borne_min || e > borne_max) {
				return 0;
			}

			return 1;
		}

		Interv intersec(Interv const b) {
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

		Interv uni(Interv const b) {
			//si l'inter des deux est vide
			if (this->intersec(b).estVide()) {
				throw 1;
			}

			return Interv(min(this->borne_min, b.borne_min), max(this->borne_max, b.borne_max));
		}





		int estVide(void) {
			return interv_est_vide;
		}



};


int min(double a, double b) {
	if (a < b) return b;
	return a;
}

int max(double a, double b) {
	if (a > b) return b;
	return a;
}





int main(void) {
	Interv a = Interv(4, 8);
	Interv b = Interv();
	Interv c = Interv(5);
	Interv d = Interv(6, 15);
	Interv e = Interv(-2, 3);


	return 0;
}




