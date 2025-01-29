/*https://atcoder.jp/contests/dp/tasks/dp_m*/
/*2025年01月26日 12時19分45秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll N, K;
    cin >> N >> K;

    vll A(N + 1, 0);
    rep(i, N) cin >> A[i + 1];

    ll MOD = (ll)1e9 + 7;

    // dp[i][j]: i 番目の子供までで j 個の飴を配る配り方
    vvll dp(N + 1, vll(K + 1, 0));
    dp[0][0] = 1;
    rep2(i, 1, N + 1) {
        // cumsum[i][k]: sum from dp[i][0] to dp[i][k-1]
        vll cumsum(K + 2, 0);
        rep2(k, 1, K + 2) {
            cumsum[k] = cumsum[k - 1] + dp[i - 1][k - 1];
            cumsum[k] %= MOD;
        }

        rep(j, K + 1) {
            dp[i][j] = MOD + cumsum[j + 1] - cumsum[max(0LL, j - A[i])];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[N][K] << endl;
}
