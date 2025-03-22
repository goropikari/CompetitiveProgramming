/*http://localhost:5173/problem/shortest_path*/
/*2025年03月22日 14時04分03秒*/
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
    int to;
    ll cost;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<Edge>> graph(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vll dist(n, INF);
    dist[s] = 0;

    // cost, id
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    vint from(n);
    from[s] = -1;

    while (pq.size()) {
        auto [cost, i] = pq.top();
        pq.pop();

        if (dist[i] < cost)
            continue;

        for (auto [ni, w] : graph[i]) {
            if (dist[ni] <= dist[i] + w)
                continue;
            dist[ni] = dist[i] + w;
            from[ni] = i;
            pq.push({dist[ni], ni});
        }
    }

    if (dist[t] == INF) {
        cout << -1 << '\n';
        return;
    }

    vint ans;
    int now = t;
    while (now != -1) {
        ans.push_back(now);
        now = from[now];
    }

    reverse(all(ans));

    int ne = (int)ans.size() - 1;
    cout << dist[t] << ' ' << ne << '\n';
    rep(i, ne) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
}
