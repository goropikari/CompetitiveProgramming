/*https://atcoder.jp/contests/abc396/tasks/abc396_d*/
/*2025年03月08日 21時13分04秒*/
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
    ll to, cost;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    rep(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    ll ans = INF;

    vint used(n, 0);

    auto dfs = [&](auto dfs, int now = 0, ll sum = 0ll) {
        if (now == n - 1) {
            chmin(ans, sum);
            return;
        }

        for (auto [to, cost] : graph[now]) {
            if (used[to])
                continue;
            used[to] = 1;
            dfs(dfs, to, sum ^ cost);
            used[to] = 0;
        }
    };

    used[0] = 1;
    dfs(dfs);
    cout << ans << endl;
}
