import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random

n = random.randint(1, 10**12)
k = min(random.randint(0, 10**6), n)

print(n, k)
