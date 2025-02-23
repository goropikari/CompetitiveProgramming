/*https://atcoder.jp/contests/abc282/tasks/abc282_d*/
/*2025年02月21日 06時31分03秒*/
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

struct Group {
    vint zeros, ones;
};

void solve() {
    int N, M;
    cin >> N >> M;

    vvint graph(N);
    vector<pair<int, int>> es;
    dsu uf(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        uf.merge(u, v);
        es.push_back({u, v});
    }

    vint col(N, -1);

    auto dfs = [&](auto dfs, int now, int p, int c) -> bool {
        bool ok = true;
        col[now] = c;
        for (int nx : graph[now]) {
            if (nx == p)
                continue;
            if (col[nx] == c) {
                return false;
            }
            if (col[nx] == -1)
                ok = ok && dfs(dfs, nx, now, 1 - c);
        }
        return ok;
    };

    rep(i, N) {
        if (col[i] == -1) {
            if (!dfs(dfs, i, -1, 0)) {
                cout << 0 << endl;
                return;
            };
        }
    }

    ll ans = 0;

    // 異なる二部グラフ間で辺を張る
    {
        ll sz = 0, tmp = 0;
        for (auto v : uf.groups()) {
            tmp += sz * v.size();
            sz += v.size();
        }
        ans += tmp;
    }

    // 単一の二部グラフに辺を追加する
    map<int, ll> numes;
    for (auto [u, v] : es) {
        int l = uf.leader(u);
        numes[l]++;
    }
    for (auto v : uf.groups()) {
        ll no = 0, nz = 0;
        for (int x : v) {
            if (col[x] == 0)
                nz++;
            if (col[x] == 1)
                no++;
        }
        int l = uf.leader(v[0]);
        ans += no * nz - numes[l];
    }

    cout << ans << endl;
}
