// https://atcoder.jp/contests/arc005/tasks/arc005_3
// 2025年04月06日 23時16分21秒
#include <bits/stdc++.h>
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

    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];

    int si, sj, ti, tj;
    rep(i, h) rep(j, w) {
        if (grid[i][j] == 's')
            si = i, sj = j;
        if (grid[i][j] == 'g')
            ti = i, tj = j;
    }

    using P = pair<ll, pair<int, int>>;
    deque<P> pq;
    pq.push_back({0, {si, sj}});
    vvll dist(h, vll(w, INF));
    dist[si][sj] = 0;

    vint di = {1, 0, -1, 0};
    vint dj = {0, -1, 0, 1};

    while (pq.size()) {
        auto [cost, now] = pq.front();
        pq.pop_front();

        auto [i, j] = now;

        if (dist[i][j] < cost)
            continue;

        rep(d, 4) {
            int ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
                continue;

            int wall = grid[ni][nj] == '#';
            if (dist[ni][nj] <= cost + wall)
                continue;

            dist[ni][nj] = cost + wall;
            if (wall)
                pq.push_back({dist[ni][nj], {ni, nj}});
            else
                pq.push_front({dist[ni][nj], {ni, nj}});
        }
    }

    string ans = "NO";
    if (dist[ti][tj] <= 2)
        ans = "YES";
    cout << ans << endl;
}
