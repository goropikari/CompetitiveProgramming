/*https://atcoder.jp/contests/abc276/tasks/abc276_e*/
/*2025年02月20日 01時22分55秒*/
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

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    int si, sj;
    rep(i, H) rep(j, W) if (grid[i][j] == 'S') si = i, sj = j;
    vvint mark(H, vint(W, -1));

    queue<pair<int, int>> q;
    q.push({si, sj});
    mark[si][sj] = 0;

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        int c = mark[i][j];
        int start = c == 0;

        rep(d, 4) {
            if (start)
                c = d + 1;
            int ni = i + di[d], nj = j + dj[d];
            if (clamp(ni, 0, H - 1) != ni || clamp(nj, 0, W - 1) != nj)
                continue;
            if (grid[ni][nj] == '#')
                continue;
            int m = mark[ni][nj];
            if (m > 0 && m != c) {
                yesno(true);
                return;
            }
            if (m == -1) {
                mark[ni][nj] = c;
                q.push({ni, nj});
            }
        }
    }
    yesno(false);
}
