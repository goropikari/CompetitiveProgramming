// https://atcoder.jp/contests/past17-open/tasks/past17_l
// 2025年04月24日 21時43分25秒
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
    cin >> N;
    vector A(N, vll(N, INF)), B(N, vll(N, INF));
    rep(i, N) {
        rep2(j, i + 1, N) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
    rep(i, N) {
        rep2(j, i + 1, N) {
            cin >> B[i][j];
            B[j][i] = B[i][j];
        }
    }

    vector dp(2, vvll(N, vll(N)));
    rep(i, N) rep(j, N) {
        dp[0][i][j] = A[i][j];
        dp[1][i][j] = B[i][j];
    }

    rep(k, N) rep(i, N) rep(j, N) {
        chmin(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
        chmin(dp[1][i][j], dp[1][i][k] + dp[0][k][j]);
        chmin(dp[1][i][j], dp[0][i][k] + dp[1][k][j]);
    }

    rep(i, N) {
        rep2(j, i + 1, N) {
            if (j != i + 1)
                cout << ' ';
            cout << dp[1][i][j];
        }
        cout << endl;
    }
}
