// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bi
/*2025年01月15日 23時09分04秒*/
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

ll modinv(ll x, ll mod) {
    return modpow(x, mod - 2, mod);
}

ll mx = 200005;
vll fac(mx, 0), invfac(mx, 0);

ll choose(ll n, ll k, ll mod) {
    ll ans = fac[n];
    ans *= invfac[n - k];
    ans %= mod;
    ans *= invfac[k];
    ans %= mod;

    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll mod = (ll)1e9 + 7;

    fac[0] = 1;
    invfac[0] = 1;
    rep2(i, 1, mx) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        invfac[i] = modinv(fac[i], mod);
    }

    ll ans = 0;
    for (ll k = 0; k < N; k++) {
        ans += choose(N - 1, k, mod) * A[k];
        ans %= mod;
    }
    cout << ans << endl;
}
