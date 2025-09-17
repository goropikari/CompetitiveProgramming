+++
date = '2025-09-15T15:10:26+09:00'
title = 'Code Festival 2014 予選A'
tags = ['atcoder', 'code festival']
+++

<https://atcoder.jp/contests/code-festival-2014-quala>

## D - 壊れた電卓

桁 DP の問題とわかった状態でものすごい時間をかけて自力で AC したが、嘘解放だった。
rate 高い人のコードを参考にしたがそれでも嘘解放が結構多かったので難しい問題と思われる。

A 以下の数のうち条件を満たす最大値と、A 以上の数のうち条件を満たす最小値を求めて、その差の最小値を求める問題。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, K;
    cin >> A >> K;

    string S = to_string(A);

    // dp[comp][used]
    // comp = 0: A と同じ
    // comp = 1: A より小さい
    // comp = 2: A より大きい
    // used: 使用した数の集合
    vector dp(3, vll(1 << 10, -1));
    dp[0][0] = 0;
    rep(j, 1 << 10) dp[2][j] = INF;

    int N = S.size();
    rep(i, N) {
        int t = S[i] - '0';
        vector dpn(3, vll(1 << 10, -1));
        rep(j, 1 << 10) dpn[2][j] = INF;

        rep(d, 10) rep(comp, 3) rep(used, 1 << 10) {
            if (dp[comp][used] < 0) continue;
            if (dp[comp][used] == INF) continue;
            int comp_n = comp;
            if (comp == 0) {
                if (d < t) comp_n = 1;
                if (d > t) comp_n = 2;
            }

            int used_n = used | (1 << d);
            if (used == 0 && d == 0) used_n = 0;  // 0 が続いている場合は 0 を使っていないとみなす

            if (comp_n <= 1) {
                chmax(dpn[comp_n][used_n], dp[comp][used] * 10 + d);
            } else {
                chmin(dpn[comp_n][used_n], dp[comp][used] * 10 + d);
            }
        }

        swap(dp, dpn);
    }

    ll ans = INF;
    {
        ll mx = 0;
        ll mi = INF;
        rep(used, 1 << 10) {
            if (__builtin_popcountll(used) > K) continue;
            chmax(mx, max(dp[0][used], dp[1][used]));
            chmin(mi, dp[2][used]);
        }
        chmin(ans, A - mx);
        chmin(ans, mi - A);
    }

    cout << ans << endl;
}
```

AC されているコードでも嘘解放が比較的多い

snuke 氏

<https://atcoder.jp/contests/code-festival-2014-quala/submissions/236393>

```text
input:
132420795125451_1

output:
912538207882

expected:
21309684014340
```

hamayanhamayan 氏

<https://atcoder.jp/contests/code-festival-2014-quala/submissions/1240951>

```text
input:
372606872877945 6

output:
57

expected:
55
```

semiexp 氏

<https://atcoder.jp/contests/code-festival-2014-quala/submissions/236122>

```text
input:
434142826127263 4

output:
284983848

expected:
173872737
```

sigma425 氏

<https://atcoder.jp/contests/code-festival-2014-quala/submissions/236806>

```text
input:
679231224974703 7

output:
8

expected:
4
```
