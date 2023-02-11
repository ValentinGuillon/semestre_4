
COMMENT = \# #mettre \# pour ne pas exécuter certain "echo", et ne rien mettre pour les exécuter
SHOW = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS = POO
DEVOIR = TP3
PROGRAMMER = GUILLON-Valentin-20002588

SRC = src/
INCLUDE = include/

CC = g++
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = -r $(SRC) $(INCLUDE) makefile tp03.pdf exo1.cpp exo2.cpp exo3.cpp


COLOR_OPEN = \033[38;2;255;154;0m
COLOR_CLOSE = \033[0m
CFLAGS = -Wall -Wextra -std=c++17 -g
PROGS = exo1 exo2 exo3


# exemple:
# 	@$(COMMENT)echo "On va compiler exo"
# 	# $(SHOW)$(CC) $(CFLAGS) exo.c -o exo
# 	@echo "$(COLOR_OPEN)Compilation de exo$(COLOR_CLOSE)"


all: $(PROGS)


# il doit exister include/fonctions.h, src/fonctions.c et exo_avec_lib.c
# exo_avec_lib: libfonctions.a
# 	$(CC) $(CFLAGS) exo_avec_lib.c -I$(INCLUDE) -L. -lfonctions -o exo_avec_lib
# 	rm -f libfonctions.a

# libfonctions.a:
# 	$(CC) -c $(SRC)fonctions.c
# 	ar -rsc libfonctions.a fonctions.o
# 	find . -name "*.o" -delete



exo1:
	$(SHOW)$(CC) $(FLAGS) exo1.cpp -o exo1
	@echo "$(COLOR_OPEN)Compilation de exo1$(COLOR_CLOSE)"
	@echo "$(COLOR_OPEN)!!! exo1.cpp n'est pas correct$(COLOR_CLOSE)"
	

exo2:
	$(SHOW)$(CC) $(FLAGS) exo2.cpp -o exo2
	@echo "$(COLOR_OPEN)Compilation de exo2$(COLOR_CLOSE)"


exo3:
	$(SHOW)$(CC) $(FLAGS) exo3.cpp -o exo3
	@echo "$(COLOR_OPEN)Compilation de exo3$(COLOR_CLOSE)"



distdir: 
	$(SHOW)rm -rf $(DISTDIRNAME)
	$(SHOW)mkdir $(DISTDIRNAME)
	$(SHOW)cp $(FILESFORDIST) $(DISTDIRNAME)
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
	$(SHOW)find . -name "*.a" -delete
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de tous les .a$(COLOR_CLOSE)"
	$(SHOW)rm -f $(PROGS)
	@echo "$(COLOR_OPEN)Suppression de $(PROGS)$(COLOR_CLOSE)"
