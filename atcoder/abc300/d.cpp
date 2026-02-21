// https://atcoder.jp/contests/abc300/tasks/abc300_d
// Sat 21 Feb 2026 06:41:50 PM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll mx = (ll)3e5 + 5;
    vll lpf = cal_lpf(mx);
    vll primes;
    rep2(i, 2, mx) {
        if (lpf[i] == i) primes.push_back(i);
    }

    ll M = primes.size();
    ll ans = 0;
    rep(i, M) {
        ll k = M - 1;
        rep2(j, i + 1, k) {
            ll a = primes[i], b = primes[j];
            if (N / a / a / b / b / b < 1) break;
            while (j < k) {
                ll c = primes[k];
                ll t = N / a / a / b / c / c;
                if (t < 1)
                    k--;
                else
                    break;
            }
            ans += k - j;
        }
    }
    cout << ans << endl;
}
