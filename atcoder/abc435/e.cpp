// https://atcoder.jp/contests/abc435/tasks/abc435_e
// Thu 18 Dec 2025 09:29:24 PM JST
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
    ll num_white;
};

S op(S a, S b) {
    return S{
        a.num_white + b.num_white,
    };
}

S e() {
    return S{0};
}

using F = ll;

S mapping(F f, S x) {
    if (f == 1) return S{0};  // 区間を黒く塗る
    return x;                 // 区間に対して何もしない
}

F composition(F f, F g) {
    return f | g;
}

F id() {
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;

    vll L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
        L[i]--;
    }

    vll pos = {0, N};
    for (auto x : L) pos.push_back(x);
    for (auto x : R) pos.push_back(x);
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    int sz = (int)pos.size() - 1;
    vector<S> a(sz);
    rep(i, sz) {
        ll len = pos[i + 1] - pos[i];
        a[i] = S{len};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    rep(i, Q) {
        int l = lower_bound(all(pos), L[i]) - pos.begin();
        int r = lower_bound(all(pos), R[i]) - pos.begin();
        seg.apply(l, r, 1);
        S ret = seg.prod(0, sz);
        cout << ret.num_white << '\n';
    }
}
