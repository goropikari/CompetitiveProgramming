/*https://atcoder.jp/contests/abc348/tasks/abc348_d*/
/*2025年02月19日 00時02分49秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <queue>
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

struct Point {
    ll r, c, p;
};

bool operator>(const Point& a, const Point& b) {
    return a.p > b.p;
}

bool operator<(const Point& a, const Point& b) {
    return a.p < b.p;
}

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    int N;
    cin >> N;
    map<pair<int, int>, ll> es;
    rep(i, N) {
        ll r, c, e;
        cin >> r >> c >> e;
        r--, c--;
        es[{r, c}] = e;
    }

    int sx, sy, tx, ty;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'S')
            sx = i, sy = j;
        if (grid[i][j] == 'T')
            tx = i, ty = j;
    }

    priority_queue<Point> pq;
    pq.push({sx, sy, es[{sx, sy}]});

    vvll energy(H, vll(W, -1));

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    while (pq.size()) {
        auto [x, y, e] = pq.top();
        pq.pop();

        if (e < energy[x][y])
            continue;

        rep(d, 4) {
            int nx = x + di[d], ny = y + dj[d];
            if (clamp(nx, 0, H - 1) != nx || clamp(ny, 0, W - 1) != ny)
                continue;
            if (grid[nx][ny] == '#')
                continue;
            if (e > 0 && max(e - 1, es[{nx, ny}]) > energy[nx][ny]) {
                energy[nx][ny] = max(e - 1, es[{nx, ny}]);
                pq.push({nx, ny, energy[nx][ny]});
            }
        }
    }

    yesno(energy[tx][ty] >= 0);
}
