/*https://atcoder.jp/contests/abc202/tasks/abc202_d*/
/*2025年03月14日 00時20分08秒*/
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

ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, k;
    cin >> a >> b >> k;

    int m = a + b;
    vvll dp(m + 1, vll(m + 1, 0));
    dp[0][0] = 1;
    rep(i, m + 1) {
        rep(j, m + 1) {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    string ans = "";
    auto dfs = [&](auto dfs, ll na, ll nb, ll rem) {
        if (na == 0 && nb == 0) {
            return;
        }

        if (na == 0) {
            ans.push_back('b');
            dfs(dfs, na, nb - 1, rem);
            return;
        }
        if (nb == 0) {
            ans.push_back('a');
            dfs(dfs, na - 1, nb, rem);
            return;
        }

        ll v = dp[na - 1][nb];
        if (rem <= v) {
            ans.push_back('a');
            dfs(dfs, na - 1, nb, rem);
            return;
        }

        ans.push_back('b');
        dfs(dfs, na, nb - 1, rem - v);
    };

    dfs(dfs, a, b, k);

    cout << ans << endl;
}
