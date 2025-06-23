# https://atcoder.jp/contests/past202212-open/tasks/past202212_f
# 2025年06月23日 18時33分46秒

n = int(input())
a, b, c, d = map(int, input().split())
x1, x2 = map(int, input().split('.'))
x = x1 * 1000+x2


def f(t):
    return (a+t+2*b+3*c+4*d) * 1000 <= (n+t)*x


ac = int(2e18+9)
wa = -1
while ac-wa > 1:
    wj = (ac+wa)//2
    if f(wj):
        ac = wj
    else:
        wa = wj

print(ac)
