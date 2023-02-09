
COURS = POO
TP = TP3
NAME = Valentin-GUILLON-20002588
FLAGS = -Wall -Wextra -std=c++17
PROGS = exo1


all: $(PROGS)

#exo_avec_lib: libExos.a
#	g++ $(FLAGS) exo_avec_lib.cpp -L. -lExos -o exo_avec_lib
#
#libExos.a:
#	g++ -c exos.cpp
#	ar -rsc libExos.a exos.o
#	rm *.o



exo1:
	g++ $(FLAGS) exo1.cpp -o exo1




dist: clean
	zip -r [$(COURS)]_$(TP)_$(NAME).zip .

clean: all
	@rm $(PROGS)
	#@rm libExos.a
