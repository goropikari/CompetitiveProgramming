// https://atcoder.jp/contests/tdpc/tasks/tdpc_tournament
// Fri 02 Jan 2026 12:19:13 AM JST
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

    ll K;
    cin >> K;
    vll R(1 << K);
    rep(i, 1ll << K) cin >> R[i];

    vector<vector<double>> dp(K + 1, vector<double>(1 << K));
    rep(i, 1 << K) dp[0][i] = 1;

    auto prob = [](ll rp, ll rq) -> double {
        double den = 1.0 + pow(10, (double)(rq - rp) / 400.0);
        return 1.0 / den;
    };

    auto dfs = [&](auto dfs, int l, int r, int k) -> void {
        if (k == 0) return;

        int m = (l + r) / 2;
        dfs(dfs, l, m, k - 1);
        dfs(dfs, m, r, k - 1);

        rep2(i, l, m) {
            rep2(j, m, r) {
                double p = prob(R[i], R[j]);
                dp[k][i] += dp[k - 1][j] * p;
            }
            dp[k][i] *= dp[k - 1][i];
        }
        rep2(i, m, r) {
            rep2(j, l, m) {
                dp[k][i] += dp[k - 1][j] * prob(R[i], R[j]);
            }
            dp[k][i] *= dp[k - 1][i];
        }
    };

    dfs(dfs, 0, 1 << K, K);

    for (auto x : dp[K]) {
        printf("%.9lf\n", x);
    }
}
