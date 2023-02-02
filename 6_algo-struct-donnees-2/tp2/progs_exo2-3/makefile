
FLAGS= -Wall -Wextra -g
PROGS= test_liste



all: $(PROGS)


test_liste: libliste.a
	gcc $(FLAGS) test_liste.c -L. -lliste -o test_liste

libliste.a:
	gcc -c liste.c
	ar -rsc libliste.a liste.o
	rm *.o





clean:
	@rm libliste.a $(PROGS)
