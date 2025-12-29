// https://atcoder.jp/contests/abc431/tasks/abc431_d
// Mon 29 Dec 2025 09:40:27 PM JST
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

    ll N;
    cin >> N;
    vll W(N), H(N), B(N);
    rep(i, N) cin >> W[i] >> H[i] >> B[i];

    ll sumb = accumulate(all(B), 0ll);
    ll sumw = accumulate(all(W), 0ll);

    vll dp(500 * 500 + 5, -INF);
    dp[0] = 0;
    rep(k, N) {
        ll w = W[k], h = H[k], b = B[k];
        for (ll i = 500 * 500; i > 0; i--) {
            if (i - w < 0) continue;
            if (dp[i - w] == -INF) continue;
            chmax(dp[i], dp[i - w] + h - b);
        }
    }

    ll ans = sumb;
    rep(w, sumw / 2 + 1) {
        chmax(ans, dp[w] + sumb);
    }
    cout << ans << endl;
}
