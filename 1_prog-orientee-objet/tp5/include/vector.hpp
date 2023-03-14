

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class vector_t {
	int size;
	int *tab; //pointeur vers un tableau de taille "size"

	//remplit tab avec des 0 (zéro)
	void init_tab (void);


	public:
		vector_t (int size);
		vector_t (vector_t const &obj);
		~vector_t (void);

		friend std::ostream &operator<<(std::ostream &out, vector_t &obj);
		// void print_tab (void);
		int & operator [] (int const index) const;
		int max (void) const;
		int min (void) const;
		vector_t operator * (int const multiplier);
		friend vector_t operator * (int const multiplier, vector_t const &obj);

};


#endif
