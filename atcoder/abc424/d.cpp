// https://atcoder.jp/contests/abc424/tasks/abc424_d
// 2025年09月20日 21時09分11秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M = 7;

    auto judge = [&](int a, int b) -> bool {
        int t = a & b;
        rep(i, M - 1) {
            if (t >> i & 1 && t >> (i + 1) & 1) return false;
        }
        return true;
    };

    auto cal = [&]() -> void {
        ll H, W;
        cin >> H >> W;
        vector<string> tmpgrid(H);
        rep(i, H) cin >> tmpgrid[i];

        vint grid(M + 1);
        rep(i, H) rep(j, W) {
            if (tmpgrid[i][j] == '#') {
                grid[i + 1] ^= 1 << j;
            }
        }

        vvll dp(M + 1, vll(1 << M, INF));
        dp[0][0] = 0;
        rep2(i, 1, M + 1) rep(pr, 1 << M) rep(nx, 1 << M) {
            if (!judge(pr, nx)) continue;
            ll cnt = 0;
            int row = grid[i];
            int ok = 1;
            rep(j, M) {
                int l = (row >> j & 1);
                int r = (nx >> j & 1);
                if (l == 0 && r == 1) {
                    ok = 0;
                    break;
                }
                if (l == 1 && r == 0) cnt++;
            }
            if (!ok) cnt = INF;
            chmin(dp[i][nx], dp[i - 1][pr] + cnt);
        }

        ll ans = INF;
        rep(st, 1 << M) chmin(ans, dp[M][st]);
        cout << ans << '\n';
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
