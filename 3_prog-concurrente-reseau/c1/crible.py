
import math
boucle = 0


def crible(n:int) -> list:
    global boucle

    square:int = int(math.sqrt(n))
    
    r:list[int] = [a for a in range(2, n + 1)]
    
    for i in range(2, square + 1):
        #print(r)
        boucle += 1
        if n % i == 0:
            for nb in r:
                boucle += 1
                if nb == i:
                    continue
                if nb % i == 0:
                    r.remove(nb)

    return r


#l = crible(30)

#print(l)
#print(boucle)


