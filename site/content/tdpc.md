+++
date = '2025-07-22T22:57:03+09:00'
title = 'Typical DP Contest'
tags = ['atcoder', 'dp', 'tdpc']
+++

<https://atcoder.jp/contests/abctdpc>

## A. コンテスト

<https://atcoder.jp/contests/tdpc/tasks/tdpc_contest>

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll P(N);
    rep(i, N) cin >> P[i];

    int mx = (int)1e5 + 5;
    vector<bool> dp(mx);
    dp[0] = true;

    rep(i, N) {
        for (ll p = mx - 1; p >= 0; p--) {
            if (p - P[i] >= 0 && dp[p - P[i]]) {
                dp[p] = true;
            }
        }
    }

    ll ans = 0;
    rep(i, mx) ans += dp[i];
    cout << ans << endl;
}
```

## B. ゲーム

<https://atcoder.jp/contests/tdpc/tasks/tdpc_game>

2日かけて自力 AC.

$f(a,b)$ を左の山のものを $a$ 個、右の山のものを $b$ 個使用された状態で自分の手番が回ってきたときに獲得できる価値の最大値とする。
また残っている物の価値の合計を $S$ とする。
$A$ の山から物を取って相手に手番を渡したとき相手が得る価値は $f(a+1,b)$、$B$ の山から物を取って相手に手番を渡したとき相手が得る価値は $f(a,b+1)$ である。

自分の手番での最適な行動は相手の獲得できる価値を最小化することであるから $f(a,b) = S - \min\{f(a+1,b), f(a,b+1)\}$ である。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vll A(N + 1), B(M + 1);
    rep(i, N) cin >> A[i + 1];
    rep(i, M) cin >> B[i + 1];

    ll sum = accumulate(all(A), 0ll) + accumulate(all(B), 0ll);

    vvll memo(N + 1, vll(M + 1));

    auto f = [&](auto f, ll rem, int a = 0, int b = 0) -> ll {
        if (memo[a][b]) return memo[a][b];
        if (a == N && b == M) return 0;

        ll l = INF, r = INF;
        if (a + 1 <= N)
            l = f(f, rem - A[a + 1], a + 1, b);
        if (b + 1 <= M)
            r = f(f, rem - B[b + 1], a, b + 1);

        return memo[a][b] = max(rem - l, rem - r);
    };

    cout << f(f, sum) << endl;
}
```

2026/1/2 追記

すぬけくんが獲得する得点を $X$、すめけくんが獲得する得点を $Y$ とすると $X-Y$ を最大化するようにゲームを進めることと同値である。

<!-- dprint-ignore -->
\begin{align*}
    S &= X+Y = \sum_i a_i + \sum_j b_j, \\\\
    Q &= X-Y
\end{align*}

とすると $X = (S+Q)/2$ であるから $X-Y$ の最大値を求めることができれば $X$ の最大値を求めることができる。

<https://drken1215.hatenablog.com/entry/2023/07/22/031100> と同じようにして解ける

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B;
    cin >> A >> B;
    vll a(A), b(B);
    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];

    vvll dp(A + 1, vll(B + 1, -INF));

    auto dfs = [&](auto dfs, int i, int j) -> ll {
        if (dp[i][j] != -INF) return dp[i][j];

        ll ret = -INF;
        if (i < A)
            chmax(ret, -dfs(dfs, i + 1, j) + a[i]);
        if (j < B)
            chmax(ret, -dfs(dfs, i, j + 1) + b[j]);
        if (ret == -INF) ret = 0;

        return dp[i][j] = ret;
    };

    ll xmy = dfs(dfs, 0, 0);
    ll xpy = accumulate(all(a), 0ll) + accumulate(all(b), 0ll);

    cout << (xpy + xmy) / 2 << endl;
}
```

## C. トーナメント

<https://atcoder.jp/contests/tdpc/tasks/tdpc_tournament>

### 解説

このコードは、動的計画法(DP)を再帰関数（分割統治法）で実装しています。

DPテーブルの定義は以下の通りです。
`dp[k][i]`：選手 `i` が `k` 回戦を勝ち抜く確率

- **初期状態:**
  `dp[0][i] = 1`
  $0$ 回戦の時点では全員が勝ち残っているため、確率は1となります。これはコードの `rep(i, 1 << K) dp[0][i] = 1;` に対応します。

- **遷移 (再帰関数 `dfs` の動作):**
  関数 `dfs(l, r, k)` は、選手 `l` から `r-1` までの選手が参加するトーナメント（$k$ 回戦）について、各選手の勝利確率を計算します。

  1. **分割:** まず、`k-1` 回戦の結果が必要なため、`dfs(l, m, k-1)` と `dfs(m, r, k-1)` を再帰的に呼び出します（`m` は `l` と `r` の中間）。これにより、トーナメント表のより下のブロックから先に確率が計算されていきます。

  2. **計算:** `k-1` 回戦の結果が `dp[k-1]` に計算された後、`k` 回戦の確率 `dp[k][i]` を計算します。
      - 選手 `i` が `k` 回戦で、特定の相手 `j` に勝って勝ち上がるシナリオを考えます。この事象が起こる確率は、以下の3つの独立な事象の確率の積となります。
          1. `i` が `k-1` 回戦までを勝ち抜く確率: `dp[k-1][i]`
          2. `j` が `k-1` 回戦までを勝ち抜く確率: `dp[k-1][j]`
          3. `i` が `j` との直接対決で勝つ確率: `prob(R[i], R[j])`
      - `i` が `k` 回戦を勝ち抜く確率は、対戦する可能性のある全ての相手 `j` について、上記のシナリオの確率を合計したものです。
        $dp[k][i] = \sum_{j \in \text{opponents}} (dp[k-1][i] \times dp[k-1][j] \times P(i \text{ beats } j))$
      - この式から `dp[k-1][i]` を因数として外に出すと、コードの計算式と一致します。
        $dp[k][i] = dp[k-1][i] \times \sum_{j \in \text{opponents}} (dp[k-1][j] \times P(i \text{ beats } j))$

      これがコード内の以下の部分に対応します。

      ```cpp
      // dp[k][i] = dp[k-1][i] * (Σ_{j in opponent_block} dp[k-1][j] * P(i beats j))

      // 左ブロックの選手 i について計算
      rep2(i, l, m) {
          double sum_prob_win_vs_opponent = 0;
          rep2(j, m, r) {
              sum_prob_win_vs_opponent += dp[k - 1][j] * prob(R[i], R[j]);
          }
          dp[k][i] = dp[k - 1][i] * sum_prob_win_vs_opponent;
      }
      ```

      (※実際のコードでは `+=` と `*=` を使って1行で計算しています)

      右ブロックの選手についても同様の計算を行います。

- **答え:**
  最終的に `dfs(0, 1 << K, K)` を呼び出すことで、`dp[K]` に全選手が $K$ 回戦を勝ち抜く（＝優勝する）確率が計算されます。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll K;
    cin >> K;
    vll R(1 << K);
    rep(i, 1ll << K) cin >> R[i];

    // dp[k][i]: k 回戦目に選手 i が勝ち上がる確率
    vector<vector<double>> dp(K + 1, vector<double>(1 << K));
    rep(i, 1 << K) dp[0][i] = 1;

    auto prob = [](ll rp, ll rq) -> double {
        double den = 1.0 + pow(10, (double)(rq - rp) / 400.0);
        return 1.0 / den;
    };

    // [l, r) の範囲でトーナメントを行い、k 回戦目の勝率を計算する
    auto dfs = [&](auto dfs, int l, int r, int k) -> void {
        if (k == 0) return;

        int m = (l + r) / 2;
        dfs(dfs, l, m, k - 1);
        dfs(dfs, m, r, k - 1);

        // 左側の選手 i が右側の選手 j に勝つ確率は、選手 i が k-1 回勝ち上がる、かつ、選手 j が k-1 回勝ち上がる、かつ、i が j に勝つ確率の積である。
        // これを右側の選手について和をとる。
        rep2(i, l, m) {
            rep2(j, m, r) {
                double p = prob(R[i], R[j]);
                dp[k][i] += dp[k - 1][j] * p;
            }
            dp[k][i] *= dp[k - 1][i];
        }

        // 右側の選手 i が左側の選手 j に勝つ確率も同様に計算する。
        rep2(i, m, r) {
            rep2(j, l, m) {
                dp[k][i] += dp[k - 1][j] * prob(R[i], R[j]);
            }
            dp[k][i] *= dp[k - 1][i];
        }
    };

    dfs(dfs, 0, 1 << K, K);

    for (auto x : dp[K]) {
        printf("%.9lf\n", x);
    }
}
```

## D. サイコロ

<https://atcoder.jp/contests/tdpc/tasks/tdpc_dice>

## E. 数

<https://atcoder.jp/contests/tdpc/tasks/tdpc_number>

## F. 準急

<https://atcoder.jp/contests/tdpc/tasks/tdpc_semiexp>

## G. 辞書順

<https://atcoder.jp/contests/tdpc/tasks/tdpc_lexicographical>

## H. ナップザック

<https://atcoder.jp/contests/tdpc/tasks/tdpc_knapsack>

解説 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, W, C;
    cin >> N >> W >> C;

    using T = tuple<ll, ll, ll>;
    vector<T> vs;
    vs.emplace_back(0, 0, 0);
    rep(i, N) {
        ll w, v, c;
        cin >> w >> v >> c;
        vs.emplace_back(w, v, c);
    }
    sort(all(vs), [](T a, T b) -> bool {
        return get<2>(a) < get<2>(b);
    });

    vector dp(W + 1, vector(C + 1, vll(2, -INF)));
    dp[0][0][0] = 0;

    rep2(i, 1, N + 1) {
        vector dpn(W + 1, vector(C + 1, vll(2, -INF)));
        dpn[0][0][0] = 0;

        auto [pw, pv, pc] = vs[i - 1];
        auto [tw, tv, tc] = vs[i];

        rep(w, W + 1) {
            rep(k, C + 1) {
                chmax(dpn[w][k][0], dp[w][k][0]);
                if (pc == tc) {
                    if (w - tw >= 0) {
                        chmax(dpn[w][k][1], dp[w - tw][k][1] + tv);
                        if (k - 1 >= 0)
                            chmax(dpn[w][k][1], dp[w - tw][k - 1][0] + tv);
                    }
                    chmax(dpn[w][k][1], dp[w][k][1]);
                } else {
                    if (w - tw >= 0 && k - 1 >= 0) {
                        chmax(dpn[w][k][1], dp[w - tw][k - 1][0] + tv);
                        chmax(dpn[w][k][1], dp[w - tw][k - 1][1] + tv);
                    }
                    chmax(dpn[w][k][0], dp[w][k][1]);
                }
            }
        }
        swap(dp, dpn);
    }

    ll ans = 0;
    for (auto& v : dp)
        for (auto& vv : v)
            chmax(ans, *max_element(all(vv)));
    cout << ans << endl;
}
```

## I. イウィ

<https://atcoder.jp/contests/tdpc/tasks/tdpc_iwi>

## J. ボール

<https://atcoder.jp/contests/tdpc/tasks/tdpc_ball>

## K. ターゲット

<https://atcoder.jp/contests/tdpc/tasks/tdpc_target>

## L. 猫

<https://atcoder.jp/contests/tdpc/tasks/tdpc_cat>

## M. 家

<https://atcoder.jp/contests/tdpc/tasks/tdpc_house>

## N. 木

<https://atcoder.jp/contests/tdpc/tasks/tdpc_tree>

## O. 文字列

<https://atcoder.jp/contests/tdpc/tasks/tdpc_string>

## P. うなぎ

<https://atcoder.jp/contests/tdpc/tasks/tdpc_eel>

## Q. 連結

<https://atcoder.jp/contests/tdpc/tasks/tdpc_concatenation>

## R. グラフ

<https://atcoder.jp/contests/tdpc/tasks/tdpc_graph>

## S. マス目

<https://atcoder.jp/contests/tdpc/tasks/tdpc_grid>

## T. フィボナッチ

<https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>
