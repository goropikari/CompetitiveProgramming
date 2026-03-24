// https://atcoder.jp/contests/awc0031/tasks/awc0031_c
// Tue 24 Mar 2026 01:10:51 AM JST
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

    ll N, D, S, T;
    cin >> N >> D >> S >> T;
    S--, T--;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    // to, cost
    using P = pair<ll, ll>;
    vvint to(N);
    rep(i, N) rep2(j, i + 1, N) {
        ll dx = X[i] - X[j];
        ll dy = Y[i] - Y[j];
        if (dx * dx + dy * dy <= D * D) {
            to[i].pb(j);
            to[j].pb(i);
        }
    }

    vll dist(N, INF);
    dist[S] = 0;

    queue<pair<ll, ll>> que;
    que.emplace(S, 0);
    while (que.size()) {
        auto [now, d] = que.front();
        que.pop();

        if (dist[now] < d) continue;

        for (int nx : to[now]) {
            if (dist[nx] <= d + 1) continue;
            dist[nx] = d + 1;
            que.emplace(nx, d + 1);
        }
    }

    ll ans = -1;
    if (dist[T] != INF) ans = dist[T];
    cout << ans << endl;
}
