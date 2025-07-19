+++
date = '2025-07-15T02:55:00+09:00'
title = 'Diverta2019'
tags = ['atcoder', 'abc']
+++

<https://atcoder.jp/contests/abcdiverta2019>

## A. Consecutive Integers

<https://atcoder.jp/contests/diverta2019/tasks/diverta2019_a>

## B. RGB Boxes

<https://atcoder.jp/contests/diverta2019/tasks/diverta2019_b>

## C. AB Substrings

<https://atcoder.jp/contests/diverta2019/tasks/diverta2019_c>

## D. DivRem Number

<https://atcoder.jp/contests/diverta2019/tasks/diverta2019_d>

条件より $N = qm + r = rm + r = r(m+1), (0 \leq r < m)$ となる。

ここで合成数 $M = ab, a<b$ について $a$ の候補は $\sqrt{N}$ までの整数であるから同様に $r$ の候補は $\sqrt{N}$ 以下である。
これを全探索して条件に見合う $m$ の値を見つければよい。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll ans = 0;
    for (ll r = 1; r * r <= N; r++) {
        if (N % r != 0) continue;
        ll m = N / r;
        m--;
        if (r < m) ans += m;
    }
    cout << ans << endl;
}
```

## E. XOR Partitioning

<https://atcoder.jp/contests/diverta2019/tasks/diverta2019_e>

## F. Edge Ordering

<https://atcoder.jp/contests/diverta2019/tasks/diverta2019_f>
