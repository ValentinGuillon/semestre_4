
COURS = ASD2
DEVOIR = TP2
PROGRAMMER = GUILLON-Valentin-20002588

FLAGS = -Wall -Wextra -g
PROGS= exo2-1 exo2-2 exo4



all: $(PROGS)


exo2-1:
	gcc $(FLAGS) exercice2-1.c -o exo2-1

exo2-2:
	gcc $(FLAGS) exercice2-2.c -o exo2-2
	@echo "!!! L'exercice2-2 n'est pas fait"

exo4:
	gcc $(FLAGS) exo4.c -o exo4



dist: clean
	zip -r [$(COURS)]_$(DEVOIR)_$(PROGRAMMER).zip .


clean: all
	@rm $(PROGS)
