import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])


import random

n = 6
m = 2

a = [(0, 0) for i in range(m)]
b = [(random.randint(-10, 10), random.randint(-10, 10))
     for i in range(n-m)]
v = a + b
random.shuffle(v)

print(n)
for t in v:
    print(t[0], t[1])
