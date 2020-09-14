from sys import stdin

input()
a = map(int, stdin.readline().split())

ans = 0
for x in a:
    ans ^= x
print(ans)
