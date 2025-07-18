// https://atcoder.jp/contests/abc412/tasks/abc412_d
// 2025年06月28日 21時20分10秒
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vvint grid(N, vint(N));
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        grid[a][b] = grid[b][a] = 1;
    }

    using P = pair<int, int>;
    vector<P> es;
    rep(i, N) rep2(j, i + 1, N) es.push_back({i, j});

    ll ans = INF;
    int m = N * (N - 1) / 2;

    auto judge = [&](int used) -> void {
        vector<P> edges;
        rep(i, m) {
            if (used >> i & 1) edges.push_back(es[i]);
        }
        vector tmp(N, vint(N));
        for (auto [u, v] : edges) {
            tmp[u][v] = 1;
            tmp[v][u] = 1;
        }

        rep(i, N) {
            ll deg = 0;
            rep(j, N) {
                deg += tmp[i][j];
            }
            if (deg != 2) return;
        }

        ll sum = 0;
        rep(i, N) rep2(j, i + 1, N) {
            if (grid[i][j] != tmp[i][j]) sum++;
        }
        chmin(ans, sum);
        return;
    };

    auto dfs = [&](auto dfs, int used) -> void {
        if (__builtin_popcount(used) == N) {
            judge(used);
            return;
        }

        int s = -1;
        rep(i, m) {
            if (used >> i & 1) s = i;
        }
        s++;
        rep2(i, s, m) {
            dfs(dfs, used | (1 << i));
        }
    };

    dfs(dfs, 0);
    cout << ans << endl;
}
