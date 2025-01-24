/*https://atcoder.jp/contests/abc306/tasks/abc306_d*/
/*2025年01月24日 00時14分31秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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
    int N;
    cin >> N;

    vll X(N + 1), Y(N + 1);
    rep(i, N) cin >> X[i + 1] >> Y[i + 1];

    // dp[flag][i]
    vvll dp(2, vll(N + 1, -INF));
    dp[0][0] = 0;
    rep2(i, 1, N + 1) {
        chmax(dp[0][i], dp[0][i - 1]);
        chmax(dp[1][i], dp[1][i - 1]);
        if (X[i] == 0) {
            chmax(dp[0][i], dp[0][i - 1] + Y[i]);
            chmax(dp[0][i], dp[1][i - 1] + Y[i]);
        } else {
            chmax(dp[1][i], dp[0][i - 1] + Y[i]);
        }
    }

    cout << max(dp[0][N], dp[1][N]) << endl;
}
