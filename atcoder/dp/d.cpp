/*https://atcoder.jp/contests/dp/tasks/dp_d*/
/*2025年01月19日 03時47分48秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rrep(i, n) for (long long int i = (n); i >= 0; --i)
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
    ll N, W;
    cin >> N >> W;
    vll w(N + 1), v(N + 1);
    rep2(i, 1, N + 1) cin >> w[i] >> v[i];

    vll dp(W + 1, -1);
    dp[0] = 0;

    rep2(i, 1, N + 1) {
        rrep(j, W) {
            int nw = j - w[i];

            if (nw >= 0 && dp[nw] >= 0) {
                chmax(dp[j], dp[nw] + v[i]);
            }
        }
    }

    ll ans = *max_element(all(dp));
    cout << ans << endl;
}
