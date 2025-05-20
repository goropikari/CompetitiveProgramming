+++
date = '2025-01-26T11:41:37+09:00'
title = 'Educational DP Contest'
tags = ['atcoder', 'edpc']
+++

## L - Deque

<https://atcoder.jp/contests/dp/tasks/dp_l>

結局のところ両者ともに自分の得点が最大になるように行動すればよい

## まずは実験

- 要素が1つのとき

$X = a_1, Y = 0$

- 要素が2つのとき

$X = \max\\{ {a_1, a_2} \\}, Y = \min \\{ a_1, a_2 \\}$

- 要素が3つのとき

$X = \max \\{a_1 + (a_2, a_3 \text{の範囲で後手のときの得点}), (a_1, a_2 \text{の範囲で後手のときの得点}) + a_3 \\}$

...

## 解法

$\mathrm{dp}(i,j)$ を $[i,j]$ の範囲での先手の得点の最大値とすると

$$
    X = \mathrm{dp}(i,j) \\\\
    Y = \left( \sum_{k=i}^{j} a_k \right) - \mathrm{dp}(i,j)
$$

となる。

$\mathrm{dp}(i,j)$ の値は先頭の要素をとった場合と末尾の要素をとった場合の得点を比較して最大となる方を採用すれば良い。
先頭の要素をとったときの得点は先頭の要素の値と、$(i+1,j)$ の範囲で手番が相手だったときの自分が得られる得点の和が先手の得点となるから
$a_i + \sum_{k=i+1}^{j} a_k - \mathrm{dp}(i+1,j)$ となる。
同様にして末尾の要素をとったときの得点は $\sum_{k=i}^{j-1} a_k - \mathrm{dp}(i,j-1) + a_j$。

\begin{equation}
\mathrm{dp}(i,j) =
\left\\{
    \begin{aligned}
        &\max\left\\{a_i + \sum_{k=i+1}^{j} a_k - \mathrm{dp}(i+1,j), \sum_{k=i}^{j-1} a_k - \mathrm{dp}(i,j-1) + a_j\right\\} ~~~\text{if } i < j \nonumber \\\\
        &a_i ~~~~\text{if } i=j \nonumber
    \end{aligned}
\right.
\end{equation}

\begin{equation}
\therefore \mathrm{dp}(i,j) =
\left\\{
    \begin{aligned}
        &\sum_{k=i}^{j} a_k + \max\left\\{ - \mathrm{dp}(i+1,j), - \mathrm{dp}(i,j-1) \right\\} ~~~\text{if } i < j \nonumber \\\\
        &a_i ~~~~\text{if } i=j \nonumber
    \end{aligned}
\right.
\end{equation}

```cpp
vll A, cumsum;
vvll dp;

ll dfs(int i, int j) {
    if (i == j)
        return A[i];
    if (j - i == 1)
        return max(A[i], A[j]);
    if (dp[i][j] != -INF)
        return dp[i][j];

    ll ans = cumsum[j + 1] - cumsum[i];
    ans += max(-dfs(i + 1, j), -dfs(i, j - 1));

    return dp[i][j] = ans;
}

void solve() {
    ll N;
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    cumsum.resize(N + 1, 0);
    rep2(i, 1, N + 1) {
        cumsum[i] = cumsum[i - 1] + A[i - 1];
    }

    dp = vvll(N + 1, vll(N + 1, -INF));
    ll tot = accumulate(all(A), 0LL);
    ll X = dfs(0, N - 1);
    ll Y = tot - X;

    cout << X - Y << endl;
}
```

## M - Candies

<https://atcoder.jp/contests/dp/tasks/dp_m>

けんちょん氏のブログを読んで理解した
<https://drken1215.hatenablog.com/entry/2023/04/30/170700>

## 間違い解法

$f(i,\mathrm{rem})$ を $i$ 番目の子供に飴を渡す時点で `rem` 個飴が余っているときの配り方の場合の数として解こうとした。

$$
f(i,\mathrm{ rem }) = \sum^{a_i}_{j=0} f(i+1, \mathrm{rem} - j)
$$
となるので N 重の for loop をしているのと等価であり TLE する。

## 解法

$dp(i,j)$ を $i$ 番目の子供までで $j$ 個飴を配ったときの場合の数とすると

```cpp
// dp[i][j]: i 番目の子供までで j 個の飴を配る配り方
vvll dp(N + 1, vll(K + 1, 0));
dp[0][0] = 1;
rep2(i, 1, N + 1) {
    rep(j, K + 1) {
        rep(k, A[i] + 1) {
            if (j - k >= 0) {
                // i 番目の子供に k 個配ったとき。i-1 番目の子供までで j-k 個配った状態から遷移してくる
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
            }
        }
    }
}
```

ただ、これでも $O(NK^2)$ の計算量がかかるので TLE する。

一番内側の loop に着目すると

\begin{equation}
    dp(i,j) =
    \left\\{
    \begin{aligned}
       \sum_{m= j-a_i}^{j} dp(i-1,m)  ~~~\text{if } j-a_i \nonumber \geq 0 \\\\
       \sum_{m= 0}^{j} dp(i-1,m)  ~~~\text{(otherwise)} \nonumber
    \end{aligned}
    \right.
\end{equation}

となっている。

$S_{i,j} = \sum_{m=0}^{j} dp(i,m)$ とすると

\begin{align}
  dp(i,j) = S_{i-1,j} - S_{i-1,j-a_i-1}
\end{align}

とかけるので事前に累積和を計算しておけば一番内側の for loop をなくせる

```cpp
void solve() {
    ll N, K;
    cin >> N >> K;

    vll A(N + 1, 0);
    rep(i, N) cin >> A[i + 1];

    ll MOD = (ll)1e9 + 7;

    // dp[i][j]: i 番目の子供までで j 個の飴を配る配り方
    vvll dp(N + 1, vll(K + 1, 0));
    dp[0][0] = 1;
    rep2(i, 1, N + 1) {
        // cumsum[i][k]: sum from dp[i][0] to dp[i][k-1]
        vll cumsum(K + 2, 0);
        rep2(k, 1, K + 2) {
            cumsum[k] = cumsum[k - 1] + dp[i - 1][k - 1];
            cumsum[k] %= MOD;
        }

        rep(j, K + 1) {
            // cumsum は MOD の余りなので i<j ならば cumsum[i] < cumsum[j] が成り立たないことがあるので注意
            dp[i][j] = MOD + cumsum[j + 1] - cumsum[max(0LL, j - A[i])];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[N][K] << endl;
}
```

## N - Slimes

<https://atcoder.jp/contests/dp/tasks/dp_n>

連鎖行列積と考え方は同じ

<https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_B>

- $N=1$ のとき

合体するものがないのでコスト $0$

- $N=2$ のとき

$a_1+a_2$ を返す

- $N=3$ のとき

slime1, slime2 を合体させたあとに slime3 を合体させた場合
$$(a_1+a_2) + ((a_1+a_2) + a_3)$$

slime2, slime3 を合体させたあとに slime1 を合体させた場合
$$(a_2+a_3) + ((a_2+a_3) + a_1)$$

これらのうち最小の方を採用

- 一般の $N$ のとき

$f(i,j)$ を $[i,j)$ の範囲でスライムを合体させたときのコストの最小値とすると

\begin{align}
    f(i,j) = \min_{k \in \\{i+1, \cdots, j-1 \\}} f(i,k) + f(k,j) + \sum_{l=i}^{j-1} a_l \nonumber
\end{align}

となる。2つの領域に分けてそれぞれのコストを計算したあと合体させたときにかかるコストを合わせたものの中で最小のものを採用する。

$\sum$ の部分はあらかじめ累積和計算しておくことで高速に計算できる。

```cpp
vll A;
vvll dp;
vll cumsum;

ll dfs(int i, int j) {
    if (i >= j)
        return 0;
    if (dp[i][j] != -INF)
        return dp[i][j];
    if (j - i == 1)
        return 0;

    ll ans = INF;
    rep2(k, i + 1, j) {
        chmin(ans, cumsum[j] - cumsum[i] + dfs(i, k) + dfs(k, j));
    }
    return dp[i][j] = ans;
}

void solve() {
    ll N;
    cin >> N;
    A = vll(N);
    rep(i, N) cin >> A[i];

    cumsum = vll(N + 1, 0);
    dp = vvll(N + 1, vll(N + 1, -INF));

    rep(i, N) {
        cumsum[i + 1] = cumsum[i] + A[i];
    }

    cout << dfs(0, N) << endl;
}
```

## O - Matching

<https://atcoder.jp/contests/dp/tasks/dp_o>

## 間違い解法

```
2
1 0
0 1
```

という入力例のとき {(1, 1), (2, 2)} の組み合わせと {(2, 2), (1, 1)} がダブルカウントされてしまう。

```cpp
map<pair<int, int>, ll> mp;
ll MOD = (ll)1e9 + 7;

ll dfs(vvint& m, int N, int male, int female) {
    if (__builtin_popcount(male) == N)
        return mp[{male, female}] = 1;
    if (mp.count({male, female}))
        return mp[{male, female}];

    ll res = 0;
    rep(i, N) {
        rep(j, N) {
            if (!(male & (1 << i)) && !(female & (1 << j)) && m[i][j]) {
                res += dfs(m, N, male | (1 << i), female | (1 << j));
                res %= MOD;
            }
        }
    }

    return mp[{male, female}] = res;
}

void solve() {
    int N;
    cin >> N;
    vvint m(N, vint(N));
    rep(i, N) rep(j, N) cin >> m[i][j];

    cout << dfs(m, N, 0, 0) << endl;
}
```

## 解法

参考: <https://smijake3.hatenablog.com/entry/2019/01/16/012916>

$dp(i,S)$ を $i-1$ 番目までの男性をマッチングさせてマッチした女性の集合が $S$ のときに $i$ 番目の男性をマッチさせる場合の数とする。

まだマッチしていない女性の中から相性の良い女性を選べば良いから

\begin{align}
    dp(i,S) = \sum_{j \notin S \wedge \mathrm{match}(i, j) = 1} dp(i+1, S \cup \\{j \\}) \nonumber
\end{align}

となる。

```cpp
ll MOD = (ll)1e9 + 7;
int N;
vvint match;

vvll dp;

ll dfs(int x, int state) {
    if (__builtin_popcount(state) == N)
        return 1;
    if (dp[x][state] != -INF)
        return dp[x][state];

    ll res = 0;
    rep(i, N) {
        // 男女がそれぞれ N 人いてそこから N 組み作るのでマッチしない男性がいるケースは考えなくて良い。
        // M < N 組作るような場合ではこの分岐ではだめ(マッチしたときしか次の男性のケースに入らないため)
        if (!(state & (1 << i)) && match[x][i]) {
            res += dfs(x + 1, state | (1 << i));
            res %= MOD;
        }
    }
    return dp[x][state] = res;
}

void solve() {
    cin >> N;
    match = vvint(N, vint(N));
    rep(i, N) rep(j, N) cin >> match[i][j];

    dp = vvll(N + 1, vll(1 << N, -INF));
    cout << dfs(0, 0) << endl;
}
```
