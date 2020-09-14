import random
from sys import argv

n = int(argv[1])
print(n)
a = [x + 1 for x in range(n)]
a = a + a
random.shuffle(a)
del a[-1]
print(*a)
