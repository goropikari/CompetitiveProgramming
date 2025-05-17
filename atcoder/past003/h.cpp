// https://atcoder.jp/contests/past202005-open/tasks/past202005_h
// 2025年05月17日 17時06分18秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, L;
    cin >> N >> L;
    vll X(N);
    rep(i, N) cin >> X[i];
    ll T1, T2, T3;
    cin >> T1 >> T2 >> T3;

    vll hurdles(L + 1);
    for (ll x : X)
        hurdles[x] = 1;

    vll dp(L + 1, INF);
    dp[0] = 0;
    rep2(i, 1, L + 1) {
        ll offset = hurdles[i] * T3;
        chmin(dp[i], dp[i - 1] + T1 + offset);
        if (i - 2 >= 0) {
            chmin(dp[i], dp[i - 2] + T1 + T2 + offset);
        }
        if (i - 4 >= 0) {
            chmin(dp[i], dp[i - 4] + T1 + T2 * 3 + offset);
        }

        // ジャンプして超える
        if (i == L) {
            if (i - 3 >= 0) {
                chmin(dp[i], dp[i - 3] + T1 / 2 + T2 / 2 * 5);
            }
            if (i - 2 >= 0) {
                chmin(dp[i], dp[i - 2] + T1 / 2 + T2 / 2 * 3);
            }
            if (i - 1 >= 0) {
                chmin(dp[i], dp[i - 1] + T1 / 2 + T2 / 2);
            }
        }
    }
    cout << dp[L] << endl;
}
