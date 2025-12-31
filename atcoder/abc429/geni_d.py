import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random

n = random.randint(3, 10)
m = random.randint(1, 5)
c = random.randint(1, n)

a = [random.randint(0, m-1) for i in range(n)]
print(n, m, c)
print(*a)
