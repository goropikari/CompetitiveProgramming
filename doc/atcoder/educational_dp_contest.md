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
