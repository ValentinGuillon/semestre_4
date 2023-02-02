FLAGS = -Wall -Wextra -g
PROGS = fuite structbug test_liste
#menu


all: $(PROGS)




liste:
	gcc $(FLAGS) liste.c -o liste

menu:
	gcc $(FLAGS) menu.c -o menu

structbug:
	gcc $(FLAGS) structbug.c -o structbug

test_liste: libliste.a
	gcc $(FLAGS) test_liste.c -L. -lliste -o test_liste





#création de l'archive pour test_liste.c
libliste.a:
	gcc -c liste.c
	ar -rsc libliste.a liste.o
	rm *.o




clean:
	rm $(PROGS) libliste.a

