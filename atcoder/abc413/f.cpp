// https://atcoder.jp/contests/abc413/tasks/abc413_f
// 2025年07月06日 09時50分21秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

    int H, W, K;
    cin >> H >> W >> K;

    vll R, C;
    rep(i, K) {
        int r, c;
        cin >> r >> c;
        R.push_back(r);
        C.push_back(c);
    }

    vvll grid(H + 2, vll(W + 2, -1));
    rep(i, K) grid[R[i]][C[i]] = 0;

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    vector track(H + 2, vector(W + 2, vll()));
    deque<pair<ll, ll>> deq;
    rep(i, K) deq.emplace_back(R[i], C[i]);
    while (deq.size()) {
        auto [r, c] = deq.front();
        deq.pop_front();
        rep(d, 4) {
            int ni = r + di[d], nj = c + dj[d];
            if (grid[ni][nj] >= 0) continue;
            track[ni][nj].push_back(grid[r][c] + 1);
            if (track[ni][nj].size() == 2) {
                auto v = track[ni][nj];
                grid[ni][nj] = max(v[0], v[1]);
                deq.push_back({ni, nj});
            }
        }
    }

    ll ans = 0;
    rep2(i, 1, H + 1) rep2(j, 1, W + 1) {
        if (grid[i][j] > 0) ans += grid[i][j];
    }
    cout << ans << endl;
}
