// https://atcoder.jp/contests/dp/tasks/dp_j
// 2025年05月24日 12時44分08秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
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
    vint A(N);
    rep(i, N) {
        cin >> A[i];
    }

    vint cnt(4);
    for (int a : A)
        cnt[a]++;

    // dp[i][j][k]: sushi が1個余っている皿が i 枚、2個余っている皿が j 枚、3個余っている皿が k 枚のときの操作回数の期待値
    vector dp(N + 1, vector(N + 1, vector<double>(N + 1, 0)));
    rep(k, N + 1) {
        rep(j, N + 1) {
            rep(i, N + 1) {
                if (i + j + k == 0)
                    continue;
                dp[i][j][k] = N;
                if (i - 1 >= 0)
                    dp[i][j][k] += dp[i - 1][j][k] * i;
                if (j - 1 >= 0 && i + 1 <= N)
                    dp[i][j][k] += dp[i + 1][j - 1][k] * j;
                if (k - 1 >= 0 && j + 1 <= N)
                    dp[i][j][k] += dp[i][j + 1][k - 1] * k;
                dp[i][j][k] /= i + j + k;
            }
        }
    }

    printf("%.9lf\n", dp[cnt[1]][cnt[2]][cnt[3]]);
}
