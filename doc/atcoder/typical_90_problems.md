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


## 007 - CP Classes（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_g)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28453912)

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

解説AC

区間変更・区間最大値取得の遅延セグメント木を使えばよい.

ACL の遅延セグメント木のチートシートを書いている方がいるのでそれを使わせてもらうと楽
- [AtCoder LibraryのLazy Segtreeのチートシート](https://betrue12.hateblo.jp/entry/2020/09/23/005940#%E5%8C%BA%E9%96%93%E5%A4%89%E6%9B%B4%E5%8C%BA%E9%96%93%E6%9C%80%E5%A4%A7%E5%80%A4%E5%8F%96%E5%BE%97)

[提出コード](https://atcoder.jp/contests/typical90/submissions/29123495)

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



## 053 - Discrete Dowsing（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ba)

スキップ

## 054 - Takahashi Number（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bb)

スキップ


## 055 - Select 5（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bc)

一見5重ループにすると $O(10^10)$ の計算量になって TLE するように見えるが
$\comb{100}{5} = 75287520$ なので, 愚直なループで間に合う.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28829214)


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


## 057 - Flip Flap（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_be)

スキップ



## 058 - Original Calculator（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bf)

ポロードローメソッドの要領で周期的に回る.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28844939)

## 059 - Many Graph Queries（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bg)

スキップ

## 060 - Chimera（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bh)

前からの LIS と後ろからの LIS を考える.
それぞれの LIS で着目している文字が LIS の何文字目かを記録する.
$i$ 文字目が前から LIS をしたときに何文字目かを記録した配列を `Front`,
$i$ 文字目が後から LIS をしたときに何文字目かを記録した配列を `Back` とすると
$\text{Front}_{i} + \text{Back}_{i} - 1$ の最大値が答えとなる.

```cpp
void solve() {
    int n;
    cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];

    vint lisf(n, INF), lisb(n, INF), front(n, 0), back(n, 0);
    rep(i,n) {
        auto it = lower_bound(all(lisf), a[i]);
        front[i] = it - lisf.begin() + 1;
        *it = a[i];
    }

    reverse(all(a));
    rep(i,n) {
        auto it = lower_bound(all(lisb), a[i]);
        back[i] = it - lisb.begin() + 1;
        *it = a[i];
    }
    reverse(all(back));

    int ans = 0;
    rep(i,n) {
        chmax(ans, front[i] + back[i] - 1);
    }
    cout << ans << endl;
}
```


[提出コード](https://atcoder.jp/contests/typical90/submissions/29129876)

## 061 - Deck（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bi)
[提出コード](https://atcoder.jp/contests/typical90/submissions/28890016)


## 062 - Paint All（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bj)

スキップ

## 063 - Monochromatic Subgrid（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bk)

行数が最大で 8 と小さいのでどの行を選ぶかを全探索 $(O(2^H))$ して, 各列に対して全ての数字が同じであるような列のみを残して, そのうちの出現回数が一番多い数字の個数が答え.

[提出コード](https://atcoder.jp/contests/typical90/submissions/28994088)

## 064 - Uplift（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bl)

いい解き方が思いつかなかったので fenwick tree を使った明らかにオーバースペックの解法で解いてしまった.


### fenwick tree を使った解き方
不便さは $|a_{l-1} - a_l|$ と $|a_r - a_{r+1}|$ の変化のみに依存する.
その他の区間では隣接要素が同じ分だけ変化するので不便さの変化には寄与しない.
クエリが処理したあとの $a_i$ の値を求めたいが, これをいもす法を使って求めることを考える.
0 で初期化した配列に対して $L$ 番目に $+v$, $R+1$ 番目を $-v$ して累積和をとると,
$i$ 番目の要素の増減が求まる.
各クエリでは累積和を取る前の配列を使いまわし, 累積和は別の配列に持っておけば各クエリ時点での $i$ 番目の要素の増減がわかる.
ただし, ここで累積和を愚直に for loop を回して求めると全体で $O(NQ)$ の計算量になってしまうので TLE になってしまう.
そこで累積和を求める部分を fenwick tree を使うことで $O(\log N)$ に落とす.
これによって全体計算量が $O(Q \log N)$ となり実行時間に間に合う.

### 階差を使った解き方

想定解は階差 $b_i = a_{i+1} - a_i$ を使って解く方法だった.

$[l,r]$ の範囲に $+v$ したあとの階差を $b^\prime_i$ とすると

\begin{align}
    b^\prime_i     &= (a_{i+1} + v) - (a_i + v) = b_i~~ (l \leq i < r) \\
    b^\prime_{l-1} &= (a_l + v) - a_{l-1} = b_{l-1} + v \\
    b^\prime_{r}   &= a_{r+1} - (a_r + v) = b_{r} - v \\
    b^\prime_i     &= b_i~~ ~ \text{otherwise}
\end{align}

となる. 初期状態の不便さを $S$ とするとクエリを処理したあとの不便さは

$S - (|b_{l-1}| + |b_r|) + (|b^\prime_{l-1}| + |b^\prime_r|)$

となる.


[提出コード fenwick tree ver](https://atcoder.jp/contests/typical90/submissions/29012172)
[提出コード 階差 ver](https://atcoder.jp/contests/typical90/submissions/29013161)

## 065 - RGB Balls 2（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bm)

スキップ

## 066 - Various Arrays（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bn)

解説AC

$x_i > x_j$ $(i < j)$ となる確率を $E_{i,j}$ とすると, $x_i > x_j$ からの寄与分の転倒数の期待値は
$0 \times (1 - E_{i,j}) + 1 \times E_{i,j} = E_{i,j}$ である.

求める答えは
\begin{align}
    \sum_{i = 1}^{N} \sum_{j = i+1}^N E_{i,j}
\end{align}

[提出コード](https://atcoder.jp/contests/typical90/submissions/29182688)


## 067 - Base 8 to 9（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bo)
[提出コード](https://atcoder.jp/contests/typical90/submissions/29027684)

## 068 - Paired Information（★5）

[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bp)


$T = 0$ のイベントで $X_i$, $Y_i$ の間に辺を張ることを考える.
$T = 1$ のイベントでは $X_i$ と $Y_i$ の間にパスがあれば答えが一意に定まる. (一つの値が決まると隣の数が自動的に決まるため. )
パスがなければ Ambiguous となる.

パスがあるか否かは Union Find を使って高速に調べることができる.

![068.png](/assets/atcoder/typical_90/068.png)

パスがある場合に $Y_i$ の値を求める方法を考える.
$X_i < Y_i$ の場合について考える.
愚直に $A_{X_i} = V_i$ を代入して $A_{X_i} + A_{X_i + 1} = V_p$ から $A_{X_i + 1}$ を求め, $A_{X_i + 1} + A_{X_i + 2} = V_q$ から $A_{X_i + 2}$ を求め, ..., $A_{Y_i}$ を求めとすると
各イベントで $O(N)$ の計算量になってしまうので TLE になってしまう.
よって, $A_{X_i}$ から $A_{Y_i}$ を高速に求める方法を考える必要がある.

$e_{X_i} = A_{X_i} + A_{X_i + 1}$ とすると

\begin{align}
A_{X_i} - A_{Y_i} &= (A_{X_i} + A_{X_i + 1}) - (A_{X_i + 1} + A_{X_i + 2}) + \cdots - (A_{Y_i -2} + A_{Y_i - 1})+ (A_{Y_i - 1} + A_{Y_i}) \\
    &= e_{X_i} - e_{X_i + 1} + \cdots + e_{Y_i - 2} - e_{Y_i - 1}
\end{align}

区間和 $e_{X_i} - e_{X_i + 1} + \cdots + e_{Y_i - 2} - e_{Y_i - 1}$ は fewwick tree などを使うと $\log N$ で計算することができる.

これらのことから問題は以下のようにして解ける. 以下 $X_i$, $Y_i$ は 0-index で考える. (問題の値 - 1 となる)

- まず fenwick tree, union find を作る.
- $T = 0$ のイベント:
  - $X_i$ が偶数ならば fenwick tree の $X_i$ 番目の値を $+ V_i$ し,
  - $X_i$ が奇数ならば fenwick tree の $X_i$ 番目の値に $-V_i$ を加える.
  - union find で $X_i$, $X_i +1$ を連結させる.
- $T = 1$ のイベント
  - $X_i$, $Y_i$ が連結でなければ Ambiguous を出力
  - 連結だった場合
    - $X_i < Y_i$ ならば $x = X_i$, $y = Y_i$, そうでなければ $x = Y_i$, $y = X_i$ とする.
    - fenwick tree で $[x, y-1]$ の範囲の和を求める. これを `sum` とする.
    - $x, y$ のパリティが同じ場合
      - $x$ が偶数ならば
          - $\text{sum} = A_{x} - A_{y}$
      - $x$ が偶数ならば
          - $\text{sum} = - A_{x} + A_{y}$
      - $X_i < Y_i$ ならば求めた sum を -1 倍
      - $\text{sum} + V_i$ を出力
    - $x, y$ のパリティが違う場合
      - $x$ が偶数ならば
        - $\text{sum} = A_{x} + A_{y}$ となる
      - $x$ が奇数ならば
          - $\text{sum} = - (A_{x} + A_{y})$
      - $x$ が奇数ならば sum を -1 倍
      - $\text{sum} - V_i$ を出力

とすることで問題を解ける.

```cpp
void solve() {
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    fenwick_tree<ll> fw(n+1);

    rep(i,q) {
        ll t, x, y, v;
        cin >> t >> x >> y >> v;
        x--, y--;
        if (t == 0) {
            if (!uf.same(x,y)) {
                if (x % 2 == 0) fw.add(x, v);
                else fw.add(x, -v);
                uf.merge(x,y);
            }
        } else {
            if (!uf.same(x,y)) {
                cout << "Ambiguous" << endl;
                continue;
            }
            ll ox = x, oy = y;
            if (x > y) swap(x,y);
            ll sum = fw.sum(x, y);
            if (x % 2 != y % 2) {
                if (x % 2 == 1) sum *= -1;
                cout << sum - v << endl;
            } else {
                if (x % 2 == 0) {
                    // ax - ay
                    if (ox < oy) {
                        sum *= -1ll;
                    }
                } else {
                    // -ax + ay
                    if (ox > oy) {
                        sum *= -1ll;
                    }
                }
                cout << sum + v << endl;
            }
        }
    }
}
```

[提出コード](https://atcoder.jp/contests/typical90/submissions/29060821)

余談

最初 $V_i$ の値が 0 以上の数となっていたから $A_i$ も 0 以上になると思っていたが, 単に整数としか書いてなかったので
出力される $A_i$ の値は負数になることもあった.
$A_i$ が non-negative と言われていたら

```
6
4
0 1 2 1
0 2 3 2
0 3 4 1
1 5 1 3
```
という入力ケースのとき, 模範解答だと Ambiguous となるけど, 5, 6 番目の何であろうと先頭4つの並びは `0 1 1 0` に確定するから 1 番目の要素は 0 と出力されるのが正解となる.
ただ, $A_i$ は負数にもなるため, 最初の4つの並びは $1, 0, 2 -1$ という並びにもなることがあるため Ambiguous となる.



## 069 - Colorful Blocks 2（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bq)

1つ目の塗り方は $K$ 通り,
2つ目の塗り方は1つ目とは違う色で塗るから $K-1$ 通り
3つ目の以降の塗り方は1つ前と2つ前と違う色で塗るから $K-2$ 通りとなる.
よって塗り方の総数の $K(K-1)(K-2)^{N-2}$.

[提出コード](https://atcoder.jp/contests/typical90/submissions/29130574)

## 070 - Plant Planning（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_br)

発電所を建設する座標を $(a, b)$ とすると不便さは

$\sum_i |a - X_i| + |b - Y_i|$ となる. ここで $x$, $y$ は独立に考えることができるので
$\sum_i |a - X_i|$ が最小になるような $a$ と $\sum_i |b - Y_i|$ が最小になるような $b$ を求めれば良い.
そのような $a$, $b$ はそれぞれ $X_i$ の中央値と $Y_i$ の中央値を選べばよい.
($N$ が偶数のとき $\lceil N/2 \rceil$ と $\lfloor N/2 \rfloor$ のいずれの要素を選んでも答えは変わらない. )

[提出コード](https://atcoder.jp/contests/typical90/submissions/29131824)

## 071 - Fuzzy Priority（★7）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bs)

スキップ

## 072 - Loop Railway Plan（★4）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bt)

$H \times W \leq 16$ と制約が小さいので DFS で全探索できる.

[提出コード](https://atcoder.jp/contests/typical90/submissions/29134619)


## 073 - We Need Both a and b（★5）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bu)

解説読んだがよくわかってない


## 074 - ABC String 2（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bv)

自力ACしたがなんでこれでいいのか証明ができていない.

とりあえず実験をしてみる. a, b, c を 0, 1, 2 にそれぞれ置き換えて考える.

![074 1](/assets/atcoder/typical_90/074_1.png)

常に一番左にある non zero の場所に対して操作をするのが最適なように見える.

入力例3 の `baaca` に対して上の予想を適用すると操作回数は 17 となりこの予想は良さそうに見える.
![074 2](/assets/atcoder/typical_90/074_2.png)

実験の動きをみると, 2進数表記で数を1ずつ減らしている動きに似ている. 2 があるので完全に2進数ではないが, その部分は2回分できると考えると操作回数は

$\displaystyle \sum_{i = 0}^{n-1} d_i \times 2^{i}$

となる. ここで
\begin{align}
d_i = \left\{
    \begin{aligned}
        0 ~~ \text{if } s_i = a \\
        1 ~~ \text{if } s_i = b \\
        2 ~~ \text{if } s_i = c
    \end{aligned}
\right.
\end{align}


### なぜ一番左にある non zero に対して操作をするのが最適か？

$\text{Potential} = \sum_{i = 0}^{n-1} d_i \times 2^{i}$ と定義する.

この Potential に対して以下の2つが成り立つ.
- (1) 1回の操作に対して Potential は必ず 1 以上減る
- (2) Potential を 1 だけ減らす操作が存在する

(1) について

例えば $x_0 x_1 \cdots x_n$ とあったとき $x_i$ ($x_i = 1 \text{ or } 2$) に操作をすると
$x_i$ が 1 減ることで Potential は $2^i$ 減る.
$x_0, \cdots x_{i-1}$ のそれぞれの数字は最大で 1 増えるので $x_0, \cdots x_{i-1}$ の変化による
Potential の増分は最大で $2^i - 1$ となる.
よってトータルで $- 2^i + (2^i - 1) = -1$ となり操作によって Potential は 1 以上減ることがわかった.


(2) について

一番左にある non zero の要素に対して操作をすると
Potential は $2^i$ 減って $2^i - 1$ 増えるので total $1$ だけ減らすことができる.

以上のことより一番左の non zero の要素に対して操作をすることが最適だということが示された.


[提出コード](https://atcoder.jp/contests/typical90/submissions/29258017)


## 075 - Magic For Balls（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bw)

$N = p_1^{r_1} p_2^{r_2} \cdots p_m^{r_m}$ と素因数分解する.

$\lceil \log_2 (\sum_i r_i) \rceil$ が答えとなる.

合成数 $x$ を2つの数に分解するときは $a$, $b$ の素因数の数がそれぞれ同じ, または素因数の数の差が 1
となるように分解したとき魔法を使う回数が最小になる.
この回数はノード数が $\sum_i r_i$ のときの完全二分木の高さと同じなので $\lceil \log_2 (\sum_i r_i) \rceil$ となる.


実際は $\log$ 使うと浮動小数点数になってしまうので $\sum_i r_i \leq 2^K$ となる最小の $K$ を出力する.


[提出コード](https://atcoder.jp/contests/typical90/submissions/29320555)


## 076 - Cake Cut（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bx)

尺取り法で求められる. 起点となる左端の index は $N$ を超えた場合(0-index)は
index 0 から始めるのと一緒なので `No` となる.
また尺取りの終点が始点に追いついてもだめ

[提出コード](https://atcoder.jp/contests/typical90/submissions/29372626)


## 077 - Planes on a 2D Plane（★7）

[問題](https://atcoder.jp/contests/typical90/tasks/typical90_by)

スキップ


## 078 - Easy Graph Problem（★2）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_bz)
[提出コード](https://atcoder.jp/contests/typical90/submissions/29372907)


## 079 - Two by Two（★3）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_ca)

操作順序によらないので愚直に左から右, 上から下に向かって $B$ と同じになるように変化させていく.
$H$ 行, $W$ 列のそれぞれの値が $A$, $B$ で同じになっていれば Yes, そうでなければ No を出力する.

最低操作回数は単純に上の操作での回数を出力すれば良い.

[提出コード](https://atcoder.jp/contests/typical90/submissions/29373286)


## 080 - Let's Share Bit（★6）
[問題](https://atcoder.jp/contests/typical90/tasks/typical90_cb)

$S_i = \{x | 2^i \text{ AND } A_j \neq 0,~~ 1 \leq j \leq n \}$ $(0 \leq i < D)$とする($i$ bit 目が立っている $A$ の部分集合).

こうすると問題は $S_i$ をいくつか選び和集合をとったとき $A$ となる組み合わせはいくつあるかという問題に言い換えられる.

入力例 1 の場合のとき
- $S_1 = {1, 3, 5}$
- $S_2 = {3}$
- $S_3 = {4, 5}$
となり, このとき和集合が ${1, 3, 4, 5}$ となる部分集合の組み合わせは $(S_0, S_2)$, $(S_0, S_1, S_2)$ の2通り.

$dp[X][i]$ を $i$ 番目までの部分集合を使って, 和集合が $X$ となる場合の数とすると
0 個の部分集合を使って和集合が $\empty$ となる場合の数は 1 であるから
$dp[\empty][0] = 1$.

それ以外のとき
- $S_i$ を使うとき: $\displaystyle dp[X \cup S_i][i] += dp[X][i-1]$
- $S_i$ を使わないとき: $\displaystyle dp[X][i] += dp[X][i-1]$

これを $X$ を $0$ から $2^N -1$ まで順に計算していく.
$S_i = \empty$ のとき $X \cup S_i = X$ となり, $dp[X][i]$ に $dp[X][i-1]$ が二回足されるので
$i$ bit 目が 0 か 1 の 2 通り選べることをちゃんと表現できている.

最終的に $dp[A][D]$ が答えとなる.


$X \cup S_i = X$ となるのでもらう DP で書くのは厳しそう.

[提出コード](https://atcoder.jp/contests/typical90/submissions/29643015)
