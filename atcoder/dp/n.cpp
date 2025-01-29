/*https://atcoder.jp/contests/dp/tasks/dp_n*/
/*2025年01月26日 18時02分03秒*/
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

vll A;
vvll dp;
vll cumsum;

ll dfs(int i, int j) {
    if (i >= j)
        return 0;
    if (dp[i][j] != -INF)
        return dp[i][j];
    if (j - i == 1)
        return 0;

    ll ans = INF;
    rep2(k, i + 1, j) {
        chmin(ans, cumsum[j] - cumsum[i] + dfs(i, k) + dfs(k, j));
    }
    return dp[i][j] = ans;
}

void solve() {
    ll N;
    cin >> N;
    A = vll(N);
    rep(i, N) cin >> A[i];

    cumsum = vll(N + 1, 0);
    dp = vvll(N + 1, vll(N + 1, -INF));

    rep(i, N) {
        cumsum[i + 1] = cumsum[i] + A[i];
    }

    cout << dfs(0, N) << endl;
}
