from random import *
from sys import argv


def rd():
    a = [randint(0, 10**9) for i in range(10**5)]
    a = list(set(a))
    shuffle(a)
    n = len(a)
    print(len(a), a[0] + a[randint(0, n - 1)])
    print(*a)

def rd2():
    a = [randint(0, 10**5) for i in range(10**5)]
    a = list(set(a))
    shuffle(a)
    n = len(a)
    print(len(a), randint(0, 2*10**5))
    print(*a)

rd2()
