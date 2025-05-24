// https://atcoder.jp/contests/abc407/tasks/abc407_d
// 2025年05月24日 21時17分53秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/type_traits/has_minus_assign.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W;
    cin >> H >> W;
    vvll grid(H, vll(W));
    rep(i, H) rep(j, W) cin >> grid[i][j];

    ll ans = 0;
    rep(i, H) rep(j, W) ans ^= grid[i][j];

    set<ll> memo;
    memo.insert(ll(0));

    queue<ll> que;
    que.push(ll(0));

    auto toid = [&](int i, int j) -> int {
        return i * W + j;
    };

    auto has_bit = [](ll x, int i) -> bool {
        return (x >> i) & 1;
    };

    auto cal = [&](ll bs) -> void {
        ll ret = 0;
        rep(i, H) rep(j, W) {
            int id = toid(i, j);
            if (!has_bit(bs, id))
                ret ^= grid[i][j];
        }
        chmax(ans, ret);
    };

    while (que.size()) {
        auto x = que.front();
        que.pop();

        rep(i, H) rep(j, W) {
            int now = toid(i, j);
            int nx_yoko = toid(i, j + 1);
            int nx_tate = toid(i + 1, j);
            if (j + 1 < W && !has_bit(x, now) && !has_bit(x, nx_yoko)) {
                auto t = x;
                t |= 1ll << now;
                t |= 1ll << nx_yoko;
                if (!memo.count(t)) {
                    memo.insert(t);
                    que.push(t);
                    cal(t);
                }
            }
            if (i + 1 < H && !has_bit(x, now) && !has_bit(x, nx_tate)) {
                auto t = x;
                t |= 1ll << now;
                t |= 1ll << nx_tate;
                if (!memo.count(t)) {
                    memo.insert(t);
                    que.push(t);
                    cal(t);
                }
            }
        }
    }
    cout << ans << endl;
}
