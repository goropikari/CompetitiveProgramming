// https://atcoder.jp/contests/awc0017/tasks/awc0017_d
// Sat 07 Mar 2026 02:11:21 AM JST
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

    ll N, M, K;
    cin >> N >> M >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    vvll B(N, vll(N));
    rep(i, M) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        B[u][v] = B[v][u] = b;
    }

    ll ans = -INF;

    auto dfs = [&](auto dfs, int state, int l, vint v) -> void {
        if ((ll)v.size() == K) {
            ll sum = 0;
            for (int i : v) sum += A[i];
            rep(i, K) rep2(j, i + 1, K) {
                sum -= B[v[i]][v[j]];
            }
            chmax(ans, sum);
            return;
        }

        rep2(i, l, N) {
            if (!(state >> i & 1)) {
                v.pb(i);
                dfs(dfs, state | 1 << i, i + 1, v);
                v.pop_back();
            }
        }
    };

    dfs(dfs, 0, 0, vint());

    cout << ans << endl;
}
