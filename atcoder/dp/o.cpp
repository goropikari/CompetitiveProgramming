/*https://atcoder.jp/contests/dp/tasks/dp_o*/
/*2025年01月26日 18時51分37秒*/
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

// ref: https://smijake3.hatenablog.com/entry/2019/01/16/012916
ll MOD = (ll)1e9 + 7;
int N;
vvint match;

// dp[i][state]: 男性 i までマッチングさせたときのマッチした女性の状態 (state)
// となる場合の数
vvll dp;

// x 番目の男性まで見たときに女性のマッチング状態が state のときの場合の数
// state の j 番目のビットが立ってないとき j 番目の女性は誰ともマッチしていない
ll dfs(int x, int state) {
    if (__builtin_popcount(state) == N)
        return 1;
    if (dp[x][state] != -INF)
        return dp[x][state];

    ll res = 0;
    rep(i, N) {
        if (!(state & (1 << i)) && match[x][i]) {
            res += dfs(x + 1, state | (1 << i));
            res %= MOD;
        }
    }
    return dp[x][state] = res;
}

void solve() {
    cin >> N;
    match = vvint(N, vint(N));
    rep(i, N) rep(j, N) cin >> match[i][j];

    dp = vvll(N + 1, vll(1 << N, -INF));
    cout << dfs(0, 0) << endl;
}
