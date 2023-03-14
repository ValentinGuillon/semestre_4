
#include<vector.hpp>

#include<iostream>
#include<cstdlib>

using namespace std;




vector_t::vector_t(int size)
{
			this->size = size;
			this->tab = (int*)malloc(sizeof(int) * size);
			init_tab();
}


vector_t::vector_t (vector_t const &obj)
{
	this->size = obj.size;
	this->tab = (int*)malloc(sizeof(int) * this->size);
	init_tab();
}


vector_t::~vector_t(void) {
			free(this->tab);
}





void vector_t::init_tab (void){
	for (int i = 0; i < this->size; i++)
		this->tab[i] = 0;
}


ostream &operator<<(std::ostream &out, vector_t &obj)
{
	out<<"[";
	for (int i = 0; i < obj.size - 1; i++) {
		out<<obj.tab[i]<<", ";
	}

	return out<<obj.tab[obj.size]<<"]";
}

// void vector_t::print_tab(void) {
// 	cout<<"[";
// 	for (int i = 0; i < this->size - 1; i++) {
// 		cout<<this->tab[i]<<", ";
// 	}

// 	cout<<this->tab[this->size -1]<<"]";
// }



int & vector_t::operator [] (int const index) const
{
	//si index trop grand, error
	if (index > this->size)
		throw 1;

	return this->tab[index];
}





int vector_t::max (void) const
{
	int max = this->tab[0];

	for (int i = 1; i < this->size; i++)
	{
		if (this->tab[i] > max)
			max = this->tab[i];
	}

	return max;
}


int vector_t::min (void) const
{
	int min = this->tab[0];

	for (int i = 1; i < this->size; i++) {
		if (this->tab[i] < min)
			min = this->tab[i];
	}

	return min;
}



vector_t vector_t::operator * (int const multiplier)
{
	vector_t new_vect{this->size};

	for (int i = 0; i < this->size; i++) {
		new_vect.tab[i] = this->tab[i] * multiplier;
	}

	return new_vect;
}

vector_t operator * (int const multiplier, vector_t const &obj)
{
	vector_t new_vect = obj;

	for (int i = 0; i < new_vect.size; i++) {
		new_vect.tab[i] = new_vect.tab[i] * multiplier;
	}

	return new_vect;
}

