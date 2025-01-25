/*https://atcoder.jp/contests/abc362/tasks/abc362_d*/
/*2025年01月25日 12時35分15秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <queue>
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
    int to;
    long long int weight;
};

bool operator>(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}

using Graph = vector<vector<Edge>>;

struct Dijkstra {
    int n;  // ノード数
    Graph graph;
    vector<long long int> dist;  // start からの最短距離
    vector<int> from;            // from[i]: i 番目のノードにどこから来たか
    int start = -1;

    Dijkstra(int n) : n(n), graph(n), dist(n, INF), from(n, -1) {}

    void add_edge(int from, int to, long long int weight) {
        graph[from].push_back({to, weight});
    }

    void run(int start) {
        dist[start] = 0;
        this->start = start;

        // cost, node
        using P = pair<long long int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, start});

        while (pq.size()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (dist[node] < cost)
                continue;

            for (auto [to, weight] : graph[node]) {
                if (dist[to] > dist[node] + weight) {
                    dist[to] = dist[node] + weight;
                    from[to] = node;
                    pq.push({dist[to], to});
                }
            }
        }
    }

    // start から fin までの最短距離.  到達不可のときは -1 を返す
    long long int distance(int fin) {
        if (dist[fin] == INF)
            return -1;
        return dist[fin];
    }

    // start -> fin への経路
    vector<int> path(int fin) {
        vector<int> ans = {fin};
        int now = fin;
        while (now != start) {
            now = from[now];
            ans.push_back(now);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) cin >> A[i];

    Dijkstra graph(N);
    rep(i, M) {
        int u, v;
        ll B;
        cin >> u >> v >> B;
        u--, v--;
        graph.add_edge(u, v, B + A[v]);
        graph.add_edge(v, u, B + A[u]);
    }

    graph.run(0);

    vll ans;
    rep2(i, 1, N) ans.push_back(A[0] + graph.distance(i));
    print(ans);
}
