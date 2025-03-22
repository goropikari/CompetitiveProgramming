/*https://atcoder.jp/contests/abc398/tasks/abc398_e*/
/*2025年03月22日 22時06分58秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    using P = pair<int, int>;
    set<P> memo;
    int n;
    cin >> n;
    vvint graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        memo.insert({u, v});
        memo.insert({v, u});
    }

    vint depth(n, 0);
    auto dfs = [&](auto dfs, int now, int p = -1) -> void {
        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            depth[nx] = depth[now] + 1;
            dfs(dfs, nx, now);
        }
    };
    dfs(dfs, 0);

    set<P> es;
    int cnt = 0;
    rep(i, n) {
        rep2(j, i + 1, n) {
            if (memo.count({i, j}))
                continue;
            if ((depth[i] + depth[j]) % 2 == 1) {
                cnt++;
                es.insert({i, j});
            }
        }
    }

    if (cnt % 2 == 1) {
        cout << "First" << endl;
        cout << flush;
        auto it = es.begin();
        cout << it->first + 1 << ' ' << it->second + 1 << endl;
        cout << flush;
        es.erase(it);
    } else {
        cout << "Second" << endl;
        cout << flush;
    }

    while (es.size()) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v)
            swap(u, v);
        es.erase({u, v});

        auto it = es.begin();
        auto [nu, nv] = *it;
        es.erase(it);
        cout << nu + 1 << ' ' << nv + 1 << endl;
        cout << flush;
    }

    int u, v;
    cin >> u >> v;
    if (u == -1 && v == -1) {
        return;
    }
}

