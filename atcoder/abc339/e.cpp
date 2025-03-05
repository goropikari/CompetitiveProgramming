/*https://atcoder.jp/contests/abc339/tasks/abc339_e*/
/*2025年03月05日 00時52分44秒*/
#include <atcoder/all>
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

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

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -INF;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, d;
    cin >> n >> d;
    vll a(n);
    rep(i, n) cin >> a[i];

    ll mx = 5e5;
    segtree<ll, op, e> seg(vll(mx + 5, 0));

    for (ll x : a) {
        ll l = clamp(x - d, 1ll, mx);
        ll r = clamp(x + d, 1ll, mx);
        ll m = seg.prod(l, r + 1);
        seg.set(x, m + 1);
    }

    ll ans = seg.all_prod();
    cout << ans << endl;
}
