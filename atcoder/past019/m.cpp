// https://atcoder.jp/contests/past19-open/tasks/past19_m
// 2025年04月21日 22時01分50秒
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

struct Edge {
    ll to;
    double w;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vll P(N);
    rep(i, N) cin >> P[i];

    vector<vector<Edge>> graph(N);
    rep(i, M) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        u--, v--;
        graph[v].push_back({u, w});
    }

    vector<double> score(N, 0.0);
    score[N - 1] = P.back();
    score[0] = -1;
    // cost, position
    priority_queue<tuple<double, int>> pq;

    // N-1 から 0 に向かって進める
    pq.push({P.back(), N - 1});
    while (pq.size()) {
        auto [sc, now] = pq.top();
        pq.pop();

        if (score[now] > sc)
            continue;
        for (auto [nx, w] : graph[now]) {
            double new_sc = sc * w + (double)P[nx];
            if (score[nx] >= new_sc)
                continue;
            score[nx] = new_sc;
            pq.push({new_sc, nx});
        }
    }

    double ans = score[0];
    if (score[0] < 0.0) {
        cout << -1 << endl;
        return;
    }
    printf("%.9lf\n", ans);
}
