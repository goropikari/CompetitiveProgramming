import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])


import random
n = random.randint(1, 500)
x = [random.randint(1, 100) for i in range(n)]
print(n)
print(*x)
