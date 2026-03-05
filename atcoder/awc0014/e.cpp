// https://atcoder.jp/contests/awc0014/tasks/awc0014_e
// Thu 26 Feb 2026 08:35:47 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
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

    using S = pair<ll, ll>;
    auto op = [](S a, S b) -> S {
        return {a.first + b.first, a.second + b.second};
    };
    auto e = []() -> S {
        return {0, 1};
    };

    using F = ll;
    auto mapping = [](F f, S x) -> S {
        return {f * x.second + x.first, x.second};
    };

    auto composition = [](F f, F g) -> F {
        return f + g;
    };

    auto id = []() -> F {
        return 0;
    };

    ll N, Q;
    cin >> N >> Q;
    vll C(N);
    rep(i, N) cin >> C[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);

    rep(i, N) {
        seg.set(i, {C[i], 1});
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            l--;
            seg.apply(l, r, v);
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            auto ret = seg.prod(l, r);
            cout << ret.first << endl;
        }
    }
}
