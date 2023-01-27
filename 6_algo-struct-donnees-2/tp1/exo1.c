
#include <stdio.h>

int tri_a_bulle(int T[], int n);
//question 1
int tri_a_bulle_corrige(int T[], int n);
//question 2
int tri_a_bulle_opti(int T[], int n);
//question 3
int permute(int *a, int *b);

//debug
void init_list(int T[], int size);
void print_int_list(int T[], int size);





int main(void) {
    int size = 10;
    int T[size];
    int loop = 0;

    init_list(T, size);
    // print_int_list(T, size);

    //tri a bulle
    loop = tri_a_bulle(T, size);
    // printf("\ntri_a_bulle(T), loop = %d\n", loop);
    // print_int_list(T, size);

    //tri a bulle corrigé
    init_list(T, size);
    loop = tri_a_bulle_corrige(T, size);
    // printf("\ntri_a_bulle_corrige(T), loop = %d\n", loop);
    // print_int_list(T, size);

    //tri a bulle opti
    init_list(T, size);
    loop = tri_a_bulle_opti(T, size);
    // printf("\ntri_a_bulle_opti(T), loop = %d\n", loop);
    // print_int_list(T, size);

    return 0;
}








int tri_a_bulle(int T[], int n) {
    // int temp;
    int loop = 0;
    for (int i = n-1; i > 0; i--) {
        for (int j = 1; j < i-1; j++) {
            loop++;
            if (T[j] > T[j+1]) {
                // temp = T[j+1];
                // T[j+1] = T[j];
                // T[j] = temp;
                permute(&T[j], &T[j+1]);
            }
        }
    }

    return loop;
}



int tri_a_bulle_corrige(int T[], int n) {
    // int temp;
    int loop = 0;
    for (int i = n-1; i > 0; i--) {
        // for (int j = 1; j < i-1; j++) {
        for (int j = 0; j < i; j++) {
            loop++;
            if (T[j] > T[j+1]) {
                // temp = T[j+1];
                // T[j+1] = T[j];
                // T[j] = temp;
                permute(&T[j], &T[j+1]);
            }
        }
    }

    return loop;
}



int tri_a_bulle_opti(int T[], int n) {
    // int temp;
    int loop = 0, none_swapped = 0;
    for (int i = n-1; i > 0; i--) {
        none_swapped = 0;
        for (int j = 0; j < i; j++) {
            loop++;
            if (T[j] > T[j+1]) {
                // temp = T[j+1];
                // T[j+1] = T[j];
                // T[j] = temp;
                permute(&T[j], &T[j+1]);
                none_swapped = 0;
            }
            else none_swapped++;
        }
        i -= none_swapped;
    }

    return loop;
}



int permute(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}



void init_list(int T[], int size) {
    int init[10] = {4, 6, 1, 5, 3, 4, 8, 2, 8, 9};
    for (int i = 0; i < size; i++) {
        T[i] = init[i];
    }
}

//debug
void print_int_list(int T[], int size) {
    printf("T = {");
    for (int i = 0; i < size; i++) {
        printf("%d", T[i]);
        if (i != size-1) printf(",");
    }
    printf("}\n");
}



