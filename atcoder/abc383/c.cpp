/*https://atcoder.jp/contests/abc383/tasks/abc383_c*/
/*2025年01月08日 22時09分22秒*/
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

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void solve() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    vvll dist(H, vll(W, INF));
    queue<pair<int, int>> que;
    rep(i, H) rep(j, W) {
        if (grid[i][j] == 'H') {
            dist[i][j] = 0;
            que.push({i, j});
        }
    }

    while (que.size()) {
        auto [i, j] = que.front();
        que.pop();

        int d = dist[i][j];
        if (d + 1 > D)
            continue;

        rep(k, 4) {
            int ni = i + dx[k], nj = j + dy[k];
            if (clamp(ni, 0, H - 1) == ni && clamp(nj, 0, W - 1) == nj &&
                grid[ni][nj] == '.' && dist[ni][nj] > d + 1) {
                dist[ni][nj] = d + 1;
                que.push({ni, nj});
            }
        }
    }

    ll ans = 0;
    rep(i, H) rep(j, W) ans += dist[i][j] <= D;
    cout << ans << endl;
}
