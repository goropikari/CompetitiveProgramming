+++
date = '2026-02-26T14:31:43+09:00'
title = '最大フローの基礎と二部マッチングへの応用'
tags = ['最大フロー', '二部マッチング', 'Ford–Fulkerson', 'Dinic']
+++

## 解説

### 最大フロー問題とは？

* 有向グラフ
* 各辺に容量がある
* source `s` から sink `t` へ
* 容量制限内で流せる最大流量を求める

---

### 最大流最小カット定理

```
max flow = min cut
```

最大流の値と
s と t を分断する最小カットの容量は一致する。

---

### Ford–Fulkerson 法

#### アルゴリズムの流れ

1. s → t の増加パスを探す
2. 流せるだけ流す
3. パスが無くなるまで繰り返す

---

#### 計算量

```
O(FE)
```

* F = 最大流量
* E = 辺数

最大流が大きいと遅くなる可能性がある。

---

#### C++ 実装

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long cap;
    int rev;
};

struct FordFulkerson {
    int N;
    vector<vector<Edge>> G;
    vector<bool> used;

    FordFulkerson(int N) : N(N), G(N), used(N) {}

    void add_edge(int from, int to, long long cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }

    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        used[v] = true;
        for (auto &e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                long long d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while (true) {
            fill(used.begin(), used.end(), false);
            long long f = dfs(s, t, LLONG_MAX);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }
};
```

---

### Dinic 法（競プロ標準）

#### アルゴリズムの流れ

1. BFS でレベルグラフ構築
2. DFS でブロッキングフロー探索

---

#### 計算量

```
O(E √V)
```

単位容量グラフなどで高速。

---

#### C++ 実装

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to;
        long long cap;
        int rev;
    };

    int N;
    vector<vector<Edge>> G;
    vector<int> level, prog;

    Dinic(int N) : N(N), G(N), level(N), prog(N) {}

    void add_edge(int fr, int to, long long cap) {
        G[fr].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({fr, 0, (int)G[fr].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        for (int &i = prog[v]; i < G[v].size(); i++) {
            auto &e = G[v][i];
            if (e.cap <= 0 || level[e.to] != level[v] + 1) continue;
            long long ret = dfs(e.to, t, min(f, e.cap));
            if (ret > 0) {
                e.cap -= ret;
                G[e.to][e.rev].cap += ret;
                return ret;
            }
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(prog.begin(), prog.end(), 0);
            long long f;
            while ((f = dfs(s, t, LLONG_MAX)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};
```

---

### 二部マッチングへの応用

#### 二部マッチングとは？

* 左集合 L
* 右集合 R
* L と R の間の辺
* 各頂点は 1 回までマッチ可能

---

#### 最大フローへの変換

```
source → L → R → sink
```

* source → L の容量 = 1
* L → R の容量 = 1
* R → sink の容量 = 1

このとき

```
最大マッチング数 = 最大フロー
```

---

#### 実装例

```cpp
int main() {
    int L = 3;
    int R = 3;

    int s = L + R;
    int t = s + 1;

    Dinic mf(L + R + 2);

    for (int i = 0; i < L; i++) {
        mf.add_edge(s, i, 1);
    }

    for (int i = 0; i < R; i++) {
        mf.add_edge(L + i, t, 1);
    }

    mf.add_edge(0, L + 0, 1);
    mf.add_edge(0, L + 1, 1);
    mf.add_edge(1, L + 1, 1);
    mf.add_edge(2, L + 2, 1);

    cout << mf.max_flow(s, t) << endl;
}
```

---

### まとめ

* Ford–Fulkerson で概念理解
* Dinic が競プロ標準
* 二部マッチングは最大フローに帰着できる
* 最大流最小カットが理論的土台

## 問題集

最大流を段階的に練習できる問題集です。

### ★☆☆☆☆ 実装練習（そのまま最大流）

#### 🔹 AOJ GRL_6_A - Maximum Flow

🔗 <https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A>

{{< details "💡 ヒント" >}}
始点0、終点V-1 の最大流を求めるだけ。
Dinic / Ford–Fulkerson の実装確認用。
{{< /details >}}

---

#### 🔹 ABC 010 D - 浮気予防

🔗 <https://atcoder.jp/contests/abc010/tasks/abc010_4>

{{< details "💡 ヒント" >}}
女の子を sink に接続。
最小カットとして考える。
{{< /details >}}

---

#### 🔹 AWC 0013 E - アルバイトのシフト割り当て

<https://atcoder.jp/contests/awc0013/tasks/awc0013_e>

### ★★☆☆☆ 二部マッチング

#### 🔹 AOJ GRL_7_A - Bipartite Matching

🔗 <https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A>

{{< details "💡 ヒント" >}}
source → 左 → 右 → sink
容量はすべて1。
{{< /details >}}

---

#### 🔹 AOJ 1163 - Cards

🔗 <https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163>

{{< details "💡 ヒント" >}}
カードの組み合わせを辺として張る。
典型的なマッチング問題。
{{< /details >}}

---

#### 🔹 Educational DP Contest O - Matching

🔗 <https://atcoder.jp/contests/dp/tasks/dp_o>

{{< details "💡 ヒント" >}}
本質は二部マッチング。
ただし解法本筋はbitDP。
{{< /details >}}

---

#### 🔹 Typical 90 077 - Planes on a 2D Plane

🔗 <https://atcoder.jp/contests/typical90/tasks/typical90_bz>

{{< details "💡 ヒント" >}}
距離条件を満たすときに辺を張る。
マッチングに帰着。
{{< /details >}}

---

### ★★★☆☆ 利益最大化 → 最小カット

#### 🔹 ARC 085 C - HSI

🔗 <https://atcoder.jp/contests/arc085/tasks/arc085_c>

{{< details "💡 ヒント" >}}
選ぶなら source 側。
依存関係は無限容量。
{{< /details >}}

---

#### 🔹 ABC 193 F - Zebraness

🔗 <https://atcoder.jp/contests/abc193/tasks/abc193_f>

{{< details "💡 ヒント" >}}
市松模様 → 二部グラフ。
隣接制約は容量∞。
{{< /details >}}

---

#### 🔹 ARC 092 C - Both Sides Merger

🔗 <https://atcoder.jp/contests/arc092/tasks/arc092_c>

{{< details "💡 ヒント" >}}
正は source、負は sink。
依存は無限容量。
{{< /details >}}

---

### ★★★★☆ 応用（頂点分割・グリッド）

#### 🔹 ARC 074 F - Lotus Leaves

🔗 <https://atcoder.jp/contests/arc074/tasks/arc074_f>

{{< details "💡 ヒント" >}}
各マスを in/out に分割。
頂点容量制限。
{{< /details >}}

---

#### 🔹 ABC 205 F - Grid and Tokens

🔗 <https://atcoder.jp/contests/abc205/tasks/abc205_f>

{{< details "💡 ヒント" >}}
行と列の二部グラフ。
容量1マッチング。
{{< /details >}}

---

#### 🔹 AOJ GRL_6_B - Minimum Cost Flow

🔗 <https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B>

{{< details "💡 ヒント" >}}
これは最小費用流。
余裕があれば挑戦。
{{< /details >}}

---

## 学習ロードマップ

1. GRL_6_A
2. GRL_7_A
3. ABC010 D
4. ARC085 C
5. ARC074 F
6. 最小費用流へ
