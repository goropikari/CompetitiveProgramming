import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])


import random

n = random.randint(1, 7)
h = random.randint(1, 10)
w = random.randint(1, 10)

print(n, h, w)
for i in range(n):
    a = random.randint(1, 10)
    b = random.randint(1, 10)
    print(a, b)
