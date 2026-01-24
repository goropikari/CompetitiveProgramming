// https://atcoder.jp/contests/abc442/tasks/abc442_f
// Sat 24 Jan 2026 10:22:22 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

    ll N;
    cin >> N;
    vector<string> grid(N);
    rep(i, N) {
        cin >> grid[i];
        grid[i] = "." + grid[i];
    }

    ll H = N, W = N + 1;

    vll dp(W);
    rep(i, H) {
        vll dpn(W, INF);

        vll cmb(W + 1), cmw(W + 1);
        rep(j, W) {
            cmb[j + 1] = cmb[j] + (grid[i][j] == '#');
            cmw[j + 1] = cmw[j] + (grid[i][j] == '.');
        }

        vll mi = dp;
        for (int j = W - 2; j >= 0; j--) {
            chmin(mi[j], mi[j + 1]);
        }

        for (int j = W - 1; j >= 0; j--) {
            ll nw = cmw[W] - cmw[j + 1];
            ll nb = cmb[j + 1];
            chmin(dpn[j], mi[j] + nb + nw);
        }

        swap(dp, dpn);
    }

    ll ans = *min_element(all(dp));
    cout << ans << endl;
}
