// https://atcoder.jp/contests/abc387/tasks/abc387_c
// 2025年06月09日 16時10分05秒
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

    ll L, R;
    cin >> L >> R;

    auto cal = [](string S) -> ll {
        int N = S.size();

        // dp[head][is_less][zero seq 続く]
        vector dp(10, vector(2, vll(2, 0)));
        dp[0][1][1] = 1;
        rep2(i, 1, S[0] - '0') dp[i][1][0] = 1;
        dp[S[0] - '0'][0][0] = 1;
        rep2(i, 1, N) {
            int t = S[i] - '0';
            vector dpn(10, vector(2, vll(2, 0)));
            rep(head, 10) {
                rep(is_less, 2) {
                    rep(zero_seq, 2) {
                        rep(nx, 10) {
                            if (!zero_seq && head <= nx) continue;  // ヘビ数を満たさない
                            if (!is_less && nx > t) continue;       // S を超える
                            int is_less_n = is_less || nx < t;
                            int zero_seq_n = zero_seq && nx == 0;
                            int headn = (zero_seq && nx != 0) ? nx : head;
                            dpn[headn][is_less_n][zero_seq_n] += dp[head][is_less][zero_seq];
                        }
                    }
                }
            }
            swap(dp, dpn);
        }

        ll ans = 0;
        rep(i, 10) rep(is_less, 2) ans += dp[i][is_less][0];
        return ans;
    };

    cout << cal(to_string(R)) - cal(to_string(L - 1)) << endl;
}
