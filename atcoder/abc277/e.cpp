// https://atcoder.jp/contests/abc277/tasks/abc277_e
// 2025年04月30日 19時40分38秒
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;

    vector<tuple<int, int, int>> es;
    rep(i, M) {
        int u, v, a;
        cin >> u >> v >> a;
        u--, v--;
        es.emplace_back(u, v, a);
    }

    vector<bool> sw(N);
    rep(i, K) {
        int s;
        cin >> s;
        s--;
        sw[s] = true;
    }

    vvint graph(N * 2);
    for (auto [u, v, a] : es) {
        if (a == 1) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        } else {
            graph[u + N].push_back(v + N);
            graph[v + N].push_back(u + N);
        }
        if (sw[u]) {
            graph[u].push_back(u + N);
            graph[u + N].push_back(u);
        }
        if (sw[v]) {
            graph[v].push_back(v + N);
            graph[v + N].push_back(v);
        }
    }

    vll dists(N * 2, INF);
    dists[0] = 0;

    // cost, position
    deque<pair<ll, ll>> dq;
    dq.push_back({0, 0});
    while (dq.size()) {
        auto [cost, now] = dq.front();
        dq.pop_front();

        if (dists[now] < cost)
            continue;

        for (int nx : graph[now]) {
            ll d = cost;
            int add = 0;
            if (abs(nx - now) != N) {
                d++;
                add++;
            }
            if (dists[nx] <= d)
                continue;
            dists[nx] = d;
            if (add)
                dq.push_back({d, nx});
            else
                dq.push_front({d, nx});
        }
    }

    ll ans = INF;
    chmin(ans, dists[N - 1]);
    chmin(ans, dists[N * 2 - 1]);
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
