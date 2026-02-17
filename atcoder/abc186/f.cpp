// https://atcoder.jp/contests/abc186/tasks/abc186_f
// Mon 16 Feb 2026 10:00:58 PM JST
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

    ll H, W, M;
    cin >> H >> W >> M;

    vvll rows(H), cols(W);
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        rows[x].push_back(y);
        cols[y].push_back(x);
    }

    rep(_, 2) {
        rep(i, H) sort(all(rows[i]));
        swap(H, W);
        swap(cols, rows);
    }

    ll ans = 0;
    rep(_, 2) {
        ll fin = H;
        if (cols[0].size()) {
            fin = cols[0][0];
        }
        rep(ri, fin) {
            if (rows[ri].size())
                ans += rows[ri][0];
            else
                ans += W;
        }

        swap(H, W);
        swap(rows, cols);
    }

    auto op = [](ll a, ll b) -> ll { return a + b; };
    auto e = []() -> ll { return 0; };
    segtree<ll, op, e> seg(W);

    ll fin = H;
    if (cols[0].size()) {
        fin = cols[0][0];
    }

    ll r = W;
    if (rows[0].size()) {
        r = rows[0][0];
    }
    rep(ri, fin) {
        ll right = r;
        if (rows[ri].size()) chmin(right, rows[ri][0]);
        ans -= right - seg.prod(0, right);
        for (ll x : rows[ri]) seg.set(x, 1);
    }

    cout << ans << endl;
}
