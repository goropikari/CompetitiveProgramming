// https://atcoder.jp/contest/abc385/tasks/abc385_b
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

void solve() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> grid(H);
    string T;
    rep(i, H) cin >> grid[i];
    cin >> T;
    X--, Y--;

    vvint visited(H, vint(W, 0));

    int nx, ny;
    int ans = 0;
    for (char c : T) {
        if (c == 'U') {
            nx = X - 1, ny = Y;
        } else if (c == 'D') {
            nx = X + 1, ny = Y;
        } else if (c == 'L') {
            nx = X, ny = Y - 1;
        } else {  // R
            nx = X, ny = Y + 1;
        }
        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
            continue;
        if (grid[nx][ny] == '#')
            continue;
        if (!visited[nx][ny] && grid[nx][ny] == '@')
            ans++;
        X = nx;
        Y = ny;
        visited[nx][ny] = 1;
    }
    cout << X + 1 << ' ' << Y + 1 << ' ' << ans << endl;
}

int main() {
    solve();
    return 0;
}
