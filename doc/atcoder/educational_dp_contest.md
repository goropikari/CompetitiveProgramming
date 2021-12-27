+++
title = "Educational DP Contest"
hascode = true
date = Date(2021, 12, 14)
+++
@def tags = ["atcoder", "dp"]


# [Educational DP Contest](https://atcoder.jp/contests/dp)

\toc

## A - Frog 1

[問題](https://atcoder.jp/contests/dp/tasks/dp_a)

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27873596)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27873828)

## B - Frog 2

[問題](https://atcoder.jp/contests/dp/tasks/dp_b)

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27874329)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27874246)

## C - Vacation

[問題](https://atcoder.jp/contests/dp/tasks/dp_c)

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27874764)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27875358)

## D - Knapsack 1

[問題](https://atcoder.jp/contests/dp/tasks/dp_d)

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27875996)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27880623)


## E - Knapsack 2

[問題](https://atcoder.jp/contests/dp/tasks/dp_e)

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27883621)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27884168)

## F - LCS

[問題](https://atcoder.jp/contests/dp/tasks/dp_f)

$dp[i][j]$: $S$ を $i$ 文字目まで, $T$ を $j$ 文字目まで見たときの部分列の最長の長さとする.

$S_i = T_j$ のとき $dp[i][j] = dp[i-1][j-1] + 1$, それ以外のときは $dp[i][j] = \mathrm{max}(dp[i-1][j], dp[i][j-1])$.

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27911665)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27912036)


## G - Longest Path

[問題](https://atcoder.jp/contests/dp/tasks/dp_g)

$f(i)$ を $i$ を始点としたときの最長経路とする.

submission code
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27912036)

## [H - Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h)

$dp[i][j]$: $(i,j)$ までの経路の数とすると $dp[i][j] = dp[i-1][j] + dp[i][j-1]$.

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27914012)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27914109)

## I - Coins

[問題](https://atcoder.jp/contests/dp/tasks/dp_i)

$dp[i][j]$: $i$ 番目までの coin を使って表が出る回数が $j$ となる確率.

$dp[i][j] = dp[i-1][j] \times (1-p[i]) + dp[i-1][j-1] \times p[i]$, ($dp[0][0] = 1$).

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27962255)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27962271)

## J - Sushi

[問題](https://atcoder.jp/contests/dp/tasks/dp_j)

submission code

## K - Stones

[問題](https://atcoder.jp/contests/dp/tasks/dp_k)

$dp[i]$ 石の個数が $i$ のとき, 先手が勝てるか?
$dp[0] = 0$

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27929636)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27929767)


## M - Candies

[問題](https://atcoder.jp/contests/dp/tasks/dp_m)

$dp[i][j]$: $i$ 番目の子どもたちに飴をあげたときに, あげた飴の総数が $j$ となる場合の数

$\displaystyle dp[i][j] = \sum_{k = \min(0, j-a[i])}^j dp[i-1][k]$

愚直に解くと $O(NK^2)$ の計算量がかかるが, summation の計算を累積和を使って高速化することで $O(NK)$ で計算できるようになる.

submission code
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/27971446)



## N - Slimes

[問題](https://atcoder.jp/contests/dp/tasks/dp_n)

$f(l, r)$: $[l,r]$ の範囲(0-index)のスライム合体させたときの最小コスト, ($f(x,x) = a[x]$).

ある $k$ $(l \leq k \leq r-1)$ について $[l,k]$, $[k+1, r]$ の2つの部分を合体してスライムを生成するときにかかるコストは

$[l,k]$ の部分からの寄与 = if $i = k$ then $f(l,k)$, otherwise $f(l,k) + a[l] + ... + a[k]$.

同様にして $[k+1, r]$ の部分からの寄与 = if $k+1 = r$ then $f(k+1,r)$, otherwise $f(k+1, r) + a[k+1] + ... + a[r]$

よって合体するときのコストは
$f(l,k) + (l \neq k) \times (\mathrm{cumsum}[k+1]-\mathrm{cumsum}[l]) + f(k+1,r) + (k+1 \neq r) \times (\mathrm{cumsum}[r+1] - \mathrm{cumsum}[k+1])$

ここで $\mathrm{cumsum}[k] = a[0] + \cdots + a[k-1]$.

これをすべての $k$ に関して求め最小となるものが $f(l, r)$

submission code
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27929767)

$f(x,x) = 0$ とすると

$\displaystyle f(l, r) = \min_k\{f(l,k) + f(k+1, r) + \mathrm{cumsum}[r+1] - \mathrm{cumsum}[l] \}$

とできるのでこちらのほうが簡単かも

submission code
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/28038660)



## O - Matching

[問題](https://atcoder.jp/contests/dp/tasks/dp_o)

男性を $i$ 人選び, $i$ 番目の女性とのペアの総数を考える.

$dp[i][S]$ を男性を $i$ 人, 選ばれた男性の集合を $S$ としたとき, $i$ 番目までの女性とのペアの数とする.

0人の男性を選んだとき, 0人の女性とのペアの数は 1.
よって $dp[0][\emptyset] = 1$.

$\displaystyle dp[i+1][S \cup j] = \sum_{j \notin S \wedge A_{i,j} \neq 0} dp[i][S] \mod 10^9+7$

計算量は $O(N^2 2^N)$. ただし, このままだと TLE になる.[TLE提出コード](https://atcoder.jp/contests/dp/submissions/28085488)

ここで $i$ は集合 $S$ のサイズと同じだからなくすことができる.よって計算量は $O(N 2^N)$ まで落とすことができる.
- [for loop 使用](https://atcoder.jp/contests/dp/submissions/28085512)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/28085649)


## P - Independent Set

[問題](https://atcoder.jp/contests/dp/tasks/dp_p)

木なので適当に root を決めて再帰的に解く.
$f(x)$ を node $x$ が白だったときの場合の数, $g(x)$ を node が黒だったときの場合の数とすると

$$f(x) = \prod_{i \in \mathrm{neighbor}(x)}(f(i) + g(i))$$
$$\displaystyle g(x) = \prod_{i \in \mathrm{neighbor}(x)}f(i)$$

$x$ が葉のとき $f(x) = g(x) = 1$

となる.ここで $\mathrm{neighbor}(x)$ は node $x$ の子 node の集合.

解説

node $x$ が白のとき, ある一つの子 node $i$ の色は白・黒どちらでも良いので $f(i) + g(i)$.
他の子 node についても同様で子 node 間の色は独立で決められるから子 node の色の組み合わせは $\prod_{i \in \mathrm{neighbor}(x)}(f(i) + g(i))$.

node $x$ が黒のとき, 制約より子 node の色は白しか置けないから子 node の色の組み合わせは $\prod_{i \in \mathrm{neighbor}(x)}f(i)$.

- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/28103298)
