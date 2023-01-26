#decomposer un nb en base 10 vers base b
import math

def base_10_to_2(n:int) -> int:
    #division euclidienne successives
    base_10:int = n
    base_2:int = 0
    digit:int = 0

    while (base_10 >= 1):
        reste = base_10 % 2
        base_10 //= 2
        base_2 += reste * math.pow(10, digit)
        digit += 1

    return int(base_2)
        
    
        
        

def base_10_to_b(n:int, base:int) -> int:
    base_2:int = base_10_to_2(n)
    base_b:int = 0
    digit:int = 0

    while (base_2):
        base_b += ((base_2 % 10) * base) * math.pow(10, digit)
        base_2 //= 10
        digit += 1

    return int(base_2)
        
        



    return 0



nb = 54
base = 8

nb_2 = base_10_to_2(nb)

print(f'{nb} base 2 = {nb_2}')



print(base_10_to_b(nb, 8))

    

#nb_b = base_10_to_b(nb, base)

#print(f'nb = {nb}\nbase = {base}\nnb_b = {nb_b}')



