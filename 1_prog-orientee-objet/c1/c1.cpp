#include<cstio>

struct Fraction {
    private:
        int pgcd; //
        int n; //numerateur
        int d; //denominateur

    public:
        Fraction(int num, int den) { // constructeur (aka __init__ du python)
            n = num;
            d = den;
            pgcd = calcul_pgcd(num, den);
        }

        void afficher_Frac(void) {
        printf("%d/%d\n", n, d); //print du c, pas du cpp (pas sûr qu'il faille donner les valeurs comme ça)
        }

        int calcul_pgcd(int a, int b) {...}
        
        Fraction produit(Fraction m) {
            Fraction r = m;
            
            r.n = n * m.n;
            r.d = d * m.d;
            
            return r;
        }
        
        void set_num(int num) {
            n = num;
            pgcd = calcul_pgcd();
        }
        
        int get_num(void) {
            return n;
        }
}




int main(void) {
    Fraction f2(4, 7); //ou bien "Fraction f2{4, 7};"
    Fraction f1 = {1, 3};
    Fraction f3 = f2.produit(f1);

    f1.afficher();
}



/*
 * -les "fractions" définies à l'intérieur de la classe sont appelées "méthodes"
 * - les "données" définies à l'intérieur de la classe sont appelées "attributs"
 * l'ensemble des attributs et méthodes sont appelés les membres de la classes
 * chaque membres peut-être "public" (default) ou "private"
 */


