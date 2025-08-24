// https://atcoder.jp/contests/abc420/tasks/abc420_d
// 2025年08月24日 21時14分12秒
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

    ll H, W;
    cin >> H >> W;
    vector<string> grid(H), invgrid(H);
    rep(i, H) cin >> grid[i];
    invgrid = grid;

    int si, sj, fi, fj;

    rep(i, H) rep(j, W) {
        if (invgrid[i][j] == 'o')
            invgrid[i][j] = 'x';
        else if (invgrid[i][j] == 'x')
            invgrid[i][j] = 'o';

        if (grid[i][j] == 'S') si = i, sj = j;
        if (grid[i][j] == 'G') fi = i, fj = j;
    }

    vector dist(2, vector(H, vll(W, INF)));
    dist[0][si][sj] = 0;

    // i, j, state, distance
    // state = 0 が表
    using P = tuple<ll, ll, ll, ll>;
    queue<P> que;
    que.push({si, sj, 0, 0});

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    while (que.size()) {
        auto [i, j, state, D] = que.front();
        que.pop();

        if (dist[state][i][j] < D) {
            continue;
        }

        rep(d, 4) {
            ll ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
            char nxmass = grid[ni][nj];
            if (nxmass == '#') continue;
            if (state == 0 && nxmass == 'x') continue;
            if (state == 1 && nxmass == 'o') continue;
            if (nxmass == '?') {
                if (dist[1 - state][ni][nj] > D + 1) {
                    dist[1 - state][ni][nj] = D + 1;
                    que.push({ni, nj, 1 - state, D + 1});
                }
            } else {
                if (dist[state][ni][nj] > D + 1) {
                    dist[state][ni][nj] = D + 1;
                    que.push({ni, nj, state, D + 1});
                }
            }
        }
    }

    ll ans = min(dist[0][fi][fj], dist[1][fi][fj]);
    if (ans == INF) ans = -1;
    cout << ans << endl;
}
