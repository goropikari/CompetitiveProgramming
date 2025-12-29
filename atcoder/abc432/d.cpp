// https://atcoder.jp/contests/abc432/tasks/abc432_d
// Wed 24 Dec 2025 11:34:46 PM JST
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

    ll N, X, Y;
    cin >> N >> X >> Y;

    using Area = tuple<ll, ll, ll, ll>;

    queue<Area> que;
    que.emplace(0, 0, X - 1, Y - 1);

    rep(i, N) {
        char c;
        ll a, b;
        cin >> c >> a >> b;
        int sz = que.size();
        rep(j, sz) {
            auto [sx, sy, fx, fy] = que.front();
            que.pop();
            if (c == 'X') {
                if (fx < a) {
                    que.emplace(sx, sy - b, fx, fy - b);
                } else if (a <= sx) {
                    que.emplace(sx, sy + b, fx, fy + b);
                } else {
                    if (a - sx > 0) {
                        que.emplace(sx, sy - b, a - 1, fy - b);
                    }
                    if (fx - a >= 0) {
                        que.emplace(a, sy + b, fx, fy + b);
                    }
                }
            } else {
                if (fy < a) {
                    que.emplace(sx - b, sy, fx - b, fy);
                } else if (a <= sy) {
                    que.emplace(sx + b, sy, fx + b, fy);
                } else {
                    if (a - sy > 0) {
                        que.emplace(sx - b, sy, fx - b, a - 1);
                    }
                    if (fy - a >= 0) {
                        que.emplace(sx + b, a, fx + b, fy);
                    }
                }
            }
        }
    }

    auto neigh = [&](const Area& a, const Area& b) -> bool {
        auto [asx, asy, afx, afy] = a;
        auto [bsx, bsy, bfx, bfy] = b;

        // x軸方向の射影が重なるか
        bool x_proj_overlap = max(asx, bsx) <= min(afx, bfx);
        // y軸方向の射影が重なるか
        bool y_proj_overlap = max(asy, bsy) <= min(afy, bfy);

        // x軸方向の射影が重なっていて、y軸方向に隣接している (上下の隣接)
        if (x_proj_overlap && (afy + 1 == bsy || bfy + 1 == asy)) {
            return true;
        }

        // y軸方向の射影が重なっていて、x軸方向に隣接している (左右の隣接)
        if (y_proj_overlap && (afx + 1 == bsx || bfx + 1 == asx)) {
            return true;
        }

        return false;
    };

    vector<Area> areas;
    while (que.size()) {
        areas.push_back(que.front());
        que.pop();
    }

    int sz = areas.size();
    dsu uf(sz);
    rep(i, sz) rep2(j, i + 1, sz) {
        if (neigh(areas[i], areas[j])) uf.merge(i, j);
    }

    auto groups = uf.groups();
    vll ans;
    for (auto grp : groups) {
        ll sum = 0;
        for (int id : grp) {
            auto [sx, sy, fx, fy] = areas[id];
            sum += (fx - sx + 1) * (fy - sy + 1);
        }
        ans.push_back(sum);
    }

    sort(all(ans));
    cout << ans.size() << endl;
    print(ans);
}
