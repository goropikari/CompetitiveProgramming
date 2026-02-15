// https://atcoder.jp/contests/abc415/tasks/abc415_f
// Fri 13 Feb 2026 11:33:24 PM JST
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

struct S {
    char lc, rc;
    ll lnum, rnum;
    ll mx, sz;

    S() {
        lc = '_';
    }

    S(char c) {
        lc = rc = c;
        lnum = rnum = 1;
        mx = 1;
        sz = 1;
    }

    S(char lc, char rc, ll lnum, ll rnum, ll mx, ll sz) : lc(lc),
                                                          rc(rc),
                                                          lnum(lnum),
                                                          rnum(rnum),
                                                          mx(mx),
                                                          sz(sz) {}
};

S op(S a, S b) {
    if (a.lc == '_') return b;
    if (b.lc == '_') return a;

    char lc = a.lc, rc = b.rc;
    ll lnum = a.lnum, rnum = b.rnum;
    ll sz = a.sz + b.sz;
    ll mx = max(a.mx, b.mx);
    chmax(mx, (a.rnum + b.lnum) * (a.rc == b.lc));

    if (a.lnum == a.sz && a.rc == b.lc) {
        lnum += b.lnum;
    }
    if (b.rnum == b.sz && a.rc == b.lc) {
        rnum += a.rnum;
    }

    chmax(mx, lnum);
    chmax(mx, rnum);

    return S(lc, rc, lnum, rnum, mx, sz);
};

S e() {
    return S();
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    string str;
    cin >> N >> Q >> str;

    vector<S> v;
    rep(i, N) {
        v.push_back(S(str[i]));
    }
    segtree<S, op, e> seg(v);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll i;
            char x;
            cin >> i >> x;
            i--;
            seg.set(i, S(x));
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            S x = seg.prod(l, r);
            cout << x.mx << endl;
        }
    }
}
