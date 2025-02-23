/*https://atcoder.jp/contests/abc351/tasks/abc351_d*/
/*2025年02月16日 18時58分10秒*/
#include <atcoder/all>
using namespace atcoder;
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

int h, w;
vector<string> grid;
vvint memo;
vvint visited;
vint di = {0, 1, 0, -1};
vint dj = {1, 0, -1, 0};

pair<int, int> ind2sub(int x) {
    return {x / w, x % w};
}

int sub2ind(int i, int j) {
    return i * w + j;
}

int canMove(int i, int j) {
    int ok = 1;
    rep(d, 4) {
        int ni = i + di[d], nj = j + dj[d];
        if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
            continue;
        if (grid[ni][nj] == '#')
            ok = 0;
    }

    return ok;
}

void solve() {
    cin >> h >> w;
    grid = vector<string>(h);
    rep(i, h) cin >> grid[i];

    dsu uf(h * w);

    rep(i, h) rep(j, w) {
        if (grid[i][j] == '.' && canMove(i, j)) {
            for (auto [ii, jj] : vector<pair<int, int>>({{1, 0}, {0, 1}})) {
                int ni = i + ii, nj = j + jj;
                if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
                    continue;
                if (canMove(ni, nj)) {
                    uf.merge(sub2ind(i, j), sub2ind(ni, nj));
                }
            }
        }
    }

    int ans = 1;
    for (auto v : uf.groups()) {
        set<pair<int, int>> stop;
        {
            auto [i, j] = ind2sub(v[0]);
            if (grid[i][j] == '#')
                continue;
            else if (!canMove(i, j)) {
                continue;
            }
        }
        for (int id : v) {
            auto [i, j] = ind2sub(id);
            rep(d, 4) {
                int ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0, h - 1) != ni || clamp(nj, 0, w - 1) != nj)
                    continue;
                if (grid[ni][nj] == '.' && !canMove(ni, nj))
                    stop.insert({ni, nj});
            }
        }
        chmax(ans, (int)v.size() + (int)stop.size());
    }

    cout << ans << endl;
}
