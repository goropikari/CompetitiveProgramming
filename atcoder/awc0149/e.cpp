// https://atcoder.jp/contests/awc0149/tasks/awc0149_e
// Sat 05 Sep 2026 09:44:08 PM JST
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
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
    }
    cout << endl;
}

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v)
        cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
template <typename T>
T ceil(T a, T b) { return (a + b - 1) / b; }

// floor(a/b)
template <typename T>
T floor(T a, T b) { return a / b; }

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

    // next, weight
    vector<vector<pair<ll, ll>>> to(N);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        to[u].pb({v, w});
        to[v].pb({u, w});
    }

    vll C(K + 2);
    rep2(i, 1, K + 1) {
        cin >> C[i];
        C[i]--;
    }
    C[K + 1] = N - 1;
    K += 2;

    auto dij = [&](ll s) -> vll {
        vll dist(N, INF);
        dist[s] = 0;

        // cost, pos
        using P = pair<ll, ll>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, s});

        while (pq.size()) {
            auto [cost, pos] = pq.top();
            pq.pop();

            if (dist[pos] < cost) continue;
            for (auto [nx, weight] : to[pos]) {
                ll tmp = cost + weight;
                if (dist[nx] <= tmp) continue;
                dist[nx] = tmp;
                pq.push({tmp, nx});
            }
        }

        return dist;
    };

    vvll td(K, vll(N, INF));
    rep(i, K) {
        td[i] = dij(C[i]);
    }

    vvll dists(K, vll(K, INF));
    rep(i, K) rep(j, K) {
        dists[i][j] = td[i][C[j]];
    }

    rep(j, K) rep(i, K) rep(k, K) {
        chmin(dists[i][k], dists[i][j] + dists[j][k]);
    }

    vvll min_dist(1 << K, vll(K, INF));
    min_dist[1][0] = 0;
    rep(state, 1 << K) rep(pr, K) rep(nx, K) {
        if (pr == nx) continue;
        if (!((state >> pr) & 1)) continue;
        if (((state >> nx) & 1)) continue;
        chmin(min_dist[state | (1 << nx)][nx], min_dist[state][pr] + dists[pr][nx]);
    }

    cout << min_dist[(1 << K) - 1][K - 1] << endl;
}
