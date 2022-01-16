+++
title = "競プロ典型90問"
hascode = true
date = Date(2022, 1, 8)
+++
@def tags = ["atcoder"]


# [競プロ典型 90 問](https://atcoder.jp/contests/typical90)

\toc

```
##
[問題]()
[提出コード]()
```

## 001 - Yokan Party（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_a)

得られるスコアを二分探索で調べる.
長さ $x$ 以上のピースに分割したとき, $K+1$ 個以上ある場合は最低限スコア $x$ は達成でき, 逆に $K+1$ 個未満のときはスコア $x$ は達成できない.
(切りすぎたピースはくっつけて全体で $K+1$ 個にすればよいので判定時には $K+1$ 以上でよい)

判定するところを以下のように書いたら WA となった.
```cpp
void solve() {
    ll n, l, k;
    cin >> n >> l >> k;
    vector<ll> a(n+2, 0);
    rep(i,n) cin >> a[i+1];
    a[n+1] = l;

    ll ans = 0;
    ll ok = 1, ng = l;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll len = 0;
        int cnt = 0;
        rep2(i,1,n+2) {
            len += a[i] - a[i-1];
            if (len >= mid) {
                cnt++;
                len = 0;
            }
        }

        if (cnt > k) {
            ok = mid;
            chmax(ans, ok);
        } else {
            ng = mid;
        }
    }
    cout << ans << endl;
}
```

`chmax(ans, ok)` で `ans` が更新されるからこれで良いと思っていたのだが
$N = 1$, $L = 2$, $K = 1$, $A_1 = 1$ のとき答えは 1 であるが,
上のプログラムだと 0 を返していた.
このような条件のときに `while` の中にそもそも入らないのが原因だった.

そのため `ans` を使わない以下のように書けば AC になった.
```cpp
ll ok = 1, ng = l;
while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    ll len = 0;
    int cnt = 0;
    rep2(i,1,n+2) {
        len += a[i] - a[i-1];
        if (len >= mid) {
            cnt++;
            len = 0;
        }
    }

    if (cnt > k) {
        ok = mid;
    } else {
        ng = mid;
    }
}
cout << ok << endl;
```

[提出コード](https://atcoder.jp/contests/typical90/submissions/28374342)

## 002 - Encyclopedia of Parentheses（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_b)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28374549)

## 003 - Longest Circular Road（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_c)

木の直径を求める問題らしい.
木の直径は求め方はどれでもいいので node を一つ選び, そこから各ノードへの最短距離を計算. 一番遠い node を選んでそこからの最短距離をまた計算. 一番距離が遠いところが木の直径になるらしい.

サイクルがあることを考えてしまったがノード数 $N$, 辺の数 $N-1$ で連結グラフなのでサイクルの心配をする必要はなかった.

木なので最短距離は幅優先探索でも Dijkstra でもどっちでも大丈夫.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28375555)

## 004 - Cross Sum（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_d)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28375743)

## 005 - Restricted Digits（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_e)

スキップ

## 006 - Smallest Subsequence（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_f)

解説AC

```cpp
void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vvi nex(N+1, vi(26, 0));
    rep(i,26) nex[N][i] = N; // 残りの文字がないことを表す番兵

    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (S[i] - 'a' == j) nex[i][j] = i;
            else nex[i][j] = nex[i+1][j];
        }
    }

    string ans = "";
    int cur = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < 26; j++) {
            int nextPos = nex[cur][j];
            int numRem = N-1 - nextPos; // nextPos 以降にある文字の数
            int needNum = K - i; // K 文字構成するのに必要な残りの数
            if (numRem >= needNum) {
                ans.push_back(S[nextPos]);
                cur = nextPos + 1;
                break;
            }
        }
    }

    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/typical90/submissions/28452819)

## 008 - AtCounter（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_h)

ほぼ同じ問題を解いていたので解けた.
[類題: ABC C - chokudai](https://atcoder.jp/contests/abc211/tasks/abc211_c)

[提出コード](https://atcoder.jp/contests/typical90/submissions/28454325)

## 009 - Three Point Angle（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_i)

解説AC

[提出コード](https://atcoder.jp/contests/typical90/submissions/28480057)


## 010 - Score Sum Queries（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_j)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28455455)

## 011 - Gravy Jobs（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_k)

解説AC

報酬のことは一旦無視して, 決まった期間でどれだけ多くの仕事をできるかという問題を考えると
区間スケジューリング問題になる.
よって, まず締切が早い順に仕事をソートする.

次にソートした仕事順に, 総仕事時間が $x$ と決まっているときにその仕事をするかしないかを決めながら報酬の合計が
最大になるように選んでいく.
これはナップザック問題と同じである.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28498511)

## 012 - Red Painting（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_l)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28456062)

## 013 - Passing（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_m)

ノード1からとNからの2つのダイクストラをする.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28456319)

## 014 - We Used to Sing a Song Together（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_n)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28456403)

## 015 - Don't be too close（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_o)

スキップ

## 016 - Minimum Coins（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_p)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28467564)

## 017 - Crossing Segments（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_q)

スキップ

## 018 - Statue of Chokudai（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_r)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28468254)


## 019 - Pick Two（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_s)

[AOJ 連鎖行列積](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_B) と同じように解く

$f(l, r)$ を $[l, r)$ の範囲を取り除くときのコストの最小値とすると

\begin{align}
f(l, r) =
\min \left\{
    \begin{aligned}
        |A_l - A_{r-1}| + f(l+1, r-1), \\
        f(l,k) + f(k, r) ~~,k \in [l+1, r)
    \end{aligned}
\right\}
\end{align}
となる.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28482583)


## 020 - Log Inequality（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_t)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28482806)

## 021 - Come Back in One Piece（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_u)

解説AC

強連結成分分解

[Algorithms on Graphs](https://www.coursera.org/learn/algorithms-on-graphs) の講義でもやったらしいのだが覚えていなかった.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28493716)

## 022 - Cubic Cake（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_v)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28493234)
