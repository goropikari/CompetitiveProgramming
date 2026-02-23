// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_be
// Tue 24 Feb 2026 12:58:09 AM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

    ll N, K;
    cin >> N >> K;
    vll V(K);
    rep(i, K) cin >> V[i];

    // vvint stock;
    //
    // auto dfs = [&](auto dfs, vint v, int left, int num) -> void {
    //     if (num == 0) {
    //         stock.pb(v);
    //         return;
    //     }
    //     if (left >= K) return;
    //
    //     rep2(i, left, K) {
    //         v.pb(V[i]);
    //         dfs(dfs, v, i + 1, num - 1);
    //         v.pop_back();
    //     }
    // };
    //
    // rep2(num, 1, K + 1) dfs(dfs, vint(), 0, num);
    //
    // ll ans = 0;
    //
    // for (auto& v : stock) {
    //     ll x = 1;
    //     for (ll a : v) x = lcm(x, a);
    //     ll sign = 1;
    //     if (v.size() % 2 == 0) sign = -1;
    //     ans += sign * N / x;
    // }
    // cout << ans << endl;

    ll ans = 0;
    rep2(state, 1, 1 << K) {
        int k = __builtin_popcountll(state);
        int sign = 1;
        if (k % 2 == 0) sign = -1;
        ll x = 1;
        rep(j, K) {
            if (state >> j & 1) x = lcm(x, V[j]);
        }
        ans += sign * N / x;
    }
    cout << ans << endl;
}
