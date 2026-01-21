// https://atcoder.jp/contests/abc437/tasks/abc437_f
// Thu 22 Jan 2026 12:03:14 AM JST
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

struct S {
    ll mx, mi;
};

S op(S a, S b) {
    return {max(a.mx, b.mx), min(a.mi, b.mi)};
}

S e() {
    return {-INF, INF};
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    segtree<S, op, e> xpy(N), xmy(N);
    rep(i, N) {
        xpy.set(i, {X[i] + Y[i], X[i] + Y[i]});
        xmy.set(i, {X[i] - Y[i], X[i] - Y[i]});
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll i, x, y;
            cin >> i >> x >> y;
            i--;

            ll xx = x + y, yy = x - y;
            xpy.set(i, {xx, xx});
            xmy.set(i, {yy, yy});
        } else {
            ll l, r, x, y;
            cin >> l >> r >> x >> y;
            l--;

            ll xx = x + y, yy = x - y;

            ll ans = 0;

            auto p = xpy.prod(l, r);
            auto m = xmy.prod(l, r);
            chmax(ans, p.mx - xx);
            chmax(ans, -p.mi + xx);
            chmax(ans, m.mx - yy);
            chmax(ans, -m.mi + yy);

            cout << ans << endl;
        }
    }
}
