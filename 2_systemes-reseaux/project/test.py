

import threading
import time

LOCK = threading.RLock()


def wait_close_input():
    while True:
        a = str(input("At any moment, type \"STOP\" to close the server.\n"))
        print(a)
        if a == "STOP":
            break


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
    def __init__(self, id:str):
        threading.Thread.__init__(self)
        self.id:str = id
        self.stop_thread = False
    


    def run(self):
        i = 0
        while True:
            if self.stop_thread:
                break

            with LOCK:
                print(f"{self.id}: i = {i}")
                time.sleep(1)
                i += 1
                if i > 1000:
                    break


        print(f"threat {self.id} has closed\n")
        return
    
    def end(self):
        self.stop_thread = True






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



stop = threading.Thread(target=wait_close_input)
stop.start()


a = Test("a")
b = Test("b")

a.start()
b.start()


stop.join()

a.end()
b.end()


