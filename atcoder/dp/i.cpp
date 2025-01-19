/*https://atcoder.jp/contests/dp/tasks/dp_i*/
/*2025年01月19日 14時42分39秒*/
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
    ll N;
    cin >> N;
    vector<double> p(N + 1);
    rep2(i, 1, N + 1) cin >> p[i];

    // dp[i][j]: i枚目まで投げたときに表が j 枚出る確率
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
    dp[0][0] = 1;

    rep2(i, 1, N + 1) {
        rep2(j, 0, i + 1) {
            if (j - 1 >= 0) {
                dp[i][j] += p[i] * dp[i - 1][j - 1];
            }
            dp[i][j] += (1 - p[i]) * dp[i - 1][j];
        }
    }

    double ans = 0.0;
    rep2(i, (N + 1) / 2, N + 1) ans += dp[N][i];
    printf("%.10lf\n", ans);
}
