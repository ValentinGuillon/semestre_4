
SHOW = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS = POO
DEVOIR = TP3
PROGRAMMER = GUILLON-Valentin-20002588

SRC = src/
INCLUDE = include/

CC = g++ #gcc or g++
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = makefile tp03.pdf exo1.cpp exo2.cpp exo3.cpp exo4.cpp


COLOR_CLOSE = \033[0m
COLOR_OPEN = $(COLOR_CLOSE)\033[38;2;255;171;0m
CFLAGS = -Wall -Wextra -g -std=c++17
PROGS = exo4


# exemple:
# 	# $(SHOW)$(CC) $(CFLAGS) exo.c -o exo
# 	@echo "$(COLOR_OPEN)Compilation de exo$(COLOR_CLOSE)"


all: clean $(PROGS)
	@echo "$(COLOR_OPEN)!!! exo1 à corriger$(COLOR_CLOSE)"


# cible: dependance
# 	commande


exo1:
	$(SHOW)$(CC) $(FLAGS) exo1.cpp -o exo1
	@echo "$(COLOR_OPEN)Compilation de exo1$(COLOR_CLOSE)"
	

exo2:
	$(SHOW)$(CC) $(FLAGS) exo2.cpp -o exo2
	@echo "$(COLOR_OPEN)Compilation de exo2$(COLOR_CLOSE)"


exo3:
	$(SHOW)$(CC) $(FLAGS) exo3.cpp -o exo3
	@echo "$(COLOR_OPEN)Compilation de exo3$(COLOR_CLOSE)"


exo4:
	$(SHOW)$(CC) $(FLAGS) exo4.cpp -o exo4
	@echo "$(COLOR_OPEN)Compilation de exo4$(COLOR_CLOSE)"






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
