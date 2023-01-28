#decomposer un nb en base 10 vers base b
import math

# def base_10_to_2(n:int) -> int:
#     #division euclidienne successives
#     base_10:int = n
#     base_2:int = 0
#     digit:int = 0

#     while (base_10 >= 1):
#         reste = base_10 % 2
#         base_10 //= 2
#         base_2 += reste * math.pow(10, digit)
#         digit += 1

#     return int(base_2)


def convert_to_char(n:int) -> str:
    if n < 10:
        return str(n)
    
    letters:str = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    return letters[n-10]



def base_10_to_b(base_10:int, base:int) -> str:
    base_b:str = ''

    while (base_10):
        reste = int(base_10 % base)
        base_b = convert_to_char(reste) + base_b
        base_10 //= base

    if not len(base_b):
        return '0'
    return base_b




#wait an int input above the limit
def int_input(min_limit:int) -> int:
    var = -1
    while var < min_limit:
        var = int(input('>'))
    return var



while(1):
    #get inputs
    print('\n\nDonnez un nombre (base 10)')
    nb_10 = int_input(0)
    print(f'Dans quelle base convertir {nb_10} ?')
    base = int_input(2)

    #convert
    nb_b = base_10_to_b(nb_10, base)
    print(f'\n{nb_10}(10) = {nb_b}({base})')
