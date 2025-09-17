import random

t = random.randint(1, 100)
print(t)
for i in range(t):
    n = random.randint(1, 2**59)
    k = random.randint(1, 60)
    print(n, k)
