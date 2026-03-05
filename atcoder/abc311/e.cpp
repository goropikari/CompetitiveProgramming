// https://atcoder.jp/contests/abc311/tasks/abc311_e
// Thu 05 Mar 2026 10:48:23 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

template <typename T>
struct Cumsum2d {
    vector<vector<T>> data;

    Cumsum2d(vector<vector<T>> v) {
        assert(v.size() != 0);
        assert(v[0].size() != 0);
        int h = v.size();
        int w = v[0].size();

        data = vector<vector<T>>(h + 1, vector<T>(w + 1));

        rep(i, h) rep(j, w) {
            data[i + 1][j + 1] += data[i][j + 1] + data[i + 1][j] - data[i][j] + v[i][j];
        }
    }

    T sum(int si, int sj, int fi, int fj) {
        T ret = data[fi][fj];
        ret -= data[si][fj];
        ret -= data[fi][sj];
        ret += data[si][sj];
        return ret;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W, N;
    cin >> H >> W >> N;

    vvint dp(H, vint(W, 1));
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dp[a][b] = 0;
    }

    rep(i, H) rep(j, W) {
        if (dp[i][j] == 0) continue;
        if (i == 0 || j == 0) continue;
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    }

    ll ans = 0;
    rep(i, H) rep(j, W) {
        ans += dp[i][j];
    }
    cout << ans << endl;
}
