#include<iostream>

int f() {
	return 5;
}


int main() {
	//référence de type Lvalue
	int maVar;
	int &ref=maVar;

	ref=1; //pareil que "maVar=1"



	//référence de type Rvalue;
	int maVar2;
	//int &&ref4=maVar2; //error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
	int &&ref2=4;
	int &&ref3=f();
}