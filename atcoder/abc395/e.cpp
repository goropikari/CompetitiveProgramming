/*https://atcoder.jp/contests/abc395/tasks/abc395_e*/
/*2025年03月01日 21時59分29秒*/
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
    ll N, M, X;
    cin >> N >> M >> X;

    vector<vector<Edge>> graph(2 * N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back({v, 1});
        graph[v + N].push_back({u + N, 1});
    }
    rep(i, N) {
        graph[i].push_back({i + N, X});
        graph[i + N].push_back({i, X});
    }

    // cost, pos
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    vll dist(N * 2, INF);
    dist[0] = 0;
    while (pq.size()) {
        auto [cost, pos] = pq.top();
        pq.pop();

        if (dist[pos] < cost)
            continue;

        for (auto [to, cost] : graph[pos]) {
            if (dist[to] <= dist[pos] + cost)
                continue;
            dist[to] = dist[pos] + cost;
            pq.push({dist[to], to});
        }
    }

    cout << min(dist[N - 1], dist[N * 2 - 1]) << endl;
}
