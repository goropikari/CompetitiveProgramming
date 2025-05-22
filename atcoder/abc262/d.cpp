// https://atcoder.jp/contests/abc262/tasks/abc262_d
// 2025年05月22日 19時25分35秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    vvll mod(N + 1, vll(N));
    rep2(m, 1, N + 1) rep(i, N) {
        mod[m][i] = A[i] % m;
    }

    mint ans = 0;
    rep2(m, 1, N + 1) {
        vector dp(vector(N + 1, vector(N + 1, vector<mint>(N))));
        rep(i, N) {
            dp[i][0][0] = 1;
        }

        rep2(i, 1, N + 1) {
            rep2(j, 1, N + 1) {
                rep(k, m) {
                    // i 番目の数字を選ばない
                    dp[i][j][k] += dp[i - 1][j][k];

                    // i 番目の数字を選ぶ
                    dp[i][j][k] += dp[i - 1][j - 1][(m - mod[m][i - 1] + k) % m];
                }
            }
        }
        ans += dp[N][m][0];
    }

    cout << ans.val() << endl;
}
