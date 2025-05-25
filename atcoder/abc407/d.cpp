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

    auto to_index = [&](int i, int j) -> int {
        return i * W + j;
    };

    auto has_bit = [&](int x, int i, int j) -> bool {
        int id = to_index(i, j);
        return (x >> id) & 1;
    };

    auto set_bit = [&](int x, int i, int j) -> ll {
        return x | (1ll << to_index(i, j));
    };

    auto cal = [&](int bs) -> void {
        ll ret = 0;
        rep(i, H) rep(j, W) {
            if (!has_bit(bs, i, j))
                ret ^= grid[i][j];
        }
        chmax(ans, ret);
    };

    set<int> memo;
    memo.insert(0);
    queue<int> que;
    que.push(0);

    while (que.size()) {
        int state = que.front();
        que.pop();
        cal(state);

        rep(i, H) rep(j, W) {
            if (has_bit(state, i, j))
                continue;
            if (j + 1 < W && !has_bit(state, i, j + 1)) {
                int t = state;
                t = set_bit(t, i, j);
                t = set_bit(t, i, j + 1);
                if (!memo.count(t)) {
                    memo.insert(t);
                    que.push(t);
                }
            }
            if (i + 1 < H && !has_bit(state, i + 1, j)) {
                int t = state;
                t = set_bit(t, i, j);
                t = set_bit(t, i + 1, j);
                if (!memo.count(t)) {
                    memo.insert(t);
                    que.push(t);
                }
            }
        }
    }
    cout << memo.size() << endl;
    cout << ans << endl;
}
