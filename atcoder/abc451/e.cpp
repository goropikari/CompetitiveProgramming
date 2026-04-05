// https://atcoder.jp/contests/abc451/tasks/abc451_e
// Wed 01 Apr 2026 10:53:41 PM JST
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
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
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

    ll N;
    cin >> N;

    int m = 10005;
    using P = pair<ll, ll>;
    vector<vector<P>> as(m);

    rep(i, N) rep2(j, i + 1, N) {
        ll a;
        cin >> a;
        as[a].pb({i, j});
    }

    dsu uf(N);

    vvll dist(N, vll(N));
    vvint to(N);
    rep(k, m) {
        for (auto [i, j] : as[k]) {
            if (uf.same(i, j)) continue;
            uf.merge(i, j);
            dist[i][j] = dist[j][i] = k;
            to[i].pb(j);
            to[j].pb(i);
        }
    }

    vvll lens(N, vll(N, INF));
    rep(i, N) lens[i][i] = 0;

    auto dfs = [&](auto dfs, vll& len, ll sum, int now, int p) -> void {
        for (int nx : to[now]) {
            if (nx == p) continue;
            len[nx] = sum + dist[now][nx];
            dfs(dfs, len, sum + dist[now][nx], nx, now);
        }
    };

    rep(i, N)
        dfs(dfs, lens[i], 0, i, -1);

    int ok = 1;
    rep(k, m) {
        for (auto [i, j] : as[k]) {
            if (lens[i][j] != k)
                ok = 0;
        }
    }
    yesno(ok);
}
