

COMMENT = \# #mettre \# pour ne pas afficher certain "echo", et ne rien mettre pour les afficher
COMMAND = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher


COURS = ASD2
DEVOIR = TP3
PROGRAMMER = GUILLON-Valentin-20002588

DIR_SRC = src/
DIR_INCLUDE = include/

CC = gcc
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = makefile exo1.c exo2.c $(DIR_SRC) $(DIR_INCLUDE)


COLOR_OPEN = \033[38;2;255;154;0m
COLOR_CLOSE = \033[0m
FLAGS = -Wall -Wextra -g
PROGS = exo1 exo2



all: $(PROGS)


#exo_avec_lib: libExos.a
#	$(CC) $(FLAGS) exo_avec_lib.cpp -L. -lExos -o exo_avec_lib
#
#libExos.a:
#	$(CC) -c exos.cpp
#	ar -rsc libExos.a exos.o
#	rm *.o




exo1: libtri_a_bulle.a
	$(COMMAND)$(CC) $(FLAGS) exo1.c -I$(DIR_INCLUDE) -L$(DIR_SRC) -ltri_a_bulle_corrige -o exo1
	@echo "$(COLOR_OPEN)Compilation de exo1$(COLOR_CLOSE)"
	$(COMMAND)rm -f $(DIR_SRC)libtri_a_bulle_corrige.a
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de l'archive $(DIR_SRC)libtri_a_bulle_corrige.a$(COLOR_CLOSE)"


libtri_a_bulle.a:
	$(COMMAND)$(CC) -c $(DIR_SRC)tri_a_bulle_corrige.c
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'objet tri_a_bulle_corrige.o$(COLOR_CLOSE)" 
	$(COMMAND)ar -rsc $(DIR_SRC)libtri_a_bulle_corrige.a tri_a_bulle_corrige.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'archive $(DIR_SRC)libtri_a_bulle_corrige.a$(COLOR_CLOSE)"
	$(COMMAND)find . -name "*.o" -delete
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de tous les .o$(COLOR_CLOSE)"



exo2: libarbre_binaire_abr.a
	$(COMMAND)$(CC) $(FLAGS) exo2.c -I$(DIR_INCLUDE) -L$(DIR_SRC) -larbre_binaire_abr -o exo2
	@echo "$(COLOR_OPEN)Compilation de exo2$(COLOR_CLOSE)"
	$(COMMAND)rm -f $(DIR_SRC)libarbre_binaire_abr.a
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de l'archive $(DIR_SRC)arbre_binaire_abr.a$(COLOR_CLOSE)"


libarbre_binaire_abr.a:
	$(COMMAND)$(CC) -c $(DIR_SRC)arbre_binaire_abr.c -o $(DIR_SRC)arbre_binaire_abr.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'objet $(DIR_SRC)arbre_binaire_abr.o$(COLOR_CLOSE)" 
	$(COMMAND)ar -rsc $(DIR_SRC)libarbre_binaire_abr.a $(DIR_SRC)arbre_binaire_abr.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'archive $(DIR_SRC)libarbre_binaire_abr.a$(COLOR_CLOSE)"
	$(COMMAND)find . -name "*.o" -delete
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de tous les .o$(COLOR_CLOSE)"




distdir: 
	$(COMMAND)rm -rf $(DISTDIRNAME)
	$(COMMAND)mkdir $(DISTDIRNAME)
	$(COMMAND)cp -r $(FILESFORDIST) $(DISTDIRNAME)
	@$(COMMENT)echo "$(COLOR_OPEN)Régroupement de copie des fichiers dans $(DISTDIRNAME)$(COLOR_CLOSE)"


dist: clean distdir
	$(COMMAND)rm -f [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de l'archive [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip$(COLOR_CLOSE)"
	$(COMMAND)zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip $(DISTDIRNAME)
	@echo "$(COLOR_OPEN)Création du .zip terminée$(COLOR_CLOSE)"
	$(COMMAND)rm -rf $(DISTDIRNAME)
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression du dir $(DISTDIRNAME)$(COLOR_CLOSE)"


clean:
	$(COMMAND)rm -f $(PROGS)
	@echo "$(COLOR_OPEN)Suppression de $(PROGS)$(COLOR_CLOSE)"
	$(COMMAND)find . -name "*.o" -delete
	@echo "$(COLOR_OPEN)Suppression de tous les .o$(COLOR_CLOSE)"
	$(COMMAND)rm -f $(DIR_SRC)libtri_a_bulle_corrige.a
	@echo "$(COLOR_OPEN)Suppression de $(DIR_SRC)libtri_a_bulle_corrige.a$(COLOR_CLOSE)"
