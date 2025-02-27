/*https://atcoder.jp/contests/abc291/tasks/abc291_e*/
/*2025年02月26日 20時45分44秒*/
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
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> es;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        es.insert({u, v});
    }

    vvint graph(n), rgraph(n);
    for (auto [u, v] : es) {
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    int sid = -1;
    {
        int cnt = 0;
        rep(i, n) {
            if (rgraph[i].size() == 0) {
                cnt++;
                sid = i;
            }
        }
        if (cnt > 1 || sid == -1) {
            yesno(false);
            return;
        }
    }

    vint track;
    vint visited(n, 0), tmpmark(n, 0);
    auto dfs = [&](auto dfs, int now) -> void {
        if (tmpmark[now]) {
            yesno(false);
            exit(0);
        }

        if (visited[now])
            return;

        tmpmark[now] = 1;
        for (int nx : graph[now]) {
            dfs(dfs, nx);
        }
        visited[now] = 1;
        tmpmark[now] = 0;
        track.push_back(now);
    };

    dfs(dfs, sid);
    reverse(all(track));
    rep(i, n - 1) {
        if (!es.count({track[i], track[i + 1]})) {
            yesno(false);
            return;
        }
    }

    vint ans(n);
    rep(i, n) {
        ans[track[i]] = i + 1;
    }
    yesno(true);
    print(ans);
}
