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

## C. トーナメント

<https://atcoder.jp/contests/tdpc/tasks/tdpc_tournament>

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
