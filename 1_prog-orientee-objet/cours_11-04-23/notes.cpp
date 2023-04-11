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
	//int &&ref2=maVar2; //error
	int &&ref2=4;
	int &&ref3=f();


}