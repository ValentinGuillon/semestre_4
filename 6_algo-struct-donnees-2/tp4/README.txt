
PROBLÈMES NON RÉSOLU

LISTE CHAÎNÉES
La structure/fonction est ok, mais pas avec tp4_db.csv (uniquement avec test.csv, db de quelques éléments).
Elle fonctionnait niquel avant que j'implémente la table de hachage (j'ai du niqué un truc, rip).
Ça crash au moment de free la liste chaînée (Segmentation fault (core dumped)).
À noter que dans le main, il y'a deux fonctions pour tester les listes chaînées.
Et chaque test à sa propre variable de ll (donc test 1; création ll, free ll. test 2; création ll, free ll)

TABLE DE HACHAGE
Problème avec le tableau de la structure (Segmentation fault (core dumped)).
J'avait d'abord, un tableau de pointeurs de contact, puis je suis passé à juste un pointeur (vers un tableau de pointeurs de contact).
Mais je n'arrive pas à mettre le doigt sur le problème.
