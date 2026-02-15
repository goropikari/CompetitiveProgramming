// https://atcoder.jp/contests/abc445/tasks/abc445_d
// Sat 14 Feb 2026 09:37:35 PM JST
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

    ll H, W, N;
    cin >> H >> W >> N;
    using P = pair<ll, ll>;
    vector<P> chocos(N);
    rep(i, N) {
        ll h, w;
        cin >> h >> w;
        chocos[i] = {h, w};
    }

    ll r = 0, c = 0;

    // h,w,index
    using T = tuple<ll, ll, ll>;
    vector<T> rows(N), cols(N);
    rep(i, N) {
        rows[i] = cols[i] = {chocos[i].first, chocos[i].second, i};
    }

    auto opr = [](const T& a, const T& b) -> bool {
        auto [ar, ac, ai] = a;
        auto [br, bc, bi] = b;
        return ar > br;
    };
    auto opc = [](const T& a, const T& b) -> bool {
        auto [ar, ac, ai] = a;
        auto [br, bc, bi] = b;
        return ac > bc;
    };
    sort(all(rows), opr);
    sort(all(cols), opc);

    // for (auto [r, c, i] : rows) cout << r << ' ' << c << ' ' << i << endl;
    // cout << endl;
    // for (auto [r, c, i] : cols) cout << r << ' ' << c << ' ' << i << endl;

    vint used(N);

    int ri = 0, ci = 0;

    vector<pair<ll, ll>> ans(N);

    rep(i, N) {
        while (ri < N) {
            auto [h, w, id] = rows[ri];
            if (!used[id]) break;
            ri++;
        }
        while (ci < N) {
            auto [h, w, id] = cols[ci];
            if (!used[id]) break;
            ci++;
        }

        if (ri < N) {
            auto [h, w, id] = rows[ri];
            if (H - r == h) {
                ans[id] = {r + 1, c + 1};
                c += w;
                used[id] = 1;
                continue;
            }
        }
        if (ci < N) {
            auto [h, w, id] = cols[ci];
            if (W - c == w) {
                ans[id] = {r + 1, c + 1};
                r += h;
                used[id] = 1;
            }
        }
    }

    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';

    // vvll grid(H, vll(W));
    // rep(i, N) {
    //     auto [x, y] = ans[i];
    //     auto [h, w] = chocos[i];
    //     x--, y--;
    //     rep2(i, x, x + h) rep2(j, y, y + w) {
    //         grid[i][j] = 1;
    //     }
    // }
    // ll sum = 0;
    // rep(i, H) rep(j, W) sum += grid[i][j];
    // yesno(sum == H * W);
}
