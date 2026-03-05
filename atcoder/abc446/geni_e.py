import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random

m = random.randint(2, 1000)
a = random.randint(0, m-1)
b = random.randint(0, m-1)
print(m, a, b)
