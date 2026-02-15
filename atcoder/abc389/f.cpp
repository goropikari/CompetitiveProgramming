// https://atcoder.jp/contests/abc389/tasks/abc389_f
// Sun 15 Feb 2026 04:16:46 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    using S = ll;
    auto op = [](S a, S b) -> S {
        return max(a, b);
    };

    auto e = []() -> S {
        return -1;
    };

    using F = ll;
    auto mapping = [](F f, S x) -> S {
        return x + f;
    };

    auto composition = [](F f, F g) -> F {
        return f + g;
    };

    auto id = []() -> F {
        return 0;
    };

    ll M = (ll)5e5;
    vll v(M);
    iota(all(v), 1ll);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    ll N;
    cin >> N;
    rep(i, N) {
        ll L, R;
        cin >> L >> R;

        auto left = [&](S x) -> bool {
            return x < L;
        };
        auto right = [&](S x) -> bool {
            return x <= R;
        };

        ll l = seg.max_right(0, left);
        ll r = seg.max_right(0, right);
        seg.apply(l, r, 1);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll x;
        cin >> x;
        x--;
        cout << seg.get(x) << endl;
    }
}
