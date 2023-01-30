
COURS = [POO]
TP = TP2
NAME = Valentin-GUILLON-20002588
FLAGS = -Wall -Wextra -std=c++17
PROGS = exo1 exo2


all: $(PROGS)




exo1: lib_point2.a
	g++ $(FLAGS) exo1.cpp -L. -lpoint2 -o exo1

exo2: lib_personne.a
	g++ $(FLAGS) exo2.cpp -L. -lpersonne_t -o exo2


lib_point2.a:
	g++ -c point2.cpp
	ar -rsc libpoint2.a point2.o
	rm *.o

lib_personne.a:
	g++ -c personne_t.cpp
	ar -rsc libpersonne_t.a personne_t.o
	rm *.o




dist: clean
	zip -r $(COURS)_$(TP)_$(NAME).zip .

clean: all
	rm $(PROGS) libpoint2.a libpersonne_t.a


