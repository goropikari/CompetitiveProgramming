N, M, K = map(int, input().split())

x = set()
for i in range(1,200):
    a = N * i
    if a % M == 0:
        continue
    x.add(a)
for i in range(1,200):
    a = M * i
    if a % N == 0:
        continue
    x.add(a)

l = list(x)
l.sort()
print(l[K-1])
