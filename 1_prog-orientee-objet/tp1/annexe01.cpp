#include<iostream>
#include<cstdio>

// ceci est un commentaire sur une ligne
/* ceci est un commentaire sur
plusieurs lignes*/

using namespace std;  // permet d'éviter d'écrire systématiquement std::cin ou std::cout (à éviter)

int main(void)
{
   int d; // une variable entière d
   int i; 

   cout<<"****Premier programme****"<<endl;
   std::cout<<"Saisissez un nombre puis appuyez sur entrée : ";
   std::cin >> d;

   i=1; // on met 0 dans i
   while(i<=15)
   {
      if( d % i == 0)
      {
         cout << i << " divise "
            << d << endl;
      }
      else
      {
         printf("%d ne divise pas %d\n",i,d);
      }
      i=i+1;
   }
}


