import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])


import random


def main():
    n = random.randint(2, 5)
    a = [random.randint(1, 3) for i in range(n)]
    b = [random.randint(1, 3) for i in range(n)]
    print(n)
    print(*a)
    print(*b)


main()
