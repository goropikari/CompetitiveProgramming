// https://atcoder.jp/contests/abc219/tasks/abc219_e
// Sun 01 Mar 2026 07:26:42 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
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

    ll N = 4;
    vvint A(N, vint(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    vint di = {0, 1, 0, -1};
    vint dj = {1, 0, -1, 0};

    int ans = 0;
    rep(state, 1ll << N * N) {
        vvint grid(N, vint(N));

        dsu uf(N * N + 1);
        rep(i, N * N) {
            if (state >> i & 1) {
                int r = i / N;
                int c = i % N;
                grid[r][c] = 1;
            }
        }

        int ok = 1;
        rep(r, N) rep(c, N) {
            if (A[r][c] && !grid[r][c]) ok = 0;
        }
        if (!ok) continue;

        rep(r, N) rep(c, N) {
            rep(d, 4) {
                ll nr = r + di[d], nc = c + dj[d];
                if (clamp(nr, 0ll, N - 1) != nr || clamp(nc, 0ll, N - 1) != nc) continue;
                if (grid[nr][nc] == grid[r][c]) {
                    int L = nr * N + nc, R = r * N + c;
                    uf.merge(L, R);
                }
            }
            if (grid[r][c] == 0 && (r == 0 || r == N - 1 || c == 0 || c == N - 1)) {
                uf.merge(r * N + c, N * N);
            }
        }

        // 堀に囲まれた壁に連結していない領域がないかチェック
        rep(r, N) rep(c, N) {
            if (grid[r][c] == 0 && !uf.same(r * N + c, N * N)) ok = 0;
        }
        if (!ok) continue;

        // 堀で囲まれた領域が一つだけであることをチェック
        set<int> ch;
        rep(i, N) rep(j, N) {
            if (grid[i][j]) ch.insert(uf.leader(i * N + j));
        }
        if (ch.size() != 1) continue;
        ans++;
    }
    cout << ans << endl;
}
