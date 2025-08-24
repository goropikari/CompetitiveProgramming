import random

up = 100
a, b = random.randint(1, up), random.randint(1, up)
if a == b:
    b += 1
elif a > b:
    a, b = b, a

print(a, b)
