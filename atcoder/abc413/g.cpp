// https://atcoder.jp/contests/abc413/tasks/abc413_g
// 2025年07月06日 11時15分02秒
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W, K;
    cin >> H >> W >> K;
    vll R(K), C(K);
    rep(i, K) {
        cin >> R[i] >> C[i];
        R[i]--, C[i]--;
    }

    using P = pair<int, int>;
    map<P, int> mp;
    rep(i, K) {
        mp[{R[i], C[i]}] = i + 1;
    }

    bool ans = true;

    // 上辺に接する障害物からムーア近傍にある障害物を連結して下辺に到達するか
    // 右辺に接する障害物からムーア近傍にある障害物を連結して下辺に到達するか
    {
        dsu uf(K + 2);
        rep(i, K) {
            int r = R[i], c = C[i];
            P p = {r, c};
            int id = mp[p];
            if (r == 0) uf.merge(id, 0);
            if (r == H - 1) uf.merge(id, K + 1);
            if (c == W - 1) uf.merge(id, 0);
        }

        rep(i, K) {
            ll r = R[i], c = C[i];
            ll now = mp[{r, c}];
            for (int rd = -1; rd <= 1; rd++) {
                for (int cd = -1; cd <= 1; cd++) {
                    ll nr = r + rd, nc = c + cd;
                    if (!mp.count({nr, nc})) continue;
                    ll nx = mp[{nr, nc}];
                    uf.merge(now, nx);
                }
            }
        }
        ans = ans && !uf.same(0, K + 1);
    }

    // 左辺に接する障害物からムーア近傍にある障害物を連結して上辺に到達するか
    // 左辺に接する障害物からムーア近傍にある障害物を連結して右辺に到達するか
    {
        dsu uf(K + 2);
        rep(i, K) {
            int r = R[i], c = C[i];
            P p = {r, c};
            int id = mp[p];
            if (c == 0) uf.merge(id, 0);
            if (r == 0) uf.merge(id, K + 1);
            if (c == W - 1) uf.merge(id, K + 1);
        }

        rep(i, K) {
            ll r = R[i], c = C[i];
            ll now = mp[{r, c}];
            for (int rd = -1; rd <= 1; rd++) {
                for (int cd = -1; cd <= 1; cd++) {
                    ll nr = r + rd, nc = c + cd;
                    if (!mp.count({nr, nc})) continue;
                    ll nx = mp[{nr, nc}];
                    uf.merge(now, nx);
                }
            }
        }
        ans = ans && !uf.same(0, K + 1);
    }

    yesno(ans);
}
