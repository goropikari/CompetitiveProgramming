// https://atcoder.jp/contests/abc192/tasks/abc192_e
// 2025年04月09日 00時11分52秒
#include <bits/stdc++.h>
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

struct Edge {
    ll to, t, k;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    X--, Y--;
    vector<vector<Edge>> graph(N);
    rep(i, M) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--, b--;
        graph[a].push_back({b, t, k});
        graph[b].push_back({a, t, k});
    }

    vll dist(N, INF);
    dist[X] = 0;
    // cost, now
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, X});
    while (pq.size()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost)
            continue;

        for (auto [nx, t, k] : graph[now]) {
            ll newd = (cost + k - 1) / k * k + t;
            if (dist[nx] <= newd)
                continue;
            dist[nx] = newd;
            pq.push({newd, nx});
        }
    }

    ll ans = -1;
    if (dist[Y] != INF)
        ans = dist[Y];
    cout << ans << endl;
}
