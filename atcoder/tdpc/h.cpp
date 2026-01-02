// https://atcoder.jp/contests/tdpc/tasks/tdpc_knapsack
// Sat 03 Jan 2026 12:16:17 AM JST
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

    ll N, W, C;
    cin >> N >> W >> C;

    using T = tuple<ll, ll, ll>;
    vector<T> vs;
    vs.emplace_back(0, 0, 0);
    rep(i, N) {
        ll w, v, c;
        cin >> w >> v >> c;
        vs.emplace_back(w, v, c);
    }
    sort(all(vs), [](T a, T b) -> bool {
        return get<2>(a) < get<2>(b);
    });

    vector dp(W + 1, vector(C + 1, vll(2, -INF)));
    dp[0][0][0] = 0;

    rep2(i, 1, N + 1) {
        vector dpn(W + 1, vector(C + 1, vll(2, -INF)));
        dpn[0][0][0] = 0;

        auto [pw, pv, pc] = vs[i - 1];
        auto [tw, tv, tc] = vs[i];

        rep(w, W + 1) {
            rep(k, C + 1) {
                chmax(dpn[w][k][0], dp[w][k][0]);
                if (pc == tc) {
                    if (w - tw >= 0) {
                        chmax(dpn[w][k][1], dp[w - tw][k][1] + tv);
                        if (k - 1 >= 0)
                            chmax(dpn[w][k][1], dp[w - tw][k - 1][0] + tv);
                    }
                    chmax(dpn[w][k][1], dp[w][k][1]);
                } else {
                    if (w - tw >= 0 && k - 1 >= 0) {
                        chmax(dpn[w][k][1], dp[w - tw][k - 1][0] + tv);
                        chmax(dpn[w][k][1], dp[w - tw][k - 1][1] + tv);
                    }
                    chmax(dpn[w][k][0], dp[w][k][1]);
                }
            }
        }
        swap(dp, dpn);
    }

    ll ans = 0;
    for (auto& v : dp)
        for (auto& vv : v)
            chmax(ans, *max_element(all(vv)));
    cout << ans << endl;
}
