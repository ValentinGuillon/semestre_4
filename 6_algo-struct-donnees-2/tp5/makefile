
SHOW = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS = ASD2
DEVOIR = TP5
PROGRAMMER = GUILLON-Valentin-20002588

SRC = src/
INCLUDE = include/

CC = gcc#gcc or g++
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = makefile *.c ASD2_TD5.pdf trajets_gare-du-nord_scenario-1.txt trajets_gare-du-nord_scenario-2.txt  #tout le contenu de $(SRC) et $(INCLUDE) est automatiquement ajouté aussi (cf cible "distdir")


COLOR_CLOSE = \033[0m
COLOR_OPEN = $(COLOR_CLOSE)\033[38;2;255;171;0m
CFLAGS = -Wall -Wextra -g -fsanitize=address #-std=c++17
PROGS = tp5


# exemple:
# 	# $(SHOW)$(CC) $(CFLAGS) exo.c -o exo
# 	@echo "$(COLOR_OPEN)Compilation de exo$(COLOR_CLOSE)"


all: clean $(PROGS) clean_soft


tp5: dijkstra.o
	$(SHOW)$(CC) $(CFLAGS) $@.c $^ -I$(INCLUDE) -o $@
	@echo "$(COLOR_OPEN)Compilation de $@$(COLOR_CLOSE)"


dijkstra.o:
	$(SHOW)$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)dijkstra.c


# cible: dependance
# 	commande



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
