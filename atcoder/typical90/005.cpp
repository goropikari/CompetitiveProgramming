/*https://atcoder.jp/contests/typical90/tasks/typical90_e*/
/*2025年03月17日 23時55分13秒*/
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

ll modpow(ll x, ll n, ll mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, b, k;
    cin >> n >> b >> k;
    vll cs(k);
    rep(i, k) cin >> cs[i];

    vector<vector<mint>> dp(63, vector<mint>(b, 0));
    for (ll x : cs)
        dp[0][x % b]++;

    vll tenth(63, 0);
    rep(i, 63) {
        tenth[i] = modpow(10, 1ll << i, b);
    }

    rep2(i, 1, 63) {
        rep(j, b) {
            rep(k, b) {
                dp[i][(tenth[i - 1] * j + k) % b] += dp[i - 1][j] * dp[i - 1][k];
            }
        }
    }

    vector<mint> ans(b, 0);
    ans[0] = 1;
    rep(i, 63) {
        vector<mint> tmp(b, 0);
        if (n & 1) {
            rep(j, b) {
                rep(k, b) {
                    tmp[(tenth[i] * j + k) % b] += ans[j] * dp[i][k];
                }
            }
            swap(tmp, ans);
        }
        n /= 2ll;
    }
    cout << ans[0].val() << endl;
}
