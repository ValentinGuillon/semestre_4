FLAGS = -Wall -Wextra -std=c++17
PROGS = exo1 exo2

all: objects libpoint2.a $(PROGS)



objects:
	g++ -c point2.cpp

#création de l'archive
libpoint2.a: point2.o
	ar -rsc libpoint2.a point2.o
	rm *.o


exo1: exo1.cpp
	g++ $(FLAGS) exo1.cpp -L . -lpoint2 -o exo1

exo2: exo2.cpp
	g++ $(FLAGS) exo2.cpp -o exo2



clean:
	rm $(PROGS) libpoint2.a

