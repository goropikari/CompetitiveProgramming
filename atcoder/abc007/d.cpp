// https://atcoder.jp/contests/abc007/tasks/abc007_4
// 2025年06月09日 15時04分23秒
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

    string A, B;
    cin >> A >> B;

    auto cal = [](string S) -> ll {
        int N = S.size();
        vector dp(N + 1, vector(2, vector(2, vll(2))));
        dp[0][0][0][0] = 1;

        rep2(i, 1, N + 1) {
            int t = S[i - 1] - '0';
            rep(d, 10) {
                bool has_four = d == 4;
                bool has_nine = d == 9;
                if (d < t) {
                    rep(fr, 2) rep(ni, 2) {
                        dp[i][1][has_four || fr][has_nine || ni] += dp[i - 1][0][fr][ni];
                    }
                }
                if (t == d) {
                    rep(fr, 2) rep(ni, 2) {
                        dp[i][0][has_four || fr][has_nine || ni] += dp[i - 1][0][fr][ni];
                    }
                }
                rep(fr, 2) rep(ni, 2) {
                    dp[i][1][has_four || fr][has_nine || ni] += dp[i - 1][1][fr][ni];
                }
            }
        }

        ll ret = 0;
        rep(fr, 2) rep(ni, 2) {
            if (fr == 0 && ni == 0) continue;
            ret += dp[N][1][fr][ni] + dp[N][0][fr][ni];
        }

        return ret;
    };
    // cout << cal(B) << endl;
    // cout << cal(A) << endl;

    cout << cal(B) - cal(to_string(stoll(A) - 1)) << endl;
}
