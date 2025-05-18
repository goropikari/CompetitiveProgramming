# https://atcoder.jp/contests/abc406/tasks/abc406_b
# 2025年05月17日 21時08分06秒
import sys
if len(sys.argv) == 2:
    sys.stdin = open(sys.argv[1])


def main():
    n, k = map(int, input().split())
    a = map(int, input().split())

    mx = 10**k
    ans = 1
    for i in a:
        ans *= i
        if ans >= mx:
            ans = 1

    print(ans)

main()
