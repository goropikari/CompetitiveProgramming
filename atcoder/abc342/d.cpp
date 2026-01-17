// https://atcoder.jp/contests/abc342/tasks/abc342_d
// Sat 17 Jan 2026 06:58:00 PM JST
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

    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    int m = (ll)2e+5 + 5;
    vll sieve(m, 1);
    iota(all(sieve), 0);
    sieve[0] = sieve[1] = 1;

    rep2(i, 2, m) {
        for (ll j = i + i; j < m; j += i) {
            chmin(sieve[j], i);
        }
    }

    auto f = [&](ll x) -> ll {
        ll ret = 1;
        while (x != 1) {
            ll d = sieve[x];
            ll cnt = 0;
            while (x % d == 0) {
                cnt++;
                x /= d;
            }
            if (cnt & 1) ret *= d;
        }
        return ret;
    };

    ll nzero = 0;
    map<ll, ll> mp;

    rep(i, N) {
        if (A[i] == 0) {
            nzero++;
        } else {
            mp[f(A[i])]++;
        }
    }

    ll ans = nzero * (nzero - 1) / 2;
    ans += nzero * (N - nzero);

    for (auto [k, v] : mp) {
        ans += v * (v - 1) / 2;
    }
    cout << ans << endl;
}
