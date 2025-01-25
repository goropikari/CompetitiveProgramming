/*https://atcoder.jp/contests/abc340/tasks/abc340_d*/
/*2025年01月24日 22時29分53秒*/
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
    ll to, cost;
};

bool operator>(const Edge& a, const Edge& b) {
    return a.cost > b.cost;
}

void solve() {
    int N;
    cin >> N;
    vll A(N - 1), B(N - 1), X(N - 1);
    rep(i, N - 1) {
        cin >> A[i] >> B[i] >> X[i];
        X[i]--;
    }

    map<pair<int, int>, ll> mp;

    vector<vector<Edge>> graph(N);
    rep(i, N - 1) {
        graph[i].push_back({i + 1, A[i]});
        graph[i].push_back({X[i], B[i]});
    }

    vll dist(N, INF);
    vint visited(N, 0);
    dist[0] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // node, cost
    pq.push({0, 0});
    while (pq.size()) {
        auto [now, _] = pq.top();
        pq.pop();
        if (visited[now])
            continue;
        visited[now] = 1;

        for (auto [to, cost] : graph[now]) {
            if (dist[to] > dist[now] + cost) {
                dist[to] = dist[now] + cost;
                pq.push({to, dist[to]});
            }
        }
    }
    cout << dist[N - 1] << endl;
}
