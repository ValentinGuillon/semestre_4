


def binary_add(a:str, b:str) -> str:
    #on retourne les binaires
    a = a[::-1]
    b = b[::-1]
    resultat = ""
    retenu = 0

    size_a = len(a)
    size_b = len(b)

    #on ajoute des zéros dans le plus court binaire
    if size_a > size_b:
        for _ in range(size_a - size_b):
            b += "0"
    elif size_b > size_a:
        for _ in range(size_b - size_a):
            a += "0"
            

    #on additionne
    for i in range(max(size_a, size_b)):
        temp_r =  int(a[i]) + int(b[i]) + retenu

        if temp_r > 1:
            resultat += str(temp_r - 2)
            retenu = 1
        else:
            resultat += str(temp_r)
            retenu = 0

    #on ajoute la dernière retenu
    if retenu:
        resultat += "1"

    return resultat[::-1]




def binary_subtract(a:str, b:str) -> str:
    
    return '0'







#retourne une version "octetisé" d'un binaire (ex:10 -> 00000010)
def to_octets(binary:str) -> str:
    add = 8 - len(binary) % 8
    for _ in range(add):
        binary = "0" + binary
    return binary

def remove_useless_0(binary:str) -> str:
    if binary == "0":
        return binary

    while binary[0] == '0':
        binary = binary[1:]
    
    return binary


while 1:
    #les inputs
    bin_a = to_octets(input("\n\nDonnez un binaire\n>"))
    bin_b = to_octets(input("Un autre\n>"))

    #calcules
    bin_add = binary_add(bin_a, bin_b)
    bin_sub = binary_subtract(bin_a, bin_b)

    #préparation des espaces pour l'affichage
    bin_a = remove_useless_0(bin_a)
    bin_b = remove_useless_0(bin_b)
    bin_add = remove_useless_0(bin_add)
    bin_sub = remove_useless_0(bin_sub)


    space = len(bin_a) - len(bin_b)
    add_space = len(bin_add) - max(len(bin_a), len(bin_b))
    sub_space = len(bin_sub) - max(len(bin_a), len(bin_b))

    #affichage
    print(f"{bin_a} - {bin_b} = {bin_sub}")

    #...add
    print("\n\n  ", end="")
    for _ in range(add_space):
        print(" ", end="")
    if space < 0:
        for _ in range((-1 * space)):
            print(" ", end="")
    print(f"{bin_a}\n+ ", end="")
    for _ in range(add_space):
        print(" ", end="")
    if space > 0:
        for _ in range(space):
            print(" ", end="")
    print(f"{bin_b}\n= {bin_add}")

    #...sub
    print("\n\n  ", end="")
    for _ in range(sub_space):
        print(" ", end="")
    if space < 0:
        for _ in range((-1 * space)):
            print(" ", end="")
    print(f"{bin_a}\n+ ", end="")
    for _ in range(sub_space):
        print(" ", end="")
    if space > 0:
        for _ in range(space):
            print(" ", end="")
    print(f"{bin_b}\n= {bin_sub}")

