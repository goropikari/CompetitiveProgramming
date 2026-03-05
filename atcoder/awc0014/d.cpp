// https://atcoder.jp/contests/awc0014/tasks/awc0014_d
// Thu 26 Feb 2026 08:29:30 PM JST
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

    ll N, M, T;
    cin >> N >> M >> T;
    T--;

    using P = pair<ll, ll>;
    vector<vector<P>> graph(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    vll dist(N, INF);
    dist[0] = 0;

    // cost, now
    using PP = pair<ll, int>;
    priority_queue<PP, vector<PP>, greater<PP>> pq;
    pq.push({0, 0});
    while (pq.size()) {
        auto [sum, now] = pq.top();
        pq.pop();

        if (dist[now] < sum) continue;

        for (auto [nx, cost] : graph[now]) {
            if (dist[nx] > sum + cost) {
                dist[nx] = sum + cost;
                pq.push({sum + cost, nx});
            }
        }
    }

    ll ans = -1;
    if (dist[T] != INF) ans = dist[T] * 2;
    cout << ans << endl;
}
