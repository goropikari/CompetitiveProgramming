// https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d
// 2025年09月15日 04時34分42秒
// https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d
// 2025年09月15日 04時34分42秒
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

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, K;
    cin >> A >> K;

    string S = to_string(A);

    // dp[comp][used]
    // comp = 0: A と同じ
    // comp = 1: A より小さい
    // comp = 2: A より大きい
    // used: 使用した数の集合
    vector dp(3, vll(1 << 10, -1));
    dp[0][0] = 0;
    rep(j, 1 << 10) dp[2][j] = INF;

    int N = S.size();
    rep(i, N) {
        int t = S[i] - '0';
        vector dpn(3, vll(1 << 10, -1));
        rep(j, 1 << 10) dpn[2][j] = INF;

        rep(d, 10) rep(comp, 3) rep(used, 1 << 10) {
            if (dp[comp][used] < 0) continue;
            if (dp[comp][used] == INF) continue;
            int comp_n = comp;
            if (comp == 0) {
                if (d < t) comp_n = 1;
                if (d > t) comp_n = 2;
            }

            int used_n = used | (1 << d);
            if (used == 0 && d == 0) used_n = 0;  // 0 が続いている場合は 0 を使っていないとみなす

            if (comp_n <= 1) {
                chmax(dpn[comp_n][used_n], dp[comp][used] * 10 + d);
            } else {
                chmin(dpn[comp_n][used_n], dp[comp][used] * 10 + d);
            }
        }

        swap(dp, dpn);
    }

    ll ans = INF;
    {
        ll mx = 0;
        ll mi = INF;
        rep(used, 1 << 10) {
            if (__builtin_popcountll(used) > K) continue;
            chmax(mx, max(dp[0][used], dp[1][used]));
            chmin(mi, dp[2][used]);
        }
        chmin(ans, A - mx);
        chmin(ans, mi - A);
    }

    cout << ans << endl;
}
