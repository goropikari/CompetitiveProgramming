// https://atcoder.jp/contests/abc419/tasks/abc419_e
// 2025年08月16日 21時31分16秒
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

    ll N, M, L;
    cin >> N >> M >> L;
    vll A(N);
    rep(i, N) cin >> A[i];

    // cost[i][r]: i 文字目を M で割った余りを r にするのにかかるコスト
    vector cost(L + 1, vll(M));
    rep(i, L) {
        for (int j = i; j < N; j += L) {
            rep(k, M) {
                cost[i + 1][(A[j] + k) % M] += k;
            }
        }
    }

    // dp[i][r]: i 文字目まで見たときの和の mod M が r となるときのコスト
    vector dp(L + 1, vll(M, INF));
    rep(i, M) dp[0][0] = 0;
    rep2(i, 1, L + 1) {
        rep(j, M) rep(k, M) {
            chmin(dp[i][(j + k) % M], dp[i - 1][j] + cost[i][k]);
        }
    }
    cout << dp[L][0] << endl;
}
