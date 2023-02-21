
#include<iostream>
#include<cstdlib>
#include<vector.hpp>


using namespace std;




vector_t::vector_t(int size) {
			this->size = size;
			this->tab = (int*)malloc(sizeof(int) * size);
			fill_tab();
}

vector_t::~vector_t(void) {
			free(this->tab);
}




void vector_t::fill_tab (void){
	for (int i = 0; i < this->size; i++)
		this->tab[i] = 0;
}




void vector_t::print_tab(void) {
	cout<<"[";
	for (int i = 0; i < this->size - 1; i++) {
		cout<<this->tab[i]<<", ";
	}

	cout<<this->tab[this->size -1]<<"]";
}


int & vector_t::operator[](int index) {
	//si index trop grand, error
	if (index > size) {
		throw 1;
	}

	//index négatif
	if (index < 0) {
		//si la taille du tableau + index est négatif, error
		if (size + index < 0)
			throw "ntm";
		return this->tab[size + index];
	}

	return this->tab[index];
}




int vector_t::max(void) {
	int max = this->tab[0];
	for (int i = 0; i < this->size; i++) {
		if (tab[i] > max)
			max = tab[i];
	}
	return max;
}


int vector_t::min(void) {
	int min = this->tab[0];
	for (int i = 0; i < this->size; i++) {
		if (tab[i] < min)
			min = tab[i];
	}
	return min;
}



vector_t vector_t::operator *(int value) {
	vector_t new_vect{this->size};

	for (int i = 0; i < this->size; i++) {
		new_vect[i] = this->tab[i] * value;
	}

	return new_vect;
}

// vector_t vector_t:: * operator(int value) {
// 	vector_t new_vect{this->size};

// 	for (int i = 0; i < this->size; i++) {
// 		new_vect[i] = this->tab[i] * value;
// 	}

// 	return new_vect;
// }



