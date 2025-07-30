// https://atcoder.jp/contests/abc416/tasks/abc416_e
// 2025年07月26日 21時42分34秒
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

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
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

    vvll dist(N + 1, vll(N + 1, INF));
    rep(i, N + 1) dist[i][i] = 0;
    rep(i, M) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        chmin(dist[u][v], c);
        chmin(dist[v][u], c);
    }

    ll K, T;
    cin >> K >> T;
    rep(i, K) {
        ll d;
        cin >> d;
        d--;
        dist[d][N] = T;
        dist[N][d] = 0;
    }

    auto warshallfloyd = [&]() -> void {
        rep(k, N + 1) rep(i, N + 1) rep(j, N + 1) {
            chmin(dist[i][j], dist[i][k] + dist[k][j]);
        }
    };

    auto Sum = [&]() -> ll {
        ll ret = 0;
        rep(i, N) rep(j, N) {
            if (dist[i][j] == INF) continue;
            ret += dist[i][j];
        }
        return ret;
    };

    warshallfloyd();

    int Q;
    cin >> Q;
    rep(i, Q) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            ll x, y, t;
            cin >> x >> y >> t;
            x--, y--;
            chmin(dist[x][y], t);
            chmin(dist[y][x], t);

            rep(i, N + 1) rep(j, N + 1) {
                chmin(dist[i][j], dist[i][y] + dist[y][x] + dist[x][j]);
            }
            rep(i, N + 1) rep(j, N + 1) {
                chmin(dist[i][j], dist[i][x] + dist[x][y] + dist[y][j]);
            }
        } else if (query_type == 2) {
            ll x;
            cin >> x;
            x--;
            dist[x][N] = T;
            dist[N][x] = 0;
            rep(i, N + 1) rep(j, N + 1) {
                chmin(dist[i][j], dist[i][N] + dist[N][x] + dist[x][j]);
            }
            rep(i, N + 1) rep(j, N + 1) {
                chmin(dist[i][j], dist[i][x] + dist[x][N] + dist[N][j]);
            }
        } else {  // t = 3;
            cout << Sum() << '\n';
        }
    }
}
