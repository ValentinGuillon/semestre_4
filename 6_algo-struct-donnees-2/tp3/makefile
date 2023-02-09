

COURS = ASD2
DEVOIR = TP3
PROGRAMMER = GUILLON-Valentin-20002588

DIR_SRC = src/
DIR_INCLUDE = include/

CC = gcc
DISTDIRNAME = $(COURS)_$(DEVOIR)_$(PROGRAMMER)
FILESFORDIST = makefile exo1-1.c $(DIR_SRC)* $(DIR_INCLUDE)* 


FLAGS = -Wall -Wextra -g
PROGS = exo1-1

all: $(PROGS)


#exo_avec_lib: libExos.a
#	$(CC) $(FLAGS) exo_avec_lib.cpp -L. -lExos -o exo_avec_lib
#
#libExos.a:
#	$(CC) -c exos.cpp
#	ar -rsc libExos.a exos.o
#	rm *.o


# exo1-1: $(SRC)tri_a_bulle_corrige.h
# 	$(CC) $(FLAGS) tri_a_bulle_corrige.o exo1-1.c -o exo1-1


exo1-1: libtri_a_bulle.a
	$(CC) $(FLAGS) exo1-1.c -I$(DIR_INCLUDE) -L$(DIR_SRC) -ltri_a_bulle_corrige -o exo1-1
	rm -f $(DIR_SRC)*.o $(DIR_SRC)*.a

libtri_a_bulle.a:
	$(CC) -c $(DIR_SRC)tri_a_bulle_corrige.c -o $(DIR_SRC)tri_a_bulle_corrige.o
	ar -rsc $(DIR_SRC)libtri_a_bulle_corrige.a $(DIR_SRC)tri_a_bulle_corrige.o





distdir: 
	rm -rf $(DISTDIRNAME)
	mkdir $(DISTDIRNAME)
	cp $(FILESFORDIST) $(DISTDIRNAME)


dist: clean distdir
	zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip $(DISTDIRNAME)
	rm -rf $(DISTDIRNAME)


clean:
	rm -f $(PROGS)
	rm -f $(DIR_SRC)/libtri_a_bulle_corrige.a

