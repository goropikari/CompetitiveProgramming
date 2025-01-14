/*https://atcoder.jp/contests/abc261/tasks/abc261_d*/
/*2025年01月11日 00時05分20秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    ll N, M;
    cin >> N >> M;
    vll X(N + 1);
    rep(i, N) cin >> X[i + 1];
    map<ll, ll> bonus;
    rep(i, M) {
        ll c, y;
        cin >> c >> y;
        bonus[c] = y;
    }

    // dp[h][i][j]
    // h: head or tail
    // i 回目
    // j 連続
    vll mx(N + 1, 0);
    vector<vector<vector<ll>>> dp(2, vvll(N + 1, vll(N + 1, 0)));
    rep2(i, 1, N + 1) {
        chmax(dp[0][i][0], dp[0][i - 1][0]);
        // rep(k, i) {
        //     chmax(dp[0][i][0], dp[1][i - 1][k]);
        // }
        chmax(dp[0][i][0], mx[i - 1]);
        rep2(j, 1, i + 1) {
            if (j == 1) {
                chmax(dp[1][i][j], dp[0][i - 1][j - 1] + bonus[j] + X[i]);
            } else {
                chmax(dp[1][i][j], dp[1][i - 1][j - 1] + bonus[j] + X[i]);
            }
            chmax(mx[i], dp[1][i][j]);
        }
    }

    ll ans = 0;
    rep(j, N + 1) {
        chmax(ans, dp[0][N][j]);
        chmax(ans, dp[1][N][j]);
    }
    cout << ans << endl;
}
