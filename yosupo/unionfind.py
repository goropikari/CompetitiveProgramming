# http://localhost:5173/problem/unionfind
# 2025年03月25日 03時18分43秒

import sys
sys.setrecursionlimit(999999999)


class UnionFind:
    def __init__(self, n):
        self.data = [-1] * n

    def leader(self, x):
        if self.data[x] < 0:
            return x
        self.data[x] = self.leader(self.data[x])
        return self.data[x]

    def merge(self, a, b):
        a = self.leader(a)
        b = self.leader(b)
        if a == b:
            return
        self.data[a] = b

    def same(self, a, b):
        return self.leader(a) == self.leader(b)


n, q = map(int, input().split())
uf = UnionFind(n)

for i in range(q):
    t, u, v = map(int, input().split())
    if t == 0:
        uf.merge(u, v)
    else:
        if uf.same(u, v):
            print(1)
        else:
            print(0)
