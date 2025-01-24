/*https://atcoder.jp/contests/abc333/tasks/abc333_d*/
/*2025年01月24日 20時48分32秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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

int N;
vvint graph;
vll nodes;

ll dfs(int now, int p) {
    nodes[now] = 1;

    ll sum = 0;
    for (int nx : graph[now]) {
        if (nx == p)
            continue;
        sum += dfs(nx, now);
    }
    nodes[now] += sum;

    return nodes[now];
}

void solve() {
    cin >> N;
    graph = vvint(N);
    nodes = vll(N);

    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, -1);

    vll children;
    for (int nx : graph[0]) {
        children.push_back(nodes[nx]);
    }
    sort(all(children));

    ll sum = accumulate(all(children), 0);
    sum -= children.back();
    cout << sum + 1 << endl;
}
