// https://atcoder.jp/contests/arc212/tasks/arc212_b
// Sun 11 Jan 2026 11:37:04 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

    // cost, to
    using Edge = pair<ll, ll>;

    ll N, M;
    cin >> N >> M;

    int s, f, init_c;

    vector<vector<Edge>> graph(N);
    rep(i, M) {
        ll x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        if (i == 0) {
            s = x, f = y, init_c = c;
        }
        graph[x].push_back({c, y});
    }

    // cost, now
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;

    vll dist(N, INF);
    dist[f] = 0;
    pq.push({0, f});

    while (pq.size()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [c, nx] : graph[now]) {
            if (dist[nx] <= c + cost) continue;
            dist[nx] = c + cost;
            pq.push({dist[nx], nx});
        }
    }

    ll ans = init_c + dist[s];
    if (dist[s] == INF) ans = -1;

    cout << ans << endl;
}
