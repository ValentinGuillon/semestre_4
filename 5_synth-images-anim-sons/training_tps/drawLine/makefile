
HIDE = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS= nom_du_cours
DEVOIR= devoir_x
PROGRAMMER= GUILLON-Valentin-20002588

SRC= src/
INCLUDE= include/

DISTNAME= $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST= makefile *$(EXT) tp0_drawLineInBMP-1.0.zip resultat-attendu.png


COLOR_CLOSE= \033[0m
COLOR_OPEN= $(COLOR_CLOSE)\033[38;2;255;171;0m


CC= gcc#gcc or g++
EXT= .c#.c ou .cpp
EXTINCL= .h#.h ou .hpp
CFLAGS= -Wall -Wextra -g -fsanitize=address #-std=c++17
CPPFLAGS= -I. -I$(HOME)/local/include $(shell sdl2-config --cflags)
LDFLAGS= -lm -L$(HOME)/local/lib -lGL4Dummies $(shell sdl2-config --libs)
LIBS= -L/usr/lib/x86_64-linux-gnu -lsndfile -lm
PROGS = drawLine


# exemple:
# 	$(HIDE)$(CC) $(CFLAGS) $@$(EXT) -o $@
# 	@echo "$(COLOR_OPEN)$@ compiled.$(COLOR_CLOSE)"


all: clean $(PROGS) clean_soft
	./drawLine
	xdg-open resu.bmp
	@echo "$(COLOR_OPEN)drawCircle() not writed !!!$(COLOR_CLOSE)"


# cible: dependance
# 	commande



drawLine: images_io.o
	$(HIDE)$(CC) $(CFLAGS) $(CPPFLAGS) $^ -I$(INCLUDE) $@$(EXT) -o $@ -lm
	@echo "$(COLOR_OPEN)\"$@\" compiled.$(COLOR_CLOSE)"

images_io.o:
	$(HIDE)$(CC) $(CFLAGS) $(LIBS) $(LDFLAGS) -I$(INCLUDE)  -c $(SRC)images_io$(EXT) -o $@





distdir: 
	$(HIDE)if [ -d $(DISTNAME) ]; then rm -rf $(DISTNAME); fi
	$(HIDE)mkdir $(DISTNAME)
	$(HIDE)cp $(FILESFORDIST) $(DISTNAME)
	$(HIDE)if [ -d $(SRC) ]; then cp -r $(SRC) $(DISTNAME); fi
	$(HIDE)if [ -d $(INCLUDE) ]; then cp -r $(INCLUDE) $(DISTNAME); fi

dist: clean distdir
	$(HIDE)rm -f $(DISTNAME).zip
	$(HIDE)zip -r $(DISTNAME).zip $(DISTNAME)
	@echo "$(COLOR_OPEN)zip created.$(COLOR_CLOSE)"
	$(HIDE)rm -rf $(DISTNAME)


clean_soft:
	$(HIDE)find . -name "*.o" -delete

clean:
	$(HIDE)find . -name "*.o" -delete
	$(HIDE)rm -f $(PROGS)
	$(HIDE)rm -f resu.bmp
	@echo "$(COLOR_OPEN)Cleaned.$(COLOR_CLOSE)"





# ===============================================
# =============== FIN DU MAKEFILE ===============
# ===============================================




# processus pour compiler avec un fichier source et un header
# (ex: exo.c, src/fonctions.c et include/fonctions.h)
# PROGS = ... exo

# exo: fonctions.o
# #on compile exo.c en y incluant $(SRC)fonctions.o
# #-I<nom_chemin>, permet d'indiquer où est le header (.h) de $(SRC)fonctions.c
# 	$(CC) $(CFLAGS) $^ -I$(INCLUDE) $@$(EXT) -o $@

# fonctions.o:
# #génération de l'objet $(SRC)fonctions.o
# 	$(CC) $(CFLAGS) -c -I$(INCLUDE) $(SRC)fonctions.c -o $@







# processus pour compiler avec une librairie statique (.a)
# (ex: exo.c, src/fonctions.c et include/fonctions.h)
# PROGS = ... exo

# exo: fonctions.a
# # création de l'éxécutable avec la librairie créé dans la cible libfonctions.a
# # puis suppression de celle-ci
# # options de la compilation; -I<dossier des .h> -L<dossier de la lib> (.a)> -l<nom de la lib> (à noter que la lib doit obligatoirement s'appeler "lib<nom>.a")
# 	$(CC) $(CFLAGS) $@$(EXE) -I$(INCLUDE) -L. -lfonctions -o $@

# fonctions.a:
# 	$(CC) $(CFLAGS) -c $(SRC)fonctions.c -o fonctions.o
# 	ar -rsc lib$@ fonctions.o
