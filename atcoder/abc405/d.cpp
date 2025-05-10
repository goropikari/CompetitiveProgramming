// https://atcoder.jp/contests/abc405/tasks/abc405_d
// 2025年05月10日 21時07分45秒
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

    int si = 0, sj = 0;
    vector<pair<int, int>> doors;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'E')
            doors.push_back({i, j});
    }

    vvll dist(H, vll(W, INF));
    // i,j, cost
    deque<tuple<ll, ll, ll>> deq;
    for (auto [i, j] : doors) {
        deq.push_back({i, j, 0});
        dist[i][j] = 0;
    }

    vll di = {0, 1, 0, -1};
    vll dj = {1, 0, -1, 0};
    while (deq.size()) {
        auto [nowi, nowj, cost] = deq.front();
        deq.pop_front();

        if (dist[nowi][nowj] < cost)
            continue;

        rep(dir, 4) {
            ll ni = nowi + di[dir], nj = nowj + dj[dir];
            if (OUTSIDE(ni, nj, H, W))
                continue;
            if (grid[ni][nj] == '#')
                continue;
            if (dist[ni][nj] <= cost + 1)
                continue;
            dist[ni][nj] = cost + 1;
            deq.push_back({ni, nj, dist[ni][nj]});
        }
    }

    vector<char> dir_mark = {'>', 'v', '<', '^'};

    vector<string> ans = grid;

    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#' || grid[i][j] == 'E')
                continue;
            rep(dir, 4) {
                ll ni = i + di[dir], nj = j + dj[dir];
                if (OUTSIDE(ni, nj, H, W))
                    continue;
                if (dist[i][j] == dist[ni][nj] + 1) {
                    ans[i][j] = dir_mark[dir];
                }
            }
        }
    }

    for (auto s : ans)
        cout << s << endl;
}
