/*https://atcoder.jp/contests/abc293/tasks/abc293_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

int H, W;
vvint grid;
int dx[] = {1, 0};
int dy[] = {0, 1};

bool valid(int x, int y) {
    return clamp(x, 0, H - 1) == x && clamp(y, 0, W - 1) == y;
}

int dfs(int x, int y, set<int>& memo) {
    if (x == H - 1 && y == W - 1) {
        return memo.size() == H + W - 1;
    }

    int ans = 0;
    rep(i, 2) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!valid(nx, ny))
            continue;
        if (memo.count(grid[nx][ny]))
            continue;
        memo.insert(grid[nx][ny]);
        ans += dfs(nx, ny, memo);
        memo.erase(grid[nx][ny]);
    }

    return ans;
}

void solve() {
    cin >> H >> W;
    grid = vvint(H, vint(W));
    rep(i, H) rep(j, W) cin >> grid[i][j];

    set<int> memo;
    memo.insert(grid[0][0]);
    cout << dfs(0, 0, memo) << endl;
}
