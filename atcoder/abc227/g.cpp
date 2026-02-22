// https://atcoder.jp/contests/abc227/tasks/abc227_g
// Sun 22 Feb 2026 07:38:34 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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

// const ll INF = (ll)2e18+9;
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

using Int = unsigned long long int;

Int kth_root(Int x, Int k) {
    assert(k != 0);
    if (x == 1 || k == 1) return x;
    Int l = 0, r = x;
    while (r - l > 1) {
        Int m = (r - l) / 2 + l;
        Int t = x;
        rep(i, k) t /= m;
        if (1 > t) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
};

// 平方根
Int isqrt(Int x) {
    return kth_root(x, 2);
};

vll cal_lpf(ll N) {
    vll lpf(N + 1, -1);
    vll primes;
    rep2(d, 2, N + 1) {
        if (lpf[d] < 0) {
            lpf[d] = d;
            primes.push_back(d);
        }
        for (ll p : primes) {
            if (p * d > N || p > lpf[d]) break;
            lpf[p * d] = p;
        }
    }

    return lpf;
}

// x を素因数分解する
// pair = <prime, cnt>
vector<pair<ll, ll>> factorize(vll& lpf, ll x) {
    vector<pair<ll, ll>> facs;
    {
        while (x != 1) {
            ll p = lpf[x];
            ll cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            facs.push_back({p, cnt});
        }
    }

    return facs;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;

    ll M = max(K + 1, (ll)isqrt(N) + 1);
    vll lpf = cal_lpf(M), primes;
    rep2(i, 2, M) {
        if (lpf[i] == i) primes.push_back(i);
    }

    ll psz = primes.size();
    vll cnt(psz);
    rep2(k, 2, K + 1) {
        auto ps = factorize(lpf, k);
        for (auto [p, num] : ps) {
            int i = lower_bound(all(primes), p) - primes.begin();
            cnt[i] -= num;
        }
    }

    ll L = N - K + 1, R = N;
    vll A(R - L + 1);
    iota(all(A), L);
    rep(i, psz) {
        ll p = primes[i];
        for (ll j = ceil(L, p) * p; j <= R; j += p) {
            ll x = A[j - L];
            ll num = 0;
            while (x % p == 0) {
                num++;
                x /= p;
            }
            cnt[i] += num;
            A[j - L] = x;
        }
    }

    mint ans = 1;
    for (ll x : cnt) ans *= x + 1;
    for (ll x : A) {
        if (x != 1) ans *= 2;
    }

    cout << ans.val() << endl;
}
