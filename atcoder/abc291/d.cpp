/*https://atcoder.jp/contests/abc291/tasks/abc291_d*/
/*2025年01月21日 23時48分07秒*/
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
    ll N;
    cin >> N;

    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<mint>> dp(2, vector<mint>(N, 0));
    dp[0][0] = dp[1][0] = 1;

    rep2(i, 1, N) {
        if (A[i] != A[i - 1]) {
            dp[0][i] += dp[0][i - 1];
        }
        if (A[i] != B[i - 1]) {
            dp[0][i] += dp[1][i - 1];
        }
        if (B[i] != B[i - 1]) {
            dp[1][i] += dp[1][i - 1];
        }
        if (B[i] != A[i - 1]) {
            dp[1][i] += dp[0][i - 1];
        }
    }

    mint ans = dp[0].back() + dp[1].back();
    cout << ans.val() << endl;
}
