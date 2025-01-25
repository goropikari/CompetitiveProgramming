/*https://atcoder.jp/contests/abc369/tasks/abc369_d*/
/*2025年01月25日 17時02分44秒*/
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
    ll N;
    cin >> N;
    vll A(N + 1);
    rep(i, N) cin >> A[i + 1];

    // dp[i][defeat][parity]:
    // i 番目のモンスターを defeat して parity になったときの経験値の最大値
    vector<vvll> dp(N + 1, vvll(2, vll(2, -INF)));
    dp[0][0][0] = 0;

    rep2(i, 1, N + 1) {
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);

        dp[i][1][0] = max(dp[i - 1][0][1], dp[i - 1][1][1]) + A[i] * 2;
        dp[i][1][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + A[i];
    }

    ll ans = 0;
    rep(i, 2) rep(j, 2) chmax(ans, dp[N][i][j]);
    cout << ans << endl;
}
