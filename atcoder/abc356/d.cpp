// https://atcoder.jp/contests/abc356/tasks/abc356_d
// Tue 13 Jan 2026 01:35:44 AM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    // 0:  0000
    // 1:  0001
    // 2:  0010
    // 3:  0011
    // 4:  0100
    // 5:  0101
    // 6:  0110
    // 7:  0111
    // 8:  1000
    // 9:  1001
    // 10: 1010
    // 11: 1011
    // 12: 1100
    // 13: 1101

    auto top_bit = [](ll x) -> ll {
        ll id = 0;
        rep(i, 60) {
            if (x >> i & 1) id = i;
        }
        return id;
    };

    auto f = [&](auto f, ll N, ll k) -> mint {
        if ((1ll << k) > N) return 0;
        ll d = top_bit(N);
        if (k == d) {
            return (mint)N - (1ll << d) + 1;
        }

        return (mint)(1ll << (d - 1)) + f(f, N - (1ll << d), k);
    };

    mint ans = 0;
    rep(i, 60) {
        if (M >> i & 1) {
            ans += f(f, N, i);
        }
    }
    cout << ans.val() << endl;
}
