import random
import string

n = random.randint(1, 100)
k = random.randint(1, n)

s = ''.join(random.choices(string.ascii_lowercase, k=n))
print(n, k)
print(s)
