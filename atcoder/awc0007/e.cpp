// https://atcoder.jp/contests/awc0007/tasks/awc0007_e
// Sun 01 Mar 2026 03:29:44 PM JST
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

    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--, T--;
    vll P(M + 2);
    rep(i, M) {
        cin >> P[i + 1];
        P[i + 1]--;
    }

    P[0] = S;
    P[M + 1] = T;

    vector<pair<ll, ll>> pos;
    for (auto x : P) {
        pos.emplace_back(x / N, x % N);
    }

    vvll dp(1 << (M + 2), vll(M + 2, INF));
    dp[1][0] = 0;

    rep2(state, 1, 1 << (M + 2)) {
        rep(pr, M + 2) {
            if (state >> pr & 1) {
                rep(nx, M + 2) {
                    if (state >> nx & 1) continue;
                    auto [r1, c1] = pos[pr];
                    auto [r2, c2] = pos[nx];

                    ll cost = abs(r1 - r2) + abs(c1 - c2);
                    chmin(dp[state | (1 << nx)][nx], dp[state][pr] + cost);
                }
            }
        }
    }

    cout << dp[(1 << (M + 2)) - 1][M + 1] << endl;
}
