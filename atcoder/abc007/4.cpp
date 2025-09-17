// https://atcoder.jp/contests/abc007/tasks/abc007_4
// 2025年09月14日 18時39分07秒
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

    auto f = [](ll X) -> ll {
        string S = to_string(X);
        int N = S.size();

        // dp[is_less][used_banned_number]
        vector dp(2, vll(2));
        dp[0][0] = 1;

        rep(i, N) {
            int t = S[i] - '0';
            vector dpn(2, vll(2));

            rep(d, 10) rep(is_less, 2) rep(used, 2) {
                if (!is_less && d > t) continue;

                int is_less_n = is_less || d < t;
                int used_n = used || d == 4 || d == 9;
                dpn[is_less_n][used_n] += dp[is_less][used];
            }

            swap(dp, dpn);
        }

        return dp[0][1] + dp[1][1];
    };

    ll A, B;
    cin >> A >> B;

    cout << f(B) - f(A - 1) << endl;
}
