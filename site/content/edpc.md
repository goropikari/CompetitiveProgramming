+++
date = '2025-01-26T11:41:37+09:00'
title = 'Educational DP Contest'
tags = ['atcoder', 'edpc']
+++

## I - Coins

$dp(i,num)$ を $i$ 番目までのコインを投げたときに表が `num` 枚となる確率とすると

\begin{align*}
    dp(i,num) &+= dp(i-1,num-1) \times p_i \\\\
    dp(i,num-1) &= dp(i-1,num-1) \times (1 - p_i) \\\\
    dp(0,0) &= 1
\end{align*}

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<double> p(N);
    rep(i, N) cin >> p[i];

    // dp[i][num]: i 枚目まで見て表の枚数が num 枚となる確率
    vector dp(N + 1, vector<double>(N + 1));
    dp[0][0] = 1.0;

    rep2(i, 1, N + 1) {
        double pi = p[i - 1];
        for (int num = N; num > 0; num--) {
            dp[i][num] += dp[i - 1][num - 1] * pi;
            dp[i][num - 1] = dp[i - 1][num - 1] * (1.0 - pi);
        }
    }

    double ans = 0.0;
    rep2(num, (N + 1) / 2, N + 1) {
        ans += dp[N][num];
    }
    printf("%.15lf\n", ans);
}
```

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<double> p(N);
    rep(i, N) cin >> p[i];

    // dp[i]: 表の枚数が i 枚となる確率
    vector<double> dp(N + 1);
    dp[0] = 1.0;

    for (auto pi : p) {
        for (int num = N; num > 0; num--) {
            dp[num] += dp[num - 1] * pi;
            dp[num - 1] *= (1.0 - pi);
        }
    }

    double ans = 0.0;
    rep2(i, (N + 1) / 2, N + 1) {
        ans += dp[i];
    }
    printf("%.15lf\n", ans);
}
```

## L - Deque

<https://atcoder.jp/contests/dp/tasks/dp_l>

結局のところ両者ともに自分の得点が最大になるように行動すればよい

### まずは実験

- 要素が1つのとき

$X = a_1, Y = 0$

- 要素が2つのとき

$X = \max\left\{ {a_1, a_2} \right\}, Y = \min \{ a_1, a_2 \}$

- 要素が3つのとき

$X = \max \{a_1 + (a_2, a_3 \text{の範囲で後手のときの得点}), (a_1, a_2 \text{の範囲で後手のときの得点}) + a_3 \}$

...

### 解法

$\mathrm{dp}(i,j)$ を $[i,j]$ の範囲での先手の得点の最大値とすると

\begin{align*}
    X &= \mathrm{dp}(i,j), \\\\
    Y &= \left( \sum_{k=i}^{j} a_k \right) - \mathrm{dp}(i,j)
\end{align*}

となる。

$\mathrm{dp}(i,j)$ の値は先頭の要素をとった場合と末尾の要素をとった場合の得点を比較して最大となる方を採用すれば良い。
先頭の要素をとったときの得点は先頭の要素の値と、$(i+1,j)$ の範囲で手番が相手だったときの自分が得られる得点の和が先手の得点となるから
$a_i + \sum_{k=i+1}^{j} a_k - \mathrm{dp}(i+1,j)$ となる。
同様にして末尾の要素をとったときの得点は $\sum_{k=i}^{j-1} a_k - \mathrm{dp}(i,j-1) + a_j$。

<!-- dprint-ignore -->
\begin{equation}
\mathrm{dp}(i,j) =
\left\\{
    \begin{aligned}
        &\max\left\\{a_i + \sum_{k=i+1}^{j} a_k - \mathrm{dp}(i+1,j), \sum_{k=i}^{j-1} a_k - \mathrm{dp}(i,j-1) + a_j\right\\} ~~~\text{if } i < j \nonumber \\\\
        &a_i ~~~~\text{if } i=j \nonumber
    \end{aligned}
\right.
\end{equation}

<!-- dprint-ignore -->
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

### 解法 1

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

<!-- dprint-ignore -->
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

<!-- dprint-ignore -->
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

### 解法 2

2025/12/29 での解法

$i$ 番目の子供まで飴を配って残りが $k$ 個となる場合の数を $dp(i,k)$ とする。
$i+1$ 番目の子供に飴を配ると残りの数は $\max(0, k-a_i) \sim k$ 個となる。

これより $dp(i+1,j)$, $j \in [\max(0, k-a_i), k]$ へはそれぞれ $dp(i,k)$ 分寄与される。
愚直に全ての $j$ について更新を行うと TLE をするのでいもす法で区間更新を行う。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vll A(N + 1);
    rep(i, N) cin >> A[i + 1];

    // dp[i][k]: i 人目までの子供に飴を配って、残りが k となる場合の数
    vector dp(N + 1, vector<mint>(K + 5));
    dp[0][K] = 1;

    rep2(i, 1, N + 1) {
        rep(num, K + 1) {
            dp[i][max(0ll, num - A[i])] += dp[i - 1][num];
            dp[i][num + 1] -= dp[i - 1][num];
        }
        rep2(j, 1, K + 1) {
            dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[N][0].val() << endl;
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

<!-- dprint-ignore -->
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

### 間違い解法

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

### 解法

参考: <https://smijake3.hatenablog.com/entry/2019/01/16/012916>

$dp(i,S)$ を $i-1$ 番目までの男性をマッチングさせてマッチした女性の集合が $S$ のときに $i$ 番目の男性をマッチさせる場合の数とする。

まだマッチしていない女性の中から相性の良い女性を選べば良いから

<!-- dprint-ignore -->
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

## Q - Flowers

自力 AC

<https://atcoder.jp/contests/dp/tasks/dp_q>

`dp(i)` を残した花の最後が $h_i$ のときの美しさの総和の最大値とすると

<!-- dprint-ignore -->
\begin{align*}
    dp(i) = \left( \max_{j < i} dp(j) \right) + a_i
\end{align*}

となる。
$i$ を小さい順に計算していけば $i$ 番目より右側にある $h_i$ よりも小さい花の $dp(j)$ ($i < j \wedge h_i > h_j$) の値は 0 になっているので segtree 等を使って max 計算を高速化すれば $O(N \log N)$ で計算できる。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vll H(N), A(N);
    rep(i, N) cin >> H[i];
    rep(i, N) cin >> A[i];

    segtree<ll, [](ll a, ll b) -> ll { return max(a, b); }, []() -> ll { return 0; }> dp(N + 1);
    rep(i, N) {
        ll h = H[i];
        ll mx = dp.prod(0, h);
        dp.set(h, mx + A[i]);
    }

    ll ans = dp.all_prod();
    cout << ans << endl;
}
```

## R - Walk

<https://atcoder.jp/contests/dp/tasks/dp_r>

自力 AC

遷移行列と、行列のべき乗計算を知っていれば簡単に解ける。

```cpp
struct Matrix {
    vector<vector<mint>> data;

    Matrix(vector<vector<mint>> data) { this->data = data; }

    Matrix operator*(const Matrix& other) {
        int n = data.size();
        int m = other.data[0].size();
        int l = other.data.size();
        vector res(n, vector<mint>(m, 0));
        rep(i, n) rep(j, m) rep(k, l) {
            res[i][j] += data[i][k] * other.data[k][j];
        }
        return Matrix(res);
    }

    Matrix exp(ll k) {
        int n = data.size();
        Matrix res(vector(n, vector<mint>(n, 0)));
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

    mint get(int i, int j) {
        return data[i][j];
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vector data(N, vector<mint>(N));
    rep(i, N) rep(j, N) {
        ll a;
        cin >> a;
        data[i][j] = a;
    }
    Matrix A(data);
    Matrix x(vector(N, vector<mint>(1, 1)));

    auto ret = A.exp(K) * x;
    mint ans = 0;
    rep(i, N) ans += ret.get(i, 0);
    cout << ans.val() << endl;
}
```

## S - Digit Sum

<https://atcoder.jp/contests/dp/tasks/dp_s>

自力 AC

$dp(i,j)$ を $0$ 以上 $10^i$ 未満の数字のうち、桁の総和が $j \mod D$ となる場合の数とする。

$dp(0,0) = 1$ とすると $i$ 桁目の数字が $j$、$i-1$ 桁目までの桁の総和の $\mod D$ が $k$ のとき、
$dp(i,(j+k \mod D)) += dp(i-1, k)$ が計上される。

問題の $K$ 以下の数字のうち桁の総和が $D$ の倍数となる場合の数について考える。
まず、$K$ が $N$ 桁の数字であるとき $K-1$ 桁の数字は全て $K$ 未満であるから $dp(N-1, 0) - 1$ を答えに加える。
$K$ の最上位の桁を $t$ とする。$N$ 桁の数字のうち最上位の桁が $1$ 以上 $t$ 未満のとき $K$ 未満の数字であるから
残りの $N-1$ 桁の数字は何を選んでも $K$ 未満の数字となる。
よって、$j+k \equiv 0 \mod D$ を満たす $1 \leq j < t$, $0 \leq k < D$ の組み合わせについて $dp(i-1, k)$ を答えに加える。

最後に、$K$ の最上位の桁から $i-1$ 番目までは桁の数字が同じで $i$ 番目の桁が $K$ の $i$ 番目の桁より小さいとき、残りの桁は何を選んでも $K$ 未満の数字となるから $K$ の $i$ 番目の桁を $t$ とすると
$j+k \equiv 0 \mod D$ を満たす $0 \leq j < t$, $0 \leq k < D$ の組み合わせについて $dp(N-i, k)$ を答えに加える。
最上位の桁との違いは $i$ 番目の桁に $0$ を選ぶことができる点である。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string K;
    ll D;
    cin >> K >> D;

    int N = K.size();
    // dp[i][j]: 0 以上 10^i 未満の数字のうち、(桁の総和 mod D) が j となる場合の数
    vector dp(N + 1, vector<mint>(D));
    dp[0][0] = 1;
    rep2(i, 1, N + 1) {
        rep(j, 10) {
            rep(k, D) {
                int m = (j + k) % D;
                dp[i][m] += dp[i - 1][k];
            }
        }
    }

    // 1 ~ N-1 桁の数字のうち桁の総和が D の倍数となる場合の数
    mint ans = dp[N - 1][0] - 1;  // 0 分を 1 個引く

    // N 桁の数字のうち、最上位の桁がもともとの数字未満のときに D の倍数となる場合の数
    rep2(i, 1, K[0] - '0') {
        rep(j, D) {
            if ((i + j) % D == 0) {
                ans += dp[N - 1][j];
            }
        }
    }

    ll sum = (K[0] - '0') % D;
    rep2(i, 1, N) {
        int d = N - i;
        int upper = K[i] - '0';
        rep(j, upper) {
            rep(k, D) {
                if ((sum + j + k) % D == 0) {
                    ans += dp[d - 1][k];
                }
            }
        }

        sum += upper;
        sum %= D;
    }

    if (sum == 0) ans++;

    cout << ans.val() << endl;
}
```

### 桁 DP 解法

[こちらのサイト](https://web.archive.org/web/20170508234139/https://pekempey.hatenablog.com/entry/2015/12/09/000603)で桁 DP に関して勉強した。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string K;
    ll D;
    cin >> K >> D;

    int N = K.size();

    // dp[i][j][k]: 左から i 桁までは見て K 未満であることが確定して(j=0 いなくて, j=1 いて) 桁の総和の mod D が k となる場合の数
    vector dp(N + 1, vector(2, vector<mint>(D)));
    dp[0][0][0] = 1;

    rep2(i, 1, N + 1) {
        int t = K[i - 1] - '0';

        rep(d, 10) {
            rep(k, D) {
                if (d < t) {
                    dp[i][1][(d + k) % D] += dp[i - 1][0][k];
                }
                if (d == t) {
                    dp[i][0][(d + k) % D] += dp[i - 1][0][k];
                }
                dp[i][1][(d + k) % D] += dp[i - 1][1][k];
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][1][0] - 1).val() << endl;
}
```

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string K;
    ll D;
    cin >> K >> D;

    ll N = K.size();

    // dp[is_less][mod]
    vector dp(2, vector<mint>(D));
    dp[0][0] = 1;

    rep(i, N) {
        int t = K[i] - '0';
        vector dpn(2, vector<mint>(D));
        rep(d, 10) rep(is_less, 2) rep(k, D) {
            if (!is_less && d > t) continue;

            int is_less_n = is_less || d < t;
            int m = (d + k) % D;
            dpn[is_less_n][m] += dp[is_less][k];
        }

        swap(dp, dpn);
    }

    cout << (dp[0][0] + dp[1][0] - 1).val() << endl;
}
```
