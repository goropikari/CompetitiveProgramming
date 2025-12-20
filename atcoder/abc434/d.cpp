// https://atcoder.jp/contests/abc434/tasks/abc434_d
// Sun 30 Nov 2025 07:09:16 PM JST
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

    ll mx = 2005;
    vvll grid(mx, vll(mx));

    int N;
    cin >> N;
    vector<tuple<ll, ll, ll, ll>> sqs;
    rep(i, N) {
        ll u, d, l, r;
        cin >> u >> d >> l >> r;
        u--, d--, l--, r--;
        sqs.emplace_back(u, d, l, r);

        grid[u][l]++;
        grid[u][r + 1]--;
        grid[d + 1][l]--;
        grid[d + 1][r + 1]++;
    }

    rep(i, mx) rep2(j, 1, mx) {
        grid[i][j] += grid[i][j - 1];
    }
    rep2(i, 1, mx) rep(j, mx) {
        grid[i][j] += grid[i - 1][j];
    }

    ll offset = 0;
    vvll freq_one(mx, vll(mx));
    {
        rep(i, 2000) rep(j, 2000) {
            if (grid[i][j] == 0) offset++;
            if (grid[i][j] == 1) freq_one[i][j] = 1;
        }
    }

    Cumsum2d cumsum(freq_one);
    for (auto [u, d, l, r] : sqs) {
        ll sum = cumsum.sum(u, l, d + 1, r + 1);
        cout << offset + sum << '\n';
    }
}
