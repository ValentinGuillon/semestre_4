

def sommeListe(numbers: list[int]) -> int:
	somme = 0
	for nb in numbers:
		somme += nb

	return somme


def mod2(number: int) -> int:
	while number >= 2:
		number -= 2

	return number



def paritePaire(trame: list[int]) -> list[int]:
	if mod2(sommeListe(trame)) == 0:
		trame.append(0)
		return trame
	trame.append(1)
	return trame


def pariteImpaire(trame: list[int]) -> list[int]:
	if mod2(sommeListe(trame)) == 1:
		trame.append(0)
		return trame
	trame.append(1)
	return trame




def checkedParitePaire(trame: list[int]) -> bool:
	#true s'il y'a un nombre PAIRE de 1
	if mod2(sommeListe(trame)) == 0:
		return True
	return False


def checkedPariteImpaire(trame: list[int]) -> bool:
	#true s'il y'a un nombre IMPAIRE de 1
	if mod2(sommeListe(trame)) == 1:
		return True
	return False







def analyse(trame:list[int]) -> None:

	if checkedParitePaire(trame):
		print(trame, "est paire")
	else:
		print(trame, "n'est pas paire")

	if (checkedPariteImpaire(trame)):
		print(trame, "est impaire")
	else:
		print(trame, "n'est pas impaire")




def main():
	a = [1, 0, 1, 1] #impaire
	b = [1, 0, 0, 1] #paire

	a_p = paritePaire(a.copy())
	b_p = paritePaire(b.copy())

	a_i = pariteImpaire(a.copy())
	b_i = pariteImpaire(b.copy())


	print(f"trame de base: {a}")
	analyse(a)
	print("parité paire:")
	analyse(a_p)
	print("parité impaire:")
	analyse(a_i)

	print("\n")
	print(f"trame de base: {b}")
	analyse(b)
	print("parité paire:")
	analyse(b_p)
	print("parité impaire:")
	analyse(b_i)










if __name__ == "__main__":
	main()

