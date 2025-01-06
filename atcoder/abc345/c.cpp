/*https://atcoder.jp/contests/abc345/tasks/abc345_c*/
/*2024年12月31日 21時13分54秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    string S;
    cin >> S;
    int N = S.size();

    // i < j, S[i] != S[j] を満たす j が何通りあるかを調べる
    vvint cumsum(200, vint(N + 1, 0));
    for (char c = 'a'; c <= 'z'; c++) {
        rep(i, N) {
            cumsum[c][i + 1] = cumsum[c][i] + (S[i] == c);
        }
    }

    ll ans = 0;
    ll same = 0;
    rep(i, N - 1) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (S[i] == c) {
                same = same || ((cumsum[c][N] - cumsum[c][i + 1]) > 0);
            } else {
                ans += cumsum[c][N] - cumsum[c][i + 1];
            }
        }
    }
    if (same)
        ans++;
    cout << ans << endl;
}
