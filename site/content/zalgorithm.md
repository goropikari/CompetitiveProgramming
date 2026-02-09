+++
date = '2026-02-09T01:06:36+09:00'
title = 'Z Algorithm 問題集'
tags = ['z-algorithm']
+++


## library

```cpp
template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}
```

## yosupo judge: Z Algorithm

<https://judge.yosupo.jp/problem/zalgorithm>

## AOJ: ALDS1_14_B

<https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B>

$S = P + T$ とする。

Z Algorithm を用いて文字列 $S$ の最大共通接頭辞の長さを求める。
$Z_i$ を $S[i:]$ と $S$ の最大共通接頭辞の長さとする。

$Z_i \geq |P| \wedge i \geq |P|$ となる $i$ を全て求めればよい。

```cpp
template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P;
    cin >> T >> P;

    string s = P + "$" + T;
    vint z = z_algorithm(s);

    vint ans;
    rep(i, (ll)T.size() - (ll)P.size() + 1) {
        if (z[P.size() + i + 1] == (ll)P.size()) ans.push_back(i);
    }
    for (ll x : ans) cout << x << '\n';
}
```

## ABC 141 E - Who Says a Pun?

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    rep(i, N) {
        vint z = z_algorithm(S.substr(i));
        int n = z.size();
        rep(j, n) {
            chmax(ans, min(j, (ll)z[j]));
        }
    }
    cout << ans << endl;
}
```

## ABC430: E - Shift String

AOJ: ALDS1_14_B の類題。

$S[i:]$ に対して Z Algorithm を適用し、求める解を探す。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        string A, B;
        cin >> A >> B;

        string S = B + A + A;

        vint z = z_algorithm(S);

        int n = A.size();
        rep(i, n) {
            if (z[n + i] >= n) {
                cout << i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
```

## ABC284: F - ABCBAC

<https://atcoder.jp/contests/abc284/tasks/abc284_f>

[解説]({{< ref "abc/284.md#f-abcbac" >}})

## ABC257: G - Prefix Concatenation

<https://atcoder.jp/contests/abc257/tasks/abc257_g>

[解説]({{< ref "abc/257.md#g-prefix-concatenation" >}})

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int n = T.size();
    vint Z;
    {
        vint tmp = z_algorithm(S + T);
        rep(i, n) Z.push_back(min(tmp[S.size() + i], (int)S.size()));
    }

    // min, sum
    using P = pair<ll, ll>;

    auto op = [](P a, P b) -> P {
        return {max(a.first, b.first), min(a.second, b.second)};
    };

    auto e = []() -> P {
        return {0, INF};
    };

    segtree<P, op, e> seg(n + 1);
    seg.set(n, {1, 0});

    for (int i = n - 1; i >= 0; i--) {
        if (!Z[i]) continue;
        P p = seg.prod(i + 1, min(i + Z[i] + 1, n + 1));
        seg.set(i, {p.first, p.second + 1});
    }

    P x = seg.get(0);
    ll ans = -1;
    if (x.first) ans = x.second;
    cout << ans << endl;
}
```
