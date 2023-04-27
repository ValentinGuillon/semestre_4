
#cryptage/décryptage d'entier utilisant la cryptographie RSA

import math
import random



def is_prime(var:int) -> bool:
    root = int(math.sqrt(var))
    for nb in range(2, root+1):
        if var % nb == 0:
            return 0
    return 1



def generate_random_int(minimal_borne:int) -> int:
    while True:
        generated = random.randint(minimal_borne, minimal_borne+9999)
        if is_prime(generated):
            break

    return generated



def inverse_mod(var:int, mod:int) -> int:
    print("inverse_mod: wtf ???")
    return 0

    # for i in range(2, mod):
    #     if res



    # res = math.pow(var, -1) % mod
    # return res

