// https://atcoder.jp/contests/abc368/tasks/abc368_g
// Sun 15 Feb 2026 09:49:21 PM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    auto opplus = [](ll a, ll b) -> ll {
        return a + b;
    };
    auto oppluse = []() -> ll {
        return 0;
    };

    auto opmax = [](ll a, ll b) -> ll {
        return max(a, b);
    };
    auto opmaxe = []() -> ll {
        return -1;
    };

    segtree<ll, opplus, oppluse> sega(A);
    segtree<ll, opmax, opmaxe> segb(B);

    ll Q;
    cin >> Q;
    while (Q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll i, x;
            cin >> i >> x;
            i--;
            sega.set(i, x);
        } else if (t == 2) {
            ll i, x;
            cin >> i >> x;
            i--;
            segb.set(i, x);
        } else {
            ll l, r;
            cin >> l >> r;
            l--;

            auto f = [](ll x) -> bool {
                return x <= 1;
            };

            ll v = 0;

            while (l < r) {
                v = max(v + sega.get(l), v * segb.get(l));
                ll next_l = min(r, (ll)segb.max_right(l + 1, f));
                if (l + 1 < next_l)
                    v += sega.prod(l + 1, next_l);
                l = next_l;
            }
            cout << v << endl;
        }
    }
}
