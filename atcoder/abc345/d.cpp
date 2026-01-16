// https://atcoder.jp/contests/abc345/tasks/abc345_d
// Fri 16 Jan 2026 09:30:54 PM JST
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

    ll N, H, W;
    cin >> N >> H >> W;

    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vvint grid(H, vint(W, -1));

    auto dfs = [&](auto dfs, int used, int curi, int curj) -> bool {
        while (grid[curi][curj] != -1) {
            curj++;
            if (curj == W) {
                curi++;
                curj = 0;
            }
            if (curi == H) break;
        }
        if (curi == H)
            return true;

        rep(k, N) {
            if (used >> k & 1) continue;

            ll a = A[k], b = B[k];
            rep(_, 2) {
                int ok = 1;
                rep(i, a) rep(j, b) {
                    int ni = curi + i, nj = curj + j;
                    if (ni < H && nj < W && grid[ni][nj] < 0) {
                        grid[ni][nj] = k;
                    } else {
                        ok = 0;
                    }
                }
                if (ok && dfs(dfs, used | 1ll << k, curi, curj))
                    return true;
                rep(i, a) rep(j, b) {
                    int ni = curi + i, nj = curj + j;
                    if (ni < H && nj < W && grid[ni][nj] == k) {
                        grid[ni][nj] = -1;
                    }
                }
                swap(a, b);
            }
        }

        return false;
    };

    yesno(dfs(dfs, 0, 0, 0));
}
