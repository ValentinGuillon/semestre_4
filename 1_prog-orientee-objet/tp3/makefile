
COURS = POO
TP = TP3
NAME = Valentin-GUILLON-20002588
FLAGS = -Wall -Wextra -std=c++17
PROGS = exo1


all: $(PROGS)

# exo1: lib_point2.a
# 	g++ $(FLAGS) exo1.cpp -L. -lpoint2 -o exo1

# lib_point2.a:
# 	g++ -c point2.cpp
# 	ar -rsc libpoint2.a point2.o
# 	rm *.o



exo1:
	g++ $(FLAGS) exo1.cpp -o exo1




dist: clean
	zip -r [$(COURS)]_$(TP)_$(NAME).zip .

clean: all
	rm $(PROGS)


