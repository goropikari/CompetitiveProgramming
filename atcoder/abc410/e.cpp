// https://atcoder.jp/contests/abc410/tasks/abc410_e
// 2025年06月14日 21時46分58秒
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
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

void yesno(bool x) {
    cout << (x ? "Yes" : "No") << '\n';
}

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, H, M;
    cin >> N >> H >> M;
    vll A(N + 1), B(N + 1);
    rep(i, N) cin >> A[i + 1] >> B[i + 1];

    vector dp(N + 1, vll(M + 1, -1));
    dp[0][M] = H;

    rep2(i, 1, N + 1) {
        rep(m, M + 1) {
            if (m + B[i] <= M) {
                chmax(dp[i][m], dp[i - 1][m + B[i]]);
            }
            chmax(dp[i][m], dp[i - 1][m] - A[i]);
        }
    }

    ll ans = 0;
    rep(i, N + 1) rep(m, M + 1) {
        if (dp[i][m] >= 0) ans = i;
    }
    cout << ans << endl;
}
