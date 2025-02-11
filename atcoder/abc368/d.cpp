/*https://atcoder.jp/contests/abc368/tasks/abc368_d*/
/*2025年02月12日 01時38分05秒*/
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

vvint graph;
vint visited;
set<int> memo;
int ans = 0;

bool dfs(int now) {
    bool res = false;
    if (memo.count(now))
        res = true;

    for (int nx : graph[now]) {
        if (visited[nx])
            continue;
        visited[nx] = 1;

        bool x = dfs(nx);
        res = res || x;

        // short-circuit で以下のよう書くと dfs が実行されない
        // res = res || dfs(nx)
    }

    if (res)
        ans++;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    graph = vvint(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vint nodes(k);
    rep(i, k) {
        cin >> nodes[i];
        nodes[i]--;
    }

    for (int x : nodes)
        memo.insert(x);

    visited = vint(n, 0);
    visited[nodes[0]] = 1;

    dfs(nodes[0]);
    cout << ans << endl;
}
