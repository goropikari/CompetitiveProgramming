/*https://atcoder.jp/contests/dp/tasks/dp_h*/
/*2025年01月19日 14時02分43秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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

int di[] = {0, -1};
int dj[] = {-1, 0};

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    ll MOD = (ll)1e9 + 7;
    vvll dist(H, vll(W, 0));
    dist[0][0] = 1;
    // rep(i, H) {
    //     rep(j, W) {
    //         rep(d, 2) {
    //             int px = i + di[d], py = j + dj[d];
    //             if (clamp(px, 0, H - 1) != px || clamp(py, 0, W - 1) != py)
    //                 continue;
    //             if (grid[px][py] == '#')
    //                 continue;
    //             if (grid[i][j] == '#')
    //                 continue;
    //
    //             dist[i][j] += dist[px][py];
    //             dist[i][j] %= MOD;
    //         }
    //     }
    // }

    vvint visited(H, vint(W, 0));
    queue<pair<int, int>> que;
    que.push({0, 0});
    while (que.size()) {
        auto [x, y] = que.front();
        que.pop();
        if (visited[x][y])
            continue;
        visited[x][y] = 1;

        vint di = {0, 1}, dj = {1, 0};
        rep(d, 2) {
            int nx = x + di[d], ny = y + dj[d];
            if (clamp(nx, 0, H - 1) != nx || clamp(ny, 0, W - 1) != ny)
                continue;
            if (grid[nx][ny] == '#')
                continue;
            dist[nx][ny] += dist[x][y];
            dist[nx][ny] %= MOD;
            que.push({nx, ny});
        }
    }

    cout << dist[H - 1][W - 1] << endl;
}
