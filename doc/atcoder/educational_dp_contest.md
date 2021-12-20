+++
title = "Educational DP Contest"
hascode = true
date = Date(2021, 12, 14)
+++
@def tags = ["atcoder", "dp"]


# [Educational DP Contest](https://atcoder.jp/contests/dp)

## [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27873596)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27873828)

## [B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b)

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27874329)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27874246)

## [C - Vacation](https://atcoder.jp/contests/dp/tasks/dp_c)

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27874764)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27875358)

## [D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d)

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27875996)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27880623)


## [E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e)

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27883621)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27884168)

## [F - LCS](https://atcoder.jp/contests/dp/tasks/dp_f)

$dp[i][j]$: $S$ を $i$ 文字目まで, $T$ を $j$ 文字目まで見たときの部分列の最長の長さとする.

$S_i = T_j$ のとき $dp[i][j] = dp[i-1][j-1] + 1$, それ以外のときは $dp[i][j] = \mathrm{max}(dp[i-1][j], dp[i][j-1])$.

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27911665)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27912036)


## [G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)

$f(i)$ を $i$ を始点としたときの最長経路とする.

submission code
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27912036)

## [H - Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h)

$dp[i][j]$: $(i,j)$ までの経路の数とすると $dp[i][j] = dp[i-1][j] + dp[i][j-1]$.

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27914012)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27914109)

## [I - Coins](https://atcoder.jp/contests/dp/tasks/dp_i)

$dp[i][j]$: $i$ 番目までの coin を使って表が出る回数が $j$ となる確率。

$dp[i][j] = dp[i-1][j] \times (1-p[i]) + dp[i-1][j-1] \times p[i]$, ($dp[0][0] = 1$).

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27962255)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27962271)

## [J - Sushi](https://atcoder.jp/contests/dp/tasks/dp_j)

submission code

## [K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k)

$dp[i]$ 石の個数が $i$ のとき、先手が勝てるか?
$dp[0] = 0$

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27929636)
- [再帰関数使用](https://atcoder.jp/contests/dp/submissions/27929767)


## [M - Candies](https://atcoder.jp/contests/dp/tasks/dp_m)

$dp[i][j]$: $i$ 番目の子どもたちに飴をあげたときに、あげた飴の総数が $j$ となる場合の数

$\displaystyle dp[i][j] = \sum_{k = \min(0, j-a[i])}^j dp[i-1][k]$

愚直に解くと $O(NK^2)$ の計算量がかかるが、summation の計算を累積和を使って高速化することで $O(NK)$ で計算できるようになる。

submission code
- [配列使用](https://atcoder.jp/contests/dp/submissions/27971446)



## [N - Slimes](https://atcoder.jp/contests/dp/tasks/dp_n)

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
