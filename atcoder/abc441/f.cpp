// https://atcoder.jp/contests/abc441/tasks/abc441_f
// Tue 24 Feb 2026 12:05:27 AM JST
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
    vll P(N + 2), V(N + 2);
    rep(i, N) cin >> P[i + 1] >> V[i + 1];

    // dp[i][j]: 1~i 番目の商品を使って値段が j 円以下のときの価値の最大値
    vvll dp(N + 2, vll(M + 1));

    // dp[i][j]: i 番目以降の商品を使って値段が j 円以下のときの価値の最大値
    vvll dp2(N + 2, vll(M + 1));

    rep(_, 2) {
        rep2(i, 1, N + 1) {
            rep(p, M + 1) {
                chmax(dp[i][p], dp[i - 1][p]);
                if (p > 0)
                    chmax(dp[i][p], dp[i][p - 1]);
                if (p - P[i] < 0) continue;
                chmax(dp[i][p], dp[i - 1][p - P[i]] + V[i]);
            }
        }
        swap(dp, dp2);
        reverse(all(P));
        reverse(all(V));
    }
    reverse(all(dp2));

    ll mxval = dp[N][M];

    vint memo(N + 1);
    rep2(i, 1, N + 1) {
        rep(p, M + 1) {
            // i 番目の商品を使わないで最大価値を達成できるか
            if (M - p >= 0 && dp[i - 1][p] + dp2[i + 1][M - p] == mxval) {
                memo[i] |= 1;
            }

            // i 番目の商品を使って最大価値を達成できるか
            if (M - p - P[i] >= 0 && dp[i - 1][p] + V[i] + dp2[i + 1][M - p - P[i]] == mxval) {
                memo[i] |= 2;
            }
        }
    }

    string ans;

    rep2(i, 1, N + 1) {
        int x = memo[i];
        if (x == 1) {
            ans.push_back('C');
        } else if (x == 3) {
            ans.push_back('B');
        } else if (x == 2) {
            ans.push_back('A');
        }
    }

    cout << ans << endl;
}
