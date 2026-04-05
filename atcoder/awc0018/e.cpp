// https://atcoder.jp/contests/awc0018/tasks/awc0018_e
// Tue 31 Mar 2026 12:08:18 AM JST
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

    ll N, K, B;
    cin >> N >> K >> B;

    vll C(N + 1), S(N + 1);
    rep2(i, 1, N + 1) cin >> C[i] >> S[i];

    // dp[i][j][k]: i 番目までの山で j 個の山を登って最後に訪れた山が k のときの入山料の合計の最小値
    vector dp(K + 1, vll(N + 1, INF));
    dp[0][0] = 0;

    rep2(k, 1, N + 1) {
        vvll dpn = dp;
        rep(pr, k) {
            rep(j, K) {
                if (S[pr] < S[k])
                    chmin(dpn[j + 1][k], dp[j][pr] + C[k]);
            }
        }
        swap(dpn, dp);
    }

    ll ans = 0;
    rep(k, K + 1) rep2(i, 1, N + 1) {
        if (dp[k][i] <= B) chmax(ans, k);
    }
    cout << ans << endl;
}
