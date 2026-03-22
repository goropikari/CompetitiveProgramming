// https://atcoder.jp/contests/abc450/tasks/abc450_c
// Sat 21 Mar 2026 09:03:50 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
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

    dsu uf(H * W + 1);
    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    int ban = H * W;

    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') continue;
            ll now = i * W + j;
            if (i == 0 || j == 0 || i == H - 1 || j == W - 1) uf.merge(now, ban);

            rep(d, 4) {
                ll ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
                if (grid[ni][nj] == '.') uf.merge(now, ni * W + nj);
            }
        }
    }

    set<int> ans;
    rep(i, H) {
        rep(j, W) {
            ll now = i * W + j;
            if (grid[i][j] == '.' && !uf.same(now, ban)) ans.insert(uf.leader(now));
        }
    }
    cout << ans.size() << endl;
}
