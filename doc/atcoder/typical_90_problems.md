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

