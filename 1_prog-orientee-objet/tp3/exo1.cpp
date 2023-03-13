
#include<iostream>
#include<cassert>



using namespace std;


int min(double a, double b);
int max(double a, double b);


class Interv
{
	double borne_min;
	double borne_max;
	int interv_est_vide = 0; //bool

	public:
		Interv(double a, double b);
		Interv(double a);
		Interv(void);

		friend ostream &operator<<(ostream &out, Interv obj)
		{
			if (obj.estVide())
				return out<<"{}";
			return out<<"["<<obj.borne_min<<"; "<<obj.borne_max<<"]";
		}

        // friend ostream &operator<<(ostream &out, vecteur2d_t &vec) {
        //     return out<<"{x:"<<vec.x<<", y:"<<vec.y<<"}";
        // }

		//retourne 1 si un double est dans l'intervalle
		int appartient(double e);
		//retourne l'Interv de deux intervalle
		Interv intersec(Interv b);
		//retourne l'union de deux intervalle
		Interv uni(Interv b);
		int estVide(void);
};




int main(void)
{
	Interv a = Interv(4, 8);
	Interv b = Interv();
	Interv c = Interv(5);
	Interv d = Interv(15, 6);
	Interv e = Interv(-2, 3);

	cout<<"Intervalle A = "<<a<<endl;
	cout<<"Intervalle B = "<<b<<endl;
	cout<<"Intervalle C = "<<c<<endl;
	cout<<"Intervalle D = "<<d<<endl;
	cout<<"Intervalle E = "<<e<<endl;


	//appartient

	for (int i = 0; i < 3; i++)
	{
		if (a.appartient(i+3))
			cout<< i+3 <<" appartient à A"<<endl;
		else
			cout<< i+3 <<" n'appartient pas à A"<<endl;
	}

	//intersection
	Interv test = a.intersec(d);
	assert(test.appartient(6.1));
	assert(test.appartient(7.9));
	assert(!test.appartient(5.9));
	assert(!test.appartient(9.1));


	
	cout<<"Intersection de A et D = "<<a.intersec(d)<<endl;
	cout<<"Intersection de D et E = "<<d.intersec(e)<<endl;

	//union
	cout<<"Union de A et D = "<<a.uni(d)<<endl;
	cout<<"Union de B et E = "<<b.uni(e)<<endl;
	cout<<"Union de A et E = "<<a.uni(e)<<endl;

	cout<<"Inter de "<<Interv{1, 3}<<" et "<<Interv{2, 4}<<" = "<<Interv{1, 3}.intersec(Interv{2, 4})<<endl;
	cout<<"Union de "<<Interv{-2, -1}<<" et "<<Interv{1, 2}<<" = "<<Interv{-2, -1}.uni(Interv{1, 2})<<endl;


	return 0;
}









int min(double a, double b)
{
	if (a > b) return b;
	return a;
}

int max(double a, double b)
{
	if (a < b) return b;
	return a;
}




Interv::Interv(double a, double b)
{
	if (b < a)
	{
		this->borne_min = b;
		this->borne_max = a;
	}
	else
	{
		this->borne_min = a;
		this->borne_max = b;
	}
}

Interv::Interv(void)
{
	//ptdr je ne sais pas comment décrire un intervalle
	this->interv_est_vide = 1;
}

Interv::Interv(double a)
{
	this->borne_min = a;
	this->borne_max = a;
}



//retourne 1 si un double est dans l'intervalle
int Interv::appartient(double e)
{
	//un des deux Interv est vide
	if (this->estVide())
		return 0;

	//si n'appartient pas
	if (e < borne_min || e > borne_max)
		return 0;

	return 1;
}

//retourne l'Interv de deux intervalle
Interv Interv::intersec(Interv b)
{
	//un des deux Interv est vide
	int cas1 = this->estVide() || b.estVide();
	//*this est strictement inférieur à b
	int cas2 = this->borne_max < b.borne_min;
	//*this est strictement supérieur à b
	int cas3 = this->borne_min > b.borne_max;
/*
	cout<<endl<<"test intersection entre "<<*this<<" et "<<b<<":"<<endl;
	cout<<"cas1="<<cas1<<", cas2="<<cas2<<", cas3="<<cas3<<endl;
*/
	//un des deux Interv est vide
	if (cas1 || cas2 || cas3)
		return Interv{};

/*
	//ici il y'a a obligatoirement un intervalle
	//regardons si a est plus faible
	if (this->borne_min <= b.borne_min)
		return Interv(b.borne_min, this->borne_max);
	else
		return Interv(this->borne_min, b.borne_max);
*/

	return Interv(max(this->borne_min, b.borne_min), min(this->borne_max, b.borne_max));


}

//retourne l'union de deux intervalle
Interv Interv::uni(Interv b)
{
	//si l'inter des deux est vide
	if (this->intersec(b).estVide())
	{
		cout<<"Impossible d'unir "<<*this<<" et "<<b<<" avec la classe actuel"<<endl;
		return Interv{};
		// throw 1;
	}

/*
	if (this->borne_max < b.borne_min)
	{
		cout<<"Impossible d'unir "<<*this<<" et "<<b<<" avec la classe actuel"<<endl;
		return Interv{};
		// throw 1;
	}
*/


	return Interv(min(this->borne_min, b.borne_min), max(this->borne_max, b.borne_max));
}


int Interv::estVide(void)
{
	return interv_est_vide;
}
