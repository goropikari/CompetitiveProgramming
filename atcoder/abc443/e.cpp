// https://atcoder.jp/contests/abc443/tasks/abc443_e
// Sat 31 Jan 2026 09:33:48 PM JST
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

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

    auto cal = []() -> void {
        ll N, C;
        cin >> N >> C;
        C--;

        vector<string> grid(N);
        rep(i, N) cin >> grid[i];

        vll blocks(N);
        rep(j, N) {
            if (grid[N - 1][j] == '#') blocks[j] = 1;
        }

        vvint dp(N, vint(N));
        dp[N - 1][C] = 1;

        vint dir = {-1, 0, 1};
        ll row = N - 1;
        rep(_, N - 1) {
            rep(j, N) {
                if (dp[row][j]) {
                    for (ll d : dir) {
                        ll nj = j + d;
                        if (clamp(nj, 0ll, N - 1) != nj) continue;
                        if (grid[row - 1][nj] == '#' && blocks[nj]) continue;
                        grid[row - 1][nj] = '.';
                        dp[row - 1][nj] = 1;
                    }
                }
            }

            row--;
            rep(j, N) {
                if (grid[row][j] == '#') blocks[j] = 1;
            }
        }

        string ans = "";
        rep(i, N) ans.push_back(dp[0][i] ? '1' : '0');
        cout << ans << '\n';
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
