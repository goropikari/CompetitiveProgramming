+++
date = '2026-01-22T00:24:44+09:00'
title = 'Abl'
+++

<https://atcoder.jp/contests/abcabl>

## A. Repeat ACL

<https://atcoder.jp/contests/abl/tasks/abl_a>

## B. Integer Preference

<https://atcoder.jp/contests/abl/tasks/abl_b>

## C. Connect Cities

<https://atcoder.jp/contests/abl/tasks/abl_c>

## D. Flat Subsequence

<https://atcoder.jp/contests/abl/tasks/abl_d>

2026/1/21 segment tree で解けると知った状態で自力 AC

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }

    auto op = [](ll a, ll b) -> ll {
        return max(a, b);
    };

    auto e = []() -> ll {
        return 0;
    };

    ll m = (ll)6e5 + 5;
    segtree<ll, op, e> seg(m);

    for (ll a : A) {
        ll l = max(0ll, a - K);
        ll r = a + K + 1;
        seg.set(a, seg.prod(l, r) + 1);
    }

    cout << seg.all_prod() << endl;
}
```

## E. Replace Digits

<https://atcoder.jp/contests/abl/tasks/abl_e>

## F. Heights and Pairs

<https://atcoder.jp/contests/abl/tasks/abl_f>
