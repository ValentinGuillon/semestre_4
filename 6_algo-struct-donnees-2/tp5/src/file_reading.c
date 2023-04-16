

#include<file_reading.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void read_file(char* filename, char* content) {
    FILE *f_ptr = fopen(filename, "r");

    content = malloc(sizeof(char));

    char c;
    int nb_char = 0;
    while (c != EOF) {
        c = (char)fgetc(f_ptr);
        nb_char++;

        content = realloc(content, (nb_char+1) * sizeof(char));
        strncat(content, &c, 1); //ajoute "c" à la suite de "content"
    }

    // strcat(content, &'\0', 1);
    fclose(f_ptr);
}






void create_matrice(int **mat, int *size, char* filename) {
    char *filecontent = NULL;
    read_file(filename, filecontent);

    *size = filecontent[0];

    mat = malloc(*size * sizeof(int*));
    for (int i = 0; i < *size; i++)
        mat[i] = malloc(*size * sizeof(int*));

    // for (int i = 0; i < SIZE; i++){
    //     for (int j = 0; j < SIZE; j++)
    //         mat[i][j] = matrice[i][j];
    // }

    for (int i = 1; filecontent != '\0'; i++) {
        if (filecontent == '\n')
            continue;
        /*...*/
    }


}


// void write_file(char* filename, char* text) {
//     return;
// }



// int main(void) {
//     char* file_name = "file_reading.txt";
//     char* text = NULL;

//     text = read_file(file_name, text);

//     for (int i = 0; text[i] != '\0'; i++) {
//         printf("%c", text[i]);
//     }
//     printf("\nEND\n");
// }

