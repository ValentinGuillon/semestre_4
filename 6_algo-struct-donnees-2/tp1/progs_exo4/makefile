FLAGS = -Wall -Wextra -g
PROGS = fuite structbug test_liste
#menu


all: objects libliste.a $(PROGS)



#génération des fichiers objets des fichiers sources
objects:
	gcc -c liste.c

#création de l'archive
libliste.a: liste.o
	ar -rsc libliste.a liste.o
	rm *.o




liste: liste.c
	gcc $(FLAGS) liste.c -o liste

menu: menu.c
	gcc $(FLAGS) menu.c -o menu

structbug: structbug.c
	gcc $(FLAGS) structbug.c -o structbug

test_liste: test_liste.c
	gcc $(FLAGS) test_liste.c -L. -lliste -o test_liste


clean:
	rm $(PROGS) libliste.a

