// https://atcoder.jp/contests/practice2/tasks/practice2_k
// Sat 03 Jan 2026 12:26:41 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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

    int N, Q;
    cin >> N >> Q;

    using S = pair<mint, ll>;
    auto op = [](S a, S b) -> S {
        return {a.first + b.first, a.second + b.second};
    };

    auto e = []() -> S {
        return {0, 1};
    };

    using F = pair<mint, mint>;

    auto mapping = [](F f, S x) -> S {
        return {f.first * x.first + f.second * x.second, x.second};
    };

    auto composition = [](F f, F g) -> F {
        return {f.first * g.first, f.first * g.second + f.second};
    };

    auto id = []() -> F {
        return {1, 0};
    };

    vector<S> A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        A[i] = {a, 1};
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        }
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).first.val() << endl;
        }
    }
}
