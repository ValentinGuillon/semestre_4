
SHOW = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS = ASD2
DEVOIR = TP4
PROGRAMMER = GUILLON-Valentin-20002588

SRC = src/
INCLUDE = include/

CC = gcc
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = makefile tp4.c README.txt tp4_db.csv test.csv -r tp_documents/


COLOR_CLOSE = \033[0m
COLOR_OPEN = $(COLOR_CLOSE)\033[38;2;255;171;0m
CFLAGS = -Wall -Wextra -g #-std=c++17
PROGS = tp4


# exemple:
# 	# $(SHOW)$(CC) $(CFLAGS) exo.c -o exo
# 	@echo "$(COLOR_OPEN)Compilation de exo$(COLOR_CLOSE)"


all: clean $(PROGS) clean_soft
	@echo "La programme tp4 ne contient pas de test pour la table de hachage (voir READMDE)"
	@echo "Erreur si compilation avec tp4_db.csv"
	@echo "Compilez avec $(COLOR_OPEN)test.csv$(COLOR_CLOSE)"



tp4: linked_list.o hachage_table.o
	$(SHOW)$(CC) $(CFLAGS) -I$(INCLUDE) $^ tp4.c -o tp4
	@echo "$(COLOR_OPEN)Compilation de tp4$(COLOR_CLOSE)"

linked_list.o:
	$(SHOW)$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)linked_list.c -o linked_list.o

hachage_table.o:
	$(SHOW)$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)hachage_table.c -o hachage_table.o




distdir: 
	$(SHOW)if [ -d $(DISTDIRNAME) ]; then rm -rf $(DISTDIRNAME); fi
	$(SHOW)mkdir $(DISTDIRNAME)
	$(SHOW)cp $(FILESFORDIST) $(DISTDIRNAME)
	$(SHOW)if [ -d $(SRC) ]; then cp -r $(SRC) $(DISTDIRNAME); fi
	$(SHOW)if [ -d $(INCLUDE) ]; then cp -r $(INCLUDE) $(DISTDIRNAME); fi

dist: clean distdir
	$(SHOW)rm -f [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip
	$(SHOW)zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip $(DISTDIRNAME)
	@echo "$(COLOR_OPEN)Création du .zip terminée$(COLOR_CLOSE)"
	$(SHOW)rm -rf $(DISTDIRNAME)


clean_soft:
	$(SHOW)find . -name "*.o" -delete

clean:
	$(SHOW)find . -name "*.o" -delete
	$(SHOW)rm -f $(PROGS)
	@echo "$(COLOR_OPEN)Nettoyage terminé !$(COLOR_CLOSE)"





# ===============================================
# =============== FIN DU MAKEFILE ===============
# ===============================================




# processus pour compiler avec un fichier source et un header
# (ex: exo.c, src/fonctions.c et include/fonctions.h)
# FILESFORDIST = ... exo.c
# PROGS = ... exo

# exo: fonctions.o
# #on compile exo.c en y incluant $(SRC)fonctions.o
# #-I<nom_chemin>, permet d'indiquer où est le header (.h) de $(SRC)fonctions.c
# 	$(CC) $(CFLAGS) $(SRC)fonctions.o -I$(INCLUDE) exo.c -o exo

# fonctions.o:
# #génération de l'objet $(SRC)fonctions.o
# 	$(CC) $(CFLAGS) -c $(SRC)fonctions.c -o $(SRC)fonctions.o


# ou, plus concis, avec une dépendance implicite (rappel: $^== dépendances de la cible actuel)
# exo: $(SRC)fonctions.o
# 	$(CC) $(CFLAGS) $^ -I$(INCLUDE) exo.c -o exo







# processus pour compiler avec une librairie statique (.a)
# (ex: exo.c, src/fonctions.c et include/fonctions.h)
# FILESFORDIST = ... exo.c
# PROGS = ... exo

# exo: fonctions.a
# # création de l'éxécutable avec la librairie créé dans la cible libfonctions.a
# # puis suppression de celle-ci
# # options de la compilation; -I<dossier des .h> -L<dossier de la lib> (.a)> -l<nom de la lib> (à noter que la lib doit obligatoirement s'appeler "lib<nom>.a")
# 	$(CC) $(FLAGS) exo.c -I$(INCLUDE) -L. -lfonctions -o exo

# fonctions.a:
# 	$(CC) -c $(SRC)fonctions.c
# 	ar -rsc libfonctions.a fonctions.o
