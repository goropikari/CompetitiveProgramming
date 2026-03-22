// https://atcoder.jp/contests/awc0029/tasks/awc0029_e
// Thu 19 Mar 2026 08:11:41 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    // to, cost
    using P = pair<ll, ll>;
    vector<vector<P>> graph(N);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(v, w);
    }

    ll S, K;
    cin >> S >> K;
    S--;

    vll T(K);
    rep(i, K) {
        cin >> T[i];
        T[i]--;
    }

    vvll dist(N, vll(N, INF));
    rep(i, N) dist[i][i] = 0;
    rep(now, N) {
        for (auto [nx, w] : graph[now]) {
            dist[now][nx] = w;
        }
    }
    rep(k, N) rep(i, N) rep(j, N) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    K++;
    vector<vector<P>> to(K);
    T.insert(T.begin(), S);

    rep(i, K) rep(j, K) {
        if (i == j) continue;
        int u = T[i], v = T[j];
        if (dist[u][v] != INF) to[i].pb({j, dist[u][v]});
    }

    vvll dp(K, vll(1 << K, INF));
    dp[0][0] = 0;

    // cost, now, visited
    using F = tuple<ll, ll, ll>;
    priority_queue<F, vector<F>, greater<F>> pq;
    pq.push({0, 0, 0});

    while (pq.size()) {
        auto [cost, now, vis] = pq.top();
        pq.pop();

        if (dp[now][vis] < cost) continue;

        for (auto [nx, w] : to[now]) {
            ll nxvis = vis;
            nxvis = vis | (1 << nx);
            if (dp[nx][nxvis] <= cost + w) continue;
            dp[nx][nxvis] = cost + w;
            pq.push({cost + w, nx, nxvis});
        }
    }

    ll ans = -1;
    if (dp[0][(1 << K) - 1] != INF) ans = dp[0][(1 << K) - 1];
    cout << ans << endl;
}
