
#include<string>


class personne_t {
    string nom;
    string prenom;
    int age;
    string profession;

    public:
        personne_t(string nom, string prenom, int age);
        void setAge(int age);
        int getAge(void);
        string getProfession(void);
        void setProfession(string newProfessions);
        string affiche(void);
};

