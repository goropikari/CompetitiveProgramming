// https://atcoder.jp/contests/abc418/tasks/abc418_e
// 2025年08月09日 21時52分36秒
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

    ll N;
    cin >> N;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    using P = pair<ll, ll>;
    map<P, vll> mp;
    rep(i, N) rep2(j, i + 1, N) {
        ll xi = X[i], yi = Y[i];
        ll xj = X[j], yj = Y[j];

        ll dy = yj - yi;
        ll dx = xj - xi;
        if (dx == 0) dy = abs(dy);
        if (dy == 0) dx = abs(dx);
        ll g = gcd(dx, dy);
        ll length = dx * dx + dy * dy;
        dy /= g;
        dx /= g;

        if (dx == 0) dy = abs(dy);
        if (dy == 0) dx = abs(dx);

        if (dx < 0) {
            dx *= -1;
            dy *= -1;
        }

        mp[{dx, dy}].push_back(length);
    }

    ll ans = 0;
    ll sq = 0;
    for (auto [p, v] : mp) {
        int sz = v.size();
        ans += sz * (sz - 1) / 2;
        map<ll, ll> freq;

        rep(i, sz) {
            freq[v[i]]++;
        }
        for (auto [_, tt] : freq) {
            sq += tt * (tt - 1) / 2;
        }
    }

    ans -= sq / 2;
    cout << ans << endl;
}
