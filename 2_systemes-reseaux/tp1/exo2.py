
import random


#coupe la trame en morceau de taille X
#retourne une liste composée de chaque morceau de la trame
def cut_trame(trame: str, block_lengh:int) -> list[str]:
    trame_cutted = []

    #on part de la fin (droite) du binaire
    i = len(trame)


    #on coupe de morceau de taille X (de droite à gauche), que l'on met au début de la liste
    while (i >= block_lengh):
        temp = trame[i-(block_lengh):i]
        trame_cutted.insert(0, temp)
        # trame_cutted.append(temp) #l'ordre des morceaux dans la liste ne changera rien à  la somme, je trouve juste plus joli que le dernier élément de la liste soit le dernier morceau du binaire
        i -= block_lengh

    #si jamais le dernier block (le plus à gauche) est plus petit que la taille X
    if (i):
        trame_cutted.insert(0, trame[:i])

    return(trame_cutted)



#retourne la somme de binaires
def block_sum(trame_cutted:list[str]) -> str:
    sum = 0

    for binaire in trame_cutted:
        sum += int(binaire, 2)

    return (bin(sum)[2:]) #[2:], car on veut retirer "0b" de la str



def complementaire(binaire:str) -> str:
    comp = ""
    for digit in binaire:
        if digit == '0':
            comp += '1'
        else:
            comp += '0'

    return comp



#ajoute des zéro en début de trame (si nécessaire)
def bourrage(trame:str, taille:int):
    while len(trame) % taille:
        trame = '0' + trame

    return trame




def checksum(trame: str, block_lengh:int) -> str:
    result:str = ""

    #on calcule la somme des morceaux de la trame coupée en morceaux de taille block_lengh
    #si cette somme est plus LONGUE que block_lengh, on continue le process avec la somme obtenu
    while True:
        trame_cutted:list[str] = cut_trame(trame, block_lengh)
        result = block_sum(trame_cutted)

        if len(result) <= block_lengh:
            break

        trame = result


    result = bourrage(result, block_lengh)

    #et on retourne le complément, évidemment
    return complementaire(result)






def print_bin(binaire:str, lengh_block: int) -> None:
    binaire = bourrage(binaire, lengh_block)

    for i, digit in enumerate(binaire, start=1):
        print(f"{digit}", end="")
        
        if i % lengh_block == 0 and i != len(binaire):
            print("_", end="")
    
    print()


def ask_for_input() -> tuple:
    trame = ""
    taille_block = 0

    user_says = input("\nVoulez-vous donner un nombre ? (y/n) (sinon, c'est random)\n>")
    if user_says == 'y':
        trame = input("Donnez une trame:\n>")
        taille_block = int(input("Taille des blocks\n>"))
    else:
        taille_trame = random.randint(8, 16)
        taille_block = random.randint(2, 8)

        for _ in range(taille_trame):
            trame += random.choice(['0', '1'])

    return trame, taille_block



def main():
    print("Ce programme effectue le checksum d'une trame")


    while 1:
        trame, taille_block = ask_for_input()

        trame_checksum = trame + checksum(trame, taille_block)

        check = checksum(trame_checksum, taille_block)

        print(f"trame: (block = {taille_block})\n  ", end="")
        print_bin(trame, taille_block)
        print(f"trame + checksum:\n  ", end="")
        print_bin(trame_checksum, taille_block)
        print(f"vérification:\n  ", end="")
        print_bin(check, taille_block)



if __name__ == "__main__":
    main()