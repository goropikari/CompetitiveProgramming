// https://atcoder.jp/contests/abc432/tasks/abc432_e
// Mon 19 Jan 2026 09:58:45 AM JST
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
    ll v, cnt;
};

S op(S a, S b) {
    return {a.v * a.cnt + b.v * b.cnt, 1};
}

S e() {
    return {0, 0};
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll m = (ll)5e5 + 5;
    fenwick_tree<ll> fw(m);
    for (auto a : A) fw.add(a, 1);

    segtree<S, op, e> seg(m);
    rep(i, m) seg.set(i, {i, 0});
    rep(i, N) {
        S now = seg.get(A[i]);
        now.cnt++;
        seg.set(A[i], now);
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x, y;
            cin >> x >> y;
            x--;
            fw.add(A[x], -1);
            fw.add(y, 1);
            {
                S now = seg.get(A[x]);
                now.cnt--;
                seg.set(A[x], now);
            }
            {
                S now = seg.get(y);
                now.cnt++;
                seg.set(y, now);
            }
            A[x] = y;
        } else {
            ll l, r;
            cin >> l >> r;

            ll ans = 0;
            if (r <= l) {
                ans += l * N;
            } else {
                ans += fw.sum(0, l) * l;
                ans += fw.sum(r + 1, m) * r;
                ans += seg.prod(l, r + 1).v;
            }
            cout << ans << endl;
        }
    }
}
