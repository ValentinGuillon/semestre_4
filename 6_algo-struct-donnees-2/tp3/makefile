
COMMENT = \##mettre \# pour ne pas exécuter certain "echo", et ne rien mettre pour les exécuter
SHOW = @#mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS = ASD2
DEVOIR = TP3
PROGRAMMER = GUILLON-Valentin-20002588

SRC = src/
INCLUDE = include/

CC = gcc
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = makefile ASD2_TD3.pdf exo1.c exo2.c


COLOR_CLOSE = \033[0m
COLOR_OPEN = $(COLOR_CLOSE)\033[38;2;255;154;0m
CFLAGS = -Wall -Wextra -g
PROGS = exo1 exo2


# exemple:
# 	@$(COMMENT)echo "On va compiler exo"
# 	# $(SHOW)$(CC) $(CFLAGS) exo.c -o exo
# 	@echo "$(COLOR_OPEN)Compilation de exo$(COLOR_CLOSE)"


all: clean $(PROGS)



exo1: tri_a_bulle_corrige.o
	$(SHOW)$(CC) $(FLAGS) $^ -I$(INCLUDE) exo1.c -o exo1
	@echo "$(COLOR_OPEN)Compilation de exo1$(COLOR_CLOSE)"

tri_a_bulle_corrige.o:
	$(SHOW)$(CC) $(FLAGS) -c $(SRC)tri_a_bulle_corrige.c -o tri_a_bulle_corrige.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de tri_a_bulle_corrige.o$(COLOR_CLOSE)"


exo2: arbre_binaire_abr.o
	$(SHOW)$(CC) $(FLAGS) $^ -I$(INCLUDE) exo2.c -o exo2
	@echo "$(COLOR_OPEN)Compilation de exo2$(COLOR_CLOSE)"

arbre_binaire_abr.o:
	$(SHOW)$(CC) $(FLAGS) -c $(SRC)arbre_binaire_abr.c -o arbre_binaire_abr.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de arbre_binaire_abr.o$(COLOR_CLOSE)"






distdir: 
	$(SHOW)if [ -d $(DISTDIRNAME) ]; then rm -rf $(DISTDIRNAME); fi
	$(SHOW)mkdir $(DISTDIRNAME)
	$(SHOW)cp $(FILESFORDIST) $(DISTDIRNAME)
	$(SHOW)if [ -d $(SRC) ]; then cp -r $(SRC) $(DISTDIRNAME); fi
	$(SHOW)if [ -d $(INCLUDE) ]; then cp -r $(INCLUDE) $(DISTDIRNAME); fi
	@$(COMMENT)echo "$(COLOR_OPEN)Regroupement de copie des fichiers dans $(DISTDIRNAME)$(COLOR_CLOSE)"

dist: clean distdir
	$(SHOW)rm -f [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de l'archive [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip$(COLOR_CLOSE)"
	$(SHOW)zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip $(DISTDIRNAME)
	@echo "$(COLOR_OPEN)Création du .zip terminée$(COLOR_CLOSE)"
	$(SHOW)rm -rf $(DISTDIRNAME)
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression du dir $(DISTDIRNAME)$(COLOR_CLOSE)"


clean:
	$(SHOW)find . -name "*.o" -delete
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de tous les .o$(COLOR_CLOSE)"
	$(SHOW)rm -f $(PROGS)
	@echo "$(COLOR_OPEN)Suppression de $(PROGS)$(COLOR_CLOSE)"
