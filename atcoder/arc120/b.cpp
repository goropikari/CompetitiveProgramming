// https://atcoder.jp/contests/arc120/tasks/arc120_b
// 2025年05月28日 02時01分27秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
// modint::set_mod(10);
// using mint = modint;
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vint red(H + W), blue(H + W), white(H + W);
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'R') red[i + j]++;
        if (grid[i][j] == 'B') blue[i + j]++;
        if (grid[i][j] == '.') white[i + j]++;
    }

    int ok = 1;
    rep(i, H + W) {
        if (red[i] > 0 && blue[i] > 0) {
            ok = 0;
            break;
        }

        if (red[i] > 0) white[i] = 0;
        if (blue[i] > 0) white[i] = 0;
    }

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    mint two = 2;
    int cnt = 0;
    rep(i, H + W) {
        if (white[i] > 0) cnt++;
    }
    cout << two.pow(cnt).val() << endl;
}
