
COURS = POO
DEVOIR = TP1
PROGRAMMER = Valentin-GUILLON_20002588

FLAGS = -std=c++17 -Wall -Wextra
PROGS = exo1 exo2 exo3 exo4-2 exo5

all: $(PROGS)



exo1:
	g++ annexe01.cpp $(FLAGS) -o exo1

exo2:
	g++ exo2.cpp $(FLAGS) -o exo2

exo3:
	g++ exo3.cpp $(FLAGS) -o exo3

exo4-2:
	g++ exo4-2.cpp $(FLAGS) -o exo4-2

exo5:
	g++ exo5.cpp $(FLAGS) -o exo5



dist: clean
	zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip .


clean:
	rm $(PROGS)

