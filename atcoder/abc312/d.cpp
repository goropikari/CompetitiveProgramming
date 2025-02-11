/*https://atcoder.jp/contests/abc312/tasks/abc312_d*/
/*2025年02月11日 16時50分04秒*/
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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
    string s;
    cin >> s;

    int n = s.size();
    s.insert(s.begin(), '-');

    // i 文字目まで見たときの '(' の余剰の数が j となる場合の数
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
    dp[0][0] = 1;
    rep2(i, 1, n + 1) {
        rep(j, n + 1) {
            if (s[i] == '(') {
                if (j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];
            } else if (s[i] == ')') {
                if (j + 1 <= n)
                    dp[i][j] += dp[i - 1][j + 1];
            } else {  // s[i] == '?'
                // ? を ( にする
                if (j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];

                // ? を ) にする
                if (j + 1 <= n)
                    dp[i][j] += dp[i - 1][j + 1];
            }
        }
    }

    cout << dp[n][0].val() << endl;
}
