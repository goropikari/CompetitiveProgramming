// https://atcoder.jp/contests/abc311/tasks/abc311_f
// Fri 06 Mar 2026 06:51:31 AM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    rep(i, H - 1) rep(j, W) {
        if (grid[i][j] == '#') {
            grid[i + 1][j] = grid[i][j];
            if (j + 1 < W) grid[i + 1][j + 1] = grid[i][j];
        }
    }
    reverse(all(grid));

    vvint ng(H + W + 1, vint(W + 1));
    rep(j, W) {
        rep(i, H) {
            if (grid[i][j] == '#') {
                ng[i + j][j + 1] = 1;
            }
        }
    }
    rep(i, H + W + 1) rep(j, W + 1) {
        if (i > H + j) ng[i][j] = 1;
        if (i < j - 1) ng[i][j] = 1;
    }

    vector dp(H + W + 1, vector<mint>(W + 1));
    dp[0][0] = 1;
    rep(j, W + 1) {
        rep(i, j + H + 1) {
            if (ng[i][j]) continue;
            if (i + 1 < H + W && !ng[i + 1][j]) {
                dp[i + 1][j] += dp[i][j];
            }
            if (j + 1 <= W && !ng[i][j + 1]) {
                dp[i][j + 1] += dp[i][j];
            };
        }
    }

    cout << dp[H + W - 1][W].val() << endl;
}
