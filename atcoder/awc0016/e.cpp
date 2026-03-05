// https://atcoder.jp/contests/awc0016/tasks/awc0016_e
// Thu 05 Mar 2026 09:03:58 PM JST
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
    vll P(N);
    rep(i, N) cin >> P[i];

    ll S, T;
    cin >> S >> T;
    S--, T--;

    // id, cost
    using PR = pair<ll, ll>;
    vector<vector<PR>> to(N);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        to[u].pb({v, w});
        to[v].pb({u, w});
    }

    vvll dp(1 << N, vll(N, -INF));
    dp[1 << S][S] = P[S];

    // cost, state, now
    using Pq = tuple<ll, ll, ll>;
    priority_queue<Pq> pq;
    pq.push({P[S], 1 << S, S});
    while (pq.size()) {
        auto [cost, state, now] = pq.top();
        pq.pop();

        if (dp[state][now] < cost) continue;

        for (auto [nx, w] : to[now]) {
            if (state >> nx & 1) {
                if (chmax(dp[state][nx], dp[state][now] - w)) {
                    pq.push({dp[state][nx], state, nx});
                }
            } else {
                int nxstate = state | 1 << nx;
                if (chmax(dp[nxstate][nx], dp[state][now] + P[nx] - w)) {
                    pq.push({dp[nxstate][nx], nxstate, nx});
                }
            }
        }
    }

    ll ans = -INF;
    rep(state, 1 << N) {
        if (state >> T & 1) {
            chmax(ans, dp[state][T]);
        }
    }

    cout << ans << endl;
}
