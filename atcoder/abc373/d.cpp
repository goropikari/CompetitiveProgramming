/*https://atcoder.jp/contests/abc373/tasks/abc373_d*/
/*2025年01月27日 02時13分00秒*/
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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
    ll to, weight;
};

void dfs(vector<vector<Edge>>& graph, vll& ans, int now) {
    for (auto [to, w] : graph[now]) {
        if (ans[to] != INF)
            continue;
        ans[to] = ans[now] + w;
        dfs(graph, ans, to);
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    vll u(M), v(M), w(M);
    rep(i, M) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }

    vector<vector<Edge>> graph(N);

    rep(i, M) {
        graph[u[i]].push_back({v[i], w[i]});
        graph[v[i]].push_back({u[i], -w[i]});
    }

    vll ans(N, INF);
    rep(i, N) {
        if (ans[i] == INF) {
            ans[i] = 0;
            dfs(graph, ans, i);
        }
    }
    print(ans);
}
