// https://atcoder.jp/contests/abc343/tasks/abc343_f
// Mon 19 Jan 2026 11:38:09 PM JST
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
    ll fir, fn;
    ll sec, sn;
};

S op(S a, S b) {
    map<ll, ll> mp;
    mp[a.fir] += a.fn;
    mp[a.sec] += a.sn;
    mp[b.fir] += b.fn;
    mp[b.sec] += b.sn;

    auto it = mp.rbegin();
    ll fir = it->first, fn = it->second;
    it++;
    ll sec = it->first, sn = it->second;
    return {fir, fn, sec, sn};
}

S e() {
    return S({0, 0, 0, 0});
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) cin >> A[i];

    segtree<S, op, e> seg(N);
    rep(i, N) {
        seg.set(i, {A[i], 1, 0, 0});
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll p, x;
            cin >> p >> x;
            p--;
            seg.set(p, {x, 1, 0, 0});
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            S v = seg.prod(l, r);
            cout << v.sn << endl;
        }
    }
}
