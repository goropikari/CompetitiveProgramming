// https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
// Sun 15 Feb 2026 07:00:26 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
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

// N 以下の数の least prime factor を求める
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

// x の約数列挙
vector<ll> cal_divisor(vector<pair<ll, ll>>& facs, ll x) {
    vll divs = {1};
    for (auto [p, cnt] : facs) {
        ll n = divs.size();
        rep(i, n) {
            ll mul = 1;
            rep(j, cnt) {
                mul *= p;
                divs.push_back(divs[i] * mul);
            }
        }
    }
    return divs;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;

    vll lpf = cal_lpf(c);
    vector<pair<ll, ll>> facs = factorize(lpf, c);
    vll divs = cal_divisor(facs, c);
    sort(all(divs));

    auto rit = upper_bound(all(divs), b);
    auto lit = lower_bound(all(divs), a);
    cout << rit - lit << endl;
}
