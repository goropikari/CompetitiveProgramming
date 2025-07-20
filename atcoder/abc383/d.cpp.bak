/*https://atcoder.jp/contests/abc383/tasks/abc383_d*/
/*2025年02月11日 00時59分38秒*/
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
    ll n;
    cin >> n;

    ll mx = (ll)2e6 + 5;
    vint isprime(mx, 1);
    rep2(i, 2, mx) {
        for (ll j = i + i; j < mx; j += i) {
            isprime[j] = 0;
        }
    }

    vll psq;
    rep2(i, 2, mx) {
        if (isprime[i])
            psq.push_back(-i * i);
    }
    reverse(all(psq));

    ll ans = 0;
    for (ll i = psq.size() - 1; i >= 0; i--) {
        ll sq = -psq[i];
        ll upper = n / sq;
        auto it = lower_bound(all(psq), -upper);
        if (it == psq.end())
            break;
        ll qsq = -*it;
        if (sq >= qsq)
            continue;
        ans += distance(it, psq.begin() + i);
    }

    for (ll i = psq.size() - 1; i >= 0; i--) {
        ll sq = psq[i];
        if (n / sq / sq / sq / sq)
            ans++;
    }

    cout << ans << endl;
}
