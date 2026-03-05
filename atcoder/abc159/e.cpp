// https://atcoder.jp/contests/abc159/tasks/abc159_e
// Sun 01 Mar 2026 04:14:03 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    ll ans = INF;

    rep(state, 1 << (H - 1)) {
        ll sum = __builtin_popcount(state);
        vint v = {0};
        rep(j, H - 1) {
            if (state >> j & 1) v.pb(j + 1);
        }
        v.pb(H);

        int ok = 1;
        vll cnt(v.size() - 1);
        rep(j, W) {
            vll row(v.size() - 1);
            rep(i, (ll)v.size() - 1) {
                for (ll k = v[i]; k < v[i + 1]; k++) {
                    if (grid[k][j] == '1') row[i]++;
                }
            }

            for (ll x : row) {
                if (x > K) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;

            int cut = 0;
            rep(i, (ll)cnt.size()) {
                if (cnt[i] + row[i] > K) {
                    cut = 1;
                    sum++;
                    swap(cnt, row);
                    break;
                }
                cnt[i] += row[i];
            }
        }

        if (ok) chmin(ans, sum);
    }

    cout << ans << endl;
}
