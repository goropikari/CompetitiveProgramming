/*https://atcoder.jp/contests/abc394/tasks/abc394_f*/
/*2025年02月22日 22時14分01秒*/
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

vint visited;

ll dfs(vvint& graph, int now, int p, ll depth) {
    ll ret = depth;
    for (int to : graph[now]) {
        if (to == p)
            continue;
        if (graph[to].size() < 4)
            continue;
        if (visited[to])
            continue;

        visited[to] = 1;

        chmax(ret, dfs(graph, to, now, depth + 1));
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vvint graph(n);
    visited.resize(n, 0);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ok = 0;
    rep(i, n) {
        if (graph[i].size() >= 4)
            ok = 1;
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }

    ll ans = 1;
    rep(i, n) {
        if (graph[i].size() < 4) {
            continue;
        }
        if (visited[i])
            continue;
        int cnt = 0;
        for (auto to : graph[i]) {
            if (graph[to].size() >= 4)
                cnt++;
        }
        if (cnt <= 1) {
            if (cnt == 1)
                chmax(ans, 2ll);
            continue;
        }
        visited[i] = 1;
        vll tmp;
        for (auto to : graph[i]) {
            if (graph[to].size() >= 4) {
                visited[to] = 1;
                tmp.push_back(dfs(graph, to, i, 2));
            }
        }
        sort(rall(tmp));
        chmax(ans, tmp[0] + tmp[1] - 1);
    }
    cout << ans + 2 * ans + 2 << endl;
}
