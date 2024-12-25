/*https://atcoder.jp/contests/abc320/tasks/abc320_c*/
/*2024年12月25日 22時39分29秒*/
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
    int M;
    cin >> M;
    vector<string> S(3);
    rep(i, 3) cin >> S[i];

    int MAX = 3 * M;
    int ans = INF;
    rep(i, MAX) {
        rep(j, MAX) {
            rep(k, MAX) {
                if (i == j || j == k || i == k)
                    continue;
                if (S[0][i % M] == S[1][j % M] && S[1][j % M] == S[2][k % M])
                    chmin(ans, max(i, max(j, k)));
            }
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
