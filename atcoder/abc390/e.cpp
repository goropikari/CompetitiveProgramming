/*https://atcoder.jp/contests/abc390/tasks/abc390_e*/
/*2025年01月25日 23時04分27秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll N, X;
    cin >> N >> X;

    vll V(N + 1), A(N + 1), C(N + 1);
    rep(i, N) {
        cin >> V[i + 1] >> A[i + 1] >> C[i + 1];
        V[i + 1]--;
    }

    // dp[i][cal][kind]:
    // i番目までの食べ物を食べて cal ときの kind の摂取量
    vector<vvll> dp(N + 1, vvll(X + 1, vll(3, -INF)));
    rep(j, 3) rep(c, X + 1) {
        dp[0][c][j] = 0;
    }

    rep2(i, 1, N + 1) {
        rep(c, X + 1) {
            // i 番目のもの食べない
            rep(j, 3) {
                chmax(dp[i][c][j], dp[i - 1][c][j]);
            }
            if (c - C[i] >= 0) {
                chmax(dp[i][c][V[i]], dp[i - 1][c - C[i]][V[i]] + A[i]);
            }
        }
    }

    ll ans = INF;
    rep(k, 3) {
        chmin(ans, dp[N][X][k]);
    }
    cout << ans << endl;
}
