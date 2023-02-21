

#ifndef VECTOR_H
#define VECTOR_H


class vector_t {
	int size;
	int *tab;

	void fill_tab (void);


	public:
		vector_t (int size);
		~vector_t (void);
		void print_tab (void);
		int & operator [] (int index);
		int max (void);
		int min (void);
		vector_t operator * (int value);
		// vector_t * operator (int value);
};


#endif
