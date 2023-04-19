
//#include<stdio.h>
#include<stdlib.h>


typedef struct ma_struct_t ma_struct;
struct ma_struct_t {
	int a, b;
	ma_struct *c;
};




int main(void) {
	int var_int = 69;
	float var_float = 3.14;
	char var_char = 'V';
	char var_chaine1[] = "aled";
	long int var_long_int = 6969;
	char var_chaine2[] = "pas aled";
	int *var_ptr_int = malloc(sizeof(var_ptr_int));
	int **var_ptr_ptr_int = malloc(sizeof(var_ptr_ptr_int));
	int var_tab_int[] = {9, 6, 4, 8, 2};
	ma_struct var_ma_struct;
	ma_struct *var_ptr_ma_struct = malloc(sizeof(var_ptr_ma_struct));


	//return 0;
	free(var_ptr_int);
	free(var_ptr_ptr_int);
	free(var_ptr_ma_struct);

	return 0;
}

