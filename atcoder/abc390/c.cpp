/*https://atcoder.jp/contests/abc390/tasks/abc390_c*/
/*2025年01月25日 21時08分11秒*/
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
    ll H, W;
    cin >> H >> W;

    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    ll minh = INF, maxh = -1, minw = INF, maxw = -1;
    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') {
                chmin(minh, i);
                chmax(maxh, i);
                chmin(minw, j);
                chmax(maxw, j);
            }
        }
    }

    int ok = 1;
    for (ll i = minh; i <= maxh; i++) {
        for (ll j = minw; j <= maxw; j++) {
            if (grid[i][j] == '.') {
                ok = 0;
                break;
            }
        }
    }
    yesno(ok);
}
