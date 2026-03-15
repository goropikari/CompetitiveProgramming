// https://atcoder.jp/contests/abc448/tasks/abc448_e
// Sat 07 Mar 2026 09:33:20 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

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

struct Repunit {
    ll mod;
    int up = 32;
    vll d;  // d[i]: (1 が 2^i 個並んだ数字) % mod

    Repunit(ll mod) : mod(mod) {
        d.resize(up);
        d[0] = 1 % mod;
        rep2(i, 1, up) {
            d[i] = d[i - 1] * modpow(10, 1ll << (i - 1), mod) + d[i - 1];
            d[i] %= mod;
        }
    }

    // (1 が n 個並んだ数) % mod
    ll cal(ll n) {
        ll ret = 0;
        rep(i, up) {
            if (n >> i & 1) {
                ret *= modpow(10, 1ll << i, mod);
                ret += d[i];
                ret %= mod;
            }
        }
        return ret;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll K, M;
    cin >> K >> M;

    vll C(K), L(K);
    rep(i, K) cin >> C[i] >> L[i];

    auto cal = [&](ll mod) -> ll {
        Repunit repunit(mod);

        ll r = 0;
        rep(i, K) {
            r *= modpow(10, L[i], mod);
            r += (C[i] * repunit.cal(L[i]));
            r %= mod;
        }

        return r;
    };

    // 10007 は素数
    ll mod = 10007;
    ll r = cal(M);
    ll n = cal(mod);

    modint::set_mod(mod);
    using mint = modint;

    mint mr = mint(r), mn = mint(n);
    cout << ((mn - mr) * mint(M).inv()).val() << endl;
}
