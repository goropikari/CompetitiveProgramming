// http://localhost:5173/problem/point_set_range_composite
// 2025年04月23日 03時21分14秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/segtree.hpp>
using namespace atcoder;
using mint = modint998244353;
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
const int INF = (int)2e9 + 7;

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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // f(x) = ax + b
    // g(x) = cx + d
    // g(f(x)) = g(ax + b) = c(ax + b) + d = acx + (bc + d)

    using P = pair<mint, mint>;
    auto op = [](P a, P b) -> P {
        return {a.first * b.first, a.second * b.first + b.second};
    };
    auto e = []() -> P {
        return {1, 0};
    };

    segtree<P, op, e> seg(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        seg.set(i, {a, b});
    }

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.set(p, {c, d});
        } else {
            int l, r, x;
            cin >> l >> r >> x;

            P f = seg.prod(l, r);
            cout << (f.first * x + f.second).val() << endl;
        }
    }
}
