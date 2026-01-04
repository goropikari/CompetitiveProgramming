+++
title = "Algorithm"
date = "2021-12-12"
tags = ["algorithm"]
+++

## int <-> string

- `to_string(int)` -> string
- `to_string(ll)` -> string
- `stoi(string)` -> int
- `stoll(string)` -> ll

## priority queue

昇順

```cpp
#include <iostream>
#include <queue>

int main() {
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

int main() {
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

bool operator<(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool operator>(const Point& a, const Point& b) {
    return a.x > b.x;
}

void solve() {
    {
        // operator< が必要
        priority_queue<Point> pq;
        rep(i, 3) pq.push({i, 3 - i});

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
        rep(i, 3) pq.push({i, 3 - i});

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
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Hoge {
    int x, y;
};

bool compare(Hoge a, Hoge b) {
    return a.y > b.y;
}

int main(int argc, char* argv[]) {
    vector<Hoge> v = {{0, 1}, {1, 9}};

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
        if (x % y != 0)
            return x / y - 1;
    }

    return x / y;
}
```

## 未満

### part 1

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

<!-- dprint-ignore -->
\begin{align*}
    f(sx+1) \leq f(P) \\\\
    \therefore&~~ \floor{  \frac{(sx+1)+x-1}{x}  } \leq f(P) \\\\
    \therefore&~~ \floor{  \frac{sx + x}{x}  } \leq f(P) \\\\
    \therefore&~~ \floor{  s+1  } \leq f(P) \\\\
    \therefore&~~   s+1  \leq f(P) \\\\
    \therefore&~~   s < s+1  \leq f(P) \\\\
    \therefore&~~   s < f(P)
\end{align*}

$(\leftarrow)$

$f(sx) = \floor{ \frac{sx + x-1}{x} } = \floor{ s + \frac{x-1}{x} } = s + \floor{ \frac{x-1}{x} } = s$

$f(sx+1) = s+1$

より $s < f(P)$ ならば

<!-- dprint-ignore -->
\begin{align*}
    &sx+1 \leq P \\\\
    \therefore~~ &sx < sx+1 \leq P \\\\
    \therefore~~ &sx < P \\\\
    \therefore~~ &s < \frac{P}{x}
\end{align*}

ref: <https://atcoder.jp/contests/abc384/tasks/abc384_e>

### part 2

$x, a, X$ が正整数のとき

$$
    x > \frac{M}{a} \iff x > \floor{ \frac{M}{a} }
$$

($\Rightarrow$)

$\frac{M}{a} \geq \floor{\frac{M}{a}}$ であるから

<!-- dprint-ignore -->
\begin{align*}
    x &> \frac{M}{a} \geq \floor{\frac{M}{a}} \\\\
    \therefore x &> \floor{\frac{M}{a}}
\end{align*}

($\Leftarrow$)

<!-- dprint-ignore -->
\begin{align*}
    x &> \floor{\frac{M}{a}} \\\\
    \therefore x &\geq \floor{\frac{M}{a}} + 1  > \frac{M}{a} \\\\
    \therefore x &> \frac{M}{a} \\\\
\end{align*}

ref: <https://atcoder.jp/contests/abc406/tasks/abc406_e>

## 以下

$x,a,y$ が正整数のとき

<!-- dprint-ignore -->
\begin{align*}
    \frac{x}{a} \leq y \iff \lceil \frac{x}{a} \rceil \leq y
\end{align*}

($\Rightarrow$)

$x = qa + r$ ($q,r \in \mathbb{N}$, $0 \leq r < a$) とする.

(i)
$r = 0$ のとき $x/a = \lceil x/a \rceil$ より $x/a = \lceil x/a \rceil \leq y$。
よって $\frac{x}{a} \leq y \Rightarrow \lceil \frac{x}{a} \rceil \leq y$

(ii)
$0 < r < a$ のとき、$0 < r/a < 1$ であり、$y$ は整数であるから
$q < q+\frac{r}{a} < q+1 \leq y$.
ここで $q + 1 = \lceil \frac{x}{a} \rceil$ であるから
$\frac{x}{a} \leq y \Rightarrow \lceil \frac{x}{a} \rceil \leq y$

(i), (ii) より、
$\frac{x}{a} \leq y \Rightarrow \lceil \frac{x}{a} \rceil \leq y$

($\Leftarrow$)

$\frac{x}{a} \leq \lceil \frac{x}{a} \rceil$ であるから

<!-- dprint-ignore -->
\begin{align*}
    \lceil \frac{x}{a} \rceil \leq y \Rightarrow \frac{x}{a} \leq y
\end{align*}

以上より

<!-- dprint-ignore -->
\begin{align*}
    \frac{x}{a} \leq y \iff \lceil \frac{x}{a} \rceil \leq y
\end{align*}

が成り立つ。

ref: <https://atcoder.jp/contests/past202212-open/tasks/past202212_f>

## gcd, lcm

$\mathrm{gcd}(a, b) = \mathrm{gcd}(b, a \\% b)$.

$\displaystyle \mathrm{lcm}(a,b) = \frac{a \times b}{\mathrm{gcd}(a,b)}$

Suppose $d = \mathrm{gcd}(a,b)$. This means $a = k_1 d$ and $b = k_2 d$ for some integers $k_1, k_2 \in \mathbb{Z}$.

$a = qb + r$ $(0 \leq r < b)$, for some integer $q$.

Then $a\\% b = r = a - qb = d(k_1 - qk_2)$.

```cpp
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
```

## 冪乗根 / 平方根

$\floor{\sqrt[\leftroot{-3}\uproot{3}k]{x}}$ を求める関数

```cpp
using Int = unsigned long long int;

auto kth_root = [](Int x, Int k) -> Int {
    assert(k != 0);
    if (x == 1 || k == 1) return x;
    Int l = 0, r = x;
    while (r - l > 1) {
        Int m = (r - l) / 2 + l;
        Int t = x;
        rep(i, k) t /= m;
        if (1 > t) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
};

// 平方根
auto isqrt = [&](Int x) -> Int {
    return kth_root(x, 2);
};
```

ref

- [ABC 400 C 問題]({{< ref "abc/400.md" >}})
- <https://judge.yosupo.jp/submission/299508>

## 累積和 (cumsum)

### 1次元

```cpp
template <typename T>
struct Cumsum {
    vector<T> data;

    Cumsum(vector<T> v) {
        int n = v.size();
        data.resize(n + 1);

        data[0] = 1;
        rep(i, n) {
            data[i + 1] = data[i] + v[i];
        }
    }

    // sum of range [l,r)
    ll sum(int l, int r) {
        return data[r] - data[l];
    }
};
```

```cpp
void solve() {
    int n, q;
    cin >> n >> q;
    vll a(n);
    rep(i, n) cin >> a[i];

    Cumsum cumsum(a);
    rep(_, q) {
        int l, r;
        cin >> l >> r;
        cout << cumsum.sum(l, r) << endl;
    }
}
```

### 2次元

```cpp
template <typename T>
struct Cumsum2d {
    vector<vector<T>> data;

    Cumsum2d(vector<vector<T>> v) {
        assert(v.size() != 0);
        assert(v[0].size() != 0);
        int h = v.size();
        int w = v[0].size();

        data = vector<vector<T>>(h + 1, vector<T>(w + 1));

        rep(i, h) rep(j, w) {
            data[i + 1][j + 1] += data[i][j + 1] + data[i + 1][j] - data[i][j] + v[i][j];
        }
    }

    T sum(int si, int sj, int fi, int fj) {
        T ret = data[fi][fj];
        ret -= data[si][fj];
        ret -= data[fi][sj];
        ret += data[si][sj];
        return ret;
    }
};
```

### 3次元

計算方法の詳細は [ABC 366]({{< ref "abc/366.md" >}}) に書いた

```cpp
template <typename T>
struct Cumsum3d {
    vector<vector<vector<T>>> data;

    Cumsum3d(vector<vector<vector<T>>> v) {
        assert(v.size() != 0);
        assert(v[0].size() != 0);
        assert(v[0][0].size() != 0);

        int n = v.size();
        int m = v[0].size();
        int l = v[0][0].size();

        data = vector(n + 1, vector(m + 1, vector<T>(l + 1)));

        vector<tuple<ll, ll, ll, ll>> d = {
            {0, 0, -1, 1},
            {0, -1, 0, 1},
            {0, -1, -1, -1},
            {-1, 0, 0, 1},
            {-1, 0, -1, -1},
            {-1, -1, 0, -1},
            {-1, -1, -1, 1},
        };

        rep2(i, 1, n + 1) rep2(j, 1, m + 1) rep2(k, 1, l + 1) {
            data[i][j][k] += v[i - 1][j - 1][k - 1];
            for (auto [x, y, z, sign] : d) {
                data[i][j][k] += data[i + x][j + y][k + z] * sign;
            }
        }
    }

    T sum(int si, int sj, int sk, int fi, int fj, int fk) {
        ll ans = 0;
        ans += data[fi][fj][fk];
        ans -= data[fi][fj][sk];
        ans -= data[fi][sj][fk];
        ans += data[fi][sj][sk];
        ans -= data[si][fj][fk];
        ans += data[si][fj][sk];
        ans += data[si][sj][fk];
        ans -= data[si][sj][sk];
        return ans;
    }
};
```

<https://atcoder.jp/contests/abc366/submissions/65702920>

## べき乗計算(冪乗)

### 高速べき乗計算

$x^n$ を高速に求める

```cpp
// x^n
ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x;
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
        if (n & 1)
            ret = (ret * x) % mod;
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
    return modpow(x, mod - 2, mod);
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
        for (int j = i + i; j < MAX; j += i) {
            isprime[j] = false;
        }
    }
}
```

#### 素因数分解、約数列挙

<https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/NTL_1_A/judge/10351236/C++23>

```cpp
// https://qiita.com/drken/items/3beb679e54266f20ab63#4-%E6%B4%BB%E7%94%A8%E4%BE%8B-1-%E9%AB%98%E9%80%9F%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3%E9%AB%98%E9%80%9F%E7%B4%84%E6%95%B0%E5%88%97%E6%8C%99
struct Sieve {
    vector<bool> isprime;

    // 整数 i を割り切る最小の素数
    vector<int> minfactor;

    Sieve(int N)
        : isprime(N + 1, true),
          minfactor(N + 1, -1) {
        isprime[1] = false;
        minfactor[1] = 1;

        for (int p = 2; p <= N; ++p) {
            // すでに合成数であるものはスキップする
            if (!isprime[p])
                continue;

            // p についての情報更新
            minfactor[p] = p;

            // p 以外の p の倍数から素数ラベルを剥奪
            for (int q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;

                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1)
                    minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解
    // pair (素因子, 指数) の vector を返す
    vector<pair<ll, ll>> factorize(int n) {
        vector<pair<ll, ll>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    // 高速約数列挙
    vector<int> divisors(int n) {
        vector<int> res({1});

        // n を素因数分解 (メンバ関数使用)
        auto pf = factorize(n);

        // 約数列挙
        for (auto p : pf) {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};
```

### 素因数分解

計算量 $O(\sqrt{N})$

<https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/NTL_1_A/judge/10351217/C++23>

```cpp
// prime, cnt
vector<pair<ll, ll>> factor(ll n) {
    vector<pair<ll, ll>> ps;
    ll t = n;
    for (int i = 2; i * i <= n; i++) {
        if (t % i == 0) {
            ll cnt = 0;
            while (t % i == 0) {
                t /= i;
                cnt++;
            }
            ps.emplace_back(i, cnt);
        }
    }
    if (t > 1)
        ps.emplace_back(t, 1);

    return ps;
}
```

## 行列

$H \times W$ の行列 $A$ を考える.
$A$ に以下の操作を加えたでできた行列を $A^\prime$ とする.
このとき $A^\prime$ の $(i^\prime, j^\prime)$ 成分と $A$ の $(i,j)$ 成分の対応は以下の通りである.

各操作を愚直に行うと $O(HW)$ かかるが, index のみを更新することで $O(H+W)$ に計算量を落とすことができる.

### rotr90

<!-- dprint-ignore -->
\begin{align*}
    i^\prime &= j \\\\
    j^\prime &= H - 1 - i
\end{align*}

$N \times N$ のとき

```cpp
template <typename T>
vector<vector<T>> rotr90(vector<vector<T>>& mat) {
    vector<vector<T>> newmat = mat;
    int N = mat.size();
    rep(i, N) {
        rep(j, N) {
            // newmat[j][N - 1 - i] = mat[i][j];
            newmat[i][j] = mat[N - j - 1][i];
        }
    }
    return newmat;
}
```

<https://atcoder.jp/contests/abc404/submissions/65484195>

### rotl90

<!-- dprint-ignore -->
\begin{align*}
    i^\prime &= W - 1 - j \\\\
    j^\prime &= i
\end{align*}

### transpose

<!-- dprint-ignore -->
\begin{align*}
    i^\prime &= j \\\\
    j^\prime &= i
\end{align*}

### 上下反転

<!-- dprint-ignore -->
\begin{align*}
    i^\prime &= H - 1 - i \\\\
    j^\prime &= j
\end{align*}

### 左右反転

<!-- dprint-ignore -->
\begin{align*}
    i^\prime &= i \\\\
    j^\prime &= W - 1 - j
\end{align*}

```cpp
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <typename T>
struct Matrix {
    Matrix(int h, int w)
        : isSwap(false), H(h), W(w), grid(h, vector<T>(w, 0)), xid(h), yid(w) {
        rep(i, h) xid[i] = i;
        rep(i, w) yid[i] = i;
    }

    T find(int x, int y) {
        P p = index(x, y);
        return grid[p.first][p.second];
    }

    void set(int x, int y, T val) {
        P p = index(x, y);
        grid[p.first][p.second] = val;
    }

    void rotr90() {
        isSwap = !isSwap;
        vector<int> new_yid(H);
        rep(i, H) new_yid[i] = H - 1 - xid[i];
        swap(H, W);
        xid = yid;
        yid = new_yid;
    }

    void rotl90() {
        isSwap = !isSwap;
        vector<int> new_xid(W);
        rep(i, W) new_xid[i] = W - 1 - yid[i];
        swap(H, W);
        yid = xid;
        xid = new_xid;
    }

    void topbottom() {
        rep(i, H / 2) swap(xid[i], xid[H - 1 - i]);
    }

    void leftright() {
        rep(i, W / 2) swap(yid[i], yid[W - 1 - i]);
    }

    void transpose() {
        isSwap = !isSwap;
        swap(xid, yid);
        swap(H, W);
    }

    void print() {
        rep(i, H) {
            rep(j, W) {
                cout << find(i, j) << " ";
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

    pair<int, int> index(int x, int y) {
        int i = xid[x];
        int j = yid[y];
        if (isSwap)
            swap(i, j);
        return {i, j};
    }
};

void solve() {
    int h = 2, w = 3;
    Matrix<char> mat(2, 3);
    rep(i, h) rep(j, w) mat.set(i, j, 'a' + i * w + j);
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
vector<pair<T, ll>> runLengthEncode(const vector<T>& input) {
    vector<pair<T, ll>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        long long int count = 1;
        while (i + 1 < size && input[i] == input[i + 1]) {
            ++i;
            ++count;
        }
        encoded.emplace_back(input[i], count);
    }
    return encoded;
}

vector<pair<char, long long int>> runLengthEncode(const string& input) {
    vector<pair<char, long long int>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        long long int count = 1;
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

    rep(i, n) {
        // A_{i_{k}} < A_{i_{k+1}}
        if (is_strong)
            *lower_bound(all(dp), A[i]) = A[i];
        // A_{i_{k}} <= A_{i_{k+1}}
        else
            *upper_bound(all(dp), A[i]) = A[i];
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

<https://judge.yosupo.jp/submission/263372>

```cpp
const ll INF = (ll)2e18 + 9;

struct Edge {
    int to;
    long long int weight;
};

bool operator>(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}

using Graph = vector<vector<Edge>>;

struct Dijkstra {
    int n;  // ノード数
    Graph graph;
    vector<long long int> dist;  // start からの最短距離
    vector<int> from;            // from[i]: i 番目のノードにどこから来たか
    int start = -1;

    Dijkstra(int n)
        : n(n), graph(n), dist(n, INF), from(n, -1) {}

    void add_edge(int from, int to, long long int weight) {
        graph[from].push_back({to, weight});
    }

    void run(int start) {
        dist[start] = 0;
        this->start = start;

        // cost, node
        using P = pair<long long int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, start});

        while (pq.size()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (dist[node] < cost)
                continue;

            for (auto [to, weight] : graph[node]) {
                if (dist[to] > dist[node] + weight) {
                    dist[to] = dist[node] + weight;
                    from[to] = node;
                    pq.push({dist[to], to});
                }
            }
        }
    }

    // start から fin までの最短距離.  到達不可のときは -1 を返す
    long long int distance(int fin) {
        if (dist[fin] == INF)
            return -1;
        return dist[fin];
    }

    // start -> fin への経路
    vector<int> path(int fin) {
        vector<int> ans = {fin};
        int now = fin;
        while (now != start) {
            now = from[now];
            ans.push_back(now);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void solve() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Dijkstra graph(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph.add_edge(a, b, c);
    }

    graph.run(s);
    if (graph.distance(t) == -1) {
        cout << -1 << endl;
        return;
    }

    vint path = graph.path(t);
    cout << graph.distance(t) << ' ' << path.size() - 1 << endl;
    rep(i, path.size() - 1) {
        cout << path[i] << ' ' << path[i + 1] << endl;
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

bool operator>(const Edge& a, const Edge& b) {
    return a.cost > b.cost;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    rep(i, m) {
        int s, t;
        ll w;
        cin >> s >> t >> w;
        graph[s].push_back({t, w});
        graph[t].push_back({s, w});
    }

    vint visited(n, 0);
    visited[0] = 1;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (auto edge : graph[0])
        pq.push(edge);
    vector<Edge> mst;
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        if (visited[t.to])
            continue;
        visited[t.to] = 1;
        mst.push_back(t);
        for (auto edge : graph[t.to]) {
            if (visited[edge.to])
                continue;
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

bool operator<(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

struct UnionFind {
    vint d;
    UnionFind(int n)
        : d(n, -1) {}
    int leader(int x) {
        if (d[x] < 0)
            return x;
        return d[x] = leader(d[x]);
    }
    void merge(int x, int y) {
        x = leader(x), y = leader(y);
        if (x == y)
            return;
        if (d[x] < d[y])
            swap(x, y);
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
    rep(i, m) {
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
    for (auto edge : mst_edges)
        tot += edge.cost;
    cout << tot << endl;
}
```

## Segment tree (セグメント木)

ACL の使い方は別途まとめた

- [ソラで書くセグメント木から ACL へ移行する](../segment_tree)

### RMQ (Range Minimum Query)  一点更新 区間最小値

- <https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A>
  - 再帰版
    - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_A/judge/10276204/C++23>
  - 非再帰版
    - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_A/judge/10276844/C++23>

```cpp
struct RMQ {
    vector<ll> seg;
    ll e = (1ll << 31) - 1;
    int len = 1;

    RMQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
    }

    void set(int p, ll x) {
        p += len;
        seg[p] = x;
        while (p / 2) {
            p /= 2;
            seg[p] = min(seg[2 * p], seg[2 * p + 1]);
        }
    }

    ll prod(int l, int r) {
        l += len, r += len;
        ll ans = (1ll << 31) - 1;
        while (l < r) {
            if (l % 2 == 1) {
                ans = min(ans, seg[l]);
                l++;
            }
            l /= 2;
            if (r % 2 == 1) {
                ans = min(ans, seg[r - 1]);
                r--;
            }
            r /= 2;
        }

        return ans;
    }

    ll prod_rec(int l, int r) {
        return _prod_rec(l, r, 0, len, 1);
    }

    ll _prod_rec(int ql, int qr, int sl, int sr, int p) {
        if (qr <= sl || sr <= ql)
            return e;
        if (ql <= sl && sr <= qr)
            return seg[p];
        int sm = (sl + sr) / 2;
        ll lmin = _prod_rec(ql, qr, sl, sm, p * 2);
        ll rmin = _prod_rec(ql, qr, sm, sr, p * 2 + 1);
        return min(lmin, rmin);
    }
};
```

### RSQ (Range Sum Query) 一点加算 区間和

- <https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B>
  - 非再帰版
    - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_B/judge/10276127/C++23>
  - 再帰版
    - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_B/judge/10276849/C++23>

```cpp
struct RSQ {
    vll seg;
    ll e = 0;
    ll len = 1;

    RSQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
    }

    void add(int p, ll x) {
        p += len;
        seg[p] += x;
        while (p / 2) {
            p /= 2;
            seg[p] += x;
        }
    }

    ll sum(int l, int r) {
        l += len, r += len;
        ll ans = e;

        while (l < r) {
            if (l & 1) {
                ans += seg[l];
                l++;
            }
            l /= 2;
            if (r & 1) {
                ans += seg[r - 1];
                r--;
            }
            r /= 2;
        }

        return ans;
    }

    ll sum_rec(int l, int r) {
        return _sum_rec(l, r, 0, len, 1);
    }

    ll _sum_rec(int ql, int qr, int sl, int sr, int p) {
        if (qr <= sl || sr <= ql)
            return e;
        if (ql <= sl && sr <= qr)
            return seg[p];
        int sm = (sl + sr) / 2;
        ll lsum = _sum_rec(ql, qr, sl, sm, p * 2);
        ll rsum = _sum_rec(ql, qr, sm, sr, p * 2 + 1);
        return lsum + rsum;
    }
};
```

### RAQ (Range Add Query) 区間加算 一点取得

- [ABC 340 E](https://atcoder.jp/contests/abc340/tasks/abc340_e)
- <https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E>
  - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_E/judge/10276094/C++23>
  - 再帰版
    - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_E/judge/10276850/C++23>

```cpp
struct RAQ {
    vll seg;
    ll e = 0;
    int len = 1;

    RAQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
    }

    ll get(int p) {
        p += len;
        ll ans = seg[p];
        while (p / 2) {
            p /= 2;
            ans += seg[p];
        }
        return ans;
    }

    void add(int l, int r, ll x) {
        l += len, r += len;
        while (l < r) {
            if (l & 1) {
                seg[l] += x;
                l++;
            }
            l /= 2;
            if (r & 1) {
                seg[r - 1] += x;
                r--;
            }
            r /= 2;
        }
    }

    void add_rec(int l, int r, ll x) {
        _add_rec(l, r, 0, len, x, 1);
    }

    void _add_rec(int ql, int qr, int sl, int sr, ll x, int p) {
        if (sr <= ql || qr <= sl)
            return;
        if (ql <= sl && sr <= qr) {
            seg[p] += x;
            return;
        }
        int sm = (sl + sr) / 2;
        _add_rec(ql, qr, sl, sm, x, p * 2);
        _add_rec(ql, qr, sm, sr, x, p * 2 + 1);
    }
};
```

### RUQ (Range Update Query) 区間更新 一点取得

いつ更新したものかという情報も付け加えて値の更新を管理する

- <https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D>
  - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_D/judge/10276168/C++23>
  - 再帰版
    - <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_D/judge/10276853/C++23>

```cpp
struct RUQ {
    vector<ll> seg;
    vint updated_at;
    ll e = (1ll << 31) - 1;
    int len = 1;
    int cnt = 0;

    RUQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
        updated_at.resize(len * 2, -1);
    }

    void update(int l, int r, ll x) {
        cnt++;
        l += len, r += len;
        while (l < r) {
            if (l & 1) {
                seg[l] = x;
                updated_at[l] = cnt;
                l++;
            }
            l /= 2;
            if (r & 1) {
                seg[r - 1] = x;
                updated_at[r - 1] = cnt;
                r--;
            }
            r /= 2;
        }
    }

    void update_rec(int l, int r, ll x) {
        cnt++;
        _update_rec(l, r, 0, len, x, 1);
    }

    void _update_rec(int ql, int qr, int sl, int sr, ll x, int p) {
        if (sr <= ql || qr <= sl)
            return;
        if (ql <= sl && sr <= qr) {
            seg[p] = x;
            updated_at[p] = cnt;
            return;
        }
        int sm = (sl + sr) / 2;
        _update_rec(ql, qr, sl, sm, x, p * 2);
        _update_rec(ql, qr, sm, sr, x, p * 2 + 1);
    }

    ll find(int p) {
        p += len;
        ll ans = seg[p];
        int t = updated_at[p];
        while (p / 2) {
            p /= 2;
            ll nv = seg[p];
            ll nt = updated_at[p];
            if (nt > t) {
                ans = nv;
                t = nt;
            }
        }
        return ans;
    }
};
```

### RSQ and RAQ

区間和、区間加算

<https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_G/judge/10276973/C++23>

```cpp
struct RSQRAQ {
    vll seg;
    vll lazy;
    int len = 1;
    ll e = 0;
    ll id = 0;

    RSQRAQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
        lazy.resize(len * 2, id);
    }

    void eval(int sl, int sr, int p) {
        if (lazy[p] == id)
            return;
        seg[p] += lazy[p];
        if (sr - sl > 1) {
            ll x = lazy[p];
            lazy[p * 2] += x / 2;
            lazy[p * 2 + 1] += x / 2;
        }
        lazy[p] = 0;
    }

    ll sum(int l, int r) {
        auto rec = [&](auto rec, int ql, int qr, int sl, int sr, int p) -> ll {
            eval(sl, sr, p);
            if (sr <= ql || qr <= sl) {
                return id;
            }
            if (ql <= sl && sr <= qr) {
                return seg[p];
            }
            int sm = (sl + sr) / 2;
            ll lsum = rec(rec, ql, qr, sl, sm, p * 2);
            ll rsum = rec(rec, ql, qr, sm, sr, p * 2 + 1);

            return lsum + rsum;
        };

        return rec(rec, l, r, 0, len, 1);
    }

    void add(int s, int t, ll x) {
        auto rec = [&](auto rec, int ql, int qr, int sl, int sr, ll x, int p) {
            eval(sl, sr, p);

            if (qr <= sl || sr <= ql)
                return;
            if (ql <= sl && sr <= qr) {
                lazy[p] += (sr - sl) * x;
                eval(sl, sr, p);
                return;
            }

            int sm = (sl + sr) / 2;
            rec(rec, ql, qr, sl, sm, x, p * 2);
            rec(rec, ql, qr, sm, sr, x, p * 2 + 1);
            seg[p] = seg[p * 2] + seg[p * 2 + 1];
        };

        rec(rec, s, t, 0, len, x, 1);
    }
};
```

### RMQ and RAQ

区間最小値、区間加算

- <https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H>
- <https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_2_H/judge/10277068/C++23>

```cpp
struct RMQRAQ {
    vll seg;
    vll lazy;
    int len = 1;
    ll e = 0;
    ll id = INF;

    RMQRAQ(int n) {
        while (n > len)
            len *= 2;
        seg.resize(len * 2, e);
        lazy.resize(len * 2, id);
    }

    void eval(int sl, int sr, int p) {
        if (lazy[p] == id)
            return;
        seg[p] += lazy[p];
        if (sr - sl > 1) {
            ll x = lazy[p];
            if (lazy[p * 2] == id)
                lazy[p * 2] = x;
            else
                lazy[p * 2] += x;

            if (lazy[p * 2 + 1] == id)
                lazy[p * 2 + 1] = x;
            else
                lazy[p * 2 + 1] += x;
        }
        lazy[p] = id;
    }

    ll find(int l, int r) {
        auto rec = [&](auto rec, int ql, int qr, int sl, int sr, int p) -> ll {
            eval(sl, sr, p);
            if (sr <= ql || qr <= sl) {
                return id;
            }
            if (ql <= sl && sr <= qr) {
                return seg[p];
            }
            int sm = (sl + sr) / 2;
            ll lmin = rec(rec, ql, qr, sl, sm, p * 2);
            ll rmin = rec(rec, ql, qr, sm, sr, p * 2 + 1);

            return min(lmin, rmin);
        };

        return rec(rec, l, r, 0, len, 1);
    }

    void add(int s, int t, ll x) {
        auto rec = [&](auto rec, int ql, int qr, int sl, int sr, ll x, int p) {
            eval(sl, sr, p);

            if (qr <= sl || sr <= ql)
                return;
            if (ql <= sl && sr <= qr) {
                if (lazy[p] == id)
                    lazy[p] = 0;
                lazy[p] += x;
                eval(sl, sr, p);
                return;
            }

            int sm = (sl + sr) / 2;
            rec(rec, ql, qr, sl, sm, x, p * 2);
            rec(rec, ql, qr, sm, sr, x, p * 2 + 1);
            seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
        };

        rec(rec, s, t, 0, len, x, 1);
    }
};
```

ac-library の lazy_segtree を使う場合

<https://judge.yosupo.jp/submission/342749>

- $[l,r)$ の範囲に対して $a_i \leftarrow a_i + x$
- $[l,r)$ の範囲の最小値を求める

```cpp
using S = ll;

S op(S a, S b) {
    return min(a, b);
}

S e() {
    return INF;
}

using F = ll;

S mapping(F f, S x) {
    return x + f;
}

F composition(F f, F g) {
    return f + g;
}

F id() {
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    vector<S> A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        A[i] = a;
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    rep(i, Q) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            ll x;
            cin >> x;
            seg.apply(l, r, x);
        }
        if (t == 1) {
            cout << seg.prod(l, r) << endl;
        }
    }
}
```

### 転倒数

<https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/ALDS1_5_D/judge/10376676/C++23>

```cpp
struct Segtree {
    int sz;
    vll data;

    Segtree(int n) {
        int i = 0;
        while ((1 << i) < n)
            i++;
        sz = 1 << i;
        data.resize(sz * 2);
    }

    void set(int p, ll x) {
        p += sz;
        data[p] = x;
        while (p / 2) {
            p /= 2;
            data[p] = data[p * 2] + data[p * 2 + 1];
        }
    }

    ll prod(int l, int r) {
        l += sz, r += sz;
        ll ans = 0;
        while (l < r) {
            if (l % 2 == 1) {
                ans += data[l];
                l++;
            }
            l /= 2;
            if (r % 2 == 1) {
                ans += data[r - 1];
                r--;
            }
            r /= 2;
        }
        return ans;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vint A(N);
    rep(i, N) {
        cin >> A[i];
    }

    vector<pair<int, int>> ids;
    rep(i, N) {
        ids.emplace_back(A[i], i);
    }
    sort(all(ids));

    Segtree seg(N);
    ll ans = 0;
    for (auto [_, i] : ids) {
        ans += seg.prod(i, N + 1);
        seg.set(i, 1);
    }
    cout << ans << endl;
}
```

## Trie

```cpp
struct Trie {
    vector<map<char, int>> to;

    Trie()
        : to(1) {};

    int add(string s) {
        int v = 0;
        for (char c : s) {
            if (to[v].count(c) == 0) {
                int u = to.size();
                to.push_back(map<char, int>());
                to[v][c] = u;
            }
            v = to[v][c];
        }
        return v;
    }
};
```

## Rolling Hash

<https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/ALDS1_14_B/judge/10319713/C++23>

```cpp
ll modpow(ll x, ll n, ll mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

struct RollingHash {
    vll data;
    const ll p = 1000000009;
    const ll mod = 1000000021;

    RollingHash(vll& v) {
        int n = v.size();
        data.resize(n + 1);
        rep(i, n) {
            data[i + 1] = (data[i] * p % mod) + v[i];
            data[i + 1] %= mod;
        }
    };

    // [l,r) の範囲の hash 値
    ll sub(ll l, ll r) {
        ll m = r - l;
        ll x = data[r] - data[l] * modpow(p, m, mod) % mod;
        x += mod;
        x %= mod;
        return x;
    }
};
```

## 全探索

### 組み合わせ

$N$ 個から $M$ を選ぶ組み合わせ

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 選んだ ID に対して何かしらの操作をする関数
    auto f = [](vint ids) -> void {
        print(ids);
    };

    auto dfs = [&](auto dfs, int n, int m, int used = 0) -> void {
        if (__builtin_popcount(used) == m) {
            vint ids;
            rep(i, n) {
                if (used >> i & 1) {
                    ids.push_back(i);
                }
            }
            f(ids);
            return;
        }

        int s = -1;
        rep(i, n) {
            if (used >> i & 1) {
                s = i;
            }
        }
        s++;

        rep2(i, s, n) {
            dfs(dfs, n, m, used | (1 << i));
        }
    };

    int n = 5, m = 3;
    dfs(dfs, n, m);
}

// 0 1 2
// 0 1 3
// 0 1 4
// 0 2 3
// 0 2 4
// 0 3 4
// 1 2 3
// 1 2 4
// 1 3 4
// 2 3 4
```

ref:

- [ABC 361 F 問題]({{< ref "abc/361.md" >}})

### 重複順列

$N$ 種類のものから重複を許して $M$ 個選ぶ順列
多重ループ相当

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto f = [](vint ids) -> void {
        print(ids);
    };

    auto dfs = [&](auto dfs, int n, int m, vint& ids) -> void {
        if (ids.size() == m) {
            f(ids);
            return;
        }

        rep(i, n) {
            ids.push_back(i);
            dfs(dfs, n, m, ids);
            ids.pop_back();
        }
    };

    vint ids;
    int n = 4, m = 3;
    dfs(dfs, n, m, ids);
}

// 0 0 0
// 0 0 1
// 0 0 2
// 0 0 3
// 0 1 0
// 0 1 1
// 0 1 2
// 0 1 3
// 0 2 0
// 0 2 1
// 0 2 2
// 0 2 3
// 0 3 0
// 0 3 1
// 0 3 2
// 0 3 3
// 1 0 0
// 1 0 1
// 1 0 2
// 1 0 3
// 1 1 0
// 1 1 1
// 1 1 2
// 1 1 3
// 1 2 0
// 1 2 1
// 1 2 2
// 1 2 3
// 1 3 0
// 1 3 1
// 1 3 2
// 1 3 3
// 2 0 0
// 2 0 1
// 2 0 2
// 2 0 3
// 2 1 0
// 2 1 1
// 2 1 2
// 2 1 3
// 2 2 0
// 2 2 1
// 2 2 2
// 2 2 3
// 2 3 0
// 2 3 1
// 2 3 2
// 2 3 3
// 3 0 0
// 3 0 1
// 3 0 2
// 3 0 3
// 3 1 0
// 3 1 1
// 3 1 2
// 3 1 3
// 3 2 0
// 3 2 1
// 3 2 2
// 3 2 3
// 3 3 0
// 3 3 1
// 3 3 2
// 3 3 3
```
