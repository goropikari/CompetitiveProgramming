/*https://atcoder.jp/contests/abc244/tasks/abc244_e*/
/*2025年03月25日 00時37分49秒*/
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--, T--, X--;
    vvint graph(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dp[k][i][j]: k 回移動後、頂点 i にたどり着くまでに頂点 X を偶数(j=0)/奇数(j=1)回訪れる経路の数
    vector<vector<vector<mint>>> dp(K + 1, vector<vector<mint>>(N, vector<mint>(2)));
    dp[0][S][0] = 1;

    rep2(i, 1, K + 1) {
        rep(j, N) {
            for (int nx : graph[j]) {
                if (nx == X) {
                    dp[i][nx][0] += dp[i - 1][j][1];
                    dp[i][nx][1] += dp[i - 1][j][0];
                } else {
                    dp[i][nx][0] += dp[i - 1][j][0];
                    dp[i][nx][1] += dp[i - 1][j][1];
                }
            }
        }
    }

    cout << dp[K][T][0].val() << endl;
}
