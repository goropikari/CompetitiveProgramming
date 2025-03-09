/*https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A*/
/*2025年03月10日 01時58分38秒*/
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

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<Edge>> graph(n);

    rep(i, m) {
        int u, v;
        ll d;
        cin >> u >> v >> d;

        graph[u].emplace_back(v, d);
    }

    vll dist(n, INF);
    dist[r] = 0;

    // cost, position
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, r});
    while (pq.size()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost)
            continue;

        for (auto [to, w] : graph[now]) {
            if (dist[to] <= dist[now] + w)
                continue;
            dist[to] = dist[now] + w;
            pq.push({dist[to], to});
        }
    }

    rep(i, n) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
}
