/*https://atcoder.jp/contests/abc367/tasks/abc367_e*/
/*2025年01月14日 21時39分57秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    ll N, K;
    cin >> N >> K;
    vll X(N), A(N);
    rep(i, N) {
        cin >> X[i];
        X[i]--;
    }
    rep(i, N) cin >> A[i];

    int mx = 61;
    vvll dp(mx, vll(N, 0));
    rep(i, N) dp[0][i] = X[i];

    rep2(i, 1, mx) {
        rep(j, N) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    vll ans;
    rep(i, N) {
        ll t = K;
        ll now = i;
        rep(j, mx) {
            if (t & 1) {
                now = dp[j][now];
            }
            t >>= 1LL;
        }
        ans.push_back(A[now]);
    }
    print(ans);
}
