// https://atcoder.jp/contests/abc315/tasks/abc315_d
// Wed 11 Feb 2026 12:19:01 AM JST
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

    ll H, W;
    cin >> H >> W;
    vvint grid(H, vint(W));
    rep(i, H) rep(j, W) {
        char c;
        cin >> c;
        grid[i][j] = c - 'a';
    }

    vvint rows(H, vint(26)), cols(W, vint(26));
    rep(i, H) rep(j, W) {
        rows[i][grid[i][j]]++;
        cols[j][grid[i][j]]++;
    }

    using T = tuple<ll, ll, ll>;

    vint delr(H), delc(W);
    int nr = H, nc = W;
    while (true) {
        vector<T> v;

        rep(i, H) rep(c, 26) {
            if (rows[i][c] == nc && rows[i][c] > 1) v.push_back({0, i, c});
        }
        rep(j, W) rep(c, 26) {
            if (cols[j][c] == nr && cols[j][c] > 1) v.push_back({1, j, c});
        }

        for (auto [t, i, c] : v) {
            if (t == 0) {
                delr[i] = 1;
                rows[i][c] = 0;
                rep(j, W) {
                    if (delc[j]) continue;
                    cols[j][c]--;
                }
                nr--;
            } else {
                delc[i] = 1;
                cols[i][c] = 0;
                rep(r, H) {
                    if (delr[r]) continue;
                    rows[r][c]--;
                }
                nc--;
            }
        }

        if (v.size() == 0) break;
    }

    cout << nr * nc << endl;
}
