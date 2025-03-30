// https://atcoder.jp/contests/past202004-open/tasks/past202004_k
/*2025年03月29日 15時34分42秒*/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    S = "_" + S;

    vll C(N + 1), D(N + 1);
    rep(i, N) cin >> C[i + 1];
    rep(i, N) cin >> D[i + 1];

    // dp[i][j]: i 文字目まで見たときの、対応が取れていない左カッコの数が j のときの最小コスト
    vvll dp(N + 1, vll(N + 1, INF));
    dp[0][0] = 0;
    rep2(i, 1, N + 1) {
        rep(j, N) {
            if (S[i] == '(') {
                chmin(dp[i][j + 1], dp[i - 1][j]);

                // 反転
                if (j - 1 >= 0)
                    chmin(dp[i][j - 1], dp[i - 1][j] + C[i]);
            } else {
                if (j - 1 >= 0)
                    chmin(dp[i][j - 1], dp[i - 1][j]);

                // 反転
                chmin(dp[i][j + 1], dp[i - 1][j] + C[i]);
            }

            // i 番目の要素を削除
            chmin(dp[i][j], dp[i - 1][j] + D[i]);
        }
    }
    cout << dp[N][0] << endl;
}
