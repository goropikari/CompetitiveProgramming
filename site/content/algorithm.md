+++
title = "Algorithm"
date = "2021-12-12"
tags = ["algorithm"]
+++

# Algorithm


## int <-> string

```cpp
to_string(int) -> string
to_string(ll) -> string
stoi(string) -> int
stoll(string) -> ll
```


## priority queue

昇順
```cpp
#include <iostream>
#include <queue>

int main()
{
  // intを要素に持つ優先順位付きキュー.
  // 降順に処理する
  std::priority_queue<int> que;

  // データを追加する
  que.push(3);
  que.push(1);
  que.push(4);

  // 処理順に出力する
  while (!que.empty()) {
    std::cout << que.top() << std::endl;
    que.pop();
  }
}
```

```
4
3
1
```

降順に出力
```cpp
#include <iostream>
#include <queue>

int main()
{
  // intを要素に持つ優先順位付きキュー.
  // 降順に処理する
  std::priority_queue<int, vector<int>, greater<int>> que;

  // データを追加する
  que.push(3);
  que.push(1);
  que.push(4);

  // 降順順に出力する
  while (!que.empty()) {
    std::cout << que.top() << std::endl;
    que.pop();
  }
}
```

```
1
3
4
```


struct で priority queue

```cpp
struct Point {
    int x, y;
};

bool operator<(const Point& a, const Point& b)
{
    return a.x < b.x;
}

bool operator>(const Point& a, const Point& b)
{
    return a.x > b.x;
}

void solve()
{
    {
        // operator< が必要
        priority_queue<Point> pq;
        rep(i, 3) pq.push({ i, 3 - i });

        while (pq.size()) {
            auto [x, y] = pq.top();
            pq.pop();
            cout << x << ' ' << y << endl;
        }
    }

    cout << endl;
    {
        // operator> が必要
        priority_queue<Point, vector<Point>, greater<Point>> pq;
        rep(i, 3) pq.push({ i, 3 - i });

        while (pq.size()) {
            auto [x, y] = pq.top();
            pq.pop();
            cout << x << ' ' << y << endl;
        }
    }
}
```

```
2 1
1 2
0 3

0 3
1 2
2 1
```

## sort

自作 struct に関して sort する.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hoge {
    int x, y;
};

bool compare(Hoge a, Hoge b) { return a.y > b.y; }

int main(int argc, char* argv[])
{
    vector<Hoge> v = { {0, 1}, {1, 9} };

    sort(v.begin(), v.end(), compare);

    for (Hoge item : v) {
        cout << item.x << " " << item.y << endl;
    }
    return 0;
}
```

```
1 9
0 1
```

## ceil, floor

$x / y$ が負のときにも対応

```cpp
// ceil(x/y)
ll ceil(ll x, ll y) {
    if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
        x = abs(x), y = abs(y);
        return (x + y - 1) / y;
    }

    // x/y が負の数のときは整数除算の x/y が切り上げになる
    return x / y;
}

// floor(x/y)
ll floor(ll x, ll y) {
    if ((x > 0 && y < 0) || (x > 0 && y < 0)) {
        if (x % y != 0) return x / y - 1;
    }

    return x / y;
}
```

## 未満

$s, x, P$ が正整数のとき

$$
s < \frac{P}{x} \iff s < \floor{ \frac{P+x-1}{x} }
$$

が成り立つ。

$(\rightarrow)$

$$
s < \frac{P}{x} \rightarrow sx < P \rightarrow sx + 1 \leq P ~(\because s, x, P \text{ are positive integers})
$$

$f(P) = \floor{ \frac{P+x-1}{x} }$ とすると $f(P)$ は non-decreasing fn だから

$$
f(sx+1) \leq f(P) \\\\
\therefore \floor{  \frac{(sx+1)+x-1}{x}  } \leq f(P) \\\\
\therefore \floor{  \frac{sx + x}{x}  } \leq f(P) \\\\
\therefore \floor{  s+1  } \leq f(P) \\\\
\therefore   s+1  \leq f(P) \\\\
\therefore   s < s+1  \leq f(P) \\\\
\therefore   s < f(P)
$$


$(\leftarrow)$

$f(sx) = \floor{ \frac{sx + x-1}{x} } = \floor{ s + \frac{x-1}{x} } = s + \floor{ \frac{x-1}{x} } = s$

$f(sx+1) = s+1$

より $s < f(P)$ ならば
$$
sx+1 \leq P \\\\
\therefore sx < sx+1 \leq P \\\\
\therefore sx < P \\\\
\therefore s < \frac{P}{x}
$$

ref: https://atcoder.jp/contests/abc384/tasks/abc384_e

## gcd, lcm

$\mathrm{gcd}(a, b) = \mathrm{gcd}(b, a \\% b)$.

$\displaystyle \mathrm{lcm}(a,b) = \frac{a \times b}{\mathrm{gcd}(a,b)}$


Suppose $d = \mathrm{gcd}(a,b)$. This means $a = k_1 d$ and $b = k_2 d$ for some integers $k_1, k_2 \in \Z$.

$a = qb + r$ $(0 \leq r < b)$, for some integer $q$.

Then $a\\% b = r = a - qb = d(k_1 - qk_2)$.


```cpp
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}
```

## cumsum

```cpp
template<typename T>
vector<T> cumsum(vector<T> v) {
    int n = v.size();
    rep2(i,1,n) v[i] += v[i-1];
    return v;
}
```

## べき乗計算(冪乗)
### 高速べき乗計算

$x^n$ を高速に求める

```cpp
// x^n
ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}
```

ref: [逆元](#逆元)


### 逆元

ref: [「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a)


#### exponential mod

```cpp
// べき乗 mod
// x^n mod m
ll modpow(ll x, ll n, ll mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}
```

フェルマーの小定理より素数 $p$ に対して $a^{p-1} \equiv 1 \mod p$ であるから
$a^{-1} \equiv a^{p-2} \mod p$

```cpp
// べき乗 inv mod
// x^{-1} mod m
ll modinv(ll x, ll mod) {
    return modpow(x, mod-2, mod);
}
```


## 素数

### エラトステネスのふるい

```cpp
int MAX = 100005;
vector<int> isprime(MAX, true);
isprime[0] = isprime[1] = false;
for (int i = 2; i < MAX; i++) {
    if (isprime[i]) {
        for (int j = i+i; j < MAX; j+=i) {
            isprime[j] = false;
        }
    }
}
```


## 行列

$H \times W$ の行列 $A$ を考える.
$A$ に以下の操作を加えたでできた行列を $A^\prime$ とする.
このとき $A^\prime$ の $(i^\prime, j^\prime)$ 成分と $A$ の $(i,j)$ 成分の対応は以下の通りである.

各操作を愚直に行うと $O(HW)$ かかるが, index のみを更新することで $O(H+W)$ に計算量を落とすことができる.

### rotr90

$
i^\prime = j \\\\
j^\prime = H - 1 - i
$

### rotl90

$
i^\prime = W - 1 - j \\\\
j^\prime = i
$

### transpose

$
i^\prime = j \\\\
j^\prime = i
$

### 上下反転

$
i^\prime = H - 1 - i \\\\
j^\prime = j
$

### 左右反転
$$
i^\prime = i \\\\
j^\prime = W - 1 - j
$$

```cpp
#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
struct Matrix {
    Matrix(int h, int w): isSwap(false), H(h), W(w), grid(h, vector<T>(w,0)), xid(h), yid(w) {
        rep(i,h) xid[i] = i;
        rep(i,w) yid[i] = i;
    }


    T find(int x, int y) {
        P p = index(x,y);
        return grid[p.first][p.second];
    }

    void set(int x, int y, T val) {
        P p = index(x,y);
        grid[p.first][p.second] = val;
    }

    void rotr90() {
        isSwap = !isSwap;
        vector<int> new_yid(H);
        rep(i,H) new_yid[i] = H - 1 - xid[i];
        swap(H, W);
        xid = yid;
        yid = new_yid;
    }

    void rotl90() {
        isSwap = !isSwap;
        vector<int> new_xid(W);
        rep(i,W) new_xid[i] = W - 1 - yid[i];
        swap(H, W);
        yid = xid;
        xid = new_xid;
    }

    void topbottom() {
        rep(i,H/2) swap(xid[i], xid[H-1-i]);
    }

    void leftright() {
        rep(i,W/2) swap(yid[i], yid[W-1-i]);
    }

    void transpose() {
        isSwap = !isSwap;
        swap(xid, yid);
        swap(H, W);
    }

    void print() {
        rep(i,H) {
            rep(j,W) {
                cout << find(i,j) << " ";
            }
            cout << endl;
        }
    }

    private:
        bool isSwap;
        int H, W;
        vector<vector<T>> grid;

        // 新しい行列の index と original の行列の index との対応表
        // 新しい行列の i, j 成分は
        // swap is false のとき
        //   grid[xid[i]][yid[j]]
        // swap is true のとき
        //   grid[yid[j]][xid[i]]
        vector<int> xid, yid;

        pair<int,int> index(int x, int y) {
            int i = xid[x];
            int j = yid[y];
            if (isSwap) swap(i,j);
            return {i,j};
        }
};

void solve() {
    int h = 2, w = 3;
    Matrix<char> mat(2, 3);
    rep(i,h) rep(j,w) mat.set(i, j, 'a' + i*w + j);
    printf("original\n");
    mat.print();
    cout << endl;

    printf("rotr90\n");
    mat.rotr90();
    mat.print();
    cout << endl;

    printf("set 'z' at (0, 1)\n");
    mat.set(0, 1, 'z');
    mat.print();
    cout << endl;

    printf("rotr90\n");
    mat.rotr90();
    mat.print();
    cout << endl;

    printf("rotl90\n");
    mat.rotl90();
    mat.print();
    cout << endl;

    printf("transpose\n");
    mat.transpose();
    mat.print();
    cout << endl;
}

int main() {
    solve();
    return 0;
}
```

output
```
original
a b c
d e f

rotr90
d a
e b
f c

set 'z' at (0, 1)
d z
e b
f c

rotr90
f e d
c b z

rotl90
d z
e b
f c

transpose
d e f
z b c
```

### べき乗

```cpp
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using vvll = vector<vector<ll>>;
ll MOD = ((ll)1e9);

struct Matrix {
    vvll data;

    Matrix(vvll data) { this->data = data; }

    Matrix operator*(const Matrix& other) {
        int n = data.size();
        int m = other.data[0].size();
        int l = other.data.size();
        vvll res(n, vll(m, 0));
        rep(i, n) rep(j, m) rep(k, l) {
            res[i][j] += data[i][k] * other.data[k][j];
            res[i][j] %= MOD;
        }
        return Matrix(res);
    }

    Matrix exp(ll k) {
        int n = data.size();
        Matrix res(vvll(n, vll(n, 0)));
        rep(i, n) res.data[i][i] = 1;
        Matrix a = *this;
        while (k > 0) {
            if (k & 1)
                res = res * a;
            a = a * a;
            k >>= 1;
        }
        return res;
    }
};

```

## ランレングス圧縮 (Run Length Encoding)

```cpp
template <typename T>
vector<pair<T, int>> runLengthEncode(const vector<T>& input) {
    vector<pair<T, int>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        int count = 1;
        while (i + 1 < size && input[i] == input[i + 1]) {
            ++i;
            ++count;
        }
        encoded.emplace_back(input[i], count);
    }
    return encoded;
}
```

## 最長増加部分列 (LIS: Longest Increasing Subsequence)

数列 $A=a_0,a_1,\cdots, a_{n−1}$ の最長増加部分列 (LIS: Longest Increasing Subsequence) とは
数列 $A$ の増加部分列 $a_{i_0}, \cdots, a_{i_k}$ ($0 \leq i_0 < i_1 < \cdots < i_k < n$ かつ $a_{i_0} < a_{i_1} < \cdots < a_{i_k}$) のうち最も $k$ が大きいもの.

- [Qiita - 最長増加部分列(LIS)の長さを求める](https://qiita.com/python_walker/items/d1e2be789f6e7a0851e5)
- [AOJ - 最長増加部分列](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D)


```cpp
// is_strong = true のとき increasing
// is_strong = false のとき non-decreasing
int LIS(vector<int>& A, bool is_strong) {
    int n = A.size();
    vector<int> dp(n, INF);

    rep(i,n) {
        // A_{i_{k}} < A_{i_{k+1}}
        if (is_strong) *lower_bound(all(dp), A[i]) = A[i];
        // A_{i_{k}} <= A_{i_{k+1}}
        else *upper_bound(all(dp), A[i]) = A[i];
    }

    return lower_bound(all(dp), INF) - dp.begin();
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cout << LIS(a, true) << endl;
}
```

## 最短経路

### ダイクストラ法 (Dijkstra)

```cpp
using Graph = vector<vector<Edge>>;

// node s からの最短距離を求める
// 到達できない node との距離は INF になる.
vector<int> dijkstra(Graph &graph, int s) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[s] = 0;
    // P: cost, node
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        for (auto e : graph[node.second]) {
            if (dist[e.to] > dist[node.second] + e.cost) {
                dist[e.to] = dist[node.second] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    return dist;
}

void solve() {
    int v, e, r;
    cin >> v >> e >> r;
    Graph graph(v);
    rep(i,e) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({t, d});
    }

    auto dist = dijkstra(graph, r);
    rep(i,v) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
```

## 最小全域木(minimum spanning tree)

### プリム法

適当な頂点(本当にどこからでもいい)を起点にして, まだ訪れていない頂点への最小のコストの辺を採用していく.
すでに訪れた頂点への辺は捨てる.

```cpp
struct Edge {
    int to;
    ll cost;
};

bool operator>(const Edge &a, const Edge &b) {
    return a.cost > b.cost;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    rep(i,m) {
        int s, t;
        ll w;
        cin >> s >> t >> w;
        graph[s].push_back({t, w});
        graph[t].push_back({s, w});
    }

    vint visited(n, 0);
    visited[0] = 1;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (auto edge : graph[0]) pq.push(edge);
    vector<Edge> mst;
    while (pq.size()) {
        auto t = pq.top(); pq.pop();
        if (visited[t.to]) continue;
        visited[t.to] = 1;
        mst.push_back(t);
        for (auto edge : graph[t.to]) {
            if (visited[edge.to]) continue;
            pq.push(edge);
        }
    }

    ll tot = 0;
    for (auto edge : mst) {
        tot += edge.cost;
    }
    cout << tot << endl;
}
```

### クラスカル法

全ての辺をコストが小さい順に見ていき, 見ている辺をつないだときにサイクルができなければその辺を採用, それ以外のときは捨てる.
サイクルの検出には Union Find を使うのが定石.

```cpp
struct Edge {
    int from;
    int to;
    ll cost;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

struct UnionFind {
    vint d;
    UnionFind(int n) : d(n, -1) {}
    int leader(int x) {
        if (d[x] < 0) return x;
        return d[x] = leader(d[x]);
    }
    void merge(int x, int y) {
        x = leader(x), y = leader(y);
        if (x == y) return;
        if (d[x] < d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    rep(i,m) {
        int s, t;
        ll w;
        cin >> s >> t >> w;
        edges.push_back({s, t, w});
        edges.push_back({t, s, w});
    }
    sort(all(edges));

    vector<Edge> mst_edges;
    UnionFind uf(n);
    for (auto [from, to, cost] : edges) {
        if (!uf.same(from, to)) {
            mst_edges.push_back({from, to, cost});
            uf.merge(from, to);
        }
    }

    ll tot = 0;
    for (auto edge : mst_edges) tot += edge.cost;
    cout << tot << endl;
}
```
