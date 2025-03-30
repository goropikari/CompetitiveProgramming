// https://atcoder.jp/contests/typical90/tasks/typical90_m
/*2025年03月28日 20時37分44秒*/
#include <bits/stdc++.h>
#include <queue>
// #include <atcoder/all>
// using namespace atcoder;
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

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vvll dists(2);
    vint nows = {0, n - 1};

    rep(k, 2) {
        int now = nows[k];

        vll dist(n, INF);
        dist[now] = 0;

        // dist, id
        using P = pair<ll, ll>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, now});
        while (pq.size()) {
            auto [cost, id] = pq.top();
            pq.pop();

            if (dist[id] < cost)
                continue;

            for (auto [nx, w] : graph[id]) {
                if (dist[nx] <= dist[id] + w)
                    continue;

                dist[nx] = dist[id] + w;
                pq.push({dist[nx], nx});
            }
        }

        dists[k] = dist;
    }

    rep(i, n) {
        cout << dists[0][i] + dists[1][i] << endl;
    }
}
