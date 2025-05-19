// https://atcoder.jp/contests/abc299/tasks/abc299_e
// 2025年05月20日 00時02分58秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18 + 9;
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

    int N, M;
    cin >> N >> M;
    vvint graph(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int K;
    cin >> K;
    vector<pair<int, int>> ps;
    rep(i, K) {
        int p, d;
        cin >> p >> d;
        p--;
        ps.push_back({p, d});
    }

    auto short_path = [](vvint& graph, int start) -> vint {
        int N = graph.size();
        vint dist(N, INF);
        dist[start] = 0;

        // cost, position
        using P = pair<ll, int>;
        deque<P> deq;
        deq.push_back({0, start});
        while (deq.size()) {
            auto [cost, now] = deq.front();
            deq.pop_front();

            if (dist[now] < cost)
                continue;

            for (int nx : graph[now]) {
                if (dist[nx] <= cost + 1)
                    continue;
                dist[nx] = cost + 1;
                deq.push_back({cost + 1, nx});
            }
        }

        return dist;
    };

    vvint dists(N);
    rep(i, N) {
        dists[i] = short_path(graph, i);
    }

    // 一旦全ての頂点を黒く塗る
    vint black(N, 1);

    // 頂点 p から d より近いところにある黒を白く塗り直す
    for (auto [p, d] : ps) {
        rep(i, N) {
            if (dists[p][i] < d)
                black[i] = 0;
        }
    }

    // 各頂点について条件を満たす黒い頂点があるか調べる
    for (auto [p, d] : ps) {
        int ok = 0;
        rep(i, N) {
            if (dists[p][i] == d && black[i])
                ok = 1;
        }
        if (!ok) {
            yesno(false);
            return;
        }
    }

    yesno(true);
    for (int x : black)
        cout << x;
    cout << endl;
}
