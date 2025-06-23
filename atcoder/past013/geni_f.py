import random

a, b, c, d = [random.randint(0, 10**11) for i in range(4)]
n = a+b+c+d
x = random.randint(1001, 4000)

print(n)
print(a, b, c, d)
print(x//1000, end='')
print('.', end='')
print(x % 1000)
