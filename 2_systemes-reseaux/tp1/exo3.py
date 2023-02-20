
import random

FLAGS = "01111110"
ESC = "11100000"








def bourrage(trame:str, taille:int):
    while len(trame) % taille:
        trame = '0' + trame

    return trame

#retire les premiers 0 (zéro) de la trame
def debourrage(trame:str) -> str:
    new_trame = ""
    skip = True

    for digit in trame:
        if digit == "1":
            skip = False

        if not skip:
            new_trame += digit
            continue

    
    return new_trame


#ajoute un octet devant la trame
#cette octet est le nombre d'octet (+ lui même) dans la trame
def characterCount(trame:str) -> str:
    trame = bourrage(trame, 8)
    octets = 0

    i = 0

    for _ in trame:
        i += 1
        if i == 8:
            octets += 1
            i = 0

    print(f"trame has {octets}(+1) octets")
    new_octet = bin(octets+1)[2:]

    return new_octet + trame



#ajoute un zéro après cinq 1 (un) successif
# #ajoute les octets de drapeau avant et après la nouvelle trame 
def byteStuffing(trame:str) -> str:
    new_trame = ""
    successive_zero = 0

    for digit in trame:
        new_trame += digit

        if digit == "0":
            successive_zero = 0
            continue
        
        successive_zero += 1

        if successive_zero == 5:
            new_trame += "0"
            successive_zero = 0

    return bourrage(new_trame, 8)
    return FLAGS + bourrage(new_trame, 8) + FLAGS







def print_bin(binaire:str, lengh_block: int) -> None:
    binaire = bourrage(binaire, lengh_block)

    for i, digit in enumerate(binaire, start=1):
        print(f"{digit}", end="")
        
        if i % lengh_block == 0 and i != len(binaire):
            print("_", end="")
    
    print()






def main():
    #création d'une trame aléatoire, pour rigoler
    trame = ""
    taille_trame = random.randint(8, 300)

    for _ in range(taille_trame):
        trame += random.choice(['0', '1'])

    trame = debourrage(trame)
    trame_charCount = characterCount(trame)
    trame_byteStuffing = byteStuffing(trame)


    print("trame:\n  ", end="")
    print_bin(trame, 8)
    print(f"\nvérification characterCount():\n  ", end="")
    print_bin(trame_charCount, 8)
    print(f"\nvérification byteStuffing(): (sans octets de drapeau)\n  ", end="")
    print_bin(trame_byteStuffing, 8)



if __name__ == "__main__":
    main()