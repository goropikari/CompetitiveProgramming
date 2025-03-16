import random
n = random.randint(1, 100)
k = random.randint(1, 1000)
x = [random.randint(1, int(2e9)) for i in range(n)]
print(n, k)
print(' '.join(map(str, x)))
