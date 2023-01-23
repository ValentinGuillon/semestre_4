#include<iostream>
#include<cstdio>
#include<string>

// ceci est un commentaire sur une ligne
/* ceci est un commentaire sur
plusieurs lignes*/

using namespace std;  // permet d'éviter d'écrire systématiquement std::cin ou std::cout (à éviter)

int main(void)
{
   int d; // une variable entière d
   int i; 
   string div;
   string ndiv;

   cout<<"****Premier programme****"<<endl;
   std::cout<<"Saisissez un nombre puis appuyez sur entrée : ";
   std::cin >> d;

   i=1; // on met 0 dans i
   while(i<=15)
   {
      if( d % i == 0)
      {
         div += to_string(i) + ",";
         //cout << i << " divise " << d << endl;
      }
      else
      {
      	 ndiv += to_string(i) + ",";
         //printf("%d ne divise pas %d\n",i,d);
      }
      
      cout << div << " divise " << d << ", " << ndiv << " ne divise pas " << d << endl;
      
      i=i+1;
   }
}


