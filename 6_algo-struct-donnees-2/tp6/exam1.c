#include <stdio.h>
#include <stdlib.h>


int main(){
	int* p=NULL;
	int tab[4];
	printf("%ld, %ld, %ld\n",sizeof(tab), sizeof(&tab), sizeof(tab[0]));
	p = malloc(5*sizeof(int));
	printf("%ld, %ld\n",sizeof(p), sizeof(*p));
	p = malloc(4*sizeof(int));
	printf("%ld, %ld\n",sizeof(p), sizeof(*p));
	for (int i=0; i<5; i++){
		if (i%2 == 0) { // i est pair
			p[i]=i;
		} else {
			p[i] = 0;
		}
	}
	for (int i=0; i<5; i++){
		printf("%d",p[i]);
	}
	free(p);
	return 0;
}

