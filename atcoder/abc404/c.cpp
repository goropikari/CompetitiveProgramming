// https://atcoder.jp/contests/abc404/tasks/abc404_c
// 2025年05月03日 21時08分45秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    if (M != N) {
        yesno(false);
        return;
    }

    vector<pair<int, int>> es;

    vvint graph(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        es.emplace_back(u, v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ok = 1;
    rep(i, N) if (graph[i].size() != 2) ok = 0;
    if (!ok) {
        yesno(false);
        return;
    }

    dsu uf(N);

    for (auto [u, v] : es) {
        if (uf.same(u, v)) {
            uf.merge(u, v);
            // 連結かチェック
            yesno(uf.size(u) == N);
            return;
        }
        uf.merge(u, v);
    }
    yesno(false);
}
