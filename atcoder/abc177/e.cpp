// https://atcoder.jp/contests/abc177/tasks/abc177_e
// Sat 21 Feb 2026 06:23:41 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll m = (ll)1e6 + 5;
    auto lpf = cal_lpf(m);
    vint used(m);
    for (ll a : A) {
        auto ps = factorize(lpf, a);
        for (auto [p, cnt] : ps) used[p]++;
    }

    int all_one = 1;
    rep(i, m) {
        if (used[i] > 1) all_one = 0;
    }

    ll tot = 0;
    for (ll a : A) tot = gcd(tot, a);

    string ans = "not coprime";
    if (all_one)
        ans = "pairwise coprime";
    else if (tot == 1)
        ans = "setwise coprime";
    cout << ans << endl;
}
