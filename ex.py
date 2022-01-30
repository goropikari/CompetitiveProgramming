a, b = map(int, input().split())

def gcd(a, b):
    if (b == 0): return a
    return gcd(b, a%b)

def lcm(a,b):
    return a * b // gcd(a,b)

ans = lcm(a,b)
if ans > 1e18:
    print("Large")
else:
    print(ans)
