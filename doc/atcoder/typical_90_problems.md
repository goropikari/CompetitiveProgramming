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

どの2つのボールについても書かれている数字が $k$ 以上離れているように $a$ 個のボールを選んでくる.
また, ボールの数字を小さい順に $1 \leq b_1 < b_2 < \cdots < b_M \leq N$ とする.

\begin{align}
\left\{
    \begin{aligned}
        b_1^\prime &= b_1 \\
        b_2^\prime &= b_2 - (k-1) \\
        \vdots \\
        b_M^\prime &= b_M - (M-1)(k-1)
    \end{aligned}
\right.
\end{align}
と定義すると $1 \leq b_1^\prime < b_2^\prime < \cdots < b_M^\prime \leq N - (M-1)(k-1)$ となる.
$\{b_i^\prime\}$ の組み合わせを決めると $\{b_i\}$ の組み合わせが一意に定まるから, $\comb{N-(M-1)(k-1)}{M}$ を計算すれば良い.

以上より, $k$ が固定したとき $\displaystyle \sum_{M}\comb{N-(M-1)(k-1)}{M}$.
ここで sum は $\displaystyle N-(M-1)(k-1) \geq M \Leftrightarrow M \leq \frac{N-1}{k} + 1 \leq \frac{N}{k} + 1$
より, combination の計算が $O(1)$ でできれば, 問題は $O(N\log N)$ で解ける.


調和級数が $O(N\log N)$ に収まる理由.
\begin{align}
    \sum_{k=1}^N \frac{N}{k} < \int^N_1 dk \frac{N}{k} = N \ln k \left.\right|^N_1 = N\ln N
\end{align}

[提出コード](https://atcoder.jp/contests/typical90/submissions/28618080)

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


## 023 - Avoid War（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_w)

スキップ

## 024 - Select +／- One（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_x)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28618532)


## 025 - Digit Product Equation（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_y)

スキップ

## 026 - Independent Set on a Tree（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_z)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28619196)


## 027 - Sign Up Requests （★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_aa)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28635533)


## 028 - Cluttered Paper（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ab)

2次元いもす法

[提出コード](https://atcoder.jp/contests/typical90/submissions/28636386)

## 029 - Long Bricks（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ac)

スキップ

遅延セグメント木で解くらしいが interval tree でもできる気がする.

## 030 - K Factors（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ad)

エラトステネスと同じ要領.

エラトステネスのふるいを使って高速に素因数分解する osa_k 法はこちらの記事がわかりやすかった.
https://blog.manuel1024.com/archives/79

[提出コード](https://atcoder.jp/contests/typical90/submissions/28648799)

## 031 - VS AtCoder（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ae)

スキップ

## 032 - AtCoder Ekiden（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_af)

$N = 10$ と小さいので `next_permutation` を使って素直に全探索で解ける.

$N = 18$ のとき, $18! = 6402373705728000$ となり, `next_permutation` 実装だと TLE になる.
この場合は DP で解ける.

$dp[S][x]$: すでに走った人の集合 $S$, 最後に走った人を $x$ とすると

$\displaystyle dp[S][x] = \min_k dp[S\backslash \{k\}][k] + A[k][|S|]$ となる.


- [提出コード 順列全探索](https://atcoder.jp/contests/typical90/submissions/28649102)
- [提出コード DP](https://atcoder.jp/contests/typical90/submissions/28650112)

## 033 - Not Too Bright（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ag)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28665856)

## 034 - There are few types of elements（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ah)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28666289)


## 035 - Preserve Connectivity（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ai)

スキップ

## 036 - Max Manhattan Distance（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_aj)

\begin{align}
    |x_i - x_j| + |y_i - y_j|
        &= \max
        \left\{
            \begin{aligned}
                x_i - x_j + y_i - y_j, \\
                -(x_i - x_j) + y_i - y_j, \\
                x_i - x_j - (y_i - y_j),\\
                -(x_i - x_j) - (y_i - y_j)
            \end{aligned}
        \right\} \\
        &= \max
        \left\{
            \begin{aligned}
                x_i + y_i - (x_j + y_j), \\
                -(x_i - y_i) + (x_j - y_j), \\
                (x_i - y_i) - (x_j - y_j), \\
                -(x_i + y_i) + (x_j + y_j)
            \end{aligned}
        \right\} \\
        &= \max
        \left\{
            \begin{aligned}
                |X_i - X_j|, \\
                |Y_i - Y_j|
            \end{aligned}
        \right\}
\end{align}
where $X = x+y$, $Y = x-y$.


$\max(|X_{\text{max}} - X_q|, |X_{\text{min}} - X_q|, |Y_{\text{min}} - Y_q|, |Y_{\text{max}} - Y_q|)$

が答え.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28670935)


## 037 - Don't Leave the Spice（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ak)

解説AC

$dp[i][w]$: $i$ 番目までの香辛料を使って重さが $w$ であるときの価値の最大値とする.
$dp[0][0] = 0$ とし, それ以外の値は $-\infty$ で初期化する.

$i$ 番目の香辛料を使って重さが $w$ とするときの価値の最大値は
$\displaystyle dp[i][w] = \max_{j \in [L,R]} \{ dp[i-1][w-j] \} + V$ となり, 使わない場合は $dp[i][w] = dp[i-1][w]$ である.

これを実装すると以下のようになる.

```cpp
vvll dp(N+1, vll(W+1, -INF));
dp[0][0] = 0;
rep2(i,1,N+1) {
    auto [l,r,v] = spices[i];
    rep2(w,0,W+1) {
        rep2(j,l,r+1) {
            if (w-j >= 0) {
                chmax(dp[i][w], dp[i-1][w-j] + v);
            }
        }
        chmax(dp[i][w], dp[i-1][w]);
    }
}

if (dp[N][W] < 0) cout << -1 << endl;
else cout << dp[N][W] << endl;
```

この実装だと計算量が $O(NW^2)$ となり TLE する.
ここで $\max_{j \in [L,R]} \{ dp[i-1][w-j] \}$ を計算している部分を segment tree を使うことで $O(\log W)$ に落とすことができる.

```cpp
segtree<ll,op,e> seg(W+1);
seg.set(0, 0);

vvll dp(N+1, vll(W+1, -INF));
dp[0][0] = 0;
rep2(i,1,N+1) {
    auto [l,r,v] = spices[i];
    rep2(w,0,W+1) {
        if (w-l >= 0) {
            int L = max(0ll, w-r);
            int R = w - l;
            ll mx = seg.prod(L, R+1);
            chmax(dp[i][w], mx + v);
        }
        chmax(dp[i][w], dp[i-1][w]);
    }
    seg = segtree<ll,op,e>(dp[i]);
}

if (dp[N][W] < 0) cout << -1 << endl;
else cout << dp[N][W] << endl;
```

上の実装では $i$ が変わるごとに segment tree を新しく作っているが, $w$ を小さくしていく方向でループを回すと segment tree 1つで事足りる.


```cpp
segtree<ll,op,e> seg(W+1);
seg.set(0, 0);

rep2(i,1,N+1) {
    auto [l,r,v] = spices[i];
    for (ll w = W; w >= 0; w--) {
        if (w-l >= 0) {
            int L = max(0ll, w-r);
            int R = w - l;
            ll mx = seg.prod(L, R+1);
            if (mx + v > seg.get(w)) seg.set(w, mx + v);
        }
    }
}

ll ans = seg.get(W);
if (ans < 0) cout << -1 << endl;
else cout << ans << endl;
```

小さい方からやる方式で同じように一つの segment tree を使いまわすと $w_p$ の更新が $w_q$ ($p < q$) に更新に影響を及ぼしてしまうためうまくいかない.

元の DP テーブルの更新で考えると $dp[i][w] = dp[i][w-j]$ としているようなもの.
通常は $dp[i][w] = dp[i-1][w-j]$ なので $w$ を大きい方からやっても小さい方からやっても変わらない.

$w$ を大きい方からやる場合, 一度 $dp[i][w]$ の値が確定するとそれ以降 $dp[i][w]$ が読まれることはないので問題にならない.


- [提出コード TLEコード](https://atcoder.jp/contests/typical90/submissions/28676703)
- [提出コード segment tree 1](https://atcoder.jp/contests/typical90/submissions/28676833)
- [提出コード segment tree 2](https://atcoder.jp/contests/typical90/submissions/28676892)

## 038 - Large LCM（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_al)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28677585)

## 039 - Tree Distance（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_am)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28678725)

## 040 - Get More Money（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_an)

スキップ

## 041 - Piles in AtCoder Farm（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ao)

スキップ

## 042 - Multiple of 9（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ap)

解説AC

9の倍数ならば各位の桁の和が9になるので, ならない場合はそのような正の整数 $X$ は存在しない.

$dp[x]$: 各位の桁の和が $x$ となる場合の数とすると
$\displaystyle dp[x] = \sum_{i = 1}^{9} dp[x-i]$ となる.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28710194)


### 9の倍数の各位の桁の和が9の倍数になる証明

$X = \sum_{i = 0} c_i 10^i$ ($c_i \in \Z$ and $0 \leq c_i \leq 9$) が9の倍数だとすると

\begin{align}
    X &\equiv 0 \mod 9 \\
      &\equiv \sum_{i = 0} c_i 10^i \\
      &\equiv \sum_{i=0} c_i (10 \mod 9)^i \\
      &\equiv \sum_{i=0} c_i (1)^i \\
      &\equiv \sum_{i=0} c_i
\end{align}

よって9の倍数ならば各位の桁の和が9の倍数になる.

公式解説にあった他のものについても調べている.
2, 5 の倍数のときは自明なので省略

### 3の倍数の各位の桁の和が3の倍数

9のときと同様にして考えて

\begin{align}
    X &\equiv 0 \mod 3 \\
      &\equiv \sum_{i = 0} c_i 10^i \\
      &\equiv \sum_{i=0} c_i (10 \mod 3)^i \\
      &\equiv \sum_{i=0} c_i (1)^i \\
      &\equiv \sum_{i=0} c_i
\end{align}


### 下2桁が4の倍数のとき, 4の倍数となる


\begin{align}
    X &\equiv 0 \mod 4 \\
      &\equiv \sum_{i = 0}^{n} c_i 10^i \\
      &\equiv \sum_{i=0}^{n} c_i (10^i \mod 4) \\
      &\equiv 10 c_1 + c_0 ~~(\because \forall i \geq 2, 10^i \equiv 0 \mod 4)
\end{align}

よって下2桁が4の倍数であれば4の倍数となる.

### 下3桁が8の倍数のとき, 4の倍数となる

\begin{align}
    X &\equiv 0 \mod 8 \\
      &\equiv \sum_{i = 0}^{n} c_i 10^i \\
      &\equiv \sum_{i=0}^{n} c_i (10^i \mod 8) \\
      &\equiv 100 c_2 + 10 c_1 + c_0 ~~(\because \forall i \geq 3, 10^i \equiv 0 \mod 8)
\end{align}

### 11の倍数: (奇数桁目の数字の和) - (偶数桁目の数字の和) が11の倍数 (1-index)

以下 0 index で考えるので (偶数桁目の数字の和) - (奇数桁目の数字の和)が11の倍数であることを示す.

まず, 10の偶数乗を11で割ったあまりは1, 10の奇数乗を11で割ったあまりは10である.
- $10^{2i} \equiv (10^2)^i \equiv (100 \mod 11)^i \equiv 1 \mod 11$
- $10^{2i+1} \equiv (10^2)^i \times 10 \equiv (100 \mod 11)^i \times 10 \equiv 10 \mod 11$

これより

\begin{align}
    X &\equiv 0 \mod 11 \\
      &\equiv \sum_{i = 0}^{n} c_i 10^i \\
      &\equiv \left(\sum_{i \text{ is even}} c_i 10^i\right) + \left(\sum_{i \text{ is odd}} c_i 10^i\right) \\
      &\equiv \left(\sum_{i \text{ is even}} c_i (10^i \mod 11)\right) + \left(\sum_{i \text{ is odd}} c_i (10^i \mod 11)\right) \\
      &\equiv \left(\sum_{i \text{ is even}} c_i \right) + \left(\sum_{i \text{ is odd}} 10c_i \right) \\
      &\equiv \left(\sum_{i \text{ is even}} c_i \right) - \left(\sum_{i \text{ is odd}} c_i \right) ~~(\because 10 \equiv -1 \mod 11)\\
\end{align}

よって, (偶数桁目の数字の和) - (奇数桁目の数字の和)が11の倍数) であれば11の倍数


## 043 - Maze Challenge with Lack of Sleep（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_aq)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28712969)

## 044 - Shift and Swapping（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ar)

circular buffer の要領で始点をシフトのときに変える

[提出コード](https://atcoder.jp/contests/typical90/submissions/me)


## 045 - Simple Grouping（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_as)


## 046 - I Love 46（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_at)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28715416)

## 047 - Monochromatic Diagonal（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_au)

スキップ

## 048 - I will not drop out（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_av)

解説AC

1分間に得られる得点は
- 部分点を獲得して $B_i$ 点を取る
- すでに部分点をとっていた課題を満点にして $A_i - B_i$ 点取る
の2通りが考えられる.

$B_1, \cdots, B_N, A_1 - B_1, \cdots, A_N - B_N$ を降順にソートして先頭の $K$ 個分の和が答えとなる.
ここで満点となるとき, 先に部分点をとっている必要があるが,
$A_i / 2 < B_i < A_i \Rightarrow A_i - B_i < B_i$ であるから, $A_i - B_i$ が選ばれる場合は先に $B_i$ が選ばれているので部分店が取られていないことを心配する必要はない.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28716913)


## 049 - Flip Digits 2（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_aw)

スキップ

## 050 - Stair Jump（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ax)

$dp[i]$: $i$ 段目への行き方の総数

$i+L$ 段目への行き方は $i+L-1$ 段目から1段上がってくる方法と, $i$ 段目から $L$ 段上がってくる方法の2通りがあるので
$dp[i+L] = dp[i+L-1] + dp[i]$ となる.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28780145)

## 051 - Typical Shop（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ay)

半分全列挙の問題

品物の選び方を全探索すると $2^N$ 通りあるのでこのままでは TLE してしまう.
半分の $2^{N/2}$ 通りなら全通り試せる.
配列を2つに分けてそれぞれで全列挙をする. 2つに分けた配列をそれぞれ $A$, $B$ と呼ぶことにする.
それぞれの配列に対して全列挙をする. このとき品物の数を key して, 値はその点数買ったときの値段を配列に昇順に保存する.

$A$ に含まれる値を1つずつ見ていきながら, 問題の条件を満たす $B$ の要素を二分探索で探す.

```cpp
// 組み合わせた数の個数ごとに値段を保存する
map<ll,vll> freq1, freq2;
int n1 = a1.size(), n2 = a2.size();
rep2(mask, 1,1<<n1) {
    int k = __builtin_popcount(mask);
    ll tot = 0;
    rep(i,n1) if (mask>>i&1) tot += a1[i];
    freq1[k].push_back(tot);
}
rep2(mask, 1,1<<n2) {
    int k = __builtin_popcount(mask);
    ll tot = 0;
    rep(i,n2) if (mask>>i&1) tot += a2[i];
    freq2[k].push_back(tot);
}

// 番兵として 0 を入れる
freq1[0].push_back(0);
freq2[0].push_back(0);

// 二分探索用に sort
for (auto it = freq2.begin(); it != freq2.end(); it++) {
    sort(all(it->second));
}

ll ans = 0;
for (auto it = freq1.begin(); it != freq1.end(); it++) {
    int num = it->first;
    if (num > K) continue;
    int k = K - num;
    for (ll x : freq1[num]) {
        auto s = upper_bound(all(freq2[k]), P-x);
        ans += s - freq2[k].begin();
    }
}
cout << ans << endl;
```

[提出コード](https://atcoder.jp/contests/typical90/submissions/28812182)

## 052 - Dice Product（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_az)

求める値は

\begin{align}
    \sum_{j_1, \cdots, j_n} A_{1,j_1} A_{2,j_2} \cdots A_{n, j_n}
        &= \left(\sum_{j_1} A_{1,j_1} \right) \times \cdots \times \left(\sum_{j_1} A_{n,j_n} \right) \\
        &= \prod_{i=1}^n \left( \sum_{j=1}^6 A_{i,j} \right)
\end{align}

DP を使って解くという方法もある. むしろ最初 DP の問題だと思っていた.

$dp[i][j]$: $i$ 番目の数字が $A_{i,j}$ であるときの総積の和とすると

$dp[i][j] = (dp[i-1][1] + \cdots dp[i-1][6]) \times A_{i,j}$

- [提出コード 積](https://atcoder.jp/contests/typical90/submissions/28796316)
- [提出コード DP](https://atcoder.jp/contests/typical90/submissions/28796194)



##
[問題]()
[提出コード]()


##
[問題]()
[提出コード]()

##
[問題]()
[提出コード]()


## 056 - Lucky Bag（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bd)


自力で解いたときは 「$dp[i][x][S]$: $i$ 日目に福袋 x を買って総額が S のなる」として DP テーブルをうめ,
逆をたどって復元 (LCS の復元のように) にしたが, 解説読んで $i$ 日目にどっち買うかを保存する必要はないということ知った.
条件を満たすような買い方を一つ求めればよいだけなので, どっちを買ったかを保存しておく必要はなかった.


```cpp
void solve() {
    int N, S;
    cin >> N >> S;
    vvint bag(N+1, vint(2));
    rep(i,N) rep(j,2) {
        cin >> bag[i+1][j];
    }

    // dp[i][x][S]: i 日目に福袋 x を買って総額が S となるか
    vector<vvint> dp(N+1, vvint(2, vint(S+1)));
    // 0 日目には何も買わないので総額が0円となることは可能
    dp[0][0][0] = dp[0][1][0] = 1;
    rep2(i,1,N+1) {
        rep(s,S+1) {
            rep(x,2) {
                // i 日目に x を買う
                rep(y,2) {
                    // i-1 日目に y を買う
                    if (s-bag[i][x] >= 0) dp[i][x][s] |= dp[i-1][y][s-bag[i][x]];
                }
            }
        }
    }

    if (dp[N][0][S] == 0 && dp[N][1][S] == 0) {
        cout << "Impossible" << endl;
        return;
    }

    int s = S;
    string ans = "";
    for (int i = N; i >= 1; i--) {
        rep(x,2) {
            if (dp[i][x][s]) {
                ans.push_back((x == 0 ? 'A' : 'B'));
                int t = s - bag[i][x];
                if (t >= 0) {
                    if (dp[i-1][0][t]) {
                        s = t;
                        break;
                    }
                    if (dp[i-1][1][t]) {
                        s = t;
                        break;
                    }
                }
            }
        }
    }
    reverse(all(ans));
    cout << ans << endl;
}
```


[提出コード](https://atcoder.jp/contests/typical90/submissions/28813811)


##
[問題]()
[提出コード]()



##
[問題]()
[提出コード]()


##
[問題]()
[提出コード]()

##
[問題]()
[提出コード]()


##
[問題]()
[提出コード]()


##
[問題]()
[提出コード]()
