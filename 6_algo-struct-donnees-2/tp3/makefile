
COMMENT = \# #mettre \# pour ne pas exécuter certain "echo", et ne rien mettre pour les exécuter
SHOW = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS = ASD2
DEVOIR = TP3
PROGRAMMER = GUILLON-Valentin-20002588

SRC = src/
INCLUDE = include/

CC = gcc
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = -r makefile $(SRC) $(INCLUDE) exo1.c exo2.c


COLOR_CLOSE = \033[0m
COLOR_OPEN = $(COLOR_CLOSE)\033[38;2;255;154;0m
CFLAGS = -Wall -Wextra -g
PROGS = exo1 exo2


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




exo1: libtri_a_bulle.a
	$(SHOW)$(CC) $(CFLAGS) exo1.c -I$(INCLUDE) -L. -ltri_a_bulle_corrige -o exo1
	@echo "$(COLOR_OPEN)Compilation de exo1$(COLOR_CLOSE)"
	$(SHOW)rm -f libtri_a_bulle_corrige.a
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de l'archive libtri_a_bulle_corrige.a$(COLOR_CLOSE)"

libtri_a_bulle.a:
	$(SHOW)$(CC) -c $(SRC)tri_a_bulle_corrige.c
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'objet tri_a_bulle_corrige.o$(COLOR_CLOSE)" 
	$(SHOW)ar -rsc libtri_a_bulle_corrige.a tri_a_bulle_corrige.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'archive libtri_a_bulle_corrige.a$(COLOR_CLOSE)"
	$(SHOW)find . -name "*.o" -delete
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de tous les .o$(COLOR_CLOSE)"




exo2: libarbre_binaire_abr.a
	$(SHOW)$(CC) $(CFLAGS) exo2.c -I$(INCLUDE) -L. -larbre_binaire_abr -o exo2
	@echo "$(COLOR_OPEN)Compilation de exo2$(COLOR_CLOSE)"
	$(SHOW)rm -f libarbre_binaire_abr.a
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de l'archive arbre_binaire_abr.a$(COLOR_CLOSE)"

libarbre_binaire_abr.a:
	$(SHOW)$(CC) -c $(SRC)arbre_binaire_abr.c
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'objet arbre_binaire_abr.o$(COLOR_CLOSE)" 
	$(SHOW)ar -rsc libarbre_binaire_abr.a arbre_binaire_abr.o
	@$(COMMENT)echo "$(COLOR_OPEN)Création de l'archive libarbre_binaire_abr.a$(COLOR_CLOSE)"
	$(SHOW)find . -name "*.o" -delete
	@$(COMMENT)echo "$(COLOR_OPEN)Suppression de tous les .o$(COLOR_CLOSE)"




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