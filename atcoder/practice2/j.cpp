/*https://atcoder.jp/contests/practice2/tasks/practice2_j*/
/*2025年03月10日 03時10分39秒*/
#include <atcoder/all>
#include <atcoder/lazysegtree.hpp>
using namespace atcoder;
// using mint = modint998244353;
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

using S = ll;
S op(S a, S b) {
    return max(a, b);
}

S e() {
    return -INF;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    segtree<S, op, e> seg(n);

    rep(i, n) {
        ll a;
        cin >> a;
        seg.set(i, a);
    }

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x, v;
            cin >> x >> v;
            x--;
            seg.set(x, v);
        }
        if (t == 2) {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            cout << seg.prod(l, r + 1) << endl;
        }
        if (t == 3) {
            ll x, v;
            cin >> x >> v;
            x--;
            int r = seg.max_right(x, [&](S a) {
                return a < v;
            });
            if (r == n)
                cout << n + 1 << endl;
            else
                cout << r + 1 << endl;
        }
    }
}
