/*https://atcoder.jp/contests/dp/tasks/dp_f*/
/*Sun Jan 19 03:01:25 2025*/
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

// const ll INF = (ll)2e18 + 9;
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
    string s, t;
    cin >> s >> t;

    int ss = s.size(), st = t.size();
    vvll dp(ss + 1, vll(st + 1, 0));
    rep2(i, 1, ss + 1) {
        rep2(j, 1, st + 1) {
            chmax(dp[i][j], dp[i][j - 1]);
            chmax(dp[i][j], dp[i - 1][j]);
            if (s[i - 1] == t[j - 1]) {
                chmax(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    ll len = dp[ss][st];
    string ans = "";
    int i = ss, j = st;
    while (len) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans.push_back(s[i - 1]);
            i--, j--;
            len--;
        }
    }
    reverse(all(ans));
    cout << ans << endl;
}
