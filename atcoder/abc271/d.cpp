// https://atcoder.jp/contest/abc271/tasks/abc271_d
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

void solve() {
    int N, S;
    cin >> N >> S;
    vint a(N + 1, 0), b(N + 1, 0);
    rep(i, N) cin >> a[i + 1] >> b[i + 1];

    vvint dp(N + 1, vint(S + 1, 0));
    dp[0][0] = 1;
    rep2(i, 1, N + 1) {
        rep(s, S + 1) {
            if (s - a[i] >= 0)
                chmax(dp[i][s], dp[i - 1][s - a[i]]);
            if (s - b[i] >= 0)
                chmax(dp[i][s], dp[i - 1][s - b[i]]);
        }
    }
    // rep(i, N) {
    //     rep(j, S + 1) {
    //         if (!dp[i][j])
    //             continue;
    //         if (j + a[i + 1] <= S)
    //             dp[i + 1][j + a[i + 1]] = 1;
    //         if (j + b[i + 1] <= S)
    //             dp[i + 1][j + b[i + 1]] = 1;
    //     }
    // }

    if (!dp[N][S]) {
        cout << "No" << endl;
        return;
    }

    string ans = "";
    int now = S;
    for (int i = N; i > 0; i--) {
        if (now - a[i] >= 0 && dp[i - 1][now - a[i]]) {
            ans.push_back('H');
            now -= a[i];
        } else {
            ans.push_back('T');
            now -= b[i];
        }
    }
    reverse(all(ans));
    cout << "Yes" << endl;
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
