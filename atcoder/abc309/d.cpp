/*https://atcoder.jp/contests/abc309/tasks/abc309_d*/
/*2025年01月24日 01時51分24秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

void depthsearch(vll& dist, vvint& graph, int s) {
    queue<int> que;
    que.push(s);
    vint visited(dist.size());
    dist = vll(dist.size(), INF);
    dist[s] = 0;

    while (que.size()) {
        int now = que.front();
        que.pop();

        if (visited[now])
            continue;
        visited[now] = 1;

        for (int nx : graph[now]) {
            if (visited[nx])
                continue;
            if (dist[nx] > dist[now] + 1) {
                chmin(dist[nx], dist[now] + 1);
                que.push(nx);
            }
        }
    }
}

void solve() {
    ll n1, n2, M;
    cin >> n1 >> n2 >> M;

    vvint graph(n1 + n2);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vll dist1(n1), dist2(n1 + n2);

    depthsearch(dist1, graph, 0);
    depthsearch(dist2, graph, n1 + n2 - 1);

    rep(i, n1) dist2[i] = 0;

    cout << (*max_element(all(dist1)) + *max_element(all(dist2)) + 1) << endl;
}
