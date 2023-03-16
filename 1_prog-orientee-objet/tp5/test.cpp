
#include <iostream>

using namespace std;


void print(char* a, int size);
char* copy(char* a, int size);


int main (void)
{
    // char chaine[10] = "aled";

    // int size = 0;
    // for (int i = 0; chaine[i] != '\0'; i++)
    // {
    //     size++;
    // }
    // cout<<"size = "<<size<<endl;


    char *a = NULL;
    int size = 4;
    a = (char*) realloc(a, sizeof(char) * size);

    a[0] = 'a';
    a[1] = 'l';
    a[2] = 'e';
    a[3] = 'd';



    print(a, size);

    char* b = copy(a, size);
    free(a);

    size = 2;
    a = (char*) realloc(a, sizeof(char) * size);
    a = copy(b, size);

    print(a, 2);

    cout<<"Prog ended"<<endl;
    return 0;
}




void print(char *a, int size)
{
    for (int i = 0; i < size; i++)
        cout<<a[i];
    cout<<endl;
    for (int i = 0; i < size; i++)
        cout<<i<<"= "<<a[i]<<endl;
}


char* copy(char* str, int size)
{
    //on verifie si la taille de "str" est plus petit que "size"
    int str_size = 0;
    for (int i = 0; str[i] != '\0'; i++)
        str_size++;

    if (str_size < size)
        size = str_size;
    
    //on copie "str" dans "ret"
    char* ret = (char*) malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        ret[i] = str[i];

    return ret;
}
