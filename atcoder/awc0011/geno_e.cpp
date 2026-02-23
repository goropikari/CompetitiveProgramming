// https://atcoder.jp/contests/awc0011/tasks/awc0011_e
// Mon 23 Feb 2026 09:46:55 PM JST
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

    ll N, M;
    cin >> N >> M;
    vll A(N + 1), B(N + 1);
    rep(i, N) cin >> A[i + 1] >> B[i + 1];

    vvll dp(N + 1, vll(M + 1, -INF));
    dp[0][0] = 0;
    rep2(i, 1, N + 1) {
        rep(j, M + 1) {
            chmax(dp[i][j], dp[i - 1][j]);
            if (j - A[i] < 0) continue;
            if (dp[i - 1][j - A[i]] < 0) continue;
            chmax(dp[i][j], dp[i - 1][j - A[i]] + B[i]);
        }
    }

    vint ans(N + 1);
    ll mxval = *max_element(all(dp[N]));
    set<tuple<int, int, ll>> memo;

    auto dfs = [&](auto dfs, int now, int weight, ll val) -> void {
        if (now == 0) return;
        if (memo.count({now, weight, val})) return;
        memo.insert({now, weight, val});
        // now を使わない
        dfs(dfs, now - 1, weight, val);

        // now を使う
        weight -= A[now];
        val -= B[now];
        if (weight < 0) return;
        if (dp[now - 1][weight] != val) return;
        ans[now] = 1;
        dfs(dfs, now - 1, weight, val);
    };

    rep(w, M + 1) {
        if (dp[N][w] == mxval) dfs(dfs, N, w, mxval);
    }

    rep2(i, 1, N + 1) yesno(ans[i]);
}
