/*https://atcoder.jp/contests/abc378/tasks/abc378_d*/
/*2025年01月29日 02時59分41秒*/
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

ll H, W, K;
vector<string> grid;
vvint visited;
ll ans = 0;

vint di = {0, 1, 0, -1};
vint dj = {1, 0, -1, 0};

void dfs(int i, int j, int depth) {
    if (depth == K) {
        ans++;
        return;
    }

    rep(d, 4) {
        ll ni = i + di[d], nj = j + dj[d];
        if (clamp(ni, 0LL, H - 1) != ni || clamp(nj, 0LL, W - 1) != nj ||
            visited[ni][nj]) {
            continue;
        }

        visited[ni][nj] = 1;
        dfs(ni, nj, depth + 1);
        visited[ni][nj] = 0;
    }
}

void solve() {
    cin >> H >> W >> K;
    grid.resize(H);
    rep(i, H) cin >> grid[i];

    visited = vvint(H, vint(W, 0));
    rep(i, H) rep(j, W) if (grid[i][j] == '#') visited[i][j] = 1;

    rep(i, H) rep(j, W) {
        if (grid[i][j] == '.') {
            visited[i][j] = 1;
            dfs(i, j, 0);
            visited[i][j] = 0;
        }
    }

    cout << ans << endl;
}
