# https://atcoder.jp/contests/abc399/tasks/abc399_a
# 2025年03月30日 01時06分18秒
import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])


def main():
    n = int(input())
    s = input()
    t = input()

    ans = 0
    for i in range(n):
        if s[i] != t[i]:
            ans += 1
    print(ans)


main()
