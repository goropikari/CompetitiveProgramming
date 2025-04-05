import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

import random


def main():
    t = 1
    print(t)
    for i in range(t):
        n = random.randint(10, 20)
        s = ''.join(random.choice(['A', 'B']) for i in range(n))
        print(n)
        print(s)


main()
