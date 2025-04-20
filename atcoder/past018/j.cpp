// https://atcoder.jp/contests/past18-open/tasks/past18_j
// 2025年04月18日 01時05分55秒
#include <bits/stdc++.h>
#include <queue>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
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

    ll start = 0;
    rep(i, H) rep(j, W) {
        ll x = i * W + j;
        if (grid[i][j] == '#')
            start |= 1ll << x;
    }

    vector<vvll> dist(1ll << (H * W), vvll(H, vll(W, INF)));
    dist[start][0][0] = 0;

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    using P = tuple<ll, ll, ll, ll>;
    queue<P> pq;
    pq.push({0, start, 0, 0});
    while (pq.size()) {
        auto [cost, now, i, j] = pq.front();
        pq.pop();

        if (dist[now][i][j] < cost)
            continue;

        rep(d, 4) {
            ll ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj)
                continue;

            ll nx = now ^ (1ll << (ni * W + nj));
            if (dist[nx][ni][nj] <= cost + 1)
                continue;

            dist[nx][ni][nj] = cost + 1;
            pq.push({dist[nx][ni][nj], nx, ni, nj});
        }
    }

    ll ans = INF;
    rep(i, H) rep(j, W) chmin(ans, dist[0][i][j]);

    cout << ans << endl;
}
