// https://atcoder.jp/contests/dp/tasks/dp_s
// 2025年09月14日 18時01分35秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

    string K;
    ll D;
    cin >> K >> D;

    ll N = K.size();

    // dp[is_less][mod]
    vector dp(2, vector<mint>(D));
    dp[0][0] = 1;

    rep(i, N) {
        vector dpn(2, vector<mint>(D));
        int t = K[i] - '0';

        rep(d, 10) rep(is_less, 2) rep(m, D) {
            if (!is_less && d > t) continue;
            int is_less_n = is_less || d < t;
            int r = (d + m) % D;
            dpn[is_less_n][r] += dp[is_less][m];
        }

        swap(dp, dpn);
    }

    cout << (dp[0][0] + dp[1][0] - 1).val() << endl;
}
