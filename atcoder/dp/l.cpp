/*https://atcoder.jp/contests/dp/tasks/dp_l*/
/*2025年01月26日 11時11分02秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

vll A, cumsum;
vvll dp;

ll dfs(int i, int j) {
    if (i == j)
        return A[i];
    if (j - i == 1)
        return max(A[i], A[j]);
    if (dp[i][j] != -INF)
        return dp[i][j];

    ll ans = cumsum[j + 1] - cumsum[i];
    ans += max(-dfs(i + 1, j), -dfs(i, j - 1));

    return dp[i][j] = ans;
}

void solve() {
    ll N;
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    cumsum.resize(N + 1, 0);
    rep2(i, 1, N + 1) {
        cumsum[i] = cumsum[i - 1] + A[i - 1];
    }

    dp = vvll(N + 1, vll(N + 1, -INF));
    ll tot = accumulate(all(A), 0LL);
    ll X = dfs(0, N - 1);
    ll Y = tot - X;

    cout << X - Y << endl;
}
