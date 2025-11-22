// https://atcoder.jp/contests/abc433/tasks/abc433_d
// Sat 22 Nov 2025 09:12:14 PM JST
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

using mint = modint;

mint to_mint(string a) {
    mint x = 0;
    for (char c : a) {
        x *= 10;
        x += c - '0';
    }
    return x;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<string> A(N);
    rep(i, N) cin >> A[i];

    modint::set_mod(M);

    int upper_pow = 11;
    vector<mint> mtens(upper_pow);
    {
        mint mtenp = 1;
        rep(i, upper_pow) {
            mtens[i] = mtenp;
            mtenp *= 10;
        }
    }

    vector<unordered_map<ll, ll>> leftp(upper_pow), rightp(upper_pow);
    for (auto a : A) {
        mint x = to_mint(a);
        rep2(i, 1, upper_pow) {
            leftp[i][(x * mtens[i]).val()]++;
        }

        rightp[a.size()][x.val()]++;
    }

    ll ans = 0;
    rep2(i, 1, upper_pow) {
        for (auto [k, v] : rightp[i]) {
            ll target = (M - k) % M;
            ans += leftp[i][target] * v;
        }
    }
    cout << ans << endl;
}
