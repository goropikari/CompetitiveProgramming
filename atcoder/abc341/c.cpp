/*https://atcoder.jp/contests/abc341/tasks/abc341_c*/
/*2024年12月31日 14時57分27秒*/
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

int H, W, N;
string T;
vector<string> grid;

bool valid(int i, int j) {
    return clamp(i, 0, H - 1) == i && clamp(j, 0, W - 1) == j;
}

bool check(int i, int j) {
    if (grid[i][j] == '#')
        return false;

    int x = i, y = j;
    for (char c : T) {
        if (c == 'L') {
            y--;
        } else if (c == 'R') {
            y++;
        } else if (c == 'U') {
            x--;
        } else {
            x++;
        }
        if (!valid(x, y))
            return false;
        if (grid[x][y] == '#')
            return false;
    }
    return grid[x][y] == '.';
}

void solve() {
    cin >> H >> W >> N;
    cin >> T;
    grid.resize(H);
    rep(i, H) cin >> grid[i];

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            ans += check(i, j);
        }
    }
    cout << ans << endl;
}
