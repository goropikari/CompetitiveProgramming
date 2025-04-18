#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<mint>> dp(N + 1, vector<mint>(M + 1, 0));
    rep(i, M) dp[1][i + 1] = 1;
    rep2(i, 2, N + 1) {
        rep2(j, 1, M + 1) {
            rep2(k, 1, M + 1) {
                if (abs(k - j) >= K)
                    dp[i][k] += dp[i - 1][j];
            }
        }
    }

    mint ans = 0;
    rep2(i, 1, M + 1) ans += dp[N][i];
    cout << ans.val() << endl;
}
