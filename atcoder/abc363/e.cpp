// https://atcoder.jp/contests/abc363/tasks/abc363_e
// Wed 07 Jan 2026 12:19:44 AM JST
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

    ll H, W, Y;
    cin >> H >> W >> Y;
    vvll grid(H, vll(W));
    rep(i, H) rep(j, W) cin >> grid[i][j];

    vvint used(H, vint(W));

    // height, i, j
    using P = tuple<ll, ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, H) rep(j, W) {
        if (clamp(i, 1ll, H - 2) == i && clamp(j, 1ll, W - 2) == j) continue;
        pq.emplace(grid[i][j], i, j);
        used[i][j] = 1;
    }

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    ll ans = H * W;

    rep2(y, 1, Y + 1) {
        while (pq.size()) {
            auto [h, i, j] = pq.top();
            if (h > y) break;
            used[i][j] = 1;
            pq.pop();
            ans--;

            rep(d, 4) {
                ll ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0ll, H - 1) != ni || clamp(nj, 0ll, W - 1) != nj) continue;
                if (used[ni][nj]) continue;
                used[ni][nj] = 1;
                pq.emplace(grid[ni][nj], ni, nj);
            }
        }
        cout << ans << endl;
    }
}
