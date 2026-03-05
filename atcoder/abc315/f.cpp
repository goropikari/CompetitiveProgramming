// https://atcoder.jp/contests/abc315/tasks/abc315_f
// Tue 24 Feb 2026 09:20:46 AM JST
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

    ll N;
    cin >> N;
    vll X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int C = 31;
    // dp[i][j]: チェックポイント i に到達するまでに j 個のチェックポイントをスキップしたときの総移動距離の最小値
    vector dp(N, vector<double>(C, (double)INF));
    dp[0][0] = 0;

    rep(i, N) {
        rep(j, C) {
            for (int skip = C - 1; skip >= 0; skip--) {
                int ni = i + skip + 1;
                int ns = j + skip;
                if (ni >= N) continue;
                if (ns >= C) continue;

                ll dx = X[ni] - X[i];
                ll dy = Y[ni] - Y[i];
                double d = sqrt(dx * dx + dy * dy);
                chmin(dp[ni][ns], dp[i][j] + d);
            }
        }
    }

    vector<double> cand = dp[N - 1];
    rep2(i, 1, C) {
        cand[i] += (double)(1ll << (i - 1));
    }

    double ans = *min_element(all(cand));
    printf("%.9lf\n", ans);
}
