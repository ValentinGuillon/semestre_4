
#include<iostream>
#include<vector.hpp>
#include<assert.h>

using namespace std;



int main(void) {
	int size = 4;

	//MIN / MAX

	vector_t a{size};


	a[0] = 5;
	a[1] = 12;
	a[2] = 6;
	a[3] = -2;
	a[4] = 2;

	cout<<"a:\n  "; a.print_tab(); cout<<endl;
	cout<<"  min ="<<' '<<a.min()<<", max = "<<a.max()<<endl;

	cout<<"\033[38;2;255;171;0;1m//a[1] = -8;\033[0m"<<endl;
	a[1] = -8;

	cout<<"a:\n  "; a.print_tab(); cout<<endl;
	cout<<"  min = "<<a.min()<<", max = "<<a.max()<<endl;



	//VECTOR_T * X

	cout<<"\033[38;2;255;171;0;1m//vector_t b = a*5;\033[0m"<<endl;
	vector_t b = a*5;
	cout<<"b: (a*5)\n  "; b.print_tab(); cout<<endl;
	cout<<"  min ="<<' '<<b.min()<<", max = "<<b.max()<<endl;
	cout<<"\033[38;2;255;171;0;1m//assert(a[2] != b[2]);\033[0m"<<endl;

	assert(a[2] != b[2]);




	return 0;
}
