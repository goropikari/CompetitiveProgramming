// https://atcoder.jp/contests/arc158/tasks/arc158_a
// 2025年07月24日 00時19分46秒
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto f = [](auto f, vll& v) -> ll {
        sort(all(v));

        if ((v[1] - v[0]) % 2 != 0 || (v[2] - v[1]) % 2 != 0) return -1;
        if (v[0] == v[1] && v[1] == v[2]) return 0;
        if (v[0] != v[1] && v[1] == v[2]) {
            if ((v[1] - v[0]) % 6 != 0) return -1;
            return (v[1] - v[0]) / 6 * 2;
        }
        if (v[0] == v[1] && v[1] != v[2]) {
            if ((v[2] - v[1]) % 6 != 0) return -1;
            return (v[2] - v[1]) / 6 * 2;
        }

        ll l = v[1] - v[0], r = v[2] - v[1];
        ll mi = min(l, r);
        ll p = mi / 2;
        v[0] += 7 * p;
        v[1] += 5 * p;
        v[2] += 3 * p;

        ll nx = f(f, v);
        if (nx < 0) return -1;

        return p + nx;
    };

    auto cal = [&]() -> void {
        vll x(3);
        rep(i, 3) cin >> x[i];

        cout << f(f, x) << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
