/*https://atcoder.jp/contests/abc387/tasks/abc387_d*/
/*2025年01月05日 21時44分07秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

int H, W;
vector<string> grid;
vector<vector<vector<ll>>> dist;

bool in_range(int x, int y) {
    return clamp(x, 0, H - 1) == x && clamp(y, 0, W - 1) == y;
}

void solve() {
    cin >> H >> W;
    grid.resize(H);
    rep(i, H) cin >> grid[i];
    dist.resize(2);
    dist[0] = vvll(H, vll(W, INF));
    dist[1] = vvll(H, vll(W, INF));

    int sx, sy, gx, gy;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'S')
            sx = i, sy = j;
        if (grid[i][j] == 'G')
            gx = i, gy = j;
    }

    dist[0][sx][sy] = dist[1][sx][sy] = 0;

    queue<pair<int, int>> que;
    que.push({sx, sy});
    while (que.size()) {
        auto [x, y] = que.front();
        que.pop();

        // 横移動で x,y にいる
        if (dist[0][x][y] != INF) {
            ll cost = dist[0][x][y] + 1;
            if (in_range(x + 1, y)) {
                if (grid[x + 1][y] == '.' && cost < dist[1][x + 1][y]) {
                    dist[1][x + 1][y] = cost;
                    que.push({x + 1, y});
                } else if (grid[x + 1][y] == 'G') {
                    chmin(dist[1][x + 1][y], cost);
                }
            }
            if (in_range(x - 1, y)) {
                if (grid[x - 1][y] == '.' && cost < dist[1][x - 1][y]) {
                    dist[1][x - 1][y] = cost;
                    que.push({x - 1, y});
                } else if (grid[x - 1][y] == 'G') {
                    chmin(dist[1][x - 1][y], cost);
                }
            }
        }

        // 縦移動で x,y にいる
        if (dist[1][x][y] != INF) {
            ll cost = dist[1][x][y] + 1;
            if (in_range(x, y + 1)) {
                if (grid[x][y + 1] == '.' && cost < dist[0][x][y + 1]) {
                    dist[0][x][y + 1] = cost;
                    que.push({x, y + 1});
                } else if (grid[x][y + 1] == 'G') {
                    chmin(dist[0][x][y + 1], cost);
                }
            }
            if (in_range(x, y - 1)) {
                if (grid[x][y - 1] == '.' && cost < dist[0][x][y - 1]) {
                    dist[0][x][y - 1] = cost;
                    que.push({x, y - 1});
                } else if (grid[x][y - 1] == 'G') {
                    chmin(dist[0][x][y - 1], cost);
                }
            }
        }
    }

    ll ans = INF;
    if (dist[0][gx][gy] == INF && dist[1][gx][gy] == INF)
        ans = -1;
    else
        chmin(ans, min(dist[0][gx][gy], dist[1][gx][gy]));
    cout << ans << endl;
}
