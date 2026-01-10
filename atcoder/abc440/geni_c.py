import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random
t = random.randint(1, 10)
print(t)

for i in range(t):
    n = random.randint(1, 10)
    w = random.randint(1, 20)
    c = [random.randint(2, 10) for i in range(n)]

    print(n, w)
    print(*c)
