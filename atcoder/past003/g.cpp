// https://atcoder.jp/contests/past202005-open/tasks/past202005_g
// 2025年05月15日 02時45分53秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

    int N, X, Y;
    cin >> N >> X >> Y;
    map<pair<int, int>, bool> block;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        block[{x, y}] = 1;
    }

    map<pair<int, int>, ll> dist;
    queue<tuple<int, int, ll>> que;
    que.push({0, 0, 0});
    vint dx = {1, 0, -1, 1, -1, 0};
    vint dy = {1, 1, 1, 0, 0, -1};
    while (que.size()) {
        auto [x, y, cost] = que.front();
        que.pop();

        if (dist.count({x, y}) && dist[{x, y}] < cost)
            continue;

        rep(dir, 6) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (abs(nx) > 201 || abs(ny) > 201)
                continue;
            if (block.count({nx, ny}))
                continue;
            ll nxdist = INF;
            if (dist.count({nx, ny}))
                nxdist = dist[{nx, ny}];
            if (nxdist <= cost + 1)
                continue;
            dist[{nx, ny}] = cost + 1;
            que.push({nx, ny, cost + 1});
        }
    }

    ll ans = -1;
    if (dist.count({X, Y}))
        ans = dist[{X, Y}];
    cout << ans << endl;
}
