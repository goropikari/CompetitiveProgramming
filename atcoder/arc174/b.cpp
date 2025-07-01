// https://atcoder.jp/contests/arc174/tasks/arc174_b
// 2025年07月01日 03時02分31秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto ceil = [](ll x, ll y) -> ll {
        return (x + y - 1) / y;
    };

    auto cal = [&]() -> void {
        int n = 5;
        vll A(n + 1), P(n + 1);
        rep(i, n) cin >> A[i + 1];
        rep(i, n) cin >> P[i + 1];

        ll a = 0, b = 0;
        rep(i, n) a += (i + 1) * A[i + 1];
        rep(i, n) b += A[i + 1];

        ll ans = INF;
        ll x = max(3 * b - a, 0ll);
        chmin(ans, x * P[4]);

        ll y = max(ceil(3 * b - a, 2), 0ll);
        chmin(ans, y * P[5]);

        ll z = max(ceil(3 * b - a - 1, 2), 0ll);
        chmin(ans, P[4] + z * P[5]);

        cout << ans << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
