
#Le plus important à mettre à jour si on ajoute un fichier à son dossier:
#    rajouter le nom du fichier dans FILESFORDIST=

COURS = nom_du_cours
DEVOIR = TPx
PROGRAMMER = NOM-Prenom-nEtudiant

SRC = src/ #dossier dans lequel on met les fichiers sources
INCLUDE = include/ #dossier dans lequel on met les headers

CC = gcc #ou g++
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER) #nom du dossier pour la création de l'archive
FILESFORDIST = -r $(DIR_SRC) $(DIR_INCLUDE) #+ exo_test.c exo1.c exo2.c ... #liste des fichiers à mettre dans le zip. Le -r permet de récupérer les fichiers qui sont dans des dossiers, et ainsi garder le même rangement dans l'archive

CFLAGS = -Wall -Wextra -g
PROGS = #exo_test exo1 exo2 ...  #liste des exécutables. Faire en sort que chaque exé ai sa cible dans le makefile



all: $(PROGS) #exo_avec_lib


# processus de compilation pour une seul fichier .c

# exo_test:
# 	$(CC) $(CFLAGS) exo_test.c -o exo_test




# processus pour compiler avec une librairie static
# (il doit exister include/fonctions.h, src/fonctions.c et exo_avec_lib.c)

exo_avec_lib: libfonctions.a
#création de l'éxécutable avec la librairie créé dans la cible libfonctions.a
#puis suppression de celle-ci
#options de la compilation; -I<dossier des .h> -L<dossier de la lib (.a)> -l<nom de la lib> (à noter que la lib doit obligatoirement s'appeler "lib<nom>.a")
	$(CC) $(FLAGS) exo_avec_lib.c -I$(INCLUDE) -L. -lfonctions -o exo_avec_lib
	rm -f libfonctions.a

libfonctions.a:
	$(CC) -c $(SRC)fonctions.c
	ar -rsc libfonctions.a fonctions.o
	find . -name "*.o" -delete





distdir:
#supprime le dossier dans lequel on met les copies de se qu'on va zip
#on recréer le dossier
#on y met les copies des fichiers à mettre dans le zip
	rm -rf $(DISTDIRNAME)
	mkdir $(DISTDIRNAME)
	cp $(FILESFORDIST) $(DISTDIRNAME)


dist: clean distdir
#on zip le dossier qu'on a remplit dans la cible distdir
#on supprime le dossier
	zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip $(DISTDIRNAME)
	rm -rf $(DISTDIRNAME)


clean:
# suppression des tous les .o
# suppression des tous les .a
# suppression des tous les executable (mentionnés dans PROGS=)
	find . -name "*.o" -delete
	find . -name "*.a" -delete
	rm -f $(PROGS)
