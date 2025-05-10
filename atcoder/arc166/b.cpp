// https://atcoder.jp/contests/arc166/tasks/arc166_b
// 2025年05月10日 01時56分29秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, a, b, c;
    cin >> N >> a >> b >> c;

    vll X(N + 1);
    rep(i, N) cin >> X[i + 1];

    vvll rem(N + 1, vll(8));

    rep2(i, 1, N + 1) {
        rep(x, 2) rep(y, 2) rep(z, 2) {
            ll mul = 1;
            if (x)
                mul = lcm(mul, a);
            if (y)
                mul = lcm(mul, b);
            if (z)
                mul = lcm(mul, c);
            ll add = (mul - X[i] % mul) % mul;
            ll t = 1 * x + 2 * y + 4 * z;
            rem[i][t] = add;
        }
    }

    vvll dp(N + 1, vll(8, INF));
    dp[0][0] = 0;

    rep2(i, 1, N + 1) {
        rep(p, 8) rep(q, 8) {
            ll t = p | q;
            chmin(dp[i][t], dp[i - 1][p] + rem[i][q]);
        }
    }

    ll ans = INF;
    rep2(i, 1, N + 1) chmin(ans, dp[i][7]);
    cout << ans << endl;
}
