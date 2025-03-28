// https://atcoder.jp/contests/typical90/tasks/typical90_c
/*2025年03月17日 01時23分22秒*/
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

    int n;
    cin >> n;
    vvint graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vll dist(n, -1);
    ll mi = -1, md = -1;
    dist[0] = 0;

    auto dfs = [&](auto dfs, int now, int p) -> void {
        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            dist[nx] = dist[now] + 1;
            if (md < dist[nx]) {
                md = dist[nx];
                mi = nx;
            }
            dfs(dfs, nx, now);
        }
    };

    dfs(dfs, 0, -1);
    dist = vll(n, -1);
    dist[mi] = 0;
    dfs(dfs, mi, -1);

    md = *max_element(all(dist));
    cout << md + 1 << endl;
}
