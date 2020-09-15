from random import *
from sys import argv

def rd():
    t = 10**5
    print(t)

    for _ in range(t):
        n = randint(0, 2147483647)
        k = randint(2, 2147483647)
        print(n, k)

def rd2():
    t = 10**5
    print(t)

    for _ in range(t):
        n = randint(0, 2147483647)
        k = randint(2, 100)
        print(n, k)


rd2()
