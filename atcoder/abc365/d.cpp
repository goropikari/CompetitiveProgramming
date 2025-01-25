/*https://atcoder.jp/contests/abc365/tasks/abc365_d*/
/*2025年01月25日 12時56分23秒*/
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

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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
    string S;
    cin >> S;
    S = "_" + S;

    // takahashi kun が dp[hand][i]: i 番目に hand
    // の手を出したときに勝つ回数の最大値 hand:
    // - 0 R
    // - 1 P
    // - 2 S
    vvll dp(3, vll(N + 1, 0));

    rep2(i, 1, N + 1) {
        if (S[i] == 'R') {
            // 1個前と違う手を出して勝つ
            chmax(dp[1][i], max(dp[0][i - 1], dp[2][i - 1]) + 1);

            // 1個前と違う手を出してあいこ
            chmax(dp[0][i], max(dp[1][i - 1], dp[2][i - 1]));
        } else if (S[i] == 'P') {
            chmax(dp[2][i], max(dp[0][i - 1], dp[1][i - 1]) + 1);
            chmax(dp[1][i], max(dp[0][i - 1], dp[2][i - 1]));
        } else {  // S
            chmax(dp[0][i], max(dp[1][i - 1], dp[2][i - 1]) + 1);
            chmax(dp[2][i], max(dp[0][i - 1], dp[1][i - 1]));
        }
    }

    ll ans = 0;
    rep(i, 3) chmax(ans, dp[i][N]);
    cout << ans << endl;
}
