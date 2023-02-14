

typedef struct s_noeud_t noeud_t;

struct s_noeud_t {
	int v;
	noeud_t* g;
	noeud_t* d;
};

//retourne l'adresse d'un noeud, en lui donnant une valeur et deux sous arbres
noeud_t* add_n(int val, noeud_t* gauche, noeud_t* droite);

//libère la mémoire de chaque noeud de l'arbre
void cut_tree(noeud_t* tree);

//retourne 1 si l'arbre binaire est de recherche, en mettant min et max à jour à chaque appel (récursif)
int is_search_binary_tree(noeud_t* tree, int* min, int* max);
//retire une valeur de l'arbre, tout en conservant l'intégrité de l'ABR
noeud_t* remove_val(noeud_t* tree, int val);

//retourne la plus petite valeur de l'arbre
int min_of_tree(noeud_t* tree);
//retourne la plus grande valeur de l'arbre
int max_of_tree(noeud_t* tree);



//affiche tout le sous-arbre gauche, puis le droit, en parcours préfixe
void print_tree(noeud_t* tree, int profondeur);
//affiche différent type de parenthèse en fonction de n
void print_parenthèse(int n, int ouvrant);




int _print_t(noeud_t *arbre, int is_left, int offset, int depth, char s[20][255]);

void print_t(noeud_t *arbre);