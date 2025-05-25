+++
date = '2025-03-17T00:46:28+09:00'
title = '競プロ典型 90 問'
+++

<https://atcoder.jp/contests/abctypical90>

## 001. Yokan Party（★4）

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

## 002 - Encyclopedia of Parentheses（★3）

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

## 003 - Longest Circular Road（★4）

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

## 004 - Cross Sum（★2）

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

## 005 - Restricted Digits（★7）

昔解説を読んで何を言っているのかわからなかった記憶があるが、3年ぶりに取り組んでなんとか解説読まずに AC できた。

桁数が最大で $10^18$ と大きいのでダブリングを使う。
$dp(i,j)$ を $2^i$ 桁の $B$ で割ったときの余りが $j$ となる場合の数とすると

<!-- dprint-ignore -->
\begin{align*}
    dp(i+1,j) = \sum_{j \equiv p \times 10^{2^i} + q \mod B} dp(i,p) \times dp(i,q)
\end{align*}

となる。

具体的に入力例1 のケースで考えてみる。
$B=7$ なので

<!-- dprint-ignore -->
\begin{align*}
    1 \equiv 1 \mod 7 \\\\
    4 \equiv 4 \mod 7 \\\\
    9 \equiv 2 \mod 7
\end{align*}

である。よって $dp(0, 1) = 1$, $dp(0, 2) = 1$, $dp(0,4) = 1$.

$1, 4, 9$ から作られる2桁の数は $11, 14, 19, 41, 44, 49, 91, 94, 99$ の9通りでありそれぞれ $B$ で割ったときの余りは

<!-- dprint-ignore -->
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

<!-- dprint-ignore -->
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

<!-- dprint-ignore -->
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

## 006 - Smallest Subsequence（★5）

解説 AC.

辞書順最小は貪欲が定石らしい。

文字 $\alpha \in \\\{ a, b, \cdots, z \\\}$ が $i$ 番目以降($i$ 番目も含む)に出る位置を $\mathrm{nex}(\alpha, i)$ とする。
$i=0$ から始め、各 $i$ について $a$ から見ていき、

- 長さ $K$ の文字列を作れるなら採用。$i$ の値を $\mathrm{nex}(i,a)+1$ に更新。$K$ を 1 減らす。
- できないなら文字 $b$ について確かめ、それでもできないなら文字 $c$ について確かめる・・・と繰り返す。

$K$ 文字になるまで上記の操作を繰り返すと答えが求まる。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vvint nex(26, vint(n + 1, n));
    for (int id = n - 1; id >= 0; id--) {
        rep(j, 26) {
            if (s[id] - 'a' == j) {
                nex[j][id] = id;
            } else if (id < n - 1) {
                nex[j][id] = nex[j][id + 1];
            }
        }
    }

    string ans = "";
    int i = 0;
    while (k) {
        rep(j, 26) {
            if (n - nex[j][i] >= k) {
                ans.push_back('a' + j);
                i = nex[j][i] + 1;
                break;
            }
        }
        k--;
    }
    cout << ans << endl;
}
```

## 007 - CP Classes（★3）

$A$ を sort して $B_i$ の値で二分探索して前後にある数字との差の絶対値のうち最小を出力

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    int q;
    cin >> q;
    vll b(q);
    rep(i, q) cin >> b[i];

    sort(all(a));

    ll ans = 0;
    for (ll x : b) {
        auto it = lower_bound(all(a), x);
        ll t = INF;
        if (it != a.begin()) {
            chmin(t, abs(x - *prev(it)));
        }
        if (it != a.end()) {
            chmin(t, abs(x - *it));
        }
        cout << t << endl;
    }
}
```

## 008 - AtCounter（★3）

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<vector<mint>> dp(n + 1, vector<mint>(8));
    rep(i, n + 1) dp[i][0] = 1;

    string atcoder = "_atcoder";

    s = "_" + s;

    rep2(i, 1, n + 1) {
        rep2(j, 1, 8) {
            if (s[i] == atcoder[j]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][7].val() << endl;
}
```

## 009 - Three Point Angle（★6）

解説 AC.

2つの候補に自分自身が含まれる場合あるけどそれは大丈夫なのか納得できていない
<https://github.com/E869120/kyopro_educational_90/blob/main/sol/009.cpp#L58-L63>

### 010 - Score Sum Queries（★2）

1組用、2組用の累積和を持っておいてクエリに対して答える。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vll c(n), pt(n);
    rep(i, n) {
        cin >> c[i] >> pt[i];
        c[i]--;
    }

    vvll cumsum(2, vll(n + 1));
    rep(i, n) {
        rep(j, 2) cumsum[j][i + 1] += cumsum[j][i];

        if (c[i] == 0) {
            cumsum[0][i + 1] += pt[i];
        } else {
            cumsum[1][i + 1] += pt[i];
        }
    }

    int q;
    cin >> q;
    rep(_, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << cumsum[0][r + 1] - cumsum[0][l] << ' ' << cumsum[1][r + 1] - cumsum[1][l] << endl;
    }
}
```

### 011 - Gravy Jobs（★6）

解説 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Work> ws;
    rep(i, n) {
        ll d, c, s;
        cin >> d >> c >> s;
        ws.emplace_back(d, c, s);
    }
    sort(all(ws));

    ws.insert(ws.begin(), {0, 0, 0});

    // dp[i][j]: i 番目までの仕事をこなした状態での j 日目時点での報酬の最大値
    vvll dp(n + 1, vll(5005, 0));
    rep2(i, 1, n + 1) {
        rep2(j, 1, 5005) {
            // i 番目の仕事をしない
            chmax(dp[i][j], dp[i - 1][j]);

            // i 番目の仕事をする
            if (j <= ws[i].d && j - ws[i].c >= 0) {
                chmax(dp[i][j], dp[i - 1][j - ws[i].c] + ws[i].s);
            }
        }
    }

    ll ans = 0;
    rep(i, 5005) chmax(ans, dp[n][i]);
    cout << ans << endl;
}
```

## 012 - Red Painting（★4）

union find で管理

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    int q;
    cin >> q;

    auto sub2id = [&](int i, int j) -> int {
        return i * w + j;
    };

    vvint grid(h, vint(w, 0));
    dsu uf(h * w);

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            grid[r][c] = 1;

            rep(d, 4) {
                int ni = r + di[d], nj = c + dj[d];
                if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
                    continue;
                if (grid[ni][nj] == 1)
                    uf.merge(sub2id(r, c), sub2id(ni, nj));
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            yesno(grid[ra][ca] == 1 && grid[rb][cb] == 1 && uf.same(sub2id(ra, ca), sub2id(rb, cb)));
        }
    }
}
```

## 013 - Passing（★5）

start, goal からダイクストラ

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vvll dists(2);
    vint nows = {0, n - 1};

    rep(k, 2) {
        int now = nows[k];

        vll dist(n, INF);
        dist[now] = 0;

        // dist, id
        using P = pair<ll, ll>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, now});
        while (pq.size()) {
            auto [cost, id] = pq.top();
            pq.pop();

            if (dist[id] < cost)
                continue;

            for (auto [nx, w] : graph[id]) {
                if (dist[nx] <= dist[id] + w)
                    continue;

                dist[nx] = dist[id] + w;
                pq.push({dist[nx], nx});
            }
        }

        dists[k] = dist;
    }

    rep(i, n) {
        cout << dists[0][i] + dists[1][i] << endl;
    }
}
```

## 014 - We Used to Sing a Song Together（★3）

人と学校の結んだ線がクロスしてもいいことないのでどっちも sort して左から割り当てていく。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    sort(all(a));
    sort(all(b));
    ll ans = 0;
    rep(i, n) ans += abs(a[i] - b[i]);
    cout << ans << endl;
}
```
