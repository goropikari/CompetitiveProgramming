import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random
n = random.randint(1, 1000)
m = random.randint(1, 3000)

print(n, m)
for i in range(m):
    a = random.randint(1, m)
    b = random.randint(1, 10**9)
    print(a, b)
