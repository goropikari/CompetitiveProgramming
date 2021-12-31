+++
title = "Algorithm"
hascode = true
date = Date(2021, 12, 12)
+++
@def tags = ["algorithm"]

# Algorithm

\toc

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
## gcd, lcm

$\mathrm{gcd}(a, b) = \mathrm{gcd}(b, a \% b)$.

$\displaystyle \mathrm{lcm}(a,b) = \frac{a \times b}{\mathrm{gcd}(a,b)}$


Suppose $d = \mathrm{gcd}(a,b)$. This means $a = k_1 d$ and $b = k_2 d$ for some integers $k_1, k_2 \in \Z$.

$a = qb + r$ $(0 \leq r < b)$, for some integer $q$.

Then $a\% b = r = a - qb = d(k_1 - qk_2)$.


```cpp
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
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

## 高速べき乗計算

$x^n$ を高速に求める

```cpp
// x^n
ll pow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

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
ll modinvpow(ll x, ll mod) {
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

## 行列操作

$H \times W$ の行列 $A$ を考える.
$A$ に以下の操作を加えたでできた行列を $A^\prime$ とする.
このとき $A^\prime$ の $(i^\prime, j^\prime)$ 成分と $A$ の $(i,j)$ 成分の対応は以下の通りである.

各操作を愚直に行うと $O(HW)$ かかるが, index のみを更新することで $O(H+W)$ に計算量を落とすことができる.

### rotr90

$
i^\prime = j \\
j^\prime = H - 1 - i
$

### rotl90

$
i^\prime = W - 1 - j \\
j^\prime = i
$

### transpose

$
i^\prime = j \\
j^\prime = i
$

### 上下反転

$
i^\prime = H - 1 - i \\
j^\prime = j
$

### 左右反転
$
i^\prime = i \\
j^\prime = W - 1 - j
$
\input{cpp}{/assets/scripts/algorithm/matrix.cpp} <!--_-->

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
