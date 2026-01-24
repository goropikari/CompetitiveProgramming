// https://atcoder.jp/contests/abc442/tasks/abc442_e
// Sat 24 Jan 2026 09:11:53 PM JST
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

    ll N, Q;
    cin >> N >> Q;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    auto area_id = [](ll x, ll y) -> ll {
        if (x >= 0 && y >= 0) return 0;
        if (x >= 0 && y < 0) return 1;
        if (x < 0 && y <= 0) return 2;
        // x < 0 && y > 0
        return 3;
    };

    // x, y
    using P = tuple<ll, ll>;
    vector<P> monsters;
    rep(i, N) monsters.emplace_back(X[i], Y[i]);

    auto less = [&](const P& a, const P& b) -> bool {
        auto [xi, yi] = a;
        auto [xj, yj] = b;

        ll ida = area_id(xi, yi), idb = area_id(xj, yj);
        if (ida != idb) return ida < idb;

        return yi * xj > xi * yj;
    };
    sort(all(monsters), less);

    while (Q--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        ll xi = X[a], yi = Y[a];
        ll xj = X[b], yj = Y[b];

        P pi = {xi, yi};
        P pj = {xj, yj};
        auto lid = lower_bound(all(monsters), pi, less) - monsters.begin();
        auto rid = upper_bound(all(monsters), pj, less) - monsters.begin();

        ll ans = 0;
        if (lid < rid) {
            ans = rid - lid;
        } else {
            ll tl = N - lid;
            ll rl = rid;
            ans = tl + rl;
        }

        cout << ans << endl;
    }
}
