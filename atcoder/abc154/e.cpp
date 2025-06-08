// https://atcoder.jp/contests/abc154/tasks/abc154_e
// 2025年06月09日 05時07分19秒
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    ll K;
    cin >> N >> K;

    int M = N.size();
    vector dp(M + 1, vector(2, vll(K + 2)));
    dp[0][0][0] = 1;
    rep2(i, 1, M + 1) {
        int t = N[i - 1] - '0';
        rep(d, 10) {
            int is_not_zero = d != 0;
            rep(c, 4) {
                int nxc = min(c + is_not_zero, K + 1);
                if (d < t) {
                    dp[i][1][nxc] += dp[i - 1][0][c];
                }
                if (d == t) {
                    dp[i][0][nxc] += dp[i - 1][0][c];
                }
                dp[i][1][nxc] += dp[i - 1][1][c];
            }
        }
    }

    ll ans = dp[M][1][K] + dp[M][0][K];
    cout << ans << endl;
}
