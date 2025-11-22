# https://atcoder.jp/contests/abc427/tasks/abc427_a
# Sat Oct 18 07:19:16 2025
import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])

s = input()
for i in range(len(s)):
    if i != len(s)//2:
        print(s[i], end='')
print()
