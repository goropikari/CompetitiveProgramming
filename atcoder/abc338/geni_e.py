import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random

n = random.randint(2, 100)
x = [i+1 for i in range(n*2)]

print(n)
for i in range(n):
    print(x[i*2], x[i*2+1])
