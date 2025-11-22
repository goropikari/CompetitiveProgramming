// https://atcoder.jp/contests/abc430/tasks/abc430_e
// Sat 01 Nov 2025 10:36:21 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

struct RollingHash {
    vll data;
    const ll p = 1000000009;
    const ll mod = 1000000021;

    RollingHash(vll& v) {
        int n = v.size();
        data.resize(n + 1);
        rep(i, n) {
            data[i + 1] = (data[i] * p % mod) + v[i];
            data[i + 1] %= mod;
        }
    };

    // [l,r) の範囲の hash 値
    ll sub(ll l, ll r) {
        ll m = r - l;
        ll x = data[r] - data[l] * modpow(p, m, mod) % mod;
        x += mod;
        x %= mod;
        return x;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        string A, B;
        cin >> A >> B;

        vll va, vb;
        int N = A.size();
        rep(i, N) {
            va.push_back(A[i] == '1');
            vb.push_back(B[i] == '1');
        }

        ll ans = INF;
        RollingHash ha(va), hb(vb);
        ll targetHash = hb.sub(0, N);
        rep(i, N) {
            ll newHash = ha.sub(i, N) * modpow(ha.p, i, ha.mod) % ha.mod + ha.sub(0, i);
            newHash %= ha.mod;
            if (newHash == targetHash) chmin(ans, i);
        }

        if (ans == INF) ans = -1;
        cout << ans << '\n';
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
