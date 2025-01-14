// https://atcoder.jp/contests/math-and-algorithm/tasks/abc007_3
/*2025年01月12日 03時01分49秒*/
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

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
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

void solve() {
    int R, C;
    cin >> R >> C;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    vector<string> grid(R);
    rep(i, R) cin >> grid[i];

    vvint dist(R, vint(C, INF));
    dist[sx][sy] = 0;
    vint dx = {0, 1, 0, -1};
    vint dy = {1, 0, -1, 0};
    queue<pair<int, int>> que;
    que.push({sx, sy});
    while (que.size()) {
        auto [x, y] = que.front();
        que.pop();

        ll D = dist[x][y];
        rep(d, 4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (grid[nx][ny] == '#')
                continue;
            if (dist[nx][ny] > D + 1) {
                dist[nx][ny] = D + 1;
                que.push({nx, ny});
            }
        }
    }
    cout << dist[gx][gy] << endl;
}
