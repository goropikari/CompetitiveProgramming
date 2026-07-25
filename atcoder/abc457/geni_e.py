import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random

n = random.randint(1, 10)
m = 10
print(n, m)

for i in range(m):
    l = random.randint(1, n)
    r = random.randint(1, n)
    if l > r:
        l, r = r, l
    print(l, r)

q = random.randint(1, 10)
print(q)
for i in range(q):
    l = random.randint(1, n)
    r = random.randint(1, n)
    if l > r:
        l, r = r, l
    print(l, r)
