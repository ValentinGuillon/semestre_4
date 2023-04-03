

import threading

LOCK = threading.RLock()

def somme(nbs):
    res = 0
    for nb in nbs:
        res += nb
    return res

def produit(nbs):
    res = 1
    for nb in nbs:
        res *= nb
    return res



class ThreadWithReturn(threading.Thread):
    def __init__(self, func, nbs:list):
        threading.Thread.__init__(self)
        self.func = func
        self.nbs:list = nbs
        self.res = None
    
    def run(self):
        res = self.func(self.nbs)
        self.res = res

    def join(self):
        threading.Thread.join(self)
        return self.res

    def return_production(self):
        return self.res





class Test(threading.Thread):
    def __init__(self, id:int):
        threading.Thread.__init__(self)
        self.id = id
    
    def run(self):
        i = 1000
        while True:
            print(f"{self.id}: i = {i}")
            i -= 1
            if i < 0:
                break






# nbs = [5, 2, 4, 8]
# nbs2 = [5, 1, 4, 8]


# thr1 = ThreadWithReturn(somme, nbs)
# thr2 = ThreadWithReturn(produit, nbs)

# thr1.start()
# thr2.start()

# a = thr1.return_production()
# b = thr2.return_production()

# print(a)
# print(b)



a = Test(1)
b = Test(2)

a.start()
b.start()

