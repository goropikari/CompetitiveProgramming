/*https://atcoder.jp/contests/abc317/tasks/abc317_e*/
/*2025年03月13日 23時34分46秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> raw_grid(h, vector<char>(w)), grid(h, vector<char>(w, '.'));
    rep(i, h) rep(j, w) cin >> raw_grid[i][j];

    int si, sj, ti, tj;
    rep(i, h) rep(j, w) {
        if (raw_grid[i][j] == 'S') {
            si = i, sj = j;
            raw_grid[i][j] = '.';
        }
        if (raw_grid[i][j] == 'G') {
            ti = i, tj = j;
            raw_grid[i][j] = '.';
        }
    }

    rep(i, h) rep(j, w) if (raw_grid[i][j] != '.') grid[i][j] = '#';

    rep(i, h) {
        int inside = 0;
        rep(j, w) {
            if (inside && raw_grid[i][j] != '.') {
                inside = 0;
            }

            if (raw_grid[i][j] == '>')
                inside = 1;
            if (inside && raw_grid[i][j] == '.') {
                grid[i][j] = '#';
            }
        }
    }
    rep(i, h) {
        int inside = 0;
        rep(j, w) {
            int rj = w - j - 1;
            if (inside && raw_grid[i][rj] != '.') {
                inside = 0;
            }

            if (raw_grid[i][rj] == '<')
                inside = 1;
            if (inside && raw_grid[i][rj] == '.') {
                grid[i][rj] = '#';
            }
        }
    }
    rep(j, w) {
        int inside = 0;
        rep(i, h) {
            if (inside && raw_grid[i][j] != '.') {
                inside = 0;
            }

            if (raw_grid[i][j] == 'v')
                inside = 1;
            if (inside && raw_grid[i][j] == '.') {
                grid[i][j] = '#';
            }
        }
    }
    rep(j, w) {
        int inside = 0;
        rep(i, h) {
            int ri = h - i - 1;
            if (inside && raw_grid[ri][j] != '.') {
                inside = 0;
            }

            if (raw_grid[ri][j] == '^')
                inside = 1;
            if (inside && raw_grid[ri][j] == '.') {
                grid[ri][j] = '#';
            }
        }
    }

    queue<pair<int, int>> que;
    que.push({si, sj});
    vvll dist(h, vll(w, INF));
    dist[si][sj] = 0;
    vint di = {1, 0, -1, 0};
    vint dj = {0, -1, 0, 1};
    while (que.size()) {
        auto [i, j] = que.front();
        que.pop();

        rep(d, 4) {
            int ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
                continue;
            if (grid[ni][nj] == '#')
                continue;
            if (dist[ni][nj] <= dist[i][j] + 1)
                continue;
            dist[ni][nj] = dist[i][j] + 1;
            que.push({ni, nj});
        }
    }

    ll ans = dist[ti][tj];
    if (dist[ti][tj] == INF)
        ans = -1;
    cout << ans << endl;
}
