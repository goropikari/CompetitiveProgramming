// https://atcoder.jp/contests/abc215/tasks/abc215_d
// Sat 21 Feb 2026 05:27:30 PM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll upper = (ll)1e5 + 5;
    vint sieve(upper);
    iota(all(sieve), 0);
    rep2(i, 2, upper) {
        for (int j = i + i; j < upper; j += i) {
            if (sieve[j] > i) sieve[j] = i;
        }
    }

    vint used(upper);
    for (ll a : A) {
        while (a != 1) {
            ll p = sieve[a];
            used[p] = 1;
            while (a % p == 0) a /= p;
        }
    }

    rep2(i, 2, upper) {
        if (!used[i]) continue;
        for (int j = i; j < upper; j += i) {
            used[j] = 1;
        }
    }

    vint ans;
    rep2(i, 1, M + 1) {
        if (!used[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (ll x : ans) cout << x << '\n';
}
