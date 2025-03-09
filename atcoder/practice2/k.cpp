/*https://atcoder.jp/contests/practice2/tasks/practice2_k*/
/*2025年03月09日 18時15分34秒*/
#include <atcoder/all>
#include <atcoder/lazysegtree.hpp>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}

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

void yesno(bool x) {
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

struct S {
    mint val;
    int size;
};

S op(S a, S b) {
    return {a.val + b.val, a.size + b.size};
}

S e() {
    return {0, 1};
}

struct F {
    mint b, c;
};

S mapping(F f, S x) {
    return {
        f.b * x.val + f.c * x.size,
        x.size,
    };
}

F composition(F f, F g) {
    return {
        f.b * g.b,
        f.b * g.c + f.c,
    };
}

F id() {
    return {1, 0};
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);

    rep(i, n) {
        ll a;
        cin >> a;
        seg.set(i, {a, 1});
    }

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r;
            ll b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).val.val() << endl;
        }
    }
}
