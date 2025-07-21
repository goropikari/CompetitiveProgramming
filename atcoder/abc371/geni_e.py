import random

n = random.randint(1, 100)
x = [random.randint(1, n) for i in range(n)]
print(n)
print(*x)
