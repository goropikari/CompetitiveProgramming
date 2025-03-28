/*https://atcoder.jp/contests/dp/tasks/dp_e*/
/*2025年01月19日 03時56分08秒*/
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

// const ll INF = (ll)2e18 + 9;
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
    vll w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    // dp[i]: 価値 i を達成できる重さの最小値
    ll vmax = (ll)1e5;
    vll dp(vmax + 1, INF);
    dp[0] = 0;
    rep(i, N) {
        for (ll x = vmax; x >= 0; x--) {
            if (x - v[i] >= 0) {
                chmin(dp[x], dp[x - v[i]] + w[i]);
            }
        }
    }

    ll ans = 0;
    rep(i, vmax + 1) {
        if (dp[i] <= W)
            chmax(ans, i);
    }
    cout << ans << endl;
}
