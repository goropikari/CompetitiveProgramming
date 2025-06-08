// https://atcoder.jp/contests/dp/tasks/dp_s
// 2025年06月07日 19時44分37秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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
using namespace std;
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

    string K;
    ll D;
    cin >> K >> D;

    int N = K.size();

    // dp[i][j][k]: 左から i 桁までは見て K 未満であることが確定して(j=0 いなくて, j=1 いて) 桁の総和の mod D が k となる場合の数
    vector dp(N + 1, vector(2, vector<mint>(D)));
    dp[0][0][0] = 1;

    rep2(i, 1, N + 1) {
        int t = K[i - 1] - '0';

        rep(d, 10) {
            rep(k, D) {
                if (d < t) {
                    dp[i][1][(d + k) % D] += dp[i - 1][0][k];
                }
                if (d == t) {
                    dp[i][0][(d + k) % D] += dp[i - 1][0][k];
                }
                dp[i][1][(d + k) % D] += dp[i - 1][1][k];
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][1][0] - 1).val() << endl;
}
