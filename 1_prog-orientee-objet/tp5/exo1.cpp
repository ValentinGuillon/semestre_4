
#include<iostream>
#include<vector.hpp>

using namespace std;



int main(void) {
	int size = 4;

	vector_t a{size};


	a[0] = 5;
	a[1] = 12;
	a[2] = 6;
	a[3] = -2;
	a[4] = 2;

	cout<<"min ="<<' '<<a.min()<<", max = "<<a.max()<<endl;

	a[1] = -8;

	cout<<"min = "<<a.min()<<", max = "<<a.max()<<endl;


	vector_t b = a*5;



	for (int i = 0; i < size; i++) {
		cout<<a[i]<<endl;
	}

	for (int i = 0; i < size; i++) {
		cout<<b[i]<<endl;
	}


	vector_t c = 3*a;




	for (int i = 0; i < size; i++) {
		cout<<c[i]<<endl;
	}








	return 0;
}
