
HIDE = @ #mettre @ pour masquer les commandes dans le terminal, et ne rien mettre pour les afficher



COURS= synth-images-anim-sons
DEVOIR= $(PROG)
PROGRAMMER= GUILLON-Valentin-20002588

SRC= src/
INCLUDE= include/

DISTNAME= $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST= makefile *$(EXT) Monocraft.otf Pastless_remake.mp3 README


COLOR_CLOSE= \033[0m
COLOR_OPEN= $(COLOR_CLOSE)\033[38;2;255;171;0m


CC= gcc
EXT= .c
EXTINCL= .h
CFLAGS= -Wall -O3 -Wextra -g #-fsanitize=address
CPPFLAGS= -I. #-I$(HOME)/local/include $(shell sdl2-config --cflags)
LDFLAGS= -lm #-L$(HOME)/local/lib -lGL4Dummies $(shell sdl2-config --libs)

# !!! DO NOT REMOVE !!!
ifneq (,$(shell ls -d /usr/local/include 2>/dev/null | tail -n 1))
	CPPFLAGS += -I/usr/local/include
endif
ifneq (,$(shell ls -d $(HOME)/local/include 2>/dev/null | tail -n 1))
	CPPFLAGS += -I$(HOME)/local/include
endif
ifneq (,$(shell ls -d /usr/local/lib 2>/dev/null | tail -n 1))
	LDFLAGS += -L/usr/local/lib
endif
ifneq (,$(shell ls -d $(HOME)/local/lib 2>/dev/null | tail -n 1))
	LDFLAGS += -L$(HOME)/local/lib
endif
ifeq ($(shell uname),Darwin)
	MACOSX_DEPLOYMENT_TARGET = 10.8
        CFLAGS += -mmacosx-version-min=$(MACOSX_DEPLOYMENT_TARGET)
        LDFLAGS += -framework OpenGL -mmacosx-version-min=$(MACOSX_DEPLOYMENT_TARGET)
else
        LDFLAGS += -lGL
endif

CPPFLAGS += $(shell sdl2-config --cflags)
LDFLAGS  += -lGL4Dummies $(shell sdl2-config --libs) -lSDL2_mixer -lSDL2_ttf
# !!! DO NOT REMOVE !!! FIN

PROG = project
SOURCES = $(PROG).c
OBJ = $(SOURCES:.c=.o)


all: clean $(PROG) clean_soft
	# ./$(PROG)


# cible: dependance
# 	commande

# exemple:
# 	$(HIDE)$(CC) $(CFLAGS) $@$(EXT) -o $@
# 	@echo "$(COLOR_OPEN)$@ compiled.$(COLOR_CLOSE)"


$(PROG): $(OBJ)
	$(HIDE)$(CC) $(OBJ) $(LDFLAGS) -o $(PROG) -lm
	@echo "$(COLOR_OPEN)\"$@\" compiled.$(COLOR_CLOSE)"
%.o: %.c
	$(HIDE)$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -lm






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
	$(HIDE)rm -f $(PROG)
	@echo "$(COLOR_OPEN)Cleaned.$(COLOR_CLOSE)"





# ===============================================
# =============== FIN DU MAKEFILE ===============
# ===============================================




# processus pour compiler avec un fichier source et un header
# (ex: exo.c, src/fonctions.c et include/fonctions.h)
# PROG = ... exo

# exo: fonctions.o
# #on compile exo.c en y incluant $(SRC)fonctions.o
# #-I<nom_chemin>, permet d'indiquer où est le header (.h) de $(SRC)fonctions.c
# 	$(CC) $(CFLAGS) $^ -I$(INCLUDE) $@$(EXT) -o $@

# fonctions.o:
# #génération de l'objet $(SRC)fonctions.o
# 	$(CC) $(CFLAGS) -c -I$(INCLUDE) $(SRC)fonctions.c -o $@







# processus pour compiler avec une librairie statique (.a)
# (ex: exo.c, src/fonctions.c et include/fonctions.h)
# PROG = ... exo

# exo: fonctions.a
# # création de l'éxécutable avec la librairie créé dans la cible libfonctions.a
# # puis suppression de celle-ci
# # options de la compilation; -I<dossier des .h> -L<dossier de la lib> (.a)> -l<nom de la lib> (à noter que la lib doit obligatoirement s'appeler "lib<nom>.a")
# 	$(CC) $(CFLAGS) $@$(EXE) -I$(INCLUDE) -L. -lfonctions -o $@

# fonctions.a:
# 	$(CC) $(CFLAGS) -c $(SRC)fonctions.c -o fonctions.o
# 	ar -rsc lib$@ fonctions.o
