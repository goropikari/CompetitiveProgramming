+++
date = '2026-03-01T23:45:30+09:00'
title = '木 DP (ABC Tree DP)'
tags = ["tree_dp"]
+++

## 🌳 木DP 問題集

AtCoder と AOJ から、木DPを体系的に学べる問題を難易度順にまとめました。

---

## 🌱 初級

### 1. ABC036 D - 塗り絵

- 🔗 <https://atcoder.jp/contests/abc036/tasks/abc036_d>

<details>
<summary>💡 ヒント</summary>

**テーマ：最大独立集合 / 0-1 木DP**

頂点 $v$ について

- $dp[v][0]$ : vを選ばない
- $dp[v][1]$ : vを選ぶ

状態遷移：

$dp[v][0] = \prod_{u \in child(v)} (dp[u][0] + dp[u][1])$

$dp[v][1] = \prod_{u \in child(v)} dp[u][0]$

DFSで子から順に計算する。

</details>

---

### 2. ABC138 D - Ki

- 🔗 <https://atcoder.jp/contests/abc138/tasks/abc138_d>

<details>
<summary>💡 ヒント</summary>

**テーマ：木上の累積和**

根からDFSを行い、

`value[child] += value[parent]`

と親から子へ値を伝播させる。

</details>

---

### 3. AOJ GRL_5_A - Diameter of a Tree

- 🔗 <https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A>

<details>
<summary>💡 ヒント</summary>

**テーマ：木の直径**

1. 任意の頂点から最遠点 $u$ を求める
2. $u$ から最遠点を求める

これが直径になる。

木DPというより2回DFS。

</details>

<details>
<summary>💡 解説</summary>

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    using P = pair<ll, ll>;
    vector<vector<P>> to(N);
    rep(i, N - 1) {
        ll s, t, w;
        cin >> s >> t >> w;
        to[s].pb({t, w});
        to[t].pb({s, w});
    }

    ll ans = 0;
    auto dfs = [&](auto dfs, int now, int p, ll sum) -> ll {
        ll mx = 0;
        for (auto [nx, w] : to[now]) {
            if (nx == p) continue;
            ll r = dfs(dfs, nx, now, w);
            chmax(ans, mx + r);
            chmax(mx, r);
        }

        return sum + mx;
    };

    dfs(dfs, 0, -1, 0);
    cout << ans << endl;
}
```

</details>

---

## 🌿 初中級

### 4. ABC160 F - Distributing Integers

- 🔗 <https://atcoder.jp/contests/abc160/tasks/abc160_f>

<details>
<summary>💡 ヒント</summary>

**テーマ：re-rooting DP（全方位木DP）**

1. まず根を固定して部分木DPを計算
2. 親から子へ値を渡す

親方向からの寄与を持たせるのが本質。

</details>

---

### 5. ABC220 F - Distance Sums 2

- 🔗 <https://atcoder.jp/contests/abc220/tasks/abc220_f>

<details>
<summary>💡 ヒント</summary>

**テーマ：全頂点からの距離和 / re-rooting**

部分木サイズを $sz[v]$ とすると、

$ans[child] = ans[parent] - sz[child] + (N - sz[child])$

1. まず1頂点を根として距離和を求める
2. 上式で re-root する

部分木サイズを事前に計算しておく。

</details>

---

## 🌲 中級

### 6. ARC112 C - DFS Game

- 🔗 <https://atcoder.jp/contests/arc112/tasks/arc112_c>

<details>
<summary>💡 ヒント</summary>

**テーマ：部分木マージDP**

子のDPを順番にマージする。

小さいDPからマージすると高速化できる場合もある（small-to-large）。

</details>

---

### 7. ABC222 F - Expensive Expense

- 🔗 <https://atcoder.jp/contests/abc222/tasks/abc222_f>

<details>
<summary>💡 ヒント</summary>

**テーマ：重み付き木 + re-rooting**

- 各頂点からの「部分木内最遠距離」を管理
- 親側からの最大値も持つ

「内側最大」と「外側最大」を分けて考える。

</details>

---

## 🌳 上級

### 8. AGC009 C - Division into Two

- 🔗 <https://atcoder.jp/contests/agc009/tasks/agc009_c>

<details>
<summary>💡 ヒント</summary>

**テーマ：木DP + 数え上げ**

制約を整理し、部分木ごとに組み合わせを数える。

mod計算と場合分けが多い。

</details>

---

## 🎯 木DPパターン整理

<details>
<summary>💡 代表的なパターン</summary>

### ① 足し上げ型

$dp[v] = \sum_{u \in child(v)} dp[u]$

---

### ② 0/1 型

頂点を選ぶ / 選ばない

---

### ③ マージ型

部分木DPを順番に統合する。

---

### ④ re-rooting 型

$ans[child] = ans[parent] + \Delta$

親から子へ値を渡すのが本質。

</details>

---

## 🚀 学習順おすすめ

1. ABC036 D
2. ABC160 F
3. ABC220 F
4. ARC112 C
5. AGC系

---
