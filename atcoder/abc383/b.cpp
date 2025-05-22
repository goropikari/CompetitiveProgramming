// https://atcoder.jp/contests/abc383/tasks/abc383_b
// 2025年05月22日 19時52分50秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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

    int H, W, D;
    cin >> H >> W >> D;

    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    auto manhattan = [](int x, int y, int i, int j) -> int {
        return abs(x - i) + abs(y - j);
    };

    int ans = 0;
    rep(i, H) rep(j, W) rep(ii, H) rep(jj, W) {
        if (i == ii && j == jj)
            continue;
        if (grid[i][j] != '.' || grid[ii][jj] != '.')
            continue;

        int cnt = 0;
        rep(x, H) rep(y, W) {
            if (grid[x][y] != '.')
                continue;
            if (manhattan(x, y, i, j) <= D || manhattan(x, y, ii, jj) <= D)
                cnt++;
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
}
