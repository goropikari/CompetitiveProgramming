+++
date = '2025-03-17T00:46:28+09:00'
title = '競プロ典型 90 問'
+++

<https://atcoder.jp/contests/abctypical90>

# 001. Yokan Party（★4）

<https://atcoder.jp/contests/typical90/tasks/typical90_a>

解説 AC

最小値を最大化する問題は二分探索を使うのが定石らしい。

最小値を $m$ としたときの分割数が $K+1$ 以上ならば最小値を $m$ 以上にすることができる。そうでないならば最小値を $m$ にすることはできない。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, L, K;
    cin >> N >> L >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    A.insert(A.begin(), 0);
    A.push_back(L);
    vll diff;
    rep(i, N + 1) {
        diff.push_back(A[i + 1] - A[i]);
    }

    int m = diff.size();
    ll ac = 0, wa = L + 1;
    while (abs(ac - wa) > 1) {
        ll wj = (ac + wa) / 2;
        int i = 0;
        ll cnt = 0;
        ll sum = 0;
        rep(i, m) {
            sum += diff[i];
            if (sum >= wj) {
                sum = 0;
                cnt++;
            }
        }

        if (cnt >= K + 1) {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    cout << ac << endl;
}
```

# 002 - Encyclopedia of Parentheses（★3）

<https://atcoder.jp/contests/typical90/tasks/typical90_b>

DFS で解いたが bit 全探索が想定解法だったらしい。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1)
        return;

    map<int, set<string>> memo;

    auto dfs = [&](auto dfs, int k) -> set<string> {
        set<string> ans;
        if (memo.count(k))
            return memo[k];
        if (k == 0) {
            ans.insert("");
            return ans;
        }
        if (k == 2) {
            ans.insert("()");
            return ans;
        }

        for (int i = 2; i < k; i += 2) {
            auto l = dfs(dfs, i);
            auto r = dfs(dfs, k - i);
            memo[i] = l;
            memo[k - i] = r;

            for (auto sl : l) {
                for (auto sr : r) {
                    ans.insert(sl + sr);
                }
            }
        }

        for (auto s : memo[k - 2]) {
            ans.insert("(" + s + ")");
        }

        return ans;
    };

    auto ans = dfs(dfs, n);
    for (string s : ans)
        cout << s << endl;
}
```

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string> ans;
    rep(i, 1ll << n) {
        int cnt = 0;
        string s = "";
        int ok = 1;
        rep(j, n) {
            if ((i >> j) & 1) {  // )
                if (cnt) {
                    cnt--;
                    s.push_back(')');
                } else {
                    ok = 0;
                    break;
                }
            } else {  // (
                cnt++;
                s.push_back('(');
            }
        }
        if (ok && cnt == 0) {
            ans.insert(s);
        }
    }

    for (auto s : ans)
        cout << s << endl;
}
```

# 003 - Longest Circular Road（★4）

<https://atcoder.jp/contests/typical90/tasks/typical90_c>

木の直径 + 1 が答え。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vvint graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vll dist(n, -1);
    ll mi = -1, md = -1;
    dist[0] = 0;

    auto dfs = [&](auto dfs, int now, int p) -> void {
        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            dist[nx] = dist[now] + 1;
            if (md < dist[nx]) {
                md = dist[nx];
                mi = nx;
            }
            dfs(dfs, nx, now);
        }
    };

    dfs(dfs, 0, -1);
    dist = vll(n, -1);
    dist[mi] = 0;
    dfs(dfs, mi, -1);

    md = *max_element(all(dist));
    cout << md + 1 << endl;
}
```

# 004 - Cross Sum（★2）

<https://atcoder.jp/contests/typical90/tasks/typical90_d>

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vvint grid(h, vint(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];
    vint sumh(h, 0), sumw(w, 0);
    rep(i, h) rep(j, w) {
        sumh[i] += grid[i][j];
        sumw[j] += grid[i][j];
    }

    rep(i, h) {
        rep(j, w) {
            if (j != 0)
                cout << ' ';
            cout << sumh[i] + sumw[j] - grid[i][j];
        }
        cout << endl;
    }
}
```

# 005 - Restricted Digits（★7）

昔解説を読んで何を言っているのかわからなかった記憶があるが、3年ぶりに取り組んでなんとか解説読まずに AC できた。

桁数が最大で $10^18$ と大きいのでダブリングを使う。
$dp(i,j)$ を $2^i$ 桁の $B$ で割ったときの余りが $j$ となる場合の数とすると

\begin{align*}
    dp(i+1,j) = \sum_{j \equiv p \times 10^{2^i} + q \mod B} dp(i,p) \times dp(i,q)
\end{align*}

となる。

具体的に入力例1 のケースで考えてみる。
$B=7$ なので

\begin{align*}
    1 \equiv 1 \mod 7 \\\\
    4 \equiv 4 \mod 7 \\\\
    9 \equiv 2 \mod 7
\end{align*}

である。よって $dp(0, 1) = 1$, $dp(0, 2) = 1$, $dp(0,4) = 1$.

$1, 4, 9$ から作られる2桁の数は $11, 14, 19, 41, 44, 49, 91, 94, 99$ の9通りでありそれぞれ $B$ で割ったときの余りは

\begin{align*}
    11 &\equiv (10 \mod 7) + 1           \equiv 4 \mod 7 \\\\
    14 &\equiv (10 \mod 7) + 4           \equiv 0 \mod 7 \\\\
    19 &\equiv (10 \mod 7) + 9           \equiv 5 \mod 7 \\\\
    41 &\equiv (4 \mod 7)(10 \mod 7) + 1 \equiv 6 \mod 7 \\\\
    44 &\equiv (4 \mod 7)(10 \mod 7) + 4 \equiv 2 \mod 7 \\\\
    49 &\equiv (4 \mod 7)(10 \mod 7) + 9 \equiv 0 \mod 7 \\\\
    91 &\equiv (9 \mod 7)(10 \mod 7) + 1 \equiv 0 \mod 7 \\\\
    94 &\equiv (9 \mod 7)(10 \mod 7) + 4 \equiv 3 \mod 7 \\\\
    99 &\equiv (9 \mod 7)(10 \mod 7) + 9 \equiv 1 \mod 7
\end{align*}

であるので

\begin{align*}
    dp(1, 0) = 3 \\\\
    dp(1, 1) = 1 \\\\
    dp(1, 2) = 1 \\\\
    dp(1, 3) = 1 \\\\
    dp(1, 4) = 1 \\\\
    dp(1, 5) = 1 \\\\
    dp(1, 6) = 1
\end{align*}

となる。これを一般化すると

\begin{align*}
    dp(i+1,j) = \sum_{j \equiv p \times 10^{2^i} + q \mod B} dp(i,p) \times dp(i,q)
\end{align*}

になる。

$N$ 桁の数の場合の数を求めるときは $N = \sum_i c_i 2^i$ と展開したとき $c_i = 1$ となる全ての $i$ に対して
$ans(m) = \sum_{m \equiv j \times 10^{2^i} + k \mod B} ans(j) \times dp(i,k)$ を $i$ が小さい方から計算していけば良い。
ここで $ans(0) = 1, ans(m) = 0 \text{ where } m \neq 0$ である。

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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, b, k;
    cin >> n >> b >> k;
    vll cs(k);
    rep(i, k) cin >> cs[i];

    vector<vector<mint>> dp(63, vector<mint>(b, 0));
    for (ll x : cs)
        dp[0][x % b]++;

    vll tenth(63, 0);
    rep(i, 63) {
        tenth[i] = modpow(10, 1ll << i, b);
    }

    rep2(i, 1, 63) {
        rep(j, b) {
            rep(k, b) {
                dp[i][(tenth[i - 1] * j + k) % b] += dp[i - 1][j] * dp[i - 1][k];
            }
        }
    }

    vector<mint> ans(b, 0);
    ans[0] = 1;
    rep(i, 63) {
        vector<mint> tmp(b, 0);
        if (n & 1) {
            rep(j, b) {
                rep(k, b) {
                    tmp[(tenth[i] * j + k) % b] += ans[j] * dp[i][k];
                }
            }
            swap(tmp, ans);
        }
        n /= 2ll;
    }
    cout << ans[0].val() << endl;
}
```
