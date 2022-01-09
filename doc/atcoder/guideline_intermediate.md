+++
title = "AtCoder上達のガイドライン 中級編"
hascode = true
date = Date(2021, 12, 31)
+++
@def tags = ["atcoder"]

# 『 レッドコーダーが教える, 競プロ・AtCoder上達のガイドライン【中級編：目指せ水色コーダー！】 』掲載問題メモ

[元記事](https://qiita.com/e869120/items/eb50fdaece12be418faa)

\toc

```
###
[問題]()
[提出コード]()
```

## 全探索：全列挙

### ITP1_7_B - How Many Ways?
[問題](https://onlinejudge.u-aizu.ac.jp/problems/ITP1_7_B)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/5/ITP1_7_B/judge/6156067/C++17)


### AtCoder Beginner Contest 106 B - 105
[問題](https://atcoder.jp/contests/abc106/tasks/abc106_b)
[提出コード](https://atcoder.jp/contests/abc106/submissions/28158388)

### AtCoder Beginner Contest 122 B - ATCoder
[問題](https://atcoder.jp/contests/abc122/tasks/abc122_b)
[提出コード](https://atcoder.jp/contests/abc122/submissions/28158330)


### パ研杯2019 C - カラオケ
[問題](https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c)
[提出コード](https://atcoder.jp/contests/pakencamp-2019-day3/submissions/28161419)

## 全探索：工夫して通り数を減らす全列挙

### AtCoder Beginner Contest 095 C - Half and Half
[問題](https://atcoder.jp/contests/abc095/tasks/arc096_a)
[提出コード](https://atcoder.jp/contests/abc095/submissions/28158599)


### 三井住友信託銀行プログラミングコンテスト 2019 D - Lucky PIN
[問題](https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d)
[提出コード](https://atcoder.jp/contests/sumitrust2019/submissions/28159010)


### JOI 2007 本選 3 - 最古の遺跡
[問題](https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c)
[提出コード](https://atcoder.jp/contests/joi2007ho/submissions/28166905)


### Square869120Contest #6 B - AtCoder Markets

[問題](https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b)
[提出コード](https://atcoder.jp/contests/s8pc-6/submissions/28167076)


###  JOI 2008 予選 4 - 星座探し
[問題](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d)
[提出コード](https://atcoder.jp/contests/joi2008yo/submissions/28167332)


## 全探索：ビット全探索

### ALDS_5_A - 総当たり
[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_A)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/5/ALDS1_5_A/judge/6160514/C++17)



### AtCoder Beginner Contest 128 C - Switches
[問題](https://atcoder.jp/contests/abc128/tasks/abc128_c)
[提出コード](https://atcoder.jp/contests/abc128/submissions/28159189)

### AtCoder Beginner Contest 002 D - 派閥
[問題](https://atcoder.jp/contests/abc002/tasks/abc002_4)
[提出コード](https://atcoder.jp/contests/abc002/submissions/28202911)

### JOI 2008 予選 5 - おせんべい
[問題](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e)

行をひっくり返すのが $2^R$ 通り. 行のひっくり返し方を決めたら列方向は白い丸が増えるようにひっくり返すかそのままにするかを決めればよい.

[提出コード](https://atcoder.jp/contests/joi2008yo/submissions/28203202)

### Square869120Contest #4 B - Buildings are Colorful!
[問題](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b)

どの建物の高さを増やすかという $2^N$ 通りを全て試して, 最小コストを求める.

[提出コード](https://atcoder.jp/contests/s8pc-4/submissions/28203429)


## 全探索：順列全探索

### AtCoder Beginner Contest 145 C - Average Length
[問題](https://atcoder.jp/contests/abc145/tasks/abc145_c)
[提出コード](https://atcoder.jp/contests/abc145/submissions/28160521)


### AtCoder Beginner Contest 150 C - Count Order
[問題](https://atcoder.jp/contests/abc150/tasks/abc150_c)
[提出コード](https://atcoder.jp/contests/abc150/submissions/28160609)

### ALDS_13_A - 8 クイーン問題
[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_13_A)

クイーンが $(x,y)$ にあるとき, そのクイーンが動ける範囲は $\{(x^\prime, y^\prime) : |x - x^\prime| = |y - y^\prime| \}$ となる.
クイーンの置き場所 $8!$ 通りを全て試す.

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/5/ALDS1_13_A/judge/6160721/C++14)


## 二分探索

### ALDS_4_B - 二分探索
[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_B)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/4/ALDS1_4_B/judge/6161188/C++14)

### JOI 2009 本選 2 - ピザ
[問題](https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b)

店の場所を表す `vector` に 0, N を追加し, ソートする. 0, N は本店を表し, 二分探索するときの番兵の役割を果たす.

```cpp
void solve() {
    int d, n, m;
    cin >> d >> n >>  m;
    vector<int> shop(n-1);
    rep(i,n-1) cin >> shop[i];
    shop.push_back(0);
    shop.push_back(d);
    sort(all(shop));

    ll ans = 0;
    rep(i,m) {
        int k;
        cin >> k;
        auto it = upper_bound(all(shop), k);
        ans += min(*it - k, k - *(it-1));
    }
    cout << ans << endl;
}
```

二分探索するときは `upper_bound` の方を使う.
`lower_bound` は指定された要素以上の値をところの iterator を返してくるので, 多くの場合は `min(*it - k, k - *(it - 1)` で正しい距離が求まるが, k = 0 のときは `it - 1` が `shohp.begin()` よりも前のアドレスを指してしまうので芳しくない.
(lower_bound 番のコードでも AC 出てしまったけれど. )

upper_bound であればそのへんの心配がないので楽

[提出コード](https://atcoder.jp/contests/joi2009ho/submissions/28283279)

### AtCoder Beginner Contest 077 C - Snuke Festival
[問題](https://atcoder.jp/contests/abc077/tasks/arc084_a)

$B$ の値を動かして, $A$, $C$ のとり得る範囲を二分探索で調べる.
$O(N\log N)$ で解ける.

[提出コード](https://atcoder.jp/contests/abc077/submissions/28207529)

### AtCoder Beginner Contest 023 D - 射撃王
[問題](https://atcoder.jp/contests/abc023/tasks/abc023_d)

風船 $i$ が割られる時刻を $k_i$ とすると, ゲームの得点が $x$ だったとき $\displaystyle \forall i, H_i + k_i S_i \leq x \Rightarrow k_i \leq \frac{x - H_i}{S_i}$ が成り立つ.

不等式より, 得点を固定すると各風船は $\frac{x - H_i}{S_i}$ 秒以内に割らないといけないことがわかる.
$j$ 秒($j \geq 0$)経過したとき $k_i \leq j$ を満たす $i$ の数が $j+1$ を超えなければ得点の上限は $x$ となり, 逆に超えた場合は得点 $x$ を取ることは不可能である.
この得点 $x$ は二分探索で求めることができる.

```cpp
void solve() {
    int n;
    cin >> n;
    vector<ll> H(n), S(n);
    ll ok = 0, ng = 0;
    rep(i,n) {
        cin >> H[i] >> S[i];
        chmax(ng, H[i]-1);
        chmax(ok, H[i]+(n-1)*S[i]);
    }

    ll ans = INF;
    while (abs(ok - ng) > 1) {
        // 答えが mid のとき, 各風船を何秒後までに割らないといけないかを計算する
        ll mid = (ok + ng) / 2;
        // cnt[i]: i 秒後までに割らないといけない風船の数
        vector<int> cnt(n);
        rep(i,n) {
            ll k = (mid - H[i]) / S[i];
            if (k > n-1) cnt[n-1]++;
            else if (k < 0) cnt[0]++;
            else cnt[k]++;
        }
        rep(i,n-1) cnt[i+1] += cnt[i];

        int achievable = 1;
        rep(i,n) {
            // 答えが mid のとき, i 秒後までに割らないといけない風船の数が
            // i+1 個を超えていた場合, mid は答えとして小さすぎるため不適
            if (cnt[i] > i+1) {
                ng = mid;
                achievable = 0;
                break;
            }
        }
        if (achievable) {
            chmin(ans, mid);
            ok = mid;
        }
    }
    cout << ans << endl;
}
```

ここでは[めぐる式二分探索](https://twitter.com/meguru_comp/status/697008509376835584)を使った.

[提出コード](https://atcoder.jp/contests/abc023/submissions/28208977)

### AtCoder Regular Contest 054 B - ムーアの法則
[問題](https://atcoder.jp/contests/arc054/tasks/arc054_b)

解いてない

### JOI 2008 本選 3 - ダーツ
[問題](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c)

$P_0 = 0$ (ダーツを投げなかった or 的を外したときの点数) とすると1本投げて獲得できる点数は $P_i$ ($0 \leq i \leq N$),
2本投げて獲得できる点数は $P_i + P_j$ ($0 \leq i,j \leq N \wedge P_i + P_j \leq M$)となる.

2本投げた時点での得点を $x$ とすると, 残り2本を投げて獲得できる得点が $P_i + P_j \leq M - x$ を満たす $P_i + P_j$ のうちの最大値をとったとき合計得点が最も大きくなる.

最初の2本の得点が決まったとき, 残りの2本の得点は二分探索で高速に探すことができる.

```cpp
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1, 0), pp;
    rep(i,n) cin >> p[i+1];
    rep(i,n+1) rep2(j,i,n+1) if (p[i]+p[j] <= m) pp.push_back(p[i]+p[j]);
    sort(all(pp));

    int ans = 0;
    for (int x : pp) {
        auto it = upper_bound(all(pp), m-x);
        chmax(ans, *(it-1) + x);
    }
    cout << ans << endl;
}
```

上記のコードでは2本の得点を作る段階で $M$ を超えた値は入れないようにしているが, その処理を入れない場合は `m - x` の値が負になることがある. その場合 `it` は `pp.begin()` になるので飛ばすという書き方もある.

```cpp
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1, 0), pp;
    rep(i,n) cin >> p[i+1];
    rep(i,n+1) rep2(j,i,n+1) pp.push_back(p[i]+p[j]);
    sort(all(pp));

    int ans = 0;
    for (int x : pp) {
        auto it = upper_bound(all(pp), m-x);
        if (it == pp.begin()) continue;
        chmax(ans, *(it-1) + x);
    }
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/joi2008ho/submissions/28213217)

## 深さ優先探索

### ALDS_11_B - 深さ優先探索
[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/4/ALDS1_11_B/judge/6162203/C++14)

### AOJ 1160 - 島はいくつある？
[問題](https://onlinejudge.u-aizu.ac.jp/problems/1160)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/4/1160/judge/6162242/C++14)

### AtCoder Beginner Contest 138 D - Ki
[問題](https://atcoder.jp/contests/abc138/tasks/abc138_d)
[提出コード](https://atcoder.jp/contests/abc138/submissions/28213792)

### JOI 2009 予選 4 - 薄氷渡り
[問題](https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d)
[提出コード](https://atcoder.jp/contests/joi2009yo/submissions/28214093)


## 幅優先探索

### ALDS_11_C - 幅優先探索
[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/4/ALDS1_11_C/judge/6162659/C++17)


### AtCoder Beginner Contest 007 C - 幅優先探索
[問題](https://atcoder.jp/contests/abc007/tasks/abc007_3)
[提出コード](https://atcoder.jp/contests/abc007/submissions/28217073)


### JOI 2011 予選 5 - チーズ
[問題](https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e)
[提出コード](https://atcoder.jp/contests/joi2011yo/submissions/28217300)


### JOI 2012 予選 5 - イルミネーション
[問題](https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e)
[提出コード](https://atcoder.jp/contests/joi2012yo/submissions/28218973)


### AOJ 1166 - 迷図と命ず
[問題](https://onlinejudge.u-aizu.ac.jp/problems/1166)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/4/1166/judge/6163330/C++17)


### AtCoder Beginner Contest 088 D - Grid Repainting
[問題](https://atcoder.jp/contests/abc088/tasks/abc088_d)
[提出コード](https://atcoder.jp/contests/abc088/submissions/28221687)


## 動的計画法：ナップザック DP

### DPL_1_B: 0-1 ナップザック問題

[問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B)

$dp[i][j]$: $i$ 番目までの品物を使って重さの総和が $j$ 以下のときの価値の最大値

$i$ 番目の品物を使わなかったときと $dp[i-1][j]$ と, $i$ 番目の品物を使うとき $dp[i-1][j-w[i]]$ の大きい方を選ぶ.

$dp[i][j] = \max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])$

```cpp
vector<vector<int>> dp(N+1, vector<int>(W+1,0));
rep2(i,1,N+1) {
    rep(j,W+1) {
        if (j-w[i] >= 0) chmax(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        chmax(dp[i][j], dp[i-1][j]);
    }
}
```


[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DPL_1_B/judge/6163387/C++17)

### DPL_1_C ナップザック問題

[問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_C)

$dp[w]$: 重さが $w$ を以下のときの価値の最大値

```cpp
vector<int> dp(W+1,0);
rep(j,W+1) {
    rep2(i,1,N+1) {
        if (j + w[i] <= W) chmax(dp[j+w[i]], dp[j]+v[i]);
    }
}
ans = dp[W];
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DPL_1_C/judge/6163401/C++14)

### DPL_1_A コイン問題

[問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_A)

$dp[n]$: $n$ 円払うときのコインの最小枚数

0円払うとき必要なコインは 0 枚だから $dp[0] = 0$.

```cpp
vector<int> dp(n+1, INF);
dp[0] = 0;
rep(i,n+1) {
    rep(j,m) {
        if (i+coins[j] <= n) chmin(dp[i+coins[j]], dp[i] + 1);
    }
}
// ans = dp[n];
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DPL_1_A/judge/6163410/C++17)

### ALDS1_10_C 最長共通部分列

[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C)

$dp[i][j]$: 文字列 $X$ を $i$ 文字目, 文字列 $Y$ を $j$ 文字目まで見たときの最長共通部分列

- $X_i = Y_j$ のとき $dp[i][j] = dp[i-1][j-1] + 1$
- $X_i \neq Y_j$ のとき, 文字列 $X$ の見ている文字を右に進めるか, 文字列 $Y$ の見ている文字を右に進めるかの2択. よって $dp[i-1][j]$ または $dp[i][j-1]$ のうちの大きい方 $dp[i][j] = \max(dp[i-1][j], dp[i][j-1])$.

```cpp
int lcs(string s, string t) {
    int lens = s.size(), lent = t.size();
    vector<vector<int>> dp(lens+1, vector<int>(lent+1, 0));
    rep2(i,1,lens+1) {
        rep2(j,1,lent+1) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[lens][lent];
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/ALDS1_10_C/judge/6163429/C++17)

### JOI 2011 予選 4 - 1 年生

[問題](https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d)

$dp[i][x]$: $i$ 番目までの数字を足し引きをして $x$ となる場合の数
$n-1$ 番目の数字を足し引きして $n$ 番目の数字と同じになる場合の数が答え

一番はじめの数は足す一択だから $dp[1][a[1]] = 1$.

$i$ が小さい方から決めていく.

配る dp の場合
```cpp
// dp[i][x]: i 番目の数字を足し引きして x となる場合の数
vector<vector<ll>> dp(n+1, vector<ll>(21,0));
// 1 番目の数は足す一択
dp[1][a[1]] = 1;

rep2(i,2,n) {
    rep(x,21) {
        // i 番目の数が x+a[i] となるのは dp[i-1] のとき x で i 番目の数字 a[i] を足したとき
        if (x+a[i] <= 20) dp[i][x+a[i]] += dp[i-1][x];

        // i 番目の数が x-a[i] となるのは dp[i-1] のとき x で i 番目の数字 a[i] を引いたとき
        if (x-a[i] >= 0) dp[i][x-a[i]] += dp[i-1][x];
    }
}

// n-1 番目の数を足し引きして, n 番目の数と一致する場合な数
cout << dp[n-1][a[n]] << endl;
```

[提出コード](https://atcoder.jp/contests/joi2011yo/submissions/28253843)


集める dp の場合
```cpp
rep2(i,2,n) {
    rep(x,21) {
        // i 番目の数字が x のなるのは i-1 の数字が x-a[i] で, i番目で a[i] を足したとき
        if (x-a[i] >= 0) dp[i][x] += dp[i-1][x-a[i]];

        // i 番目の数字が x のなるのは i-1 の数字が x+a[i] で, i番目で a[i] を引いたとき
        if (x+a[i] <= 20) dp[i][x] += dp[i-1][x+a[i]];
    }
}
```

[提出コード](https://atcoder.jp/contests/joi2011yo/submissions/28253965)



### JOI 2012 予選 4 - パスタ

[問題](https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d)

$dp[i][x][y]$: $i$ 日目にソース x を食べ, $i-1$ にソース y を食べたときの場合の数.

$i$, $i-1$ 日目にソース x を食べたとき, $i-2$ 日目には x 以外のソースを食べる必要があるため
$\displaystyle dp[i][x][x] = \sum_{k \neq x} dp[i-1][x][k]$

$i$, $i-1$ 日目に食べるソースが違った場合は $i-2$ 日目に何を食べてもよいので
$\displaystyle dp[i][x][y] = \sum_{k} dp[i-1][y][k]$


```cpp
void solve() {
    int N, K;
    cin >> N >> K;
    // dp[i][x][y]: i日目にソース x を食べ, i-1 日目にはソース y を食べたときの場合の数
    // ソースの種類 1 <= x, y <= 3
    // y = 0 のときは食べなかったことを表す
    int dp[105][4][4];
    rep(i,105) rep(j,4) rep(k,4) dp[i][j][k] = 0;

    map<int,int> mp;
    rep(i,K) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }

    const int MOD = 10000;
    if (mp.find(1) != mp.end()) {
        dp[1][mp[1]][0] = 1;
    } else {
        rep2(i,1,4) dp[1][i][0] = 1;
    }

    rep2(i,2,N+1) {
        rep2(x,1,4) {
            if (mp.find(i) != mp.end()) {
                // i 日目に食べるものが決まっていた場合は, それ以外の候補は除外する
                if (x != mp[i]) continue;
            }
            rep(y,4) {
                if (x == y) {
                    rep(z,4) {
                        // i, i-1 日目にソース x を食べたとき, i-2 日目には x 以外のソースを食べる必要がある
                        if (z != x) {
                            dp[i][x][x] += dp[i-1][x][z];
                            dp[i][x][x] %= MOD;
                        }
                    }
                } else {
                    rep(z,4) {
                        dp[i][x][y] += dp[i-1][y][z];
                        dp[i][x][y] %= MOD;
                    }
                }
            }
        }
    }


    ll ans = 0;
    rep2(i,1,4) rep2(j,1,4) {
        ans += dp[N][i][j];
        ans %= MOD;
    }
    cout << ans << endl;
```

[提出コード](https://atcoder.jp/contests/joi2012yo/submissions/28232419)

### JOI 2013 予選 4 - 暑い日々

[問題](https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d)

$dp[i][j]$: $i$ 日目に服 $j$ を着たときの $\displaystyle \sum_{k=1}^{i-1} |C_{x_k} - C_{x_{k+1}}|$ の最大値

$i$ 日目に服 $j$ を着たときの最大値は, $i-1$ 日目に服 $k$ ($1 \leq k \leq N$)を着たときからの遷移だから

$\displaystyle dp[i][j] = \max_{k} \left\{ dp[i-1][k] + |C[k] - C[j]| \right\}$

ただし, 最高気温に適した服のみ選ぶ.

答えは $D$ 日目に着ていた服のうち, $\displaystyle \sum_{i=1}^{D-1} |C_{x_i} - C_{x_{i+1}}|$ が最大となるもの.

```cpp
vector<vector<int>> dp(D+1, vector<int>(N+1, 0));
rep2(i,2,D+1) {
    rep2(j,1,N+1) {
        rep2(k,1,N+1) {
            // i 日目に j を, i-1 日目に k を着る
            if (A[j] <= T[i] && T[i] <= B[j] && A[k] <= T[i-1] && T[i-1] <= B[k]) {
                chmax(dp[i][j], dp[i-1][k]+abs(C[k]-C[j]));
            }
        }
    }
}

int ans = 0;
rep2(i,1,N+1) chmax(ans, dp[D][i]);
```

[提出コード](https://atcoder.jp/contests/joi2013yo/submissions/28234808)


### JOI 2015 予選 4 - シルクロード

[問題](https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d)

$dp[i][j]$: $i$ 日目に都市 $j$ にいるときの最小コスト

0 日目に都市 0 にいるコストは 0, $dp[0][0] = 0$.

$i$ 日目に都市 $j$ にいるときのコストは, $i-k$ 日目に都市 $j-1$ にいて, $i$ 日目に都市 $j$ に移動してきた, または,
$i-1$ 日目には都市 $j$ にいて, そのまま動かなかった場合のいずれか. そのうちの最小コストが $dp[i][j]$ となる.

- 移動してくる: $\displaystyle \min_k \{dp[i-k][j-1] + c[i] \times d[j]\}$
- 移動しない: $dp[i-1][j]$

$\displaystyle dp[i][j] = \min \left(dp[i-1][j],~ \min_k \{dp[i-k][j-1] + c[i] \times d[j]\}  \right)$

答えは $dp[m][n]$.


```cpp
vector<vector<ll>> dp(m+1, vector<ll>(n+1, INF));

dp[0][0] = 0;
rep2(i,1,m+1) {
    rep2(j,1,n+1) {
        rep2(k,1,i+1) {
            chmin(dp[i][j], dp[i-k][j-1] + c[i] * d[j]);
            chmin(dp[i][j], dp[i-1][j]);
        }
    }
}

cout << dp[m][n] << endl;
```

[提出コード](https://atcoder.jp/contests/joi2015yo/submissions/28237554)


### パ研杯2019 D - パ研軍旗

[問題](https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d)

$dp[j][x]$: $j$ 列目の色を x で塗ったときの最小コスト

2列連続で同じ色は使えないから, $dp[j][x]$ は $j-1$ 列目を色 y (x != y) で塗ったときのコストと j 列目を x で塗るときのコストの和のうち最小となるもの.

$\displaystyle dp[j][x] = \min_{x \neq y} \{ dp[j-1][y] + (\text{\# of not x at j th column}) \}$

```cpp
void solve() {
    int n;
    cin >> n;
    int nrow = 5;
    vector<vector<int>> flag(nrow, vector<int>(n+1,0));
    rep(i,nrow) {
        rep(j,n) {
            char c;
            cin >> c;
            if (c == 'R') flag[i][j+1] = 0;
            if (c == 'B') flag[i][j+1] = 1;
            if (c == 'W') flag[i][j+1] = 2;
            if (c == '#') flag[i][j+1] = 3;
        }
    }

    // dp[j][x]: j-1 列目までの色は確定しており, j 列目を色 x で塗ったときの最小コスト
    vector<vector<int>> dp(n+1, vector<int>(3, INF));
    rep(x,3) dp[0][x] = 0;

    rep2(j,1,n+1) {
        rep(x,3) {
            int numnotx = 0;
            rep(i,nrow) {
                numnotx += flag[i][j] != x;
            }

            rep(y,3) {
                if (x == y) continue;
                chmin(dp[j][x], dp[j-1][y] + numnotx);
            }
        }
    }

    int ans = INF;
    rep(x,3) chmin(ans, dp[n][x]);
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/pakencamp-2019-day3/submissions/28253637)



### AOJ 1167 - ポロック予想

[問題](https://onlinejudge.u-aizu.ac.jp/problems/1167)

$dp[x]$: x を表すのに必要な正四面体数の個数の最小値

$\displaystyle dp[x] = \min_{i}\{ dp[x-s_i] + dp[s_i] \}$ ここで $s_i$ は $i$ 番目の正四面体数.

x が小さいところから順に確定させていく

```cpp
void solve() {
    // sq[i]: i 番目の正四面体数
    vector<int> sq;
    for (int n = 1; n*(n+1)*(n+2)/6 <= (int)1e6; n++) {
        sq.push_back(n*(n+1)*(n+2)/6);
    }

    // dp[x]: x を表すのに必要な正四面体数の個数の最小値
    vector<int> dp((int)1e6+5, INF);
    vector<int> odddp((int)1e6+5, INF);
    for (int x : sq) {
        dp[x] = 1;
        if (x&1) odddp[x] = 1;
    }

    rep(x,(int)1e6+1) {
        for (int s : sq) {
            if (x - s >= 0) {
                chmin(dp[x], dp[x-s] + dp[s]);
                if (s&1) chmin(odddp[x], odddp[x-s] + odddp[s]);
            }
        }
    }

    while (1) {
        int x;
        cin >> x;
        if (x == 0) return;
        cout << dp[x] << " " << odddp[x] << endl;
    }
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/1167/judge/6165707/C++17)


### AOJ 2199 - 差分パルス符号変調

[問題](https://onlinejudge.u-aizu.ac.jp/problems/2199)

$dp[i][x]$: $y_i = x$ となるときの考えうる二乗和のうちの最小値

$y_{i-1} + C[l] > 255$ のとき $y_i = 255$, $y_{i-1} + C[l] < 0$ のとき $y_i = 0$ になるので配る dp で書くと楽そう

答えは $\displaystyle \min_k \{ dp[n][k] \}$.

```cpp
void solve(int n, int m) {
    vector<int> C(m+1), x(n+1);
    rep(i,m) cin >> C[i+1];
    rep(i,n) cin >> x[i+1];

    // dp[i][x]: y_i が x だったときの二乗和の最小値
    vector<vector<int>> dp(n+1, vector<int>(256,INF));
    dp[0][128] = 0;

    rep2(i,1,n+1) {
        rep(k,256) {
            rep2(j,1,m+1) {
                int s = k + C[j];
                if (s > 255) s = 255;
                if (s < 0) s = 0;
                chmin(dp[i][s], dp[i-1][k] + (s-x[i])*(s-x[i]));
            }
        }
    }

    int ans = INF;
    rep(i,256) chmin(ans, dp[n][i]);
    cout << ans << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/2199/judge/6166950/C++17)


## 動的計画法：区間 DP

### ALDS_10_B - 連鎖行列積

[問題](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_B)

$f(l,r)$ を $M_l M_{l+1} \cdots M_r$ のスカラー乗算の回数が最小値とする.

$\displaystyle f(l, r) = \min_{k \in [0, r), k \in \Z} \{ f(l,k) + f(k+1, r) + (\text{\# of row of } M_l) \times (\text{\# of column of } M_k) \times (\text{\# of column of } M_r) \}$
となる.

```cpp
int dfs(int l, int r) {
    if (l < 0 || r >= n) return INF;
    if (visited[l][r]) return dp[l][r];
    visited[l][r] = 1;

    rep2(k,l,r) {
        chmin(dp[l][r], dfs(l,k) + dfs(k+1,r) + mats[l].first * mats[k].second * mats[r].second);
    }

    return dp[l][r];
}


void solve() {
    cin >> n;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        mats.push_back({a,b});
    }

    // dp[l][r]: [l, r] の範囲の連鎖行列のスカラー乗算回数の最小値
    dp.resize(n, vector<int>(n, INF));
    visited.resize(n, vector<int>(n, 0));
    rep(i,n) {
        dp[i][i] = 0;
        visited[i][i] = 1;
    }

    cout << dfs(0, n-1) << endl;
}
```


[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/ALDS1_10_B/judge/6167331/C++17)


### JOI 2015 本選 2 - ケーキの切り分け 2

[問題](https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b)

$calc(s, f)$: JOI の番が終わった状態で, $A_s$, $A_f$ が端として残っているときから操作をすることで JOI が獲得できるスコアの最大値とする. (すでに食べられた部分のことは考えない)

次のターンで IOI は $A_s$ と $A_f$ のうち大きい方を食べる.

- $A_s > A_f$ のとき
IOI が $A_s$ を食べ, 次のターンに JOI は $A_{s-1}$ または $A_f$ を食べる.
$A_{s-1}$ を食べたときの得点は $A_{s-1} + calc(s-2, f)$, $A_f$ を食べたときの得点は $A_f + calc(s-1, f+1)$.
この2通りのうち大きいほうが $calc(s, f)$ となるので

$calc(s, f) = \max(A_{s-1} + calc(s-2, f), A_f + calc(s-1, f+1))$.

- $A_s < A_f$ のとき

同様にして

$calc(s, f) = \max(A_s + calc(s-1, f+1), A_{f+1} + calc(s, f+2))$.


あとは JOI がピースのどの部分から食べるかを全探索することで答えを得られる.

```cpp
int n;
vector<vector<ll>> dp, visited;
vector<ll> A;

// calc(s, f): JOI の番が終わった段階で A_s と A_f が端として残っているとき,
//             JOI が獲得できる最大のスコア
// s+1, ..., f-1 (mod n) の範囲がすでに食べられている
ll calc(int s, int f) {
    if (s == f) return 0; // 残りが1つのときは JOI に得点は入らない
    if (s == (f+1)%n) return min(A[s], A[f]); // 残り2つのとき小さいほうが JOI の得点
    if (visited[s][f]) return dp[s][f];
    visited[s][f] = 1;

    // JOI の番が終わった状態で A[s], A[f] が残っているとき, IOI は A[s] または A[f] の
    // 大きい方を食べる
    if (A[s] > A[f]) {
        // IOI が A[s] をたべる
        // IOI のあとに JOI は A[s-1] または A[f] を食べる.
        return dp[s][f] = max(
            calc((s-2+n)%n, f) + A[(s-1+n)%n], // JOI が A[s-1] を食べる
            calc((s-1+n)%n, (f+1)%n) + A[f]    // JOI が A[f] を食べる
        );
    }
    return dp[s][f] = max(
        calc((s-1+n)%n, (f+1)%n) + A[s], // JOI が A[s] を食べる
        calc(s, (f+2)%n) + A[(f+1)%n]    // JOI が A[f+1] を食べる
    );
}

void solve() {
    cin >> n;
    dp.resize(n, vector<ll>(n, 0));
    visited.resize(n, vector<ll>(n, 0));
    A.resize(n);
    rep(i,n) cin >> A[i];

    ll ans = 0;
    rep(i,n) {
        int s = (i - 1 + n) % n;
        int f = (i + 1) % n;
        chmax(ans, A[i] + calc(s,f));
    }
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/joi2015ho/submissions/28264730)


### AOJ 1611 ダルマ落とし

[問題](https://onlinejudge.u-aizu.ac.jp/problems/1611)

$\mathrm{dfs}(l, r)$: $[l, r]$ の区間のブロックを落とせる最大値とする

- $\mathrm{dfs}(l+1, r-1) = l-r-1$ のとき

$[l+1, r-1]$ の範囲のブロックをすべて落とせるということだから

$\mathrm{dfs}(l, r) = \mathrm{dfs}(l+1, r-1) + (|w_l - w_r| \leq 1) \times 2$

- 適当な $k \in [l, r]$ で上下を分離して考えたとき

$\displaystyle \mathrm{dfs}(l, r) = \min_{k \in [l,r-1]} \{ \mathrm{dfs}(l, k) + \mathrm{dfs}(k+1, r) \}$

$k$, $k+1$ 番目のブロックが $|w_k - w_{k+1}| \leq 1$ を満たしていてもそれをここで考慮する必要はない.
なぜなら, そのようなケースの場合は $\mathrm{dfs}(l+1, r-1) = l-r-1$ のときの条件ですでに考慮されているため.

```cpp
int n;
const int MAX = 305;
int w[MAX], dp[MAX][MAX], visited[MAX][MAX];

void init() {
    rep(i,n) cin >> w[i];
    rep(i,MAX) rep(j,MAX) dp[i][j] = visited[i][j] = 0;
}

// dfs(l, r): [l, r] の範囲で落とせる最大の数
int dfs(int l, int r) {
    if (l >= r) return 0;
    if (visited[l][r]) return dp[l][r];
    visited[l][r] = 1;

    if (dfs(l+1, r-1) == r-l-1) {
        chmax(dp[l][r], dfs(l+1, r-1) + (abs(w[l] - w[r]) <= 1) * 2);
    }
    rep2(k,l,r) {
        chmax(dp[l][r], dfs(l, k) + dfs(k+1, r));
    }

    return dp[l][r];
}

void solve() {
    init();
    cout << dfs(0, n-1) << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/1611/judge/6167977/C++17)


## 動的計画法：bit DP

### DPL_2_A - 巡回セールスマン問題

[問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A)

$dp[S][x]$: $S$ をすでに訪れた node の集合, $x$ を最後に訪れた node としたときのコストの最小値
サイクルがあるならどこからスタートしても問題ないので node 0 から始めたとする.
まだどこも訪れていない状態で node 0 にいるコストは 0 なので $dp[{}][0] = 0$.
答えはすべてを訪れた状態で最後に訪れたのが 0 のときだから $dp[V][0]$.

```cpp
bool hasBit(int x, int i) {
    return (x>>i)&1;
}

struct Edge {
    int from, weight;
};

int v, e;
vector<vector<Edge>> graph;

void solve() {
    cin >> v >> e;
    graph.resize(v);
    rep(i,e) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[t].push_back({s, d});
    }

    // dp[S][x]: S を訪れた集合, x を最後に訪れた node としたときのコストの最小値
    // サイクルがあるならどこからスタートでも問題ないので node 0 からスタートすると考える
    vector<vector<int>> dp(1<<v, vector<int>(v, INF));
    dp[0][0] = 0;
    rep(S, 1<<v) {
        rep(x,v) {
            if (!hasBit(S, x)) {
                for (auto edge : graph[x]) {
                    int from = edge.from;
                    int weight = edge.weight;
                    chmin(dp[S|(1<<x)][x], dp[S][from] + weight);
                }
            }
        }
    }

    int ans = dp[(1<<v)-1][0];
    cout << (ans == INF ? -1 : ans) << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DPL_2_A/judge/6168190/C++17)


### Square869120Contest #1 G - Revenge of Traveling Salesman Problem

[問題](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g)

上記の巡回セールマン問題とほぼ同じだが, 遷移を考えるときに時間を見て, 所定の時間を超えていた場合は緩和処理を飛ばすようにする.


```cpp
bool hasBit(int x, int i) {
    return (x>>i)&1;
}

struct Edge {
    int from;
    ll weight, time;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    rep(i,m) {
        int s, t;
        ll d, time;
        cin >> s >> t >> d >> time;
        s--, t--;
        graph[s].push_back({t, d, time});
        graph[t].push_back({s, d, time});
    }

    // dp[S][x]: S 訪れた建物の集合, x 最後に訪れた建物としたときの最短時間とそれを達成する方法の総数
    // pair = (time, count)
    vector<vector<pair<ll,ll>>> dp(1<<n, vector<pair<ll,ll>>(n, {INF, 0}));
    dp[0][0] = {0, 1};
    rep(S, 1<<n) {
        rep(x,n) {
            if (!hasBit(S, x)) {
                for (auto edge : graph[x]) {
                    int from = edge.from;
                    ll weight = edge.weight;
                    ll time = edge.time;
                    ll cost = dp[S][from].first + weight;
                    if (cost > time) continue;
                    if (dp[S|(1<<x)][x].first > cost) {
                        dp[S|(1<<x)][x] = {cost, dp[S][from].second};
                    } else if (dp[S|(1<<x)][x].first == cost) {
                        dp[S|(1<<x)][x].second += dp[S][from].second;
                    }
                }
            }
        }
    }

    ll ans_time = dp[(1<<n)-1][0].first;
    ll ans_cnt = dp[(1<<n)-1][0].second;
    if (ans_time == INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans_time << " " << ans_cnt << endl;
}
```

[提出コード](https://atcoder.jp/contests/s8pc-1/submissions/28272213)

### JOI 2014 予選 4 - 部活のスケジュール表
[問題](https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d)

$dp[i][S]$: $i$ 日目に出席する人の集合が $S$ のなる場合の数とする.
最初鍵を持っている J は0日目に出席したと考えて $dp[0][\{\text{J}\}] = 1$.

$i$ 日目には責任者と $i-1$ 日目に鍵を持ち帰った人が出席する必要があるから,
$i$ 日目の責任者を $x$, $i$ 日目の出席者の集合を $S_i$ とすると $x \in S_i \wedge S_i \cap S_{i-1} \neq \empty$ が成り立つ. 鍵は出席者のうちの誰かが持ち帰ればいいので, 誰が持ち帰ったかということは気にする必要はない.

\begin{align}
dp[i][S] =
\left\{
    \begin{aligned}
    & 0  ~~(S \text{に責任者が含まれない場合)} \\
    & \sum_{S^\prime} dp[i-1][S^\prime] ~~ (S \cap S^\prime \neq \empty)
    \end{aligned}
\right.
\end{align}

となる.
入力例1 と照らし合わせると二日目に J, O, I となるのは1日目が J, O 由来のものと, J, O, I 由来がある.

```cpp
bool hasBit(int x, int n) {
    return (x>>n)&1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> admin(n+1);
    rep(i,n) admin[i+1] = (s[i] == 'J' ? 0 : s[i] == 'O' ? 1 : 2);

    const int mod = 10007;

    // dp[i][S]: i 日目に出席する人の集合が S となる場合の数
    vector<vector<int>> dp(n+1, vector<int>(1<<3, 0));
    dp[0][1] = 1;
    rep2(i,1,n+1) {
        rep(S, 1<<3) {
            rep(Sp, 1<<3) {
                if (hasBit(S, admin[i]) && (S & Sp) > 0) {
                    dp[i][S] += dp[i-1][Sp];
                    dp[i][S] %= mod;
                }
            }
        }
    }

    int ans = 0;
    rep(S, 1<<3) {
        ans += dp[n][S];
        ans %= mod;
    }
    cout << ans << endl;
}
```


[提出コード](https://atcoder.jp/contests/joi2014yo/submissions/28287737)


### JOI 2017 予選 4 - ぬいぐるみの整理

[問題](https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d)

愚直にぬいぐるみの並び順を考えると $M!$ 通りあるので $1 \leq M \leq 20$ の制約では全探索は現実的ではない.
$M$ の制約が小さいので順列全探索を $O(M 2^M)$ の DP で解く問題なのだろうという推測がつく.
$2^{20} = 1048576$ なのでこれならば実行時間制限に十分間に合う.

$dp[S]$ をすでに並べたぬいぐるみの集合を $S$ としたときの最小コストとする.
すでに並べたぬいぐるみが決まっているとき, それまででどこにどのぬいぐるみを置いたかを考慮する必要はない.
よって
$\displaystyle dp[S] = \min_{k} \{ dp[S \backslash \{k\}] + (k \text{を置くためにどかす必要のあるぬいぐるみの数)} \}$

```cpp
void solve() {
    int n, m;
    cin >> n >> m;
    // numfig[i][j]: ぬいぐるみ i が j 列目までに何個含まれているか
    vector<vector<int>> numfig(m, vector<int>(n+1, 0));
    rep(i,n) {
        int c;
        cin >> c;
        c--;
        numfig[c][i+1]++;
    }
    rep(i,m) rep(j,n) numfig[i][j+1] += numfig[i][j];

    // dp[S]: すでに並べたぬいぐるみの集合を S としたときの最小コスト
    // 0 種類のぬいぐるみを置くとき, 入れ替えが必要な種類は 0.
    vector<int> dp(1<<m, INF);
    dp[0] = 0;
    rep2(S, 1,1<<m) {
        int num_occupied = 0; // S のぬいぐるみが置かれているとき, すでに何個決まっているか
        rep(j,m) if (S & (1<<j)) num_occupied += numfig[j][n];
        rep(i,m) {
            if (!hasBit(S, i)) continue;
            int numi = numfig[i][n]; // ぬいぐるみ i が全部で何個あるか
            int must_remove = numi - (numfig[i][num_occupied] - numfig[i][num_occupied - numi]);
            chmin(dp[S], dp[S^(1<<i)]+must_remove);
        }
    }
    cout << dp[(1<<m)-1] << endl;
}
```

[提出コード](https://atcoder.jp/contests/joi2017yo/submissions/28292131)


## 動的計画法：その他

### DPL_1_D - 最長増加部分列 (LIS, Longest Increasing Subsequence)
[問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D)

参考記事: [最長増加部分列(LIS)の長さを求める](https://qiita.com/python_walker/items/d1e2be789f6e7a0851e5)

無駄な更新をしないようにすると `upper_bound` 使って以下のような感じになる.
```cpp
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), lis(n, INF);
    rep(i,n) cin >> a[i];

    rep(i,n) {
        auto it = upper_bound(all(lis), a[i]);
        if (it == lis.begin()) {
            *it = a[i];
        } else if (*(it-1) < a[i]) {
            *it = a[i];
        }
    }

    auto it = lower_bound(all(lis), INF);
    cout << it - lis.begin() << endl;
}
```

同じところを同じ数字に置き換えても問題ないので, `lower_bound` を使うほうがよりシンプルに書ける.

```cpp
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), lis(n, INF);
    rep(i,n) cin >> a[i];

    rep(i,n) {
        auto it = lower_bound(all(lis), a[i]);
        *it = a[i];
    }

    auto it = lower_bound(all(lis), INF);
    cout << it - lis.begin() << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DPL_1_D/judge/6170671/C++17)


### AtCoder Beginner Contest 006 D - トランプ挿入ソート

[問題](https://atcoder.jp/contests/abc006/tasks/abc006_4)

LIS 分はトランプを動かす必要ないが, それ以外はソートのために動かさないといけないので $N - LIS$ が答え.

```cpp
void solve() {
    int n;
    cin >> n;
    vector<int> c(n), lis(n, INF);
    rep(i,n) cin >> c[i];

    rep(i,n) {
        auto it = lower_bound(all(lis), c[i]);
        *it = c[i];
    }

    cout << n - (lower_bound(all(lis), INF) - lis.begin()) << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc006/submissions/28292614)


### AtCoder Beginner Contest 134 E - Sequence Decomposing

[問題](https://atcoder.jp/contests/abc134/tasks/abc134_e)

けんちょん さんの[解説記事](https://drken1215.hatenablog.com/entry/2020/12/25/184700)がとてもわかり易かった.

```cpp
void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    rep(i,n) cin >> A[i];
    vector<int> lis(n, INF);
    reverse(all(A));

    rep(i,n) {
        auto it = upper_bound(all(lis), A[i]);
        *it = A[i];
    }

    cout << lower_bound(all(lis), INF) - lis.begin() << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc134/submissions/28293382)


## 最短経路問題：ダイクストラ法

### GRL_1_A - 単一始点最短経路

[問題](https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A)

素直にダイクストラを実装する

```cpp
struct Edge {
    int to, cost;
};

void solve() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<Edge>> graph(n);
    rep(i,m) {
        int s, t, cost;
        cin >> s >> t >> cost;
        graph[s].push_back({t, cost});
    }

    vector<int> dist(n, INF);
    dist[r] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, r});
    while (!pq.empty()) {
        int cost, node;
        tie(cost, node) = pq.top();
        pq.pop();

        for (auto e : graph[node]) {
            if (dist[e.to] > dist[node] + e.cost) {
                pq.push({dist[node]+e.cost, e.to});
                dist[e.to] = dist[node] + e.cost;
            }
        }
    }

    rep(i,n) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/GRL_1_A/judge/6171021/C++17)


### JOI 2008 予選 6 - 船旅
[問題](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f)

注文表のときは最短距離を計算して, 新たな航路ができたときはグラフを更新する.

[提出コード](https://atcoder.jp/contests/joi2008yo/submissions/28295773)


### JOI 2016 予選 5 - ゾンビ島
[問題](https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e)

公式解説のように危険な町の探索の仕方を工夫する.

```cpp
using Graph = vector<vector<Edge>>;

// 危険な町か否かの情報を持つ vector を返す
// 0 -> 安全
// 1 -> 危険
// -1 -> ゾンビがいる町 を表す
vector<int> danger_zone(Graph graph, vector<int> &zonbi, int s) {
    // ゾンビがいる町と直接つながる仮想的な町を追加する.
    // その町から距離 s+1 以内にある町が危険な町
    graph.push_back(vector<Edge>());
    int n = graph.size();
    int k = zonbi.size();
    rep(i,k) graph[n-1].push_back({zonbi[i], 0});

    vector<int> isdanger(n, 0);

    // P: island id, distance
    queue<P> que;
    que.push({n-1, -1}); // ゾンビがいる町にいるときにコスト 0 になるように距離を -1 にしておく.
    while (!que.empty()) {
        auto p = que.front();
        int id = p.first;
        int dis = p.second;
        que.pop();

        isdanger[id] = 1;
        for (auto e : graph[id]) {
            if (isdanger[e.to]) continue;
            if (dis+1 <= s) {
                que.push({e.to, dis+1});
            }
        }
    }

    rep(i,k) isdanger[zonbi[i]] = -1;

    return isdanger;
}

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    ll p, q;
    cin >> p >> q;

    vector<int> C(k);
    rep(i,k) cin >> C[i], C[i]--;

    Graph graph(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back({b, INF});
        graph[b].push_back({a, INF});
    }

    vector<int> is_danger = danger_zone(graph, C, s);
    // 危険な町の情報をもとに移動コストをつけ直す
    rep(i,n) {
        for (auto &e : graph[i]) {
            if (e.to == n-1) e.cost = 0; // 町 n-1 では宿泊しないのでコスト 0
            else if (is_danger[e.to] == -1) e.cost = INF;
            else if (is_danger[e.to] == 1) e.cost = q;
            else e.cost = p;
        }
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;

    // P: cost, node id
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto node = pq.top();
        int id = node.second;
        pq.pop();
        for (auto e : graph[id]) {
            if (dist[e.to] > dist[id] + e.cost) {
                dist[e.to] = dist[id] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    cout << dist[n-1] << endl;
}
```

[提出コード](https://atcoder.jp/contests/joi2016yo/submissions/28297302)


### JOI 2014 予選 5 - タクシー
[問題](https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e)

町 $i$ とタクシー $i$ で到達できる町を直接つなぐグラフを作り, そのグラフに対して最短経路問題を解く.
辺の数がすごいことになりそうだが大丈夫らしい.
$K$ が最大でも 10000 というところが結構効いているっぽい.
$N = 5000$ のときの完全グラフの辺の数は $\displaystyle \frac{5000 \times 4999}{2} = 12497500$ なので,
それと比べると確かに辺の数が少ないスカスカなグラフということがわかる.

```cpp
struct Edge {
    int to;
    ll cost;
};

using Root = vector<vector<int>>;
using Graph = vector<vector<Edge>>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> cost(n), R(n);
    rep(i,n) cin >> cost[i] >> R[i];

    Root root(n); // 道のつながりを表す
    rep(i,k) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        root[a].push_back(b);
        root[b].push_back(a);
    }

    // taxi で同じ値段で行けるところを直接つなぐグラフを構築する
    Graph graph(n);
    // P: id, dist
    queue<P> que;
    rep(i,n) {
        // taxi i を使って到達できる町を調べる
        vector<int> visited(n, 0);
        que.push({i,0});
        visited[i] = 1;
        while (!que.empty()) {
            auto q = que.front();
            que.pop();
            visited[q.first] = 1;
            for (int to : root[q.first]) {
                if (visited[to]) continue;
                int next_step = q.second + 1;
                if (next_step <= R[i]) {
                    que.push({to, next_step});
                }
            }
        }

        // 町 i と taxi i からいける町を直接つなぐ graph をつくる
        rep(k,n) if (i != k && visited[k]) graph[i].push_back({k, cost[i]});
    }

    // dijkstra
    vector<ll> dist(n, INF);
    dist[0] = 0;
    // P: cost, node id
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        for (auto e : graph[node.second]) {
            if (dist[e.to] > dist[node.second] + e.cost) {
                dist[e.to] = dist[node.second] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    cout << dist[n-1] << endl;
}
```

[提出コード](https://atcoder.jp/contests/joi2014yo/submissions/28298613)


## 最短経路問題：ワーシャルフロイド法

### GRL_1_C - 全点対間最短経路

[問題](https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/GRL_1_C/judge/6171465/C++17)

### AtCoder Beginner Contest 012 D - バスと避けられない運命

[問題](https://atcoder.jp/contests/abc012/tasks/abc012_4)
[提出コード](https://atcoder.jp/contests/abc012/submissions/28299292)

### AtCoder Beginner Contest 079 D - Wall
[問題](https://atcoder.jp/contests/abc079/tasks/abc079_d)
[提出コード](https://atcoder.jp/contests/abc079/submissions/28299377)


### AtCoder Beginner Contest 074 D - Restoring Road Network
[問題](https://atcoder.jp/contests/abc074/tasks/arc083_b)

与えられた隣接行列に対してワーシャルフロイドをして, 距離が変われば元々の隣接行列の値は最短距離を表していなかったということなのでそのような経路は存在しない.

経路が存在していた場合, どこかを経由した場合と, 直接行く場合の距離が同じ場合,
すなわち $dist(i, j) = dist(i, k) + dist(k, j)~~ (i \neq k \wedge k \neq j)$ のとき
直接の経路はなくても最短距離に影響を及ぼさないので消しても問題ない.

```cpp
void solve() {
    int n;
    cin >> n;
    Graph A(n, vector<ll>(n, 0));
    rep(i,n) rep(j,n) cin >> A[i][j];

    // Floyd–Warshall
    // 最短距離を求めて, 元の matrix と異なった場合は, 元々の隣接行列は最短距離ではなかったということ
    Graph B = A;
    rep(k,n) rep(i,n) rep(j,n) chmin(A[i][j], A[i][k] + A[k][j]);
    rep(i,n) rep(j,n) {
        if (A[i][j] != B[i][j]) {
            cout << -1 << endl;
            return;
        }
    }

    // 直接つないでいる距離が他を経由しても同じ場合は, 直接の経路はなくしても
    // 全体の最短距離には影響を与えない
    Graph removable(n, vector<ll>(n, 0));
    rep(k,n) rep(i,n) rep(j,n) {
        if (j != k && i != k && A[i][j] == A[i][k] + A[k][j]) removable[i][j] = 1;
    }
    rep(i,n) rep(j,n) if (removable[i][j]) A[i][j] = 0;

    // 無向グラフなので上三角部分を足すと経路の和になる
    ll ans = 0;
    rep(i,n) rep2(j,i+1, n) ans += A[i][j];
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc074/submissions/28302075)


## 最小全域木問題

### GRL_2_A - 最小全域木

[問題](https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A)

適当に root を決めて, 辺のコストが小さい順に採用していく. (プリム法)

```cpp
struct Edge {
    int to;
    ll cost;
};

bool operator> (const Edge &a, const Edge &b) {
    return a.cost > b.cost;
}

using Graph = vector<vector<Edge>>;

void solve() {
    int v, e;
    cin >> v >> e;
    Graph graph(v);
    rep(i,e) {
        int s, t;
        ll w;
        cin >> s >> t >> w;
        graph[s].push_back({t, w});
        graph[t].push_back({s, w});
    }

    vector<int> used(v, 0);
    used[0] = 1;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (auto e : graph[0]) pq.push(e);
    ll ans = 0;
    while (!pq.empty()) {
        auto e = pq.top();
        pq.pop();
        if (used[e.to]) continue;
        used[e.to] = 1;
        ans += e.cost;
        for (auto edge : graph[e.to]) {
            if (used[edge.to]) continue;
            pq.push(edge);
        }
    }
    cout << ans << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/GRL_2_A/judge/6171650/C++17)


### JOI 2010 春合宿 - Finals
[問題](https://atcoder.jp/contests/joisc2010/tasks/joisc2010_finals)

最小全域木を作ったあと, コストが高い辺 $k-1$ 本を抜いたときの残りの辺のコストを合計が答え.

[提出コード](https://atcoder.jp/contests/joisc2010/submissions/28302422)


### AOJ 1127 - Building a Space Station
[問題](https://onlinejudge.u-aizu.ac.jp/problems/1127)

球体 $i$, $j$ 間の距離を $dist(i,j)$ とする. $dist(i,j) > r_i + r_j$ ならば corridor を作る必要があるし,
そうでないならば球体同士は接するまたはオーバーラップしているので corridor を作る必要はない.
作る必要のある corridor の長さを辺とする graph をつくり, 最小全域木のコストを出力する.
ただしcorridor を作る必要がないときの辺の長さ 0 とする.

```cpp
using Graph = vector<vector<double>>;

void solve(int n) {
    vector<double> x(n), y(n), z(n), r(n);
    rep(i,n) {
        cin >> x[i] >> y[i] >> z[i] >> r[i];
    }

    Graph dist(n, vector<double>(n, 0.0));
    rep(i,n) rep2(j,i+1,n) {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        double dz = z[i] - z[j];
        if (sqrt(dx*dx + dy*dy + dz*dz) > r[i] + r[j]) {
            dist[i][j] = dist[j][i] = sqrt(dx*dx + dy*dy + dz*dz) - (r[i] + r[j]);
        }
    }

    // PDI: cost, node id
    using PDI = pair<double,int>;
    priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
    rep2(i,1,n) pq.push({dist[0][i], i});
    vector<int> used(n, 0);
    used[0] = 1;
    double ans = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (used[t.second]) continue;
        used[t.second] = 1;
        ans += t.first;
        rep(i,n) {
            if (used[i]) continue;
            pq.push({dist[t.second][i], i});
        }
    }
    printf("%.3lf\n", ans);
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/1127/judge/6171699/C++17)



### AtCoder Beginner Contest 065 D - Built?

[問題](https://atcoder.jp/contests/abc065/tasks/arc076_b)

プリム法からわかるように最小全域木を構築する過程では最もコストの小さい辺から採用していくので,
この問題の場合, 最も $x$ 軸方向に最も近い node をつなぐ辺か, $y$ 軸方向に最も近い node をつなぐ辺の2通り以外の辺を
考える必要はない.
よって, 座標を $x$, $y$ それぞれでソートして隣接する node 間に辺を張ったグラフを作り最小全域木を作ればよい.
辺の数が $2(N-1)$ 本になるので計算量は $O(N \log N)$ になる.

```cpp
void solve() {
    int n;
    cin >> n;
    vector<P> x(n), y(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        x[i] = {a, i};
        y[i] = {b, i};
    }

    sort(all(x));
    sort(all(y));

    using Graph = vector<vector<P>>;
    Graph graph(n);
    rep(i,n-1) {
        int a = x[i].second;
        int costa = x[i].first;
        int b = x[i+1].second;
        int costb = x[i+1].first;
        graph[a].push_back({abs(costa - costb), b});
        graph[b].push_back({abs(costa - costb), a});
    }
    rep(i,n-1) {
        int a = y[i].second;
        int costa = y[i].first;
        int b = y[i+1].second;
        int costb = y[i+1].first;
        graph[a].push_back({abs(costa - costb), b});
        graph[b].push_back({abs(costa - costb), a});
    }

    vector<int> used(n, 0);
    used[0] = 1;
    priority_queue<P, vector<P>, greater<P>> pq;
    for (auto e : graph[0]) pq.push(e);
    ll ans = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (used[p.second]) continue;
        used[p.second] = 1;
        ans += p.first;
        for (auto e : graph[p.second]) {
            if (used[e.second]) continue;
            pq.push(e);
        }
    }
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc065/submissions/28302812)


## 高速な素数判定法

### NTL_1_A - 素因数分解
[問題](https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A)

```cpp
void solve() {
    int n;
    cin >> n;
    cout << n << ":";
    int t = n;
    for (int i = 2; i*i <= n; i++) {
        while (t % i == 0) {
            cout << " " << i;
            t /= i;
        }
    }
    if (t > 1) cout << " " << t;
    cout << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/NTL_1_A/judge/6171712/C++17)


### AtCoder Beginner Contest 084 D - 2017-like Number
[問題](https://atcoder.jp/contests/abc084/tasks/abc084_d)

- エラトステネスのふるいで素数判定テーブルを作る
- $[0,r]$ の範囲に 2017 に似た数がいくつあるかを保持する累積和を作る
- `cum[r] - cum[l-1]` を答える

```cpp
void solve() {
    int MAX = 100005;
    vector<int> isprime(MAX, false);
    for (int i = 2; i < MAX; i++) {
        if (!isprime[i]) {
            for (int j = i+i; j < MAX; j+=i) {
                isprime[j] = true;
            }
        }
    }
    rep2(i,2,MAX) isprime[i] = !isprime[i];

    vector<int> like2017(MAX, 0);
    for (int i = 3; i < MAX; i+=2) {
        if (isprime[i] && isprime[(i+1)/2]) like2017[i] = 1;
    }
    vector<int> cum(MAX, 0);
    rep(i,MAX-1) cum[i+1] += cum[i] + like2017[i+1];

    int q;
    cin >> q;
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        cout << cum[r] - cum[l-1] << endl;
    }
}
```

[提出コード](https://atcoder.jp/contests/abc084/submissions/28303166)




## 高速なべき乗計算

### NTL_1_B - べき乗
[問題](https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B)

```cpp
ll powmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return ret;
}

void solve() {
    int m, n;
    cin >> m >> n;
    cout << powmod(m, n, (ll)1e9+7) << endl;
}
```

[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/NTL_1_B/judge/6171740/C++17)


### Square869120Contest #1 E - 散歩
[問題](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e)

```cpp
const ll MOD = (ll)1e9 + 7;

ll powmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return ret;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), c(q+2, 0);
    rep(i,n) cin >> a[i];
    rep(i,q) cin >> c[i+1], c[i+1]--;

    vector<ll> len(n, 0);
    rep2(i,1,n) len[i] = powmod(a[i-1], a[i], MOD);
    vector<ll> cumlen(n+1, 0);
    rep2(i,1,n+1) {
        cumlen[i] += cumlen[i-1] + len[i];
        cumlen[i] %= MOD;
    }

    ll ans = 0;
    rep2(i,1,q+2) {
        int a = c[i];
        int b = c[i-1];
        if (a > b) swap(a,b);
        ans += (cumlen[b] - cumlen[a] + MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
```
[提出コード](https://atcoder.jp/contests/s8pc-1/submissions/28303428)


## 逆元を使う問題


### AtCoder Beginner Contest 034 C - 経路
[問題](https://atcoder.jp/contests/abc034/tasks/abc034_c)

```cpp
ll powmod(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ret;
}

ll invmod(ll x, ll mod) {
    return powmod(x, mod-2, mod);
}

void solve() {
    const ll MOD = (ll)1e9 + 7;
    const ll MAX = (ll)2e5 + 5;
    ll W, H;
    cin >> W >> H;
    // (W+H) choose W
    vector<ll> fac(MAX, 1), invfac(MAX, 1);
    rep2(i,2,MAX) fac[i] = (fac[i-1] * i) % MOD;
    rep2(i,2,MAX) invfac[i] = invmod(fac[i], MOD);

    W--, H--;
    ll ans = 1;
    ans = ans * fac[H+W] % MOD;
    ans = ans * invfac[H] % MOD;
    ans = ans * invfac[W] % MOD;
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc034/submissions/28303535)


### AtCoder Beginner Contest 145 D - Knight
[問題](https://atcoder.jp/contests/abc145/tasks/abc145_d)

$(i+1,j+2)$ の操作を $a$ 回, $(i+2,j+1)$ の操作を $b$ 回行うとすると

\begin{align}
\left\{
    \begin{aligned}
        a + 2b = X \\
        2a + b = Y
    \end{aligned}
\right.
\Rightarrow
\left\{
    \begin{aligned}
        a = \frac{2Y - X}{3} \\
        b = \frac{2X - Y}{3}
    \end{aligned}
\right.
\end{align}

が成り立つ.
$a < 0$ or $b < 0$ のとき条件を満たす操作はない.

操作できるときは $\displaystyle \comb{a+b}{a} = \frac{(a+b)!}{a!~b!}$ を求めればよい

```cpp
ll powmod(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if(n&1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

ll invmod(ll x, ll mod) {
    return powmod(x, mod-2, mod);
}

void solve() {
    ll MAX = (ll)2e6 + 6;
    ll MOD = (ll)1e9 + 7;
    vector<ll> fac(MAX, 1), invfac(MAX, 1);
    rep2(i,2,MAX) fac[i] = fac[i-1] * i % MOD;
    rep2(i,2,MAX) invfac[i] = invmod(fac[i], MOD);

    ll x, y;
    cin >> x >> y;
    ll a = 2* x - y;
    ll b = 2* y - x;
    if (a >= 0 && b >= 0 && a % 3 == 0 && b % 3 == 0) {
        a /= 3, b /= 3;
        ll ans = fac[a+b] * (invfac[a] * invfac[b] % MOD) % MOD;
        cout << ans << endl;
        return;
    }
    cout << 0 << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc145/submissions/28303725)


### AtCoder Beginner Contest 021 D - 多重ループ

[問題](https://atcoder.jp/contests/abc021/tasks/abc021_d)

$a^\prime_i = a_i + k-1$ とおくと
$1 \leq a^\prime_1 < \cdots < a^\prime_k \leq n + k - 1$ となる.
よって $[1, n-k-1]$ の範囲の数字を $k$ 個選んで昇順に並べると題意を条件を満たした数列を構築できる.
そのような選び方は $\displaystyle \comb{n+k-1}{k} = \frac{(n+k-1)!}{k! ~ (n-1)!}$ 通りある.

```cpp
ll powmod(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if(n&1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

ll invmod(ll x, ll mod) {
    return powmod(x, mod-2, mod);
}

void solve() {
    ll MAX = (ll)2e5 + 5;
    ll MOD = (ll)1e9 + 7;
    vector<ll> fac(MAX, 1), invfac(MAX, 1);
    rep2(i,2,MAX) fac[i] = fac[i-1] * i % MOD;
    rep2(i,2,MAX) invfac[i] = invmod(fac[i], MOD);

    ll n, k;
    cin >> n >> k;
    ll ans = fac[n+k-1] * (invfac[k] * invfac[n-1] % MOD) % MOD;
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/abc021/submissions/28303844)



### AtCoder Beginner Contest 149 F - Surrounded Nodes
[問題](https://atcoder.jp/contests/abc149/tasks/abc149_f)

解けていない


## 全国統一プログラミング王決定戦本戦 A - Abundant Resources
### 全国統一プログラミング王決定戦本戦 A - Abundant Resources
[問題](https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_a)
[提出コード](https://atcoder.jp/contests/nikkei2019-final/submissions/28306263)

### JOI 2010 本選 1 - 旅人
[問題](https://atcoder.jp/contests/joi2010ho/tasks/joi2010ho_a)
[提出コード](https://atcoder.jp/contests/joi2010ho/submissions/28306419)

### JOI 2011 本選 1 - 惑星探査
[問題](https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1)

$s[x][y] = s[x-1][y] + s[x][y-1] - s[x-1][y-1] + (grid[x][y] == 'X')$

といった感じで累積和を求める

[提出コード](https://atcoder.jp/contests/joi2011ho/submissions/28306857)


### AtCoder Beginner Contest 106 D - AtCoder Express 2
[問題](https://atcoder.jp/contests/abc106/tasks/abc106_d)
[提出コード](https://atcoder.jp/contests/abc106/submissions/28309629)


### GigaCode 2019 D - 家の建設

[問題](https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_d)
[提出コード](https://atcoder.jp/contests/gigacode-2019/submissions/28310222)

### AtCoder Beginner Contest 014 C - AtColor

[問題](https://atcoder.jp/contests/abc014/tasks/abc014_3)
[提出コード](https://atcoder.jp/contests/abc014/submissions/28310306)


### AOJ 2013 - 大崎

[問題](https://onlinejudge.u-aizu.ac.jp/problems/2013)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/2013/judge/6172945/C++17)


### JOI 2015 本選 1 - 鉄道運賃

[問題](https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_a)

各鉄道を何回乗るかをいもす法で調べて, きっぷまたは IC のうち安い方を使うようにする.

[提出コード](https://atcoder.jp/contests/joi2015ho/submissions/28311058)

### JOI 2012 本選 4 - 釘
[問題](https://atcoder.jp/contests/joi2012ho/tasks/joi2012ho4)

理解しきれなかったので一旦飛ばし



## Union-Find

### DSL_1_A - 互いに素な集合
[問題](https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/DSL_1_A/judge/6175933/C++17)


### AtCoder Beginner Contest 075 C - Bridge
[問題](https://atcoder.jp/contests/abc075/tasks/abc075_c)
[提出コード](https://atcoder.jp/contests/abc075/submissions/28324991)

### AtCoder Beginner Contest 120 D - Decayed Bridge
[問題](https://atcoder.jp/contests/abc120/tasks/abc120_d)

$A_i$, $B_i$ を反転させて, 橋を構築していくごとに不便さがどう減るかを考える. これを逆順にすれば問題の答えとなる.

橋が全くなかったときの不便さは $\displaystyle \comb{n}{2} = \frac{n(n-1)}{2}$ となる.
$x$ 個の島が橋によって行き来できるようになったとすると不便さは $\comb{x}{2}$ 減る.
また $x$ 個の島からなる島群と, $y$ 個の島からなる島群が橋によってつながると不便さは
$\displaystyle \comb{x}{2} + \comb{y}{2} - \comb{x+y}{2} = \frac{x(x-1)}{2} + \frac{y(y-1)}{2} - \frac{(x+y)(x+y-1)}{2} = xy$ だけ減る.

```cpp
struct UnionFind {
    vector<int> d;
    UnionFind(int n) : d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return -d[find(x)];
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    reverse(all(a));
    reverse(all(b));

    ll inconvenient = n * (n-1) / 2;
    UnionFind uf(n);
    vector<ll> ans;
    ans.reserve(m);
    ans.push_back(inconvenient);
    rep(i,m-1) {
        if (uf.same(a[i], b[i])) {
            ans.push_back(inconvenient);
        } else {
            ll asize = uf.size(a[i]);
            ll bsize = uf.size(b[i]);
            inconvenient -= asize * bsize;
            ans.push_back(inconvenient);
            uf.unite(a[i], b[i]);
        }
    }
    reverse(all(ans));
    for (ll x : ans) cout << x << endl;
}
```

```cpp
rep(i,m-1) {
    if (uf.same(a[i], b[i])) {
        ans.push_back(inconvenient);
    } else {
        ll asize = uf.size(a[i]);
        ll bsize = uf.size(b[i]);
        inconvenient -= asize * bsize;
        ans.push_back(inconvenient);
        uf.unite(a[i], b[i]);
    }
}
```
のように loop の回数が $m-1$ 回で良い理由は, 1つの目の橋が壊れるときの不便さは 2個目 ~ $m$ 個目の橋を構築したときの不便さなので $A_1$, $B_1$ 間の橋のことは考えなくてよい.

[提出コード](https://atcoder.jp/contests/abc120/submissions/28329931)


その他のテクニック
### JOI 2008 本選 1 - 碁石ならべ
[問題](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_a)
[提出コード](https://atcoder.jp/contests/joi2008ho/submissions/28329897)

### JOI 2013 本選 1 - 電飾
[問題](https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1)
[提出コード](https://atcoder.jp/contests/joi2013ho/submissions/28340054)

### Square869120Contest #5 B - Emblem
[問題](https://atcoder.jp/contests/s8pc-5/tasks/s8pc_5_b)

半径が決まっていない円の半径を全て同じペースで大きくしていって, どれかの円の接したときの半径が取りうる最大の半径となると考え, 二分探索で取れる半径の最大値を探した.
解説によるとそんな複雑なことはしなくてよかったらしい.

[提出コード](https://atcoder.jp/contests/s8pc-5/submissions/28340947)


### AtCoder Beginner Contest 144 D - Water Bottle

[問題](https://atcoder.jp/contests/abc144/tasks/abc144_d)
[提出コード](https://atcoder.jp/contests/abc144/submissions/28341673)


### AOJ 1193 - 連鎖消滅パズル
[問題](https://onlinejudge.u-aizu.ac.jp/problems/1193)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/1193/judge/6184833/C++17)


### Square869120Contest #3 B - 石落としゲーム
[問題](https://atcoder.jp/contests/s8pc-3/tasks/s8pc_3_b)
[提出コード](https://atcoder.jp/contests/s8pc-3/submissions/28353405)


### AOJ 1149 - ケーキカット
[問題](https://onlinejudge.u-aizu.ac.jp/problems/1149)
[提出コード](https://onlinejudge.u-aizu.ac.jp/status/users/goropikari/submissions/1/1149/judge/6185660/C++17)


### AtCoder Beginner Contest 149 B - Greedy Takahashi
[問題](https://atcoder.jp/contests/abc149/tasks/abc149_b)
[提出コード](https://atcoder.jp/contests/abc149/submissions/28354817)

### AtCoder Beginner Contest 139 D - ModSum
[問題](https://atcoder.jp/contests/abc139/tasks/abc139_d)
[提出コード](https://atcoder.jp/contests/abc139/submissions/28362718)

### AtCoder Beginner Contest 150 D - Semi Common Multiple
[問題](https://atcoder.jp/contests/abc150/tasks/abc150_d)
[提出コード](https://atcoder.jp/contests/abc150/submissions/28363212)

### 三井住友信託銀行プログラミングコンテスト2019 予選 E - Colorful Hats 2
[問題](https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e)

$A_i = k$ ($0 \leq k \leq N-1$) だったとき, $i$ 番目の人の帽子の選び方を $T_i$ とすると



\begin{align}
T_i = \left\{
    \begin{aligned}
        &3 - \text{(それまでに出た } 0 \text{ と言った人の数) if } k = 0 \\
        & (\text{それまでに出た } k-1 \text{ と言った人の数}) - (\text{それまでに出た } k \text{ と言った人の数})
    \end{aligned}
\right.
\end{align}

通りである.
よって答えは $\displaystyle \prod_i T_i \mod 1000000007$.

```cpp
void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i], A[i]++;

    vector<ll> cnt(n+1, 0);
    cnt[0] = 3;
    ll ans = 1;
    rep(i,n) {
        ans *= cnt[A[i]-1];
        ans %= MOD;
        cnt[A[i]]++;
        cnt[A[i]-1]--;
    }
    cout << ans << endl;
}
```

[提出コード](https://atcoder.jp/contests/sumitrust2019/submissions/28364331)



### DDCC2020 予選 D - Digit Sum Replace
[問題](https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d)
[公式解説](https://www.youtube.com/watch?v=BssyLgQvdcY)

公式解説補足

$s$ が1桁になるまでに 9 を引く回数を $x$ とすると $1 \leq s - 9x \leq 9$ が成り立つ.
よって

$\displaystyle \frac{s-9}{9} \leq x \leq \frac{s-1}{9}$ を満たす整数 $x$ は
$\displaystyle x = \left\lfloor \frac{s-1}{9} \right\rfloor$.

```cpp
void solve() {
    int m;
    cin >> m;
    vector<ll> d(m), c(m);
    rep(i,m) cin >> d[i] >> c[i];
    ll keta = 0;
    ll sum = 0;
    rep(i,m) {
        keta += c[i];
        sum += d[i] * c[i];
    }

    cout << keta - 1 + (sum - 1) / 9 << endl;
}
```

[提出コード](https://atcoder.jp/contests/ddcc2020-qual/submissions/28365947)


### Tenka1 Programmer Beginner Contest D - Crossing
[問題](https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d)
[提出コード](https://atcoder.jp/contests/tenka1-2018-beginner/submissions/28366912)
