n, target = map(int, input().split())
a = map(int, input().split())

S = set([0])
ans = 0
for x in a:
    if target - x in S:
        ans += 1
    S.add(x)
print(ans)
