
from crible import crible

def decompose(n:int) -> list:
    l:list[int] = crible(n)
    decompose:list[int] = []
    
    n_temp:int = n
    
    for diviseur in l:
        if n_temp == 1:
            decompose.insert(0, 1)
            break
        while n_temp % diviseur == 0:
            decompose.append(diviseur)
            n_temp / diviseur

    return decompose



def find_pgcd(a:int, b:int) -> int:
    a_decomp:list[int] = decompose(a)
    return 0
    #b_decomp:list[int] = decompose(b)
    


    if not len(a_decomp) or not len(b_decomp):
        print("ERROR")
        exit()

    if a_decomp[-1] > b_decomp[-1]:
        a_decomp.pop(-1)
    elif a_decomp[-1] < b_decomp[-1]:
        b_decomp.pop(-1)
    else:
        return b_decomp[-1]



print(find_pgcd(21, 15))
            

