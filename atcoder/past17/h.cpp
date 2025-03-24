// https://atcoder.jp/contests/past17-open/tasks/past17_h
/*2025年03月24日 22時11分08秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vll a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    vector<vector<pair<ll, ll>>> lec(5001);
    rep(i, n) {
        lec[b[i]].push_back({a[i], c[i]});
    }

    vvll dp(5001, vll(m + 1, INF));
    dp[0][0] = 0;
    rep2(i, 1, 5001) {
        rep(j, m + 1) {
            chmin(dp[i][j], dp[i - 1][j]);
            rep(k, lec[i].size()) {
                chmin(dp[i][j], dp[i - 1][max(0ll, j - lec[i][k].second)] + lec[i][k].first);
            }
        }
    }

    ll ans = dp[5000][m];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
