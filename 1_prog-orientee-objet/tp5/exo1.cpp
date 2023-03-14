
#include<vector.hpp>

#include<iostream>
#include<cassert>

using namespace std;



int main(void) {


	vector_t v(5);
	vector_t t(500000);

	v[3] = 2;
	int a = v[3];
	// v[6]; //out of range
	v.max();
	v.min();
	vector_t b = v*3;
	assert(b[3] != v[3]);
	b = 4*v;

	// int size = 4;

	// //MIN / MAX

	// vector_t a{size};


	// a[0] = 5;
	// a[1] = 12;
	// a[2] = 6;
	// a[3] = -2;
	// a[4] = 2;

	// cout<<"a:\n  "; a.print_tab(); cout<<endl;
	// cout<<"  min ="<<' '<<a.min()<<", max = "<<a.max()<<endl;

	// cout<<"//a[1] = -8;"<<endl;
	// a[1] = -8;

	// cout<<"a:\n  "; a.print_tab(); cout<<endl;
	// cout<<"  min = "<<a.min()<<", max = "<<a.max()<<endl;



	// //VECTOR_T * X

	// cout<<"//vector_t b = a*5;"<<endl;
	// vector_t b = a*5;
	// cout<<"b: (a*5)\n  "; b.print_tab(); cout<<endl;
	// cout<<"  min ="<<' '<<b.min()<<", max = "<<b.max()<<endl;
	// cout<<"//assert(a[2] != b[2]);"<<endl;

	// assert(a[2] != b[2]);




	return 0;
}
