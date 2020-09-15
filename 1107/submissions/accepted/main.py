from sys import stdin


def soda(n, k):
    ans = 0
    while n >= k:
        ans += n // k
        n = n // k + n % k
    return ans


input()
for line in stdin.readlines():
    n, k = map(int, line.split())
    print(soda(n, k))
