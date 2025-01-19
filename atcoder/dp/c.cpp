/*https://atcoder.jp/contests/dp/tasks/dp_c*/
/*2025年01月19日 03時34分06秒*/
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
    ll N;
    cin >> N;
    vvll happy(3, vll(N + 1));
    rep2(i, 1, N + 1) {
        rep(j, 3) {
            cin >> happy[j][i];
        }
    }

    vvll dp(3, vll(N + 1, 0));

    rep2(i, 1, N + 1) {
        rep(j, 3) rep(k, 3) {
            if (j == k)
                continue;
            chmax(dp[j][i], dp[k][i - 1] + happy[j][i]);
        }
    }

    ll ans = 0;
    rep(i, 3) chmax(ans, dp[i][N]);
    cout << ans << endl;
}
