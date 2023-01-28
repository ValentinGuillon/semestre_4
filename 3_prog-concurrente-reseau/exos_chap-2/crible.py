
import math
boucle = 0


def crible(n:int) -> list:

    square:int = int(math.sqrt(n))
    
    r:list[int] = [a for a in range(2, n + 1)]
    
    to_remove:list[int] = []
    for i in range(2, square + 1):
        if i in to_remove:
            continue

        if n % i == 0:
            for nb in r:
                if nb == i:
                    continue
                if nb % i == 0:
                    to_remove.append(i)
    
    for n in to_remove:
        r.remove(n)

    return r


#l = crible(30)

#print(l)
#print(boucle)


print("Crible d'Eratostène:")
a = int(input("Donnez un entier\n>"))

print(crible(a))

