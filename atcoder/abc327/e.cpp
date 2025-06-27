// https://atcoder.jp/contests/abc327/tasks/abc327_e
// 2025年06月28日 00時19分13秒
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

    ll N;
    cin >> N;
    vll P(N + 1);
    rep(i, N) cin >> P[i + 1];

    double INF = 100000;
    vector dp(N + 1, vector<double>(N + 1, -INF));
    dp[0][0] = 0;
    rep2(i, 1, N + 1) {
        rep(num, i + 1) {
            chmax(dp[i][num], dp[i - 1][num]);

            if (dp[i - 1][num] != -INF)
                chmax(dp[i][num + 1], dp[i - 1][num] * 0.9 + P[i]);
        }
    }

    vector<double> pow(N + 1), prd(N + 1);
    pow[0] = prd[0] = 1;
    rep2(i, 1, N + 1) {
        pow[i] = pow[i - 1] * 0.9;
        prd[i] += pow[i] + prd[i - 1];
    }

    double ans = -INF;
    rep2(num, 1, N + 1) {
        chmax(ans, dp[N][num] / prd[num - 1] - 1200.0 / sqrt(num));
    }
    printf("%.9lf\n", ans);
}
