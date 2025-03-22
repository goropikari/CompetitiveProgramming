/*https://atcoder.jp/contests/abc322/tasks/abc322_e*/
/*2025年03月21日 22時03分11秒*/
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p;
    cin >> n >> k >> p;
    vll c(n + 1);
    vvll A(n + 1, vll(k));
    rep(i, n) {
        cin >> c[i + 1];
        rep(j, k) {
            cin >> A[i + 1][j];
        }
    }

    vector<map<vll, ll>> dp(n + 1);
    dp[0][vll(k, 0)] = 0;
    rep2(i, 1, n + 1) {
        dp[i] = dp[i - 1];
        for (auto [v, val] : dp[i - 1]) {
            vll t = v;
            rep(j, k) {
                t[j] += A[i][j];
                if (t[j] > p)
                    t[j] = p;
            }
            if (dp[i].count(t)) {
                chmin(dp[i][t], val + c[i]);
            } else {
                dp[i][t] = val + c[i];
            }
        }
    }

    vll v(k, p);
    if (dp[n].count(v)) {
        cout << dp[n][v] << endl;
    } else {
        cout << -1 << endl;
    }
}
