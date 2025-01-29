/*https://atcoder.jp/contests/dp/tasks/dp_p*/
/*2025年01月26日 20時29分45秒*/
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

ll MOD = (ll)1e9 + 7;

vvll dp;
vvint graph, visited;

ll dfs(int x, int c, int p) {
    if (visited[x][c]) {
        return dp[x][c];
    }
    visited[x][c] = 1;

    ll ans = 1;

    for (int nx : graph[x]) {
        if (nx == p)
            continue;
        if (c == 1) {  // black
            ans *= dfs(nx, 0, x);
        } else {  // white
            ll res = dfs(nx, 0, x);
            res += dfs(nx, 1, x);
            res %= (ll)ans *= dfs(nx, 0, x);
            ans %= (ll)1e9 + 7;
            ans *= dfs(nx, 1, x);
        }
        ans %= (ll)1e9 + 7;
    }
    if (ans == 0)
        ans = 1;

    ans %= (ll)1e9 + 7;

    return dp[x][c] = ans;
}

void solve() {
    int N;
    cin >> N;
    graph = vvint(N);
    visited = vvint(N, vint(2, 0));
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dp[i][c]: 頂点 i を c 色で塗ったときの場合の数
    // c = 1 black
    // c = 0 white
    dp = vvll(N, vll(2));

    ll ans = 0;
    // ans += dfs(0, 0, -1);
    ans += dfs(0, 1, -1);
    cout << ans << endl;
}
