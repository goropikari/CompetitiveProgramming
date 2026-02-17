import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random


def mass():
    if random.randint(0, 1) == 0:
        return '.'
    return '#'


H = random.randint(1, 10)
W = random.randint(1, 10)

grid = [
    "".join([mass() for i in range(W)])
    for j in range(H)
]

x = list(grid[0])
x[0] = '.'
grid[0] = ''.join(x)

obj = []
for i in range(H):
    for j in range(W):
        if grid[i][j] == '#':
            obj.append((i+1, j+1))

M = len(obj)
print(H, W, M)
for x in obj:
    print(*x)
