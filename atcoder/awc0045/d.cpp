// https://atcoder.jp/contests/awc0045/tasks/awc0045_d
// Sat 11 Apr 2026 01:52:12 PM JST
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
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll UP = (int)1e6 + 5;
    vll sieve_mi(UP);
    iota(all(sieve_mi), 0);
    rep2(i, 2, UP) {
        for (ll j = i + i; j <= UP; j += i) {
            if (sieve_mi[j] > i) {
                sieve_mi[j] = i;
            }
        }
    }

    auto is_prime = [&](ll x) -> bool {
        return sieve_mi[x] == x;
    };

    vll sieve_mx = sieve_mi;
    rep2(i, 2, UP) {
        if (sieve_mi[i] != i) continue;
        for (ll j = i + i; j <= UP; j += i) {
            sieve_mx[j] = i;
        }
    }

    vll memomx(UP, -1), memomi(UP, -1);
    rep2(i, 2, UP) {
        if (is_prime(i)) {
            memomx[i] = memomi[i] = 1;
        }
    }
    memomx[1] = memomi[1] = 0;

    auto f = [&](auto f, ll x) -> ll {
        if (memomx[x] >= 0) return memomx[x];

        ll p = sieve_mx[x];
        return memomx[x] = p * f(f, x / p) + 1;
    };
    auto g = [&](auto g, ll x) -> ll {
        if (memomi[x] >= 0) return memomi[x];

        ll p = sieve_mi[x];
        return memomi[x] = p * g(g, x / p) + 1;
    };

    ll mx = 0, mi = 0;
    for (ll a : A) {
        mx += f(f, a);
        mi += g(g, a);
    }

    cout << mi << ' ' << mx << endl;
}
