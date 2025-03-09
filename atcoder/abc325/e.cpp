/*https://atcoder.jp/contests/abc325/tasks/abc325_e*/
/*2025年03月10日 01時03分37秒*/
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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vvll D(n, vll(n));
    rep(i, n) rep(j, n) cin >> D[i][j];

    vector<vector<Edge>> graph(n * 2);
    rep(i, n) rep(j, n) {
        if (i == j)
            continue;
        graph[i].push_back({j, D[i][j] * a});
        graph[j].push_back({i, D[i][j] * a});
        graph[n + i].push_back({n + j, D[i][j] * b + c});
        graph[n + j].push_back({n + i, D[i][j] * b + c});
    }
    rep(i, n) graph[i].push_back({n + i, 0});

    vll dist(n * 2, INF);
    dist[0] = 0;

    // cost, pos
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});
    while (pq.size()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost)
            continue;

        for (auto [to, cost] : graph[now]) {
            if (dist[to] <= dist[now] + cost)
                continue;

            dist[to] = dist[now] + cost;
            pq.push({dist[to], to});
        }
    }

    cout << min(dist[n - 1], dist[n * 2 - 1]) << '\n';
}
