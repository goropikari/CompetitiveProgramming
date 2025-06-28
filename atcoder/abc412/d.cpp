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

    ll ans = INF;

    vint v(N);
    iota(all(v), 0);

    do {
        vector<set<int>> graph(N);
        rep(i, N) {
            graph[i].insert(v[i]);
            graph[v[i]].insert(i);
        }
        int ok = 1;
        rep(i, N) if (graph[i].size() != 2) ok = 0;
        if (!ok) continue;

        vvint tmp(N, vint(N));
        rep(i, N) {
            for (int nx : graph[i]) {
                tmp[i][nx] = 1;
            }
        }

        ll cnt = 0;
        rep(i, N) rep2(j, i + 1, N) {
            if (grid[i][j] != tmp[i][j]) cnt++;
        }
        chmin(ans, cnt);
    } while (next_permutation(all(v)));
    cout << ans << endl;
}
