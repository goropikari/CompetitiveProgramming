/*https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A*/
/*2025年03月10日 02時13分06秒*/
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

struct Edge {
    ll to, w;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<Edge>> graph(n);
    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    int id = 0, d = 0;
    vint visited(n, 0);
    auto dfs = [&](auto dfs, int now, int depth) -> void {
        visited[now] = 1;

        for (auto [to, w] : graph[now]) {
            if (visited[to])
                continue;
            if (d < depth + w) {
                id = to;
                d = depth + w;
            }
            dfs(dfs, to, depth + w);
        }
    };

    dfs(dfs, 0, 0);

    visited = vint(n, 0);
    d = 0;
    dfs(dfs, id, 0);

    cout << d << endl;
}
