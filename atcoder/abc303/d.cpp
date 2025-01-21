/*https://atcoder.jp/contests/abc303/tasks/abc303_d*/
/*2025年01月22日 01時10分03秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;

    S = "0" + S;

    // dp[flag][i]: flag の状態のときに i 文字目を入力するのにかかる時間の最小値
    vvll dp(2, vll(S.size(), INF));
    dp[0][0] = 0;
    rep2(i, 1, S.size()) {
        if (S[i] == 'a') {
            dp[0][i] = min(dp[0][i - 1] + X, dp[1][i - 1] + Z + X);
            dp[1][i] = min(dp[1][i - 1] + Y, dp[0][i - 1] + Z + Y);
        } else {
            dp[0][i] = min(dp[0][i - 1] + Y, dp[1][i - 1] + Z + Y);
            dp[1][i] = min(dp[1][i - 1] + X, dp[0][i - 1] + Z + X);
        }
    }

    int N = S.size() - 1;
    cout << min(dp[0][N], dp[1][N]) << endl;
}
