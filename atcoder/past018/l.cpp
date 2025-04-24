// https://atcoder.jp/contests/past18-open/tasks/past18_l
// 2025年04月23日 21時00分02秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}

template <typename T>
void print(vector<T> v) {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << ' ' << v[i];
    }
    cout << endl;
}

void yesno(bool x) {
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) {
    return std::max(a, b);
}
S e() {
    return -INF;
}
S mapping(F f, S x) {
    return (f == ID ? x : f);
}
F composition(F f, F g) {
    return (f == ID ? g : f);
}
F id() {
    return ID;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<pair<string, ll>> sp(N);
    rep(i, N) {
        string s;
        ll p;
        cin >> s >> p;
        sp[i] = {s, p};
    }

    vector<pair<ll, int>> qsort;
    rep(i, Q) {
        ll t;
        cin >> t;
        qsort.push_back({t, i});
    }
    sort(all(qsort));

    vll q(Q);
    rep(i, Q) {
        q[i] = qsort[i].first;
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(q);

    int neg = 0;
    for (auto [s, p] : sp) {
        if (s == "NEGATE") {
            neg = 1 - neg;
            continue;
        }
        if (neg)
            p *= -1;
        int t = seg.max_right(0, [&](S x) -> ll {
            return x <= p;
        });
        if (s == "CHMIN" && neg || s == "CHMAX" && !neg) {
            seg.apply(0, t, p);
        } else {
            seg.apply(t, Q, p);
        }
    }

    vll ans(Q);
    rep(i, Q) {
        ll x = seg.get(i);
        ll sign = 1;
        if (neg)
            sign = -1;
        ans[qsort[i].second] = x * sign;
    }
    for (ll x : ans)
        cout << x << '\n';
}
