import random

n = random.randint(1, 20)
a = random.randint(1, 10**9)
b = random.randint(1, 10**9)
print(n, a, b)

s = ''.join([random.choice(['(', ')']) for i in range(n*2)])
print(s)
